/*
 * SPDX-FileCopyrightText: 2006-2021 Istituto Italiano di Tecnologia (IIT)
 * SPDX-License-Identifier: BSD-3-Clause
 */

// Autogenerated by Thrift Compiler (0.14.1-yarped)
//
// This is an automatically generated file.
// It could get re-generated if the ALLOW_IDL_GENERATION flag is on.

#include <return_get_map_names.h>

// Default constructor
return_get_map_names::return_get_map_names() :
        WirePortable(),
        retval(false),
        map_names()
{
}

// Constructor with field values
return_get_map_names::return_get_map_names(const bool retval,
                                           const std::vector<std::string>& map_names) :
        WirePortable(),
        retval(retval),
        map_names(map_names)
{
}

// Read structure on a Wire
bool return_get_map_names::read(yarp::os::idl::WireReader& reader)
{
    if (!read_retval(reader)) {
        return false;
    }
    if (!read_map_names(reader)) {
        return false;
    }
    return !reader.isError();
}

// Read structure on a Connection
bool return_get_map_names::read(yarp::os::ConnectionReader& connection)
{
    yarp::os::idl::WireReader reader(connection);
    if (!reader.readListHeader(2)) {
        return false;
    }
    if (!read_retval(reader)) {
        return false;
    }
    if (!read_map_names(reader)) {
        return false;
    }
    return !reader.isError();
}

// Write structure on a Wire
bool return_get_map_names::write(const yarp::os::idl::WireWriter& writer) const
{
    if (!write_retval(writer)) {
        return false;
    }
    if (!write_map_names(writer)) {
        return false;
    }
    return !writer.isError();
}

// Write structure on a Connection
bool return_get_map_names::write(yarp::os::ConnectionWriter& connection) const
{
    yarp::os::idl::WireWriter writer(connection);
    if (!writer.writeListHeader(2)) {
        return false;
    }
    if (!write_retval(writer)) {
        return false;
    }
    if (!write_map_names(writer)) {
        return false;
    }
    return !writer.isError();
}

// Convert to a printable string
std::string return_get_map_names::toString() const
{
    yarp::os::Bottle b;
    b.read(*this);
    return b.toString();
}

// Editor: default constructor
return_get_map_names::Editor::Editor()
{
    group = 0;
    obj_owned = true;
    obj = new return_get_map_names;
    dirty_flags(false);
    yarp().setOwner(*this);
}

// Editor: constructor with base class
return_get_map_names::Editor::Editor(return_get_map_names& obj)
{
    group = 0;
    obj_owned = false;
    edit(obj, false);
    yarp().setOwner(*this);
}

// Editor: destructor
return_get_map_names::Editor::~Editor()
{
    if (obj_owned) {
        delete obj;
    }
}

// Editor: edit
bool return_get_map_names::Editor::edit(return_get_map_names& obj, bool dirty)
{
    if (obj_owned) {
        delete this->obj;
    }
    this->obj = &obj;
    obj_owned = false;
    dirty_flags(dirty);
    return true;
}

// Editor: validity check
bool return_get_map_names::Editor::isValid() const
{
    return obj != nullptr;
}

// Editor: state
return_get_map_names& return_get_map_names::Editor::state()
{
    return *obj;
}

// Editor: grouping begin
void return_get_map_names::Editor::start_editing()
{
    group++;
}

// Editor: grouping end
void return_get_map_names::Editor::stop_editing()
{
    group--;
    if (group == 0 && is_dirty) {
        communicate();
    }
}
// Editor: retval setter
void return_get_map_names::Editor::set_retval(const bool retval)
{
    will_set_retval();
    obj->retval = retval;
    mark_dirty_retval();
    communicate();
    did_set_retval();
}

// Editor: retval getter
bool return_get_map_names::Editor::get_retval() const
{
    return obj->retval;
}

// Editor: retval will_set
bool return_get_map_names::Editor::will_set_retval()
{
    return true;
}

// Editor: retval did_set
bool return_get_map_names::Editor::did_set_retval()
{
    return true;
}

// Editor: map_names setter
void return_get_map_names::Editor::set_map_names(const std::vector<std::string>& map_names)
{
    will_set_map_names();
    obj->map_names = map_names;
    mark_dirty_map_names();
    communicate();
    did_set_map_names();
}

