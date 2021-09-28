/*
 * SPDX-FileCopyrightText: 2006-2021 Istituto Italiano di Tecnologia (IIT)
 * SPDX-License-Identifier: BSD-3-Clause
 */

// Autogenerated by Thrift Compiler (0.14.1-yarped)
//
// This is an automatically generated file.
// It could get re-generated if the ALLOW_IDL_GENERATION flag is on.

#include <MobileBaseVelocityControlRPC.h>

#include <yarp/os/idl/WireTypes.h>

// applyVelocityCommandRPC helper class declaration
class MobileBaseVelocityControlRPC_applyVelocityCommandRPC_helper :
        public yarp::os::Portable
{
public:
    MobileBaseVelocityControlRPC_applyVelocityCommandRPC_helper() = default;
    MobileBaseVelocityControlRPC_applyVelocityCommandRPC_helper(const double x_vel, const double y_vel, const double theta_vel, const double timeout);
    bool write(yarp::os::ConnectionWriter& connection) const override;
    bool read(yarp::os::ConnectionReader& connection) override;

    bool writeCmd(yarp::os::idl::WireWriter& writer) const;
    bool writeCmdLen(yarp::os::idl::WireWriter& writer) const;
    bool writeCmdTag(yarp::os::idl::WireWriter& writer) const;
    bool writeCmdArgs(yarp::os::idl::WireWriter& writer) const;

    bool readCmd(yarp::os::idl::WireReader& reader);
    bool readCmdLen(yarp::os::idl::WireReader& reader);
    bool readCmdTag(yarp::os::idl::WireReader& reader);
    bool readCmdArgs(yarp::os::idl::WireReader& reader);

    bool writeReply(yarp::os::idl::WireWriter& writer) const;

    bool readReply(yarp::os::idl::WireReader& reader);

    void call(MobileBaseVelocityControlRPC* ptr);

    double m_x_vel;
    double m_y_vel;
    double m_theta_vel;
    double m_timeout;

    bool m_return_helper{};

    static constexpr const char* s_tag{"applyVelocityCommandRPC"};
    static constexpr size_t s_tag_len{1};
    static constexpr size_t s_cmd_len{5};
    static constexpr size_t s_reply_len{1};
    static constexpr const char* s_prototype{"bool MobileBaseVelocityControlRPC::applyVelocityCommandRPC(const double x_vel, const double y_vel, const double theta_vel, const double timeout)"};
    static constexpr const char* s_help{""};
};

// getLastVelocityCommandRPC helper class declaration
class MobileBaseVelocityControlRPC_getLastVelocityCommandRPC_helper :
        public yarp::os::Portable
{
public:
    MobileBaseVelocityControlRPC_getLastVelocityCommandRPC_helper() = default;
    bool write(yarp::os::ConnectionWriter& connection) const override;
    bool read(yarp::os::ConnectionReader& connection) override;

    bool writeCmd(yarp::os::idl::WireWriter& writer) const;
    bool writeCmdLen(yarp::os::idl::WireWriter& writer) const;
    bool writeCmdTag(yarp::os::idl::WireWriter& writer) const;
    bool writeCmdArgs(yarp::os::idl::WireWriter& writer) const;

    bool readCmd(yarp::os::idl::WireReader& reader);
    bool readCmdLen(yarp::os::idl::WireReader& reader);
    bool readCmdTag(yarp::os::idl::WireReader& reader);
    bool readCmdArgs(yarp::os::idl::WireReader& reader);

    bool writeReply(yarp::os::idl::WireWriter& writer) const;

    bool readReply(yarp::os::idl::WireReader& reader);

    void call(MobileBaseVelocityControlRPC* ptr);

    return_getLastVelocityCommand m_return_helper{};

    static constexpr const char* s_tag{"getLastVelocityCommandRPC"};
    static constexpr size_t s_tag_len{1};
    static constexpr size_t s_cmd_len{1};
    static constexpr size_t s_reply_len{4};
    static constexpr const char* s_prototype{"return_getLastVelocityCommand MobileBaseVelocityControlRPC::getLastVelocityCommandRPC()"};
    static constexpr const char* s_help{""};
};

