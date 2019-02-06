/*
 * Copyright (C) 2006-2019 Istituto Italiano di Tecnologia (IIT)
 * Copyright (C) 2006-2010 RobotCub Consortium
 * All rights reserved.
 *
 * This software may be modified and distributed under the terms of the
 * BSD-3-Clause license. See the accompanying LICENSE file for details.
 */

#include <yarp/os/impl/UnitTest.h>

#include <yarp/os/impl/Logger.h>
#include <yarp/os/NetInt32.h>
#include <yarp/os/Network.h>
#include <yarp/serversql/yarpserversql.h>
#include <yarp/companion/yarpcompanion.h>

#include "TestList.h"


using namespace yarp::os;
using namespace yarp::os::impl;
using namespace yarp::serversql::impl;


int main(int argc, char *argv[]) {
    Network yarp;

    Property opts;
    opts.put("portdb",":memory:");
    opts.put("subdb",":memory:");
    opts.put("local",1);
    NameStore *store = yarpserver_create(opts);
    yarp.queryBypass(store);

    bool done = false;
    int result = 0;

    if (argc>1) {
        int verbosity = 0;
        while (std::string(argv[1])==std::string("verbose")) {
            verbosity++;
            argc--;
            argv++;
        }
        if (verbosity>0) {
            Logger::get().setVerbosity(verbosity);
        }

        if (std::string(argv[1])==std::string("regression")) {
            done = true;
            UnitTest::startTestSystem();
            TestList::collectTests();  // just in case automation doesn't work
            if (argc>2) {
                result = UnitTest::getRoot().run(argc-2,argv+2);
            } else {
                result = UnitTest::getRoot().run();
            }
            UnitTest::stopTestSystem();
        }
    }
    if (!done) {
        yarp::companion::main(argc,argv);
    }

    delete store;
    return result;
}
