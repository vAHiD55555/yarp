/*
 * SPDX-FileCopyrightText: 2023-2023 Istituto Italiano di Tecnologia (IIT)
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */


// Generated by yarpDeviceParamParserGenerator (1.0)
// This is an automatically generated file. Please do not edit it.
// It will be re-generated if the cmake flag ALLOW_DEVICE_PARAM_PARSER_GERNERATION is ON.

// Generated on: Wed Feb  7 16:51:11 2024


#ifndef DEVICEBUNDLER_PARAMSPARSER_H
#define DEVICEBUNDLER_PARAMSPARSER_H

#include <yarp/os/Searchable.h>
#include <yarp/dev/IDeviceDriverParams.h>
#include <string>
#include <cmath>

/**
* This class is the parameters parser for class DeviceBundler.
*
* These are the used parameters:
* | Group name | Parameter name  | Type   | Units | Default Value | Required | Description                                                       | Notes                                                |
* |:----------:|:---------------:|:------:|:-----:|:-------------:|:--------:|:-----------------------------------------------------------------:|:----------------------------------------------------:|
* | -          | wrapper_device  | string | -     | device_name1  | 1        | Name of the wrapper device                                        | This device must derive from yarp::dev::IWrapper     |
* | -          | attached_device | string | -     | device_name2  | 1        | Name of the subdevice that will be attached to the wrapper device | -                                                    |
* | -          | doNotAttach     | bool   | -     | false         | 0        | If set to true, the two devices are opened, but not attached      | It should not be used, except for debugging purposes |
*
* The device can be launched by yarpdev using one of the following examples:
* \code{.unparsed}
* yarpdev --device DeviceBundler --wrapper_device device_name1 --attached_device device_name2 --doNotAttach false
* \endcode
*
* \code{.unparsed}
* yarpdev --device DeviceBundler --wrapper_device device_name1 --attached_device device_name2
* \endcode
*
*/

class DeviceBundler_ParamsParser : public yarp::dev::IDeviceDriverParams
{
public:
    ~DeviceBundler_ParamsParser() override = default;

public:
    const std::string m_device_type = {"DeviceBundler"};
    bool m_parser_is_strict = false;
    struct parser_version_type
    {
         int major = 1;
         int minor = 0;
    };
    const parser_version_type m_parser_version;
    std::string m_wrapper_device = {"device_name1"};
    std::string m_attached_device = {"device_name2"};
    bool m_doNotAttach = {false};

    bool          parseParams(const yarp::os::Searchable & config) override;
    std::string   getDeviceType() const override { return m_device_type; }
    std::string   getDocumentationOfDeviceParams() const override;
    std::vector<std::string> getListOfParams() const override;
};

#endif
