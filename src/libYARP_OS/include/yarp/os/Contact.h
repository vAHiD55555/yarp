/*
 * Copyright (C) 2006-2018 Istituto Italiano di Tecnologia (IIT)
 * Copyright (C) 2006-2010 RobotCub Consortium
 * All rights reserved.
 *
 * This software may be modified and distributed under the terms of the
 * BSD-3-Clause license. See the accompanying LICENSE file for details.
 */

#ifndef YARP_OS_CONTACT_H
#define YARP_OS_CONTACT_H

#include <yarp/conf/system.h>
#include <yarp/conf/compiler.h>
#include <string>
#include <yarp/os/NestedContact.h>


namespace yarp {
    namespace os {
        class Contact;
        class Searchable;
    }
}

/**
 * @ingroup comm_class
 * @brief Represents how to reach a part of a YARP network.
 *
 * May contain complete or partial information about network parameters.
 * Use the constructors or the factory methods (Contact::fromString,
 * Contact::fromConfig) to create Contact objects.
 */
class YARP_OS_API yarp::os::Contact {
public:

/** @{ */

    /**
     * @brief Constructor.
     *
     * @param name the name
     * @param carrier the carrier
     * @param hostname the hostname
     * @param port the port number
     */
    Contact(const std::string& name = std::string(),
            const std::string& carrier = std::string(),
            const std::string& hostname = std::string(),
            int port = -1);

    /**
     * @brief Constructor by hostname and port.
     *
     * @param hostname the hostname
     * @param port the port number
     */
    Contact(const std::string& hostname,
            int port);

    /**
     * @brief Constructor by socket.
     *
     * @param carrier the carrier
     * @param hostname the hostname
     * @param port the port number
     */
    Contact(const std::string& carrier,
            const std::string& hostname,
            int port);

    /**
     * @brief Copy constructor.
     *
     * @param rhs the Contact to copy
     */
    Contact(const Contact& rhs);

    /**
     * @brief Move constructor.
     *
     * @param rhs the Contact to be moved
     */
    Contact(Contact&& rhs);

    /**
     * @brief Destructor.
     */
    virtual ~Contact();

    /**
     * Copy assignment operator.
     *
     * @param rhs the Contact to copy
     * @return this object
     */
    Contact& operator=(const Contact& rhs);

    /**
     * @brief Move assignment operator.
     *
     * @param rhs the Contact to be moved
     * @return this object
     */
    Contact& operator=(Contact&& rhs);

/** @} */
/** @{ */

    /**
     * @brief Factory method.
     *
     * Returns a Contact configured from the information in config.
     *
     * @param config a Property, Bottle, or other Searchable containing the
     *               Contact configuration.
     *               Key names include "name", "ip", "port_number", "carrier"
     * @return the new Contact
     */
    static Contact fromConfig(const Searchable& config);

    /**
     * @brief Factory method.
     *
     * Parse a textual representation of a Contact.
     *
     * @param txt the text to parse
     * @return the new Contact
     */
    static Contact fromString(const std::string& txt);

/** @} */
/** @{ */

    /**
     * @brief Get the name associated with this Contact.
     *
     * If the name is not set, it is generated from hostname and port.
     *
     * @return The name associated with this Contact, or the empty string
     *         if no name is set.
     */
    std::string getName() const;

    /**
     * @brief Set the name associated with this Contact.
     *
     * @param name the new name
     */
    void setName(const std::string& name);

    /**
     * @brief Get the name associated with this Contact.
     *
     * The regName is not generated and is set only using setName, or one of the
     * factory methods (byName, byConfig, and fromString).
     *
     * @return The regName associated with this Contact
     */
    std::string getRegName() const;

/** @} */
/** @{ */

    /**
     * @brief Get the host name associated with this Contact for socket
     * communication.
     *
     * @return The host name associated with this Contact, or the empty string
     *         if no host name is set
     */
    std::string getHost() const;

