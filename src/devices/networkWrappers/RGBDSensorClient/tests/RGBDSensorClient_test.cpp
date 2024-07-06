/*
 * SPDX-FileCopyrightText: 2006-2021 Istituto Italiano di Tecnologia (IIT)
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <yarp/os/Network.h>
#include <yarp/dev/PolyDriver.h>
#include <yarp/dev/WrapperSingle.h>
#include <yarp/dev/IRGBDSensor.h>
#include <yarp/dev/tests/IRGBDSensorTest.h>

#include <catch2/catch_amalgamated.hpp>
#include <harness.h>

using namespace yarp::dev;
using namespace yarp::sig;
using namespace yarp::os;

TEST_CASE("dev::RGBDSensorClientTest", "[yarp::dev]")
{
    YARP_REQUIRE_PLUGIN("fakeDepthCamera", "device");
    YARP_REQUIRE_PLUGIN("rgbdSensor_nws_yarp", "device");
    YARP_REQUIRE_PLUGIN("RGBDSensorClient", "device");

    Network::setLocalMode(true);

    SECTION("Checking RGBDSensorClient device")
    {
        PolyDriver dddepth;
        PolyDriver ddnws;
        PolyDriver ddnwc;
        IRGBDSensor* irgbd = nullptr;

        ////////"Checking opening polydriver"
        {
            Property pdepth_cfg;
            pdepth_cfg.put("device", "fakeDepthCamera");
            pdepth_cfg.put("width", 32);  //smaller frame to improve valgrind speed
            pdepth_cfg.put("height", 24); //smaller frame to improve valgrind speed
            REQUIRE(dddepth.open(pdepth_cfg));
        }
        {
            Property pnws_cfg;
            pnws_cfg.put("device", "rgbdSensor_nws_yarp");
            pnws_cfg.put("name",   "/rgbd_nws");
            REQUIRE(ddnws.open(pnws_cfg));
        }

        //attach the nws to the fakeDepthCamera device
        {yarp::dev::WrapperSingle* ww_nws = nullptr; ddnws.view(ww_nws);
        REQUIRE(ww_nws);
        bool result_att = ww_nws->attach(&dddepth);
        REQUIRE(result_att); }

        //wait some time
        yarp::os::SystemClock::delaySystem(1.0);
        INFO("rgbdSensor_nws_yarp and fakeDepthCamera ready");

        //create the client
        {
            Property pnwc_cfg;
            pnwc_cfg.put("device", "RGBDSensorClient");
            pnwc_cfg.put("localImagePort",  "/rgbd_nwc/rgbImage:i");
            pnwc_cfg.put("remoteImagePort", "/rgbd_nws/rgbImage:o");

            pnwc_cfg.put("localDepthPort",  "/rgbd_nwc/depthImage:i");
            pnwc_cfg.put("remoteDepthPort", "/rgbd_nws/depthImage:o");

            pnwc_cfg.put("localRpcPort",    "/rgbd_nwc/rpc:o");
            pnwc_cfg.put("remoteRpcPort",   "/rgbd_nws/rpc:i");

            //beware: default carrier is udp, but we do not want to use it for tests
            //since it may fail on the cloud CI.
            pnwc_cfg.put("ImageCarrier",   "tcp");
            pnwc_cfg.put("DepthCarrier",   "tcp");
            REQUIRE(ddnwc.open(pnwc_cfg));
        }
        REQUIRE(ddnwc.view(irgbd));

        //execute tests
        yarp::dev::tests::exec_iRGBDSensor_test_1(irgbd);

        //Close all polydrivers and check
        CHECK(ddnwc.close());
        yarp::os::Time::delay(0.1);
        INFO("RGBDSensorClient closed");

        CHECK(ddnws.close());
        yarp::os::Time::delay(0.1);
        INFO("rgbdSensor_nws_yarp closed");

        CHECK(dddepth.close());
        yarp::os::Time::delay(0.1);
        INFO("fakeDepthCamera closed");

        INFO("Test complete");
    }

    Network::setLocalMode(false);
}
