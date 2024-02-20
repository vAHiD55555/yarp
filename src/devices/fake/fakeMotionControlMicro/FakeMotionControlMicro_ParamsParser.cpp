/*
 * SPDX-FileCopyrightText: 2023-2023 Istituto Italiano di Tecnologia (IIT)
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */


// Generated by yarpDeviceParamParserGenerator (1.0)
// This is an automatically generated file. Please do not edit it.
// It will be re-generated if the cmake flag ALLOW_DEVICE_PARAM_PARSER_GERNERATION is ON.

// Generated on: Tue Feb 20 00:04:30 2024


#include "FakeMotionControlMicro_ParamsParser.h"
#include <yarp/os/LogStream.h>
#include <yarp/os/Value.h>

namespace {
    YARP_LOG_COMPONENT(FakeMotionControlMicroParamsCOMPONENT, "yarp.device.FakeMotionControlMicro")
}


FakeMotionControlMicro_ParamsParser::FakeMotionControlMicro_ParamsParser()
{
}


std::vector<std::string> FakeMotionControlMicro_ParamsParser::getListOfParams() const
{
    std::vector<std::string> params;
    params.push_back("GENERAL::Joints");
    params.push_back("GENERAL::AxisMap");
    params.push_back("GENERAL::AxisName");
    params.push_back("GENERAL::AxisType");
    params.push_back("GENERAL::Encoder");
    return params;
}


