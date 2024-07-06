/*
 * SPDX-FileCopyrightText: 2006-2021 Istituto Italiano di Tecnologia (IIT)
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#ifndef YARP_DEV_FRAMETRANSFORMCLIENT_H
#define YARP_DEV_FRAMETRANSFORMCLIENT_H


#include <yarp/os/BufferedPort.h>
#include <yarp/os/Network.h>
#include <yarp/os/PeriodicThread.h>
#include <yarp/os/Semaphore.h>
#include <yarp/os/Time.h>

#include <yarp/sig/Vector.h>

#include <yarp/dev/ControlBoardHelpers.h>
#include <yarp/dev/ControlBoardInterfaces.h>
#include <yarp/dev/IFrameTransform.h>
#include <yarp/dev/IFrameTransformClientControl.h>
#include <yarp/dev/IFrameTransformStorage.h>
#include <yarp/dev/PolyDriver.h>

#include <yarp/math/FrameTransform.h>
#include <yarp/os/PeriodicThread.h>
#include <mutex>
#include <yarp/robotinterface/Param.h>
#include <yarp/robotinterface/XMLReader.h>

#include <yarp/dev/FrameTransformContainer.h>
#include <mutex>

#define DEFAULT_THREAD_PERIOD 20 //ms
const int MAX_PORTS = 5;

/**
 *  @ingroup dev_impl_network_clients
 *
 * \section FrameTransformClient_device_parameters Description of input parameters
 *
 * \brief `frameTransformClient`: A client to manage FrameTransforms for a robot
 * (For more information, go to \ref FrameTransform)
 *
 *   Parameters required by this device are:
 * | Parameter name   | SubParameter         | Type    | Units          | Default Value         | Required     | Description                                                                                                |
 * |:----------------:|:--------------------:|:-------:|:--------------:|:---------------------:|:-----------: |:----------------------------------------------------------------------------------------------------------:|
 * | filexml_option   | -                    | string  | -              | ftc_local_only.xml    | no           | The name of the xml file containing the needed client configuration                                        |
 * | testxml_from     | -                    | string  | -              | -                     | no           | NB: FOR TEST ONLY. The name of the xml file containing the configuration to test                           |
 * | testxml_context  | -                    | string  | -              | -                     | no           | NB: FOR TEST ONLY. The context folder the test xml file has to be searched in                              |
 * | period           | -                    | float   | -              | 10ms                  | no           | The period for publishing individual tfs on port                                                           |
 * | ft_client_prefix | -                    | string  | -              | ""                    | no           | A prefix to add to the names of all the ports opened by the NWCs instantiated by the frameTransformClient  |
 * | ft_server_prefix | -                    | string  | -              | ""                    | no           | The prefix added to all the names of the ports opened by the NWSs instantiated by the frameTransformServer |
 * | local_rpc        | -                    | string  | -              | "/ftClient/rpc"       | no           | Name of the utility RPC port opened by the client                                                          |
 *
 * Example of command line:
 * \code{.unparsed}
 * yarpdev --device frameTransformClient --filexml_option ftc_local_only.xml
 * \endcode
 *
 * Example of configuration file using .ini format.
 * \code{.unparsed}
 * device frameTransformClient
 * filexml_option ftc_local_only.xml
 * \endcode
 */

class FrameTransformClient :
        public yarp::dev::DeviceDriver,
        public yarp::dev::IFrameTransform,
        public yarp::os::PortReader,
        public yarp::os::PeriodicThread
{
private:
    enum class ConnectionType {DISCONNECTED = 0, DIRECT, INVERSE, UNDIRECT, IDENTITY};

    FrameTransformClient::ConnectionType priv_getConnectionType(const std::string &target_frame, const std::string &source_frame, std::string* commonAncestor);

    bool priv_canExplicitTransform(const std::string& target_frame_id, const std::string& source_frame_id) const;
    bool priv_getChainedTransform(const std::string &target_frame_id, const std::string &source_frame_id, yarp::sig::Matrix &transform) const;

protected:

    yarp::os::Port      m_rpc_InterfaceToUser;
    std::string         m_local_name;
    double              m_period;
    std::mutex          m_rpc_mutex;

    //ports to broadcast stuff...
    struct broadcast_port_t
    {
        enum class format_t {matrix=0} format= format_t::matrix;
        yarp::os::Port port;
        std::string transform_src;
        std::string transform_dst;
    };
    std::vector<broadcast_port_t*>  m_array_of_ports;

    //enum to generate tf diagrams
    enum show_transforms_in_diagram_t
    {
        do_not_show = 0,
        show_quaternion = 1,
        show_matrix = 2,
        show_rpy = 3
    };
    show_transforms_in_diagram_t  m_show_transforms_in_diagram = do_not_show;

    //new stuff
    yarp::robotinterface::Robot m_robot;
    yarp::dev::IFrameTransformStorageGet* m_ift_get = nullptr;
    yarp::dev::IFrameTransformStorageSet* m_ift_set = nullptr;
    yarp::dev::IFrameTransformStorageUtils* m_ift_util = nullptr;


public:
    FrameTransformClient();
    ~FrameTransformClient();

public:
    // DeviceDriver methods
    bool open(yarp::os::Searchable& config) override;
    bool close() override;
    bool read(yarp::os::ConnectionReader& connection) override;

    //IFrameTransform
    bool     allFramesAsString(std::string &all_frames) override;
    bool     canTransform(const std::string &target_frame, const std::string &source_frame) override;
    bool     clear() override;
    bool     frameExists(const std::string &frame_id) override;
    bool     getAllFrameIds(std::vector< std::string > &ids) override;
    bool     getParent(const std::string &frame_id, std::string &parent_frame_id) override;
    bool     getTransform(const std::string &target_frame_id, const std::string &source_frame_id, yarp::sig::Matrix &transform) override;
    bool     setTransform(const std::string &target_frame_id, const std::string &source_frame_id, const yarp::sig::Matrix &transform) override;
    bool     setTransformStatic(const std::string &target_frame_id, const std::string &source_frame_id, const yarp::sig::Matrix &transform) override;
    bool     deleteTransform(const std::string &target_frame_id, const std::string &source_frame_id) override;
    bool     transformPoint(const std::string &target_frame_id, const std::string &source_frame_id, const yarp::sig::Vector &input_point, yarp::sig::Vector &transformed_point) override;
    bool     transformPose(const std::string &target_frame_id, const std::string &source_frame_id, const yarp::sig::Vector &input_pose, yarp::sig::Vector &transformed_pose) override;
    bool     transformQuaternion(const std::string &target_frame_id, const std::string &source_frame_id, const yarp::math::Quaternion &input_quaternion, yarp::math::Quaternion &transformed_quaternion) override;
    bool     waitForTransform(const std::string &target_frame_id, const std::string &source_frame_id, const double &timeout) override;

    //PeriodicThread
    bool     threadInit() override;
    void     threadRelease() override;
    void     run() override;

    //extra
    bool          priv_generate_view();
    std::string   priv_get_matrix_as_text(yarp::math::FrameTransform* t);
};

#endif // YARP_DEV_FRAMETRANSFORMCLIENT_H
