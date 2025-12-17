
#include "ipc_lite/ipc_channel_proxy.h"
#include "ipc_lite/ipc_message_macros.h"
#include "electron/browser/api/MessageFilterWrap.h"
#include "electron/browser/api/ApiMessagePortMain.h"
#include "electron/browser/api/PostMessageUtil.h"
#include "electron/common/IoThread.h"
#include "electron/common/NodeRegisterHelp.h"
#include "electron/common/IdLiveDetect.h"
#include "electron/common/NodeBinding.h"
#include "electron/common/NodeThread.h"
#include "electron/common/AtomVersion.h"
#include "electron/common/V8Util.h"
#include "electron/common/ipc/UtilityProcessMsgs.h"
#include "electron/common/api/EventEmitter.h"
#include "electron/common/api/EventEmitterCaller.h"
#include "electron/common/gin_helper/dictionary.h"
#include "electron/common/gin_helper/object_template_builder.h"
#include "electron/common/gin_helper/public/gin_embedders.h"
#include "electron/common/gin_helper/public/wrapper_info.h"
#include "third_party/libnode/src/node_binding.h"
#include "third_party/blink/public/common/messaging/cloneable_message.h"
#include "third_party/blink/public/common/messaging/message_port_descriptor.h"
#include "third_party/blink/public/common/messaging/transferable_message.h"
#include "third_party/blink/public/common/messaging/transferable_message_mojom_traits.h"
//#include "third_party/blink/public/mojom/messaging/transferable_message.mojom.h"
#include "third_party/blink/public/mojom/messaging/transferable_message.mojom-blink.h"
#include "mojo/public/cpp/bindings/connector.h"
#include "base/task/sequenced_task_runner.h"
#include "base/process/process.h"
#include "base/process/launch.h"
#include "base/strings/stringprintf.h"
#include "base/strings/utf_string_conversions.h"
#include "base/containers/id_map.h"
#include "base/process/kill.h"
#include "base/command_line.h"
#include "base/base_paths.h"
#include "base/path_service.h"
#include "base/no_destructor.h"

extern "C" MojoResult MojoBindIpcChannelProxy(int64_t pid, void* /* IPC::ChannelProxy*/ channelProxy);
extern "C" MojoResult MojoChangeToRemoteServiceMode(int64_t pid, MojoHandle handle);

// electron\shell\browser\api\electron_api_utility_process.cc
namespace atom {

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

bool isValidWrappable(const v8::Local<v8::Value>& val);

static std::string generateChannelID()
{
    // The channel counter keeps us out of trouble if we create and destroy
    // several AutomationProxies sequentially over the course of a test run.
    // (Creating the channel sometimes failed before when running a lot of
    // tests in sequence, and our theory is that sometimes the channel ID
    // wasn't getting freed up in time for the next test.)
    static int channelCounter = 0;
    ++channelCounter;
    return base::StringPrintf("%lu|%d", base::GetCurrentProcId(), channelCounter);
}

class ApiUtilityProcess : public mate::EventEmitter<ApiUtilityProcess>, public MessageFilterInterface, public mojo::MessageReceiver {
public:
    static void init(v8::Isolate* isolate, v8::Local<v8::Object> target, node::Environment* env);
    static void create(const v8::FunctionCallbackInfo<v8::Value>& info);

    explicit ApiUtilityProcess(v8::Isolate* isolate,
        v8::Local<v8::Object> wrapper,
        const std::string& modulePath,
        const base::EnvironmentMap& envMap,
        const std::vector<std::string>& execArgv,
        const std::string& cwd);
    ~ApiUtilityProcess();
    void close();

    void postMessageApi(const v8::FunctionCallbackInfo<v8::Value>& info);
    void onChildMsg(const std::vector<char>& msg);
    bool killApi();
    void getOSProcessIdApi(const v8::FunctionCallbackInfo<v8::Value>& info);

    // MessageFilterWrap
    /*virtual*/ bool onMessageReceived(const IPC::Message& message) override;
    /*virtual*/ void onChannelConnected(int32 peerPid) override;
    /*virtual*/ void onChannelError() override;
    /*virtual*/ void onChannelClosing() override;
    //---

    //mojo::MessageReceiver
    bool Accept(mojo::Message* mojoMessage) override;
    //---

