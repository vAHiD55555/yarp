/*
 * SPDX-FileCopyrightText: 2023-2023 Istituto Italiano di Tecnologia (IIT)
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */


// Generated by yarpDeviceParamParserGenerator (1.0)
// This is an automatically generated file. Please do not edit it.
// It will be re-generated if the cmake flag ALLOW_DEVICE_PARAM_PARSER_GERNERATION is ON.

// Generated on: Mon Feb 12 13:43:55 2024


#include "FakeMotionControl_ParamsParser.h"
#include <yarp/os/LogStream.h>
#include <yarp/os/Value.h>

namespace {
    YARP_LOG_COMPONENT(FakeMotionControlParamsCOMPONENT, "yarp.device.FakeMotionControl")
}


std::vector<std::string> FakeMotionControl_ParamsParser::getListOfParams() const
{
    std::vector<std::string> params;
    params.push_back("GENERAL::joints");
    params.push_back("GENERAL::AxisMap");
    params.push_back("GENERAL::AxisName");
    params.push_back("GENERAL::AxisType");
    params.push_back("GENERAL::ampsToSensor");
    params.push_back("GENERAL::fullscalePWM");
    params.push_back("GENERAL::Encoder");
    return params;
}


bool      FakeMotionControl_ParamsParser::parseParams(const yarp::os::Searchable & config)
{
    //Check for --help option
    if (config.check("help"))
    {
        yCInfo(FakeMotionControlParamsCOMPONENT) << getDocumentationOfDeviceParams();
    }

    std::string config_string = config.toString();
    yarp::os::Property prop_check(config_string.c_str());
    //Parser of parameter GENERAL::joints
    {
        yarp::os::Bottle sectionp;
        sectionp = config.findGroup("GENERAL");
        if (sectionp.check("joints"))
        {
            m_GENERAL_joints = sectionp.find("joints").asInt64();
            yCInfo(FakeMotionControlParamsCOMPONENT) << "Parameter 'GENERAL::joints' using value:" << m_GENERAL_joints;
        }
        else
        {
            yCInfo(FakeMotionControlParamsCOMPONENT) << "Parameter 'GENERAL::joints' using DEFAULT value:" << m_GENERAL_joints;
        }
        prop_check.unput("GENERAL::joints");
    }

    //Parser of parameter GENERAL::AxisMap
    {
        yarp::os::Bottle sectionp;
        sectionp = config.findGroup("GENERAL");
        if (sectionp.check("AxisMap"))
        {
            m_GENERAL_AxisMap = sectionp.find("AxisMap").asString();
            yCInfo(FakeMotionControlParamsCOMPONENT) << "Parameter 'GENERAL::AxisMap' using value:" << m_GENERAL_AxisMap;
        }
        else
        {
            yCInfo(FakeMotionControlParamsCOMPONENT) << "Parameter 'GENERAL::AxisMap' using DEFAULT value:" << m_GENERAL_AxisMap;
        }
        prop_check.unput("GENERAL::AxisMap");
    }

    //Parser of parameter GENERAL::AxisName
    {
        yarp::os::Bottle sectionp;
        sectionp = config.findGroup("GENERAL");
        if (sectionp.check("AxisName"))
        {
            m_GENERAL_AxisName = sectionp.find("AxisName").asString();
            yCInfo(FakeMotionControlParamsCOMPONENT) << "Parameter 'GENERAL::AxisName' using value:" << m_GENERAL_AxisName;
        }
        else
        {
            yCInfo(FakeMotionControlParamsCOMPONENT) << "Parameter 'GENERAL::AxisName' using DEFAULT value:" << m_GENERAL_AxisName;
        }
        prop_check.unput("GENERAL::AxisName");
    }

    //Parser of parameter GENERAL::AxisType
    {
        yarp::os::Bottle sectionp;
        sectionp = config.findGroup("GENERAL");
        if (sectionp.check("AxisType"))
        {
            m_GENERAL_AxisType = sectionp.find("AxisType").asString();
            yCInfo(FakeMotionControlParamsCOMPONENT) << "Parameter 'GENERAL::AxisType' using value:" << m_GENERAL_AxisType;
        }
        else
        {
            yCInfo(FakeMotionControlParamsCOMPONENT) << "Parameter 'GENERAL::AxisType' using DEFAULT value:" << m_GENERAL_AxisType;
        }
        prop_check.unput("GENERAL::AxisType");
    }

    //Parser of parameter GENERAL::ampsToSensor
    {
        yarp::os::Bottle sectionp;
        sectionp = config.findGroup("GENERAL");
        if (sectionp.check("ampsToSensor"))
        {
            m_GENERAL_ampsToSensor = sectionp.find("ampsToSensor").asString();
            yCInfo(FakeMotionControlParamsCOMPONENT) << "Parameter 'GENERAL::ampsToSensor' using value:" << m_GENERAL_ampsToSensor;
        }
        else
        {
            yCInfo(FakeMotionControlParamsCOMPONENT) << "Parameter 'GENERAL::ampsToSensor' using DEFAULT value:" << m_GENERAL_ampsToSensor;
        }
        prop_check.unput("GENERAL::ampsToSensor");
    }

    //Parser of parameter GENERAL::fullscalePWM
    {
        yarp::os::Bottle sectionp;
        sectionp = config.findGroup("GENERAL");
        if (sectionp.check("fullscalePWM"))
        {
            m_GENERAL_fullscalePWM = sectionp.find("fullscalePWM").asString();
            yCInfo(FakeMotionControlParamsCOMPONENT) << "Parameter 'GENERAL::fullscalePWM' using value:" << m_GENERAL_fullscalePWM;
        }
        else
        {
            yCInfo(FakeMotionControlParamsCOMPONENT) << "Parameter 'GENERAL::fullscalePWM' using DEFAULT value:" << m_GENERAL_fullscalePWM;
        }
        prop_check.unput("GENERAL::fullscalePWM");
    }

    //Parser of parameter GENERAL::Encoder
    {
        yarp::os::Bottle sectionp;
        sectionp = config.findGroup("GENERAL");
        if (sectionp.check("Encoder"))
        {
            m_GENERAL_Encoder = sectionp.find("Encoder").asString();
            yCInfo(FakeMotionControlParamsCOMPONENT) << "Parameter 'GENERAL::Encoder' using value:" << m_GENERAL_Encoder;
        }
        else
        {
            yCInfo(FakeMotionControlParamsCOMPONENT) << "Parameter 'GENERAL::Encoder' using DEFAULT value:" << m_GENERAL_Encoder;
        }
        prop_check.unput("GENERAL::Encoder");
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
                yCError(FakeMotionControlParamsCOMPONENT) << "User asking for parameter: "<<it->name <<" which is unknown to this parser!";
                extra_params_found = true;
            }
            else
            {
                yCWarning(FakeMotionControlParamsCOMPONENT) << "User asking for parameter: "<< it->name <<" which is unknown to this parser!";
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


std::string      FakeMotionControl_ParamsParser::getDocumentationOfDeviceParams() const
{
    std::string doc;
    doc = doc + std::string("\n=============================================\n");
    doc = doc + std::string("This is the help for device: FakeMotionControl\n");
    doc = doc + std::string("\n");
    doc = doc + std::string("This is the list of the parameters accepted by the device:\n");
    doc = doc + std::string("'GENERAL::joints': Number of degrees of freedom\n");
    doc = doc + std::string("'GENERAL::AxisMap': a list of reordered indices for the axes\n");
    doc = doc + std::string("'GENERAL::AxisName': a list of strings representing the axes names\n");
    doc = doc + std::string("'GENERAL::AxisType': a list of strings representing the axes type (revolute/prismatic)\n");
    doc = doc + std::string("'GENERAL::ampsToSensor': a list of scales for the ampsToSensor conversion factors\n");
    doc = doc + std::string("'GENERAL::fullscalePWM': a list of scales for the fullscalePWM conversion factors\n");
    doc = doc + std::string("'GENERAL::Encoder': a list of scales for the encoders\n");
    doc = doc + std::string("\n");
    doc = doc + std::string("Here are some examples of invocation command with yarpdev, with all params:\n");
    doc = doc + " yarpdev --device FakeMotionControl --GENERAL::joints 1 --GENERAL::AxisMap <optional_value> --GENERAL::AxisName <optional_value> --GENERAL::AxisType <optional_value> --GENERAL::ampsToSensor <optional_value> --GENERAL::fullscalePWM <optional_value> --GENERAL::Encoder <optional_value>\n";
    doc = doc + std::string("Using only mandatory params:\n");
    doc = doc + " yarpdev --device FakeMotionControl\n";
    doc = doc + std::string("=============================================\n\n");    return doc;
}