// applyVelocityCommandRPC helper class implementation
MobileBaseVelocityControlRPC_applyVelocityCommandRPC_helper::MobileBaseVelocityControlRPC_applyVelocityCommandRPC_helper(const double x_vel, const double y_vel, const double theta_vel, const double timeout) :
        m_x_vel{x_vel},
        m_y_vel{y_vel},
        m_theta_vel{theta_vel},
        m_timeout{timeout},
        m_return_helper{}
{
}

bool MobileBaseVelocityControlRPC_applyVelocityCommandRPC_helper::write(yarp::os::ConnectionWriter& connection) const
{
    yarp::os::idl::WireWriter writer(connection);
    return writeCmd(writer);
}

bool MobileBaseVelocityControlRPC_applyVelocityCommandRPC_helper::read(yarp::os::ConnectionReader& connection)
{
    yarp::os::idl::WireReader reader(connection);
    return readReply(reader);
}

bool MobileBaseVelocityControlRPC_applyVelocityCommandRPC_helper::writeCmd(yarp::os::idl::WireWriter& writer) const
{
    if (!writeCmdLen(writer)) {
        return false;
    }
    if (!writeCmdTag(writer)) {
        return false;
    }
    if (!writeCmdArgs(writer)) {
        return false;
    }
    return true;
}

bool MobileBaseVelocityControlRPC_applyVelocityCommandRPC_helper::writeCmdLen(yarp::os::idl::WireWriter& writer) const
{
    if (!writer.writeListHeader(s_cmd_len)) {
        return false;
    }
    return true;
}

bool MobileBaseVelocityControlRPC_applyVelocityCommandRPC_helper::writeCmdTag(yarp::os::idl::WireWriter& writer) const
{
    if (!writer.writeTag(s_tag, 1, s_tag_len)) {
        return false;
    }
    return true;
}

bool MobileBaseVelocityControlRPC_applyVelocityCommandRPC_helper::writeCmdArgs(yarp::os::idl::WireWriter& writer [[maybe_unused]]) const
{
    if (!writer.writeFloat64(m_x_vel)) {
        return false;
    }
    if (!writer.writeFloat64(m_y_vel)) {
        return false;
    }
    if (!writer.writeFloat64(m_theta_vel)) {
        return false;
    }
    if (!writer.writeFloat64(m_timeout)) {
        return false;
    }
    return true;
}

bool MobileBaseVelocityControlRPC_applyVelocityCommandRPC_helper::readCmd(yarp::os::idl::WireReader& reader)
{
    if (!readCmdLen(reader)) {
        return false;
    }
    if (!readCmdTag(reader)) {
        return false;
    }
    if (!readCmdArgs(reader)) {
        return false;
    }
    return true;
}

bool MobileBaseVelocityControlRPC_applyVelocityCommandRPC_helper::readCmdLen(yarp::os::idl::WireReader& reader)
{
    if (!reader.readListHeader()) {
        reader.fail();
        return false;
    }
    return true;
}

bool MobileBaseVelocityControlRPC_applyVelocityCommandRPC_helper::readCmdTag(yarp::os::idl::WireReader& reader)
{
    std::string tag = reader.readTag();
    if (reader.isError()) {
        return false;
    }
    if (tag != s_tag) {
        reader.fail();
        return false;
    }
    return true;
}

bool MobileBaseVelocityControlRPC_applyVelocityCommandRPC_helper::readCmdArgs(yarp::os::idl::WireReader& reader [[maybe_unused]])
{
    if (!reader.readFloat64(m_x_vel)) {
        reader.fail();
        return false;
    }
    if (!reader.readFloat64(m_y_vel)) {
        reader.fail();
        return false;
    }
    if (!reader.readFloat64(m_theta_vel)) {
        reader.fail();
        return false;
    }
    if (!reader.readFloat64(m_timeout)) {
        reader.fail();
        return false;
    }
    return true;
}

