/*
 * SPDX-FileCopyrightText: 2024-2024 Istituto Italiano di Tecnologia (IIT)
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <yarp/os/Network.h>
#include <yarp/dev/PolyDriver.h>
#include <yarp/dev/WrapperSingle.h>
#include <yarp/dev/IDeviceDriverParams.h>

#include <catch2/catch_amalgamated.hpp>
#include <harness.h>

using namespace yarp::dev;
using namespace yarp::os;

TEST_CASE("dev::TestDeviceWGP", "[yarp::dev]")
{
    YARP_REQUIRE_PLUGIN("testDeviceWGP", "device");

    Network::setLocalMode(true);

    SECTION("Checking TestDeviceWGP help")
    {
        PolyDriver dd;
        Property p_cfg;
        p_cfg.put("device", "testDeviceWGP");
        p_cfg.put("help","");
        REQUIRE(dd.open(p_cfg)==false);
    }

    SECTION("Checking TestDeviceWGP device")
    {
        PolyDriver dd;

        ////////"Checking opening polydriver with no attached device"
        {
            Property p_cfg;
            p_cfg.put("device",    "testDeviceWGP");

            p_cfg.put("param_1", "string");
            p_cfg.put("param_2", 1.00000);
            p_cfg.put("param_3", true);
            p_cfg.put("param_4", 1);
            p_cfg.put("param_5", "a");
            p_cfg.put("param_6", 10);
            p_cfg.put("param_7", 1.0);

            Property& pp_cfg1 = p_cfg.addGroup("group1");
            pp_cfg1.put ("param_1", "def10");
            pp_cfg1.put ("param_2", 101);
            pp_cfg1.put ("param_3", true);
            pp_cfg1.put ("param_4", 1001);

            Property& pp_cfg2 = p_cfg.addGroup("group2");
            pp_cfg2.put ("param_1", "def20");
            pp_cfg2.put ("param_2", 102);
            pp_cfg2.put ("param_3", true);
            pp_cfg2.put ("param_4", 1002);

            Property& pp_cfg5 = p_cfg.addGroup("group5");
            Property& ppp_cfg1 = pp_cfg5.addGroup("subgroup1");
            Property& ppp_cfg2 = pp_cfg5.addGroup("subgroup2");
            ppp_cfg1.put("param_1", 200);
            ppp_cfg1.put("param_2", 210);
            ppp_cfg1.put("param_3", 220);
            ppp_cfg1.put("param_4", 230);
            ppp_cfg2.put("param_1", 300);
            ppp_cfg2.put("param_2", 310);
            ppp_cfg2.put("param_3", 320);
            ppp_cfg2.put("param_4", 330);

            REQUIRE(dd.open(p_cfg));

            yarp::dev::IDeviceDriverParams* idevparams = nullptr;
            REQUIRE (dd.view(idevparams));
            REQUIRE (idevparams!=nullptr);

            std::string ss1 = idevparams->getDeviceClassName();
            CHECK (ss1 == "TestDeviceWGP");
            std::string ss2 = idevparams->getDeviceName();
            CHECK (ss2 == "testDeviceWGP");

            std::vector<std::string> vv = idevparams->getListOfParams();
            CHECK(vv.empty() == false);
        }

        yarp::os::Time::delay(1.0);

        //"Close all polydrivers and check"
        {
            CHECK(dd.close());
        }

    }

    Network::setLocalMode(false);
}
