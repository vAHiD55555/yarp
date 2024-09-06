/*
 * SPDX-FileCopyrightText: 2023-2023 Istituto Italiano di Tecnologia (IIT)
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "AudioFromFileDevice.h"

#include <yarp/os/Thread.h>
#include <yarp/os/Time.h>
#include <yarp/os/Stamp.h>
#include <yarp/os/LogComponent.h>
#include <yarp/os/LogStream.h>

#include <mutex>
#include <string>


using namespace yarp::os;
using namespace yarp::dev;
using namespace yarp::sig;

constexpr double c_DEFAULT_PERIOD=0.01;   //s

namespace {
YARP_LOG_COMPONENT(AUDIOFROMFILE, "yarp.device.audioFromFileDevice")
}

typedef unsigned short int audio_sample_16t;

AudioFromFileDevice::AudioFromFileDevice() :
        PeriodicThread(c_DEFAULT_PERIOD)
{
}

AudioFromFileDevice::~AudioFromFileDevice()
{
}

bool AudioFromFileDevice::setHWGain(double gain)
{
    yCInfo(AUDIOFROMFILE) << "Not yet implemented";
    return false;
}

bool AudioFromFileDevice::open(yarp::os::Searchable &config)
{
    bool b = false;
    b = parseParams(config);
    if (!b) { return false; }

    b = configureRecorderAudioDevice(config.findGroup("AUDIO_BASE"), "audioFromFileDevice");
    if (!b) { return false; }

    //sets the thread period
    setPeriod(m_period);

    //opens the file
    bool ret = yarp::sig::file::read(m_audioFile, m_file_name.c_str());
    if (ret == false)
    {
        yCError(AUDIOFROMFILE) << "Unable to open file" << m_file_name.c_str();
        return false;
    }
    yCInfo(AUDIOFROMFILE) << "Loaded file has the following properties: samples:" << m_audioFile.getSamples() << " channels:"<< m_audioFile.getChannels() << " bytes per samples:" << m_audioFile.getBytesPerSample();

    if (m_use_params_from_file)
    {
        this->m_audiorecorder_cfg.numChannels = m_audioFile.getChannels();
        this->m_audiorecorder_cfg.frequency = m_audioFile.getFrequency();
        this->m_audiorecorder_cfg.bytesPerSample = m_audioFile.getBytesPerSample();
        this->m_audiorecorder_cfg.numSamples = m_audioFile.getSamples();
    }
    else
    {
        if (m_audioFile.getChannels() != this->m_audiorecorder_cfg.numChannels)
        {
            yCInfo(AUDIOFROMFILE) << "Number of channels mismatch!";
            return false;
        }
        yCError(AUDIOFROMFILE) << "Not Yet implemented! I should replace this fatal error with a configuration conversion here!";
        return false;
    }


    //sets the audio configuration equal to the audio file
    //constexpr size_t c_EXTRA_SPACE = 2;
    //AudioBufferSize buffer_size(m_audiorecorder_cfg.numSamples* c_EXTRA_SPACE, m_audiorecorder_cfg.numChannels, m_audiorecorder_cfg.bytesPerSample);
    //m_inputBuffer = new yarp::dev::CircularAudioBuffer_16t("fake_mic_buffer", buffer_size);

    m_datap = m_audioFile.getInterleavedAudioRawData();

    //start the capture thread
    start();
    return true;
}

bool AudioFromFileDevice::close()
{
    AudioFromFileDevice::stop();
    return true;
}

bool AudioFromFileDevice::stopRecording()
{
    bool b = AudioRecorderDeviceBase::stopRecording();
    if (b && m_reset_on_stop)
    {
        m_bpnt=0;
    }
    return b;
}

bool AudioFromFileDevice::threadInit()
{
    return true;
}


void AudioFromFileDevice::run()
{
    // when not recording, do nothing
    if (!m_recording_enabled)
    {
        return;
    }

    // Just acquire raw data and put them in the buffer
    //each iteration, which occurs every xxx ms (thread period), I copy a fixed amount of
    //samples (m_driver_frame_size) in the buffer. This operation cannot be interrupted by stopping the device
    //with m_recording_enabled=false. When the pointer reaches the end of the sound (audioFile),
    //just restart from the beginning in an endless loop
    size_t chan_num = m_audioFile.getChannels();
    size_t fsize_in_samples = m_audioFile.getSamples();
    for (size_t i = 0; i < m_driver_frame_size; i++)
    {
        if (m_bpnt >= fsize_in_samples)
        {
            m_bpnt = 0;
        }
        for (size_t c=0; c< chan_num; c++)
        {
            m_inputBuffer->write((unsigned short)(m_datap.at(m_bpnt* chan_num +c).get()));
        }
        m_bpnt++;
    }

    if (m_audiobase_debug)
    {
        yCDebug(AUDIOFROMFILE) << "b_pnt" << m_bpnt << "/" << fsize_in_samples << " samples";
    }
}
