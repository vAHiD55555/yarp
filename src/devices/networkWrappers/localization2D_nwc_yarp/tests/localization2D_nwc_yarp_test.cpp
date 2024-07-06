/*
 * SPDX-FileCopyrightText: 2006-2021 Istituto Italiano di Tecnologia (IIT)
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <yarp/dev/ILocalization2D.h>
#include <yarp/os/Network.h>
#include <yarp/dev/PolyDriver.h>
#include <yarp/dev/WrapperSingle.h>
#include <yarp/dev/tests/ILocalization2DTest.h>

#include <catch2/catch_amalgamated.hpp>
#include <harness.h>

using namespace yarp::dev;
using namespace yarp::os;

TEST_CASE("dev::localization2D_nwc", "[yarp::dev]")
{
    YARP_REQUIRE_PLUGIN("fakeLocalizer", "device");
    YARP_REQUIRE_PLUGIN("localization2D_nws_yarp", "device");
    YARP_REQUIRE_PLUGIN("localization2D_nwc_yarp", "device");

    Network::setLocalMode(true);

    SECTION("Checking localization2D_nwc device")
    {
        yarp::dev::Nav2D::ILocalization2D* iloc=nullptr;
        PolyDriver ddnws;
        PolyDriver ddfake;
        PolyDriver ddnwc;

        ////////"Checking opening map2DServer and map2DClient polydrivers"
        {
            Property pnws_cfg;
            pnws_cfg.put("device", "localization2D_nws_yarp");
            REQUIRE(ddnws.open(pnws_cfg));

            Property pdev_cfg;
            pdev_cfg.put("device", "fakeLocalizer");
            REQUIRE(ddfake.open(pdev_cfg));

            {yarp::dev::WrapperSingle* ww_nws=nullptr; ddnws.view(ww_nws);
            REQUIRE(ww_nws);
            bool result_att = ww_nws->attach(&ddfake);
            REQUIRE(result_att); }

            Property pnwc_cfg;
            pnwc_cfg.put("device", "localization2D_nwc_yarp");
            pnwc_cfg.put("local", "/localization2D_nwc_yarp");
            pnwc_cfg.put("remote", "/localization2D_nws_yarp");
            REQUIRE(ddnwc.open(pnwc_cfg));
            REQUIRE(ddnwc.view(iloc));
        }

        yarp::dev::tests::exec_iLocalization2D_test_1(iloc);

        //"Close all polydrivers and check"
        {
            CHECK(ddnwc.close());
            yarp::os::Time::delay(0.1);
            CHECK(ddnws.close());
            yarp::os::Time::delay(0.1);
            CHECK(ddfake.close());
        }
    }

    Network::setLocalMode(false);
}
