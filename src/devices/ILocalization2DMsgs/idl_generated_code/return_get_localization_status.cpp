/*
 * SPDX-FileCopyrightText: 2006-2021 Istituto Italiano di Tecnologia (IIT)
 * SPDX-License-Identifier: BSD-3-Clause
 */

// Autogenerated by Thrift Compiler (0.14.1-yarped)
//
// This is an automatically generated file.
// It could get re-generated if the ALLOW_IDL_GENERATION flag is on.

#include <return_get_localization_status.h>

// Constructor with field values
return_get_localization_status::return_get_localization_status(const bool ret,
                                                               const yarp::dev::Nav2D::LocalizationStatusEnum status) :
        WirePortable(),
        ret(ret),
        status(status)
{
}

// Read structure on a Wire
bool return_get_localization_status::read(yarp::os::idl::WireReader& reader)
{
    if (!read_ret(reader)) {
        return false;
    }
    if (!nested_read_status(reader)) {
        return false;
    }
    if (reader.isError()) {
        return false;
    }
    return true;
}

// Read structure on a Connection
bool return_get_localization_status::read(yarp::os::ConnectionReader& connection)
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
bool return_get_localization_status::write(const yarp::os::idl::WireWriter& writer) const
{
    if (!write_ret(writer)) {
        return false;
    }
    if (!nested_write_status(writer)) {
        return false;
    }
    if (writer.isError()) {
        return false;
    }
    return true;
}

// Write structure on a Connection
bool return_get_localization_status::write(yarp::os::ConnectionWriter& connection) const
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
std::string return_get_localization_status::toString() const
{
    yarp::os::Bottle b;
    b.read(*this);
    return b.toString();
}

// read ret field
bool return_get_localization_status::read_ret(yarp::os::idl::WireReader& reader)
{
    if (!reader.readBool(ret)) {
        ret = false;
    }
    return true;
}

// write ret field
bool return_get_localization_status::write_ret(const yarp::os::idl::WireWriter& writer) const
{
    if (!writer.writeBool(ret)) {
        return false;
    }
    return true;
}

// read (nested) ret field
bool return_get_localization_status::nested_read_ret(yarp::os::idl::WireReader& reader)
{
    if (!reader.readBool(ret)) {
        ret = false;
    }
    return true;
}

// write (nested) ret field
bool return_get_localization_status::nested_write_ret(const yarp::os::idl::WireWriter& writer) const
{
    if (!writer.writeBool(ret)) {
        return false;
    }
    return true;
}

// read status field
bool return_get_localization_status::read_status(yarp::os::idl::WireReader& reader)
{
    if (reader.noMore()) {
        reader.fail();
        return false;
    }
    yarp::conf::vocab32_t _ecast;
    if (!reader.readVocab32(_ecast)) {
        reader.fail();
        return false;
    }
    status = static_cast<yarp::dev::Nav2D::LocalizationStatusEnum>(_ecast);
    return true;
}

// write status field
bool return_get_localization_status::write_status(const yarp::os::idl::WireWriter& writer) const
{
    if (!writer.writeVocab32(static_cast<yarp::conf::vocab32_t>(status))) {
        return false;
    }
    return true;
}

// read (nested) status field
bool return_get_localization_status::nested_read_status(yarp::os::idl::WireReader& reader)
{
    if (reader.noMore()) {
        reader.fail();
        return false;
    }
    yarp::conf::vocab32_t _ecast;
    if (!reader.readVocab32(_ecast)) {
        reader.fail();
        return false;
    }
    status = static_cast<yarp::dev::Nav2D::LocalizationStatusEnum>(_ecast);
    return true;
}

// write (nested) status field
bool return_get_localization_status::nested_write_status(const yarp::os::idl::WireWriter& writer) const
{
    if (!writer.writeVocab32(static_cast<yarp::conf::vocab32_t>(status))) {
        return false;
    }
    return true;
}
