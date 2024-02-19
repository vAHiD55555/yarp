/*
 * SPDX-FileCopyrightText: 2023-2023 Istituto Italiano di Tecnologia (IIT)
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */


// Generated by yarpDeviceParamParserGenerator (1.0)
// This is an automatically generated file. Please do not edit it.
// It will be re-generated if the cmake flag ALLOW_DEVICE_PARAM_PARSER_GERNERATION is ON.

// Generated on: Mon Feb 19 16:27:58 2024


#include "FakeBattery_ParamsParser.h"
#include <yarp/os/LogStream.h>
#include <yarp/os/Value.h>

namespace {
    YARP_LOG_COMPONENT(FakeBatteryParamsCOMPONENT, "yarp.device.FakeBattery")
}


FakeBattery_ParamsParser::FakeBattery_ParamsParser()
{
}


std::vector<std::string> FakeBattery_ParamsParser::getListOfParams() const
{
    std::vector<std::string> params;
    params.push_back("period");
    params.push_back("charge");
    params.push_back("voltage");
    params.push_back("current");
    params.push_back("temperature");
    params.push_back("info");
    params.push_back("rpc_port_name");
    return params;
}


bool      FakeBattery_ParamsParser::parseParams(const yarp::os::Searchable & config)
{
    //Check for --help option
    if (config.check("help"))
    {
        yCInfo(FakeBatteryParamsCOMPONENT) << getDocumentationOfDeviceParams();
    }

    std::string config_string = config.toString();
    yarp::os::Property prop_check(config_string.c_str());
    //Parser of parameter period
    {
        if (config.check("period"))
        {
            m_period = config.find("period").asFloat64();
            yCInfo(FakeBatteryParamsCOMPONENT) << "Parameter 'period' using value:" << m_period;
        }
        else
        {
            yCInfo(FakeBatteryParamsCOMPONENT) << "Parameter 'period' using DEFAULT value:" << m_period;
        }
        prop_check.unput("period");
    }

    //Parser of parameter charge
    {
        if (config.check("charge"))
        {
            m_charge = config.find("charge").asFloat64();
            yCInfo(FakeBatteryParamsCOMPONENT) << "Parameter 'charge' using value:" << m_charge;
        }
        else
        {
            yCInfo(FakeBatteryParamsCOMPONENT) << "Parameter 'charge' using DEFAULT value:" << m_charge;
        }
        prop_check.unput("charge");
    }

    //Parser of parameter voltage
    {
        if (config.check("voltage"))
        {
            m_voltage = config.find("voltage").asFloat64();
            yCInfo(FakeBatteryParamsCOMPONENT) << "Parameter 'voltage' using value:" << m_voltage;
        }
        else
        {
            yCInfo(FakeBatteryParamsCOMPONENT) << "Parameter 'voltage' using DEFAULT value:" << m_voltage;
        }
        prop_check.unput("voltage");
    }

    //Parser of parameter current
    {
        if (config.check("current"))
        {
            m_current = config.find("current").asFloat64();
            yCInfo(FakeBatteryParamsCOMPONENT) << "Parameter 'current' using value:" << m_current;
        }
        else
        {
            yCInfo(FakeBatteryParamsCOMPONENT) << "Parameter 'current' using DEFAULT value:" << m_current;
        }
        prop_check.unput("current");
    }

    //Parser of parameter temperature
    {
        if (config.check("temperature"))
        {
            m_temperature = config.find("temperature").asFloat64();
            yCInfo(FakeBatteryParamsCOMPONENT) << "Parameter 'temperature' using value:" << m_temperature;
        }
        else
        {
            yCInfo(FakeBatteryParamsCOMPONENT) << "Parameter 'temperature' using DEFAULT value:" << m_temperature;
        }
        prop_check.unput("temperature");
    }

    //Parser of parameter info
    {
        if (config.check("info"))
        {
            m_info = config.find("info").asString();
            yCInfo(FakeBatteryParamsCOMPONENT) << "Parameter 'info' using value:" << m_info;
        }
        else
        {
            yCInfo(FakeBatteryParamsCOMPONENT) << "Parameter 'info' using DEFAULT value:" << m_info;
        }
        prop_check.unput("info");
    }

    //Parser of parameter rpc_port_name
    {
        if (config.check("rpc_port_name"))
        {
            m_rpc_port_name = config.find("rpc_port_name").asString();
            yCInfo(FakeBatteryParamsCOMPONENT) << "Parameter 'rpc_port_name' using value:" << m_rpc_port_name;
        }
        else
        {
            yCInfo(FakeBatteryParamsCOMPONENT) << "Parameter 'rpc_port_name' using DEFAULT value:" << m_rpc_port_name;
        }
        prop_check.unput("rpc_port_name");
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
                yCError(FakeBatteryParamsCOMPONENT) << "User asking for parameter: "<<it->name <<" which is unknown to this parser!";
                extra_params_found = true;
            }
            else
            {
                yCWarning(FakeBatteryParamsCOMPONENT) << "User asking for parameter: "<< it->name <<" which is unknown to this parser!";
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


std::string      FakeBattery_ParamsParser::getDocumentationOfDeviceParams() const
{
    std::string doc;
    doc = doc + std::string("\n=============================================\n");
    doc = doc + std::string("This is the help for device: FakeBattery\n");
    doc = doc + std::string("\n");
    doc = doc + std::string("This is the list of the parameters accepted by the device:\n");
    doc = doc + std::string("'period': thread period\n");
    doc = doc + std::string("'charge': Initial charge\n");
    doc = doc + std::string("'voltage': Initial voltage\n");
    doc = doc + std::string("'current': Initial current\n");
    doc = doc + std::string("'temperature': Initial temperature\n");
    doc = doc + std::string("'info': Initial battery information\n");
    doc = doc + std::string("'rpc_port_name': Full rpc port name\n");
    doc = doc + std::string("\n");
    doc = doc + std::string("Here are some examples of invocation command with yarpdev, with all params:\n");
    doc = doc + " yarpdev --device fakeBattery --period 0.02 --charge 50.0 --voltage 30.0 --current 3.0 --temperature 20.0 --info Fake battery system v2.0 --rpc_port_name /fakeBattery/rpc\n";
    doc = doc + std::string("Using only mandatory params:\n");
    doc = doc + " yarpdev --device fakeBattery\n";
    doc = doc + std::string("=============================================\n\n");    return doc;
}
