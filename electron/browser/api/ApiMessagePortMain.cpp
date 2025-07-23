
#include "electron/browser/api/ApiMessagePortMain.h"

#include "electron/browser/api/PostMessageUtil.h"
#include "electron/common/NodeRegisterHelp.h"
#include "electron/common/IdLiveDetect.h"
#include "electron/common/NodeBinding.h"
#include "electron/common/NodeThread.h"
#include "electron/common/AtomVersion.h"
#include "electron/common/V8Util.h"
#include "electron/common/api/GetConstructorFromTls.h"
#include "electron/common/api/EventEmitter.h"
#include "electron/common/api/EventEmitterCaller.h"
#include "electron/common/gin_helper/dictionary.h"
#include "electron/common/gin_helper/data_object_builder.h"
#include "electron/common/gin_helper/object_template_builder.h"
#include "electron/common/gin_helper/public/gin_embedders.h"
#include "electron/common/gin_helper/public/wrapper_info.h"
#include "electron/common/gin_helper/error_thrower.h"
#include "third_party/libnode/src/node_binding.h"
#include "base/strings/string_number_conversions.h"
#include "base/task/sequenced_task_runner.h"
#include "base/task/single_thread_task_runner.h"
#include "base/containers/contains.h"
#include "base/command_line.h"
#include <unordered_set>

namespace content {
void printCallstack();
}

