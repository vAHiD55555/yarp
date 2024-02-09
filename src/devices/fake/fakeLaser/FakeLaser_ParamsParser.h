/*
 * SPDX-FileCopyrightText: 2023-2023 Istituto Italiano di Tecnologia (IIT)
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */


// Generated by yarpDeviceParamParserGenerator (1.0)
// This is an automatically generated file. Please do not edit it.
// It will be re-generated if the cmake flag ALLOW_DEVICE_PARAM_PARSER_GERNERATION is ON.

// Generated on: Fri Feb  9 20:17:52 2024


#ifndef FAKELASER_PARAMSPARSER_H
#define FAKELASER_PARAMSPARSER_H

#include <yarp/os/Searchable.h>
#include <yarp/dev/IDeviceDriverParams.h>
#include <string>
#include <cmath>

/**
* This class is the parameters parser for class FakeLaser.
*
* These are the used parameters:
* | Group name | Parameter name      | Type   | Units | Default Value                 | Required | Description                                                                     | Notes                                                                  |
* |:----------:|:-------------------:|:------:|:-----:|:-----------------------------:|:--------:|:-------------------------------------------------------------------------------:|:----------------------------------------------------------------------:|
* | -          | test                | string | -     | use_pattern                   | 1        | Choose the modality                                                             | It can be one of the following: no_obstacles, use_pattern, use_mapfile |
* | -          | localization_port   | string | -     | /fakeLaser/location:i         | 0        | Full name of the port to which device connects to receive the localization data | -                                                                      |
* | -          | localization_server | string | -     | /localizationServer           | 0        | Full name of the port to which device connects to receive the localization data | -                                                                      |
* | -          | localization_client | string | -     | /fakeLaser/localizationClient | 0        | Full name of the local transformClient opened by the device                     | It cannot be used togheter if localization_port parameter is set       |
* | -          | localization_device | string | -     | localization2DClient          | 0        | Type of localization device, e.g. localization2DClient, localization2D_nwc_yarp | It cannot be used togheter if localization_port parameter is set       |
* | -          | map_file            | string | -     | -                             | 0        | Full path to a .map file                                                        | Mandatory if --test use_mapfile option has been set                    |
* | -          | map_context         | string | -     | -                             | 0        | Full path to a .map file                                                        | Mandatory if --test use_mapfile option has been set                    |
* | -          | clip_max            | double | m     | 3.5                           | 0        | Maximum detectable distance for an obstacle                                     | -                                                                      |
* | -          | clip_min            | double | m     | 0.1                           | 0        | Minimum detectable distance for an obstacle                                     | -                                                                      |
*
* The device can be launched by yarpdev using one of the following examples:
* \code{.unparsed}
* yarpdev --device FakeLaser --test use_pattern --localization_port /fakeLaser/location:i --localization_server /localizationServer --localization_client /fakeLaser/localizationClient --localization_device localization2DClient --map_file <optional_value> --map_context <optional_value> --clip_max 3.5 --clip_min 0.1
* \endcode
*
* \code{.unparsed}
* yarpdev --device FakeLaser --test use_pattern
* \endcode
*
*/

class FakeLaser_ParamsParser : public yarp::dev::IDeviceDriverParams
{
public:
    FakeLaser_ParamsParser() = default;
    ~FakeLaser_ParamsParser() override = default;

public:
    const std::string m_device_type = {"FakeLaser"};
    bool m_parser_is_strict = false;
    struct parser_version_type
    {
         int major = 1;
         int minor = 0;
    };
    const parser_version_type m_parser_version;
    std::string m_test = {"use_pattern"};
    std::string m_localization_port = {"/fakeLaser/location:i"};
    std::string m_localization_server = {"/localizationServer"};
    std::string m_localization_client = {"/fakeLaser/localizationClient"};
    std::string m_localization_device = {"localization2DClient"};
    std::string m_map_file = {}; //This default value is autogenerated. It is highly recommended to provide a suggested value also for optional string parameters.
    std::string m_map_context = {}; //This default value is autogenerated. It is highly recommended to provide a suggested value also for optional string parameters.
    double m_clip_max = {3.5};
    double m_clip_min = {0.1};

    bool          parseParams(const yarp::os::Searchable & config) override;
    std::string   getDeviceType() const override { return m_device_type; }
    std::string   getDocumentationOfDeviceParams() const override;
    std::vector<std::string> getListOfParams() const override;
};

#endif
