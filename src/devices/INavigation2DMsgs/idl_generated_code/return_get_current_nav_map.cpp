/*
 * SPDX-FileCopyrightText: 2006-2021 Istituto Italiano di Tecnologia (IIT)
 * SPDX-License-Identifier: BSD-3-Clause
 */

// Autogenerated by Thrift Compiler (0.14.1-yarped)
//
// This is an automatically generated file.
// It could get re-generated if the ALLOW_IDL_GENERATION flag is on.

#include <return_get_current_nav_map.h>

// Constructor with field values
return_get_current_nav_map::return_get_current_nav_map(const bool ret,
                                                       const yarp::dev::Nav2D::MapGrid2D& mapgrid) :
        WirePortable(),
        ret(ret),
        mapgrid(mapgrid)
{
}

// Read structure on a Wire
bool return_get_current_nav_map::read(yarp::os::idl::WireReader& reader)
{
    if (!read_ret(reader)) {
        return false;
    }
    if (!nested_read_mapgrid(reader)) {
        return false;
    }
    if (reader.isError()) {
        return false;
    }
    return true;
}

// Read structure on a Connection
bool return_get_current_nav_map::read(yarp::os::ConnectionReader& connection)
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
bool return_get_current_nav_map::write(const yarp::os::idl::WireWriter& writer) const
{
    if (!write_ret(writer)) {
        return false;
    }
    if (!nested_write_mapgrid(writer)) {
        return false;
    }
    if (writer.isError()) {
        return false;
    }
    return true;
}

// Write structure on a Connection
bool return_get_current_nav_map::write(yarp::os::ConnectionWriter& connection) const
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
std::string return_get_current_nav_map::toString() const
{
    yarp::os::Bottle b;
    b.read(*this);
    return b.toString();
}

// read ret field
bool return_get_current_nav_map::read_ret(yarp::os::idl::WireReader& reader)
{
    if (!reader.readBool(ret)) {
        ret = false;
    }
    return true;
}

// write ret field
bool return_get_current_nav_map::write_ret(const yarp::os::idl::WireWriter& writer) const
{
    if (!writer.writeBool(ret)) {
        return false;
    }
    return true;
}

// read (nested) ret field
bool return_get_current_nav_map::nested_read_ret(yarp::os::idl::WireReader& reader)
{
    if (!reader.readBool(ret)) {
        ret = false;
    }
    return true;
}

// write (nested) ret field
bool return_get_current_nav_map::nested_write_ret(const yarp::os::idl::WireWriter& writer) const
{
    if (!writer.writeBool(ret)) {
        return false;
    }
    return true;
}

// read mapgrid field
bool return_get_current_nav_map::read_mapgrid(yarp::os::idl::WireReader& reader)
{
    if (reader.noMore()) {
        reader.fail();
        return false;
    }
    if (!reader.read(mapgrid)) {
        reader.fail();
        return false;
    }
    return true;
}

// write mapgrid field
bool return_get_current_nav_map::write_mapgrid(const yarp::os::idl::WireWriter& writer) const
{
    if (!writer.write(mapgrid)) {
        return false;
    }
    return true;
}

// read (nested) mapgrid field
bool return_get_current_nav_map::nested_read_mapgrid(yarp::os::idl::WireReader& reader)
{
    if (reader.noMore()) {
        reader.fail();
        return false;
    }
    if (!reader.readNested(mapgrid)) {
        reader.fail();
        return false;
    }
    return true;
}

// write (nested) mapgrid field
bool return_get_current_nav_map::nested_write_mapgrid(const yarp::os::idl::WireWriter& writer) const
{
    if (!writer.writeNested(mapgrid)) {
        return false;
    }
    return true;
}
