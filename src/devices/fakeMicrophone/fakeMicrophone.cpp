/*
 * Copyright (C) 2006-2020 Istituto Italiano di Tecnologia (IIT)
 * All rights reserved.
 *
 * This software may be modified and distributed under the terms of the
 * BSD-3-Clause license. See the accompanying LICENSE file for details.
 */

#include "fakeMicrophone.h"

#include <yarp/os/Thread.h>
#include <yarp/os/Time.h>
#include <yarp/os/Semaphore.h>
#include <yarp/os/Stamp.h>
#include <yarp/os/LogComponent.h>
#include <yarp/os/LogStream.h>

#include <mutex>
#define _USE_MATH_DEFINES
#include <math.h>
#include <string>


using namespace yarp::os;
using namespace yarp::dev;
using namespace yarp::sig;

constexpr size_t c_SAMPLES_TO_BE_COPIED=512; //samples
constexpr size_t c_default_freq = 44100; //hz
constexpr size_t c_channels = 2; //stereo
constexpr size_t c_bytes_form = 2; //16bit

namespace {
YARP_LOG_COMPONENT(FAKEMICROPHONE, "yarp.device.fakeMicrophone")
}

typedef unsigned short int audio_sample_16t;

fakeMicrophone::fakeMicrophone() :
        PeriodicThread(DEFAULT_PERIOD)
{
    start_time = yarp::os::Time::now();
}

fakeMicrophone::~fakeMicrophone()
{
    close();
}

bool fakeMicrophone::open(yarp::os::Searchable &config)
{
    //sets the thread period
    if(config.check("period"))
    {
        double period = config.find("period").asFloat64();
        setPeriod(period);
        yCInfo(FAKEMICROPHONE) << "Using chosen period of " << period << " s";
    }
    else
    {
        yCInfo(FAKEMICROPHONE) << "Using default period of " << DEFAULT_PERIOD << " s";
    }

    m_audiorecorder_cfg.numSamples = c_default_freq *5; //5sec
    m_audiorecorder_cfg.numChannels = c_channels;
    m_audiorecorder_cfg.frequency = c_default_freq;
    m_audiorecorder_cfg.bytesPerSample = c_bytes_form;
    const size_t EXTRA_SPACE = 2;
    AudioBufferSize buffer_size(m_audiorecorder_cfg.numSamples*EXTRA_SPACE, m_audiorecorder_cfg.numChannels, m_audiorecorder_cfg.bytesPerSample);
    m_inputBuffer = new yarp::dev::CircularAudioBuffer_16t("fake_mic_buffer", buffer_size);

    //start the capture thread
    start_time = yarp::os::Time::now();
    start();
    return true;
}

bool fakeMicrophone::close()
{
    fakeMicrophone::stop();
    //wait until the thread is stopped

    if (m_inputBuffer)
    {
        delete m_inputBuffer;
        m_inputBuffer = 0;
    }
    return true;
}


bool fakeMicrophone::threadInit()
{
    return true;
}


void fakeMicrophone::run()
{
    // when not recording, do nothing
    if (!m_isRecording)
    {
        return;
    }

    //fill the buffer with a sine tone
    //each iteration, which occurs every xxx ms, I copy a bunch of samples in the buffer.
    for (size_t i = 0; i < c_SAMPLES_TO_BE_COPIED; i++)
    {
        //this sine waveform has amplitude (-32000,32000)
        constexpr double c_wave_ampl = 32000;
        // on the left  channel it has frequency 440Hz (A4 note)
        // on the right channel it has frequency 220Hz (A3 note)
        double wt1 = double(t) / double (m_audiorecorder_cfg.frequency) * 440.0 * 2 * M_PI;
        unsigned short elem1 = double(c_wave_ampl * sin(wt1));
        double wt2 = double(t) / double(m_audiorecorder_cfg.frequency) * 220.0 * 2 * M_PI;
        unsigned short elem2 = double(c_wave_ampl * sin(wt2));
        m_inputBuffer->write(elem1); //chan1
        m_inputBuffer->write(elem2); //chan2
        t++;
    }
}
