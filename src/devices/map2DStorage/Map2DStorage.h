/*
 * SPDX-FileCopyrightText: 2006-2021 Istituto Italiano di Tecnologia (IIT)
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#ifndef YARP_DEV_MAP2DSERVER_H
#define YARP_DEV_MAP2DSERVER_H

#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <mutex>

#include <yarp/os/Network.h>
#include <yarp/os/Port.h>
#include <yarp/os/Bottle.h>
#include <yarp/os/Time.h>
#include <yarp/os/Property.h>

#include <yarp/os/PeriodicThread.h>
#include <yarp/os/BufferedPort.h>
#include <yarp/os/RpcServer.h>
#include <yarp/sig/Vector.h>
#include <yarp/dev/IMap2D.h>
#include <yarp/dev/MapGrid2D.h>
#include <yarp/dev/Map2DLocation.h>
#include <yarp/dev/Map2DArea.h>
#include <yarp/dev/Map2DPath.h>
#include <yarp/os/ResourceFinder.h>

#include <yarp/dev/PolyDriver.h>
#include <yarp/dev/DeviceDriver.h>
#include <yarp/dev/api.h>

#include "Map2DStorage_ParamsParser.h"

#define DEFAULT_THREAD_PERIOD 20 //ms

/**
 *  @ingroup dev_impl_wrapper dev_impl_navigation
 *
 * \section Map2DStorage
 *
 * \brief `Map2DStorage`: A device capable of read/save collections of maps from disk, and make them accessible to any Map2DClient device.
 *
 * Parameters required by this device are shown in class: Map2DStorage_ParamsParser
 */

class Map2DStorage :
        public yarp::dev::DeviceDriver,
        public yarp::os::PortReader,
        public yarp::dev::Nav2D::IMap2D,
        public Map2DStorage_ParamsParser
{
private:
    std::map<std::string, yarp::dev::Nav2D::MapGrid2D>     m_maps_storage;
    std::map<std::string, yarp::dev::Nav2D::Map2DLocation> m_locations_storage;
    std::map<std::string, yarp::dev::Nav2D::Map2DPath>     m_paths_storage;
    std::map<std::string, yarp::dev::Nav2D::Map2DArea>     m_areas_storage;

public:
    Map2DStorage();
    ~Map2DStorage();
    bool open(yarp::os::Searchable& params) override;
    bool close() override;

public:
    //IMap2D methods
    bool clearAllMaps() override;
    bool store_map(const yarp::dev::Nav2D::MapGrid2D & map) override;
    bool get_map(std::string map_name, yarp::dev::Nav2D::MapGrid2D & map) override;
    bool get_map_names(std::vector<std::string> & map_names) override;
    bool remove_map(std::string map_name) override;
    bool storeLocation(std::string location_name, yarp::dev::Nav2D::Map2DLocation loc) override;
    bool storeArea(std::string area_name, yarp::dev::Nav2D::Map2DArea area) override;
    bool storePath(std::string path_name, yarp::dev::Nav2D::Map2DPath path) override;
    bool getLocation(std::string location_name, yarp::dev::Nav2D::Map2DLocation & loc) override;
    bool getArea(std::string area_name, yarp::dev::Nav2D::Map2DArea & area) override;
    bool getPath(std::string path_name, yarp::dev::Nav2D::Map2DPath & path) override;
    bool getLocationsList(std::vector<std::string> & locations) override;
    bool getAreasList(std::vector<std::string> & areas) override;
    bool getPathsList(std::vector<std::string> & paths) override;
    bool getAllLocations(std::vector<yarp::dev::Nav2D::Map2DLocation>& locations) override;
    bool getAllAreas(std::vector<yarp::dev::Nav2D::Map2DArea>& areas) override;
    bool getAllPaths(std::vector<yarp::dev::Nav2D::Map2DPath>& paths) override;
    bool renameLocation(std::string original_name, std::string new_name) override;
    bool deleteLocation(std::string location_name) override;
    bool deletePath(std::string path_name) override;
    bool renameArea(std::string original_name, std::string new_name) override;
    bool renamePath(std::string original_name, std::string new_name) override;
    bool deleteArea(std::string area_name) override;
    bool clearAllLocations() override;
    bool clearAllAreas() override;
    bool clearAllPaths() override;
    bool clearAllMapsTemporaryFlags() override;
    bool clearMapTemporaryFlags(std::string map_name) override;
    bool saveMapToDisk(std::string map_name, std::string file_name) override;
    bool loadMapFromDisk(std::string file_name) override;
    bool saveMapsCollection(std::string maps_collection_file) override;
    bool loadMapsCollection(std::string maps_collection_file) override;
    bool loadLocationsAndExtras(std::string locations_file) override;
    bool saveLocationsAndExtras(std::string locations_file) override;
    bool enableMapsCompression(bool enable) override;

private:
    bool priv_load_locations_and_areas_v1(std::ifstream& file);
    bool priv_load_locations_and_areas_v2(std::ifstream& file);
    bool priv_load_locations_and_areas_v3(std::ifstream& file);

private:
    yarp::os::ResourceFinder     m_rf_mapCollection;
    std::mutex                   m_mutex;
    yarp::os::RpcServer          m_rpcPort;

    bool read(yarp::os::ConnectionReader& connection) override;
};

#endif // YARP_DEV_MAP2DSTORAGE_H
