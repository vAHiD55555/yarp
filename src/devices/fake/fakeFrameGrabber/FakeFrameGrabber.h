/*
 * SPDX-FileCopyrightText: 2006-2021 Istituto Italiano di Tecnologia (IIT)
 * SPDX-FileCopyrightText: 2006-2010 RobotCub Consortium
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef YARP_FAKEFRAMEGRABBER_FAKEFRAMEGRABBER_H
#define YARP_FAKEFRAMEGRABBER_FAKEFRAMEGRABBER_H


#include <yarp/sig/ImageFile.h>
#include <yarp/dev/DeviceDriver.h>
#include <yarp/dev/IFrameGrabberControls.h>
#include <yarp/dev/IFrameGrabberImage.h>
#include <yarp/dev/AudioVisualInterfaces.h>
#include <yarp/dev/IPreciselyTimed.h>
#include <yarp/os/Searchable.h>
#include <yarp/os/Thread.h>
#include <yarp/os/Time.h>
#include <yarp/os/Vocab.h>
#include <yarp/os/Log.h>
#include <yarp/os/Value.h>
#include <yarp/dev/IRgbVisualParams.h>

#include <cstdio>
#include <random>
#include <condition_variable>
#include "FakeFrameGrabber_ParamsParser.h"

/**
 * @ingroup dev_impl_media dev_impl_fake
 *
 * \brief `fakeFrameGrabber`: A fake camera for testing.
 *
 * Implements the IFrameGrabberImage and IFrameGrabberControls
 * interfaces.
 *
 * Parameters required by this device are shown in class: FakeFrameGrabber_ParamsParser
 */
class FakeFrameGrabber :
#ifndef YARP_NO_DEPRECATED // Since YARP 3.5`
        virtual public yarp::dev::DeviceDriver,
#else
        public yarp::dev::DeviceDriver,
