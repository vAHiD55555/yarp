/*
 * SPDX-FileCopyrightText: 2023-2023 Istituto Italiano di Tecnologia (IIT)
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */


// Generated by yarpDeviceParamParserGenerator (1.0)
// This is an automatically generated file. Please do not edit it.
// It will be re-generated if the cmake flag ALLOW_DEVICE_PARAM_PARSER_GERNERATION is ON.

// Generated on: Fri Mar  8 16:13:05 2024


#ifndef AUDIOFROMFILEDEVICE_PARAMSPARSER_H
#define AUDIOFROMFILEDEVICE_PARAMSPARSER_H

#include <yarp/os/Searchable.h>
#include <yarp/dev/IDeviceDriverParams.h>
#include <string>
#include <cmath>

/**
* This class is the parameters parser for class AudioFromFileDevice.
*
* These are the used parameters:
* | Group name | Parameter name       | Type   | Units   | Default Value | Required | Description                                                                                                                                                                    | Notes                                       |
* |:----------:|:--------------------:|:------:|:-------:|:-------------:|:--------:|:------------------------------------------------------------------------------------------------------------------------------------------------------------------------------:|:-------------------------------------------:|
* | -          | use_params_from_file | bool   | -       | true          | 0        | If set to true, recording params (e.g. channels, freq etc. are taken from file. Otherwise are AUDIO_BASE parameters are used and the file is converted to the specified format | -                                           |
* | -          | file_name            | string | -       | audio.wav     | 0        | The name of the file opened by the module                                                                                                                                      | Only .wav files supported                   |
* | -          | period               | double | s       | 0.010         | 0        | the period of thread which processes the file                                                                                                                                  | On each iteration xxx samples are processed |
* | -          | driver_frame_size    | int    | samples | 512           | 0        | the number of samples to process on each iteration of the thread                                                                                                               | -                                           |
* | -          | reset_on_stop        | bool   | -       | false         | 0        | if enabled, the file is played back from the beginning every stop. Otherwise on start the previous position is resumed                                                         | -                                           |
*
* The device can be launched by yarpdev using one of the following examples (with and without all optional parameters):
* \code{.unparsed}
* yarpdev --device audioFromFileDevice --use_params_from_file true --file_name audio.wav --period 0.010 --driver_frame_size 512 --reset_on_stop false
* \endcode
*
* \code{.unparsed}
* yarpdev --device audioFromFileDevice
* \endcode
*
*/

class AudioFromFileDevice_ParamsParser : public yarp::dev::IDeviceDriverParams
{
public:
    AudioFromFileDevice_ParamsParser();
    ~AudioFromFileDevice_ParamsParser() override = default;

public:
    const std::string m_device_classname = {"AudioFromFileDevice"};
    const std::string m_device_name = {"audioFromFileDevice"};
    bool m_parser_is_strict = false;
    struct parser_version_type
    {
         int major = 1;
         int minor = 0;
    };
    const parser_version_type m_parser_version = {};

    const std::string m_use_params_from_file_defaultValue = {"true"};
    const std::string m_file_name_defaultValue = {"audio.wav"};
    const std::string m_period_defaultValue = {"0.010"};
    const std::string m_driver_frame_size_defaultValue = {"512"};
    const std::string m_reset_on_stop_defaultValue = {"false"};

    bool m_use_params_from_file = {true};
    std::string m_file_name = {"audio.wav"};
    double m_period = {0.010};
    int m_driver_frame_size = {512};
    bool m_reset_on_stop = {false};

    bool          parseParams(const yarp::os::Searchable & config) override;
    std::string   getDeviceClassName() const override { return m_device_classname; }
    std::string   getDeviceName() const override { return m_device_name; }
    std::string   getDocumentationOfDeviceParams() const override;
    std::vector<std::string> getListOfParams() const override;
};

#endif
