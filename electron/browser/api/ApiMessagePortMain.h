
#ifndef electron_browser_api_ApiMessagePortMain_h
#define electron_browser_api_ApiMessagePortMain_h

#include "electron/common/gin_helper/wrappable.h"
#include "electron/common/api/EventEmitter.h"
#include "third_party/blink/public/common/messaging/message_port_channel.h"
#include "third_party/blink/public/common/messaging/message_port_descriptor.h"
#include "mojo/public/cpp/bindings/message.h"
#include "mojo/public/cpp/bindings/connector.h"
#include "gin/handle.h"
#include "base/timer/timer.h"

namespace node {
class Environment;
}

namespace mojo {
class Connector;
}

namespace atom {

class ApiMessagePortMain : public mate::EventEmitter<ApiMessagePortMain>, mojo::MessageReceiver {
public:
    static void init(v8::Isolate* isolate, v8::Local<v8::Object> target, node::Environment* env);
    static ApiMessagePortMain* create(v8::Isolate* isolate);

    void postMessageApi(const v8::FunctionCallbackInfo<v8::Value>& info);
    void startApi();
    void closeApi();

    void entangle(blink::MessagePortDescriptor port);
    void entangle(blink::MessagePortChannel channel);

    blink::MessagePortChannel disentangle();

    bool isEntangled() const
    {
        return !m_closed && !isNeutered();
    }
    bool isNeutered() const
    {
        return !m_connector || !m_connector->is_valid();
    }

    static std::vector<ApiMessagePortMain*> entanglePorts(v8::Isolate* isolate, std::vector<blink::MessagePortChannel> channels);

    static std::vector<blink::MessagePortChannel> disentanglePorts(v8::Isolate* isolate, const std::vector<ApiMessagePortMain*>& ports, bool* threw_exception);

    explicit ApiMessagePortMain(v8::Isolate* isolate, v8::Local<v8::Object> wrapper);
    ~ApiMessagePortMain();

    static void newFunction(const v8::FunctionCallbackInfo<v8::Value>& args);

public:
    static gin_helper::WrapperInfo kWrapperInfo;

private:
    // The blink version of MessagePort uses the very nice "ActiveScriptWrapper"
    // class, which keeps the object alive through the V8 embedder hooks into the
    // GC lifecycle: see
    // https://source.chromium.org/chromium/chromium/src/+/main:third_party/blink/renderer/platform/heap/thread_state.cc;l=258;drc=b892cf58e162a8f66cd76d7472f129fe0fb6a7d1
    // We do not have that luxury, so we brutishly use v8::Global to accomplish
    // something similar. Critically, whenever the value of
    // "HasPendingActivity()" changes, we must call Pin() or Unpin() as
    // appropriate.
    bool hasPendingActivity() const;
    void pin();
    void unpin();
    void delayPinOrUnpin();

    // mojo::MessageReceiver
    bool Accept(mojo::Message* mojo_message) override;

    std::unique_ptr<mojo::Connector> m_connector;
    bool m_started = false;
    bool m_closed = false;

    v8::Global<v8::Value> m_pinned;

    // The internal port owned by this class. The handle itself is moved into the
    // |connector_| while entangled.
    blink::MessagePortDescriptor m_port;

    base::OneShotTimer m_delayPinOrUnpin;

    base::WeakPtrFactory<ApiMessagePortMain> m_weakFactory { this };
};

} // namespace atom

#endif // electron_browser_api_ApiMessagePortMain_h