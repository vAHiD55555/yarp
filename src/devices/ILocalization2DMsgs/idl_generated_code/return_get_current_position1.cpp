/*
 * SPDX-FileCopyrightText: 2006-2021 Istituto Italiano di Tecnologia (IIT)
 * SPDX-License-Identifier: BSD-3-Clause
 */

// Autogenerated by Thrift Compiler (0.14.1-yarped)
//
// This is an automatically generated file.
// It could get re-generated if the ALLOW_IDL_GENERATION flag is on.

#include <return_get_current_position1.h>

// Constructor with field values
return_get_current_position1::return_get_current_position1(const bool ret,
                                                           const yarp::dev::Nav2D::Map2DLocation& loc) :
        WirePortable(),
        ret(ret),
        loc(loc)
{
}

// Read structure on a Wire
bool return_get_current_position1::read(yarp::os::idl::WireReader& reader)
{
    if (!read_ret(reader)) {
        return false;
    }
    if (!nested_read_loc(reader)) {
        return false;
    }
    if (reader.isError()) {
        return false;
    }
    return true;
}

// Read structure on a Connection
bool return_get_current_position1::read(yarp::os::ConnectionReader& connection)
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
bool return_get_current_position1::write(const yarp::os::idl::WireWriter& writer) const
{
    if (!write_ret(writer)) {
        return false;
    }
    if (!nested_write_loc(writer)) {
        return false;
    }
    if (writer.isError()) {
        return false;
    }
    return true;
}

// Write structure on a Connection
bool return_get_current_position1::write(yarp::os::ConnectionWriter& connection) const
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
std::string return_get_current_position1::toString() const
{
    yarp::os::Bottle b;
    if (!yarp::os::Portable::copyPortable(*this, b)) {
        return {};
    }
    return b.toString();
}

// read ret field
bool return_get_current_position1::read_ret(yarp::os::idl::WireReader& reader)
{
    if (!reader.readBool(ret)) {
        ret = false;
    }
    return true;
}

// write ret field
bool return_get_current_position1::write_ret(const yarp::os::idl::WireWriter& writer) const
{
    if (!writer.writeBool(ret)) {
        return false;
    }
    return true;
}

// read (nested) ret field
bool return_get_current_position1::nested_read_ret(yarp::os::idl::WireReader& reader)
{
    if (!reader.readBool(ret)) {
        ret = false;
    }
    return true;
}

// write (nested) ret field
bool return_get_current_position1::nested_write_ret(const yarp::os::idl::WireWriter& writer) const
{
    if (!writer.writeBool(ret)) {
        return false;
    }
    return true;
}

// read loc field
bool return_get_current_position1::read_loc(yarp::os::idl::WireReader& reader)
{
    if (reader.noMore()) {
        reader.fail();
        return false;
    }
    if (!reader.read(loc)) {
        reader.fail();
        return false;
    }
    return true;
}

// write loc field
bool return_get_current_position1::write_loc(const yarp::os::idl::WireWriter& writer) const
{
    if (!writer.write(loc)) {
        return false;
    }
    return true;
}

// read (nested) loc field
bool return_get_current_position1::nested_read_loc(yarp::os::idl::WireReader& reader)
{
    if (reader.noMore()) {
        reader.fail();
        return false;
    }
    if (!reader.readNested(loc)) {
        reader.fail();
        return false;
    }
    return true;
}

// write (nested) loc field
bool return_get_current_position1::nested_write_loc(const yarp::os::idl::WireWriter& writer) const
{
    if (!writer.writeNested(loc)) {
        return false;
    }
    return true;
}
