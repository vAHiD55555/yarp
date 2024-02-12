/*
 * SPDX-FileCopyrightText: 2023-2023 Istituto Italiano di Tecnologia (IIT)
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */


// Generated by yarpDeviceParamParserGenerator (1.0)
// This is an automatically generated file. Please do not edit it.
// It will be re-generated if the cmake flag ALLOW_DEVICE_PARAM_PARSER_GERNERATION is ON.

// Generated on: Mon Feb 12 13:43:57 2024


#ifndef FAKEFRAMEGRABBER_PARAMSPARSER_H
#define FAKEFRAMEGRABBER_PARAMSPARSER_H

#include <yarp/os/Searchable.h>
#include <yarp/dev/IDeviceDriverParams.h>
#include <string>
#include <cmath>

/**
* This class is the parameters parser for class FakeFrameGrabber.
*
* These are the used parameters:
* | Group name | Parameter name            | Type   | Units | Default Value                       | Required | Description                                                                                                    | Notes |
* |:----------:|:-------------------------:|:------:|:-----:|:-----------------------------------:|:--------:|:--------------------------------------------------------------------------------------------------------------:|:-----:|
* | -          | width                     | int    | -     | 320                                 | 0        | desired width of test image                                                                                    | -     |
* | -          | height                    | int    | -     | 240                                 | 0        | desired height of test image                                                                                   | -     |
* | -          | horizontalFov             | double | -     | 1.0                                 | 0        | desired horizontal fov of test image                                                                           | -     |
* | -          | verticalFov               | double | -     | 2.0                                 | 0        | desired horizontal fov of test image                                                                           | -     |
* | -          | fakeFrameGrabber_rpc_port | string | -     | /fakeFrameGrabber/rpc               | 0        | rpc port for the fakeFrameGrabber                                                                              | -     |
* | -          | mirror                    | bool   | -     | false                               | 0        | mirror height of test image                                                                                    | -     |
* | -          | syncro                    | bool   | -     | false                               | 0        | synchronize producer and consumer, so that all images are used once and only once                              | -     |
* | -          | topIsLow                  | bool   | -     | true                                | 0        | explicitly set the topIsLow field in the images                                                                | -     |
* | -          | physFocalLength           | double | -     | 3.0                                 | 0        | Physical focal length                                                                                          | -     |
* | -          | focalLengthX              | double | -     | 4.0                                 | 0        | Horizontal component of the focal length                                                                       | -     |
* | -          | focalLengthY              | double | -     | 5.0                                 | 0        | Vertical component of the focal length                                                                         | -     |
* | -          | principalPointX           | double | -     | 6.0                                 | 0        | X coordinate of the principal point                                                                            | -     |
* | -          | principalPointY           | double | -     | 7.0                                 | 0        | Y coordinate of the principal point                                                                            | -     |
* | -          | distortionModel           | string | -     | FishEye                             | 0        | Reference to group of parameters describing the distortion model of the camera                                 | -     |
* | -          | k1                        | double | -     | 8.0                                 | 0        | Radial distortion coefficient of the lens(fake                                                                 | -     |
* | -          | k2                        | double | -     | 9.0                                 | 0        | Radial distortion coefficient of the lens(fake)                                                                | -     |
* | -          | k3                        | double | -     | 10.0                                | 0        | Radial distortion coefficient of the lens(fake)                                                                | -     |
* | -          | t1                        | double | -     | 11.0                                | 0        | Tangential distortion of the lens(fake)                                                                        | -     |
* | -          | t2                        | double | -     | 12.0                                | 0        | Tangential distortion of the lens(fake)                                                                        | -     |
* | -          | freq                      | double | -     | 0                                   | 0        | rate of test images in Hz                                                                                      | -     |
* | -          | period                    | double | -     | 0                                   | 0        | period of test images in seconds                                                                               | -     |
* | -          | mode                      | string | -     | [line]                              | 0        | bouncy [ball], scrolly [line], grid [grid], grid multisize [size], random [rand], none [none], time test[time] | -     |
* | -          | src                       | string | -     | test.ppm                            | 0        | background image to use, if any                                                                                | -     |
* | -          | add_timestamp             | bool   | -     | false                               | 0        | should write the timestamp in the first bytes of the image                                                     | -     |
* | -          | add_noise                 | bool   | -     | false                               | 0        | should add noise to the image (uses snr parameter)                                                             | -     |
* | -          | bayer                     | bool   | -     | false                               | 0        | should emit bayer test image                                                                                   | -     |
* | -          | mono                      | bool   | -     | false                               | 0        | should emit a monochrome image                                                                                 | -     |
* | -          | snr                       | double | -     | 0.5                                 | 0        | Signal noise ratio ([0.0-1.0]                                                                                  | -     |
* | -          | rectificationMatrix       | string | -     | 1.0 0.0 0.0 0.0 1.0 0.0 0.0 0.0 1.0 | 0        | Matrix that describes the lens' distortion                                                                     | -     |
*
* The device can be launched by yarpdev using one of the following examples:
* \code{.unparsed}
* yarpdev --device FakeFrameGrabber --width 320 --height 240 --horizontalFov 1.0 --verticalFov 2.0 --fakeFrameGrabber_rpc_port /fakeFrameGrabber/rpc --mirror false --syncro false --topIsLow true --physFocalLength 3.0 --focalLengthX 4.0 --focalLengthY 5.0 --principalPointX 6.0 --principalPointY 7.0 --distortionModel FishEye --k1 8.0 --k2 9.0 --k3 10.0 --t1 11.0 --t2 12.0 --freq 0 --period 0 --mode [line] --src test.ppm --add_timestamp false --add_noise false --bayer false --mono false --snr 0.5 --rectificationMatrix 1.0 0.0 0.0 0.0 1.0 0.0 0.0 0.0 1.0
* \endcode
*
* \code{.unparsed}
* yarpdev --device FakeFrameGrabber
* \endcode
*
*/

