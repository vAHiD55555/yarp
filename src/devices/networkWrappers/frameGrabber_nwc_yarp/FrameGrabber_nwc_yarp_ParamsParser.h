/*
 * SPDX-FileCopyrightText: 2023-2023 Istituto Italiano di Tecnologia (IIT)
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */


// Generated by yarpDeviceParamParserGenerator (1.0)
// This is an automatically generated file. Please do not edit it.
// It will be re-generated if the cmake flag ALLOW_DEVICE_PARAM_PARSER_GERNERATION is ON.

// Generated on: Thu Mar  7 17:59:44 2024


#ifndef FRAMEGRABBER_NWC_YARP_PARAMSPARSER_H
#define FRAMEGRABBER_NWC_YARP_PARAMSPARSER_H

#include <yarp/os/Searchable.h>
#include <yarp/dev/IDeviceDriverParams.h>
#include <string>
#include <cmath>

/**
* This class is the parameters parser for class FrameGrabber_nwc_yarp.
*
* These are the used parameters:
* | Group name | Parameter name | Type   | Units | Default Value | Required | Description                                                                                                          | Notes |
* |:----------:|:--------------:|:------:|:-----:|:-------------:|:--------:|:--------------------------------------------------------------------------------------------------------------------:|:-----:|
* | -          | local          | string | -     | -             | 1        | Prefix of the ports opened locally by the nwc for streaming and rpc operations                                       | -     |
* | -          | remote         | string | -     | -             | 1        | Name of the remote rpc port opened by the nws                                                                        | -     |
* | -          | carrier        | string | -     | fast_tcp      | 0        | Protocol used for connection with the nws streaming port                                                             | -     |
* | -          | no_stream      | bool   | -     | false         | 0        | Full port name of the port remotely opened by the Navigation server, to which the Navigation2D_nwc_yarp connects to. | -     |
*
* The device can be launched by yarpdev using one of the following examples (with and without all optional parameters):
* \code{.unparsed}
* yarpdev --device frameGrabber_nwc_yarp --local <mandatory_value> --remote <mandatory_value> --carrier fast_tcp --no_stream false
* \endcode
*
* \code{.unparsed}
* yarpdev --device frameGrabber_nwc_yarp --local <mandatory_value> --remote <mandatory_value>
* \endcode
*
*/

class FrameGrabber_nwc_yarp_ParamsParser : public yarp::dev::IDeviceDriverParams
{
public:
    FrameGrabber_nwc_yarp_ParamsParser();
    ~FrameGrabber_nwc_yarp_ParamsParser() override = default;

public:
    const std::string m_device_classname = {"FrameGrabber_nwc_yarp"};
    const std::string m_device_name = {"frameGrabber_nwc_yarp"};
    bool m_parser_is_strict = false;
    struct parser_version_type
    {
         int major = 1;
         int minor = 0;
    };
    const parser_version_type m_parser_version = {};

    const std::string m_local_defaultValue = {""};
    const std::string m_remote_defaultValue = {""};
    const std::string m_carrier_defaultValue = {"fast_tcp"};
    const std::string m_no_stream_defaultValue = {"false"};

    std::string m_local = {}; //This default value is autogenerated. It is highly recommended to provide a suggested value also for mandatory parameters.
    std::string m_remote = {}; //This default value is autogenerated. It is highly recommended to provide a suggested value also for mandatory parameters.
    std::string m_carrier = {"fast_tcp"};
    bool m_no_stream = {false};

    bool          parseParams(const yarp::os::Searchable & config) override;
    std::string   getDeviceClassName() const override { return m_device_classname; }
    std::string   getDeviceName() const override { return m_device_name; }
    std::string   getDocumentationOfDeviceParams() const override;
    std::vector<std::string> getListOfParams() const override;
};

#endif
