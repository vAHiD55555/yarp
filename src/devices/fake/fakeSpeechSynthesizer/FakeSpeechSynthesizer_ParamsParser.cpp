/*
 * SPDX-FileCopyrightText: 2023-2023 Istituto Italiano di Tecnologia (IIT)
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */


// Generated by yarpDeviceParamParserGenerator (1.0)
// This is an automatically generated file. Please do not edit it.
// It will be re-generated if the cmake flag ALLOW_DEVICE_PARAM_PARSER_GERNERATION is ON.

// Generated on: Thu Mar  7 17:59:42 2024


#include "FakeSpeechSynthesizer_ParamsParser.h"
#include <yarp/os/LogStream.h>
#include <yarp/os/Value.h>

namespace {
    YARP_LOG_COMPONENT(FakeSpeechSynthesizerParamsCOMPONENT, "yarp.device.FakeSpeechSynthesizer")
}


FakeSpeechSynthesizer_ParamsParser::FakeSpeechSynthesizer_ParamsParser()
{
}


std::vector<std::string> FakeSpeechSynthesizer_ParamsParser::getListOfParams() const
{
    std::vector<std::string> params;
    params.push_back("language");
    params.push_back("voice");
    params.push_back("speed");
    params.push_back("pitch");
    return params;
}


bool      FakeSpeechSynthesizer_ParamsParser::parseParams(const yarp::os::Searchable & config)
{
    //Check for --help option
    if (config.check("help"))
    {
        yCInfo(FakeSpeechSynthesizerParamsCOMPONENT) << getDocumentationOfDeviceParams();
    }

    std::string config_string = config.toString();
    yarp::os::Property prop_check(config_string.c_str());
    //Parser of parameter language
    {
        if (config.check("language"))
        {
            m_language = config.find("language").asString();
            yCInfo(FakeSpeechSynthesizerParamsCOMPONENT) << "Parameter 'language' using value:" << m_language;
        }
        else
        {
            yCInfo(FakeSpeechSynthesizerParamsCOMPONENT) << "Parameter 'language' using DEFAULT value:" << m_language;
        }
        prop_check.unput("language");
    }

    //Parser of parameter voice
    {
        if (config.check("voice"))
        {
            m_voice = config.find("voice").asString();
            yCInfo(FakeSpeechSynthesizerParamsCOMPONENT) << "Parameter 'voice' using value:" << m_voice;
        }
        else
        {
            yCInfo(FakeSpeechSynthesizerParamsCOMPONENT) << "Parameter 'voice' using DEFAULT value:" << m_voice;
        }
        prop_check.unput("voice");
    }

    //Parser of parameter speed
    {
        if (config.check("speed"))
        {
            m_speed = config.find("speed").asFloat64();
            yCInfo(FakeSpeechSynthesizerParamsCOMPONENT) << "Parameter 'speed' using value:" << m_speed;
        }
        else
        {
            yCInfo(FakeSpeechSynthesizerParamsCOMPONENT) << "Parameter 'speed' using DEFAULT value:" << m_speed;
        }
        prop_check.unput("speed");
    }

    //Parser of parameter pitch
    {
        if (config.check("pitch"))
        {
            m_pitch = config.find("pitch").asFloat64();
            yCInfo(FakeSpeechSynthesizerParamsCOMPONENT) << "Parameter 'pitch' using value:" << m_pitch;
        }
        else
        {
            yCInfo(FakeSpeechSynthesizerParamsCOMPONENT) << "Parameter 'pitch' using DEFAULT value:" << m_pitch;
        }
        prop_check.unput("pitch");
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
                yCError(FakeSpeechSynthesizerParamsCOMPONENT) << "User asking for parameter: "<<it->name <<" which is unknown to this parser!";
                extra_params_found = true;
            }
            else
            {
                yCWarning(FakeSpeechSynthesizerParamsCOMPONENT) << "User asking for parameter: "<< it->name <<" which is unknown to this parser!";
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


std::string      FakeSpeechSynthesizer_ParamsParser::getDocumentationOfDeviceParams() const
{
    std::string doc;
    doc = doc + std::string("\n=============================================\n");
    doc = doc + std::string("This is the help for device: FakeSpeechSynthesizer\n");
    doc = doc + std::string("\n");
    doc = doc + std::string("This is the list of the parameters accepted by the device:\n");
    doc = doc + std::string("'language': language code\n");
    doc = doc + std::string("'voice': voice code\n");
    doc = doc + std::string("'speed': speed\n");
    doc = doc + std::string("'pitch': pitch\n");
    doc = doc + std::string("\n");
    doc = doc + std::string("Here are some examples of invocation command with yarpdev, with all params:\n");
    doc = doc + " yarpdev --device fakeSpeechSynthesizer --language auto --voice auto --speed 0.0 --pitch 0.0\n";
    doc = doc + std::string("Using only mandatory params:\n");
    doc = doc + " yarpdev --device fakeSpeechSynthesizer\n";
    doc = doc + std::string("=============================================\n\n");    return doc;
}
