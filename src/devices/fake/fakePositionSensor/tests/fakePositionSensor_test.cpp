/*
 * SPDX-FileCopyrightText: 2023-2023 Istituto Italiano di Tecnologia (IIT)
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <yarp/os/Network.h>
#include <yarp/dev/PolyDriver.h>
#include <yarp/dev/MultipleAnalogSensorsInterfaces.h>
#include <yarp/dev/tests/IPositionSensorsTest.h>
#include <yarp/dev/tests/IOrientationSensorsTest.h>

#include <catch2/catch_amalgamated.hpp>
#include <harness.h>

using namespace yarp::dev;
using namespace yarp::os;

TEST_CASE("dev::fakePositionSensor", "[yarp::dev]")
{
    YARP_REQUIRE_PLUGIN("fakePositionSensor", "device");

    Network::setLocalMode(true);

    SECTION("Checking fakePositionSensor device")
    {
        PolyDriver dd;
        yarp::dev::IPositionSensors* ipos = nullptr;
        yarp::dev::IOrientationSensors* iors = nullptr;

        ////////"Checking opening device polydrivers"
        {
            Property p_cfg;
            p_cfg.put("device", "fakePositionSensor");
            REQUIRE(dd.open(p_cfg));
        }

        dd.view(ipos);
        REQUIRE(ipos!=nullptr);

        dd.view(iors);
        REQUIRE(iors != nullptr);

        yarp::dev::tests::exec_IPositionSensors_test_1(ipos);
        yarp::dev::tests::exec_IOrientationSensors_test_1(iors);

        //"Close all polydrivers and check"
        {
            CHECK(dd.close());
        }
    }

    Network::setLocalMode(false);
}
