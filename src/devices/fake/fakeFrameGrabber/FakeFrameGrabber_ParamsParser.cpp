/*
 * SPDX-FileCopyrightText: 2023-2023 Istituto Italiano di Tecnologia (IIT)
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */


// Generated by yarpDeviceParamParserGenerator (1.0)
// This is an automatically generated file. Please do not edit it.
// It will be re-generated if the cmake flag ALLOW_DEVICE_PARAM_PARSER_GERNERATION is ON.

// Generated on: Mon Feb 19 16:28:00 2024


#include "FakeFrameGrabber_ParamsParser.h"
#include <yarp/os/LogStream.h>
#include <yarp/os/Value.h>

namespace {
    YARP_LOG_COMPONENT(FakeFrameGrabberParamsCOMPONENT, "yarp.device.FakeFrameGrabber")
}


FakeFrameGrabber_ParamsParser::FakeFrameGrabber_ParamsParser()
{
    //Default value of parameterrectificationMatrix
    {
        m_rectificationMatrix.clear();
        yarp::os::Bottle tempBot;
        tempBot.fromString(m_rectificationMatrix_defaultValue);
        if (tempBot.size()!=0)
        {
            for (size_t i=0; i<tempBot.size(); i++)
            {
                m_rectificationMatrix.push_back(tempBot.get(i).asFloat64());
            }
        }
        else
        {
             yError() <<"parameter 'rectificationMatrix' is not a properly formatted bottle";
        }
    }

}


std::vector<std::string> FakeFrameGrabber_ParamsParser::getListOfParams() const
{
    std::vector<std::string> params;
    params.push_back("width");
    params.push_back("height");
    params.push_back("horizontalFov");
    params.push_back("verticalFov");
    params.push_back("fakeFrameGrabber_rpc_port");
    params.push_back("mirror");
    params.push_back("syncro");
    params.push_back("topIsLow");
    params.push_back("physFocalLength");
    params.push_back("focalLengthX");
    params.push_back("focalLengthY");
    params.push_back("principalPointX");
    params.push_back("principalPointY");
    params.push_back("distortionModel");
    params.push_back("k1");
    params.push_back("k2");
    params.push_back("k3");
    params.push_back("t1");
    params.push_back("t2");
    params.push_back("freq");
    params.push_back("period");
    params.push_back("mode");
    params.push_back("src");
    params.push_back("add_timestamp");
    params.push_back("add_noise");
    params.push_back("bayer");
    params.push_back("mono");
    params.push_back("snr");
    params.push_back("rectificationMatrix");
    return params;
}


