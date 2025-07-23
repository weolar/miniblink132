
#include "electron/browser/api/PostMessageUtil.h"

#include "electron/browser/api/ApiMessagePortMain.h"
#include "electron/common/V8Util.h"
#include "third_party/blink/public/common/messaging/cloneable_message.h"
#include "third_party/blink/public/common/messaging/message_port_descriptor.h"
#include "third_party/blink/public/common/messaging/transferable_message.h"
#include "third_party/blink/public/common/messaging/transferable_message_mojom_traits.h"
#include "third_party/blink/public/mojom/messaging/transferable_message.mojom-blink.h"
#include "third_party/blink/renderer/core/execution_context/execution_context.h"
#include "third_party/blink/renderer/core/messaging/message_port.h"
#include "third_party/blink/renderer/platform/bindings/script_state.h"
#include "electron/common/gin_helper/data_object_builder.h"
#include "electron/common/gin_helper/public/wrapper_info.h"
#include "electron/common/gin_helper/public/gin_embedders.h"
#include <windows.h>

namespace content {
void printCallstack();
}

namespace gin_helper {

template <> struct Converter<blink::MessagePortArray> {
    static v8::Local<v8::Value> ToV8(v8::Isolate* isolate, const blink::MessagePortArray& val)
    {
        std::vector<v8::Local<v8::Value> > elements;
        blink::ScriptState* scriptState = blink::ScriptState::From(isolate, isolate->GetCurrentContext());
        for (size_t i = 0; i < val.size(); ++i) {
            blink::MessagePort* port = val[i].Get();
            v8::Local<v8::Value> element = port->ToV8(scriptState);
            elements.push_back(element);
        }

        return v8::Array::New(isolate, elements.data(), elements.size());
    }
    //static bool FromV8(v8::Isolate* isolate, v8::Local<v8::Value> val, blink::MessagePortArray* out);
};

} // gin_helper