#endif
        public yarp::dev::IFrameGrabberImage,
        public yarp::dev::IFrameGrabberImageRaw,
        public yarp::dev::IFrameGrabberControls,
        public yarp::dev::IPreciselyTimed,
        public yarp::dev::IAudioVisualStream,
        public yarp::dev::IRgbVisualParams,
        public yarp::os::Thread,
        public yarp::os::PortReader,
        public FakeFrameGrabber_ParamsParser
{
public:
    FakeFrameGrabber() = default;
    FakeFrameGrabber(const FakeFrameGrabber&) = delete;
    FakeFrameGrabber(FakeFrameGrabber&&) = delete;
    FakeFrameGrabber& operator=(const FakeFrameGrabber&) = delete;
    FakeFrameGrabber& operator=(FakeFrameGrabber&&) = delete;
    ~FakeFrameGrabber() override = default;

    bool close() override;

    /**
     * @param config The options to use
     * @return true iff the object could be configured.
     */
    bool open(yarp::os::Searchable& config) override;

    // yarp::os::PortReader
    bool read(yarp::os::ConnectionReader& connection) override;

    // yarp::os::Thread
    void run() override;
    void onStop() override;

    void timing();

    int height() const override;

    int width() const override;
    //IRgbVisualParams
    int getRgbHeight() override;

    int getRgbWidth() override;

    bool getRgbSupportedConfigurations(yarp::sig::VectorOf<yarp::dev::CameraConfig>& configurations) override;

    bool getRgbResolution(int& width, int& height) override;

    bool setRgbResolution(int width, int height) override;

    bool getRgbFOV(double& horizontalFov, double& verticalFov) override;

    bool setRgbFOV(double horizontalFov, double verticalFov) override;

    bool getRgbIntrinsicParam(yarp::os::Property& intrinsic) override;

    bool getRgbMirroring(bool& mirror) override;

    bool setRgbMirroring(bool mirror) override;
    //
    bool getImage(yarp::sig::ImageOf<yarp::sig::PixelRgb>& image) override;
    bool getImage(yarp::sig::ImageOf<yarp::sig::PixelMono>& image) override;

    bool getImageCrop(cropType_id_t cropType,
                      yarp::sig::VectorOf<std::pair<int, int>> vertices,
                      yarp::sig::ImageOf<yarp::sig::PixelRgb>& image) override;
    bool getImageCrop(cropType_id_t cropType,
                      yarp::sig::VectorOf<std::pair<int, int>> vertices,
                      yarp::sig::ImageOf<yarp::sig::PixelMono>& image) override;

    yarp::os::Stamp getLastInputStamp() override;

    bool hasAudio() override;

    bool hasVideo() override;

    bool hasRawVideo() override;

    bool getCameraDescription(CameraDescriptor *camera) override;

    bool hasFeature(int feature, bool *hasFeature) override;

    bool setFeature(int feature, double value) override;

    bool getFeature(int feature, double *value) override;

    bool setFeature(int feature, double  value1, double  value2) override;

    bool getFeature(int feature, double *value1, double *value2) override;

    bool hasOnOff(int feature, bool *HasOnOff) override;

    bool setActive(int feature, bool onoff) override;

    bool getActive(int feature, bool *isActive) override;

    bool hasAuto(int feature, bool *hasAuto) override;

    bool hasManual(int feature, bool *hasManual) override;

    bool hasOnePush(int feature, bool *hasOnePush) override;

    bool setMode(int feature, FeatureMode mode) override;

    bool getMode(int feature, FeatureMode *mode) override;

    bool setOnePush(int feature) override;

private:
    static constexpr size_t default_w = 128;
    static constexpr size_t default_h = 128;
    static constexpr size_t default_freq = 30;
    static constexpr double default_snr = 0.5;

    yarp::os::Port     m_rpcPort;

    size_t ct{0};
    size_t bx{0};
    size_t by{0};
    unsigned long rnd{0};
    double first{0};
    double prev{0};
    bool have_bg{false};
    yarp::os::Property m_intrinsic;
    yarp::sig::VectorOf<yarp::dev::CameraConfig> configurations;

    std::random_device rnddev;
    std::default_random_engine randengine{rnddev()};
    std::uniform_int_distribution<int> udist{-1, 1};
    std::uniform_real_distribution<double> ucdist{0.0, 1.0};

    std::mutex curr_buff_mutex;
    size_t curr_buff{1};
    yarp::sig::ImageOf<yarp::sig::PixelRgb> buffs[2];
    bool img_ready[2] {false, false};
    bool img_consumed[2] {true, true};
    std::mutex mutex[2]; // FIXME C++17 perhaps use shared_mutex (check if this causes starvation)
    std::condition_variable img_ready_cv[2];
    std::condition_variable img_consumed_cv[2];
    double buff_ts[2];

    yarp::sig::ImageOf<yarp::sig::PixelRgb> background;
    yarp::sig::ImageOf<yarp::sig::PixelRgb> rgb_image;
    yarp::os::Stamp stamp;

    void createTestImage(yarp::sig::ImageOf<yarp::sig::PixelRgb>& image,
                         double& timestamp);

    bool makeSimpleBayer(yarp::sig::ImageOf<yarp::sig::PixelRgb>& src,
                         yarp::sig::ImageOf<yarp::sig::PixelMono>& bayer);

    void printTime(unsigned char* pixbuf, size_t pixbuf_w, size_t pixbuf_h, size_t x, size_t y, char* s, size_t size);
};

#ifndef YARP_NO_DEPRECATED // Since YARP 3.5
/**
 * @ingroup dev_impl_fake dev_impl_deprecated
 * \brief `testFrameGrabber` *deprecated*
 *
 */
class TestFrameGrabber :
        public yarp::dev::DeprecatedDeviceDriver,
        public FakeFrameGrabber
{
};
#endif // YARP_NO_DEPRECATED

#endif // YARP_FAKEFRAMEGRABBER_FAKEFRAMEGRABBER_H
