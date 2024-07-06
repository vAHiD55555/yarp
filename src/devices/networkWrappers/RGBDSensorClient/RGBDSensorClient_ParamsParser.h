/*
 * SPDX-FileCopyrightText: 2023-2023 Istituto Italiano di Tecnologia (IIT)
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */


// Generated by yarpDeviceParamParserGenerator (1.0)
// This is an automatically generated file. Please do not edit it.
// It will be re-generated if the cmake flag ALLOW_DEVICE_PARAM_PARSER_GERNERATION is ON.

// Generated on: Thu Mar  7 17:59:49 2024


#ifndef RGBDSENSORCLIENT_PARAMSPARSER_H
#define RGBDSENSORCLIENT_PARAMSPARSER_H

#include <yarp/os/Searchable.h>
#include <yarp/dev/IDeviceDriverParams.h>
#include <string>
#include <cmath>

/**
* This class is the parameters parser for class RGBDSensorClient.
*
* These are the used parameters:
* | Group name | Parameter name  | Type   | Units | Default Value     | Required | Description                                                        | Notes         |
* |:----------:|:---------------:|:------:|:-----:|:-----------------:|:--------:|:------------------------------------------------------------------:|:-------------:|
* | -          | period          | double | s     | 0.03              | 0        | refresh period (in s) of the broadcasted values through yarp ports | default 0.03s |
* | -          | localImagePort  | string | -     | /RGBD_nwc/Image:o | 1        | Full name of the local image streaming port to open                | -             |
* | -          | localDepthPort  | string | -     | /RGBD_nwc/Depth:o | 1        | Full name of the local depth streaming port to open                | -             |
* | -          | remoteImagePort | string | -     | /RGBD_nws/Image:o | 1        | Full name of the remote image port to connect to                   | -             |
* | -          | remoteDepthPort | string | -     | /RGBD_nws/Depth:i | 1        | Full name of the remote depth port to connect to                   | -             |
* | -          | localRpcPort    | string | -     | /RGBD_nwc/rpc:o   | 1        | Full name of the local rpc port to open                            | -             |
* | -          | remoteRpcPort   | string | -     | /RGBD_nws/rpc:i   | 1        | Full name of the remote rpc port to connect to                     | -             |
* | -          | ImageCarrier    | string | -     | udp               | 0        | Carrier for the image stream                                       | -             |
* | -          | DepthCarrier    | string | -     | udp               | 0        | Carrier for the depth stream                                       | -             |
*
* The device can be launched by yarpdev using one of the following examples (with and without all optional parameters):
* \code{.unparsed}
* yarpdev --device RGBDSensorClient --period 0.03 --localImagePort /RGBD_nwc/Image:o --localDepthPort /RGBD_nwc/Depth:o --remoteImagePort /RGBD_nws/Image:o --remoteDepthPort /RGBD_nws/Depth:i --localRpcPort /RGBD_nwc/rpc:o --remoteRpcPort /RGBD_nws/rpc:i --ImageCarrier udp --DepthCarrier udp
* \endcode
*
* \code{.unparsed}
* yarpdev --device RGBDSensorClient --localImagePort /RGBD_nwc/Image:o --localDepthPort /RGBD_nwc/Depth:o --remoteImagePort /RGBD_nws/Image:o --remoteDepthPort /RGBD_nws/Depth:i --localRpcPort /RGBD_nwc/rpc:o --remoteRpcPort /RGBD_nws/rpc:i
* \endcode
*
*/

class RGBDSensorClient_ParamsParser : public yarp::dev::IDeviceDriverParams
{
public:
    RGBDSensorClient_ParamsParser();
    ~RGBDSensorClient_ParamsParser() override = default;

public:
    const std::string m_device_classname = {"RGBDSensorClient"};
    const std::string m_device_name = {"RGBDSensorClient"};
    bool m_parser_is_strict = false;
    struct parser_version_type
    {
         int major = 1;
         int minor = 0;
    };
    const parser_version_type m_parser_version = {};

    const std::string m_period_defaultValue = {"0.03"};
    const std::string m_localImagePort_defaultValue = {"/RGBD_nwc/Image:o"};
    const std::string m_localDepthPort_defaultValue = {"/RGBD_nwc/Depth:o"};
    const std::string m_remoteImagePort_defaultValue = {"/RGBD_nws/Image:o"};
    const std::string m_remoteDepthPort_defaultValue = {"/RGBD_nws/Depth:i"};
    const std::string m_localRpcPort_defaultValue = {"/RGBD_nwc/rpc:o"};
    const std::string m_remoteRpcPort_defaultValue = {"/RGBD_nws/rpc:i"};
    const std::string m_ImageCarrier_defaultValue = {"udp"};
    const std::string m_DepthCarrier_defaultValue = {"udp"};

    double m_period = {0.03};
    std::string m_localImagePort = {"/RGBD_nwc/Image:o"};
    std::string m_localDepthPort = {"/RGBD_nwc/Depth:o"};
    std::string m_remoteImagePort = {"/RGBD_nws/Image:o"};
    std::string m_remoteDepthPort = {"/RGBD_nws/Depth:i"};
    std::string m_localRpcPort = {"/RGBD_nwc/rpc:o"};
    std::string m_remoteRpcPort = {"/RGBD_nws/rpc:i"};
    std::string m_ImageCarrier = {"udp"};
    std::string m_DepthCarrier = {"udp"};

    bool          parseParams(const yarp::os::Searchable & config) override;
    std::string   getDeviceClassName() const override { return m_device_classname; }
    std::string   getDeviceName() const override { return m_device_name; }
    std::string   getDocumentationOfDeviceParams() const override;
    std::vector<std::string> getListOfParams() const override;
};

#endif