bool      FakeFrameGrabber_ParamsParser::parseParams(const yarp::os::Searchable & config)
{
    //Check for --help option
    if (config.check("help"))
    {
        yCInfo(FakeFrameGrabberParamsCOMPONENT) << getDocumentationOfDeviceParams();
    }

    std::string config_string = config.toString();
    yarp::os::Property prop_check(config_string.c_str());
    //Parser of parameter width
    {
        if (config.check("width"))
        {
            m_width = config.find("width").asInt64();
            yCInfo(FakeFrameGrabberParamsCOMPONENT) << "Parameter 'width' using value:" << m_width;
        }
        else
        {
            yCInfo(FakeFrameGrabberParamsCOMPONENT) << "Parameter 'width' using DEFAULT value:" << m_width;
        }
        prop_check.unput("width");
    }

    //Parser of parameter height
    {
        if (config.check("height"))
        {
            m_height = config.find("height").asInt64();
            yCInfo(FakeFrameGrabberParamsCOMPONENT) << "Parameter 'height' using value:" << m_height;
        }
        else
        {
            yCInfo(FakeFrameGrabberParamsCOMPONENT) << "Parameter 'height' using DEFAULT value:" << m_height;
        }
        prop_check.unput("height");
    }

    //Parser of parameter horizontalFov
    {
        if (config.check("horizontalFov"))
        {
            m_horizontalFov = config.find("horizontalFov").asFloat64();
            yCInfo(FakeFrameGrabberParamsCOMPONENT) << "Parameter 'horizontalFov' using value:" << m_horizontalFov;
        }
        else
        {
            yCInfo(FakeFrameGrabberParamsCOMPONENT) << "Parameter 'horizontalFov' using DEFAULT value:" << m_horizontalFov;
        }
        prop_check.unput("horizontalFov");
    }

    //Parser of parameter verticalFov
    {
        if (config.check("verticalFov"))
        {
            m_verticalFov = config.find("verticalFov").asFloat64();
            yCInfo(FakeFrameGrabberParamsCOMPONENT) << "Parameter 'verticalFov' using value:" << m_verticalFov;
        }
        else
        {
            yCInfo(FakeFrameGrabberParamsCOMPONENT) << "Parameter 'verticalFov' using DEFAULT value:" << m_verticalFov;
        }
        prop_check.unput("verticalFov");
    }

    //Parser of parameter fakeFrameGrabber_rpc_port
    {
        if (config.check("fakeFrameGrabber_rpc_port"))
        {
            m_fakeFrameGrabber_rpc_port = config.find("fakeFrameGrabber_rpc_port").asString();
            yCInfo(FakeFrameGrabberParamsCOMPONENT) << "Parameter 'fakeFrameGrabber_rpc_port' using value:" << m_fakeFrameGrabber_rpc_port;
        }
        else
        {
            yCInfo(FakeFrameGrabberParamsCOMPONENT) << "Parameter 'fakeFrameGrabber_rpc_port' using DEFAULT value:" << m_fakeFrameGrabber_rpc_port;
        }
        prop_check.unput("fakeFrameGrabber_rpc_port");
    }

    //Parser of parameter mirror
    {
        if (config.check("mirror"))
        {
            m_mirror = config.find("mirror").asBool();
            yCInfo(FakeFrameGrabberParamsCOMPONENT) << "Parameter 'mirror' using value:" << m_mirror;
        }
        else
        {
            yCInfo(FakeFrameGrabberParamsCOMPONENT) << "Parameter 'mirror' using DEFAULT value:" << m_mirror;
        }
        prop_check.unput("mirror");
    }

    //Parser of parameter syncro
    {
        if (config.check("syncro"))
        {
            m_syncro = config.find("syncro").asBool();
            yCInfo(FakeFrameGrabberParamsCOMPONENT) << "Parameter 'syncro' using value:" << m_syncro;
        }
        else
        {
            yCInfo(FakeFrameGrabberParamsCOMPONENT) << "Parameter 'syncro' using DEFAULT value:" << m_syncro;
        }
        prop_check.unput("syncro");
    }

    //Parser of parameter topIsLow
    {
        if (config.check("topIsLow"))
        {
            m_topIsLow = config.find("topIsLow").asBool();
            yCInfo(FakeFrameGrabberParamsCOMPONENT) << "Parameter 'topIsLow' using value:" << m_topIsLow;
        }
        else
        {
            yCInfo(FakeFrameGrabberParamsCOMPONENT) << "Parameter 'topIsLow' using DEFAULT value:" << m_topIsLow;
        }
        prop_check.unput("topIsLow");
    }

    //Parser of parameter physFocalLength
    {
        if (config.check("physFocalLength"))
        {
            m_physFocalLength = config.find("physFocalLength").asFloat64();
            yCInfo(FakeFrameGrabberParamsCOMPONENT) << "Parameter 'physFocalLength' using value:" << m_physFocalLength;
        }
        else
        {
            yCInfo(FakeFrameGrabberParamsCOMPONENT) << "Parameter 'physFocalLength' using DEFAULT value:" << m_physFocalLength;
        }
        prop_check.unput("physFocalLength");
    }

    //Parser of parameter focalLengthX
    {
        if (config.check("focalLengthX"))
        {
            m_focalLengthX = config.find("focalLengthX").asFloat64();
            yCInfo(FakeFrameGrabberParamsCOMPONENT) << "Parameter 'focalLengthX' using value:" << m_focalLengthX;
        }
        else
        {
            yCInfo(FakeFrameGrabberParamsCOMPONENT) << "Parameter 'focalLengthX' using DEFAULT value:" << m_focalLengthX;
        }
        prop_check.unput("focalLengthX");
    }

    //Parser of parameter focalLengthY
    {
        if (config.check("focalLengthY"))
        {
            m_focalLengthY = config.find("focalLengthY").asFloat64();
            yCInfo(FakeFrameGrabberParamsCOMPONENT) << "Parameter 'focalLengthY' using value:" << m_focalLengthY;
        }
        else
        {
            yCInfo(FakeFrameGrabberParamsCOMPONENT) << "Parameter 'focalLengthY' using DEFAULT value:" << m_focalLengthY;
        }
        prop_check.unput("focalLengthY");
    }

    //Parser of parameter principalPointX
    {
        if (config.check("principalPointX"))
        {
            m_principalPointX = config.find("principalPointX").asFloat64();
            yCInfo(FakeFrameGrabberParamsCOMPONENT) << "Parameter 'principalPointX' using value:" << m_principalPointX;
        }
        else
        {
            yCInfo(FakeFrameGrabberParamsCOMPONENT) << "Parameter 'principalPointX' using DEFAULT value:" << m_principalPointX;
        }
        prop_check.unput("principalPointX");
    }

    //Parser of parameter principalPointY
    {
        if (config.check("principalPointY"))
        {
            m_principalPointY = config.find("principalPointY").asFloat64();
            yCInfo(FakeFrameGrabberParamsCOMPONENT) << "Parameter 'principalPointY' using value:" << m_principalPointY;
        }
        else
        {
            yCInfo(FakeFrameGrabberParamsCOMPONENT) << "Parameter 'principalPointY' using DEFAULT value:" << m_principalPointY;
        }
        prop_check.unput("principalPointY");
    }

    //Parser of parameter distortionModel
    {
        if (config.check("distortionModel"))
        {
            m_distortionModel = config.find("distortionModel").asString();
            yCInfo(FakeFrameGrabberParamsCOMPONENT) << "Parameter 'distortionModel' using value:" << m_distortionModel;
        }
        else
        {
            yCInfo(FakeFrameGrabberParamsCOMPONENT) << "Parameter 'distortionModel' using DEFAULT value:" << m_distortionModel;
        }
        prop_check.unput("distortionModel");
    }

    //Parser of parameter k1
    {
        if (config.check("k1"))
        {
            m_k1 = config.find("k1").asFloat64();
            yCInfo(FakeFrameGrabberParamsCOMPONENT) << "Parameter 'k1' using value:" << m_k1;
        }
        else
        {
            yCInfo(FakeFrameGrabberParamsCOMPONENT) << "Parameter 'k1' using DEFAULT value:" << m_k1;
        }
        prop_check.unput("k1");
    }

    //Parser of parameter k2
    {
        if (config.check("k2"))
        {
            m_k2 = config.find("k2").asFloat64();
            yCInfo(FakeFrameGrabberParamsCOMPONENT) << "Parameter 'k2' using value:" << m_k2;
        }
        else
        {
            yCInfo(FakeFrameGrabberParamsCOMPONENT) << "Parameter 'k2' using DEFAULT value:" << m_k2;
        }
        prop_check.unput("k2");
    }

    //Parser of parameter k3
    {
        if (config.check("k3"))
        {
            m_k3 = config.find("k3").asFloat64();
            yCInfo(FakeFrameGrabberParamsCOMPONENT) << "Parameter 'k3' using value:" << m_k3;
        }
        else
        {
            yCInfo(FakeFrameGrabberParamsCOMPONENT) << "Parameter 'k3' using DEFAULT value:" << m_k3;
        }
        prop_check.unput("k3");
    }

    //Parser of parameter t1
    {
        if (config.check("t1"))
        {
            m_t1 = config.find("t1").asFloat64();
            yCInfo(FakeFrameGrabberParamsCOMPONENT) << "Parameter 't1' using value:" << m_t1;
        }
        else
        {
            yCInfo(FakeFrameGrabberParamsCOMPONENT) << "Parameter 't1' using DEFAULT value:" << m_t1;
        }
        prop_check.unput("t1");
    }

    //Parser of parameter t2
    {
        if (config.check("t2"))
        {
            m_t2 = config.find("t2").asFloat64();
            yCInfo(FakeFrameGrabberParamsCOMPONENT) << "Parameter 't2' using value:" << m_t2;
        }
        else
        {
            yCInfo(FakeFrameGrabberParamsCOMPONENT) << "Parameter 't2' using DEFAULT value:" << m_t2;
        }
        prop_check.unput("t2");
    }

    //Parser of parameter freq
    {
        if (config.check("freq"))
        {
            m_freq = config.find("freq").asFloat64();
            yCInfo(FakeFrameGrabberParamsCOMPONENT) << "Parameter 'freq' using value:" << m_freq;
        }
        else
        {
            yCInfo(FakeFrameGrabberParamsCOMPONENT) << "Parameter 'freq' using DEFAULT value:" << m_freq;
        }
        prop_check.unput("freq");
    }

    //Parser of parameter period
    {
        if (config.check("period"))
        {
            m_period = config.find("period").asFloat64();
            yCInfo(FakeFrameGrabberParamsCOMPONENT) << "Parameter 'period' using value:" << m_period;
        }
        else
        {
            yCInfo(FakeFrameGrabberParamsCOMPONENT) << "Parameter 'period' using DEFAULT value:" << m_period;
        }
        prop_check.unput("period");
    }

    //Parser of parameter mode
    {
        if (config.check("mode"))
        {
            m_mode = config.find("mode").asString();
            yCInfo(FakeFrameGrabberParamsCOMPONENT) << "Parameter 'mode' using value:" << m_mode;
        }
        else
        {
            yCInfo(FakeFrameGrabberParamsCOMPONENT) << "Parameter 'mode' using DEFAULT value:" << m_mode;
        }
        prop_check.unput("mode");
    }

    //Parser of parameter src
    {
        if (config.check("src"))
        {
            m_src = config.find("src").asString();
            yCInfo(FakeFrameGrabberParamsCOMPONENT) << "Parameter 'src' using value:" << m_src;
        }
        else
        {
            yCInfo(FakeFrameGrabberParamsCOMPONENT) << "Parameter 'src' using DEFAULT value:" << m_src;
        }
        prop_check.unput("src");
    }

    //Parser of parameter add_timestamp
    {
        if (config.check("add_timestamp"))
        {
            m_add_timestamp = config.find("add_timestamp").asBool();
            yCInfo(FakeFrameGrabberParamsCOMPONENT) << "Parameter 'add_timestamp' using value:" << m_add_timestamp;
        }
        else
        {
            yCInfo(FakeFrameGrabberParamsCOMPONENT) << "Parameter 'add_timestamp' using DEFAULT value:" << m_add_timestamp;
        }
        prop_check.unput("add_timestamp");
    }

    //Parser of parameter add_noise
    {
        if (config.check("add_noise"))
        {
            m_add_noise = config.find("add_noise").asBool();
            yCInfo(FakeFrameGrabberParamsCOMPONENT) << "Parameter 'add_noise' using value:" << m_add_noise;
        }
        else
        {
            yCInfo(FakeFrameGrabberParamsCOMPONENT) << "Parameter 'add_noise' using DEFAULT value:" << m_add_noise;
        }
        prop_check.unput("add_noise");
    }

    //Parser of parameter bayer
    {
        if (config.check("bayer"))
        {
            m_bayer = config.find("bayer").asBool();
            yCInfo(FakeFrameGrabberParamsCOMPONENT) << "Parameter 'bayer' using value:" << m_bayer;
        }
        else
        {
            yCInfo(FakeFrameGrabberParamsCOMPONENT) << "Parameter 'bayer' using DEFAULT value:" << m_bayer;
        }
        prop_check.unput("bayer");
    }

    //Parser of parameter mono
    {
        if (config.check("mono"))
        {
            m_mono = config.find("mono").asBool();
            yCInfo(FakeFrameGrabberParamsCOMPONENT) << "Parameter 'mono' using value:" << m_mono;
        }
        else
        {
            yCInfo(FakeFrameGrabberParamsCOMPONENT) << "Parameter 'mono' using DEFAULT value:" << m_mono;
        }
        prop_check.unput("mono");
    }

    //Parser of parameter snr
    {
        if (config.check("snr"))
        {
            m_snr = config.find("snr").asFloat64();
            yCInfo(FakeFrameGrabberParamsCOMPONENT) << "Parameter 'snr' using value:" << m_snr;
        }
        else
        {
            yCInfo(FakeFrameGrabberParamsCOMPONENT) << "Parameter 'snr' using DEFAULT value:" << m_snr;
        }
        prop_check.unput("snr");
    }

    //Parser of parameter rectificationMatrix
    {
        if (config.check("rectificationMatrix"))
        {
            {
                m_rectificationMatrix.clear();
                yarp::os::Bottle* tempBot = config.find("rectificationMatrix").asList();
                if (tempBot)
                {
                    for (size_t i=0; i<tempBot->size(); i++)
                    {
                        m_rectificationMatrix.push_back(tempBot->get(i).asFloat64());
                    }
                }
                else
                {
                     yError() <<"parameter 'rectificationMatrix' is not a properly formatted bottle";
                }
            }
            yCInfo(FakeFrameGrabberParamsCOMPONENT) << "Parameter 'rectificationMatrix' using value:" << m_rectificationMatrix;
        }
        else
        {
            yCInfo(FakeFrameGrabberParamsCOMPONENT) << "Parameter 'rectificationMatrix' using DEFAULT value:" << m_rectificationMatrix;
        }
        prop_check.unput("rectificationMatrix");
    }

    /*
    //This code check if the user set some parameter which are not check by the parser
    //If the parser is set in strict mode, this will generate an error
    if (prop_check.size() > 0)
    {
        bool extra_params_found = false;
        for (auto it=prop_check.begin(); it!=prop_check.end(); it++)
        {
            if (m_parser_is_strict)
            {
                yCError(FakeFrameGrabberParamsCOMPONENT) << "User asking for parameter: "<<it->name <<" which is unknown to this parser!";
                extra_params_found = true;
            }
            else
            {
                yCWarning(FakeFrameGrabberParamsCOMPONENT) << "User asking for parameter: "<< it->name <<" which is unknown to this parser!";
            }
        }

       if (m_parser_is_strict && extra_params_found)
       {
           return false;
       }
    }
    */
    return true;
}