bool MobileBaseVelocityControlRPC_applyVelocityCommandRPC_helper::writeReply(yarp::os::idl::WireWriter& writer) const
{
    if (!writer.isNull()) {
        if (!writer.writeListHeader(s_reply_len)) {
            return false;
        }
        if (!writer.writeBool(m_return_helper)) {
            return false;
        }
    }
    return true;
}

bool MobileBaseVelocityControlRPC_applyVelocityCommandRPC_helper::readReply(yarp::os::idl::WireReader& reader [[maybe_unused]])
{
    if (!reader.readListReturn()) {
        return false;
    }
    if (!reader.readBool(m_return_helper)) {
        reader.fail();
        return false;
    }
    return true;
}

void MobileBaseVelocityControlRPC_applyVelocityCommandRPC_helper::call(MobileBaseVelocityControlRPC* ptr)
{
    m_return_helper = ptr->applyVelocityCommandRPC(m_x_vel, m_y_vel, m_theta_vel, m_timeout);
}

// getLastVelocityCommandRPC helper class implementation
bool MobileBaseVelocityControlRPC_getLastVelocityCommandRPC_helper::write(yarp::os::ConnectionWriter& connection) const
{
    yarp::os::idl::WireWriter writer(connection);
    return writeCmd(writer);
}

bool MobileBaseVelocityControlRPC_getLastVelocityCommandRPC_helper::read(yarp::os::ConnectionReader& connection)
{
    yarp::os::idl::WireReader reader(connection);
    return readReply(reader);
}

bool MobileBaseVelocityControlRPC_getLastVelocityCommandRPC_helper::writeCmd(yarp::os::idl::WireWriter& writer) const
{
    if (!writeCmdLen(writer)) {
        return false;
    }
    if (!writeCmdTag(writer)) {
        return false;
    }
    if (!writeCmdArgs(writer)) {
        return false;
    }
    return true;
}

bool MobileBaseVelocityControlRPC_getLastVelocityCommandRPC_helper::writeCmdLen(yarp::os::idl::WireWriter& writer) const
{
    if (!writer.writeListHeader(s_cmd_len)) {
        return false;
    }
    return true;
}

bool MobileBaseVelocityControlRPC_getLastVelocityCommandRPC_helper::writeCmdTag(yarp::os::idl::WireWriter& writer) const
{
    if (!writer.writeTag(s_tag, 1, s_tag_len)) {
        return false;
    }
    return true;
}

bool MobileBaseVelocityControlRPC_getLastVelocityCommandRPC_helper::writeCmdArgs(yarp::os::idl::WireWriter& writer [[maybe_unused]]) const
{
    return true;
}

bool MobileBaseVelocityControlRPC_getLastVelocityCommandRPC_helper::readCmd(yarp::os::idl::WireReader& reader)
{
    if (!readCmdLen(reader)) {
        return false;
    }
    if (!readCmdTag(reader)) {
        return false;
    }
    if (!readCmdArgs(reader)) {
        return false;
    }
    return true;
}

bool MobileBaseVelocityControlRPC_getLastVelocityCommandRPC_helper::readCmdLen(yarp::os::idl::WireReader& reader)
{
    if (!reader.readListHeader()) {
        reader.fail();
        return false;
    }
    return true;
}

bool MobileBaseVelocityControlRPC_getLastVelocityCommandRPC_helper::readCmdTag(yarp::os::idl::WireReader& reader)
{
    std::string tag = reader.readTag();
    if (reader.isError()) {
        return false;
    }
    if (tag != s_tag) {
        reader.fail();
        return false;
    }
    return true;
}

bool MobileBaseVelocityControlRPC_getLastVelocityCommandRPC_helper::readCmdArgs(yarp::os::idl::WireReader& reader [[maybe_unused]])
{
    return true;
}

bool MobileBaseVelocityControlRPC_getLastVelocityCommandRPC_helper::writeReply(yarp::os::idl::WireWriter& writer) const
{
    if (!writer.isNull()) {
        if (!writer.writeListHeader(s_reply_len)) {
            return false;
        }
        if (!writer.write(m_return_helper)) {
            return false;
        }
    }
    return true;
}

