/*
 * Copyright (C) 2006-2018 Istituto Italiano di Tecnologia (IIT)
 * Copyright (C) 2006-2010 RobotCub Consortium
 * All rights reserved.
 *
 * This software may be modified and distributed under the terms of the
 * BSD-3-Clause license. See the accompanying LICENSE file for details.
 */

#include <yarp/os/impl/ThreadImpl.h>
#include <yarp/os/NetType.h>

#include <yarp/os/impl/Logger.h>
#include <yarp/os/impl/PlatformSignal.h>
#include <yarp/os/impl/SemaphoreImpl.h>

#include <cstdlib>
#include <thread>
#include <sstream>

#if defined(YARP_HAS_ACE)
#  include <ace/Thread.h> // For using ACE_hthread_t as native_handle
#endif

#if defined(__linux__) // Use the POSIX syscalls for the gettid()
#  include <sys/syscall.h>
#  include <unistd.h>
#endif


using namespace yarp::os::impl;

int ThreadImpl::threadCount = 0;
int ThreadImpl::defaultStackSize = 0;
SemaphoreImpl *ThreadImpl::threadMutex = nullptr;
SemaphoreImpl *ThreadImpl::timeMutex = nullptr;

void ThreadImpl::init()
{
    if (!threadMutex) {
        threadMutex = new SemaphoreImpl(1);
    }
    if (!timeMutex) {
        timeMutex = new SemaphoreImpl(1);
    }
}

void ThreadImpl::fini()
{
    if (threadMutex) {
        delete threadMutex;
        threadMutex = nullptr;
    }
    if (timeMutex) {
        delete timeMutex;
        timeMutex = nullptr;
    }
}


void theExecutiveBranch(void *args)
{
    // just for now -- rather deal with broken pipes through normal procedures
    yarp::os::impl::signal(SIGPIPE, SIG_IGN);


    /*
    sigset_t set;
    sigemptyset(&set);
    sigaddset(&set, SIGHUP);
    sigaddset(&set, SIGINT);
    sigaddset(&set, SIGQUIT);
    sigaddset(&set, SIGTERM);
    sigaddset(&set, SIGUSR1);
    sigaddset(&set, SIGCHLD);
    ACE_OS::thr_sigsetmask(SIG_BLOCK, &set, nullptr);
    fprintf(stderr, "Blocking signals\n");
    */

    ThreadImpl *thread = (ThreadImpl *)args;

    YARP_DEBUG(Logger::get(), "Thread starting up");

    bool success=thread->threadInit();
    thread->notify(success);
    thread->notifyOpened(success);
    thread->synchroPost();

    if (success) {
        // the thread id must be set before calling run() to avoid a race
        // condition in case the run() method checks it.
        thread->id = std::this_thread::get_id();
#if defined(__linux__)
        // Use the POSIX syscalls to get
        // the real thread ID (gettid) on Linux machine
        thread->tid = static_cast<long int>(syscall(SYS_gettid));
#else
        thread->tid = static_cast<long int>(std::hash<std::thread::id>()(thread->id));
#endif

        thread->setPriority();
        thread->run();
        thread->threadRelease();
    }


    //YARP_ERROR(Logger::get(), std::string("uncaught exception in thread: ") +
    //             e.toString());

    ThreadImpl::changeCount(-1);
    YARP_DEBUG(Logger::get(), "Thread shutting down");
    //ACE_Thread::exit();

    thread->notify(false);
    thread->synchroPost();

    return;
}


ThreadImpl::ThreadImpl() :
        tid(-1),
        id(std::thread::id()),
        defaultPriority(-1),
        defaultPolicy(-1),
        hid(std::thread()),
        active(false),
        opened(false),
        closing(false),
        needJoin(false),
        delegate(nullptr),
        synchro(0),
        initWasSuccessful(false)
{
    setOptions();
}


ThreadImpl::ThreadImpl(Runnable *target) :
        tid(-1),
        id(std::thread::id()),
        defaultPriority(-1),
        defaultPolicy(-1),
        hid(std::thread()),
        active(false),
        opened(false),
        closing(false),
        needJoin(false),
        delegate(target),
        synchro(0),
        initWasSuccessful(false)
{
    setOptions();
}


ThreadImpl::~ThreadImpl()
{
    YARP_DEBUG(Logger::get(), "Thread being deleted");
    join();
}


long int ThreadImpl::getKey()
{
    return tid;
}


long int ThreadImpl::getKeyOfCaller()
{
#if defined(__linux__)
    // Use the POSIX syscalls to get
    // the real thread ID (gettid) on Linux machine
    return static_cast<long int>(syscall(SYS_gettid));
#else
    return static_cast<long int>(std::hash<std::thread::id>()(std::this_thread::get_id()));
#endif
}


void ThreadImpl::setOptions(int stackSize)
{
    this->stackSize = stackSize;
}


int ThreadImpl::join(double seconds)
{
    closing = true;
    if (needJoin) {
        if (seconds>0) {
            if (!initWasSuccessful) {
                // join called before start completed
                YARP_ERROR(Logger::get(), std::string("Tried to join a thread before starting it"));
                return -1;
            }
            synchro.waitWithTimeout(seconds);
            if (active) {
                return -1;
            }
        }

        int result = -1;
        if (hid.joinable()) {
            hid.join();
            result = 0;
        }

        needJoin = false;
        active = false;
        while (synchro.check()) {}
        return result;
    }
    return 0;
}

void ThreadImpl::run()
{
    if (delegate!=nullptr) {
        delegate->run();
    }
}

void ThreadImpl::close()
{
    closing = true;
    if (delegate!=nullptr) {
        delegate->close();
    }
    join(-1);
}

