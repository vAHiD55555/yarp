/*
 * SPDX-FileCopyrightText: 2006-2021 Istituto Italiano di Tecnologia (IIT)
 * SPDX-License-Identifier: BSD-3-Clause
 */

namespace yarp yarp.sig

typedef i32 ( yarp.type = "size_t" ) size_t

/**
* \brief `AudioPlayerStatus`: A class used to describe the status of an audio player device.
* See \ref AudioDoc for additional documentation on YARP audio.
*/
struct AudioPlayerStatus
{
    /** true if the playback is currently enabled */
    1: bool         enabled;

    /** the size of the audio buffer [samples] */
    2: size_t       current_buffer_size;

    /** the max_size of the audio buffer [samples] */
    3: size_t       max_buffer_size;
}
(
    yarp.api.include = "yarp/sig/api.h"
    yarp.api.keyword = "YARP_sig_API"
)
