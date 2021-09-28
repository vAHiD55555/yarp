/*
 * SPDX-FileCopyrightText: 2006-2021 Istituto Italiano di Tecnologia (IIT)
 * SPDX-License-Identifier: BSD-3-Clause
 */

// Autogenerated by Thrift Compiler (0.14.1-yarped)
//
// This is an automatically generated file.
// It could get re-generated if the ALLOW_IDL_GENERATION flag is on.

#include <FrameTransformStorageSetRPC.h>

#include <yarp/os/idl/WireTypes.h>

// setTransformsRPC helper class declaration
class FrameTransformStorageSetRPC_setTransformsRPC_helper :
        public yarp::os::Portable
{
public:
    FrameTransformStorageSetRPC_setTransformsRPC_helper() = default;
    explicit FrameTransformStorageSetRPC_setTransformsRPC_helper(const std::vector<yarp::math::FrameTransform>& transforms);
    bool write(yarp::os::ConnectionWriter& connection) const override;
    bool read(yarp::os::ConnectionReader& connection) override;

    std::vector<yarp::math::FrameTransform> m_transforms;

    bool m_return_helper{};
};

// setTransformRPC helper class declaration
class FrameTransformStorageSetRPC_setTransformRPC_helper :
        public yarp::os::Portable
{
public:
    FrameTransformStorageSetRPC_setTransformRPC_helper() = default;
    explicit FrameTransformStorageSetRPC_setTransformRPC_helper(const yarp::math::FrameTransform& transform);
    bool write(yarp::os::ConnectionWriter& connection) const override;
    bool read(yarp::os::ConnectionReader& connection) override;

    yarp::math::FrameTransform m_transform;

    bool m_return_helper{};
};

// deleteTransformRPC helper class declaration
class FrameTransformStorageSetRPC_deleteTransformRPC_helper :
        public yarp::os::Portable
{
public:
    FrameTransformStorageSetRPC_deleteTransformRPC_helper() = default;
    FrameTransformStorageSetRPC_deleteTransformRPC_helper(const std::string& src, const std::string& dst);
    bool write(yarp::os::ConnectionWriter& connection) const override;
    bool read(yarp::os::ConnectionReader& connection) override;

    std::string m_src;
    std::string m_dst;

    bool m_return_helper{};
};

// clearAllRPC helper class declaration
class FrameTransformStorageSetRPC_clearAllRPC_helper :
        public yarp::os::Portable
{
public:
    FrameTransformStorageSetRPC_clearAllRPC_helper() = default;
    bool write(yarp::os::ConnectionWriter& connection) const override;
    bool read(yarp::os::ConnectionReader& connection) override;

    bool m_return_helper{};
};

// setTransformsRPC helper class implementation
FrameTransformStorageSetRPC_setTransformsRPC_helper::FrameTransformStorageSetRPC_setTransformsRPC_helper(const std::vector<yarp::math::FrameTransform>& transforms) :
        m_transforms{transforms},
        m_return_helper{}
{
}

bool FrameTransformStorageSetRPC_setTransformsRPC_helper::write(yarp::os::ConnectionWriter& connection) const
{
    yarp::os::idl::WireWriter writer(connection);
    if (!writer.writeListHeader(2)) {
        return false;
    }
    if (!writer.writeTag("setTransformsRPC", 1, 1)) {
        return false;
    }
    if (!writer.writeListBegin(BOTTLE_TAG_LIST, static_cast<uint32_t>(m_transforms.size()))) {
        return false;
    }
    for (const auto& _item12 : m_transforms) {
        if (!writer.writeNested(_item12)) {
            return false;
        }
    }
    if (!writer.writeListEnd()) {
        return false;
    }
    return true;
}

bool FrameTransformStorageSetRPC_setTransformsRPC_helper::read(yarp::os::ConnectionReader& connection [[maybe_unused]])
{
    yarp::os::idl::WireReader reader(connection);
    if (!reader.readListReturn()) {
        return false;
    }
    if (!reader.readBool(m_return_helper)) {
        reader.fail();
        return false;
    }
    return true;
}

// setTransformRPC helper class implementation
FrameTransformStorageSetRPC_setTransformRPC_helper::FrameTransformStorageSetRPC_setTransformRPC_helper(const yarp::math::FrameTransform& transform) :
        m_transform{transform},
        m_return_helper{}
{
}

bool FrameTransformStorageSetRPC_setTransformRPC_helper::write(yarp::os::ConnectionWriter& connection) const
{
    yarp::os::idl::WireWriter writer(connection);
    if (!writer.writeListHeader(2)) {
        return false;
    }
    if (!writer.writeTag("setTransformRPC", 1, 1)) {
        return false;
    }
    if (!writer.write(m_transform)) {
        return false;
    }
    return true;
}

bool FrameTransformStorageSetRPC_setTransformRPC_helper::read(yarp::os::ConnectionReader& connection [[maybe_unused]])
{
    yarp::os::idl::WireReader reader(connection);
    if (!reader.readListReturn()) {
        return false;
    }
    if (!reader.readBool(m_return_helper)) {
        reader.fail();
        return false;
    }
    return true;
}

