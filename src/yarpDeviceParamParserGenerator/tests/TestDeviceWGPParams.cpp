/*
 * SPDX-FileCopyrightText: 2023-2023 Istituto Italiano di Tecnologia (IIT)
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */


// Autogenerated by yarpDeviceParamParserGenerator (1.0)
//
// This is an automatically generated file. Please do not edit it.
// It will be re-generated if the cmake flag ALLOW_DEVICE_PARAM_PARSER_GERNERATION is ON.

// Generated on: Tue Jan 16 12:22:18 2024


#include "TestDeviceWGPParams.h"
#include <yarp/os/LogStream.h>
#include <yarp/os/Value.h>

namespace {
    YARP_LOG_COMPONENT(TestDeviceWGPParamsCOMPONENT, "yarp.device.TestDeviceWGP")
}


std::vector<std::string> TestDeviceWGP_params::getListOfParams() const
{
    std::vector<std::string> params;
    params.push_back("file_name");
    params.push_back("save_mode");
    params.push_back("add_marker");
    params.push_back("gggg::aaaaa");
    params.push_back("period");
    return params;
}


bool      TestDeviceWGP_params::parseParams(const yarp::os::Searchable & config)
{
    //Parser of parameter file_name
    {
        if (config.check("file_name"))
        {
            m_file_name = config.find("file_name").asString();
            yCInfo(TestDeviceWGPParamsCOMPONENT) << "Parameter 'file_name' using value:" << m_file_name;
        }
        else
        {
            yCError(TestDeviceWGPParamsCOMPONENT) << "Mandatory parameter 'file_name' not found!";
            yCError(TestDeviceWGPParamsCOMPONENT) << "Description of the parameter: The name of the file written by the module";
            return false;
        }
    }

    //Parser of parameter save_mode
    {
        if (config.check("save_mode"))
        {
            m_save_mode = config.find("save_mode").asString();
            yCInfo(TestDeviceWGPParamsCOMPONENT) << "Parameter 'save_mode' using value:" << m_save_mode;
        }
        else
        {
            yCInfo(TestDeviceWGPParamsCOMPONENT) << "Parameter 'save_mode' using DEFAULT value:" << m_save_mode;
        }
    }

    //Parser of parameter add_marker
    {
        if (config.check("add_marker"))
        {
            m_add_marker = config.find("add_marker").asBool();
            yCInfo(TestDeviceWGPParamsCOMPONENT) << "Parameter 'add_marker' using value:" << m_add_marker;
        }
        else
        {
            yCInfo(TestDeviceWGPParamsCOMPONENT) << "Parameter 'add_marker' using DEFAULT value:" << m_add_marker;
        }
    }

    //Parser of parameter gggg::aaaaa
    {
        yarp::os::Bottle sectionp;
        sectionp = config.findGroup("gggg");
        if (sectionp.check("aaaaa"))
        {
            m_gggg_aaaaa = sectionp.find("aaaaa").asBool();
            yCInfo(TestDeviceWGPParamsCOMPONENT) << "Parameter 'gggg::aaaaa' using value:" << m_gggg_aaaaa;
        }
        else
        {
            yCInfo(TestDeviceWGPParamsCOMPONENT) << "Parameter 'gggg::aaaaa' using DEFAULT value:" << m_gggg_aaaaa;
        }
    }

    //Parser of parameter period
    {
        if (config.check("period"))
        {
            m_period = config.find("period").asFloat64();
            yCInfo(TestDeviceWGPParamsCOMPONENT) << "Parameter 'period' using value:" << m_period;
        }
        else
        {
            yCError(TestDeviceWGPParamsCOMPONENT) << "Mandatory parameter 'period' not found!";
            yCError(TestDeviceWGPParamsCOMPONENT) << "Description of the parameter: If set, it will add a marker at the beginning and at the ending of each received waveform.";
            yCError(TestDeviceWGPParamsCOMPONENT) << "Remember: Units for this parameter are: 's'";
            return false;
        }
    }

    return true;
}


std::string      TestDeviceWGP_params::getDocumentationOfDeviceParams() const
{
    std::string doc;
    doc = doc + std::string("'file_name': The name of the file written by the module\n");
    doc = doc + std::string("'save_mode': Affects the behavior of the module and defines the save mode, as described in the documentation.\n");
    doc = doc + std::string("'add_marker': If set, it will add a marker at the beginning and at the ending of each received waveform.\n");
    doc = doc + std::string("'gggg::aaaaa': If set, it will add a marker at the beginning and at the ending of each received waveform.\n");
    doc = doc + std::string("'period': If set, it will add a marker at the beginning and at the ending of each received waveform.\n");
    return doc;
}
