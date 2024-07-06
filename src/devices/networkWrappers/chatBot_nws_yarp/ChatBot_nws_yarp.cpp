/*
 * SPDX-FileCopyrightText: 2023-2023 Istituto Italiano di Tecnologia (IIT)
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "ChatBot_nws_yarp.h"

#include <yarp/os/LogComponent.h>
#include <yarp/os/LogStream.h>
#include <yarp/os/Os.h>

namespace {
YARP_LOG_COMPONENT(CHATBOT_NWS_YARP, "yarp.devices.chatBot_nws_yarp")
}

ChatBot_nws_yarp::~ChatBot_nws_yarp()
{
    closeMain();
}

bool ChatBot_nws_yarp::close()
{
    return closeMain();
}

bool ChatBot_nws_yarp::open(Searchable& config)
{
    if (!parseParams(config)) { return false; }

    m_inputBuffer.attach(m_inputPort);
    if(!m_inputPort.open(m_name+"/text:i"))
    {
        yCError(CHATBOT_NWS_YARP) << "Could not open port" << m_name +"/text:i";
        return false;
    }
    if(!m_outputPort.open(m_name + "/text:o"))
    {
        yCError(CHATBOT_NWS_YARP) << "Could not open port" << m_name +"/text:o";
        return false;
    }
    if (!m_thriftServerPort.open(m_name +"/rpc"))
    {
        yCError(CHATBOT_NWS_YARP, "Failed to open rpc port");
        return false;
    }
    m_thriftServerPort.setReader(*this);

    yCInfo(CHATBOT_NWS_YARP, "Device waiting for attach...");
    return true;
}

bool  ChatBot_nws_yarp::attach(yarp::dev::PolyDriver* deviceToAttach)
{
    if (deviceToAttach->isValid())
    {
        deviceToAttach->view(m_iChatBot);
    }

    if (nullptr == m_iChatBot)
    {
        yCError(CHATBOT_NWS_YARP, "Subdevice passed to attach method is invalid");
        return false;
    }

    yCInfo(CHATBOT_NWS_YARP, "Attach done");

    m_cbkHelper = new ChatBotRPC_CallbackHelper();
    if(!m_cbkHelper->setCommunications(m_iChatBot,&m_outputPort))
    {
        yCError(CHATBOT_NWS_YARP) << "Error setting ChatBot_CallbackHelper object interfaces";
        delete m_cbkHelper;
        m_cbkHelper=nullptr;
        return false;
    }
    m_inputBuffer.useCallback(*m_cbkHelper);
    if(!m_msgsImpl.setInterfaces(m_iChatBot))
    {
        yCError(CHATBOT_NWS_YARP) << "Error setting IChatBotMsgsImpl object interfaces";
        return false;
    }

    return true;
}

bool  ChatBot_nws_yarp::detach()
{
    m_iChatBot = nullptr;
    return true;
}

bool ChatBot_nws_yarp::closeMain()
{
    //close the port connection here
    m_inputBuffer.disableCallback();
    m_inputPort.close();
    m_outputPort.close();
    m_thriftServerPort.close();
    if (m_cbkHelper) {delete m_cbkHelper; m_cbkHelper=nullptr;}
    return true;
}

bool ChatBot_nws_yarp::read(yarp::os::ConnectionReader& connection)
{
    bool b = m_msgsImpl.read(connection);
    if (b)
    {
        return true;
    }
    else
    {
        yCError(CHATBOT_NWS_YARP, "read() Command failed");
        return false;
    }
}