// deleteTransformRPC helper class implementation
FrameTransformStorageSetRPC_deleteTransformRPC_helper::FrameTransformStorageSetRPC_deleteTransformRPC_helper(const std::string& src, const std::string& dst) :
        m_src{src},
        m_dst{dst},
        m_return_helper{}
{
}

bool FrameTransformStorageSetRPC_deleteTransformRPC_helper::write(yarp::os::ConnectionWriter& connection) const
{
    yarp::os::idl::WireWriter writer(connection);
    if (!writer.writeListHeader(3)) {
        return false;
    }
    if (!writer.writeTag("deleteTransformRPC", 1, 1)) {
        return false;
    }
    if (!writer.writeString(m_src)) {
        return false;
    }
    if (!writer.writeString(m_dst)) {
        return false;
    }
    return true;
}

bool FrameTransformStorageSetRPC_deleteTransformRPC_helper::read(yarp::os::ConnectionReader& connection [[maybe_unused]])
{
    yarp::os::idl::WireReader reader(connection);
    if (!reader.readListReturn()) {
        return false;
    }
    if (!reader.readBool(m_return_helper)) {
        reader.fail();
        return false;
    }
    return true;
}

// clearAllRPC helper class implementation
bool FrameTransformStorageSetRPC_clearAllRPC_helper::write(yarp::os::ConnectionWriter& connection) const
{
    yarp::os::idl::WireWriter writer(connection);
    if (!writer.writeListHeader(1)) {
        return false;
    }
    if (!writer.writeTag("clearAllRPC", 1, 1)) {
        return false;
    }
    return true;
}

bool FrameTransformStorageSetRPC_clearAllRPC_helper::read(yarp::os::ConnectionReader& connection [[maybe_unused]])
{
    yarp::os::idl::WireReader reader(connection);
    if (!reader.readListReturn()) {
        return false;
    }
    if (!reader.readBool(m_return_helper)) {
        reader.fail();
        return false;
    }
    return true;
}

// Constructor
FrameTransformStorageSetRPC::FrameTransformStorageSetRPC()
{
    yarp().setOwner(*this);
}

bool FrameTransformStorageSetRPC::setTransformsRPC(const std::vector<yarp::math::FrameTransform>& transforms)
{
    if (!yarp().canWrite()) {
        yError("Missing server method '%s'?", "bool FrameTransformStorageSetRPC::setTransformsRPC(const std::vector<yarp::math::FrameTransform>& transforms)");
    }
    FrameTransformStorageSetRPC_setTransformsRPC_helper helper{transforms};
    bool ok = yarp().write(helper, helper);
    return ok ? helper.m_return_helper : bool{};
}

bool FrameTransformStorageSetRPC::setTransformRPC(const yarp::math::FrameTransform& transform)
{
    if (!yarp().canWrite()) {
        yError("Missing server method '%s'?", "bool FrameTransformStorageSetRPC::setTransformRPC(const yarp::math::FrameTransform& transform)");
    }
    FrameTransformStorageSetRPC_setTransformRPC_helper helper{transform};
    bool ok = yarp().write(helper, helper);
    return ok ? helper.m_return_helper : bool{};
}

bool FrameTransformStorageSetRPC::deleteTransformRPC(const std::string& src, const std::string& dst)
{
    if (!yarp().canWrite()) {
        yError("Missing server method '%s'?", "bool FrameTransformStorageSetRPC::deleteTransformRPC(const std::string& src, const std::string& dst)");
    }
    FrameTransformStorageSetRPC_deleteTransformRPC_helper helper{src, dst};
    bool ok = yarp().write(helper, helper);
    return ok ? helper.m_return_helper : bool{};
}

bool FrameTransformStorageSetRPC::clearAllRPC()
{
    if (!yarp().canWrite()) {
        yError("Missing server method '%s'?", "bool FrameTransformStorageSetRPC::clearAllRPC()");
    }
    FrameTransformStorageSetRPC_clearAllRPC_helper helper{};
    bool ok = yarp().write(helper, helper);
    return ok ? helper.m_return_helper : bool{};
}

// help method
std::vector<std::string> FrameTransformStorageSetRPC::help(const std::string& functionName)
{
    bool showAll = (functionName == "--all");
    std::vector<std::string> helpString;
    if (showAll) {
        helpString.emplace_back("*** Available commands:");
        helpString.emplace_back("setTransformsRPC");
        helpString.emplace_back("setTransformRPC");
        helpString.emplace_back("deleteTransformRPC");
        helpString.emplace_back("clearAllRPC");
        helpString.emplace_back("help");
    } else {
        if (functionName == "setTransformsRPC") {
            helpString.emplace_back("bool setTransformsRPC(const std::vector<yarp::math::FrameTransform>& transforms) ");
        }
        if (functionName == "setTransformRPC") {
            helpString.emplace_back("bool setTransformRPC(const yarp::math::FrameTransform& transform) ");
        }
        if (functionName == "deleteTransformRPC") {
            helpString.emplace_back("bool deleteTransformRPC(const std::string& src, const std::string& dst) ");
        }
        if (functionName == "clearAllRPC") {
            helpString.emplace_back("bool clearAllRPC() ");
        }
        if (functionName == "help") {
            helpString.emplace_back("std::vector<std::string> help(const std::string& functionName = \"--all\")");
            helpString.emplace_back("Return list of available commands, or help message for a specific function");
            helpString.emplace_back("@param functionName name of command for which to get a detailed description. If none or '--all' is provided, print list of available commands");
            helpString.emplace_back("@return list of strings (one string per line)");
        }
    }
    if (helpString.empty()) {
        helpString.emplace_back("Command not found");
    }
    return helpString;
}

