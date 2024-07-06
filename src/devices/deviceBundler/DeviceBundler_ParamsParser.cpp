/*
 * SPDX-FileCopyrightText: 2023-2023 Istituto Italiano di Tecnologia (IIT)
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */


// Generated by yarpDeviceParamParserGenerator (1.0)
// This is an automatically generated file. Please do not edit it.
// It will be re-generated if the cmake flag ALLOW_DEVICE_PARAM_PARSER_GERNERATION is ON.

// Generated on: Thu Mar  7 17:59:50 2024


#include "DeviceBundler_ParamsParser.h"
#include <yarp/os/LogStream.h>
#include <yarp/os/Value.h>

namespace {
    YARP_LOG_COMPONENT(DeviceBundlerParamsCOMPONENT, "yarp.device.DeviceBundler")
}


DeviceBundler_ParamsParser::DeviceBundler_ParamsParser()
{
}


std::vector<std::string> DeviceBundler_ParamsParser::getListOfParams() const
{
    std::vector<std::string> params;
    params.push_back("wrapper_device");
    params.push_back("attached_device");
    params.push_back("doNotAttach");
    return params;
}


bool      DeviceBundler_ParamsParser::parseParams(const yarp::os::Searchable & config)
{
    //Check for --help option
    if (config.check("help"))
    {
        yCInfo(DeviceBundlerParamsCOMPONENT) << getDocumentationOfDeviceParams();
    }

    std::string config_string = config.toString();
    yarp::os::Property prop_check(config_string.c_str());
    //Parser of parameter wrapper_device
    {
        if (config.check("wrapper_device"))
        {
            m_wrapper_device = config.find("wrapper_device").asString();
            yCInfo(DeviceBundlerParamsCOMPONENT) << "Parameter 'wrapper_device' using value:" << m_wrapper_device;
        }
        else
        {
            yCError(DeviceBundlerParamsCOMPONENT) << "Mandatory parameter 'wrapper_device' not found!";
            yCError(DeviceBundlerParamsCOMPONENT) << "Description of the parameter: Name of the wrapper device";
            return false;
        }
        prop_check.unput("wrapper_device");
    }

    //Parser of parameter attached_device
    {
        if (config.check("attached_device"))
        {
            m_attached_device = config.find("attached_device").asString();
            yCInfo(DeviceBundlerParamsCOMPONENT) << "Parameter 'attached_device' using value:" << m_attached_device;
        }
        else
        {
            yCError(DeviceBundlerParamsCOMPONENT) << "Mandatory parameter 'attached_device' not found!";
            yCError(DeviceBundlerParamsCOMPONENT) << "Description of the parameter: Name of the subdevice that will be attached to the wrapper device";
            return false;
        }
        prop_check.unput("attached_device");
    }

    //Parser of parameter doNotAttach
    {
        if (config.check("doNotAttach"))
        {
            m_doNotAttach = config.find("doNotAttach").asBool();
            yCInfo(DeviceBundlerParamsCOMPONENT) << "Parameter 'doNotAttach' using value:" << m_doNotAttach;
        }
        else
        {
            yCInfo(DeviceBundlerParamsCOMPONENT) << "Parameter 'doNotAttach' using DEFAULT value:" << m_doNotAttach;
        }
        prop_check.unput("doNotAttach");
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
                yCError(DeviceBundlerParamsCOMPONENT) << "User asking for parameter: "<<it->name <<" which is unknown to this parser!";
                extra_params_found = true;
            }
            else
            {
                yCWarning(DeviceBundlerParamsCOMPONENT) << "User asking for parameter: "<< it->name <<" which is unknown to this parser!";
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


std::string      DeviceBundler_ParamsParser::getDocumentationOfDeviceParams() const
{
    std::string doc;
    doc = doc + std::string("\n=============================================\n");
    doc = doc + std::string("This is the help for device: DeviceBundler\n");
    doc = doc + std::string("\n");
    doc = doc + std::string("This is the list of the parameters accepted by the device:\n");
    doc = doc + std::string("'wrapper_device': Name of the wrapper device\n");
    doc = doc + std::string("'attached_device': Name of the subdevice that will be attached to the wrapper device\n");
    doc = doc + std::string("'doNotAttach': If set to true, the two devices are opened, but not attached\n");
    doc = doc + std::string("\n");
    doc = doc + std::string("Here are some examples of invocation command with yarpdev, with all params:\n");
    doc = doc + " yarpdev --device deviceBundler --wrapper_device device_name1 --attached_device device_name2 --doNotAttach false\n";
    doc = doc + std::string("Using only mandatory params:\n");
    doc = doc + " yarpdev --device deviceBundler --wrapper_device device_name1 --attached_device device_name2\n";
    doc = doc + std::string("=============================================\n\n");    return doc;
}