    static void newFunction(const v8::FunctionCallbackInfo<v8::Value>& args);

public:
    base::Process m_childProcess;
    //blink::MessagePortDescriptor m_hostPort;
    IPC::ChannelProxy* m_channel = nullptr;
    scoped_refptr<base::SequencedTaskRunner> m_mainThread;

    scoped_refptr<MessageFilterWrap> m_messageFilterWrap;
    std::unique_ptr<mojo::Connector> m_connector;
    static gin_helper::WrapperInfo kWrapperInfo;
};

gin_helper::WrapperInfo ApiUtilityProcess::kWrapperInfo = { gin_helper::GinEmbedder::kEmbedderNativeGin };
v8::Persistent<v8::Function> s_ApiUtilityProcessConstructor;

static base::NoDestructor<base::IDMap<ApiUtilityProcess*, base::ProcessId>> s_allUtilityProcess;

static void initializeApiUtilityProcess(v8::Local<v8::Object> target, v8::Local<v8::Value> unused, v8::Local<v8::Context> context, const NodeNative* native)
{
    ApiUtilityProcess::init(context->GetIsolate(), target, nullptr);
}

void ApiUtilityProcess::init(v8::Isolate* isolate, v8::Local<v8::Object> target, node::Environment* env)
{
    v8::Local<v8::Context> context = isolate->GetCurrentContext();
    v8::Local<v8::FunctionTemplate> prototype = v8::FunctionTemplate::New(isolate, ApiUtilityProcess::newFunction);
    gin_helper::ObjectTemplateBuilder builder(isolate, prototype->InstanceTemplate());
    builder.SetMethod("postMessage", &ApiUtilityProcess::postMessageApi);
    builder.SetMethod("kill", &ApiUtilityProcess::killApi);
    builder.SetProperty("pid", &ApiUtilityProcess::getOSProcessIdApi);

    gin_helper::Dictionary dict(isolate, target);
    dict.SetMethod("_fork", &ApiUtilityProcess::create); // 导出一个静态函数

    v8::Local<v8::Function> prototypFunc = prototype->GetFunction(context).ToLocalChecked();

    s_ApiUtilityProcessConstructor.Reset(isolate, prototypFunc);
}

void traverseObjectForEnvMap(v8::Isolate* isolate, v8::Local<v8::Object> obj, base::EnvironmentMap* envMap)
{
    v8::TryCatch tryCatch(isolate); // 捕获可能的异常

    if (obj.IsEmpty())
        return;

    v8::Local<v8::Array> propertyNames;
    if (!obj->GetPropertyNames(isolate->GetCurrentContext()).ToLocal(&propertyNames))
        return;

    for (uint32_t i = 0; i < propertyNames->Length(); ++i) {
        v8::Local<v8::Value> key;
        if (!propertyNames->Get(isolate->GetCurrentContext(), i).ToLocal(&key))
            continue;

        v8::Local<v8::String> keyStr;
        if (!key->IsString())
            continue;

        keyStr = key.As<v8::String>();
        v8::Local<v8::Value> value;
        if (!obj->Get(isolate->GetCurrentContext(), key).ToLocal(&value))
            continue;

        if (!value->IsString())
            continue;

        v8::Local<v8::String> valueStr = value.As<v8::String>();

        v8::String::Utf8Value keyUtf8(isolate, keyStr);
        v8::String::Utf8Value valueUtf8(isolate, valueStr);

        std::wstring keyW = base::UTF8ToWide(*keyUtf8);
        std::wstring valueW = base::UTF8ToWide(*valueUtf8);
        (*envMap)[keyW] = valueW;
    }
}

void ApiUtilityProcess::newFunction(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    v8::Isolate* isolate = info.GetIsolate();
    v8::Local<v8::Context> context = isolate->GetCurrentContext();

    CHECK(info.IsConstructCall());
    if (info.Length() != 1)
        return;

    // https://www.electronjs.org/docs/latest/api/utility-process
    gin_helper::Dictionary args(info.GetIsolate(), info[0]->ToObject(context).ToLocalChecked());
    std::string modulePath;
    args.Get("modulePath", &modulePath);

    base::EnvironmentMap envMap;
    gin_helper::Dictionary opts(info.GetIsolate());
    args.Get("options", &opts);

    v8::Local<v8::Object> env;
    opts.Get("env", &env);
    traverseObjectForEnvMap(isolate, env, &envMap);

    std::vector<std::string> execArgv;
    opts.Get("execArgv", &execArgv);

    std::string cwd;
    opts.Get("cwd", &cwd);
    
    new ApiUtilityProcess(isolate, info.This(), modulePath, envMap, execArgv, cwd); // v8管理内存回收
    info.GetReturnValue().Set(info.This());
}

IPC::ChannelProxy* g_channel = nullptr;
void* testChannel()
{
    std::vector<char> testData;
    testData.resize(10);
    //     g_channel->Send(new UtilityProcessMsg_Test(testData));
    return new UtilityProcessMsg_Test(testData);
}

ApiUtilityProcess::ApiUtilityProcess(
    v8::Isolate* isolate, 
    v8::Local<v8::Object> wrapper, 
    const std::string& modulePath,
    const base::EnvironmentMap& envMap,
    const std::vector<std::string>& execArgv,
    const std::string& cwd)
{
    gin_helper::Wrappable<ApiUtilityProcess>::InitWith(isolate, wrapper);
    m_mainThread = base::SequencedTaskRunner::GetCurrentDefault();
    m_messageFilterWrap = new MessageFilterWrap(this);

    base::FilePath program;
    base::PathService::Get(base::BasePathKey::FILE_EXE, &program);
    base::CommandLine cmdLine(program);
    cmdLine.AppendArgPath(base::FilePath::FromUTF8Unsafe(modulePath));

    std::string channelId = generateChannelID();
    cmdLine.AppendSwitchASCII(kElectronUtilProcChannelId, channelId);

    for (size_t i = 0; i < execArgv.size(); ++i) {
        cmdLine.AppendArg(execArgv[i]);
    }

    std::unique_ptr<IPC::ChannelProxy> channel(new IPC::ChannelProxy(channelId, IPC::Channel::MODE_NAMED_SERVER, nullptr, IoThread::get()->taskRunner()));
    m_channel = channel.get();
    m_channel->AddFilter(m_messageFilterWrap.get());
    g_channel = m_channel;

    base::LaunchOptions launchOpt;
    launchOpt.start_hidden = true;
    launchOpt.elevated = false;
    if (!cwd.empty())
        launchOpt.current_directory = base::FilePath::FromUTF8Unsafe(cwd);
    launchOpt.environment = envMap;

    m_childProcess = base::LaunchProcess(cmdLine, launchOpt);
    if (!m_childProcess.IsValid())
        return;

    MojoBindIpcChannelProxy(m_childProcess.Pid(), channel.release());

    mojo::MessagePipe pipe;
    MojoHandle remotePort = pipe.handle1.get().value();

    char output[100] = { 0 };
    sprintf_s(output, 99, "ApiUtilityProcess: %d %d %d\n", pipe.handle0.get().value(), pipe.handle1.get().value(), remotePort);
    OutputDebugStringA(output);

    MojoChangeToRemoteServiceMode(m_childProcess.Pid(), remotePort);
    m_channel->Send(new UtilityProcessMsg_PostMessagePortToChildProcess(remotePort));

    m_connector = std::make_unique<mojo::Connector>(std::move(pipe.handle0), mojo::Connector::SINGLE_THREADED_SEND);
    m_connector->PauseIncomingMethodCallProcessing();
    m_connector->set_incoming_receiver(this);
    m_connector->set_connection_error_handler(base::BindOnce(&ApiUtilityProcess::close, base::Unretained(this)));
    m_connector->StartReceiving(base::SequencedTaskRunner::GetCurrentDefault());

    s_allUtilityProcess->AddWithID(this, m_childProcess.Pid());
}

ApiUtilityProcess::~ApiUtilityProcess()
{
    if (m_channel)
        m_channel->RemoveFilter(m_messageFilterWrap.get());
}

void ApiUtilityProcess::create(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    v8::Isolate* isolate = info.GetIsolate();
    if (info.Length() != 1)
        return;
    if (!info[0]->IsObject())
        return;
    v8::Local<v8::Object> arg0 = info[0].As<v8::Object>();
    //gin_helper::Dictionary options(isolate, arg0);
    const int argc = 1;
    v8::Local<v8::Value> argv[argc] = { arg0 }; // { gin_helper::ConvertToV8(isolate, options) };
    v8::Local<v8::Function> constructorFunction = v8::Local<v8::Function>::New(isolate, s_ApiUtilityProcessConstructor);
    v8::Local<v8::Context> context = isolate->GetCurrentContext();

    v8::MaybeLocal<v8::Object> obj = constructorFunction->NewInstance(context, argc, argv); // call into ApiUtilityProcess::ApiUtilityProcess
    if (obj.IsEmpty())
        return;

    v8::Local<v8::Object> objV8 = obj.ToLocalChecked();
    ApiUtilityProcess* self = (ApiUtilityProcess*)WrappableBase::GetNativePtr(objV8, &kWrapperInfo);
    info.GetReturnValue().Set(objV8);
}

void ApiUtilityProcess::close()
{
}

bool ApiUtilityProcess::killApi()
{
    if (m_childProcess.IsValid())
        return false;
    base::Process process = base::Process::Open(m_childProcess.Pid());
    bool result = process.Terminate(/*content::RESULT_CODE_NORMAL_EXIT*/ 0, false);
    // Refs https://bugs.chromium.org/p/chromium/issues/detail?id=818244
    // Currently utility process is not sandboxed which
    // means Zygote is not used on linux, refs
    // content::UtilitySandboxedProcessLauncherDelegate::GetZygote.
    // If sandbox feature is enabled for the utility process, then the
    // process reap should be signaled through the zygote via
    // content::ZygoteCommunication::EnsureProcessTerminated.
    base::EnsureProcessTerminated(std::move(process));
    //killed_ = result;
    return result;
}

void ApiUtilityProcess::getOSProcessIdApi(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    info.GetReturnValue().Set(gin_helper::ConvertToV8(info.GetIsolate(), (uint64_t)(m_childProcess.Pid())));
}

void ApiUtilityProcess::postMessageApi(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    if (!m_channel)
        return;
    postMessageHelper(m_connector.get(), info);
}

// 本函数被废弃了，用Accept
void ApiUtilityProcess::onChildMsg(const std::vector<char>& msg)
{
    DebugBreak();
    v8::Isolate* isolate = v8::Isolate::GetCurrent();
    base::span<const uint8_t> data((const uint8_t*)msg.data(), msg.size());
    v8::Local<v8::Value> msgV8 = deserializeV8Value(v8::Isolate::GetCurrent(), data);

    mate::EventEmitter<ApiUtilityProcess>::emit("message", msgV8);
}

bool ApiUtilityProcess::Accept(mojo::Message* mojoMessage)
{
    CHECK(m_mainThread->RunsTasksInCurrentSequence());
    return onApiUtilityProcessAcceptHelper(getWrapper(), mojoMessage);
}

// 在io线程运行
bool ApiUtilityProcess::onMessageReceived(const IPC::Message& message)
{
    bool handled = true;
    bool deserializeSuccess = true;
    IPC_BEGIN_MESSAGE_MAP_EX(ApiUtilityProcess, message, deserializeSuccess)
        IPC_MESSAGE_HANDLER(UtilityProcessMsg_PostToParentMessage, onChildMsg)
        IPC_MESSAGE_UNHANDLED(handled = false)
    IPC_END_MESSAGE_MAP_EX()

    return handled;
}

void ApiUtilityProcess::onChannelConnected(int32 peerPid)
{
    m_mainThread->PostTask(
        FROM_HERE, base::BindOnce([](ApiUtilityProcess* self) { self->mate::EventEmitter<ApiUtilityProcess>::emit("spawn"); }, base::Unretained(this)));
}

void ApiUtilityProcess::onChannelError()
{
    m_channel = nullptr;

    m_mainThread->PostTask(FROM_HERE,
        base::BindOnce(
            [](ApiUtilityProcess* self) {
                s_allUtilityProcess->Remove(self->m_childProcess.Pid());
                self->mate::EventEmitter<ApiUtilityProcess>::emit("exit");
            },
            base::Unretained(this)));
}

void ApiUtilityProcess::onChannelClosing()
{
    m_channel = nullptr;
}

static const char UtilityProcessSricpt[] = "exports = {};";

static NodeNative nativeUtilityProcessNative { "ApiUtilityProcess", UtilityProcessSricpt, sizeof(UtilityProcessSricpt) - 1 };

NODE_MODULE_CONTEXT_AWARE_BUILTIN_SCRIPT_MANUAL(electron_browser_utility_process, initializeApiUtilityProcess, &nativeUtilityProcessNative)

} // atom