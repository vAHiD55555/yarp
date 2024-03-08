/*
 * SPDX-FileCopyrightText: 2023-2023 Istituto Italiano di Tecnologia (IIT)
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */


// Generated by yarpDeviceParamParserGenerator (1.0)
// This is an automatically generated file. Please do not edit it.
// It will be re-generated if the cmake flag ALLOW_DEVICE_PARAM_PARSER_GERNERATION is ON.

// Generated on: Thu Mar  7 17:59:46 2024


#ifndef LLM_NWS_YARP_PARAMSPARSER_H
#define LLM_NWS_YARP_PARAMSPARSER_H

#include <yarp/os/Searchable.h>
#include <yarp/dev/IDeviceDriverParams.h>
#include <string>
#include <cmath>

/**
* This class is the parameters parser for class LLM_nws_yarp.
*
* These are the used parameters:
* | Group name | Parameter name | Type   | Units | Default Value | Required | Description                                              | Notes                                              |
* |:----------:|:--------------:|:------:|:-----:|:-------------:|:--------:|:--------------------------------------------------------:|:--------------------------------------------------:|
* | -          | name           | string | -     | /LLM_nws      | 1        | Prefix of the ports (rpc and streaming) opened by device | Two ports will be opened: xxx/rpc:i and xxx/conv:o |
*
* The device can be launched by yarpdev using one of the following examples (with and without all optional parameters):
* \code{.unparsed}
* yarpdev --device LLM_nws_yarp --name /LLM_nws
* \endcode
*
* \code{.unparsed}
* yarpdev --device LLM_nws_yarp --name /LLM_nws
* \endcode
*
*/

class LLM_nws_yarp_ParamsParser : public yarp::dev::IDeviceDriverParams
{
public:
    LLM_nws_yarp_ParamsParser();
    ~LLM_nws_yarp_ParamsParser() override = default;

public:
    const std::string m_device_classname = {"LLM_nws_yarp"};
    const std::string m_device_name = {"LLM_nws_yarp"};
    bool m_parser_is_strict = false;
    struct parser_version_type
    {
         int major = 1;
         int minor = 0;
    };
    const parser_version_type m_parser_version = {};

    const std::string m_name_defaultValue = {"/LLM_nws"};

    std::string m_name = {"/LLM_nws"};

    bool          parseParams(const yarp::os::Searchable & config) override;
    std::string   getDeviceClassName() const override { return m_device_classname; }
    std::string   getDeviceName() const override { return m_device_name; }
    std::string   getDocumentationOfDeviceParams() const override;
    std::vector<std::string> getListOfParams() const override;
};

#endif