// Editor: map_names setter (list)
void return_get_map_names::Editor::set_map_names(size_t index, const std::string& elem)
{
    will_set_map_names();
    obj->map_names[index] = elem;
    mark_dirty_map_names();
    communicate();
    did_set_map_names();
}

// Editor: map_names getter
const std::vector<std::string>& return_get_map_names::Editor::get_map_names() const
{
    return obj->map_names;
}

// Editor: map_names will_set
bool return_get_map_names::Editor::will_set_map_names()
{
    return true;
}

// Editor: map_names did_set
bool return_get_map_names::Editor::did_set_map_names()
{
    return true;
}

// Editor: clean
void return_get_map_names::Editor::clean()
{
    dirty_flags(false);
}

// Editor: read
bool return_get_map_names::Editor::read(yarp::os::ConnectionReader& connection)
{
    if (!isValid()) {
        return false;
    }
    yarp::os::idl::WireReader reader(connection);
    reader.expectAccept();
    if (!reader.readListHeader()) {
        return false;
    }
    int len = reader.getLength();
    if (len == 0) {
        yarp::os::idl::WireWriter writer(reader);
        if (writer.isNull()) {
            return true;
        }
        if (!writer.writeListHeader(1)) {
            return false;
        }
        writer.writeString("send: 'help' or 'patch (param1 val1) (param2 val2)'");
        return true;
    }
    std::string tag;
    if (!reader.readString(tag)) {
        return false;
    }
    if (tag == "help") {
        yarp::os::idl::WireWriter writer(reader);
        if (writer.isNull()) {
            return true;
        }
        if (!writer.writeListHeader(2)) {
            return false;
        }
        if (!writer.writeTag("many", 1, 0)) {
            return false;
        }
        if (reader.getLength() > 0) {
            std::string field;
            if (!reader.readString(field)) {
                return false;
            }
            if (field == "retval") {
                if (!writer.writeListHeader(1)) {
                    return false;
                }
                if (!writer.writeString("bool retval")) {
                    return false;
                }
            }
            if (field == "map_names") {
                if (!writer.writeListHeader(1)) {
                    return false;
                }
                if (!writer.writeString("std::vector<std::string> map_names")) {
                    return false;
                }
            }
        }
        if (!writer.writeListHeader(3)) {
            return false;
        }
        writer.writeString("*** Available fields:");
        writer.writeString("retval");
        writer.writeString("map_names");
        return true;
    }
    bool nested = true;
    bool have_act = false;
    if (tag != "patch") {
        if (((len - 1) % 2) != 0) {
            return false;
        }
        len = 1 + ((len - 1) / 2);
        nested = false;
        have_act = true;
    }
    for (int i = 1; i < len; ++i) {
        if (nested && !reader.readListHeader(3)) {
            return false;
        }
        std::string act;
        std::string key;
        if (have_act) {
            act = tag;
        } else if (!reader.readString(act)) {
            return false;
        }
        if (!reader.readString(key)) {
            return false;
        }
        if (key == "retval") {
            will_set_retval();
            if (!obj->nested_read_retval(reader)) {
                return false;
            }
            did_set_retval();
        } else if (key == "map_names") {
            will_set_map_names();
            if (!obj->nested_read_map_names(reader)) {
                return false;
            }
            did_set_map_names();
        } else {
            // would be useful to have a fallback here
        }
    }
    reader.accept();
    yarp::os::idl::WireWriter writer(reader);
    if (writer.isNull()) {
        return true;
    }
    writer.writeListHeader(1);
    writer.writeVocab32('o', 'k');
    return true;
}

// Editor: write
bool return_get_map_names::Editor::write(yarp::os::ConnectionWriter& connection) const
{
    if (!isValid()) {
        return false;
    }
    yarp::os::idl::WireWriter writer(connection);
    if (!writer.writeListHeader(dirty_count + 1)) {
        return false;
    }
    if (!writer.writeString("patch")) {
        return false;
    }
    if (is_dirty_retval) {
        if (!writer.writeListHeader(3)) {
            return false;
        }
        if (!writer.writeString("set")) {
            return false;
        }
        if (!writer.writeString("retval")) {
            return false;
        }
        if (!obj->nested_write_retval(writer)) {
            return false;
        }
    }
    if (is_dirty_map_names) {
        if (!writer.writeListHeader(3)) {
            return false;
        }
        if (!writer.writeString("set")) {
            return false;
        }
        if (!writer.writeString("map_names")) {
            return false;
        }
        if (!obj->nested_write_map_names(writer)) {
            return false;
        }
    }
    return !writer.isError();
}