// read from ConnectionReader
bool FrameTransformStorageSetRPC::read(yarp::os::ConnectionReader& connection)
{
    yarp::os::idl::WireReader reader(connection);
    reader.expectAccept();
    if (!reader.readListHeader()) {
        reader.fail();
        return false;
    }

    std::string tag = reader.readTag();
    bool direct = (tag == "__direct__");
    if (direct) {
        tag = reader.readTag();
    }
    while (!reader.isError()) {
        if (tag == "setTransformsRPC") {
            std::vector<yarp::math::FrameTransform> transforms;
            transforms.clear();
            uint32_t _size13;
            yarp::os::idl::WireState _etype16;
            reader.readListBegin(_etype16, _size13);
            transforms.resize(_size13);
            for (size_t _i17 = 0; _i17 < _size13; ++_i17) {
                if (!reader.readNested(transforms[_i17])) {
                    reader.fail();
                    return false;
                }
            }
            reader.readListEnd();
            FrameTransformStorageSetRPC_setTransformsRPC_helper helper{transforms};
            helper.m_return_helper = setTransformsRPC(transforms);
            yarp::os::idl::WireWriter writer(reader);
            if (!writer.isNull()) {
                if (!writer.writeListHeader(1)) {
                    return false;
                }
                if (!writer.writeBool(helper.m_return_helper)) {
                    return false;
                }
            }
            reader.accept();
            return true;
        }
        if (tag == "setTransformRPC") {
            yarp::math::FrameTransform transform;
            if (!reader.readNested(transform)) {
                reader.fail();
                return false;
            }
            FrameTransformStorageSetRPC_setTransformRPC_helper helper{transform};
            helper.m_return_helper = setTransformRPC(transform);
            yarp::os::idl::WireWriter writer(reader);
            if (!writer.isNull()) {
                if (!writer.writeListHeader(1)) {
                    return false;
                }
                if (!writer.writeBool(helper.m_return_helper)) {
                    return false;
                }
            }
            reader.accept();
            return true;
        }
        if (tag == "deleteTransformRPC") {
            std::string src;
            std::string dst;
            if (!reader.readString(src)) {
                reader.fail();
                return false;
            }
            if (!reader.readString(dst)) {
                reader.fail();
                return false;
            }
            FrameTransformStorageSetRPC_deleteTransformRPC_helper helper{src, dst};
            helper.m_return_helper = deleteTransformRPC(src, dst);
            yarp::os::idl::WireWriter writer(reader);
            if (!writer.isNull()) {
                if (!writer.writeListHeader(1)) {
                    return false;
                }
                if (!writer.writeBool(helper.m_return_helper)) {
                    return false;
                }
            }
            reader.accept();
            return true;
        }
        if (tag == "clearAllRPC") {
            FrameTransformStorageSetRPC_clearAllRPC_helper helper{};
            helper.m_return_helper = clearAllRPC();
            yarp::os::idl::WireWriter writer(reader);
            if (!writer.isNull()) {
                if (!writer.writeListHeader(1)) {
                    return false;
                }
                if (!writer.writeBool(helper.m_return_helper)) {
                    return false;
                }
            }
            reader.accept();
            return true;
        }
        if (tag == "help") {
            std::string functionName;
            if (!reader.readString(functionName)) {
                functionName = "--all";
            }
            auto help_strings = help(functionName);
            yarp::os::idl::WireWriter writer(reader);
            if (!writer.isNull()) {
                if (!writer.writeListHeader(2)) {
                    return false;
                }
                if (!writer.writeTag("many", 1, 0)) {
                    return false;
                }
                if (!writer.writeListBegin(BOTTLE_TAG_INT32, static_cast<uint32_t>(help_strings.size()))) {
                    return false;
                }
                for (const auto& help_string : help_strings) {
                    if (!writer.writeString(help_string)) {
                        return false;
                    }
                }
                if (!writer.writeListEnd()) {
                    return false;
                }
            }
            reader.accept();
            return true;
        }
        if (reader.noMore()) {
            reader.fail();
            return false;
        }
        std::string next_tag = reader.readTag();
        if (next_tag.empty()) {
            break;
        }
        tag.append("_").append(next_tag);
    }
    return false;
}
