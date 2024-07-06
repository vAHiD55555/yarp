/*
 * SPDX-FileCopyrightText: 2006-2021 Istituto Italiano di Tecnologia (IIT)
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#ifndef YARP_DEV_MAP2D_NWC_YARP_H
#define YARP_DEV_MAP2D_NWC_YARP_H


#include <yarp/os/Network.h>
#include <yarp/os/BufferedPort.h>
#include <yarp/dev/IMap2D.h>
#include <yarp/sig/Vector.h>
#include <yarp/dev/MapGrid2D.h>
#include <yarp/dev/Map2DLocation.h>
#include <yarp/dev/Map2DArea.h>
#include <yarp/os/Semaphore.h>
#include <yarp/os/Time.h>
#include <yarp/dev/PolyDriver.h>
#include "IMap2DMsgs.h"

#include "Map2D_nwc_yarp_ParamsParser.h"

/**
 * @ingroup dev_impl_nwc_yarp dev_impl_navigation
 *
 * \section Map2D_nwc_yarp
 *
 * \brief `Map2D_nwc_yarp`: A device which allows a client application to store/retrieve user maps device in a map server.
 *
 * Parameters required by this device are shown in class: Map2D_nwc_yarp_ParamsParser
 *
 */

class Map2D_nwc_yarp :
        public yarp::dev::DeviceDriver,
        public yarp::dev::Nav2D::IMap2D,
        public Map2D_nwc_yarp_ParamsParser
{
protected:
    yarp::os::Port      m_rpcPort_to_Map2D_nws;
    IMap2DMsgs          m_map_RPC;
    std::mutex          m_mutex;

public:

     /* DeviceDriver methods */
    bool open(yarp::os::Searchable& config) override;
    bool close() override;

    /* The following methods belong to IMap2D interface */
    bool     clearAllMaps  () override;
    bool     remove_map (std::string map_name) override;
    bool     store_map  (const yarp::dev::Nav2D::MapGrid2D& map) override;
    bool     get_map    (std::string map_name, yarp::dev::Nav2D::MapGrid2D& map) override;
    bool     get_map_names(std::vector<std::string>& map_names) override;

    bool     storeLocation(std::string location_name, yarp::dev::Nav2D::Map2DLocation loc) override;
    bool     storeArea(std::string area_name, yarp::dev::Nav2D::Map2DArea area) override;
    bool     storePath(std::string path_name, yarp::dev::Nav2D::Map2DPath path) override;

    bool     getLocation(std::string location_name, yarp::dev::Nav2D::Map2DLocation& loc) override;
    bool     getArea(std::string location_name, yarp::dev::Nav2D::Map2DArea& area) override;
    bool     getPath(std::string path_name, yarp::dev::Nav2D::Map2DPath& path) override;

    bool     renameLocation(std::string original_name, std::string new_name) override;
    bool     renameArea(std::string original_name, std::string new_name) override;
    bool     renamePath(std::string original_name, std::string new_name) override;

    bool     deleteLocation(std::string location_name) override;
    bool     deleteArea(std::string location_name) override;
    bool     deletePath(std::string path_name) override;

    bool     getLocationsList(std::vector<std::string>& locations) override;
    bool     getAreasList(std::vector<std::string>& locations) override;
    bool     getPathsList(std::vector<std::string>& paths) override;

    bool     getAllLocations(std::vector<yarp::dev::Nav2D::Map2DLocation>& locations) override;
    bool     getAllAreas(std::vector<yarp::dev::Nav2D::Map2DArea>& areas) override;
    bool     getAllPaths(std::vector<yarp::dev::Nav2D::Map2DPath>& paths) override;

    bool     clearAllLocations() override;
    bool     clearAllAreas() override;
    bool     clearAllPaths() override;

    bool     clearAllMapsTemporaryFlags() override;
    bool     clearMapTemporaryFlags(std::string map_name) override;

    bool     saveMapsCollection(std::string maps_collection_file) override;
    bool     loadMapsCollection(std::string maps_collection_file) override;
    bool     saveLocationsAndExtras(std::string locations_collection_file) override;
    bool     loadLocationsAndExtras(std::string locations_collection_file) override;
    bool     saveMapToDisk(std::string map_name, std::string file_name) override;
    bool     loadMapFromDisk(std::string file_name) override;
    bool     enableMapsCompression(bool enable) override;
};

#endif // YARP_DEV_MAP2D_NWC_YARP_H
