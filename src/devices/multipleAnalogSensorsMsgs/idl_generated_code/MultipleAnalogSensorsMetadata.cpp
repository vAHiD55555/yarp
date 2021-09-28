/*
 * SPDX-FileCopyrightText: 2006-2021 Istituto Italiano di Tecnologia (IIT)
 * SPDX-License-Identifier: BSD-3-Clause
 */

// Autogenerated by Thrift Compiler (0.14.1-yarped)
//
// This is an automatically generated file.
// It could get re-generated if the ALLOW_IDL_GENERATION flag is on.

#include <MultipleAnalogSensorsMetadata.h>

#include <yarp/os/idl/WireTypes.h>

// getMetadata helper class declaration
class MultipleAnalogSensorsMetadata_getMetadata_helper :
        public yarp::os::Portable
{
public:
    MultipleAnalogSensorsMetadata_getMetadata_helper() = default;
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

    void call(MultipleAnalogSensorsMetadata* ptr);

    SensorRPCData m_return_helper{};

    static constexpr const char* s_tag{"getMetadata"};
    static constexpr size_t s_tag_len{1};
    static constexpr size_t s_cmd_len{1};
    static constexpr size_t s_reply_len{10};
    static constexpr const char* s_prototype{"SensorRPCData MultipleAnalogSensorsMetadata::getMetadata()"};
    static constexpr const char* s_help{
        "Read the sensor metadata necessary to configure the MultipleAnalogSensorsClient device."
    };
};

// getMetadata helper class implementation
bool MultipleAnalogSensorsMetadata_getMetadata_helper::write(yarp::os::ConnectionWriter& connection) const
{
    yarp::os::idl::WireWriter writer(connection);
    return writeCmd(writer);
}

bool MultipleAnalogSensorsMetadata_getMetadata_helper::read(yarp::os::ConnectionReader& connection)
{
    yarp::os::idl::WireReader reader(connection);
    return readReply(reader);
}

bool MultipleAnalogSensorsMetadata_getMetadata_helper::writeCmd(yarp::os::idl::WireWriter& writer) const
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

bool MultipleAnalogSensorsMetadata_getMetadata_helper::writeCmdLen(yarp::os::idl::WireWriter& writer) const
{
    if (!writer.writeListHeader(s_cmd_len)) {
        return false;
    }
    return true;
}

bool MultipleAnalogSensorsMetadata_getMetadata_helper::writeCmdTag(yarp::os::idl::WireWriter& writer) const
{
    if (!writer.writeTag(s_tag, 1, s_tag_len)) {
        return false;
    }
    return true;
}

bool MultipleAnalogSensorsMetadata_getMetadata_helper::writeCmdArgs(yarp::os::idl::WireWriter& writer [[maybe_unused]]) const
{
    return true;
}

bool MultipleAnalogSensorsMetadata_getMetadata_helper::readCmd(yarp::os::idl::WireReader& reader)
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

bool MultipleAnalogSensorsMetadata_getMetadata_helper::readCmdLen(yarp::os::idl::WireReader& reader)
{
    if (!reader.readListHeader()) {
        reader.fail();
        return false;
    }
    return true;
}

bool MultipleAnalogSensorsMetadata_getMetadata_helper::readCmdTag(yarp::os::idl::WireReader& reader)
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

bool MultipleAnalogSensorsMetadata_getMetadata_helper::readCmdArgs(yarp::os::idl::WireReader& reader [[maybe_unused]])
{
    return true;
}

bool MultipleAnalogSensorsMetadata_getMetadata_helper::writeReply(yarp::os::idl::WireWriter& writer) const
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

bool MultipleAnalogSensorsMetadata_getMetadata_helper::readReply(yarp::os::idl::WireReader& reader [[maybe_unused]])
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

void MultipleAnalogSensorsMetadata_getMetadata_helper::call(MultipleAnalogSensorsMetadata* ptr)
{
    m_return_helper = ptr->getMetadata();
}

// Constructor
MultipleAnalogSensorsMetadata::MultipleAnalogSensorsMetadata()
{
    yarp().setOwner(*this);
}

SensorRPCData MultipleAnalogSensorsMetadata::getMetadata()
{
    if (!yarp().canWrite()) {
        yError("Missing server method '%s'?", MultipleAnalogSensorsMetadata_getMetadata_helper::s_prototype);
    }
    MultipleAnalogSensorsMetadata_getMetadata_helper helper{};
    bool ok = yarp().write(helper, helper);
    return ok ? helper.m_return_helper : SensorRPCData{};
}

// help method
std::vector<std::string> MultipleAnalogSensorsMetadata::help(const std::string& functionName)
{
    bool showAll = (functionName == "--all");
    std::vector<std::string> helpString;
    if (showAll) {
        helpString.emplace_back("*** Available commands:");
        helpString.emplace_back(MultipleAnalogSensorsMetadata_getMetadata_helper::s_tag);
        helpString.emplace_back("help");
    } else {
        if (functionName == MultipleAnalogSensorsMetadata_getMetadata_helper::s_tag) {
            helpString.emplace_back(MultipleAnalogSensorsMetadata_getMetadata_helper::s_prototype);
            helpString.emplace_back(MultipleAnalogSensorsMetadata_getMetadata_helper::s_help);
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
bool MultipleAnalogSensorsMetadata::read(yarp::os::ConnectionReader& connection)
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
        if (tag == MultipleAnalogSensorsMetadata_getMetadata_helper::s_tag) {
            MultipleAnalogSensorsMetadata_getMetadata_helper helper;
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
