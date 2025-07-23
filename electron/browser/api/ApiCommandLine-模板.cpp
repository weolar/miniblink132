
#include "electron/common/NodeRegisterHelp.h"
#include "electron/common/IdLiveDetect.h"
#include "electron/common/NodeBinding.h"
#include "electron/common/NodeThread.h"
#include "electron/common/AtomVersion.h"
#include "electron/common/V8Util.h"
#include "electron/common/api/EventEmitter.h"
#include "electron/common/api/EventEmitterCaller.h"
#include "electron/common/gin_helper/dictionary.h"
#include "electron/common/gin_helper/object_template_builder.h"
#include "electron/common/gin_helper/public/gin_embedders.h"
#include "electron/common/gin_helper/public/wrapper_info.h"
#include "third_party/libnode/src/node_binding.h"
#include "base/threading/thread_task_runner_handle.h"
#include "base/command_line.h"

// electron\shell\browser\api\electron_api_utility_process.cc
namespace atom {

// // Main process
// const { app } = require('electron')
// app.commandLine.hasSwitch('disable-gpu')

class ApiCommandLine : public gin_helper::Wrappable<ApiCommandLine> {
public:
    static void init(v8::Isolate* isolate, v8::Local<v8::Object> target, node::Environment* env);
    static void create(const v8::FunctionCallbackInfo<v8::Value>& info);

    explicit ApiCommandLine(v8::Isolate* isolate, v8::Local<v8::Object> wrapper, const std::string& modulePath);
    ~ApiCommandLine();

    void hasSwitchApi(const v8::FunctionCallbackInfo<v8::Value>& info) const;
    std::string getSwitchValueApi(const std::string& switchStr) const;

    static void newFunction(const v8::FunctionCallbackInfo<v8::Value>& args);

public:
    static gin_helper::WrapperInfo kWrapperInfo;
};

gin_helper::WrapperInfo ApiCommandLine::kWrapperInfo = { gin_helper::GinEmbedder::kEmbedderNativeGin };
v8::Persistent<v8::Function> s_ApiCommandLineConstructor;

static void initializeApiCommandLine(v8::Local<v8::Object> target, v8::Local<v8::Value> unused, v8::Local<v8::Context> context, const NodeNative* native)
{
    ApiCommandLine::init(context->GetIsolate(), target, nullptr);
}

void ApiCommandLine::init(v8::Isolate* isolate, v8::Local<v8::Object> target, node::Environment* env)
{
    v8::Local<v8::Context> context = isolate->GetCurrentContext();
    v8::Local<v8::FunctionTemplate> prototype = v8::FunctionTemplate::New(isolate, ApiCommandLine::newFunction);
    gin_helper::ObjectTemplateBuilder builder(isolate, prototype->PrototypeTemplate());
    builder.SetMethod("hasSwitch", &ApiCommandLine::hasSwitchApi);
    builder.SetMethod("getSwitchValue", &ApiCommandLine::getSwitchValueApi);

    v8::Local<v8::Function> prototypFunc = prototype->GetFunction(context).ToLocalChecked();
    target->Set(context, v8::String::NewFromUtf8(isolate, "ApiCommandLine").ToLocalChecked(), prototypFunc);
    s_ApiCommandLineConstructor.Reset(isolate, prototypFunc);
}

void ApiCommandLine::newFunction(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    v8::Isolate* isolate = info.GetIsolate();
    v8::Local<v8::Context> context = isolate->GetCurrentContext();

    CHECK(info.IsConstructCall());
    if (info.Length() != 1)
        return;

    gin_helper::Dictionary args(info.GetIsolate(), info[0]->ToObject(context).ToLocalChecked());
    std::string modulePath;
    args.Get("modulePath", &modulePath);
    //     if (args.Has("args") && !args.Get("args", &params->args)) {
    //         args.ThrowTypeError("Invalid value for args");
    //         return;
    //     }

    new ApiCommandLine(isolate, info.This(), modulePath); // v8管理内存回收
    info.GetReturnValue().Set(info.This());
}

ApiCommandLine::ApiCommandLine(v8::Isolate* isolate, v8::Local<v8::Object> wrapper, const std::string& modulePath)
{
    gin_helper::Wrappable<ApiCommandLine>::InitWith(isolate, wrapper);
    //base::CommandLine cmdLine(program);
    //cmdLine.AppendArgPath(base::FilePath::FromUTF8Unsafe(modulePath));
}

ApiCommandLine::~ApiCommandLine()
{
}

void ApiCommandLine::create(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    v8::Isolate* isolate = info.GetIsolate();
    v8::Local<v8::Context> context = isolate->GetCurrentContext();
    v8::Local<v8::Function> constructorFunction = v8::Local<v8::Function>::New(isolate, s_ApiCommandLineConstructor);

    //     if (info.Length() != 1)
    //         return;
    //     if (!info[0]->IsObject())
    //         return;
    //     v8::Local<v8::Object> arg0 = info[0].As<v8::Object>();
    //     const int argc = 1;
    //     v8::Local<v8::Value> argv[argc] = { arg0 }; // { gin_helper::ConvertToV8(isolate, options) };
    //
    //     v8::MaybeLocal<v8::Object> obj = constructorFunction->NewInstance(context, argc, argv); // call into ApiCommandLine::ApiCommandLine
    v8::MaybeLocal<v8::Object> obj = constructorFunction->NewInstance(context, 0, nullptr); // call into ApiCommandLine::ApiCommandLine
    if (obj.IsEmpty())
        return;

    v8::Local<v8::Object> objV8 = obj.ToLocalChecked();
    ApiCommandLine* self = (ApiCommandLine*)WrappableBase::GetNativePtr(objV8, &kWrapperInfo);
    info.GetReturnValue().Set(objV8);
}

void ApiCommandLine::hasSwitchApi(const v8::FunctionCallbackInfo<v8::Value>& info) const
{
    DebugBreak();
    return;
}

std::string ApiCommandLine::getSwitchValueApi(const std::string& switchStr) const
{
    DebugBreak();
    return ";";
}

static const char CommandLineSricpt[] = "exports = {};";

static NodeNative nativeCommandLineNative { "ApiCommandLine", CommandLineSricpt, sizeof(CommandLineSricpt) - 1 };

NODE_MODULE_CONTEXT_AWARE_BUILTIN_SCRIPT_MANUAL(atom_browser_commandline, initializeApiCommandLine, &nativeCommandLineNative)

} // atom