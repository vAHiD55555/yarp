/*
 * SPDX-FileCopyrightText: 2006-2021 Istituto Italiano di Tecnologia (IIT)
 * SPDX-FileCopyrightText: 2006-2010 RobotCub Consortium
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef YARP_DEV_POLYDRIVER_H
#define YARP_DEV_POLYDRIVER_H

#include <yarp/dev/api.h>
#include <yarp/dev/Drivers.h>

namespace yarp::dev {


/**
 * \ingroup dev_class
 *
 * A container for a device driver.
 */
class YARP_dev_API PolyDriver :
        public DeviceDriver
{
public:
    using DeviceDriver::open;

    /**
     * Constructor.
     */
    PolyDriver();

    /**
     * Construct and configure a device by its common name.
     * @param txt common name of the device
     */
    PolyDriver(const std::string& txt);

    /**
     * Create and configure a device, by name.  The config
     * object should have a property called "device" that
     * is set to the common name of the device.  All other
     * properties are passed on the the device's
     * DeviceDriver::open method.
     * @param config configuration options for the device
     */
    PolyDriver(yarp::os::Searchable& config);

    /**
     * Destructor.
     */
    virtual ~PolyDriver();

    PolyDriver(const PolyDriver& alt) = delete;
    const PolyDriver& operator=(const PolyDriver& alt) = delete;

    /**
     * Construct and configure a device by its common name.
     * @param txt common name of the device
     * @return true iff the device was created and configured successfully
     */
    bool open(const std::string& txt);

    /**
     * Create and configure a device, by name.  The config
     * object should have a property called "device" that
     * is set to the common name of the device.  All other
     * properties are passed on the the device's
     * DeviceDriver::open method.
     * @param config configuration options for the device
     * @return true iff the device was created and configured successfully
     */
    bool open(yarp::os::Searchable& config) override;

    /**
     * Make this device be a link to an existing one.
     * The device will be reference counted, and destroyed
     * when the last relevant call to close() is made.
     * @param alt the device to link to
     * @return true iff link succeeded
     */
    bool link(PolyDriver& alt);


    /**
     * Gets the device this object manages.
     * The user is then responsible for managing it.
     * @return the device this object manages.
     */
    DeviceDriver *take();

    /**
     * Take on management of a device.
     * The PolyDriver may be responsible for destroying it.
     * @param dd the device to manage.
     * @param own true if PolyDriver should destroy device when done.
     * @return true on success.
     */
    bool give(DeviceDriver *dd, bool own);

    bool close() override;

    /**
     * Check if device is valid.
     * @return true iff the device was created and configured successfully
     */
    bool isValid() const;

    DeviceDriver *getImplementation() override;

private:
    DeviceDriver *m_dd;

    bool coreOpen(yarp::os::Searchable& config);

#ifndef DOXYGEN_SHOULD_SKIP_THIS
    class Private;
    Private* m_Priv;
#endif
};

} // namespace yarp::dev

#endif // YARP_DEV_POLYDRIVER_H
