/*
 * SPDX-FileCopyrightText: 2023-2023 Istituto Italiano di Tecnologia (IIT)
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */


// Generated by yarpDeviceParamParserGenerator (1.0)
// This is an automatically generated file. Please do not edit it.
// It will be re-generated if the cmake flag ALLOW_DEVICE_PARAM_PARSER_GERNERATION is ON.

// Generated on: Thu Mar  7 17:59:43 2024


#include "FakeLocalizer_ParamsParser.h"
#include <yarp/os/LogStream.h>
#include <yarp/os/Value.h>

namespace {
    YARP_LOG_COMPONENT(FakeLocalizerParamsCOMPONENT, "yarp.device.FakeLocalizer")
}


FakeLocalizer_ParamsParser::FakeLocalizer_ParamsParser()
{
}


std::vector<std::string> FakeLocalizer_ParamsParser::getListOfParams() const
{
    std::vector<std::string> params;
    params.push_back("period");
    return params;
}


bool      FakeLocalizer_ParamsParser::parseParams(const yarp::os::Searchable & config)
{
    //Check for --help option
    if (config.check("help"))
    {
        yCInfo(FakeLocalizerParamsCOMPONENT) << getDocumentationOfDeviceParams();
    }

    std::string config_string = config.toString();
    yarp::os::Property prop_check(config_string.c_str());
    //Parser of parameter period
    {
        if (config.check("period"))
        {
            m_period = config.find("period").asFloat64();
            yCInfo(FakeLocalizerParamsCOMPONENT) << "Parameter 'period' using value:" << m_period;
        }
        else
        {
            yCInfo(FakeLocalizerParamsCOMPONENT) << "Parameter 'period' using DEFAULT value:" << m_period;
        }
        prop_check.unput("period");
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
                yCError(FakeLocalizerParamsCOMPONENT) << "User asking for parameter: "<<it->name <<" which is unknown to this parser!";
                extra_params_found = true;
            }
            else
            {
                yCWarning(FakeLocalizerParamsCOMPONENT) << "User asking for parameter: "<< it->name <<" which is unknown to this parser!";
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


std::string      FakeLocalizer_ParamsParser::getDocumentationOfDeviceParams() const
{
    std::string doc;
    doc = doc + std::string("\n=============================================\n");
    doc = doc + std::string("This is the help for device: FakeLocalizer\n");
    doc = doc + std::string("\n");
    doc = doc + std::string("This is the list of the parameters accepted by the device:\n");
    doc = doc + std::string("'period': thread period\n");
    doc = doc + std::string("\n");
    doc = doc + std::string("Here are some examples of invocation command with yarpdev, with all params:\n");
    doc = doc + " yarpdev --device fakeLocalizer --period 0.010\n";
    doc = doc + std::string("Using only mandatory params:\n");
    doc = doc + " yarpdev --device fakeLocalizer\n";
    doc = doc + std::string("=============================================\n\n");    return doc;
}