bool MobileBaseVelocityControlRPC_getLastVelocityCommandRPC_helper::readReply(yarp::os::idl::WireReader& reader [[maybe_unused]])
{
    if (!reader.readListReturn()) {
        return false;
    }
    if (!reader.read(m_return_helper)) {
        reader.fail();
        return false;
    }
    return true;
}

void MobileBaseVelocityControlRPC_getLastVelocityCommandRPC_helper::call(MobileBaseVelocityControlRPC* ptr)
{
    m_return_helper = ptr->getLastVelocityCommandRPC();
}

// Constructor
MobileBaseVelocityControlRPC::MobileBaseVelocityControlRPC()
{
    yarp().setOwner(*this);
}

bool MobileBaseVelocityControlRPC::applyVelocityCommandRPC(const double x_vel, const double y_vel, const double theta_vel, const double timeout)
{
    if (!yarp().canWrite()) {
        yError("Missing server method '%s'?", MobileBaseVelocityControlRPC_applyVelocityCommandRPC_helper::s_prototype);
    }
    MobileBaseVelocityControlRPC_applyVelocityCommandRPC_helper helper{x_vel, y_vel, theta_vel, timeout};
    bool ok = yarp().write(helper, helper);
    return ok ? helper.m_return_helper : bool{};
}

return_getLastVelocityCommand MobileBaseVelocityControlRPC::getLastVelocityCommandRPC()
{
    if (!yarp().canWrite()) {
        yError("Missing server method '%s'?", MobileBaseVelocityControlRPC_getLastVelocityCommandRPC_helper::s_prototype);
    }
    MobileBaseVelocityControlRPC_getLastVelocityCommandRPC_helper helper{};
    bool ok = yarp().write(helper, helper);
    return ok ? helper.m_return_helper : return_getLastVelocityCommand{};
}

// help method
std::vector<std::string> MobileBaseVelocityControlRPC::help(const std::string& functionName)
{
    bool showAll = (functionName == "--all");
    std::vector<std::string> helpString;
    if (showAll) {
        helpString.emplace_back("*** Available commands:");
        helpString.emplace_back(MobileBaseVelocityControlRPC_applyVelocityCommandRPC_helper::s_tag);
        helpString.emplace_back(MobileBaseVelocityControlRPC_getLastVelocityCommandRPC_helper::s_tag);
        helpString.emplace_back("help");
    } else {
        if (functionName == MobileBaseVelocityControlRPC_applyVelocityCommandRPC_helper::s_tag) {
            helpString.emplace_back(MobileBaseVelocityControlRPC_applyVelocityCommandRPC_helper::s_prototype);
        }
        if (functionName == MobileBaseVelocityControlRPC_getLastVelocityCommandRPC_helper::s_tag) {
            helpString.emplace_back(MobileBaseVelocityControlRPC_getLastVelocityCommandRPC_helper::s_prototype);
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
bool MobileBaseVelocityControlRPC::read(yarp::os::ConnectionReader& connection)
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
        if (tag == MobileBaseVelocityControlRPC_applyVelocityCommandRPC_helper::s_tag) {
            MobileBaseVelocityControlRPC_applyVelocityCommandRPC_helper helper;
            if (!helper.readCmdArgs(reader)) {
                return false;
            }

            helper.call(this);

            yarp::os::idl::WireWriter writer(reader);
            if (!helper.writeReply(writer)) {
                return false;
            }
            reader.accept();
            return true;
        }
        if (tag == MobileBaseVelocityControlRPC_getLastVelocityCommandRPC_helper::s_tag) {
            MobileBaseVelocityControlRPC_getLastVelocityCommandRPC_helper helper;
            if (!helper.readCmdArgs(reader)) {
                return false;
            }

            helper.call(this);

            yarp::os::idl::WireWriter writer(reader);
            if (!helper.writeReply(writer)) {
                return false;
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
