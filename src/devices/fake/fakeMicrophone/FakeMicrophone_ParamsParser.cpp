/*
 * SPDX-FileCopyrightText: 2023-2023 Istituto Italiano di Tecnologia (IIT)
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */


// Generated by yarpDeviceParamParserGenerator (1.0)
// This is an automatically generated file. Please do not edit it.
// It will be re-generated if the cmake flag ALLOW_DEVICE_PARAM_PARSER_GERNERATION is ON.

// Generated on: Tue Feb 27 00:56:32 2024


#include "FakeMicrophone_ParamsParser.h"
#include <yarp/os/LogStream.h>
#include <yarp/os/Value.h>

namespace {
    YARP_LOG_COMPONENT(FakeMicrophoneParamsCOMPONENT, "yarp.device.FakeMicrophone")
}


FakeMicrophone_ParamsParser::FakeMicrophone_ParamsParser()
{
}


std::vector<std::string> FakeMicrophone_ParamsParser::getListOfParams() const
{
    std::vector<std::string> params;
    params.push_back("period");
    params.push_back("waveform");
    params.push_back("signal_frequency");
    params.push_back("signal_amplitude");
    params.push_back("driver_frame_size");
    return params;
}


bool      FakeMicrophone_ParamsParser::parseParams(const yarp::os::Searchable & config)
{
    //Check for --help option
    if (config.check("help"))
    {
        yCInfo(FakeMicrophoneParamsCOMPONENT) << getDocumentationOfDeviceParams();
    }

    std::string config_string = config.toString();
    yarp::os::Property prop_check(config_string.c_str());
    //Parser of parameter period
    {
        if (config.check("period"))
        {
            m_period = config.find("period").asFloat64();
            yCInfo(FakeMicrophoneParamsCOMPONENT) << "Parameter 'period' using value:" << m_period;
        }
        else
        {
            yCInfo(FakeMicrophoneParamsCOMPONENT) << "Parameter 'period' using DEFAULT value:" << m_period;
        }
        prop_check.unput("period");
    }

    //Parser of parameter waveform
    {
        if (config.check("waveform"))
        {
            m_waveform = config.find("waveform").asString();
            yCInfo(FakeMicrophoneParamsCOMPONENT) << "Parameter 'waveform' using value:" << m_waveform;
        }
        else
        {
            yCInfo(FakeMicrophoneParamsCOMPONENT) << "Parameter 'waveform' using DEFAULT value:" << m_waveform;
        }
        prop_check.unput("waveform");
    }

    //Parser of parameter signal_frequency
    {
        if (config.check("signal_frequency"))
        {
            m_signal_frequency = config.find("signal_frequency").asInt64();
            yCInfo(FakeMicrophoneParamsCOMPONENT) << "Parameter 'signal_frequency' using value:" << m_signal_frequency;
        }
        else
        {
            yCInfo(FakeMicrophoneParamsCOMPONENT) << "Parameter 'signal_frequency' using DEFAULT value:" << m_signal_frequency;
        }
        prop_check.unput("signal_frequency");
    }

    //Parser of parameter signal_amplitude
    {
        if (config.check("signal_amplitude"))
        {
            m_signal_amplitude = config.find("signal_amplitude").asInt64();
            yCInfo(FakeMicrophoneParamsCOMPONENT) << "Parameter 'signal_amplitude' using value:" << m_signal_amplitude;
        }
        else
        {
            yCInfo(FakeMicrophoneParamsCOMPONENT) << "Parameter 'signal_amplitude' using DEFAULT value:" << m_signal_amplitude;
        }
        prop_check.unput("signal_amplitude");
    }

    //Parser of parameter driver_frame_size
    {
        if (config.check("driver_frame_size"))
        {
            m_driver_frame_size = config.find("driver_frame_size").asInt64();
            yCInfo(FakeMicrophoneParamsCOMPONENT) << "Parameter 'driver_frame_size' using value:" << m_driver_frame_size;
        }
        else
        {
            yCInfo(FakeMicrophoneParamsCOMPONENT) << "Parameter 'driver_frame_size' using DEFAULT value:" << m_driver_frame_size;
        }
        prop_check.unput("driver_frame_size");
    }

    /*
    //This code check if the user set some parameter which are not check by the parser
    //If the parser is set in strict mode, this will generate an error
    if (prop_check.size() > 0)
    {
        bool extra_params_found = false;
        for (auto it=prop_check.begin(); it!=prop_check.end(); it++)
        {
            if (m_parser_is_strict)
            {
                yCError(FakeMicrophoneParamsCOMPONENT) << "User asking for parameter: "<<it->name <<" which is unknown to this parser!";
                extra_params_found = true;
            }
            else
            {
                yCWarning(FakeMicrophoneParamsCOMPONENT) << "User asking for parameter: "<< it->name <<" which is unknown to this parser!";
            }
        }

       if (m_parser_is_strict && extra_params_found)
       {
           return false;
       }
    }
    */
    return true;
}


std::string      FakeMicrophone_ParamsParser::getDocumentationOfDeviceParams() const
{
    std::string doc;
    doc = doc + std::string("\n=============================================\n");
    doc = doc + std::string("This is the help for device: FakeMicrophone\n");
    doc = doc + std::string("\n");
    doc = doc + std::string("This is the list of the parameters accepted by the device:\n");
    doc = doc + std::string("'period': the period of processing thread\n");
    doc = doc + std::string("'waveform': Defines the shape of the waveform. Can be one of the following: sine,sawtooth,square,constant\n");
    doc = doc + std::string("'signal_frequency': Frequency of the generated signal\n");
    doc = doc + std::string("'signal_amplitude': Amplitude of the generated signal\n");
    doc = doc + std::string("'driver_frame_size': the number of samples to process on each iteration of the thread\n");
    doc = doc + std::string("\n");
    doc = doc + std::string("Here are some examples of invocation command with yarpdev, with all params:\n");
    doc = doc + " yarpdev --device fakeMicrophone --period 0.010 --waveform sine --signal_frequency 440 --signal_amplitude 32000 --driver_frame_size 512\n";
    doc = doc + std::string("Using only mandatory params:\n");
    doc = doc + " yarpdev --device fakeMicrophone\n";
    doc = doc + std::string("=============================================\n\n");    return doc;
}
