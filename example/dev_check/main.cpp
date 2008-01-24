// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

#include <stdio.h>
#include <stdlib.h>

#include <yarp/os/Property.h>
#include <yarp/sig/Image.h>
#include <yarp/dev/PolyDriver.h>
#include <yarp/dev/FrameGrabberInterfaces.h>
#include <yarp/dev/ControlBoardInterfaces.h>

#ifdef USE_NEW_DEVICE_MECHANISM
#include "drivers.h"
#endif

using namespace yarp::os;
using namespace yarp::dev;
using namespace yarp::sig;


int main() {
#ifdef USE_NEW_DEVICE_MECHANISM
    DriverCollection dev;
#endif

    PolyDriver dd;
    Property fakebot;
    fakebot.put("device","fakebot");
    fakebot.put("background",""); // suppress background image
    fakebot.put("target","");     // suppress foreground image
    dd.open(fakebot);

    if (!dd.isValid()) {
        printf("fakebot not available\n");
        exit(1);
    }

    printf("*** fakebot created\n");

    PolyDriver dd2("test_grabber");
    if (!dd2.isValid()) {
        printf("test_grabber not available\n");
        exit(1);
    }

  
    IFrameGrabberImage *grabber;
    dd2.view(grabber);
  
    if (grabber!=NULL) {
        printf("*** It can supply images\n");
        ImageOf<PixelRgb> img;
        if (grabber->getImage(img)) {
            printf("*** Got a %dx%d image\n", img.width(), img.height());
        } else {
            printf("*** Failed to actually read an image\n");
        }
    } else {
        printf("*** It can <<<<<NOT>>>>> supply images\n");
    }

    IPidControl *pid;
    dd.view(pid);
  
    if (pid!=NULL) {
        printf("*** It can do PID control\n");
    } else {
        printf("*** It can <<<<<NOT>>>>> do PID control\n");
    }
  
    return 0;
}



