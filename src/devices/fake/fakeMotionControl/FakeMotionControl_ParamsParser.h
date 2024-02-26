/*
 * SPDX-FileCopyrightText: 2023-2023 Istituto Italiano di Tecnologia (IIT)
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */


// Generated by yarpDeviceParamParserGenerator (1.0)
// This is an automatically generated file. Please do not edit it.
// It will be re-generated if the cmake flag ALLOW_DEVICE_PARAM_PARSER_GERNERATION is ON.

// Generated on: Tue Feb 27 00:56:29 2024


#ifndef FAKEMOTIONCONTROL_PARAMSPARSER_H
#define FAKEMOTIONCONTROL_PARAMSPARSER_H

#include <yarp/os/Searchable.h>
#include <yarp/dev/IDeviceDriverParams.h>
#include <string>
#include <cmath>

/**
* This class is the parameters parser for class FakeMotionControl.
*
* These are the used parameters:
* | Group name | Parameter name | Type           | Units | Default Value | Required | Description                                                       | Notes |
* |:----------:|:--------------:|:--------------:|:-----:|:-------------:|:--------:|:-----------------------------------------------------------------:|:-----:|
* | GENERAL    | Joints         | int            | -     | 1             | 0        | Number of degrees of freedom                                      | -     |
* | GENERAL    | AxisMap        | vector<int>    | -     | -             | 0        | a list of reordered indices for the axes                          | -     |
* | GENERAL    | AxisName       | vector<string> | -     | -             | 0        | a list of strings representing the axes names                     | -     |
* | GENERAL    | AxisType       | vector<string> | -     | -             | 0        | a list of strings representing the axes type (revolute/prismatic) | -     |
* | GENERAL    | ampsToSensor   | vector<double> | -     | -             | 0        | a list of scales for the ampsToSensor conversion factors          | -     |
* | GENERAL    | fullscalePWM   | vector<double> | -     | -             | 0        | a list of scales for the fullscalePWM conversion factors          | -     |
* | GENERAL    | Encoder        | vector<int>    | -     | -             | 0        | a list of scales for the encoders                                 | -     |
* | LIMITS     | Max            | vector<double> | deg   | -             | 0        | max encoder position                                              | -     |
* | LIMITS     | Min            | vector<double> | deg   | -             | 0        | min encoder position                                              | -     |
*
* The device can be launched by yarpdev using one of the following examples:
* \code{.unparsed}
* yarpdev --device fakeMotionControl --GENERAL::Joints 1 --GENERAL::AxisMap <optional_value> --GENERAL::AxisName <optional_value> --GENERAL::AxisType <optional_value> --GENERAL::ampsToSensor <optional_value> --GENERAL::fullscalePWM <optional_value> --GENERAL::Encoder <optional_value> --LIMITS::Max <optional_value> --LIMITS::Min <optional_value>
* \endcode
*
* \code{.unparsed}
* yarpdev --device fakeMotionControl
* \endcode
*
*/

class FakeMotionControl_ParamsParser : public yarp::dev::IDeviceDriverParams
{
public:
    FakeMotionControl_ParamsParser();
    ~FakeMotionControl_ParamsParser() override = default;

public:
    const std::string m_device_classname = {"FakeMotionControl"};
    const std::string m_device_name = {"fakeMotionControl"};
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
    const std::string m_GENERAL_ampsToSensor_defaultValue = {""};
    const std::string m_GENERAL_fullscalePWM_defaultValue = {""};
    const std::string m_GENERAL_Encoder_defaultValue = {""};
    const std::string m_LIMITS_Max_defaultValue = {""};
    const std::string m_LIMITS_Min_defaultValue = {""};

    int m_GENERAL_Joints = {1};
    std::vector<int> m_GENERAL_AxisMap = {}; //The default value of this list is an empty list. It is highly recommended to provide a suggested value also for optional string parameters.
    std::vector<std::string> m_GENERAL_AxisName = {}; //The default value of this list is an empty list. It is highly recommended to provide a suggested value also for optional string parameters.
    std::vector<std::string> m_GENERAL_AxisType = {}; //The default value of this list is an empty list. It is highly recommended to provide a suggested value also for optional string parameters.
    std::vector<double> m_GENERAL_ampsToSensor = {}; //The default value of this list is an empty list. It is highly recommended to provide a suggested value also for optional string parameters.
    std::vector<double> m_GENERAL_fullscalePWM = {}; //The default value of this list is an empty list. It is highly recommended to provide a suggested value also for optional string parameters.
    std::vector<int> m_GENERAL_Encoder = {}; //The default value of this list is an empty list. It is highly recommended to provide a suggested value also for optional string parameters.
    std::vector<double> m_LIMITS_Max = {}; //The default value of this list is an empty list. It is highly recommended to provide a suggested value also for optional string parameters.
    std::vector<double> m_LIMITS_Min = {}; //The default value of this list is an empty list. It is highly recommended to provide a suggested value also for optional string parameters.

    bool          parseParams(const yarp::os::Searchable & config) override;
    std::string   getDeviceClassName() const override { return m_device_classname; }
    std::string   getDeviceName() const override { return m_device_name; }
    std::string   getDocumentationOfDeviceParams() const override;
    std::vector<std::string> getListOfParams() const override;
};

#endif