bool      FakeMotionControlMicro_ParamsParser::parseParams(const yarp::os::Searchable & config)
{
    //Check for --help option
    if (config.check("help"))
    {
        yCInfo(FakeMotionControlMicroParamsCOMPONENT) << getDocumentationOfDeviceParams();
    }

    std::string config_string = config.toString();
    yarp::os::Property prop_check(config_string.c_str());
    //Parser of parameter GENERAL::Joints
    {
        yarp::os::Bottle sectionp;
        sectionp = config.findGroup("GENERAL");
        if (sectionp.check("Joints"))
        {
            m_GENERAL_Joints = sectionp.find("Joints").asInt64();
            yCInfo(FakeMotionControlMicroParamsCOMPONENT) << "Parameter 'GENERAL::Joints' using value:" << m_GENERAL_Joints;
        }
        else
        {
            yCInfo(FakeMotionControlMicroParamsCOMPONENT) << "Parameter 'GENERAL::Joints' using DEFAULT value:" << m_GENERAL_Joints;
        }
        prop_check.unput("GENERAL::Joints");
    }

    //Parser of parameter GENERAL::AxisMap
    {
        yarp::os::Bottle sectionp;
        sectionp = config.findGroup("GENERAL");
        if (sectionp.check("AxisMap"))
        {
            {
                m_GENERAL_AxisMap.clear();
                yarp::os::Bottle* tempBot = sectionp.find("AxisMap").asList();
                if (tempBot)
                {
                    for (size_t i=0; i<tempBot->size(); i++)
                    {
                        m_GENERAL_AxisMap.push_back(tempBot->get(i).asInt64());
                    }
                }
                else
                {
                     yError() <<"parameter 'GENERAL_AxisMap' is not a properly formatted bottle";
                }
            }
            yCInfo(FakeMotionControlMicroParamsCOMPONENT) << "Parameter 'GENERAL::AxisMap' using value:" << m_GENERAL_AxisMap;
        }
        else
        {
            yCInfo(FakeMotionControlMicroParamsCOMPONENT) << "Parameter 'GENERAL::AxisMap' using DEFAULT value:" << m_GENERAL_AxisMap;
        }
        prop_check.unput("GENERAL::AxisMap");
    }

    //Parser of parameter GENERAL::AxisName
    {
        yarp::os::Bottle sectionp;
        sectionp = config.findGroup("GENERAL");
        if (sectionp.check("AxisName"))
        {
            {
                m_GENERAL_AxisName.clear();
                yarp::os::Bottle* tempBot = sectionp.find("AxisName").asList();
                if (tempBot)
                {
                    for (size_t i=0; i<tempBot->size(); i++)
                    {
                        m_GENERAL_AxisName.push_back(tempBot->get(i).asString());
                    }
                }
                else
                {
                     yError() <<"parameter 'GENERAL_AxisName' is not a properly formatted bottle";
                }
            }
            yCInfo(FakeMotionControlMicroParamsCOMPONENT) << "Parameter 'GENERAL::AxisName' using value:" << m_GENERAL_AxisName;
        }
        else
        {
            yCInfo(FakeMotionControlMicroParamsCOMPONENT) << "Parameter 'GENERAL::AxisName' using DEFAULT value:" << m_GENERAL_AxisName;
        }
        prop_check.unput("GENERAL::AxisName");
    }

    //Parser of parameter GENERAL::AxisType
    {
        yarp::os::Bottle sectionp;
        sectionp = config.findGroup("GENERAL");
        if (sectionp.check("AxisType"))
        {
            {
                m_GENERAL_AxisType.clear();
                yarp::os::Bottle* tempBot = sectionp.find("AxisType").asList();
                if (tempBot)
                {
                    for (size_t i=0; i<tempBot->size(); i++)
                    {
                        m_GENERAL_AxisType.push_back(tempBot->get(i).asString());
                    }
                }
                else
                {
                     yError() <<"parameter 'GENERAL_AxisType' is not a properly formatted bottle";
                }
            }
            yCInfo(FakeMotionControlMicroParamsCOMPONENT) << "Parameter 'GENERAL::AxisType' using value:" << m_GENERAL_AxisType;
        }
        else
        {
            yCInfo(FakeMotionControlMicroParamsCOMPONENT) << "Parameter 'GENERAL::AxisType' using DEFAULT value:" << m_GENERAL_AxisType;
        }
        prop_check.unput("GENERAL::AxisType");
    }

    //Parser of parameter GENERAL::Encoder
    {
        yarp::os::Bottle sectionp;
        sectionp = config.findGroup("GENERAL");
        if (sectionp.check("Encoder"))
        {
            {
                m_GENERAL_Encoder.clear();
                yarp::os::Bottle* tempBot = sectionp.find("Encoder").asList();
                if (tempBot)
                {
                    for (size_t i=0; i<tempBot->size(); i++)
                    {
                        m_GENERAL_Encoder.push_back(tempBot->get(i).asInt64());
                    }
                }
                else
                {
                     yError() <<"parameter 'GENERAL_Encoder' is not a properly formatted bottle";
                }
            }
            yCInfo(FakeMotionControlMicroParamsCOMPONENT) << "Parameter 'GENERAL::Encoder' using value:" << m_GENERAL_Encoder;
        }
        else
        {
            yCInfo(FakeMotionControlMicroParamsCOMPONENT) << "Parameter 'GENERAL::Encoder' using DEFAULT value:" << m_GENERAL_Encoder;
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
                yCError(FakeMotionControlMicroParamsCOMPONENT) << "User asking for parameter: "<<it->name <<" which is unknown to this parser!";
                extra_params_found = true;
            }
            else
            {
                yCWarning(FakeMotionControlMicroParamsCOMPONENT) << "User asking for parameter: "<< it->name <<" which is unknown to this parser!";
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


std::string      FakeMotionControlMicro_ParamsParser::getDocumentationOfDeviceParams() const
{
    std::string doc;
    doc = doc + std::string("\n=============================================\n");
    doc = doc + std::string("This is the help for device: FakeMotionControlMicro\n");
    doc = doc + std::string("\n");
    doc = doc + std::string("This is the list of the parameters accepted by the device:\n");
    doc = doc + std::string("'GENERAL::Joints': Number of degrees of freedom\n");
    doc = doc + std::string("'GENERAL::AxisMap': a list of reordered indices for the axes\n");
    doc = doc + std::string("'GENERAL::AxisName': a list of strings representing the axes names\n");
    doc = doc + std::string("'GENERAL::AxisType': a list of strings representing the axes type (revolute/prismatic)\n");
    doc = doc + std::string("'GENERAL::Encoder': a list of scales for the encoders\n");
    doc = doc + std::string("\n");
    doc = doc + std::string("Here are some examples of invocation command with yarpdev, with all params:\n");
    doc = doc + " yarpdev --device fakeMotionControlMicro --GENERAL::Joints 1 --GENERAL::AxisMap <optional_value> --GENERAL::AxisName <optional_value> --GENERAL::AxisType <optional_value> --GENERAL::Encoder <optional_value>\n";
    doc = doc + std::string("Using only mandatory params:\n");
    doc = doc + " yarpdev --device fakeMotionControlMicro\n";
    doc = doc + std::string("=============================================\n\n");    return doc;
}
