
#ifndef electron_browser_api_MessageFilterWrap_h
#define electron_browser_api_MessageFilterWrap_h

#include "ipc_lite/ipc_channel_proxy.h"

namespace atom {

class MessageFilterInterface {
public:
    virtual bool onMessageReceived(const IPC::Message& message) = 0;
    virtual void onChannelConnected(int32 peerPid) = 0;
    virtual void onChannelError() = 0;
    virtual void onChannelClosing() = 0;
};

class MessageFilterWrap : public IPC::ChannelProxy::MessageFilter {
public:
    MessageFilterWrap(MessageFilterInterface* intelface)
    {
        m_intelface = intelface;
    }
    bool OnMessageReceived(const IPC::Message& message) override
    {
        return m_intelface->onMessageReceived(message);
    }
    void OnChannelConnected(int32 peerPid) override
    {
        m_intelface->onChannelConnected(peerPid);
    }
    void OnChannelError() override
    {
        m_intelface->onChannelError();
    }
    void OnChannelClosing() override
    {
        m_intelface->onChannelClosing();
    }

    MessageFilterInterface* m_intelface;
};

}

#endif // electron_browser_api_MessageFilterWrap_h