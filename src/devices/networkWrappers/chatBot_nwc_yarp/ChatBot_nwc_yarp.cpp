/*
 * SPDX-FileCopyrightText: 2023-2023 Istituto Italiano di Tecnologia (IIT)
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "ChatBot_nwc_yarp.h"
#include <yarp/os/Log.h>
#include <yarp/os/LogComponent.h>
#include <yarp/os/LogStream.h>

namespace
{
    YARP_LOG_COMPONENT(CHATBOT_NWC_YARP, "yarp.device.chatBot_nwc_yarp")
}

bool ChatBot_nwc_yarp::open(yarp::os::Searchable &config)
{
    if (!parseParams(config)) { return false; }

    if (!m_thriftClientPort.open(m_local))
    {
        yCError(CHATBOT_NWC_YARP) << "Cannot open rpc port, check network";

        return false;
    }

    bool ok = false;

    ok = yarp::os::Network::connect(m_local, m_remote);

    if (!ok)
    {
        yCError(CHATBOT_NWC_YARP) << "open() error could not connect to" << m_remote;
        return false;
    }

    if (!m_thriftClient.yarp().attachAsClient(m_thriftClientPort))
    {
        yCError(CHATBOT_NWC_YARP) << "Cannot attach the m_thriftClientPort port as client";
        return false;
    }

    yCDebug(CHATBOT_NWC_YARP) << "Opening of nwc successful";
    return true;
}

bool ChatBot_nwc_yarp::close()
{
    m_thriftClientPort.close();
    return true;
}

bool ChatBot_nwc_yarp::interact(const std::string& messageIn, std::string& messageOut)
{
    return_interact output = m_thriftClient.interactRPC(messageIn);
    if(!output.result)
    {
        yCError(CHATBOT_NWC_YARP) << "Could not interact with the chatbot";
        return false;
    }

    messageOut = output.messageOut;
    return true;
}

bool ChatBot_nwc_yarp::setLanguage(const std::string& language)
{
    if(!m_thriftClient.setLanguageRPC(language))
    {
        yCError(CHATBOT_NWC_YARP) << "Could not set the chatbot language to" << language;
        return false;
    }
    return true;
}

bool ChatBot_nwc_yarp::getLanguage(std::string& language)
{
    return_getLanguage output = m_thriftClient.getLanguageRPC();
    if(!output.result)
    {
        yCError(CHATBOT_NWC_YARP) << "Could not retrieve the currently set language";
        return false;
    }
    language = output.language;
    return true;
}

bool ChatBot_nwc_yarp::getStatus(std::string& status)
{
    return_getStatus output = m_thriftClient.getStatusRPC();
    if(!output.result)
    {
        yCError(CHATBOT_NWC_YARP) << "Could not retrieve the current bot status";
        return false;
    }
    status = output.status;
    return true;
}

bool ChatBot_nwc_yarp::resetBot()
{
    if(!m_thriftClient.resetBotRPC())
    {
        yCError(CHATBOT_NWC_YARP) << "Could not reset the chatbot";
        return false;
    }
    return true;
}
