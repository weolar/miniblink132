
#include "ipc_lite/ipc_channel_proxy.h"
#include "ipc_lite/ipc_message_macros.h"
#include "electron/browser/api/MessageFilterWrap.h"
#include "electron/browser/api/PostMessageUtil.h"
#include "electron/common/NodeRegisterHelp.h"
#include "electron/common/IdLiveDetect.h"
#include "electron/common/NodeBinding.h"
#include "electron/common/NodeThread.h"
#include "electron/common/AtomVersion.h"
#include "electron/common/V8Util.h"
#include "electron/common/IoThread.h"
#include "electron/common/ipc/UtilityProcessMsgs.h"
#include "electron/common/api/EventEmitter.h"
#include "electron/common/api/EventEmitterCaller.h"
#include "electron/common/gin_helper/dictionary.h"
#include "electron/common/gin_helper/object_template_builder.h"
#include "electron/common/gin_helper/public/gin_embedders.h"
#include "electron/common/gin_helper/public/wrapper_info.h"
#include "electron/common/gin_helper/data_object_builder.h"
#include "gin/handle.h"
#include "third_party/libnode/src/node_binding.h"
#include "third_party/blink/public/common/messaging/cloneable_message.h"
#include "third_party/blink/public/common/messaging/message_port_descriptor.h"
#include "third_party/blink/public/common/messaging/transferable_message.h"
#include "third_party/blink/public/common/messaging/transferable_message_mojom_traits.h"
//#include "third_party/blink/public/mojom/messaging/transferable_message.mojom.h"
#include "third_party/blink/public/mojom/messaging/transferable_message.mojom-blink.h"
#include "mojo/public/cpp/bindings/connector.h"
#include "base/task/sequenced_task_runner.h"
#include "base/strings/string_split.h"
#include "base/process/process.h"
#include "base/process/launch.h"
#include "base/strings/stringprintf.h"
#include "base/command_line.h"

extern "C" MojoResult MojoBindIpcChannelProxy(int64_t pid, void* /* IPC::ChannelProxy*/ channelProxy);
extern "C" MojoResult MojoChangeToRemoteClientMode(MojoHandle handle, int64_t pid, MojoHandle* out);

namespace atom {

bool isValidWrappable(const v8::Local<v8::Value>& val);

// // Main process
// const child = utilityProcess.fork(path.join(__dirname, 'test.js'));
// child.postMessage({ message: 'hello' });
// child.on('message', (data) = > {
//     console.log(data) // hello world!
// });
// // Child process
// process.parentPort.on('message', (e) = > {
//     process.parentPort.postMessage(`${e.data} world!`)
// });

// 本类产生的对象一般都不会销毁
class ApiParentPort : public mate::EventEmitter<ApiParentPort>, public MessageFilterInterface, public mojo::MessageReceiver {
public:
    static void init(v8::Isolate* isolate, v8::Local<v8::Object> target, node::Environment* env);
    static void create(const v8::FunctionCallbackInfo<v8::Value>& info);

    explicit ApiParentPort(v8::Isolate* isolate, v8::Local<v8::Object> wrapper, const gin_helper::Dictionary& options);
    ~ApiParentPort();

    void onRecvParentMessagePort(uintptr_t pipe);
    void closePipe();

    // MessageFilterWrap
    /*virtual*/ bool onMessageReceived(const IPC::Message& message) override;
    /*virtual*/ void onChannelConnected(int32 peerPid) override
    {
        //m_channel = nullptr;
    }
    /*virtual*/ void onChannelError() override
    {
        m_channel = nullptr;
        HANDLE handle = ::OpenProcess(PROCESS_ALL_ACCESS, 0, ::GetCurrentProcessId());
        ::TerminateProcess(handle, -1);
    }
    /*virtual*/ void onChannelClosing() override
    {
        m_channel = nullptr;
    }

    // mojo::MessageReceiver
    /*virtual*/ bool Accept(mojo::Message* message) override;

