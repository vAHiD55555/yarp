/*
 * SPDX-FileCopyrightText: 2023-2023 Istituto Italiano di Tecnologia (IIT)
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */


// Generated by yarpDeviceParamParserGenerator (1.0)
// This is an automatically generated file. Please do not edit it.
// It will be re-generated if the cmake flag ALLOW_DEVICE_PARAM_PARSER_GERNERATION is ON.

// Generated on: Thu Mar  7 17:59:49 2024


#include "RgbdSensor_nws_yarp_ParamsParser.h"
#include <yarp/os/LogStream.h>
#include <yarp/os/Value.h>

namespace {
    YARP_LOG_COMPONENT(RgbdSensor_nws_yarpParamsCOMPONENT, "yarp.device.RgbdSensor_nws_yarp")
}


RgbdSensor_nws_yarp_ParamsParser::RgbdSensor_nws_yarp_ParamsParser()
{
}


std::vector<std::string> RgbdSensor_nws_yarp_ParamsParser::getListOfParams() const
{
    std::vector<std::string> params;
    params.push_back("period");
    params.push_back("name");
    return params;
}


bool      RgbdSensor_nws_yarp_ParamsParser::parseParams(const yarp::os::Searchable & config)
{
    //Check for --help option
    if (config.check("help"))
    {
        yCInfo(RgbdSensor_nws_yarpParamsCOMPONENT) << getDocumentationOfDeviceParams();
    }

    std::string config_string = config.toString();
    yarp::os::Property prop_check(config_string.c_str());
    //Parser of parameter period
    {
        if (config.check("period"))
        {
            m_period = config.find("period").asFloat64();
            yCInfo(RgbdSensor_nws_yarpParamsCOMPONENT) << "Parameter 'period' using value:" << m_period;
        }
        else
        {
            yCInfo(RgbdSensor_nws_yarpParamsCOMPONENT) << "Parameter 'period' using DEFAULT value:" << m_period;
        }
        prop_check.unput("period");
    }

    //Parser of parameter name
    {
        if (config.check("name"))
        {
            m_name = config.find("name").asString();
            yCInfo(RgbdSensor_nws_yarpParamsCOMPONENT) << "Parameter 'name' using value:" << m_name;
        }
        else
        {
            yCError(RgbdSensor_nws_yarpParamsCOMPONENT) << "Mandatory parameter 'name' not found!";
            yCError(RgbdSensor_nws_yarpParamsCOMPONENT) << "Description of the parameter: Prefix name of the ports opened by the RGBD wrapper, e.g. /robotName/RGBD";
            return false;
        }
        prop_check.unput("name");
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
                yCError(RgbdSensor_nws_yarpParamsCOMPONENT) << "User asking for parameter: "<<it->name <<" which is unknown to this parser!";
                extra_params_found = true;
            }
            else
            {
                yCWarning(RgbdSensor_nws_yarpParamsCOMPONENT) << "User asking for parameter: "<< it->name <<" which is unknown to this parser!";
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


std::string      RgbdSensor_nws_yarp_ParamsParser::getDocumentationOfDeviceParams() const
{
    std::string doc;
    doc = doc + std::string("\n=============================================\n");
    doc = doc + std::string("This is the help for device: RgbdSensor_nws_yarp\n");
    doc = doc + std::string("\n");
    doc = doc + std::string("This is the list of the parameters accepted by the device:\n");
    doc = doc + std::string("'period': refresh period of the broadcasted values in s\n");
    doc = doc + std::string("'name': Prefix name of the ports opened by the RGBD wrapper, e.g. /robotName/RGBD\n");
    doc = doc + std::string("\n");
    doc = doc + std::string("Here are some examples of invocation command with yarpdev, with all params:\n");
    doc = doc + " yarpdev --device rgbdSensor_nws_yarp --period 0.02 --name <mandatory_value>\n";
    doc = doc + std::string("Using only mandatory params:\n");
    doc = doc + " yarpdev --device rgbdSensor_nws_yarp --name <mandatory_value>\n";
    doc = doc + std::string("=============================================\n\n");    return doc;
}