// Editor: send if possible
void return_get_map_names::Editor::communicate()
{
    if (group != 0) {
        return;
    }
    if (yarp().canWrite()) {
        yarp().write(*this);
        clean();
    }
}

// Editor: mark dirty overall
void return_get_map_names::Editor::mark_dirty()
{
    is_dirty = true;
}

// Editor: retval mark_dirty
void return_get_map_names::Editor::mark_dirty_retval()
{
    if (is_dirty_retval) {
        return;
    }
    dirty_count++;
    is_dirty_retval = true;
    mark_dirty();
}

// Editor: map_names mark_dirty
void return_get_map_names::Editor::mark_dirty_map_names()
{
    if (is_dirty_map_names) {
        return;
    }
    dirty_count++;
    is_dirty_map_names = true;
    mark_dirty();
}

// Editor: dirty_flags
void return_get_map_names::Editor::dirty_flags(bool flag)
{
    is_dirty = flag;
    is_dirty_retval = flag;
    is_dirty_map_names = flag;
    dirty_count = flag ? 2 : 0;
}

// read retval field
bool return_get_map_names::read_retval(yarp::os::idl::WireReader& reader)
{
    if (!reader.readBool(retval)) {
        retval = 0;
    }
    return true;
}

// write retval field
bool return_get_map_names::write_retval(const yarp::os::idl::WireWriter& writer) const
{
    if (!writer.writeBool(retval)) {
        return false;
    }
    return true;
}

// read (nested) retval field
bool return_get_map_names::nested_read_retval(yarp::os::idl::WireReader& reader)
{
    if (!reader.readBool(retval)) {
        retval = 0;
    }
    return true;
}

// write (nested) retval field
bool return_get_map_names::nested_write_retval(const yarp::os::idl::WireWriter& writer) const
{
    if (!writer.writeBool(retval)) {
        return false;
    }
    return true;
}

// read map_names field
bool return_get_map_names::read_map_names(yarp::os::idl::WireReader& reader)
{
    map_names.clear();
    uint32_t _size0;
    yarp::os::idl::WireState _etype3;
    reader.readListBegin(_etype3, _size0);
    map_names.resize(_size0);
    for (size_t _i4 = 0; _i4 < _size0; ++_i4) {
        if (!reader.readString(map_names[_i4])) {
            reader.fail();
            return false;
        }
    }
    reader.readListEnd();
    return true;
}

// write map_names field
bool return_get_map_names::write_map_names(const yarp::os::idl::WireWriter& writer) const
{
    if (!writer.writeListBegin(BOTTLE_TAG_STRING, static_cast<uint32_t>(map_names.size()))) {
        return false;
    }
    for (const auto& _item5 : map_names) {
        if (!writer.writeString(_item5)) {
            return false;
        }
    }
    if (!writer.writeListEnd()) {
        return false;
    }
    return true;
}

// read (nested) map_names field
bool return_get_map_names::nested_read_map_names(yarp::os::idl::WireReader& reader)
{
    map_names.clear();
    uint32_t _size6;
    yarp::os::idl::WireState _etype9;
    reader.readListBegin(_etype9, _size6);
    map_names.resize(_size6);
    for (size_t _i10 = 0; _i10 < _size6; ++_i10) {
        if (!reader.readString(map_names[_i10])) {
            reader.fail();
            return false;
        }
    }
    reader.readListEnd();
    return true;
}

// write (nested) map_names field
bool return_get_map_names::nested_write_map_names(const yarp::os::idl::WireWriter& writer) const
{
    if (!writer.writeListBegin(BOTTLE_TAG_STRING, static_cast<uint32_t>(map_names.size()))) {
        return false;
    }
    for (const auto& _item11 : map_names) {
        if (!writer.writeString(_item11)) {
            return false;
        }
    }
    if (!writer.writeListEnd()) {
        return false;
    }
    return true;
}
