/*
 * Copyright (C) 2006-2021 Istituto Italiano di Tecnologia (IIT)
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include "FrameTransformStorage.h"
#include <yarp/os/Log.h>
#include <yarp/os/LogComponent.h>
#include <yarp/os/LogStream.h>

using namespace std;
using namespace yarp::dev;
using namespace yarp::os;
using namespace yarp::sig;
using namespace yarp::math;

namespace {
YARP_LOG_COMPONENT(FRAMETRANSFORSTORAGE, "yarp.device.frameTransformStorage")
}

//------------------------------------------------------------------------------------------------------------------------------

bool FrameTransformStorage::open(yarp::os::Searchable& config)
{
    return true;
}

bool FrameTransformStorage::close()
{
    return true;
}

bool FrameTransformStorage::getTransforms(std::vector<yarp::math::FrameTransform>& transforms) const
{
    std::lock_guard<std::mutex> lock(m_trf_mutex);
    transforms = m_transforms;
    return true;
}

bool FrameTransformStorage::setTransforms(const std::vector<yarp::math::FrameTransform>& transforms)
{
    for (auto& it : transforms)
    {
        setTransform(it);
    }
    return true;
}

bool FrameTransformStorage::setTransform(const yarp::math::FrameTransform& t)
{
    std::lock_guard<std::mutex> lock(m_trf_mutex);
    for (auto& it : m_transforms)
    {
        //this linear search may require some optimization
        if (it.dst_frame_id == t.dst_frame_id && it.src_frame_id == t.src_frame_id)
        {
            //transform already exists, update it
            it = t;
            return true;
        }
    }

    //add a new transform
    m_transforms.push_back(t);
    return true;
}

bool FrameTransformStorage::delete_transform(string t1, string t2)
{
    std::lock_guard<std::mutex> lock(m_trf_mutex);
    if (t1 == "*" && t2 == "*")
    {
        m_transforms.clear();
        return true;
    }
    else
    {
        if (t1 == "*")
        {
            for (size_t i = 0; i < m_transforms.size(); )
            {
                //source frame is jolly, thus delete all frames with destination == t2
                if (m_transforms[i].dst_frame_id == t2)
                {
                    m_transforms.erase(m_transforms.begin() + i);
                    i = 0; //the erase operation invalidates the iteration, loop restart is required
                }
                else
                {
                    i++;
                }
            }
            return true;
        }
        else
        {
            if (t2 == "*")
            {
                for (size_t i = 0; i < m_transforms.size(); )
                {
                    //destination frame is jolly, thus delete all frames with source == t1
                    if (m_transforms[i].src_frame_id == t1)
                    {
                        m_transforms.erase(m_transforms.begin() + i);
                        i = 0; //the erase operation invalidates the iteration, loop restart is required
                    }
                    else
                    {
                        i++;
                    }
                }
                return true;
            }
            else
            {
                for (size_t i = 0; i < m_transforms.size(); i++)
                {
                    if ((m_transforms[i].dst_frame_id == t1 && m_transforms[i].src_frame_id == t2) ||
                        (m_transforms[i].dst_frame_id == t2 && m_transforms[i].src_frame_id == t1))
                    {
                        m_transforms.erase(m_transforms.begin() + i);
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

void FrameTransformStorage::run()
{
    std::lock_guard <std::mutex> lg(m_pd_mutex);
    for (size_t i = 0; i < iGetIf.size(); i++)
    {
        std::vector<yarp::math::FrameTransform> tfs;
        bool b=iGetIf[i]->getTransforms(tfs);
        if (b) this->setTransforms(tfs);
    }
}

bool FrameTransformStorage::detachAll()
{
    std::lock_guard <std::mutex> lg(m_pd_mutex);
    iGetIf.clear();
}

bool FrameTransformStorage::attachAll(const yarp::dev::PolyDriverList& device2attach)
{
    std::lock_guard <std::mutex> lg(m_pd_mutex);
    pDriverList = device2attach;

    for (size_t i = 0; i < pDriverList.size(); i++)
    {
        yarp::dev::PolyDriver* pd = pDriverList[i]->poly;
        if (pd->isValid())
        {
            IFrameTransformStorageGet* pp=nullptr;
            if (pd->view(pp) && pp!=nullptr)
            {
                iGetIf.push_back(pp);
            }
        }
    }
    return true;
}

bool FrameTransformStorage::clear()
{
    std::lock_guard<std::mutex> lock(m_trf_mutex);
    m_transforms.clear();
    return true;
}

bool FrameTransformStorage::size(size_t& size) const
{
    std::lock_guard<std::mutex> lock(m_trf_mutex);
    size = m_transforms.size();
    return true;
}

/*
bool FrameTransformStorage::delete_transform(int id)
{
    std::lock_guard<std::mutex> lock(m_mutex);
    if (id >= 0 && (size_t)id < m_transforms.size())
    {
        m_transforms.erase(m_transforms.begin() + id);
        return true;
    }
    return false;
}


yarp::math::FrameTransform& operator[]   (std::size_t idx)
{
    return m_transforms[idx];
}
*/
