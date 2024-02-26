/*
 * SPDX-FileCopyrightText: 2023-2023 Istituto Italiano di Tecnologia (IIT)
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */


// Generated by yarpDeviceParamParserGenerator (1.0)
// This is an automatically generated file. Please do not edit it.
// It will be re-generated if the cmake flag ALLOW_DEVICE_PARAM_PARSER_GERNERATION is ON.

// Generated on: Tue Feb 27 00:56:32 2024


#include "FakeSpeechTranscription_ParamsParser.h"
#include <yarp/os/LogStream.h>
#include <yarp/os/Value.h>

namespace {
    YARP_LOG_COMPONENT(FakeSpeechTranscriptionParamsCOMPONENT, "yarp.device.FakeSpeechTranscription")
}


FakeSpeechTranscription_ParamsParser::FakeSpeechTranscription_ParamsParser()
{
}


std::vector<std::string> FakeSpeechTranscription_ParamsParser::getListOfParams() const
{
    std::vector<std::string> params;
    params.push_back("language");
    return params;
}


bool      FakeSpeechTranscription_ParamsParser::parseParams(const yarp::os::Searchable & config)
{
    //Check for --help option
    if (config.check("help"))
    {
        yCInfo(FakeSpeechTranscriptionParamsCOMPONENT) << getDocumentationOfDeviceParams();
    }

    std::string config_string = config.toString();
    yarp::os::Property prop_check(config_string.c_str());
    //Parser of parameter language
    {
        if (config.check("language"))
        {
            m_language = config.find("language").asString();
            yCInfo(FakeSpeechTranscriptionParamsCOMPONENT) << "Parameter 'language' using value:" << m_language;
        }
        else
        {
            yCInfo(FakeSpeechTranscriptionParamsCOMPONENT) << "Parameter 'language' using DEFAULT value:" << m_language;
        }
        prop_check.unput("language");
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
                yCError(FakeSpeechTranscriptionParamsCOMPONENT) << "User asking for parameter: "<<it->name <<" which is unknown to this parser!";
                extra_params_found = true;
            }
            else
            {
                yCWarning(FakeSpeechTranscriptionParamsCOMPONENT) << "User asking for parameter: "<< it->name <<" which is unknown to this parser!";
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


std::string      FakeSpeechTranscription_ParamsParser::getDocumentationOfDeviceParams() const
{
    std::string doc;
    doc = doc + std::string("\n=============================================\n");
    doc = doc + std::string("This is the help for device: FakeSpeechTranscription\n");
    doc = doc + std::string("\n");
    doc = doc + std::string("This is the list of the parameters accepted by the device:\n");
    doc = doc + std::string("'language': language code\n");
    doc = doc + std::string("\n");
    doc = doc + std::string("Here are some examples of invocation command with yarpdev, with all params:\n");
    doc = doc + " yarpdev --device fakeSpeechTranscription --language auto\n";
    doc = doc + std::string("Using only mandatory params:\n");
    doc = doc + " yarpdev --device fakeSpeechTranscription\n";
    doc = doc + std::string("=============================================\n\n");    return doc;
}