    /**
     * @brief Set the host name to be the input parameter.
     *
     * @param hostname the new host name
     */
    void setHost(const std::string& hostname);

/** @} */
/** @{ */

    /**
     * @brief Get the port number associated with this Contact for socket
     * communication.
     *
     * @return The port number associated with this Contact, or <= 0
     *         if no port number is set
     */
    int getPort() const;


    /**
     * @brief Set the port number to be the input parameter.
     *
     * @param port the new port number
     */
    void setPort(int port);

/** @} */
/** @{ */

    /**
     * @brief Get the carrier associated with this Contact for socket
     * communication.
     *
     * @return The carrier associated with this Contact, or the empty string
     *         if no carrier is set
     */
    std::string getCarrier() const;

    /**
     * @brief Set the carrier to use for this Contact.
     *
     * @param carrier the new carrier
     */
    void setCarrier(const std::string& carrier);

/** @} */
/** @{ */

    /**
     * @brief Get the NestedContact containing extra information for this
     * Contact.
     *
     * @return the nested contact
     */
    const NestedContact& getNested() const;

    /**
     * @brief Sets the NestedContact containing extra information for this
     * Contact.
     *
     * @param nestedContact the nested Contact
     */
    void setNestedContact(const yarp::os::NestedContact& nestedContact);

/** @} */
/** @{ */

    /**
     * @brief Check if this Contact has a timeout.
     *
     * @return true iff this Contact has a timeout.
     */
    bool hasTimeout() const;

    /**
     * @brief Get timeout for this Address.
     *
     * @return The timeout for this Address
     */
    float getTimeout() const;

    /**
     * @brief Set timeout for this Contact.
     *
     * @param timeout The timeout to set.
     */
    void setTimeout(float timeout);

/** @} */
/** @{ */

    /**
     * @brief Set information to a Contact about how to reach it using socket
     * communication.
     *
     * @param carrier the carrier (network protocol) to use
     * @param hostname the name of the host machine (usually expressed as an
     *                 IP address)
     * @param port the number of the socket port to use
     */
    void setSocket(const std::string& carrier,
                   const std::string& hostname,
                   int port);

/** @} */
/** @{ */

    /**
     * @brief Checks if a Contact is tagged as valid.
     *
     * @return true iff Contact is tagged as valid.
     *         All Contact objects are valid except the one created by
     *         Contact::invalid.
     */
    bool isValid() const;

    /**
     * @brief Get a textual representation of the Contact.
     *
     * @return a textual representation of the Contact
     */
    std::string toString() const;

    /**
     * @brief Get a representation of the Contact as a URI.
     *
     * @param includeCarrier if false do not include the carrier in the URI
     * @return a URI representation of the Contact
     */
    std::string toURI(bool includeCarrier = true) const;

/** @} */
/** @{ */

    /**
     * @brief If the host is a machine name, convert it to a plausible IP
     * address.
     *
     * @param name the name to convert
     */
    static std::string convertHostToIp(const char *name);

/** @} */

#ifndef YARP_NO_DEPRECATED // since YARP 2.3.68

/** @{ */

    /**
     * @brief Copies a Contact and sets the name for the new one.
     *
     * @param name the name
     * @return the new Contact
     * @deprecated since YARP 2.3.68
     */
    YARP_DEPRECATED_MSG("Use setName instead")
    Contact addName(const std::string& name) const;

    /**
     * @brief Copies a Contact and sets the carrier for the new one.
     *
     * @param carrier the carrier
     * @return the new Contact
     * @deprecated since YARP 2.3.68
     */
    YARP_DEPRECATED_MSG("Use setCarrier instead")
    Contact addCarrier(const std::string& carrier) const;

    /**
     * @brief Copies a Contact and sets the hostname for the new one.
     *
     * @param hostname the hostname
     * @return the new Contact
     * @deprecated since YARP 2.3.68
     */
    YARP_DEPRECATED_MSG("Use setHost instead")
    Contact addHost(const std::string& hostname) const;