// electron\shell\browser\api\electron_api_utility_process.cc
namespace atom {

// Main proces

gin_helper::WrapperInfo ApiMessagePortMain::kWrapperInfo = { gin_helper::GinEmbedder::kEmbedderNativeGin };
v8::Persistent<v8::Function> s_ApiMessagePortMainConstructor;
//DWORD s_ApiMessagePortMainConstructorTlsKey = 0;

static void initializeApiMessagePortMain(v8::Local<v8::Object> target, v8::Local<v8::Value> unused, v8::Local<v8::Context> context, const NodeNative* native)
{
    ApiMessagePortMain::init(context->GetIsolate(), target, nullptr);
}

static void createPair(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    v8::Isolate* isolate = info.GetIsolate();
    ApiMessagePortMain* port1 = ApiMessagePortMain::create(isolate);
    ApiMessagePortMain* port2 = ApiMessagePortMain::create(isolate);
    blink::MessagePortDescriptorPair pipe;
    port1->entangle(pipe.TakePort0());
    port2->entangle(pipe.TakePort1());

    v8::Local<v8::Value> ret = gin_helper::DataObjectBuilder(isolate).Set("port1", port1).Set("port2", port2).Build();
    info.GetReturnValue().Set(ret);
}

void ApiMessagePortMain::init(v8::Isolate* isolate, v8::Local<v8::Object> target, node::Environment* env)
{
//     v8::Persistent<v8::Function>* constructor = atom::V8PersistentTls::get(&s_ApiMessagePortMainConstructorTlsKey);
//     if (!(*constructor).IsEmpty())
//         return;
    CHECK(s_ApiMessagePortMainConstructor.IsEmpty());

    v8::Local<v8::Context> context = isolate->GetCurrentContext();
    v8::Local<v8::FunctionTemplate> prototype = v8::FunctionTemplate::New(isolate, ApiMessagePortMain::newFunction);
    gin_helper::ObjectTemplateBuilder builder(isolate, prototype->PrototypeTemplate());
    gin_helper::ObjectTemplateBuilder builder2(isolate, prototype->InstanceTemplate()); // 实例模板也要调用一下，才能设置实例的SetInternalFieldCount

    builder.SetMethod("postMessage", &ApiMessagePortMain::postMessageApi);
    builder.SetMethod("start", &ApiMessagePortMain::startApi);
    builder.SetMethod("close", &ApiMessagePortMain::closeApi);

    v8::Local<v8::Function> prototypFunc = prototype->GetFunction(context).ToLocalChecked();
    target->Set(context, v8::String::NewFromUtf8(isolate, "ApiMessagePortMain").ToLocalChecked(), prototypFunc);
    //constructor->Reset(isolate, prototypFunc);
    s_ApiMessagePortMainConstructor.Reset(isolate, prototypFunc);

    gin_helper::Dictionary dict(isolate, target);
    dict.SetMethod("createPair", &createPair);
}

void ApiMessagePortMain::newFunction(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    v8::Isolate* isolate = info.GetIsolate();
    v8::Local<v8::Context> context = isolate->GetCurrentContext();

    CHECK(info.IsConstructCall());
    if (info.Length() != 0)
        return;
    new ApiMessagePortMain(isolate, info.This()); // v8管理内存回收
    info.GetReturnValue().Set(info.This());
}

void ApiMessagePortMain::delayPinOrUnpin()
{
    if (hasPendingActivity())
        pin();
    else
        unpin();
}

ApiMessagePortMain::ApiMessagePortMain(v8::Isolate* isolate, v8::Local<v8::Object> wrapper)
{
    char output[100] = { 0 };
    sprintf_s(output, 99, "ApiMessagePortMain::ApiMessagePortMain: %p\n", this);
    OutputDebugStringA(output);

    gin_helper::Wrappable<ApiMessagePortMain>::InitWith(isolate, wrapper);

    // 这里和原版electron不一样。原版没有在这pin。之所有这里要pin一下，因为有时候会在创建了ApiMessagePortMain
    // 后，还没走到start就立马内存回收了。
    pin();
    m_delayPinOrUnpin.Start(FROM_HERE, base::Seconds(80000), base::BindOnce(&ApiMessagePortMain::delayPinOrUnpin, base::Unretained(this))); // TODO!!!!
}

ApiMessagePortMain::~ApiMessagePortMain()
{
    if (!isNeutered()) {
        // Disentangle before teardown. The MessagePortDescriptor will blow up if it
        // hasn't had its underlying handle returned to it before teardown.
        disentangle();
    }
}

ApiMessagePortMain* ApiMessagePortMain::create(v8::Isolate* isolate)
{
    v8::Local<v8::Context> context = isolate->GetCurrentContext();
    v8::Local<v8::Function> constructorFunction = v8::Local<v8::Function>::New(isolate, s_ApiMessagePortMainConstructor);
    //v8::Persistent<v8::Function>* constructor = atom::V8PersistentTls::get(&s_ApiMessagePortMainConstructorTlsKey);
    //if ((*constructor).IsEmpty()) { // 如果没设置，说明可能是渲染线程里
    //    v8::Local<v8::Object> dummuyTarget = v8::Object::New(isolate);
    //    ApiMessagePortMain::init(isolate, dummuyTarget, nullptr);
    //}
    //v8::Local<v8::Function> constructorFunction = v8::Local<v8::Function>::New(isolate, *constructor);
    
    v8::MaybeLocal<v8::Object> obj = constructorFunction->NewInstance(context, 0, nullptr); // call into ApiMessagePortMain::ApiMessagePortMain
    CHECK(!obj.IsEmpty());

    v8::Local<v8::Object> objV8 = obj.ToLocalChecked();
    ApiMessagePortMain* self = (ApiMessagePortMain*)WrappableBase::GetNativePtr(objV8, &kWrapperInfo);
    return self;
}

bool ApiMessagePortMain::Accept(class mojo::Message* mojoMessage)
{
    v8::Isolate* isolate = v8::Isolate::GetCurrent();
    v8::HandleScope scope(isolate);
    return onChannelMessagingApiAcceptHelper(false, "message", getWrapper(), mojoMessage);
}

void ApiMessagePortMain::postMessageApi(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    mojo::Message* mojoMessage = new mojo::Message;
    if (!v8FunInfoToMojoMessage(info, mojoMessage, nullptr)) {
        delete mojoMessage;
        return;
    }

    base::SequencedTaskRunner::GetCurrentDefault()->PostNonNestableDelayedTask(
    FROM_HERE, base::BindOnce([](ApiMessagePortMain* self, mojo::Message* mojoMessage) {
        self->m_connector->Accept(mojoMessage);
        delete mojoMessage;
    }, base::Unretained(this), base::Unretained(mojoMessage)), base::Microseconds(3000));

    //postMessageHelper(m_connector.get(), info);
}

void ApiMessagePortMain::startApi()
{
    if (!isEntangled())
        return;

    if (m_started)
        return;

    m_started = true;
    if (hasPendingActivity())
        pin();
    m_connector->ResumeIncomingMethodCallProcessing();
}

void ApiMessagePortMain::closeApi()
{
    content::printCallstack();

    if (m_closed)
        return;
    if (!isNeutered()) {
        disentangle().ReleaseHandle();
        blink::MessagePortDescriptorPair pipe;
        entangle(pipe.TakePort0());
    }
    m_closed = true;
    if (!hasPendingActivity())
        unpin();

    v8::Isolate* isolate = v8::Isolate::GetCurrent();
    v8::HandleScope scope(isolate);
    v8::Local<v8::Object> self;
    if (!GetWrapper(isolate).IsEmpty())
        mate::EventEmitter<ApiMessagePortMain>::emit("close");
}

void ApiMessagePortMain::entangle(blink::MessagePortDescriptor port)
{
    DCHECK(port.IsValid());
    DCHECK(!m_connector);
    m_port = std::move(port);

    char output[100] = { 0 };
    sprintf_s(output, 99, "ApiMessagePortMain::entangle: %p, %d\n", this, m_port.handle().get().value());
    OutputDebugStringA(output);

    v8::Isolate* isolate = v8::Isolate::GetCurrent();
    v8::HandleScope scope(isolate);
    m_connector = std::make_unique<mojo::Connector>(
        m_port.TakeHandleToEntangleWithEmbedder(), mojo::Connector::SINGLE_THREADED_SEND, base::SingleThreadTaskRunner::GetCurrentDefault());
    m_connector->PauseIncomingMethodCallProcessing();
    m_connector->set_incoming_receiver(this);
    m_connector->set_connection_error_handler(base::BindOnce(&ApiMessagePortMain::closeApi, m_weakFactory.GetWeakPtr()));

    if (hasPendingActivity())
        pin();
}

void ApiMessagePortMain::entangle(blink::MessagePortChannel channel)
{
    entangle(channel.ReleaseHandle());
}

blink::MessagePortChannel ApiMessagePortMain::disentangle()
{
    DCHECK(!isNeutered());
    m_port.GiveDisentangledHandle(m_connector->PassMessagePipe());

    //m_connector.release(); // !!!!!!!!!!TODO
    m_connector = nullptr;

#if 0
    if (!hasPendingActivity())
        unpin();
#else
    // 延时再unpin，不然可能立马被回收了
    m_delayPinOrUnpin.Stop();
    m_delayPinOrUnpin.Start(FROM_HERE, base::Seconds(80000), base::BindOnce(&ApiMessagePortMain::delayPinOrUnpin, base::Unretained(this)));
#endif
    return blink::MessagePortChannel(std::move(m_port));
}

bool ApiMessagePortMain::hasPendingActivity() const
{
    // The spec says that entangled message ports should always be treated as if
    // they have a strong reference.
    // We'll also stipulate that the queue needs to be open (if the app drops its
    // reference to the port before start()-ing it, then it's not really entangled
    // as it's unreachable).
    return m_started && isEntangled();
}

// static
std::vector<ApiMessagePortMain*> ApiMessagePortMain::entanglePorts(v8::Isolate* isolate, std::vector<blink::MessagePortChannel> channels)
{
    std::vector<ApiMessagePortMain*> wrappedPorts;
    for (blink::MessagePortChannel& port : channels) {
        ApiMessagePortMain* wrappedPort = ApiMessagePortMain::create(isolate);
        wrappedPort->entangle(std::move(port));
        wrappedPorts.emplace_back(wrappedPort);
    }
    return wrappedPorts;
}

// static
std::vector<blink::MessagePortChannel> ApiMessagePortMain::disentanglePorts(
    v8::Isolate* isolate, 
    const std::vector<ApiMessagePortMain*>& ports, 
    bool* threw_exception)
{
    if (ports.empty())
        return std::vector<blink::MessagePortChannel>();

    std::unordered_set<ApiMessagePortMain*> visited;

    std::vector<blink::MessagePortChannel> result;
    // Walk the incoming array - if there are any duplicate ports, or null ports
    // or cloned ports, throw an error (per section 8.3.3 of the HTML5 spec).
    for (unsigned i = 0; i < ports.size(); ++i) {
        ApiMessagePortMain* port = ports[i];
        if (!port || port->isNeutered() || base::Contains(visited, port)) {
            std::string type;
            if (!port)
                type = "null";
            else if (port->isNeutered())
                type = "already neutered";
            else
                type = "a duplicate";
            gin_helper::ErrorThrower(isolate).ThrowError("Port at index " + base::NumberToString(i) + " is " + type + ".");
            *threw_exception = true;
            return std::vector<blink::MessagePortChannel>();
        }
        visited.insert(port);
        result.push_back(port->disentangle());
    }

    // Passed-in ports passed validity checks, so we can disentangle them.
    //return base::ToVector(ports, [](ApiMessagePortMain* port) { return port->disentangle(); });
    return result;
}

void ApiMessagePortMain::pin()
{
    if (!m_pinned.IsEmpty())
        return;
    v8::HandleScope scope(isolate());
    v8::Local<v8::Object> self = GetWrapper(isolate());
    if (!self.IsEmpty()) {
        m_pinned.Reset(isolate(), self);
    }
}

void ApiMessagePortMain::unpin()
{
    m_pinned.Reset();
}

static const char ApiMessagePortMainSricpt[] = "exports = {};";

static NodeNative nativeApiMessagePortMainNative { "ApiMessagePortMain", ApiMessagePortMainSricpt, sizeof(ApiMessagePortMainSricpt) - 1 };

NODE_MODULE_CONTEXT_AWARE_BUILTIN_SCRIPT_MANUAL(electron_browser_message_port, initializeApiMessagePortMain, &nativeApiMessagePortMainNative)

} // atom