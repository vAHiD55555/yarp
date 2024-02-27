/*
 * SPDX-FileCopyrightText: 2023-2023 Istituto Italiano di Tecnologia (IIT)
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */


// Generated by yarpDeviceParamParserGenerator (1.0)
// This is an automatically generated file. Please do not edit it.
// It will be re-generated if the cmake flag ALLOW_DEVICE_PARAM_PARSER_GERNERATION is ON.

// Generated on: Tue Feb 27 14:27:36 2024


#include "ControlBoardCouplingHandler_ParamsParser.h"
#include <yarp/os/LogStream.h>
#include <yarp/os/Value.h>

namespace {
    YARP_LOG_COMPONENT(ControlBoardCouplingHandlerParamsCOMPONENT, "yarp.device.ControlBoardCouplingHandler")
}


ControlBoardCouplingHandler_ParamsParser::ControlBoardCouplingHandler_ParamsParser()
{
}


std::vector<std::string> ControlBoardCouplingHandler_ParamsParser::getListOfParams() const
{
    std::vector<std::string> params;
    params.push_back("jointNames");
    params.push_back("LIMITS::");
    params.push_back("LIMITS::jntPosMin");
    params.push_back("LIMITS::jntPosMax");
    params.push_back("COUPLING::");
    params.push_back("COUPLING::actuatedAxesNames");
    params.push_back("COUPLING::actuatedAxesPosMin");
    params.push_back("COUPLING::actuatedAxesPosMax");
    params.push_back("COUPLING_PARAMS::");
    return params;
}


