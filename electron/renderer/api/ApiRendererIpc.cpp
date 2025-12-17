
#include "electron/nodeblink.h"
#include "mbvip/core/mb.h"
#include "electron/renderer/WebviewPluginImpl.h"
#include "electron/browser/api/ApiWebContents.h"
#include "electron/common/NodeRegisterHelp.h"
#include "electron/common/api/EventEmitter.h"
#include "electron/common/NodeRegisterHelp.h"
#include "electron/common/gin_helper/wrappable.h"
#include "electron/common/gin_helper/object_template_builder.h"
#include "electron/common/gin_helper/dictionary.h"
#include "electron/common/gin_helper/public/gin_embedders.h"
#include "electron/common/gin_helper/public/wrapper_info.h"
#include "electron/common/V8Util.h"
#include "third_party/libnode/src/node.h"
#include "third_party/libnode/src/node_binding.h"
#include "third_party/libnode/src/node_version.h"
#include "third_party/libuv/include/uv.h"
#include "third_party/blink/public/common/messaging/cloneable_message.h"
#include "base/values.h"
#include <xstring>

namespace content {
void printCallstack();
}

namespace atom {

class IpcRenderer : public mate::EventEmitter<IpcRenderer> {
public:
    explicit IpcRenderer(v8::Isolate* isolate, v8::Local<v8::Object> wrapper)
    {
        gin_helper::Wrappable<IpcRenderer>::InitWith(isolate, wrapper);
    }

    static void init(v8::Local<v8::Object> target, v8::Isolate* isolate)
    {
        v8::Local<v8::Context> context = isolate->GetCurrentContext();
        v8::Local<v8::FunctionTemplate> prototype = v8::FunctionTemplate::New(isolate, IpcRenderer::newFunction);

        prototype->SetClassName(v8::String::NewFromUtf8(isolate, "IpcRenderer").ToLocalChecked());
        gin_helper::ObjectTemplateBuilder builder(isolate, prototype->InstanceTemplate());
        builder.SetMethod("send", &IpcRenderer::rendererIpcSend);
        builder.SetMethod("sendSync", &IpcRenderer::rendererIpcSendSync);

        constructor.Reset(isolate, prototype->GetFunction(context).ToLocalChecked());
        target->Set(context, v8::String::NewFromUtf8(isolate, "ipcRenderer").ToLocalChecked(), prototype->GetFunction(context).ToLocalChecked());
    }

    // 这个channel和js里event.channel不是一个东西
    void rendererIpcSend(
        const v8::FunctionCallbackInfo<v8::Value>& info
        //const std::string& channel, std::unique_ptr<std::vector<blink::CloneableMessage>> arguments
    )
    {
        gin_helper::Arguments arg(info);
        std::string channel;
        if (!arg.GetNext(&channel)) {
            arg.ThrowError();
            return;
        }

        std::vector<blink::CloneableMessage>* args = new std::vector<blink::CloneableMessage>();
        if (!arg.GetRemaining(args)) {
            delete args;
            arg.ThrowError();
            return;
        }

        if ("ipc-message-host" == channel) {
            sendToHost(std::unique_ptr<std::vector<blink::CloneableMessage>>(args));
            return;
        }

        mbWebView view = mbGetWebViewForCurrentContext();
        if (!view)
            return;
        WebContents* webContents = (WebContents*)mbGetUserKeyValue(view, "WebContents");
        if (!webContents)
            return;

        mbWebFrameHandle frame = mbGetWebFrameForCurrentContext();
        if (0 == frame)
            return;

        webContents->rendererPostMessageToMain(frame, channel, std::unique_ptr<std::vector<blink::CloneableMessage>>(args));
    }

    v8::Local<v8::Value> rendererIpcSendSync(
        //const std::string& channel, std::unique_ptr<std::vector<blink::CloneableMessage>> arguments
        const v8::FunctionCallbackInfo<v8::Value>& info
        )
    {
        gin_helper::Arguments arg(info);
        std::string channel;
        if (!arg.GetNext(&channel)) {
            arg.ThrowError();
            return v8::Local<v8::Value>();
        }

        std::vector<blink::CloneableMessage>* args = new std::vector<blink::CloneableMessage>();
        if (!arg.GetRemaining(args)) {
            delete args;
            arg.ThrowError();
            return v8::Local<v8::Value>();
        }

        mbWebView view = mbGetWebViewForCurrentContext();
        if (!view)
            return v8::Undefined(isolate());
        WebContents* webContents = (WebContents*)mbGetUserKeyValue(view, "WebContents");
        if (!webContents)
            return v8::Undefined(isolate());

        mbWebFrameHandle frame = mbGetWebFrameForCurrentContext();
        if (0 == frame)
            return v8::Undefined(isolate());

        std::vector<uint8_t> encodedMessage;
        webContents->rendererSendMessageToMain(frame, channel, std::unique_ptr<std::vector<blink::CloneableMessage>>(args), &encodedMessage);

        if (0 == encodedMessage.size())
            return v8::Undefined(isolate());

        base::span<const uint8_t> data((const uint8_t*)(encodedMessage.data()), encodedMessage.size());
        return deserializeV8Value(isolate(), data);
    }

    void sendToHost(std::unique_ptr<std::vector<blink::CloneableMessage>> arguments)
    {
        DebugBreak();
//         if (arguments->empty())
//             return;
// 
//         const base::Value& arg0 = arguments->at(0);
//         if (!arg0.is_string())
//             return;
//         const std::string* evtChannel = arg0.GetIfString();
//         if (!evtChannel || evtChannel->empty())
//             return;
// 
//         mbWebView view = mbGetWebViewForCurrentContext();
//         if (!view)
//             return;
//         WebviewPluginImpl* pluginHost = (WebviewPluginImpl*)mbGetUserKeyValue(view, "WebviewPluginImpl");
//         if (!pluginHost)
//             return;
// 
//         std::string json;
//         pluginHost->guestSendMessageToHost(*evtChannel, arguments);
    }

    static void newFunction(const v8::FunctionCallbackInfo<v8::Value>& args)
    {
        v8::Isolate* isolate = args.GetIsolate();
        new IpcRenderer(isolate, args.This());

        if (args.IsConstructCall()) {
            args.GetReturnValue().Set(args.This());
            return;
        }
    }

public:
    static gin_helper::WrapperInfo kWrapperInfo;
    static v8::Persistent<v8::Function> constructor;
};

v8::Persistent<v8::Function> IpcRenderer::constructor;
gin_helper::WrapperInfo IpcRenderer::kWrapperInfo = { gin_helper::GinEmbedder::kEmbedderNativeGin };

static void initializeRendererIpcApi(v8::Local<v8::Object> target, v8::Local<v8::Value> unused, v8::Local<v8::Context> context, const NodeNative* native)
{
    IpcRenderer::init(target, context->GetIsolate());
}

static const char RendererIpcNative[] = "exports = {};";

static NodeNative nativeRendererIpcNative { "ipc-renderer", RendererIpcNative, sizeof(RendererIpcNative) - 1 };

NODE_MODULE_CONTEXT_AWARE_BUILTIN_SCRIPT_MANUAL(electron_renderer_ipc, initializeRendererIpcApi, &nativeRendererIpcNative)

}