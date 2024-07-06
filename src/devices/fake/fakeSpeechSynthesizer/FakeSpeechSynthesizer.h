/*
 * SPDX-FileCopyrightText: 2023-2023 Istituto Italiano di Tecnologia (IIT)
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FAKESPEECHSYNTHESIZER_H
#define FAKESPEECHSYNTHESIZER_H

#include <yarp/dev/DeviceDriver.h>
#include <yarp/dev/ISpeechSynthesizer.h>
#include <yarp/os/Bottle.h>
#include <stdio.h>

#include "FakeSpeechSynthesizer_ParamsParser.h"

using namespace yarp::os;

/**
 * @ingroup dev_impl_fake dev_impl_other
 *
 * \brief `FakeSpeechSynthesizer`: A fake implementation of a speech synthesizer plugin.
 *
 * Parameters required by this device are shown in class: FakeSpeechSynthesizer_ParamsParser
 */
class FakeSpeechSynthesizer :
        public yarp::dev::DeviceDriver,
        public yarp::dev::ISpeechSynthesizer,
        public FakeSpeechSynthesizer_ParamsParser
{
private:
    bool m_verbose = true;

public:
    FakeSpeechSynthesizer();
    virtual ~FakeSpeechSynthesizer();
    FakeSpeechSynthesizer(const FakeSpeechSynthesizer&) = delete;
    FakeSpeechSynthesizer(FakeSpeechSynthesizer&&) = delete;
    FakeSpeechSynthesizer& operator=(const FakeSpeechSynthesizer&) = delete;
    FakeSpeechSynthesizer& operator=(FakeSpeechSynthesizer&&) = delete;

    bool open(yarp::os::Searchable& config) override;
    bool close() override;

    virtual bool setLanguage(const std::string& language) override;
    virtual bool getLanguage(std::string& language) override;
    virtual bool setVoice(const std::string& voice) override;
    virtual bool getVoice(std::string& voice) override;
    virtual bool setSpeed(const double speed) override;
    virtual bool getSpeed(double& voice) override;
    virtual bool setPitch(const double pitch) override;
    virtual bool getPitch(double& voice) override;
    virtual bool synthesize(const std::string& text, yarp::sig::Sound& sound) override;
};

#endif
