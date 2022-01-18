/*
 * SPDX-FileCopyrightText: 2006-2021 Istituto Italiano di Tecnologia (IIT)
 * SPDX-License-Identifier: BSD-3-Clause
 */

// Autogenerated by Thrift Compiler (0.14.1-yarped)
//
// This is an automatically generated file.
// It could get re-generated if the ALLOW_IDL_GENERATION flag is on.

#include <return_get_name_of_current_target.h>

// Constructor with field values
return_get_name_of_current_target::return_get_name_of_current_target(const bool ret,
                                                                     const std::string& name) :
        WirePortable(),
        ret(ret),
        name(name)
{
}

// Read structure on a Wire
bool return_get_name_of_current_target::read(yarp::os::idl::WireReader& reader)
{
    if (!read_ret(reader)) {
        return false;
    }
    if (!read_name(reader)) {
        return false;
    }
    if (reader.isError()) {
        return false;
    }
    return true;
}

// Read structure on a Connection
bool return_get_name_of_current_target::read(yarp::os::ConnectionReader& connection)
{
    yarp::os::idl::WireReader reader(connection);
    if (!reader.readListHeader(2)) {
        return false;
    }
    if (!read(reader)) {
        return false;
    }
    return true;
}

// Write structure on a Wire
bool return_get_name_of_current_target::write(const yarp::os::idl::WireWriter& writer) const
{
    if (!write_ret(writer)) {
        return false;
    }
    if (!write_name(writer)) {
        return false;
    }
    if (writer.isError()) {
        return false;
    }
    return true;
}

// Write structure on a Connection
bool return_get_name_of_current_target::write(yarp::os::ConnectionWriter& connection) const
{
    yarp::os::idl::WireWriter writer(connection);
    if (!writer.writeListHeader(2)) {
        return false;
    }
    if (!write(writer)) {
        return false;
    }
    return true;
}

// Convert to a printable string
std::string return_get_name_of_current_target::toString() const
{
    yarp::os::Bottle b;
    if (!yarp::os::Portable::copyPortable(*this, b)) {
        return {};
    }
    return b.toString();
}

// read ret field
bool return_get_name_of_current_target::read_ret(yarp::os::idl::WireReader& reader)
{
    if (!reader.readBool(ret)) {
        ret = false;
    }
    return true;
}

// write ret field
bool return_get_name_of_current_target::write_ret(const yarp::os::idl::WireWriter& writer) const
{
    if (!writer.writeBool(ret)) {
        return false;
    }
    return true;
}

// read (nested) ret field
bool return_get_name_of_current_target::nested_read_ret(yarp::os::idl::WireReader& reader)
{
    if (!reader.readBool(ret)) {
        ret = false;
    }
    return true;
}

// write (nested) ret field
bool return_get_name_of_current_target::nested_write_ret(const yarp::os::idl::WireWriter& writer) const
{
    if (!writer.writeBool(ret)) {
        return false;
    }
    return true;
}

// read name field
bool return_get_name_of_current_target::read_name(yarp::os::idl::WireReader& reader)
{
    if (reader.noMore()) {
        reader.fail();
        return false;
    }
    if (!reader.readString(name)) {
        reader.fail();
        return false;
    }
    return true;
}

// write name field
bool return_get_name_of_current_target::write_name(const yarp::os::idl::WireWriter& writer) const
{
    if (!writer.writeString(name)) {
        return false;
    }
    return true;
}

// read (nested) name field
bool return_get_name_of_current_target::nested_read_name(yarp::os::idl::WireReader& reader)
{
    if (reader.noMore()) {
        reader.fail();
        return false;
    }
    if (!reader.readString(name)) {
        reader.fail();
        return false;
    }
    return true;
}

// write (nested) name field
bool return_get_name_of_current_target::nested_write_name(const yarp::os::idl::WireWriter& writer) const
{
    if (!writer.writeString(name)) {
        return false;
    }
    return true;
}
