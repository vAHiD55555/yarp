/*
 * SPDX-FileCopyrightText: 2006-2021 Istituto Italiano di Tecnologia (IIT)
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * @file constants.h
 * @author Giulia Martino, Fabio Valla
 * @brief File containing constans used in FfmpegPortmonitor.cpp
 * @version 1.0
 * @date 2021-01-04
 */

#ifndef YARP_FFMPEG_CARRIER_FFMPEGPORTMONITOR_CL_PARAMS_H
#define YARP_FFMPEG_CARRIER_FFMPEGPORTMONITOR_CL_PARAMS_H

// Standard imports
#include <string>
#include <vector>
#include <map>

// Ffmpeg imports
extern "C" {
    #include <libavcodec/avcodec.h>
}

// YARP imports
#include <yarp/sig/Image.h>

/**
 * @brief This vector contains all parameters that have to be ignored while parsing command line string.
 *
 */
static const std::vector<std::string> FFMPEGPORTMONITOR_IGNORE_PARAMS {
    "tcp",
    "fast_tcp",
    "udp",
    "send.portmonitor",
    "recv.portmonitor",
    "file.image_compression_ffmpeg",
    "type.dll"
};

/**
 * @brief This string is the "key" value for the codec parameter
 *
 */
static const std::string FFMPEGPORTMONITOR_CL_CODEC_KEY = "codec";

/**
 * @brief This vector contains the only accepted values for the command line parameter "codec"
 *
 */
static const std::vector<std::string> FFMPEGPORTMONITOR_CL_CODECS {
    "mpeg2video",
    "h264",
    "h265"
};

/**
 * @brief This string is the "key" value for the custom encoder parameter
 *
 */
static const std::string FFMPEGPORTMONITOR_CL_CUSTOM_ENC_KEY = "custom_enc";

/**
 * @brief This string is the "key" value for the custom decoder parameter
 *
 */
static const std::string FFMPEGPORTMONITOR_CL_CUSTOM_DEC_KEY = "custom_dec";

/**
 * @brief This string is the "key" value for the pixel format parameter
 *
 */
static const std::string FFMPEGPORTMONITOR_CL_PIXEL_FORMAT_KEY = "pixel_format";

/**
 * @brief This string is the "key" value for the frame rate parameter
 *
 */
static const std::string FFMPEGPORTMONITOR_CL_FRAME_RATE_KEY = "frame_rate";

/**
 * @brief This string is the "key" value to enable the print statistics
 *
 */
static const std::string FFMPEGPORTMONITOR_CL_PRINT_STATISTICS_KEY = "print_statistics";

/**
 * @brief This vector contains the codec ids corresponding to the codecs of the FFMPEGPORTMONITOR_CL_CODECS vector.
 *
 */
static const std::vector<int> FFMPEGPORTMONITOR_CODE_CODECS {
    AV_CODEC_ID_MPEG2VIDEO,
    AV_CODEC_ID_H264,
    AV_CODEC_ID_H265
};

/**
 * @brief This structure maps YARP pixel format codec into Ffmpeg pixel format codes.
 *
 */
static std::map<int, int> FFMPEGPORTMONITOR_PIXELMAP = {
  { VOCAB_PIXEL_RGB, AV_PIX_FMT_RGB24 },
  { VOCAB_PIXEL_RGBA, AV_PIX_FMT_RGBA },
  { VOCAB_PIXEL_BGR, AV_PIX_FMT_BGR24 },
  { VOCAB_PIXEL_BGRA, AV_PIX_FMT_BGRA },
  { VOCAB_PIXEL_YUV_420, AV_PIX_FMT_YUV420P }
};

/**
 * @brief Default pixel format to be used within ffmpeg.
 *
 */
static AVPixelFormat FFMPEGPORTMONITOR_DEFAULT_PIXEL_FORMAT = AV_PIX_FMT_YUV420P;

#endif  // YARP_FFMPEG_CARRIER_FFMPEGPORTMONITOR_CL_PARAMS_H
