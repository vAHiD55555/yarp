/*
 * Copyright (C) 2006-2021 Istituto Italiano di Tecnologia (IIT)
 * Copyright (C) 2006-2010 RobotCub Consortium
 * All rights reserved.
 *
 * This software may be modified and distributed under the terms of the
 * BSD-3-Clause license. See the accompanying LICENSE file for details.
 */

#ifndef YARP_DEV_WRAPPER_H
#define YARP_DEV_WRAPPER_H

#include <yarp/conf/system.h>

#include <yarp/conf/system.h>
#if !defined(YARP_INCLUDING_DEPRECATED_HEADER_YARP_DEV_IWRAPPER_H_ON_PURPOSE)
YARP_COMPILER_WARNING("<yarp/dev/Wrapper.h> file is deprecated. Use <yarp/dev/IWrapper.h> and <yarp/dev/IMultipleWrapper.h> instead")
#endif


#ifndef YARP_NO_DEPRECATED // Since YARP 3.3.0
#include <yarp/dev/IWrapper.h>
#include <yarp/dev/IMultipleWrapper.h>
#endif // YARP_NO_DEPRECATED

#endif // YARP_DEV_WRAPPER_H