bool      ControlBoardCouplingHandler_ParamsParser::parseParams(const yarp::os::Searchable & config)
{
    //Check for --help option
    if (config.check("help"))
    {
        yCInfo(ControlBoardCouplingHandlerParamsCOMPONENT) << getDocumentationOfDeviceParams();
    }

    std::string config_string = config.toString();
    yarp::os::Property prop_check(config_string.c_str());
    //Parser of parameter jointNames
    {
        if (config.check("jointNames"))
        {
            {
                m_jointNames.clear();
                yarp::os::Bottle* tempBot = config.find("jointNames").asList();
                if (tempBot)
                {
                    std::string tempBots = tempBot->toString();
                    for (size_t i=0; i<tempBot->size(); i++)
                    {
                        m_jointNames.push_back(tempBot->get(i).asString());
                    }
                }
                else
                {
                     yCError(ControlBoardCouplingHandlerParamsCOMPONENT) <<"parameter 'jointNames' is not a properly formatted bottle";
                }
            }
            yCInfo(ControlBoardCouplingHandlerParamsCOMPONENT) << "Parameter 'jointNames' using value:" << m_jointNames;
        }
        else
        {
            yCError(ControlBoardCouplingHandlerParamsCOMPONENT) << "Mandatory parameter 'jointNames' not found!";
            yCError(ControlBoardCouplingHandlerParamsCOMPONENT) << "Description of the parameter: Names of the physical joints";
            return false;
        }
        prop_check.unput("jointNames");
    }

    //Parser of parameter LIMITS::
    {
        yarp::os::Bottle sectionp;
        sectionp = config.findGroup("LIMITS");
        if (sectionp.check(""))
        {
            m_LIMITS_ = sectionp.find("").asString();
            yCInfo(ControlBoardCouplingHandlerParamsCOMPONENT) << "Parameter 'LIMITS::' using value:" << m_LIMITS_;
        }
        else
        {
            yCError(ControlBoardCouplingHandlerParamsCOMPONENT) << "Mandatory parameter 'LIMITS::' not found!";
            yCError(ControlBoardCouplingHandlerParamsCOMPONENT) << "Description of the parameter: string containing the physical joint limits";
            return false;
        }
        prop_check.unput("LIMITS::");
    }

    //Parser of parameter LIMITS::jntPosMin
    {
        yarp::os::Bottle sectionp;
        sectionp = config.findGroup("LIMITS");
        if (sectionp.check("jntPosMin"))
        {
            {
                m_LIMITS_jntPosMin.clear();
                yarp::os::Bottle* tempBot = sectionp.find("jntPosMin").asList();
                if (tempBot)
                {
                    std::string tempBots = tempBot->toString();
                    for (size_t i=0; i<tempBot->size(); i++)
                    {
                        m_LIMITS_jntPosMin.push_back(tempBot->get(i).asFloat64());
                    }
                }
                else
                {
                     yCError(ControlBoardCouplingHandlerParamsCOMPONENT) <<"parameter 'LIMITS_jntPosMin' is not a properly formatted bottle";
                }
            }
            yCInfo(ControlBoardCouplingHandlerParamsCOMPONENT) << "Parameter 'LIMITS::jntPosMin' using value:" << m_LIMITS_jntPosMin;
        }
        else
        {
            yCError(ControlBoardCouplingHandlerParamsCOMPONENT) << "Mandatory parameter 'LIMITS::jntPosMin' not found!";
            yCError(ControlBoardCouplingHandlerParamsCOMPONENT) << "Description of the parameter: Phyisical joints' position minimum";
            return false;
        }
        prop_check.unput("LIMITS::jntPosMin");
    }

    //Parser of parameter LIMITS::jntPosMax
    {
        yarp::os::Bottle sectionp;
        sectionp = config.findGroup("LIMITS");
        if (sectionp.check("jntPosMax"))
        {
            {
                m_LIMITS_jntPosMax.clear();
                yarp::os::Bottle* tempBot = sectionp.find("jntPosMax").asList();
                if (tempBot)
                {
                    std::string tempBots = tempBot->toString();
                    for (size_t i=0; i<tempBot->size(); i++)
                    {
                        m_LIMITS_jntPosMax.push_back(tempBot->get(i).asFloat64());
                    }
                }
                else
                {
                     yCError(ControlBoardCouplingHandlerParamsCOMPONENT) <<"parameter 'LIMITS_jntPosMax' is not a properly formatted bottle";
                }
            }
            yCInfo(ControlBoardCouplingHandlerParamsCOMPONENT) << "Parameter 'LIMITS::jntPosMax' using value:" << m_LIMITS_jntPosMax;
        }
        else
        {
            yCError(ControlBoardCouplingHandlerParamsCOMPONENT) << "Mandatory parameter 'LIMITS::jntPosMax' not found!";
            yCError(ControlBoardCouplingHandlerParamsCOMPONENT) << "Description of the parameter: Phyisical joints' position maximum";
            return false;
        }
        prop_check.unput("LIMITS::jntPosMax");
    }

    //Parser of parameter COUPLING::
    {
        yarp::os::Bottle sectionp;
        sectionp = config.findGroup("COUPLING");
        if (sectionp.check(""))
        {
            m_COUPLING_ = sectionp.find("").asString();
            yCInfo(ControlBoardCouplingHandlerParamsCOMPONENT) << "Parameter 'COUPLING::' using value:" << m_COUPLING_;
        }
        else
        {
            yCError(ControlBoardCouplingHandlerParamsCOMPONENT) << "Mandatory parameter 'COUPLING::' not found!";
            yCError(ControlBoardCouplingHandlerParamsCOMPONENT) << "Description of the parameter: The string containing the coupling description";
            return false;
        }
        prop_check.unput("COUPLING::");
    }

    //Parser of parameter COUPLING::actuatedAxesNames
    {
        yarp::os::Bottle sectionp;
        sectionp = config.findGroup("COUPLING");
        if (sectionp.check("actuatedAxesNames"))
        {
            {
                m_COUPLING_actuatedAxesNames.clear();
                yarp::os::Bottle* tempBot = sectionp.find("actuatedAxesNames").asList();
                if (tempBot)
                {
                    std::string tempBots = tempBot->toString();
                    for (size_t i=0; i<tempBot->size(); i++)
                    {
                        m_COUPLING_actuatedAxesNames.push_back(tempBot->get(i).asString());
                    }
                }
                else
                {
                     yCError(ControlBoardCouplingHandlerParamsCOMPONENT) <<"parameter 'COUPLING_actuatedAxesNames' is not a properly formatted bottle";
                }
            }
            yCInfo(ControlBoardCouplingHandlerParamsCOMPONENT) << "Parameter 'COUPLING::actuatedAxesNames' using value:" << m_COUPLING_actuatedAxesNames;
        }
        else
        {
            yCError(ControlBoardCouplingHandlerParamsCOMPONENT) << "Mandatory parameter 'COUPLING::actuatedAxesNames' not found!";
            yCError(ControlBoardCouplingHandlerParamsCOMPONENT) << "Description of the parameter: Names of the actuated axes";
            return false;
        }
        prop_check.unput("COUPLING::actuatedAxesNames");
    }

    //Parser of parameter COUPLING::actuatedAxesPosMin
    {
        yarp::os::Bottle sectionp;
        sectionp = config.findGroup("COUPLING");
        if (sectionp.check("actuatedAxesPosMin"))
        {
            {
                m_COUPLING_actuatedAxesPosMin.clear();
                yarp::os::Bottle* tempBot = sectionp.find("actuatedAxesPosMin").asList();
                if (tempBot)
                {
                    std::string tempBots = tempBot->toString();
                    for (size_t i=0; i<tempBot->size(); i++)
                    {
                        m_COUPLING_actuatedAxesPosMin.push_back(tempBot->get(i).asString());
                    }
                }
                else
                {
                     yCError(ControlBoardCouplingHandlerParamsCOMPONENT) <<"parameter 'COUPLING_actuatedAxesPosMin' is not a properly formatted bottle";
                }
            }
            yCInfo(ControlBoardCouplingHandlerParamsCOMPONENT) << "Parameter 'COUPLING::actuatedAxesPosMin' using value:" << m_COUPLING_actuatedAxesPosMin;
        }
        else
        {
            yCError(ControlBoardCouplingHandlerParamsCOMPONENT) << "Mandatory parameter 'COUPLING::actuatedAxesPosMin' not found!";
            yCError(ControlBoardCouplingHandlerParamsCOMPONENT) << "Description of the parameter: Actuated axes' position minimum";
            return false;
        }
        prop_check.unput("COUPLING::actuatedAxesPosMin");
    }

    //Parser of parameter COUPLING::actuatedAxesPosMax
    {
        yarp::os::Bottle sectionp;
        sectionp = config.findGroup("COUPLING");
        if (sectionp.check("actuatedAxesPosMax"))
        {
            {
                m_COUPLING_actuatedAxesPosMax.clear();
                yarp::os::Bottle* tempBot = sectionp.find("actuatedAxesPosMax").asList();
                if (tempBot)
                {
                    std::string tempBots = tempBot->toString();
                    for (size_t i=0; i<tempBot->size(); i++)
                    {
                        m_COUPLING_actuatedAxesPosMax.push_back(tempBot->get(i).asString());
                    }
                }
                else
                {
                     yCError(ControlBoardCouplingHandlerParamsCOMPONENT) <<"parameter 'COUPLING_actuatedAxesPosMax' is not a properly formatted bottle";
                }
            }
            yCInfo(ControlBoardCouplingHandlerParamsCOMPONENT) << "Parameter 'COUPLING::actuatedAxesPosMax' using value:" << m_COUPLING_actuatedAxesPosMax;
        }
        else
        {
            yCError(ControlBoardCouplingHandlerParamsCOMPONENT) << "Mandatory parameter 'COUPLING::actuatedAxesPosMax' not found!";
            yCError(ControlBoardCouplingHandlerParamsCOMPONENT) << "Description of the parameter: Actuated axes' position maximum";
            return false;
        }
        prop_check.unput("COUPLING::actuatedAxesPosMax");
    }

    //Parser of parameter COUPLING_PARAMS::
    {
        yarp::os::Bottle sectionp;
        sectionp = config.findGroup("COUPLING_PARAMS");
        if (sectionp.check(""))
        {
            m_COUPLING_PARAMS_ = sectionp.find("").asString();
            yCInfo(ControlBoardCouplingHandlerParamsCOMPONENT) << "Parameter 'COUPLING_PARAMS::' using value:" << m_COUPLING_PARAMS_;
        }
        else
        {
            yCError(ControlBoardCouplingHandlerParamsCOMPONENT) << "Mandatory parameter 'COUPLING_PARAMS::' not found!";
            yCError(ControlBoardCouplingHandlerParamsCOMPONENT) << "Description of the parameter: The string containing the coupling params";
            return false;
        }
        prop_check.unput("COUPLING_PARAMS::");
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
                yCError(ControlBoardCouplingHandlerParamsCOMPONENT) << "User asking for parameter: "<<it->name <<" which is unknown to this parser!";
                extra_params_found = true;
            }
            else
            {
                yCWarning(ControlBoardCouplingHandlerParamsCOMPONENT) << "User asking for parameter: "<< it->name <<" which is unknown to this parser!";
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


std::string      ControlBoardCouplingHandler_ParamsParser::getDocumentationOfDeviceParams() const
{
    std::string doc;
    doc = doc + std::string("\n=============================================\n");
    doc = doc + std::string("This is the help for device: ControlBoardCouplingHandler\n");
    doc = doc + std::string("\n");
    doc = doc + std::string("This is the list of the parameters accepted by the device:\n");
    doc = doc + std::string("'jointNames': Names of the physical joints\n");
    doc = doc + std::string("'LIMITS::': string containing the physical joint limits\n");
    doc = doc + std::string("'LIMITS::jntPosMin': Phyisical joints' position minimum\n");
    doc = doc + std::string("'LIMITS::jntPosMax': Phyisical joints' position maximum\n");
    doc = doc + std::string("'COUPLING::': The string containing the coupling description\n");
    doc = doc + std::string("'COUPLING::actuatedAxesNames': Names of the actuated axes\n");
    doc = doc + std::string("'COUPLING::actuatedAxesPosMin': Actuated axes' position minimum\n");
    doc = doc + std::string("'COUPLING::actuatedAxesPosMax': Actuated axes' position maximum\n");
    doc = doc + std::string("'COUPLING_PARAMS::': The string containing the coupling params\n");
    doc = doc + std::string("\n");
    doc = doc + std::string("Here are some examples of invocation command with yarpdev, with all params:\n");
    doc = doc + " yarpdev --device controlBoardCouplingHandler --jointNames <mandatory_value> --LIMITS:: <mandatory_value> --LIMITS::jntPosMin <mandatory_value> --LIMITS::jntPosMax <mandatory_value> --COUPLING:: <mandatory_value> --COUPLING::actuatedAxesNames <mandatory_value> --COUPLING::actuatedAxesPosMin <mandatory_value> --COUPLING::actuatedAxesPosMax <mandatory_value> --COUPLING_PARAMS:: <mandatory_value>\n";
    doc = doc + std::string("Using only mandatory params:\n");
    doc = doc + " yarpdev --device controlBoardCouplingHandler --jointNames <mandatory_value> --LIMITS:: <mandatory_value> --LIMITS::jntPosMin <mandatory_value> --LIMITS::jntPosMax <mandatory_value> --COUPLING:: <mandatory_value> --COUPLING::actuatedAxesNames <mandatory_value> --COUPLING::actuatedAxesPosMin <mandatory_value> --COUPLING::actuatedAxesPosMax <mandatory_value> --COUPLING_PARAMS:: <mandatory_value>\n";
    doc = doc + std::string("=============================================\n\n");    return doc;
}