    static void newFunction(const v8::FunctionCallbackInfo<v8::Value>& args);

public:
    void onRecvParentMessagePortImpl();
    void bindIpcChannelProxy(const std::string& channelId, int64_t parentProcessId);
    void onParentMsg(const std::vector<char>& msg);
    void _sendApi(const v8::FunctionCallbackInfo<v8::Value>& info);

    scoped_refptr<base::SequencedTaskRunner> m_mainThread;
    IPC::ChannelProxy* m_channel = nullptr;
    scoped_refptr<MessageFilterWrap> m_messageFilterWrap;
    std::unique_ptr<mojo::Connector> m_connector;

    int64_t m_parentProcessId = 0;

    uintptr_t m_parentPipe = 0; // 来自ApiUtilityProcess::ApiUtilityProcess

    static gin_helper::WrapperInfo kWrapperInfo;
};

// 只能有一个子进程
static ApiParentPort* s_childProcessParentPort = nullptr;

gin_helper::WrapperInfo ApiParentPort::kWrapperInfo = { gin_helper::GinEmbedder::kEmbedderNativeGin };
v8::Persistent<v8::Function> s_ParentPortConstructor;

static void initializeParentPortApi(v8::Local<v8::Object> target, v8::Local<v8::Value> unused, v8::Local<v8::Context> context, const NodeNative* native)
{
    ApiParentPort::init(context->GetIsolate(), target, nullptr);
}

void ApiParentPort::init(v8::Isolate* isolate, v8::Local<v8::Object> target, node::Environment* env)
{
    v8::Local<v8::Context> context = isolate->GetCurrentContext();
    v8::Local<v8::FunctionTemplate> prototype = v8::FunctionTemplate::New(isolate, ApiParentPort::newFunction);

    prototype->SetClassName(v8::String::NewFromUtf8(isolate, "ParentPort").ToLocalChecked());
    gin_helper::ObjectTemplateBuilder builder(isolate, prototype->InstanceTemplate());
    builder.SetMethod("_send", &ApiParentPort::_sendApi);

    v8::Local<v8::Function> prototypFunc = prototype->GetFunction(context).ToLocalChecked();
    s_ParentPortConstructor.Reset(isolate, prototypFunc);

    base::CommandLine* cmdLine = base::CommandLine::ForCurrentProcess();
    if (cmdLine->HasSwitch(kElectronUtilProcChannelId)) { // 本进程属于UtilityProcess才会绑定
        target->Set(context, v8::String::NewFromUtf8(isolate, "ParentPort").ToLocalChecked(), prototypFunc);
    }
}

void ApiParentPort::newFunction(const v8::FunctionCallbackInfo<v8::Value>& args)
{
    v8::Isolate* isolate = args.GetIsolate();
    v8::Local<v8::Context> context = isolate->GetCurrentContext();

    //MessageBoxA(0, "ApiParentPort::newFunction", 0, 0);

    CHECK(args.IsConstructCall());
    if (args.Length() != 1)
        return;

    gin_helper::Dictionary options(args.GetIsolate(), args[0]->ToObject(context).ToLocalChecked());
    new ApiParentPort(isolate, args.This(), options);
    args.GetReturnValue().Set(args.This());
}

static bool s_firstEvaluateModule = false; // nodejs是否加载了第一个js

void PreEvaluateModule()
{
    s_firstEvaluateModule = true;
    //OutputDebugStringA("PreEvaluateModule\n");
}

void PostEvaluateModule()
{
    //OutputDebugStringA("PostEvaluateModule\n");
}

void ApiParentPort::bindIpcChannelProxy(const std::string& channelId, int64_t parentProcessId)
{
    // 要延迟一下，不然js那边还没执行到process.parentPort.once
    if (!s_firstEvaluateModule) {
        base::SequencedTaskRunner::GetCurrentDefault()->PostNonNestableDelayedTask(FROM_HERE,
            base::BindOnce([](ApiParentPort* self, const std::string& channelId, int64_t parentProcessId) {
                self->bindIpcChannelProxy(channelId, parentProcessId);
        }, base::Unretained(this), channelId, parentProcessId), base::Milliseconds(2000));
        s_firstEvaluateModule = true;
        return;
    }
    m_channel = (new IPC::ChannelProxy(channelId, IPC::Channel::MODE_CLIENT, nullptr, IoThread::get()->taskRunner()));
    m_channel->AddFilter(m_messageFilterWrap.get());

    char output[100] = { 0 };
    sprintf_s(output, 99, "ApiParentPort::bindIpcChannelProxy: %d\n", parentProcessId);
    //MessageBoxA(0, output, 0, 0);
    OutputDebugStringA(output);
    MojoBindIpcChannelProxy(parentProcessId, m_channel);
}

ApiParentPort::ApiParentPort(v8::Isolate* isolate, v8::Local<v8::Object> wrapper, const gin_helper::Dictionary& options)
{
    gin_helper::Wrappable<ApiParentPort>::InitWith(isolate, wrapper);
    m_mainThread = base::SequencedTaskRunner::GetCurrentDefault();
    m_messageFilterWrap = new MessageFilterWrap(this);

    CHECK(!s_childProcessParentPort);
    s_childProcessParentPort = this;

    base::CommandLine* cmd = base::CommandLine::ForCurrentProcess();
    std::string channelId = cmd->GetSwitchValueASCII(kElectronUtilProcChannelId);
    std::vector<std::string> tempStr = base::SplitString(channelId, "|", base::TRIM_WHITESPACE, base::SPLIT_WANT_ALL);
    CHECK(tempStr.size() == 2);
    int64_t parentProcessId = 0;
    CHECK(base::StringToInt64(tempStr[0], &parentProcessId));
    m_parentProcessId = parentProcessId;

    //MessageBoxA(0, "ApiParentPort::ApiParentPort", 0, 0);
    OutputDebugStringA("ApiParentPort::ApiParentPort\n");

    bindIpcChannelProxy(channelId, parentProcessId);
}

ApiParentPort::~ApiParentPort()
{
    if (m_channel)
        m_channel->RemoveFilter(m_messageFilterWrap.get());
}

void ApiParentPort::create(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    v8::Isolate* isolate = info.GetIsolate();
    if (info.Length() != 1)
        return;
    if (!info[0]->IsObject())
        return;
    v8::Local<v8::Object> arg0 = info[0].As<v8::Object>();
    gin_helper::Dictionary options(isolate, arg0);
    const int argc = 1;
    v8::Local<v8::Value> argv[argc] = { arg0 }; // { gin_helper::ConvertToV8(isolate, options) };
    v8::Local<v8::Function> constructorFunction = v8::Local<v8::Function>::New(isolate, s_ParentPortConstructor);
    v8::Local<v8::Context> context = isolate->GetCurrentContext();

    v8::MaybeLocal<v8::Object> obj = constructorFunction->NewInstance(context, argc, argv); // call into ApiUtilityProcess::ApiUtilityProcess
    if (obj.IsEmpty())
        return;

    v8::Local<v8::Object> objV8 = obj.ToLocalChecked();
    info.GetReturnValue().Set(objV8);
}

void ApiParentPort::_sendApi(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    OutputDebugStringA("ApiParentPort::_sendApi\n");

    mojo::Message mojoMessage;
    if (!v8FunInfoToMojoMessage(info, &mojoMessage, nullptr))
        return;

    if (m_connector.get()) {
        bool b = m_connector->Accept(&mojoMessage);
        b ? OutputDebugStringA("ApiParentPort::_sendApi 1 ok\n") : OutputDebugStringA("ApiParentPort::_sendApi 1 fail\n");
        return;
    }

    // 等待主进程的hello消息
    m_mainThread->PostNonNestableDelayedTask(FROM_HERE, base::BindOnce([](ApiParentPort* self, const mojo::Message& mojoMessage) {
        if (!self->m_connector) {
            OutputDebugStringA("ApiParentPort::_sendApi 3 fail\n");
            return;
        }
        bool b = self->m_connector->Accept((mojo::Message*)(&mojoMessage));
        b ? OutputDebugStringA("ApiParentPort::_sendApi 2 ok\n") : OutputDebugStringA("ApiParentPort::_sendApi 2 fail\n");
    }, base::Unretained(this), std::move(mojoMessage)), base::Milliseconds(3000));
}

bool ApiParentPort::onMessageReceived(const IPC::Message& message)
{
    bool handled = true;
    bool deserializeSuccess = true;
    IPC_BEGIN_MESSAGE_MAP_EX(ApiParentPort, message, deserializeSuccess)
        IPC_MESSAGE_HANDLER(UtilityProcessMsg_PostMessagePortToChildProcess, onRecvParentMessagePort)
        IPC_MESSAGE_UNHANDLED(handled = false)
    IPC_END_MESSAGE_MAP_EX()

    return handled;
}

bool ApiParentPort::Accept(mojo::Message* mojoMessage)
{
    return onChannelMessagingApiAcceptHelper(false, "message", getWrapper(), mojoMessage);
}

void ApiParentPort::closePipe()
{
    m_channel = nullptr;
}

void ApiParentPort::onRecvParentMessagePortImpl()
{
    char output2[120] = { 0 };
    sprintf_s(output2, 119, "ApiParentPort.onRecvParentMessagePort 2: %d\n", m_parentPipe);
    OutputDebugStringA(output2);

    if (m_connector.get())
        return;

    MojoHandle localHandle = 0;
    MojoChangeToRemoteClientMode(m_parentPipe, m_parentProcessId, &localHandle);

    mojo::MessagePipeHandle h(localHandle);
    mojo::ScopedMessagePipeHandle scopedMsgPipeHandle(std::move(h));
    m_connector = std::make_unique<mojo::Connector>(std::move(scopedMsgPipeHandle), mojo::Connector::SINGLE_THREADED_SEND);
    m_connector->PauseIncomingMethodCallProcessing();
    m_connector->set_incoming_receiver(this);
    m_connector->set_connection_error_handler(base::BindOnce(&ApiParentPort::closePipe, base::Unretained(this)));
    m_connector->StartReceiving(m_mainThread);
}

// 这个是在io线程执行的，接受父进程的hello消息
void ApiParentPort::onRecvParentMessagePort(uintptr_t pipe)
{
    char output[120] = { 0 };
    sprintf_s(output, 119, "ApiParentPort.onRecvParentMessagePort 1: %d\n", pipe);
    OutputDebugStringA(output);

    m_parentPipe = pipe;

    m_mainThread->PostTask(FROM_HERE, base::BindOnce([](ApiParentPort* self, uintptr_t pipe) {
        self->onRecvParentMessagePortImpl();
    }, base::Unretained(this), pipe));
}

// 本函数被废弃了，用Accept
void ApiParentPort::onParentMsg(const std::vector<char>& msg)
{
    base::span<const uint8_t> data((const uint8_t*)msg.data(), msg.size());
    v8::Local<v8::Value> msvV8 = deserializeV8Value(v8::Isolate::GetCurrent(), data);
    mate::EventEmitter<ApiParentPort>::emit("message", msvV8);
}

static const char ParentPortSricpt[] = "exports = {};";

static NodeNative nativeParentPortNative { "ParentPort", ParentPortSricpt, sizeof(ParentPortSricpt) - 1 };

NODE_MODULE_CONTEXT_AWARE_BUILTIN_SCRIPT_MANUAL(electron_browser_parent_port, initializeParentPortApi, &nativeParentPortNative)

} // atom