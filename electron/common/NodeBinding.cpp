
#include "electron/common/NodeBinding.h"

#include "electron/nodeblink.h"
#include "third_party/libnode/src/node.h"
#include "third_party/libuv/include/uv.h"
#include "electron/common/StringUtil.h"
#include "electron/common/AtomVersion.h"
#include "electron/common/ChromeVersion.h"
#include "electron/common/AtomCommandLine.h"
#include "electron/common/BaseMacros.h"
#include "electron/common/api/EventEmitterCaller.h"
//#include "electron/common/TracingControllerImpl.h"
#include "electron/common/Locker.h"
#include "electron/common/LoadMiniElectronAsarRes.h"
#include "electron/common/NodeThread.h"
//#include "base/task/thread_pool/initialization_util.h"
#include "gin/v8_platform_page_allocator.h"
#include "gin/dictionary.h"
#include "base/files/file_path.h"
#include "base/strings/utf_string_conversions.h"
#include "base/path_service.h"
#include <xstring>
#include <vector>
#include <memory>
#include <shlwapi.h>

namespace content {
void* v8ContextToMbWebFrameHandle(v8::Local<v8::Context> context);
void printCallstack();
}

namespace atom {

bool isMainThread();

namespace {

void crash(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    DebugBreak();
}

void hang(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    for (;;) {
        ::Sleep(1000);
    };
}

void getProcessMemoryInfo(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    v8::Isolate* isolate = info.GetIsolate();
    //std::unique_ptr<base::ProcessMetrics> metrics(base::ProcessMetrics::CreateCurrentProcessMetrics());

    gin::Dictionary dict = gin::Dictionary::CreateEmpty(isolate);
    dict.Set("workingSetSize", /*static_cast<double>(metrics->GetWorkingSetSize() >> 10)*/ 1000);
    dict.Set("peakWorkingSetSize", /*static_cast<double>(metrics->GetPeakWorkingSetSize() >> 10)*/ 1000);

    //size_t private_bytes, shared_bytes;
    //if (metrics->GetMemoryBytes(&private_bytes, &shared_bytes)) {
    dict.Set("privateBytes", /*static_cast<double>(private_bytes >> 10)*/ 1000);
    dict.Set("sharedBytes", /*static_cast<double>(shared_bytes >> 10)*/ 1000);
    //}

    info.GetReturnValue().Set(gin::Converter<gin::Dictionary>::ToV8(isolate, dict));
}

void getSystemMemoryInfo(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    v8::Isolate* isolate = info.GetIsolate();
    //     base::SystemMemoryInfoKB mem_info;
    //     if (!base::GetSystemMemoryInfo(&mem_info)) {
    //         args->ThrowError("Unable to retrieve system memory information");
    //         return v8::Undefined(isolate);
    //     }

    gin::Dictionary dict = gin::Dictionary::CreateEmpty(isolate);
    dict.Set("total", /*mem_info.total*/ 10);
    dict.Set("free", /*mem_info.free*/ 10);

    // NB: These return bogus values on macOS
#if !defined(OS_MACOSX)
    dict.Set("swapTotal", /*mem_info.swap_total*/ 10);
    dict.Set("swapFree", /*mem_info.swap_free*/ 10);
#endif

    info.GetReturnValue().Set(gin::Converter<gin::Dictionary>::ToV8(isolate, dict));
}

// Called when there is a fatal error in V8, we just crash the process here so
// we can get the stack trace.
void fatalErrorCallback(const char* location, const char* message)
{
    //crash(info);
    DebugBreak();
}

void log(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    //std::cout << message << std::flush;
    crash(info);
}

void getSystemVersion(const v8::FunctionCallbackInfo<v8::Value>& args)
{
    OSVERSIONINFOEXW os = { 0 };
    os.dwOSVersionInfoSize = sizeof(os);
    ::GetVersionEx(reinterpret_cast<LPOSVERSIONINFOW>(&os));

    std::vector<char> buf(201);
    sprintf(buf.data(), "%d.%d.%d\n", os.dwMajorVersion, os.dwMinorVersion, os.dwBuildNumber);

    v8::Local<v8::String> result = v8::String::NewFromUtf8(args.GetIsolate(), buf.data()).ToLocalChecked();
    args.GetReturnValue().Set(result);
}

} // namespace

NodeBindings::NodeBindings(bool isBrowser)
    : m_isBrowser(isBrowser)
    , m_uvLoop(nullptr)
    , m_uvEnv(nullptr)
    , m_callNextTickAsync(new uv_async_t())
{
}

NodeBindings::~NodeBindings()
{
    if (m_uvEnv) { // 渲染进程里，这个有可能在WebContents::onWillReleaseScriptContextCallback就被销毁了
        nodeDeleteNodeEnvironment(m_uvEnv);
    }

    if (m_isolateData)
        node::FreeIsolateData(m_isolateData);
    delete m_callNextTickAsync;
}

static std::wstring* kResPath = nullptr;

std::wstring getResourcesPath(const std::wstring& name)
{
    std::wstring out;
    if (kResPath) {
        out += *kResPath + name;
        return out;
    }

    std::vector<WCHAR> path;
    path.resize(MAX_PATH + 1);
    ::GetModuleFileName(nullptr, path.data(), MAX_PATH);
    std::wstring selfPathW = path.data();

    //std::string selfPath = base::UTF16ToUTF8(std::u16string_view((const char16_t*)selfPathW.data(), selfPathW.size()));
    //setMiniElectronAsarResPath(selfPath);

    ::PathRemoveFileSpecW(&path[0]);
    out += &path[0];

    std::wstring temp(out);
    temp += L"\\skia.lib";
    if (::PathFileExists(temp.c_str())) {
        out += L"..\\..\\..\\electron\\lib\\";
    } else { // release模式下，直接用打包好的数据
        out = out + L"\\" kMiniElectronAsarPrefix "\\lib\\";
        setMiniElectronAsarResPath(base::WideToUTF8(out));

//         WCHAR drive = L'c';
//         for (size_t i = 0; path[i] != L'\0'; ++i) { // 取一个可用的盘符
//             if (path[i] == L':') {
//                 CHECK(i != 0);
//                 drive = path[i - 1];
//                 if (drive >= 'A' && drive <= 'Z') {
//                     drive += 32;
//                 }
//                 break;
//             }
//         }
//         out = drive;
//         out += L":\\" kMiniElectronAsarPrefix "\\lib\\";
    }

    kResPath = new std::wstring(out);
    out += name;

    temp = L"getResourcesPath:";
    temp += out;
    temp += L"\n";
    OutputDebugStringW(temp.c_str());

    return out;
}

void loadNodeScriptFromRes(void* path)
{
    NodeNative* nativePath = (NodeNative*)path;
    std::wstring sourceW;
    for (size_t i = 0; i < nativePath->sourceLen; ++i)
        sourceW += nativePath->source[i];

    if (L'.' == sourceW[0] && L'/' == sourceW[1])
        sourceW = sourceW.substr(2, sourceW.size() - 2);
    sourceW += L".js";
    sourceW = getResourcesPath(sourceW);

    WIN32_FILE_ATTRIBUTE_DATA attrs;
    if (::GetFileAttributesExW(sourceW.c_str(), GetFileExInfoStandard, &attrs) == 0)
        return;

    HANDLE fileHandle = ::CreateFileW(sourceW.c_str(), FILE_READ_DATA, FILE_SHARE_READ, 0, OPEN_EXISTING, 0, 0);
    if (fileHandle == INVALID_HANDLE_VALUE)
        return;

    std::vector<char>* buffer = new std::vector<char>(); // 内存泄漏
    buffer->resize(attrs.nFileSizeLow);

    DWORD bytesRead;
    int retval = ::ReadFile(fileHandle, &buffer->at(0), attrs.nFileSizeLow, &bytesRead, 0);
    ::CloseHandle(fileHandle);

    if (retval == 0 || bytesRead != attrs.nFileSizeLow)
        return;

    nativePath->source = &buffer->at(0);
    nativePath->sourceLen = bytesRead;
}

// Convert the given vector to an array of C-strings. The strings in the
// returned vector are only guaranteed valid so long as the vector of strings
// is not modified.
std::unique_ptr<const char*[]> stringVectorToArgArray(const std::vector<std::string>& vector)
{
    std::unique_ptr<const char*[]> argsArray(new const char*[vector.size()]);
    for (size_t i = 0; i < vector.size(); ++i) {
        argsArray[i] = vector[i].c_str();
    }
    return argsArray;
}

void NodeBindings::initNodeEnv()
{
    std::vector<std::string> args = AtomCommandLine::argv();
    int argsSize = args.size();

    std::unique_ptr<const char*[]> c_argv = stringVectorToArgArray(args);
    //int exec_argc;
    //const char** execArgv = nullptr;
    //node::Init(&argsSize, c_argv.get(), &exec_argc, &execArgv);

    //std::vector<std::string> argv = { "electron" };
    std::vector<std::string> execArgv;
    std::vector<std::string> errors;
    uint64_t processFlags = node::ProcessFlags::kNoFlags;
    // We do not want the child processes spawned from the utility process
    // to inherit the custom stdio handles created for the parent.
    processFlags |= node::ProcessFlags::kEnableStdioInheritance;

    args.push_back("--no-experimental-detect-module"); // 不加这行，asar的流程会走到nodejs的openhandle里去

    /*int exit_code = */ node::InitializeNodeWithArgs(&args, &execArgv, &errors, (node::ProcessFlags::Flags)(processFlags));
}

static void MethodCallbackWrap(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    v8::Local<v8::External> v8Holder;
    gin::ConvertFromV8(info.GetIsolate(), info.Data(), &v8Holder);
    std::function<void(const v8::FunctionCallbackInfo<v8::Value>&)>* func = (std::function<void(const v8::FunctionCallbackInfo<v8::Value>&)>*)v8Holder->Value();
    (*func)(info);
}

static void bindMethod(
    v8::Isolate* isolate, v8::Local<v8::Object> object, const char* name, const std::function<void(const v8::FunctionCallbackInfo<v8::Value>&)>&& callback)
{
    v8::Local<v8::Context> context = isolate->GetCurrentContext();
    v8::Local<v8::External> wrap = v8::External::New(isolate, new std::function<void(const v8::FunctionCallbackInfo<v8::Value>&)>(callback));
    v8::Local<v8::Function> func = v8::FunctionTemplate::New(isolate, MethodCallbackWrap, wrap)->GetFunction(context).ToLocalChecked();

    // kInternalized strings are created in the old space.
    const v8::NewStringType type = v8::NewStringType::kInternalized;
    v8::Local<v8::String> nameString = v8::String::NewFromUtf8(isolate, name, type).ToLocalChecked();
    object->Set(context, nameString, func);
    func->SetName(nameString); // NODE_SET_METHOD() compatibility.
}

static void isInElectronEnv(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    v8::Isolate* isolate = info.GetIsolate();
    info.GetReturnValue().Set(v8::Boolean::New(isolate, true).As<v8::Value>());
}

void NodeBindings::bindFunction(v8::Isolate* isolate, v8::Local<v8::Object> object)
{
    NodeBindings* self = this;
    bindMethod(isolate, object, "crash", &crash);
    bindMethod(isolate, object, "hang", &hang);
    bindMethod(isolate, object, "log", &log);
    bindMethod(isolate, object, "getProcessMemoryInfo", &getProcessMemoryInfo);
    bindMethod(isolate, object, "getSystemMemoryInfo", &getSystemMemoryInfo);
#if defined(OS_POSIX)
    bindMethod(isolate, object, "setFdLimit", &base::SetFdLimit);
#endif
    bindMethod(isolate, object, "activateUvLoop", [self](const v8::FunctionCallbackInfo<v8::Value>& info) { self->activateUVLoop(info.GetIsolate()); });

#if defined(MAS_BUILD)
    bindMethod(isolate, object, "mas", true);
#endif
    bindMethod(isolate, object, "getSystemVersion", getSystemVersion); // M:\chromium\electron14\electron\shell\common\api\electron_bindings.cc

    gin::Dictionary processObject = gin::Dictionary(isolate, object);
    processObject.Set("sandboxed", false);
    if (!m_processObjInfo.isBrowserProcess)
        processObject.Set("contextIsolated", m_processObjInfo.isContextIsolated);

    // processObject == dict
}

// third_party\libnode\src\node_process_object.cc的PatchProcessObject会重新设置versions，所以我们这个函数的时机也要注意一下
void patchProcessObject(v8::Local<v8::Object> object)
{
    v8::Isolate* isolate = v8::Isolate::GetCurrent();
    gin::Dictionary versions = gin::Dictionary::CreateEmpty(isolate);
    gin::Dictionary processObject = gin::Dictionary(isolate, object);
    v8::Local<v8::Context> context = isolate->GetCurrentContext();
    v8::Context::Scope contextScope(context);

    if (processObject.Get("versions", &versions)) {
        versions.DefineOwnProperty("atom-project-name", std::string(ATOM_VERSION_STRING));
        versions.DefineOwnProperty("atom-shell", std::string(ATOM_VERSION_STRING)); // For compatibility.
        versions.DefineOwnProperty("chrome", std::string(CHROME_VERSION_STRING));
        versions.DefineOwnProperty("electron", std::string(ATOM_VERSION_STRING));

        base::FilePath exePath;
        base::PathService::Get(base::BasePathKey::FILE_EXE, &exePath);
        versions.DefineOwnProperty("execPath", exePath.AsUTF8Unsafe());

        object->Delete(context, gin::StringToV8(isolate, "versions"));
        processObject.DefineOwnProperty("versions", versions);
    }
}

static void mbGetV8NameIdHash(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    if (info.Length() != 1) {
        info.GetReturnValue().Set(0);
        return;
    }
    v8::Local<v8::Value> arg0 = info[0];
    if (!arg0->IsName()) {
        info.GetReturnValue().Set(0);
        return;
    }
    v8::Local<v8::Name> name = arg0.As<v8::Name>();
    info.GetReturnValue().Set(name->GetIdentityHash());
}

struct MbConsoleLogInfo {
    MbConsoleLogInfo(bool isMainNode)
        : m_isMainNode(isMainNode)
    {
    }

