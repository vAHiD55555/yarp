/*
 * SPDX-FileCopyrightText: 2006-2021 Istituto Italiano di Tecnologia (IIT)
 * SPDX-License-Identifier: BSD-3-Clause
 */

// Autogenerated by Thrift Compiler (0.14.1-yarped)
//
// This is an automatically generated file.
// It could get re-generated if the ALLOW_IDL_GENERATION flag is on.

#include <return_get_last_velocity_command.h>

// Constructor with field values
return_get_last_velocity_command::return_get_last_velocity_command(const bool ret,
                                                                   const double x_vel,
                                                                   const double y_vel,
                                                                   const double theta_vel) :
        WirePortable(),
        ret(ret),
        x_vel(x_vel),
        y_vel(y_vel),
        theta_vel(theta_vel)
{
}

// Read structure on a Wire
bool return_get_last_velocity_command::read(yarp::os::idl::WireReader& reader)
{
    if (!read_ret(reader)) {
        return false;
    }
    if (!read_x_vel(reader)) {
        return false;
    }
    if (!read_y_vel(reader)) {
        return false;
    }
    if (!read_theta_vel(reader)) {
        return false;
    }
    if (reader.isError()) {
        return false;
    }
    return true;
}

// Read structure on a Connection
bool return_get_last_velocity_command::read(yarp::os::ConnectionReader& connection)
{
    yarp::os::idl::WireReader reader(connection);
    if (!reader.readListHeader(4)) {
        return false;
    }
    if (!read(reader)) {
        return false;
    }
    return true;
}

// Write structure on a Wire
bool return_get_last_velocity_command::write(const yarp::os::idl::WireWriter& writer) const
{
    if (!write_ret(writer)) {
        return false;
    }
    if (!write_x_vel(writer)) {
        return false;
    }
    if (!write_y_vel(writer)) {
        return false;
    }
    if (!write_theta_vel(writer)) {
        return false;
    }
    if (writer.isError()) {
        return false;
    }
    return true;
}

// Write structure on a Connection
bool return_get_last_velocity_command::write(yarp::os::ConnectionWriter& connection) const
{
    yarp::os::idl::WireWriter writer(connection);
    if (!writer.writeListHeader(4)) {
        return false;
    }
    if (!write(writer)) {
        return false;
    }
    return true;
}

// Convert to a printable string
std::string return_get_last_velocity_command::toString() const
{
    yarp::os::Bottle b;
    b.read(*this);
    return b.toString();
}

// read ret field
bool return_get_last_velocity_command::read_ret(yarp::os::idl::WireReader& reader)
{
    if (!reader.readBool(ret)) {
        ret = false;
    }
    return true;
}

// write ret field
bool return_get_last_velocity_command::write_ret(const yarp::os::idl::WireWriter& writer) const
{
    if (!writer.writeBool(ret)) {
        return false;
    }
    return true;
}

// read (nested) ret field
bool return_get_last_velocity_command::nested_read_ret(yarp::os::idl::WireReader& reader)
{
    if (!reader.readBool(ret)) {
        ret = false;
    }
    return true;
}

// write (nested) ret field
bool return_get_last_velocity_command::nested_write_ret(const yarp::os::idl::WireWriter& writer) const
{
    if (!writer.writeBool(ret)) {
        return false;
    }
    return true;
}

// read x_vel field
bool return_get_last_velocity_command::read_x_vel(yarp::os::idl::WireReader& reader)
{
    if (reader.noMore()) {
        reader.fail();
        return false;
    }
    if (!reader.readFloat64(x_vel)) {
        reader.fail();
        return false;
    }
    return true;
}

// write x_vel field
bool return_get_last_velocity_command::write_x_vel(const yarp::os::idl::WireWriter& writer) const
{
    if (!writer.writeFloat64(x_vel)) {
        return false;
    }
    return true;
}

// read (nested) x_vel field
bool return_get_last_velocity_command::nested_read_x_vel(yarp::os::idl::WireReader& reader)
{
    if (reader.noMore()) {
        reader.fail();
        return false;
    }
    if (!reader.readFloat64(x_vel)) {
        reader.fail();
        return false;
    }
    return true;
}

// write (nested) x_vel field
bool return_get_last_velocity_command::nested_write_x_vel(const yarp::os::idl::WireWriter& writer) const
{
    if (!writer.writeFloat64(x_vel)) {
        return false;
    }
    return true;
}

// read y_vel field
bool return_get_last_velocity_command::read_y_vel(yarp::os::idl::WireReader& reader)
{
    if (reader.noMore()) {
        reader.fail();
        return false;
    }
    if (!reader.readFloat64(y_vel)) {
        reader.fail();
        return false;
    }
    return true;
}

// write y_vel field
bool return_get_last_velocity_command::write_y_vel(const yarp::os::idl::WireWriter& writer) const
{
    if (!writer.writeFloat64(y_vel)) {
        return false;
    }
    return true;
}

// read (nested) y_vel field
bool return_get_last_velocity_command::nested_read_y_vel(yarp::os::idl::WireReader& reader)
{
    if (reader.noMore()) {
        reader.fail();
        return false;
    }
    if (!reader.readFloat64(y_vel)) {
        reader.fail();
        return false;
    }
    return true;
}

// write (nested) y_vel field
bool return_get_last_velocity_command::nested_write_y_vel(const yarp::os::idl::WireWriter& writer) const
{
    if (!writer.writeFloat64(y_vel)) {
        return false;
    }
    return true;
}

// read theta_vel field
bool return_get_last_velocity_command::read_theta_vel(yarp::os::idl::WireReader& reader)
{
    if (reader.noMore()) {
        reader.fail();
        return false;
    }
    if (!reader.readFloat64(theta_vel)) {
        reader.fail();
        return false;
    }
    return true;
}

// write theta_vel field
bool return_get_last_velocity_command::write_theta_vel(const yarp::os::idl::WireWriter& writer) const
{
    if (!writer.writeFloat64(theta_vel)) {
        return false;
    }
    return true;
}

// read (nested) theta_vel field
bool return_get_last_velocity_command::nested_read_theta_vel(yarp::os::idl::WireReader& reader)
{
    if (reader.noMore()) {
        reader.fail();
        return false;
    }
    if (!reader.readFloat64(theta_vel)) {
        reader.fail();
        return false;
    }
    return true;
}

// write (nested) theta_vel field
bool return_get_last_velocity_command::nested_write_theta_vel(const yarp::os::idl::WireWriter& writer) const
{
    if (!writer.writeFloat64(theta_vel)) {
        return false;
    }
    return true;
}
