/*
 * SPDX-FileCopyrightText: 2023-2023 Istituto Italiano di Tecnologia (IIT)
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */


// Generated by yarpDeviceParamParserGenerator (1.0)
// This is an automatically generated file. Please do not edit it.
// It will be re-generated if the cmake flag ALLOW_DEVICE_PARAM_PARSER_GERNERATION is ON.

// Generated on: Thu Mar  7 17:59:40 2024


#ifndef FAKEMOTIONCONTROLMICRO_PARAMSPARSER_H
#define FAKEMOTIONCONTROLMICRO_PARAMSPARSER_H

#include <yarp/os/Searchable.h>
#include <yarp/dev/IDeviceDriverParams.h>
#include <string>
#include <cmath>

/**
* This class is the parameters parser for class FakeMotionControlMicro.
*
* These are the used parameters:
* | Group name | Parameter name | Type           | Units | Default Value | Required | Description                                                       | Notes |
* |:----------:|:--------------:|:--------------:|:-----:|:-------------:|:--------:|:-----------------------------------------------------------------:|:-----:|
* | GENERAL    | Joints         | int            | -     | 1             | 0        | Number of degrees of freedom                                      | -     |
* | GENERAL    | AxisMap        | vector<int>    | -     | -             | 0        | a list of reordered indices for the axes                          | -     |
* | GENERAL    | AxisName       | vector<string> | -     | -             | 0        | a list of strings representing the axes names                     | -     |
* | GENERAL    | AxisType       | vector<string> | -     | -             | 0        | a list of strings representing the axes type (revolute/prismatic) | -     |
* | GENERAL    | Encoder        | vector<int>    | -     | -             | 0        | a list of scales for the encoders                                 | -     |
*
* The device can be launched by yarpdev using one of the following examples (with and without all optional parameters):
* \code{.unparsed}
* yarpdev --device fakeMotionControlMicro --GENERAL::Joints 1 --GENERAL::AxisMap <optional_value> --GENERAL::AxisName <optional_value> --GENERAL::AxisType <optional_value> --GENERAL::Encoder <optional_value>
* \endcode
*
* \code{.unparsed}
* yarpdev --device fakeMotionControlMicro
* \endcode
*
*/

class FakeMotionControlMicro_ParamsParser : public yarp::dev::IDeviceDriverParams
{
public:
    FakeMotionControlMicro_ParamsParser();
    ~FakeMotionControlMicro_ParamsParser() override = default;

public:
    const std::string m_device_classname = {"FakeMotionControlMicro"};
    const std::string m_device_name = {"fakeMotionControlMicro"};
    bool m_parser_is_strict = false;
    struct parser_version_type
    {
         int major = 1;
         int minor = 0;
    };
    const parser_version_type m_parser_version = {};

    const std::string m_GENERAL_Joints_defaultValue = {"1"};
    const std::string m_GENERAL_AxisMap_defaultValue = {""};
    const std::string m_GENERAL_AxisName_defaultValue = {""};
    const std::string m_GENERAL_AxisType_defaultValue = {""};
    const std::string m_GENERAL_Encoder_defaultValue = {""};

    int m_GENERAL_Joints = {1};
    std::vector<int> m_GENERAL_AxisMap = {}; //The default value of this list is an empty list. It is highly recommended to provide a suggested value also for optional string parameters.
    std::vector<std::string> m_GENERAL_AxisName = {}; //The default value of this list is an empty list. It is highly recommended to provide a suggested value also for optional string parameters.
    std::vector<std::string> m_GENERAL_AxisType = {}; //The default value of this list is an empty list. It is highly recommended to provide a suggested value also for optional string parameters.
    std::vector<int> m_GENERAL_Encoder = {}; //The default value of this list is an empty list. It is highly recommended to provide a suggested value also for optional string parameters.

    bool          parseParams(const yarp::os::Searchable & config) override;
    std::string   getDeviceClassName() const override { return m_device_classname; }
    std::string   getDeviceName() const override { return m_device_name; }
    std::string   getDocumentationOfDeviceParams() const override;
    std::vector<std::string> getListOfParams() const override;
};

#endif
