/*
 * SPDX-FileCopyrightText: 2006-2021 Istituto Italiano di Tecnologia (IIT)
 * SPDX-License-Identifier: BSD-3-Clause
 */

// Autogenerated by Thrift Compiler (0.14.1-yarped)
//
// This is an automatically generated file.
// It could get re-generated if the ALLOW_IDL_GENERATION flag is on.

#ifndef YARP_THRIFT_GENERATOR_SERVICE_INAVIGATION2DMSGS_H
#define YARP_THRIFT_GENERATOR_SERVICE_INAVIGATION2DMSGS_H

#include <yarp/os/Wire.h>
#include <yarp/os/idl/WireTypes.h>
#include <return_get_abs_loc_of_curr_target.h>
#include <return_get_all_nav_waypoints.h>
#include <return_get_current_nav_map.h>
#include <return_get_current_nav_waypoint.h>
#include <return_get_last_velocity_command.h>
#include <return_get_name_of_current_target.h>
#include <return_get_navigation_status.h>
#include <return_get_rel_loc_of_curr_target.h>
#include <yarp/dev/INavigation2D.h>
#include <yarp/dev/Map2DLocation.h>
#include <yarp/dev/Map2DPath.h>

class INavigation2DMsgs :
        public yarp::os::Wire
{
public:
    // Constructor
    INavigation2DMsgs();

    virtual bool stop_navigation_RPC();

    virtual bool resume_navigation_RPC();

    virtual bool suspend_navigation_RPC(const double time_s);

    virtual bool recompute_current_navigation_path_RPC();

    virtual return_get_navigation_status get_navigation_status_RPC();

    virtual return_get_current_nav_waypoint get_current_nav_waypoint_RPC();

    virtual return_get_all_nav_waypoints get_all_navigation_waypoints_RPC(const yarp::dev::Nav2D::TrajectoryTypeEnum trajectory_type);

    virtual return_get_current_nav_map get_current_navigation_map_RPC(const yarp::dev::Nav2D::NavigationMapTypeEnum map_type);

    virtual bool goto_target_by_absolute_location_RPC(const yarp::dev::Nav2D::Map2DLocation& loc);

    virtual bool follow_path_RPC(const yarp::dev::Nav2D::Map2DPath& path);

    virtual bool goto_target_by_relative_location1_RPC(const double x, const double y);

    virtual bool goto_target_by_relative_location2_RPC(const double x, const double y, const double theta);

    virtual return_get_abs_loc_of_curr_target get_absolute_location_of_current_target_RPC();

    virtual return_get_rel_loc_of_curr_target get_relative_location_of_current_target_RPC();

    virtual bool goto_target_by_absolute_location_and_set_name_RPC(const yarp::dev::Nav2D::Map2DLocation& loc, const std::string& name);

    virtual bool apply_velocity_command_RPC(const double x_vel, const double y_vel, const double theta_vel, const double timeout);

    virtual return_get_last_velocity_command get_last_velocity_command_RPC();

    virtual return_get_name_of_current_target get_name_of_current_target_RPC();

    // help method
    virtual std::vector<std::string> help(const std::string& functionName = "--all");

    // read from ConnectionReader
    bool read(yarp::os::ConnectionReader& connection) override;
};

#endif // YARP_THRIFT_GENERATOR_SERVICE_INAVIGATION2DMSGS_H
