/*
 * SPDX-FileCopyrightText: 2023-2023 Istituto Italiano di Tecnologia (IIT)
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <yarp/os/Network.h>
#include <yarp/dev/PolyDriver.h>
#include <yarp/dev/WrapperSingle.h>

#include <catch2/catch_amalgamated.hpp>
#include <harness.h>

using namespace yarp::dev;
using namespace yarp::os;

TEST_CASE("dev::serialPort_nws_yarp", "[yarp::dev]")
{
    YARP_REQUIRE_PLUGIN("fakeSerialPort", "device");
    YARP_REQUIRE_PLUGIN("serialPort_nws_yarp", "device");

    Network::setLocalMode(true);

    SECTION("Checking serialPort_nws_yarp device alone")
    {
        PolyDriver dd;

        ////////"Checking opening polydriver with no attached device"
        {
            Property p_cfg;
            p_cfg.put("device", "serialPort_nws_yarp");
            p_cfg.put("name", "/serialPort_nws");
            REQUIRE(dd.open(p_cfg));
        }

        yarp::os::Time::delay(1.0);

        //"Close all polydrivers and check"
        {
            CHECK(dd.close());
        }
    }

    SECTION("Checking serialPort_nws_yarp device attached to fake device")
    {
        PolyDriver ddnws;
        PolyDriver ddfake;

        ////////"Checking opening localization2D_nws_yarp polydrivers"
        {
            Property pnws_cfg;
            pnws_cfg.put("device", "serialPort_nws_yarp");
            pnws_cfg.put("name", "/serialPort_nws");
            REQUIRE(ddnws.open(pnws_cfg));

            Property pdev_cfg;
            pdev_cfg.put("device", "fakeSerialPort");
            pdev_cfg.put("comport", "fakePort");
            pdev_cfg.put("baudrate", 9600);
            REQUIRE(ddfake.open(pdev_cfg));

            {yarp::dev::WrapperSingle* ww_nws=nullptr; ddnws.view(ww_nws);
            REQUIRE(ww_nws);
            bool result_att = ww_nws->attach(&ddfake);
            REQUIRE(result_att); }
        }

        //tests
        {
            Port p;
            CHECK(p.open("/test:o"));
            CHECK(Network::connect("/test:o","/serialPort_nws/in"));
            yarp::os::Time::delay(0.5);
            Bottle b;
            b.addString("fake_command");
            CHECK(p.write(b));
            yarp::os::Time::delay(0.5);
            p.close();
        }
        yarp::os::Time::delay(0.5);

        //"Close all polydrivers and check"
        {
            CHECK(ddnws.close());
            CHECK(ddfake.close());
        }
    }

    Network::setLocalMode(false);
}
