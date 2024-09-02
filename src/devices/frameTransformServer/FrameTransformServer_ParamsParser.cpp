/*
 * SPDX-FileCopyrightText: 2023-2023 Istituto Italiano di Tecnologia (IIT)
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */


// Generated by yarpDeviceParamParserGenerator (1.0)
// This is an automatically generated file. Please do not edit it.
// It will be re-generated if the cmake flag ALLOW_DEVICE_PARAM_PARSER_GERNERATION is ON.

// Generated on: Sat Apr  6 12:05:03 2024


#include "FrameTransformServer_ParamsParser.h"
#include <yarp/os/LogStream.h>
#include <yarp/os/Value.h>

namespace {
    YARP_LOG_COMPONENT(FrameTransformServerParamsCOMPONENT, "yarp.device.FrameTransformServer")
}


FrameTransformServer_ParamsParser::FrameTransformServer_ParamsParser()
{
}


std::vector<std::string> FrameTransformServer_ParamsParser::getListOfParams() const
{
    std::vector<std::string> params;
    params.push_back("testxml_from");
    params.push_back("testxml_context");
    params.push_back("filexml_option");
    params.push_back("local_rpc");
    params.push_back("FrameTransform_verbose_debug");
    params.push_back("period");
    return params;
}


bool      FrameTransformServer_ParamsParser::parseParams(const yarp::os::Searchable & config)
{
    //Check for --help option
    if (config.check("help"))
    {
        yCInfo(FrameTransformServerParamsCOMPONENT) << getDocumentationOfDeviceParams();
    }

    std::string config_string = config.toString();
    yarp::os::Property prop_check(config_string.c_str());
    //Parser of parameter testxml_from
    {
        if (config.check("testxml_from"))
        {
            m_testxml_from = config.find("testxml_from").asString();
            yCInfo(FrameTransformServerParamsCOMPONENT) << "Parameter 'testxml_from' using value:" << m_testxml_from;
        }
        else
        {
            yCInfo(FrameTransformServerParamsCOMPONENT) << "Parameter 'testxml_from' using DEFAULT value:" << m_testxml_from;
        }
        prop_check.unput("testxml_from");
    }

    //Parser of parameter testxml_context
    {
        if (config.check("testxml_context"))
        {
            m_testxml_context = config.find("testxml_context").asString();
            yCInfo(FrameTransformServerParamsCOMPONENT) << "Parameter 'testxml_context' using value:" << m_testxml_context;
        }
        else
        {
            yCInfo(FrameTransformServerParamsCOMPONENT) << "Parameter 'testxml_context' using DEFAULT value:" << m_testxml_context;
        }
        prop_check.unput("testxml_context");
    }

    //Parser of parameter filexml_option
    {
        if (config.check("filexml_option"))
        {
            m_filexml_option = config.find("filexml_option").asString();
            yCInfo(FrameTransformServerParamsCOMPONENT) << "Parameter 'filexml_option' using value:" << m_filexml_option;
        }
        else
        {
            yCInfo(FrameTransformServerParamsCOMPONENT) << "Parameter 'filexml_option' using DEFAULT value:" << m_filexml_option;
        }
        prop_check.unput("filexml_option");
    }

    //Parser of parameter local_rpc
    {
        if (config.check("local_rpc"))
        {
            m_local_rpc = config.find("local_rpc").asString();
            yCInfo(FrameTransformServerParamsCOMPONENT) << "Parameter 'local_rpc' using value:" << m_local_rpc;
        }
        else
        {
            yCInfo(FrameTransformServerParamsCOMPONENT) << "Parameter 'local_rpc' using DEFAULT value:" << m_local_rpc;
        }
        prop_check.unput("local_rpc");
    }

    //Parser of parameter FrameTransform_verbose_debug
    {
        if (config.check("FrameTransform_verbose_debug"))
        {
            m_FrameTransform_verbose_debug = config.find("FrameTransform_verbose_debug").asBool();
            yCInfo(FrameTransformServerParamsCOMPONENT) << "Parameter 'FrameTransform_verbose_debug' using value:" << m_FrameTransform_verbose_debug;
        }
        else
        {
            yCInfo(FrameTransformServerParamsCOMPONENT) << "Parameter 'FrameTransform_verbose_debug' using DEFAULT value:" << m_FrameTransform_verbose_debug;
        }
        prop_check.unput("FrameTransform_verbose_debug");
    }

    //Parser of parameter period
    {
        if (config.check("period"))
        {
            m_period = config.find("period").asFloat64();
            yCInfo(FrameTransformServerParamsCOMPONENT) << "Parameter 'period' using value:" << m_period;
        }
        else
        {
            yCInfo(FrameTransformServerParamsCOMPONENT) << "Parameter 'period' using DEFAULT value:" << m_period;
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
                yCError(FrameTransformServerParamsCOMPONENT) << "User asking for parameter: "<<it->name <<" which is unknown to this parser!";
                extra_params_found = true;
            }
            else
            {
                yCWarning(FrameTransformServerParamsCOMPONENT) << "User asking for parameter: "<< it->name <<" which is unknown to this parser!";
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


std::string      FrameTransformServer_ParamsParser::getDocumentationOfDeviceParams() const
{
    std::string doc;
    doc = doc + std::string("\n=============================================\n");
    doc = doc + std::string("This is the help for device: FrameTransformServer\n");
    doc = doc + std::string("\n");
    doc = doc + std::string("This is the list of the parameters accepted by the device:\n");
    doc = doc + std::string("'testxml_from': xml configuration file name\n");
    doc = doc + std::string("'testxml_context': xml configuration file context\n");
    doc = doc + std::string("'filexml_option': The name of the xml file containing the needed configuration. if used, the name will be appended to config_xml/\n");
    doc = doc + std::string("'local_rpc': Full name of the rpc port\n");
    doc = doc + std::string("'FrameTransform_verbose_debug': Enable debug prints\n");
    doc = doc + std::string("'period': thread period\n");
    doc = doc + std::string("\n");
    doc = doc + std::string("Here are some examples of invocation command with yarpdev, with all params:\n");
    doc = doc + " yarpdev --device frameTransformServer --testxml_from <optional_value> --testxml_context <optional_value> --filexml_option fts_yarp_only.xml --local_rpc /ftServer/rpc --FrameTransform_verbose_debug false --period 0.10\n";
    doc = doc + std::string("Using only mandatory params:\n");
    doc = doc + " yarpdev --device frameTransformServer\n";
    doc = doc + std::string("=============================================\n\n");    return doc;
}
