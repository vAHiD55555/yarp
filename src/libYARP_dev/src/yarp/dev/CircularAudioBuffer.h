/*
 * SPDX-FileCopyrightText: 2023-2023 Istituto Italiano di Tecnologia (IIT)
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef YARP_DEV_CIRCULARAUDIOBUFFER_H
#define YARP_DEV_CIRCULARAUDIOBUFFER_H

#include <yarp/os/Log.h>
#include <yarp/sig/AudioBufferSize.h>
#include <cstdio>
#include <string>

#include <yarp/os/LogStream.h>

namespace yarp::dev {


template <typename SAMPLE>
class CircularAudioBuffer
{
    std::string name;
    yarp::sig::AudioBufferSize maxsize;
    size_t start;
    size_t end;
    SAMPLE *elems=nullptr;

    public:
    bool isFull()
    {
        return (end + 1) % maxsize.getBufferElements() == start;
    }

    const SAMPLE* getRawData()
    {
        return elems;
    }

    bool isEmpty()
    {
        return end == start;
    }

    void write(SAMPLE elem)
    {
        elems[end] = elem;
        end = (end + 1) % maxsize.getBufferElements();
        if (end == start)
        {
            printf ("ERROR: %s buffer overrun!\n", name.c_str());
            start = (start + 1) % maxsize.getBufferElements(); // full, overwrite
        }
    }

    yarp::sig::AudioBufferSize size()
    {
        size_t i;
        if (end > start) {
            i = end-start;
        } else if (end == start) {
            i = 0;
        } else {
            i = maxsize.getBufferElements() - start + end;
        }
        return yarp::sig::AudioBufferSize(i/maxsize.getChannels(), maxsize.getChannels(), sizeof(SAMPLE));
    }

    SAMPLE read()
    {
        if (end == start)
        {
            printf ("ERROR: %s buffer underrun!\n", name.c_str());
        }
        SAMPLE elem = elems[start];
        start = (start + 1) % maxsize.getBufferElements();
        return elem;
    }

    yarp::sig::AudioBufferSize getMaxSize()
    {
        return maxsize;
    }

    void clear()
    {
        start = 0;
        end   = 0;
    }

    CircularAudioBuffer(std::string buffer_name, yarp::sig::AudioBufferSize bufferSize) :
            name{buffer_name},
            maxsize{bufferSize},
            start{0},
            end{0},
            elems{static_cast<SAMPLE*>(calloc(maxsize.getBufferElements(), sizeof(SAMPLE)))}
    {
        static_assert (std::is_same<unsigned char, SAMPLE>::value ||
                       std::is_same<unsigned short int, SAMPLE>::value ||
                       std::is_same<unsigned int, SAMPLE>::value,
                        "CircularAudioBuffer can be specialized only as <unsigned char>, <unsigned short int>, <unsigned int>");

        yAssert(bufferSize.getDepth() == sizeof(SAMPLE));
    }

    ~CircularAudioBuffer()
    {
        if (elems)
        {
            free(elems);
            elems =nullptr;
        }
    }

};

typedef yarp::dev::CircularAudioBuffer<unsigned char> CircularAudioBuffer_8t;
typedef yarp::dev::CircularAudioBuffer<unsigned short int> CircularAudioBuffer_16t;
typedef yarp::dev::CircularAudioBuffer<unsigned int> CircularAudioBuffer_32t;

} // namespace yarp::dev

#endif // YARP_DEV_CIRCULARAUDIOBUFFER_H
