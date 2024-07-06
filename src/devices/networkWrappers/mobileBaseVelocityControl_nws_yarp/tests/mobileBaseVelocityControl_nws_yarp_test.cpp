/*
 * SPDX-FileCopyrightText: 2023-2023 Istituto Italiano di Tecnologia (IIT)
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <yarp/dev/INavigation2D.h>
#include <yarp/os/Network.h>
#include <yarp/dev/PolyDriver.h>
#include <yarp/dev/WrapperSingle.h>

#include <catch2/catch_amalgamated.hpp>
#include <harness.h>

using namespace yarp::dev;
using namespace yarp::os;

TEST_CASE("dev::mobileBaseVelocityControl_nws_yarp", "[yarp::dev]")
{
    YARP_REQUIRE_PLUGIN("fakeNavigation", "device");
    YARP_REQUIRE_PLUGIN("mobileBaseVelocityControl_nws_yarp", "device");

    Network::setLocalMode(true);

    SECTION("Checking mobileBaseVelocityControl_nws_yarp device alone")
    {
        PolyDriver dd;

        ////////"Checking opening mobileBaseVelocityControl_nws_yarp polydriver with no attached device"
        {
            Property p_cfg;
            p_cfg.put("device", "mobileBaseVelocityControl_nws_yarp");
            p_cfg.put("local",  "/mobileBaseVelocityControl_nws_yarp");
            REQUIRE(dd.open(p_cfg));
        }

        yarp::os::Time::delay(1.0);

        //"Close all polydrivers and check"
        {
            CHECK(dd.close());
        }
    }

    SECTION("Checking mobileBaseVelocityControl_nws_yarp device attached to fakeNavigation")
    {
        PolyDriver ddnws;
        PolyDriver ddfake;

        ////////"Checking opening mobileBaseVelocityControl_nws_yarp polydrivers"
        {
            Property pnws_cfg;
            pnws_cfg.put("device", "mobileBaseVelocityControl_nws_yarp");
            pnws_cfg.put("local", "/mobileBaseVelocityControl_nws_yarp");
            REQUIRE(ddnws.open(pnws_cfg));

            Property pdev_cfg;
            pdev_cfg.put("device", "fakeNavigation");
            REQUIRE(ddfake.open(pdev_cfg));

            {yarp::dev::WrapperSingle* ww_nws=nullptr; ddnws.view(ww_nws);
            REQUIRE(ww_nws);
            bool result_att = ww_nws->attach(&ddfake);
            REQUIRE(result_att); }
        }

        yarp::os::Time::delay(0.1);

        //"Close all polydrivers and check"
        {
            CHECK(ddnws.close());
            CHECK(ddfake.close());
        }
    }

    Network::setLocalMode(false);
}