    /**
     * @brief Returns a new Contact with the previous information plus the
     * updated port number
     *
     * @param port port number
     * @return a new Contact the the port number updated
     * @deprecated since YARP 2.3.68
     */
    YARP_DEPRECATED_MSG("Use setPort instead")
    Contact addPort(int port) const;

    /**
     * @brief Copies a Contact and sets the NestedContact for the new one.
     *
     * @param nestedContact the nested Contact
     * @return the new Contact
     * @deprecated since YARP 2.3.68
     */
    YARP_DEPRECATED_MSG("Use setNestedContact instead")
    Contact addNested(const NestedContact& nestedContact) const;

    /**
     * @brief Add information to a Contact about how to reach it using socket
     * communication.
     *
     * @param carrier the carrier (network protocol) to use
     * @param hostname the name of the host machine (usually expressed as an
     *                 IP address)
     * @param port the number of the socket port to use
     * @return the new Contact with socket communication parameters
     * @deprecated since YARP 2.3.68
     */
    YARP_DEPRECATED_MSG("Use setSocket instead")
    Contact addSocket(const std::string& carrier,
                      const std::string& hostname,
                      int port) const;

/** @} */
/** @{ */

    /**
     * @brief Factory method.
     *
     * Returns a new, blank, unnamed, invalid Contact.
     *
     * @return a blank Contact
     * @deprecated since YARP 2.3.68
     */
    YARP_DEPRECATED_MSG("Use the default constructor instead")
    static Contact empty();

    /**
     * @brief Factory method.
     *
     * Returns a new, invalid Contact.
     *
     * @return an invalid Contact
     * @deprecated since YARP 2.3.68
     */
    YARP_DEPRECATED_MSG("Use the default constructor instead")
    static Contact invalid();

    /**
     * @brief Factory method.
     *
     * Returns a named Contact, with no information about how to reach that
     * Contact.
     *
     * @param name the name for the Contact
     * @return a named Contact
     * @deprecated since YARP 2.3.68
     */
    YARP_DEPRECATED_MSG("Use constructor by name instead")
    static Contact byName(const std::string& name);

    /**
     * @brief Factory method.
     *
     * Returns an unnamed Contact, with information about which carrier/protocol
     * to use to reach that Contact.
     *
     * @param carrier the carrier to add ("tcp", "udp", ...)
     * @return the new Contact
     */
    YARP_DEPRECATED_MSG("Use constructor by name and carrier instead")
    static Contact byCarrier(const std::string& carrier);

    /**
     * @brief Factory method.
     *
     * Creates an unnamed Contact, with information about how to reach it using
     * socket communication.
     *
     * @param carrier the carrier (network protocol) to use
     * @param hostname the name of the host machine (usually expressed as an
     *                 IP address)
     * @param port the number of the socket port to use
     * @return the new Contact
     * @deprecated since YARP 2.3.68
     */
    YARP_DEPRECATED_MSG("Use constructor by socket instead")
    static Contact bySocket(const std::string& carrier,
                            const std::string& hostname,
                            int port);

    /**
     * @brief Factory method.
     *
     * Returns a Contact configured from the information in config.
     *
     * @param config a Property, Bottle, or other Searchable containing the
     *               Contact configuration.
     *               Key names include "name", "ip", "port_number", "carrier"
     * @return the new Contact
     * @deprecated since YARP 2.3.68
     */
    YARP_DEPRECATED_MSG("Use fromConfig instead")
    static Contact byConfig(Searchable& config);

/** @} */

#endif // YARP_NO_DEPRECATED

#ifndef DOXYGEN_SHOULD_SKIP_THIS
private:
    class Private;
    Private * mPriv;
#endif // DOXYGEN_SHOULD_SKIP_THIS

};

#endif // YARP_OS_CONTACT_H