    bool getIsMainNode() const
    {
        return m_isMainNode;
    };

private:
    bool m_isMainNode;
};

static void mbConsoleLog(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    v8::Isolate* isolate = info.GetIsolate();
    v8::Local<v8::Context> context = isolate->GetCurrentContext();

    MbConsoleLogInfo* consoleLogInfo = static_cast<MbConsoleLogInfo*>(v8::External::Cast(*info.Data())->Value());

    v8::Local<v8::Value> param0 = info[0];
    v8::MaybeLocal<v8::String> param0Maybe = param0->ToString(context);
    //v8::Local<v8::String> param0V8String = param0->ToString(isolate);
    if (param0Maybe.IsEmpty())
        return;
    v8::Local<v8::String> param0V8String = param0Maybe.ToLocalChecked();

    v8::String::Utf8Value param0String(isolate, param0V8String);
    char temp[150] = { 0 };
    const char* strTemp = (consoleLogInfo->getIsMainNode() ? ("mbConsoleLog, Main(%p):") : ("mbConsoleLog, Render(%p):"));
    void* frameId = consoleLogInfo->getIsMainNode() ? nullptr : content::v8ContextToMbWebFrameHandle(context);
    sprintf(temp, strTemp, frameId);

    std::string str = temp;
    str += *param0String;
    str += "\n";

    if (std::string::npos != str.find("__alert__"))
        MessageBoxA(0, str.c_str(), 0, 0);

    if (std::string::npos != str.find("__callstack__")) {
        content::printCallstack();
    }

    std::wstring strW = StringUtil::UTF8ToUTF16(str);
//     if (std::wstring::npos != strW.find(L"下载文件"))
//         OutputDebugStringA("");

    OutputDebugStringW(strW.c_str());
}

void mbTestMessageChannelMain(const v8::FunctionCallbackInfo<v8::Value>& info);

static void addFunction(v8::Local<v8::Context> context, const char* name, v8::FunctionCallback callback, bool isMainNode)
{
    v8::Isolate* isolate = context->GetIsolate();
    //     if (!isolate->InContext())
    //         return;
    v8::HandleScope handleScope(isolate);
    v8::TryCatch block(isolate);
    v8::Context::Scope contextScope(context);

    v8::Local<v8::Object> object = context->Global();
    v8::Local<v8::FunctionTemplate> tmpl = v8::FunctionTemplate::New(isolate);
    v8::Local<v8::Value> data = v8::External::New(isolate, new MbConsoleLogInfo(isMainNode)); // TODO: 内存泄露

    // Set the function handler callback.
    tmpl->SetCallHandler(callback, data);

    // Retrieve the function object and set the name.
    v8::Local<v8::Function> func = tmpl->GetFunction(context).ToLocalChecked();
    if (func.IsEmpty())
        return;

    v8::MaybeLocal<v8::String> nameV8 = v8::String::NewFromUtf8(isolate, name, v8::NewStringType::kNormal, -1);
    if (nameV8.IsEmpty())
        return;
    v8::Local<v8::String> nameV8Local = nameV8.ToLocalChecked();
    func->SetName(nameV8Local);

    object->Set(context, nameV8Local, func);
}

void bindMbConsoleLog(v8::Local<v8::Context> context)
{
    bool isBrowserProcess = isMainThread();
    addFunction(context, "mbConsoleLog", mbConsoleLog, isBrowserProcess);
    addFunction(context, "mbGetV8NameIdHash", mbGetV8NameIdHash, isBrowserProcess);
    addFunction(context, "mbTestMessageChannelMain", mbTestMessageChannelMain, isBrowserProcess);
    addFunction(context, "_isInElectronEnv", isInElectronEnv, isBrowserProcess);
}

node::Environment* NodeBindings::createEnvironment(v8::Local<v8::Context> context)
{
    v8::Isolate* isolate = context->GetIsolate();
    uv_async_init(m_uvLoop, m_callNextTickAsync, onCallNextTick);
    m_callNextTickAsync->data = this;

    std::vector<std::string> args = AtomCommandLine::argv();
    // Feed node the path to initialization script.
    std::wstring processType = m_isBrowser ? FILE_PATH_LITERAL("browser") : FILE_PATH_LITERAL("renderer");
    std::wstring resourcesPath = getResourcesPath(FILE_PATH_LITERAL(""));
    std::wstring scriptPath = resourcesPath // .append(FILE_PATH_LITERAL("electron.asar"))
                                  .append(processType)
                                  .append(FILE_PATH_LITERAL("\\init.js"));

    // electron里的process.resourcesPath指的是xxx/resources目录。而main.js一般在xxx/resources/app下
    if (args.size() > 1) {
        resourcesPath = StringUtil::MultiByteToUTF16(/*CP_ACP*/ (936), args[1]);
        const WCHAR* resourcesPos = wcsstr(resourcesPath.c_str(), L"resources");
        if (!resourcesPos) {
            std::vector<WCHAR> wbuf(resourcesPath.size() + 1);
            memset(&wbuf[0], 0, 2 * (resourcesPath.size() + 1));
            wcsncpy(&wbuf[0], resourcesPath.c_str(), resourcesPath.size());
            ::PathRemoveFileSpecW(&wbuf[0]);
            resourcesPath = &wbuf[0];
        } else {
            resourcesPath = std::wstring(resourcesPath.c_str(), resourcesPos - resourcesPath.c_str() + 9);
        }
    }

    // 新版本electron的resourcesPath直接就是{exe dir}/resources
    base::FilePath exePath;
    base::PathService::Get(base::BasePathKey::FILE_EXE, &exePath);
    base::FilePath resPath = exePath.DirName();
    resourcesPath = (const WCHAR*)(resPath.AppendASCII("resources").AsUTF16Unsafe()).c_str();

    if (scriptPath.length() > 0 && scriptPath[0] >= L'a' && scriptPath[0] <= L'z')
        scriptPath[0] += L'A' - L'a';

    std::string scriptPathStr = StringUtil::UTF16ToUTF8(scriptPath);
    args.insert(args.begin() + 1, scriptPathStr.c_str()); 

    if (!m_isolateData) {
        g_nodeArgc->m_registerIsolatesLock.Acquire();
        if (g_nodeArgc->m_registerIsolates.end() == g_nodeArgc->m_registerIsolates.find(isolate)) {
            g_nodeArgc->m_registerIsolates.insert(isolate);
            g_nodeArgc->m_nodeMultiIsolatePlatform->RegisterIsolate(isolate, m_uvLoop); // 所有线程的isolate都必须调用这个注册
        }
        m_isolateData = node::CreateIsolateData(isolate, m_uvLoop, g_nodeArgc->m_nodeMultiIsolatePlatform);
        g_nodeArgc->m_registerIsolatesLock.Release();
    }

    uint64_t flags =
        //node::EnvironmentFlags::kDefaultFlags |
        node::EnvironmentFlags::kOwnsProcessState | node::EnvironmentFlags::kHideConsoleWindows | node::EnvironmentFlags::kNoGlobalSearchPaths;

    std::vector<std::string> execArgs;
    std::unique_ptr<const char*[]> c_argv = stringVectorToArgArray(args);
    node::Environment* env = node::CreateEnvironment(m_isolateData, context, args, execArgs, static_cast<node::EnvironmentFlags::Flags>(flags));
    nodeEnvironmentElectronPostEarlyInitialization(env);
    if (!m_isBrowser)
        nodeEnvironmentSetIsblinkCore(env);

    //     const char* argv1[] = { "electron.exe", "E:\\mycode\\miniblink49\\trunk\\electron\\lib\\init.js" };
    //     node::Environment* env = node::CreateEnvironment(isolate, m_uvLoop, context, 2, argv1, 2, argv1);
    //     node::Environment* env = node::CreateEnvironment(isolate, m_uvLoop, context, 2, argv1, 2, argv1);

    // Node turns off AutorunMicrotasks, but we need it in web pages to match the
    // behavior of Chrome.
    //     if (!m_isBrowser)

    gin::Dictionary process(isolate, nodeGetEnvironmentProcessObject(env));
    process.Set("type", StringUtil::UTF16ToUTF8(processType));
    process.Set("resourcesPath", StringUtil::UTF16ToUTF8(resourcesPath));
    // Do not set DOM globals for renderer process.
    if (!m_isBrowser) {
        process.Set("_noBrowserGlobals", StringUtil::UTF16ToUTF8(resourcesPath));
        addFunction(context, "blinkConsoleLog", mbConsoleLog, false);
    }

    m_processObjInfo.isBrowserProcess = m_isBrowser;
    bindFunction(isolate, nodeGetEnvironmentProcessObject(env));

    // The path to helper app.
    //     base::FilePath helper_exec_path;
    //     PathService::Get(content::CHILD_PROCESS_EXE, &helper_exec_path);
    //     process.Set("helperExecPath", helper_exec_path);
    return env;
}

void NodeBindings::loadEnvironment(node::Environment* evn)
{
    node::LoadEnvironment(evn, node::StartExecutionCallback {});
    mate::emitEvent(nodeEnvironmentGetV8Isolate(evn), nodeGetEnvironmentProcessObject(evn), "loaded");
}

void NodeBindings::activateUVLoop(v8::Isolate* isoloate)
{
    node::Environment* env = nodeEnvironmentGetCurrent(isoloate);
    if (std::find(m_pendingNextTicks.begin(), m_pendingNextTicks.end(), env) != m_pendingNextTicks.end())
        return;

    m_pendingNextTicks.push_back(env);
    uv_async_send(m_callNextTickAsync);
}

// static
void NodeBindings::onCallNextTick(uv_async_t* handle)
{
    NodeBindings* self = static_cast<NodeBindings*>(handle->data);

    for (std::list<node::Environment*>::const_iterator it = self->m_pendingNextTicks.begin(); it != self->m_pendingNextTicks.end(); ++it) {
        node::Environment* env = *it;
        v8::Local<v8::Context> context = nodeEnvironmentGetV8Context(env);
        if (!context->GetMicrotaskQueue())
            continue;

        //         v8::HandleScope handleScope(isolate);
        //
        //         // KickNextTick, copied from node.cc:
        //         node::Environment::AsyncCallbackScope callbackScope(env);
        //         if (callbackScope.in_makecallback())
        //             continue;
        //
        //         v8::Context::Scope contextScope(env->context());
        //
        //         v8::Isolate* isolate = isolate;
        //         v8::Local<v8::Context> ctx = isolate->GetCurrentContext();
        //         v8::Isolate* isolate2 = v8::Isolate::GetCurrent();
        //
        //         node::TickInfo* tickInfo = env->tick_info();
        //         if (tickInfo->length() == 0)
        //             isolate->RunMicrotasks();
        //
        //         v8::Local<v8::Object> process = env->process_object();
        //         if (tickInfo->length() == 0)
        //             tickInfo->set_index(0);
        //
        //         env->tick_callback_function()->Call(process, 0, nullptr).IsEmpty();

        // look: E:\chroium\electron22\electron\shell\common\api\electron_bindings.cc
        v8::Isolate* isolate = nodeEnvironmentGetV8Isolate(env);
        //gin_helper::Locker locker(isolate, self->m_isBrowser); // 暂时不锁了，不然在initNodeEnvAndRunLoop里的 v8::HandleScope会导致gin_helper::Locker卡死
        v8::Context::Scope contextScope(context);
        v8::HandleScope handleScope(isolate);
        v8::MicrotasksScope microtasksScope(context, v8::MicrotasksScope::kRunMicrotasks);
        node::CallbackScope scope(isolate, v8::Object::New(isolate), { 0, 0 });
    }

    self->m_pendingNextTicks.clear();
}

} // atom