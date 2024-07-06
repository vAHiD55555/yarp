/*
 * SPDX-FileCopyrightText: 2006-2021 Istituto Italiano di Tecnologia (IIT)
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef YARP_FAKEDEPTHCAMERADRIVER_H
#define YARP_FAKEDEPTHCAMERADRIVER_H

#include <string>
#include <yarp/dev/DeviceDriver.h>
#include <yarp/sig/all.h>
#include <yarp/sig/Matrix.h>
#include <yarp/os/Stamp.h>
#include <yarp/dev/IRGBDSensor.h>
#include <yarp/dev/IFrameGrabberImage.h>
#include <yarp/dev/PolyDriver.h>
#include "FakeDepthCameraDriver_ParamsParser.h"

/**
 * @ingroup dev_impl_fake
 *
 * \brief `fakeDepthCamera`: Documentation to be added
 *
 * Parameters required by this device are shown in class: FakeDepthCameraDriver_ParamsParser
 *
 * The device internally opens a fakeFrameGrabber, so check also FakeFrameGrabber_ParamsParser
 */

class FakeDepthCameraDriver :
        public yarp::dev::DeviceDriver,
        public yarp::dev::IRGBDSensor,
        public FakeDepthCameraDriver_ParamsParser
{
private:
    typedef yarp::sig::ImageOf<yarp::sig::PixelFloat> depthImage;
    typedef yarp::os::Stamp                           Stamp;
    typedef yarp::os::Property                        Property;
    typedef yarp::sig::FlexImage                      FlexImage;

public:
    FakeDepthCameraDriver();
    ~FakeDepthCameraDriver() override;

    // DeviceDriver
    bool open(yarp::os::Searchable& config) override;
    bool close() override;

    // IRGBDSensor
    int    getRgbHeight() override;
    int    getRgbWidth() override;
    bool   getRgbSupportedConfigurations(yarp::sig::VectorOf<yarp::dev::CameraConfig>& configurations) override;
    bool   getRgbResolution(int& width, int& height) override;
    bool   setRgbResolution(int width, int height) override;
    bool   getRgbFOV(double& horizontalFov, double& verticalFov) override;
    bool   setRgbFOV(double horizontalFov, double verticalFov) override;
    bool   getRgbMirroring(bool& mirror) override;
    bool   setRgbMirroring(bool mirror) override;

    bool   getRgbIntrinsicParam(Property& intrinsic) override;
    int    getDepthHeight() override;
    int    getDepthWidth() override;
    bool   setDepthResolution(int width, int height) override;
    bool   getDepthFOV(double& horizontalFov, double& verticalFov) override;
    bool   setDepthFOV(double horizontalFov, double verticalFov) override;
    bool   getDepthIntrinsicParam(Property& intrinsic) override;
    double getDepthAccuracy() override;
    bool   setDepthAccuracy(double accuracy) override;
    bool   getDepthClipPlanes(double& nearPlane, double& farPlane) override;
    bool   setDepthClipPlanes(double nearPlane, double farPlane) override;
    bool   getDepthMirroring(bool& mirror) override;
    bool   setDepthMirroring(bool mirror) override;


    bool getExtrinsicParam(yarp::sig::Matrix& extrinsic) override;
    bool getRgbImage(FlexImage& rgbImage, Stamp* timeStamp = nullptr) override;
    bool getDepthImage(depthImage& depthImage, Stamp* timeStamp = nullptr) override;
    bool getImages(FlexImage& colorFrame, depthImage& depthFrame, Stamp* colorStamp = nullptr, Stamp* depthStamp = nullptr) override;

    RGBDSensor_status getSensorStatus() override;
    std::string getLastErrorMsg(Stamp* timeStamp = nullptr) override;

private:
    yarp::sig::ImageOf<yarp::sig::PixelRgb> imageof;
    yarp::dev::PolyDriver                   testgrabber;
    yarp::dev::IFrameGrabberImage*                     image;
};
#endif // YARP_FAKEDEPTHCAMERADRIVER_H
