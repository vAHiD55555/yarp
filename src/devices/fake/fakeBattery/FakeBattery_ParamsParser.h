/*
 * SPDX-FileCopyrightText: 2023-2023 Istituto Italiano di Tecnologia (IIT)
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */


// Generated by yarpDeviceParamParserGenerator (1.0)
// This is an automatically generated file. Please do not edit it.
// It will be re-generated if the cmake flag ALLOW_DEVICE_PARAM_PARSER_GERNERATION is ON.

// Generated on: Mon Feb 12 13:43:56 2024


#ifndef FAKEBATTERY_PARAMSPARSER_H
#define FAKEBATTERY_PARAMSPARSER_H

#include <yarp/os/Searchable.h>
#include <yarp/dev/IDeviceDriverParams.h>
#include <string>
#include <cmath>

/**
* This class is the parameters parser for class FakeBattery.
*
* These are the used parameters:
* | Group name | Parameter name | Type   | Units | Default Value            | Required | Description                 | Notes |
* |:----------:|:--------------:|:------:|:-----:|:------------------------:|:--------:|:---------------------------:|:-----:|
* | -          | period         | double | s     | 0.02                     | 0        | thread period               | -     |
* | -          | charge         | double | -     | 50.0                     | 0        | Initial charge              | -     |
* | -          | voltage        | double | V     | 30.0                     | 0        | Initial voltage             | -     |
* | -          | current        | double | A     | 3.0                      | 0        | Initial current             | -     |
* | -          | temperature    | double | C     | 20.0                     | 0        | Initial temperature         | -     |
* | -          | info           | string | -     | Fake battery system v2.0 | 0        | Initial battery information | -     |
* | -          | rpc_port_name  | string | -     | /fakeBattery/rpc         | 0        | Full rpc port name          | -     |
*
* The device can be launched by yarpdev using one of the following examples:
* \code{.unparsed}
* yarpdev --device FakeBattery --period 0.02 --charge 50.0 --voltage 30.0 --current 3.0 --temperature 20.0 --info Fake battery system v2.0 --rpc_port_name /fakeBattery/rpc
* \endcode
*
* \code{.unparsed}
* yarpdev --device FakeBattery
* \endcode
*
*/

class FakeBattery_ParamsParser : public yarp::dev::IDeviceDriverParams
{
public:
    FakeBattery_ParamsParser() = default;
    ~FakeBattery_ParamsParser() override = default;

public:
    const std::string m_device_type = {"FakeBattery"};
    bool m_parser_is_strict = false;
    struct parser_version_type
    {
         int major = 1;
         int minor = 0;
    };
    const parser_version_type m_parser_version = {};
    double m_period = {0.02};
    double m_charge = {50.0};
    double m_voltage = {30.0};
    double m_current = {3.0};
    double m_temperature = {20.0};
    std::string m_info = {"Fake battery system v2.0"};
    std::string m_rpc_port_name = {"/fakeBattery/rpc"};

    bool          parseParams(const yarp::os::Searchable & config) override;
    std::string   getDeviceType() const override { return m_device_type; }
    std::string   getDocumentationOfDeviceParams() const override;
    std::vector<std::string> getListOfParams() const override;
};

#endif