class FakeFrameGrabber_ParamsParser : public yarp::dev::IDeviceDriverParams
{
public:
    FakeFrameGrabber_ParamsParser() = default;
    ~FakeFrameGrabber_ParamsParser() override = default;

public:
    const std::string m_device_type = {"FakeFrameGrabber"};
    bool m_parser_is_strict = false;
    struct parser_version_type
    {
         int major = 1;
         int minor = 0;
    };
    const parser_version_type m_parser_version = {};
    int m_width = {320};
    int m_height = {240};
    double m_horizontalFov = {1.0};
    double m_verticalFov = {2.0};
    std::string m_fakeFrameGrabber_rpc_port = {"/fakeFrameGrabber/rpc"};
    bool m_mirror = {false};
    bool m_syncro = {false};
    bool m_topIsLow = {true};
    double m_physFocalLength = {3.0};
    double m_focalLengthX = {4.0};
    double m_focalLengthY = {5.0};
    double m_principalPointX = {6.0};
    double m_principalPointY = {7.0};
    std::string m_distortionModel = {"FishEye"};
    double m_k1 = {8.0};
    double m_k2 = {9.0};
    double m_k3 = {10.0};
    double m_t1 = {11.0};
    double m_t2 = {12.0};
    double m_freq = {0};
    double m_period = {0};
    std::string m_mode = {"[line]"};
    std::string m_src = {"test.ppm"};
    bool m_add_timestamp = {false};
    bool m_add_noise = {false};
    bool m_bayer = {false};
    bool m_mono = {false};
    double m_snr = {0.5};
    std::string m_rectificationMatrix = {"1.0 0.0 0.0 0.0 1.0 0.0 0.0 0.0 1.0"};

    bool          parseParams(const yarp::os::Searchable & config) override;
    std::string   getDeviceType() const override { return m_device_type; }
    std::string   getDocumentationOfDeviceParams() const override;
    std::vector<std::string> getListOfParams() const override;
};

#endif
