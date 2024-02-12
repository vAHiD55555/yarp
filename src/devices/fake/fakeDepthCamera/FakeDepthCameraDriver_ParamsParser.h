/*
 * SPDX-FileCopyrightText: 2023-2023 Istituto Italiano di Tecnologia (IIT)
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */


// Generated by yarpDeviceParamParserGenerator (1.0)
// This is an automatically generated file. Please do not edit it.
// It will be re-generated if the cmake flag ALLOW_DEVICE_PARAM_PARSER_GERNERATION is ON.

// Generated on: Mon Feb 12 13:43:55 2024


#ifndef FAKEDEPTHCAMERADRIVER_PARAMSPARSER_H
#define FAKEDEPTHCAMERADRIVER_PARAMSPARSER_H

#include <yarp/os/Searchable.h>
#include <yarp/dev/IDeviceDriverParams.h>
#include <string>
#include <cmath>

/**
* This class is the parameters parser for class FakeDepthCameraDriver.
*
* These are the used parameters:
* | Group name | Parameter name | Type   | Units | Default Value | Required | Description | Notes                                    |
* |:----------:|:--------------:|:------:|:-----:|:-------------:|:--------:|:-----------:|:----------------------------------------:|
* | -          | rgb_h          | double | -     | 480.0         | 0        | rgb_h       | -                                        |
* | -          | rgb_w          | double | -     | 640.0         | 0        | rgb_w       | -                                        |
* | -          | dep_h          | double | -     | 480.0         | 0        | dep_h       | probably it should be identical to rgb_h |
* | -          | dep_w          | double | -     | 640.0         | 0        | dep_w       | probably it should be identical to rgb_w |
* | -          | accuracy       | double | -     | 0.001         | 0        | accuracy    | -                                        |
* | -          | rgb_Vfov       | double | -     | 50.0          | 0        | rgb_Vfov    | -                                        |
* | -          | rgb_Hfov       | double | -     | 36.0          | 0        | rgb_Hfov    | -                                        |
* | -          | dep_Vfov       | double | -     | 50.0          | 0        | dep_Vfov    | -                                        |
* | -          | dep_Hfov       | double | -     | 36.0          | 0        | dep_Hfov    | -                                        |
* | -          | dep_near       | double | -     | 0.2           | 0        | dep_near    | -                                        |
* | -          | dep_far        | double | -     | 6.0           | 0        | dep_far     | -                                        |
*
* The device can be launched by yarpdev using one of the following examples:
* \code{.unparsed}
* yarpdev --device FakeDepthCameraDriver --rgb_h 480.0 --rgb_w 640.0 --dep_h 480.0 --dep_w 640.0 --accuracy 0.001 --rgb_Vfov 50.0 --rgb_Hfov 36.0 --dep_Vfov 50.0 --dep_Hfov 36.0 --dep_near 0.2 --dep_far 6.0
* \endcode
*
* \code{.unparsed}
* yarpdev --device FakeDepthCameraDriver
* \endcode
*
*/

class FakeDepthCameraDriver_ParamsParser : public yarp::dev::IDeviceDriverParams
{
public:
    FakeDepthCameraDriver_ParamsParser() = default;
    ~FakeDepthCameraDriver_ParamsParser() override = default;

public:
    const std::string m_device_type = {"FakeDepthCameraDriver"};
    bool m_parser_is_strict = false;
    struct parser_version_type
    {
         int major = 1;
         int minor = 0;
    };
    const parser_version_type m_parser_version = {};
    double m_rgb_h = {480.0};
    double m_rgb_w = {640.0};
    double m_dep_h = {480.0};
    double m_dep_w = {640.0};
    double m_accuracy = {0.001};
    double m_rgb_Vfov = {50.0};
    double m_rgb_Hfov = {36.0};
    double m_dep_Vfov = {50.0};
    double m_dep_Hfov = {36.0};
    double m_dep_near = {0.2};
    double m_dep_far = {6.0};

    bool          parseParams(const yarp::os::Searchable & config) override;
    std::string   getDeviceType() const override { return m_device_type; }
    std::string   getDocumentationOfDeviceParams() const override;
    std::vector<std::string> getListOfParams() const override;
};

#endif