std::string      FakeFrameGrabber_ParamsParser::getDocumentationOfDeviceParams() const
{
    std::string doc;
    doc = doc + std::string("\n=============================================\n");
    doc = doc + std::string("This is the help for device: FakeFrameGrabber\n");
    doc = doc + std::string("\n");
    doc = doc + std::string("This is the list of the parameters accepted by the device:\n");
    doc = doc + std::string("'width': desired width of test image\n");
    doc = doc + std::string("'height': desired height of test image\n");
    doc = doc + std::string("'horizontalFov': desired horizontal fov of test image\n");
    doc = doc + std::string("'verticalFov': desired horizontal fov of test image\n");
    doc = doc + std::string("'fakeFrameGrabber_rpc_port': rpc port for the fakeFrameGrabber\n");
    doc = doc + std::string("'mirror': mirror height of test image\n");
    doc = doc + std::string("'syncro': synchronize producer and consumer, so that all images are used once and only once\n");
    doc = doc + std::string("'topIsLow': explicitly set the topIsLow field in the images\n");
    doc = doc + std::string("'physFocalLength': Physical focal length\n");
    doc = doc + std::string("'focalLengthX': Horizontal component of the focal length\n");
    doc = doc + std::string("'focalLengthY': Vertical component of the focal length\n");
    doc = doc + std::string("'principalPointX': X coordinate of the principal point\n");
    doc = doc + std::string("'principalPointY': Y coordinate of the principal point\n");
    doc = doc + std::string("'distortionModel': Reference to group of parameters describing the distortion model of the camera\n");
    doc = doc + std::string("'k1': Radial distortion coefficient of the lens(fake\n");
    doc = doc + std::string("'k2': Radial distortion coefficient of the lens(fake)\n");
    doc = doc + std::string("'k3': Radial distortion coefficient of the lens(fake)\n");
    doc = doc + std::string("'t1': Tangential distortion of the lens(fake)\n");
    doc = doc + std::string("'t2': Tangential distortion of the lens(fake)\n");
    doc = doc + std::string("'freq': rate of test images in Hz\n");
    doc = doc + std::string("'period': period of test images in seconds\n");
    doc = doc + std::string("'mode': bouncy [ball], scrolly [line], grid [grid], grid multisize [size], random [rand], none [none], time test[time]\n");
    doc = doc + std::string("'src': background image to use, if any\n");
    doc = doc + std::string("'add_timestamp': should write the timestamp in the first bytes of the image\n");
    doc = doc + std::string("'add_noise': should add noise to the image (uses snr parameter)\n");
    doc = doc + std::string("'bayer': should emit bayer test image\n");
    doc = doc + std::string("'mono': should emit a monochrome image\n");
    doc = doc + std::string("'snr': Signal noise ratio ([0.0-1.0]\n");
    doc = doc + std::string("'rectificationMatrix': Matrix that describes the lens' distortion\n");
    doc = doc + std::string("\n");
    doc = doc + std::string("Here are some examples of invocation command with yarpdev, with all params:\n");
    doc = doc + " yarpdev --device fakeFrameGrabber --width 320 --height 240 --horizontalFov 1.0 --verticalFov 2.0 --fakeFrameGrabber_rpc_port /fakeFrameGrabber/rpc --mirror false --syncro false --topIsLow true --physFocalLength 3.0 --focalLengthX 4.0 --focalLengthY 5.0 --principalPointX 6.0 --principalPointY 7.0 --distortionModel FishEye --k1 8.0 --k2 9.0 --k3 10.0 --t1 11.0 --t2 12.0 --freq 0 --period 0 --mode [line] --src <optional_value> --add_timestamp false --add_noise false --bayer false --mono false --snr 0.5 --rectificationMatrix \" 1.0 0.0 0.0 0.0 1.0 0.0 0.0 0.0 1.0 \"\n";
    doc = doc + std::string("Using only mandatory params:\n");
    doc = doc + " yarpdev --device fakeFrameGrabber\n";
    doc = doc + std::string("=============================================\n\n");    return doc;
}
