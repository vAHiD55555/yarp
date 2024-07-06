/*
 * SPDX-FileCopyrightText: 2024-2024 Istituto Italiano di Tecnologia (IIT)
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "FakeDeviceWrapped.h"

#include <yarp/os/Log.h>
#include <yarp/os/LogComponent.h>
#include <yarp/os/LogStream.h>

using namespace yarp::os;
using namespace yarp::dev;

namespace {
    YARP_LOG_COMPONENT(FAKEDEVICEUNWRAPPED, "yarp.device.fakeDeviceWrapped")
}

void FakeDeviceWrapped::testSetValue(int value)
{
    yCInfo(FAKEDEVICEUNWRAPPED) << "testSetValue" << value;
    m_value = value;
}

void FakeDeviceWrapped::testGetValue(int& value)
{
    yCInfo(FAKEDEVICEUNWRAPPED) << "testGetValue" << m_value;
    value = m_value;
}

bool FakeDeviceWrapped::open(yarp::os::Searchable& config)
{
    yCInfo(FAKEDEVICEUNWRAPPED) << "FakeDeviceWrapped opened";
    return true;
}

bool FakeDeviceWrapped::close()
{
    yCInfo(FAKEDEVICEUNWRAPPED) << "FakeDeviceWrapped closed";
    return true;
}
