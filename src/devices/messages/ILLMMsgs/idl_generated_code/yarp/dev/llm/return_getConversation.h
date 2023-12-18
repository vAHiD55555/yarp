/*
 * SPDX-FileCopyrightText: 2006-2021 Istituto Italiano di Tecnologia (IIT)
 * SPDX-License-Identifier: BSD-3-Clause
 */

// Autogenerated by Thrift Compiler (0.14.1-yarped)
//
// This is an automatically generated file.
// It could get re-generated if the ALLOW_IDL_GENERATION flag is on.

#ifndef YARP_THRIFT_GENERATOR_STRUCT_RETURN_GETCONVERSATION_H
#define YARP_THRIFT_GENERATOR_STRUCT_RETURN_GETCONVERSATION_H

#include <yarp/os/Wire.h>
#include <yarp/os/idl/WireTypes.h>
#include <yarp/dev/ILLM.h>

namespace yarp::dev::llm {

class return_getConversation :
        public yarp::os::idl::WirePortable
{
public:
    // Fields
    bool ret{false};
    std::vector<yarp::dev::LLM_Message> conversation{};

    // Default constructor
    return_getConversation() = default;

    // Constructor with field values
    return_getConversation(const bool ret,
                           const std::vector<yarp::dev::LLM_Message>& conversation);

    // Read structure on a Wire
    bool read(yarp::os::idl::WireReader& reader) override;

    // Read structure on a Connection
    bool read(yarp::os::ConnectionReader& connection) override;

    // Write structure on a Wire
    bool write(const yarp::os::idl::WireWriter& writer) const override;

    // Write structure on a Connection
    bool write(yarp::os::ConnectionWriter& connection) const override;

    // Convert to a printable string
    std::string toString() const;

    // If you want to serialize this class without nesting, use this helper
    typedef yarp::os::idl::Unwrapped<return_getConversation> unwrapped;

private:
    // read/write ret field
    bool read_ret(yarp::os::idl::WireReader& reader);
    bool write_ret(const yarp::os::idl::WireWriter& writer) const;
    bool nested_read_ret(yarp::os::idl::WireReader& reader);
    bool nested_write_ret(const yarp::os::idl::WireWriter& writer) const;

    // read/write conversation field
    bool read_conversation(yarp::os::idl::WireReader& reader);
    bool write_conversation(const yarp::os::idl::WireWriter& writer) const;
    bool nested_read_conversation(yarp::os::idl::WireReader& reader);
    bool nested_write_conversation(const yarp::os::idl::WireWriter& writer) const;
};

} // namespace yarp::dev::llm

#endif // YARP_THRIFT_GENERATOR_STRUCT_RETURN_GETCONVERSATION_H