namespace atom {

bool isValidWrappable(const v8::Local<v8::Value>& val)
{
    if (!val->IsObject())
        return false;

    v8::Local<v8::Object> port = val.As<v8::Object>();
    int count = port->InternalFieldCount();
    if (count != gin_helper::InternalFields::kNumberOfInternalFields)
        return false;

    const auto* info = static_cast<gin_helper::WrapperInfo*>(port->GetAlignedPointerFromInternalField(gin_helper::InternalFields::kWrapperInfoIndex));

    return info && info->embedder == gin_helper::GinEmbedder::kEmbedderNativeGin;
}

// utiltyProcess的postMessage参数是2个：child.postMessage({message: 'hello'}, [port1]);
// 而webcontents.postMessage(channel, message, [transfer]); 参数是两个或者三个
bool v8FunInfoToMojoMessage(const v8::FunctionCallbackInfo<v8::Value>& info, mojo::Message* mojoMessage, std::string* channel)
{
    v8::Isolate* isolate = info.GetIsolate();
    if (info.Length() <= 0 || (channel && info.Length() < 2)) {
        isolate->ThrowException(gin_helper::StringToV8(isolate, "args num is error"));
        return false;
    }  

    if (channel && !gin_helper::Converter<std::string>::FromV8(isolate, info[0], channel)) {
        isolate->ThrowException(gin_helper::StringToV8(isolate, "channel must be set"));
        return false;
    }

    blink::TransferableMessage transferableMsg;
    if (!serializeV8Value(info.GetIsolate(), info[channel ? 1 : 0], &transferableMsg)) // SerializeV8Value sets an exception.
        return false;

    std::vector<ApiMessagePortMain*> wrappedPorts;
    if (info.Length() == (channel ? 3 : 2)) {
        v8::Local<v8::Value> transferables = info[channel ? 2 : 1];
        std::vector<v8::Local<v8::Value>> wrappedPortValues;
        if (!gin_helper::ConvertFromV8(isolate, transferables, &wrappedPortValues)) {
            isolate->ThrowException(gin_helper::StringToV8(isolate, "transferables must be an array of MessagePorts"));
            return false;
        }

        for (size_t i = 0; i < wrappedPortValues.size(); ++i) {
            if (!isValidWrappable(wrappedPortValues[i])) {
                std::string temp = "Port at index " + base::NumberToString(i) + " is not a valid port";
                isolate->ThrowException(gin_helper::StringToV8(isolate, temp));
                return false;
            }
        }

        if (!gin_helper::ConvertFromV8(isolate, transferables, &wrappedPorts)) {
            isolate->ThrowException(gin_helper::StringToV8(isolate, "Passed an invalid MessagePort"));
            return false;
        }

        bool threwException = false;
        transferableMsg.ports = ApiMessagePortMain::disentanglePorts(isolate, wrappedPorts, &threwException);
        if (threwException)
            return false;
    }

    *mojoMessage = blink::mojom::blink::TransferableMessage::WrapAsMessage(std::move(transferableMsg));
    return true;
}

bool postMessageHelper(mojo::Connector* connector, const v8::FunctionCallbackInfo<v8::Value>& info)
{
    mojo::Message mojoMessage;
    if (!v8FunInfoToMojoMessage(info, &mojoMessage, nullptr))
        return false;
    bool b = connector->Accept(&mojoMessage);
    b ? OutputDebugStringA("postMessageHelper ok\n") : OutputDebugStringA("postMessageHelper fail\n");
    return true;
}

// 可以看出，主进程和子进程的on收到的message的格式稍微有点不同。子进程收到的消息是在e.data里
// //Main process
// const child = utilityProcess.fork(path.join(__dirname, 'test.js'));
// child.postMessage({ message: 'hello' });
// child.on('message', (data) = > {
//     console.log(data); // hello world!
// });
// 
// //Child process
// process.parentPort.on('message', (e) = > {
//     process.parentPort.postMessage(`${e.data} world!`);
// });

bool onChannelMessagingApiAcceptHelper(
    bool inBlinkThread,
    const std::string& channel,
    v8::Local<v8::Object> wrap,
    mojo::Message* mojoMessage)
{
    // v8::Isolate* isolate = JavascriptEnvironment::GetIsolate();
    v8::Isolate* isolate = v8::Isolate::GetCurrent();
    v8::HandleScope handleScope(isolate);
    blink::TransferableMessage message;
    if (!blink::mojom::blink::TransferableMessage::DeserializeFromMessage(std::move(*mojoMessage), &message)) {
        isolate->ThrowException(gin_helper::StringToV8(isolate, "Passed an invalid TransferableMessage"));
        return false;
    }

    v8::Local<v8::Context> context = isolate->GetCurrentContext();
    if (context.IsEmpty()) {
        v8::MaybeLocal<v8::Context> maybeContext = wrap->GetCreationContext(isolate);
        if (maybeContext.IsEmpty()) {
            isolate->ThrowException(gin_helper::StringToV8(isolate, "Context is invalid"));
            return false;
        }
        context = maybeContext.ToLocalChecked();
    }
    if (context.IsEmpty()) {
        isolate->ThrowException(gin_helper::StringToV8(isolate, "Context is empty"));
        return false;
    }

    v8::Context::Scope scope(context);
    v8::Local<v8::Value> messageValue = deserializeV8Value(context, message.encoded_message);

    // 接受的参数形式有这两种：
    // 1) ipcRenderer.on('port', (e, args) => {}); // channel可以是任意字符串，比如'port'，args里放用户传的其他数据
    // 2) port2.on('message', (event) => { // channel必须叫'message'，event.data里放用户传的其他数据
    //    console.log('from renderer main world:', event.data);
    // });
    if (inBlinkThread) {
        WTF::Vector<blink::MessagePortChannel> channels;
        blink::ExecutionContext* blinkContext = blink::ExecutionContext::From(context);
        if (!blinkContext) {
            isolate->ThrowException(gin_helper::StringToV8(isolate, "blinkContext is empty"));
            return false;
        }
        for (size_t i = 0; i < message.ports.size(); ++i) {
            channels.push_back(message.ports[i]);
        }
        blink::MessagePortArray* blinkMessagePortArray = blink::MessagePort::EntanglePorts(*blinkContext, channels);

        // v8::Local<v8::Object> evt2 = gin_helper::DataObjectBuilder(isolate).Set("ports", std::move(*blinkMessagePortArray)).Build();
        v8::Local<v8::Object> evt2 = v8::Object::New(isolate);

        v8::Local<v8::String> v8Key = gin_helper::StringToSymbol(isolate, "ports");
        v8::Local<v8::Value> v8Value = gin_helper::Converter<blink::MessagePortArray>::ToV8(isolate, *blinkMessagePortArray);
        CHECK(evt2->CreateDataProperty(context, v8Key, v8Value).ToChecked());

        mate::emitEvent(isolate, wrap, channel, evt2, messageValue);
    } else {
        std::vector<ApiMessagePortMain*> wrappedPorts = ApiMessagePortMain::entanglePorts(isolate, std::move(message.ports));

        CHECK(channel == "message");
        v8::Local<v8::Object> evt1 = gin_helper::DataObjectBuilder(isolate)
            .Set("ports", wrappedPorts)
            .Set("data", messageValue)
            .Build();
        mate::emitEvent(isolate, wrap, channel, evt1);
    }

    return true;
}

// bool onChannelMessagingApiAcceptHelper(
//     bool argsIsInDataField,
//     const std::string& channel,
//     v8::Local<v8::Object> wrap, 
//     mojo::Message* mojoMessage)
// {
//     // v8::Isolate* isolate = JavascriptEnvironment::GetIsolate();
//     v8::Isolate* isolate = v8::Isolate::GetCurrent();
//     v8::HandleScope handleScope(isolate);
//     blink::TransferableMessage message;
//     if (!blink::mojom::blink::TransferableMessage::DeserializeFromMessage(std::move(*mojoMessage), &message)) {
//         isolate->ThrowException(gin_helper::StringToV8(isolate, "Passed an invalid TransferableMessage"));
//         return false;
//     }
// 
//     v8::Local<v8::Context> context = isolate->GetCurrentContext();
//     if (context.IsEmpty()) {
//         v8::MaybeLocal<v8::Context> maybeContext = wrap->GetCreationContext(isolate);
//         if (maybeContext.IsEmpty()) {
//             isolate->ThrowException(gin_helper::StringToV8(isolate, "Context is invalid"));
//             return false;
//         }
//         context = maybeContext.ToLocalChecked();
//     }
//     if (context.IsEmpty()) {
//         isolate->ThrowException(gin_helper::StringToV8(isolate, "Context is empty"));
//         return false;
//     }
// 
//     v8::Context::Scope scope(context);
//     v8::Local<v8::Value> messageValue = deserializeV8Value(context, message.encoded_message);
// 
//     std::vector<ApiMessagePortMain*> wrappedPorts = ApiMessagePortMain::entanglePorts(isolate, std::move(message.ports));
// 
//     // 接受的参数形式有这两种：
//     // 1) ipcRenderer.on('port', (e, args) => {}); // channel可以是任意字符串，比如'port'，args里放用户传的其他数据
//     // 2) port2.on('message', (event) => { // channel必须叫'message'，event.data里放用户传的其他数据
//     //    console.log('from renderer main world:', event.data);
//     // });
// 
//     v8::Local<v8::Object> evt = gin_helper::DataObjectBuilder(isolate)
//         .Set("data", messageValue)
//         .Set("ports", wrappedPorts)
//         .Build();
//     if (!argsIsInDataField) {
//         mate::emitEvent(isolate, wrap, /*"message"*/channel, evt, messageValue);
//     } else {
//         mate::emitEvent(isolate, wrap, /*"message"*/channel, evt);
//     }
// 
//     return true;
// }

bool onApiUtilityProcessAcceptHelper(v8::Local<v8::Object> wrap, mojo::Message* mojoMessage)
{
    blink::TransferableMessage message;
    if (!blink::mojom::blink::TransferableMessage::DeserializeFromMessage(std::move(*mojoMessage), &message))
        return false;

    v8::Isolate* isolate = v8::Isolate::GetCurrent();
    v8::HandleScope handleScope(isolate);
    v8::Local<v8::Value> messageValue = deserializeV8Value(isolate, message.encoded_message);
    mate::emitEvent(isolate, wrap, "message", messageValue);

    return true;
}


}