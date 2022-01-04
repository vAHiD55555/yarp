/*
 * SPDX-FileCopyrightText: 2006-2021 Istituto Italiano di Tecnologia (IIT)
 * SPDX-License-Identifier: BSD-3-Clause
 */

// Autogenerated by Thrift Compiler (0.14.1-yarped)
//
// This is an automatically generated file.
// It could get re-generated if the ALLOW_IDL_GENERATION flag is on.

#include <return_get_paths_list.h>

// Constructor with field values
return_get_paths_list::return_get_paths_list(const bool retval,
                                             const std::vector<std::string>& paths) :
        WirePortable(),
        retval(retval),
        paths(paths)
{
}

// Read structure on a Wire
bool return_get_paths_list::read(yarp::os::idl::WireReader& reader)
{
    if (!read_retval(reader)) {
        return false;
    }
    if (!read_paths(reader)) {
        return false;
    }
    if (reader.isError()) {
        return false;
    }
    return true;
}

// Read structure on a Connection
bool return_get_paths_list::read(yarp::os::ConnectionReader& connection)
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
bool return_get_paths_list::write(const yarp::os::idl::WireWriter& writer) const
{
    if (!write_retval(writer)) {
        return false;
    }
    if (!write_paths(writer)) {
        return false;
    }
    if (writer.isError()) {
        return false;
    }
    return true;
}

// Write structure on a Connection
bool return_get_paths_list::write(yarp::os::ConnectionWriter& connection) const
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
std::string return_get_paths_list::toString() const
{
    yarp::os::Bottle b;
    if (!yarp::os::Portable::copyPortable(*this, b)) {
        return {};
    }
    return b.toString();
}

// read retval field
bool return_get_paths_list::read_retval(yarp::os::idl::WireReader& reader)
{
    if (!reader.readBool(retval)) {
        retval = false;
    }
    return true;
}

// write retval field
bool return_get_paths_list::write_retval(const yarp::os::idl::WireWriter& writer) const
{
    if (!writer.writeBool(retval)) {
        return false;
    }
    return true;
}

// read (nested) retval field
bool return_get_paths_list::nested_read_retval(yarp::os::idl::WireReader& reader)
{
    if (!reader.readBool(retval)) {
        retval = false;
    }
    return true;
}

// write (nested) retval field
bool return_get_paths_list::nested_write_retval(const yarp::os::idl::WireWriter& writer) const
{
    if (!writer.writeBool(retval)) {
        return false;
    }
    return true;
}

// read paths field
bool return_get_paths_list::read_paths(yarp::os::idl::WireReader& reader)
{
    if (reader.noMore()) {
        reader.fail();
        return false;
    }
    size_t _csize;
    yarp::os::idl::WireState _etype;
    reader.readListBegin(_etype, _csize);
    // WireReader removes BOTTLE_TAG_LIST from the tag
    constexpr int expected_tag = ((BOTTLE_TAG_STRING) & (~BOTTLE_TAG_LIST));
    if constexpr (expected_tag != 0) {
        if (_csize != 0 && _etype.code != expected_tag) {
            return false;
        }
    }
    paths.resize(_csize);
    for (size_t _i = 0; _i < _csize; ++_i) {
        if (reader.noMore()) {
            reader.fail();
            return false;
        }
        if (!reader.readString(paths[_i])) {
            reader.fail();
            return false;
        }
    }
    reader.readListEnd();
    return true;
}

// write paths field
bool return_get_paths_list::write_paths(const yarp::os::idl::WireWriter& writer) const
{
    if (!writer.writeListBegin(BOTTLE_TAG_STRING, paths.size())) {
        return false;
    }
    for (const auto& _item : paths) {
        if (!writer.writeString(_item, true)) {
            return false;
        }
    }
    if (!writer.writeListEnd()) {
        return false;
    }
    return true;
}

// read (nested) paths field
bool return_get_paths_list::nested_read_paths(yarp::os::idl::WireReader& reader)
{
    if (reader.noMore()) {
        reader.fail();
        return false;
    }
    size_t _csize;
    yarp::os::idl::WireState _etype;
    reader.readListBegin(_etype, _csize);
    // WireReader removes BOTTLE_TAG_LIST from the tag
    constexpr int expected_tag = ((BOTTLE_TAG_STRING) & (~BOTTLE_TAG_LIST));
    if constexpr (expected_tag != 0) {
        if (_csize != 0 && _etype.code != expected_tag) {
            return false;
        }
    }
    paths.resize(_csize);
    for (size_t _i = 0; _i < _csize; ++_i) {
        if (reader.noMore()) {
            reader.fail();
            return false;
        }
        if (!reader.readString(paths[_i])) {
            reader.fail();
            return false;
        }
    }
    reader.readListEnd();
    return true;
}

// write (nested) paths field
bool return_get_paths_list::nested_write_paths(const yarp::os::idl::WireWriter& writer) const
{
    if (!writer.writeListBegin(BOTTLE_TAG_STRING, paths.size())) {
        return false;
    }
    for (const auto& _item : paths) {
        if (!writer.writeString(_item, true)) {
            return false;
        }
    }
    if (!writer.writeListEnd()) {
        return false;
    }
    return true;
}
