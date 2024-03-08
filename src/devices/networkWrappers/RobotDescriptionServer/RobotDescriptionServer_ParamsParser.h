/*
 * SPDX-FileCopyrightText: 2023-2023 Istituto Italiano di Tecnologia (IIT)
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */


// Generated by yarpDeviceParamParserGenerator (1.0)
// This is an automatically generated file. Please do not edit it.
// It will be re-generated if the cmake flag ALLOW_DEVICE_PARAM_PARSER_GERNERATION is ON.

// Generated on: Thu Mar  7 17:59:49 2024


#ifndef ROBOTDESCRIPTIONSERVER_PARAMSPARSER_H
#define ROBOTDESCRIPTIONSERVER_PARAMSPARSER_H

#include <yarp/os/Searchable.h>
#include <yarp/dev/IDeviceDriverParams.h>
#include <string>
#include <cmath>

/**
* This class is the parameters parser for class RobotDescriptionServer.
*
* These are the used parameters:
* | Group name | Parameter name | Type   | Units | Default Value               | Required | Description                          | Notes |
* |:----------:|:--------------:|:------:|:-----:|:---------------------------:|:--------:|:------------------------------------:|:-----:|
* | -          | local          | string | -     | /robotDescriptionServer/rpc | 1        | Full port name opened by the device. | -     |
*
* The device can be launched by yarpdev using one of the following examples (with and without all optional parameters):
* \code{.unparsed}
* yarpdev --device robotDescriptionServer --local /robotDescriptionServer/rpc
* \endcode
*
* \code{.unparsed}
* yarpdev --device robotDescriptionServer --local /robotDescriptionServer/rpc
* \endcode
*
*/

class RobotDescriptionServer_ParamsParser : public yarp::dev::IDeviceDriverParams
{
public:
    RobotDescriptionServer_ParamsParser();
    ~RobotDescriptionServer_ParamsParser() override = default;

public:
    const std::string m_device_classname = {"RobotDescriptionServer"};
    const std::string m_device_name = {"robotDescriptionServer"};
    bool m_parser_is_strict = false;
    struct parser_version_type
    {
         int major = 1;
         int minor = 0;
    };
    const parser_version_type m_parser_version = {};

    const std::string m_local_defaultValue = {"/robotDescriptionServer/rpc"};

    std::string m_local = {"/robotDescriptionServer/rpc"};

    bool          parseParams(const yarp::os::Searchable & config) override;
    std::string   getDeviceClassName() const override { return m_device_classname; }
    std::string   getDeviceName() const override { return m_device_name; }
    std::string   getDocumentationOfDeviceParams() const override;
    std::vector<std::string> getListOfParams() const override;
};

#endif
