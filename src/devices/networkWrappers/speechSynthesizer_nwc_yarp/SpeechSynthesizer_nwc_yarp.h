/*
 * SPDX-FileCopyrightText: 2023-2023 Istituto Italiano di Tecnologia (IIT)
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef YARP_DEV_SPEECHSYNTHESIZER_NWC_YARP_H
#define YARP_DEV_SPEECHSYNTHESIZER_NWC_YARP_H

#include <cstdio>
#include <cstdlib>

#include <yarp/os/BufferedPort.h>
#include <yarp/dev/PolyDriver.h>
#include <yarp/dev/ISpeechSynthesizer.h>
#include <yarp/sig/Sound.h>
#include <yarp/os/Time.h>
#include <yarp/os/Network.h>
#include <yarp/os/Thread.h>
#include <yarp/os/Vocab.h>
#include <yarp/os/Bottle.h>
#include <yarp/os/RpcServer.h>
#include <yarp/dev/WrapperSingle.h>
#include "ISpeechSynthesizerMsgs.h"
#include "SpeechSynthesizer_nwc_yarp_ParamsParser.h"

/**
 *  @ingroup dev_impl_nwc_yarp
 *
 * \section speechSynthesizer_nwc_yarp
 *
 * \brief `speechSynthesizer_nwc_yarp`: A network wrapper client that connects to a speechSynthesizer_nws_yarp to perform speech synthesis.
 *
 * Parameters required by this device are shown in class: SpeechSynthesizer_nwc_yarp_ParamsParser
 *
 */

class SpeechSynthesizer_nwc_yarp :
    public yarp::dev::DeviceDriver,
    public yarp::dev::ISpeechSynthesizer,
    public SpeechSynthesizer_nwc_yarp_ParamsParser
{
    // Methods
private:
    bool closeMain();

public:
    SpeechSynthesizer_nwc_yarp() = default;
    SpeechSynthesizer_nwc_yarp(const SpeechSynthesizer_nwc_yarp&) = delete;
    SpeechSynthesizer_nwc_yarp(SpeechSynthesizer_nwc_yarp&&) = delete;
    SpeechSynthesizer_nwc_yarp& operator=(const SpeechSynthesizer_nwc_yarp&) = delete;
    SpeechSynthesizer_nwc_yarp& operator=(SpeechSynthesizer_nwc_yarp&&) = delete;
    ~SpeechSynthesizer_nwc_yarp() override;

    // yarp::dev::DeviceDriver
    bool open(yarp::os::Searchable& config) override;
    bool close() override;

    // yarp::dev::ISpeechSynthesizer
    bool setLanguage(const std::string& language="auto") override;
    bool getLanguage(std::string& language) override;
    bool setVoice(const std::string& voice_name = "auto") override;
    bool getVoice(std::string& voice_name) override;
    bool setSpeed(const double speed=0) override;
    bool getSpeed(double& speed) override;
    bool setPitch(const double pitch) override;
    bool getPitch(double& pitch) override;
    bool synthesize(const std::string& text, yarp::sig::Sound& sound) override;

    // Parameters
private:
    ISpeechSynthesizerMsgs m_thriftClient;

protected:
    yarp::os::Port                m_thriftClientPort;
};


#endif // YARP_DEV_SPEECHSYNTHESIZER_NWC_YARP_H