// similar to close(), but does not join (does not block)
void ThreadImpl::askToClose()
{
    closing = true;
    if (delegate!=nullptr) {
        delegate->close();
    }
}

void ThreadImpl::beforeStart()
{
    if (delegate!=nullptr) {
        delegate->beforeStart();
    }
}

void ThreadImpl::afterStart(bool success)
{
    if (delegate!=nullptr) {
        delegate->afterStart(success);
    }
}

bool ThreadImpl::threadInit()
{
    if (delegate!=nullptr) {
        return delegate->threadInit();
    }
    else
        return true;
}

void ThreadImpl::threadRelease()
{
    if (delegate!=nullptr){
        delegate->threadRelease();
    }
}

bool ThreadImpl::start()
{
    join();
    closing = false;
    initWasSuccessful = false;
    beforeStart();
    hid = std::thread(theExecutiveBranch, (void*)this);
    int result = hid.joinable() ? 0 : 1;
    if (result==0) {
        // we must, at some point in the future, join the thread
        needJoin = true;

        // the thread started correctly, wait for the initialization
        YARP_DEBUG(Logger::get(), std::string("Child thread initializing"));
        synchroWait();
        initWasSuccessful = true;
        if (opened) {
            ThreadImpl::changeCount(1);
            YARP_DEBUG(Logger::get(), "Child thread initialized ok");
            afterStart(true);
            return true;
        } else {
            YARP_DEBUG(Logger::get(), "Child thread did not initialize ok");
            //wait for the thread to really exit
            ThreadImpl::join(-1);
        }
    }
    //the thread did not start, call afterStart() to warn the user
    char tmp[80];
    sprintf(tmp, "%d", result);
    YARP_ERROR(Logger::get(), std::string("A thread failed to start with error code: ")+std::string(tmp));
    afterStart(false);
    return false;
}

void ThreadImpl::synchroWait()
{
    synchro.wait();
}

void ThreadImpl::synchroPost()
{
    synchro.post();
}

void ThreadImpl::notify(bool s)
{
    active = s;
}

bool ThreadImpl::isClosing()
{
    return closing;
}

bool ThreadImpl::isRunning()
{
    return active;
}

int ThreadImpl::getCount()
{
    init();
    threadMutex->wait();
    int ct = threadCount;
    threadMutex->post();
    return ct;
}


void ThreadImpl::changeCount(int delta)
{
    init();
    threadMutex->wait();
    threadCount+=delta;
    threadMutex->post();
}

int ThreadImpl::setPriority(int priority, int policy)
{
    if (priority==-1) {
        priority = defaultPriority;
        policy = defaultPolicy;
    } else {
        defaultPriority = priority;
        defaultPolicy = policy;
    }
    if (active && priority!=-1) {
#if defined(YARP_HAS_ACE)
        if (std::is_same<std::thread::native_handle_type, ACE_hthread_t>::value) {
            return ACE_Thread::setprio(hid.native_handle(), priority, policy);
        } else {
            YARP_ERROR(Logger::get(), "Cannot set priority without ACE");
        }
#elif defined(__unix__)
        if (std::is_same<std::thread::native_handle_type, pthread_t>::value) {
            struct sched_param thread_param;
            thread_param.sched_priority = priority;
            int ret = pthread_setschedparam(hid.native_handle(), policy, &thread_param);
            return (ret != 0) ? -1 : 0;
        } else {
            YARP_ERROR(Logger::get(), "Cannot set priority without ACE");
        }
#else
        YARP_ERROR(Logger::get(), "Cannot set priority without ACE");
#endif
    }
    return 0;
}

int ThreadImpl::getPriority()
{
    int prio = defaultPriority;
    if (active) {
#if defined(YARP_HAS_ACE)
        if (std::is_same<std::thread::native_handle_type, ACE_hthread_t>::value) {
            ACE_Thread::getprio(hid.native_handle(), prio);
        } else {
            YARP_ERROR(Logger::get(), "Cannot get priority without ACE");
        }
#elif defined(__unix__)
        if (std::is_same<std::thread::native_handle_type, pthread_t>::value) {
            struct sched_param thread_param;
            int policy;
            if (pthread_getschedparam(hid.native_handle(), &policy, &thread_param) == 0) {
                prio = thread_param.sched_priority;
            } else {
                YARP_ERROR(Logger::get(), "Cannot get priority without ACE");
            }
        }
#else
        YARP_ERROR(Logger::get(), "Cannot get priority without ACE");
#endif
    }
    return prio;
}

int ThreadImpl::getPolicy()
{
    int policy = defaultPolicy;
    if (active) {
#if defined(YARP_HAS_ACE)
        if (std::is_same<std::thread::native_handle_type, ACE_hthread_t>::value) {
            int prio;
            ACE_Thread::getprio(hid.native_handle(), prio, policy);
        } else {
            YARP_ERROR(Logger::get(), "Cannot get scheduling policy without ACE");
        }
#elif defined(__unix__)
        if (std::is_same<std::thread::native_handle_type, pthread_t>::value) {
            struct sched_param thread_param;
            if (pthread_getschedparam(hid.native_handle(), &policy, &thread_param) != 0) {
                policy = defaultPolicy;
            }
        } else {
            YARP_ERROR(Logger::get(), "Cannot get scheduling policy without ACE");
        }
#else
        YARP_ERROR(Logger::get(), "Cannot get scheduling policy without ACE");
#endif
    }
    return policy;
}

long ThreadImpl::getTid()
{
    return tid;
}


void ThreadImpl::setDefaultStackSize(int stackSize)
{
    defaultStackSize = stackSize;
}

void ThreadImpl::yield()
{
    std::this_thread::yield();
}
