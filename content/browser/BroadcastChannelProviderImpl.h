
#ifndef content_browser_BroadcastChannelProviderImpl_h
#define content_browser_BroadcastChannelProviderImpl_h

#include "third_party/blink/public/mojom/broadcastchannel/broadcast_channel.mojom-blink.h"
#include "content/common/common.h"

namespace content {

class WebLocalFrameClientImpl;

class BroadcastChannelProviderImpl : public ::blink::mojom::blink::BroadcastChannelProvider {
public:
    BroadcastChannelProviderImpl(WebLocalFrameClientImpl* frameClient);
    ~BroadcastChannelProviderImpl();

    void ConnectToChannel(const WTF::String& name, ::mojo::PendingAssociatedRemote<::blink::mojom::blink::BroadcastChannelClient> client,
        ::mojo::PendingAssociatedReceiver<::blink::mojom::blink::BroadcastChannelClient> connection) override;

private:
    WebLocalFrameClientImpl* m_frameClient = nullptr;
};

}

#endif // content_browser_BroadcastChannelProviderImpl_h
