/*
 * SPDX-FileCopyrightText: 2023-2023 Istituto Italiano di Tecnologia (IIT)
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <yarp/os/Network.h>
#include <yarp/os/Carriers.h>
#include <yarp/os/YarpPluginSettings.h>

#include <catch2/catch_amalgamated.hpp>
#include <harness.h>

using namespace yarp::os;
TEST_CASE("os::ListCarriersTest", "[yarp::os]")
{
    NetworkBase::setLocalMode(true);

    SECTION("Checking listCarriers() method")
    {
        yarp::os::Bottle lst;
        lst = yarp::os::Carriers::listCarriers();
        CHECK (lst.size() != 0);
    }

    NetworkBase::setLocalMode(false);
}
