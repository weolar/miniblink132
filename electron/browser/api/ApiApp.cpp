
#define _CRT_NON_CONFORMING_SWPRINTFS

#include "browser/api/ApiApp.h"

#include "electron/common/NodeRegisterHelp.h"
#include "electron/common/AtomCommandLine.h"
#include "electron/common/StringUtil.h"
#include "electron/common/api/EventEmitter.h"
#include "electron/common/IconUtil.h"
#include "electron/common/gin_helper/promise.h"
#include "electron/common/gin_helper/ConverterUtil.h"
#include "electron/common/gin_helper/object_template_builder.h"
#include "electron/common/gin_helper/arguments.h"
#include "electron/common/gin_helper/wrappable.h"
#include "electron/common/gin_helper/dictionary.h"
#include "electron/browser/api/ApiSession.h"
#include "electron/browser/api/WindowList.h"
#include "electron/browser/api/WindowInterface.h"
#include "electron/browser/api/AppBrowser.h"
#include "electron/nodeblink.h"
#include "base/values.h"
#include "base/base_paths.h"
#include "base/path_service.h"
#include "base/base64.h"
#include "base/json/json_writer.h"
#include "base/files/file_path.h"
#include "base/strings/string_util.h"
#include "base/strings/utf_string_conversions.h"
#include "base/win/scoped_co_mem.h"
#include "third_party/libnode/src/node.h"
#include "third_party/libnode/src/node_binding.h"
#include "third_party/libuv/include/uv.h"
#include "content/common/mbchar.h"
#include "content/common/ThreadCall.h"

#include <shlobj.h>
#include <Shlwapi.h>
#include <shellapi.h>
#include <Netlistmgr.h>

typedef BOOL(__stdcall* FN_ChangeWindowMessageFilterEx)(HWND hwnd, UINT message, DWORD action, void* pChangeFilterStruct);

namespace content {
void printCallstack();
}

namespace mbnet {
int checkIsNetwork(INetworkListManager* pNetworkListManager);
static INetworkListManager* getNetworkList(IUnknown** ppUnknown);
}

namespace {

static void MB_CALL_TYPE onOnUvCreateProcessCallback(
    mbWebView webView, void* param, const WCHAR* applicationPath, const WCHAR* arguments, STARTUPINFOW* startup)
{
    OutputDebugStringW(L"onOnUvCreateProcessCallback:");
    OutputDebugStringW(applicationPath);
    OutputDebugStringW(L"\n");

    if (nullptr != wcsstr(applicationPath, L"git.exe"))
        startup->wShowWindow = SW_HIDE;
    if (nullptr != wcsstr(applicationPath, L"Microsoft.VSCode.CPP.Extension.exe"))
        startup->wShowWindow = SW_HIDE;
    if (nullptr != wcsstr(applicationPath, L"watcher\\win32\\CodeHelper.exe"))
        startup->wShowWindow = SW_HIDE;
}

}

namespace atom {

App* App::m_instance = nullptr;
static const WCHAR kMutexName[] = L"LocalAtomProcessSingletonStartup!";
const WCHAR kHiddenWindowPropName[] = L"mb_app_hidden_window";
const int BUFSIZE = 4096;

App* App::getInstance()
{
    return m_instance;
}

App::App(v8::Isolate* isolate, v8::Local<v8::Object> wrapper)
{
    gin_helper::Wrappable<App>::InitWith(isolate, wrapper);
    m_instance = this;
    m_version = "1.3.3";
    m_singleInstanceHandle = nullptr;

    //mbOnNodeCreateProcess(NULL_WEBVIEW, onOnUvCreateProcessCallback, nullptr);
}

App::~App()
{
    ::CloseHandle(m_singleInstanceHandle);
    m_singleInstanceHandle = nullptr;

    DebugBreak();
}

void App::init(v8::Local<v8::Object> target, v8::Isolate* isolate)
{
    v8::Local<v8::FunctionTemplate> prototype = v8::FunctionTemplate::New(isolate, newFunction);

    prototype->SetClassName(v8::String::NewFromUtf8(isolate, "App").ToLocalChecked());
    gin_helper::ObjectTemplateBuilder builder(isolate, prototype->InstanceTemplate());
    builder.SetMethod("quit", &App::quitApi);
    builder.SetMethod("exit", &App::exitApi);
    builder.SetMethod("focus", &App::focusApi);
    builder.SetMethod("getVersion", &App::getVersionApi);
    builder.SetMethod("setVersion", &App::setVersionApi);
    builder.SetMethod("getName", &App::getNameApi);
    builder.SetMethod("setName", &App::setNameApi);
    builder.SetMethod("isReady", &App::isReadyApi);
    builder.SetProperty("isPackaged", &App::isPackagedApi);
    builder.SetMethod("_setAppPath", &App::_setAppPathApi);
    builder.SetMethod("_setIsReady", &App::_setIsReadyApi);
    builder.SetMethod("isOnline", &App::isOnlineApi);
    builder.SetMethod("addRecentDocument", &App::addRecentDocumentApi);
    builder.SetMethod("clearRecentDocuments", &App::clearRecentDocumentsApi);
    builder.SetMethod("setAppUserModelId", &App::setAppUserModelIdApi);
    builder.SetMethod("requestSingleInstanceLock", &App::requestSingleInstanceLockApi);
    builder.SetMethod("isDefaultProtocolClient", &App::isDefaultProtocolClientApi);
    builder.SetMethod("setAsDefaultProtocolClient", &App::setAsDefaultProtocolClientApi);
    builder.SetMethod("removeAsDefaultProtocolClient", &App::removeAsDefaultProtocolClientApi);
    builder.SetMethod("setBadgeCount", &App::setBadgeCountApi);
    builder.SetMethod("getBadgeCount", &App::getBadgeCountApi);
    builder.SetMethod("getLoginItemSettings", &App::getLoginItemSettingsApi);
    builder.SetMethod("setLoginItemSettings", &App::setLoginItemSettingsApi);
    builder.SetMethod("setUserTasks", &App::setUserTasksApi);
    builder.SetMethod("getJumpListSettings", &App::getJumpListSettingsApi);
    builder.SetMethod("setJumpList", &App::setJumpListApi);
    builder.SetMethod("setPath", &App::setPathApi);
    builder.SetMethod("getPath", &App::getPathApi);
    builder.SetMethod("setDesktopName", &App::setDesktopNameApi);
    builder.SetMethod("getLocale", &App::getLocaleApi);
    builder.SetMethod("makeSingleInstanceImpl", &App::makeSingleInstanceImplApi);
    builder.SetMethod("releaseSingleInstance", &App::releaseSingleInstanceApi);
    builder.SetMethod("_relaunch", &App::relaunchApi);
    builder.SetMethod("isAccessibilitySupportEnabled", &App::isAccessibilitySupportEnabled);
    builder.SetMethod("disableHardwareAcceleration", &App::disableHardwareAcceleration);
    builder.SetMethod("getFileIcon", &App::getFileIconApi);

    v8::Local<v8::Context> context = isolate->GetCurrentContext();
    constructor.Reset(isolate, prototype->GetFunction(context).ToLocalChecked());
    target->Set(context, v8::String::NewFromUtf8(isolate, "App").ToLocalChecked(), prototype->GetFunction(context).ToLocalChecked());
}

void App::nullFunction()
{
    OutputDebugStringA("nullFunction\n");
}

void quit()
{
    ::TerminateProcess(::GetCurrentProcess(), 0);
    WindowList::closeAllWindows();

    //     content::ThreadCall::exitMessageLoop(content::ThreadCall::getBlinkThreadId());
    //     content::ThreadCall::exitMessageLoop(content::ThreadCall::getUiThreadId());
}

void App::quitApi()
{
    OutputDebugStringA("quitApi\n");

    content::printCallstack();

    App* self = this;
    content::ThreadCall::callUiThreadAsync(FROM_HERE, [self] {
        content::ThreadCall::callUiThreadAsync(FROM_HERE, [self] { self->emit("before-quit"); });
        quit();
    });
}

void App::exitApi()
{
    quitApi();
}

void App::focusApi()
{
    OutputDebugStringA("focusApi\n");
}

bool App::isReadyApi() const
{
    return m_isReady;
}

void App::_setIsReadyApi()
{
    m_isReady = true;
}

bool App::isPackagedApi()
{
    return true; // weolar!!!
//     if (-1 == m_isPackaged) {
//         std::string appPath = m_appPath;
//         std::transform(appPath.begin(), appPath.end(), appPath.begin(), [](unsigned char c) { return std::tolower(c); });
//         m_isPackaged = (appPath.find(".asar") != std::string::npos) ? 1 : 0;
//     }
//     return m_isPackaged == 1;
}

void App::_setAppPathApi(const std::string& path)
{
    m_appPath = path;
}

bool App::isOnlineApi()
{
    IUnknown* pUnknown = nullptr;
    static INetworkListManager* pNetworkListManager = nullptr;
    if (!pNetworkListManager)
        pNetworkListManager = mbnet::getNetworkList(&pUnknown);

    BOOL checkNetwork = mbnet::checkIsNetwork(pNetworkListManager);
    return !!checkNetwork;
}

// const std::string& path, gin_helper::Arguments* args
void App::getFileIconApi(const v8::FunctionCallbackInfo<v8::Value>& args)
{
    std::string path;
    if (!gin_helper::ConvertFromV8(args.GetIsolate(), args[0], &path))
        return;

    if (path.empty())
        return;

    std::string sizeStr("small"); // small | normal | large
    base::Value::Dict obj;
    if (gin_helper::ConvertFromV8(args.GetIsolate(), args[1], &obj)) {
        const std::string* sizeStrPtr = obj.FindString("size");
        if (sizeStrPtr && !sizeStrPtr->empty())
            sizeStr = *sizeStrPtr;
    }

    gin_helper::Promise<v8::Local<v8::Object>>* promise = new gin_helper::Promise<v8::Local<v8::Object>>(args.GetIsolate());
    v8::Local<v8::Promise> ret = promise->GetHandle();

    int size = 0;
    if (sizeStr == "small")
        size = SHGFI_SMALLICON;
    else if (sizeStr == "normal")
        size = 0;
    else if (sizeStr == "large")
        size = SHGFI_LARGEICON;
    else
        return;

    std::string* pathStr = new std::string(path);

    App* self = this;
    content::ThreadCall::callUiThreadAsync(FROM_HERE, [self, promise, pathStr, size] {
        SHFILEINFO fileInfo = { 0 };
        v8::Isolate* isolate = v8::Isolate::GetCurrent();
        std::u16string path = base::UTF8ToUTF16(*pathStr);
        delete pathStr;

        if (!::SHGetFileInfo((const WCHAR*)path.c_str(), FILE_ATTRIBUTE_NORMAL, &fileInfo, sizeof(SHFILEINFO), SHGFI_ICON | size | SHGFI_USEFILEATTRIBUTES)) {
            promise->Reject();
            return;
        }

        v8::Local<v8::Object> bitmap = IconUtil::CreateSkBitmapFromHICON(isolate, fileInfo.hIcon);
        ::DestroyIcon(fileInfo.hIcon);
        if (bitmap.IsEmpty()) {
            promise->Reject();
            return;
        }

        promise->Resolve(bitmap);
    });

    args.GetReturnValue().Set(ret);
}

void App::addRecentDocumentApi(const std::string& path)
{
    OutputDebugStringA("addRecentDocumentApi\n");
}

void App::clearRecentDocumentsApi()
{
    OutputDebugStringA("clearRecentDocumentsApi\n");
}

void App::setAppUserModelIdApi(const std::string& id)
{
    OutputDebugStringA("setAppUserModelIdApi\n");
}

bool App::requestSingleInstanceLockApi()
{
    base::FilePath path;
    base::PathService::Get(base::DIR_EXE, &path);
    std::string temp = path.AsUTF8Unsafe();
    temp = base::Base64Encode(std::string_view(temp.c_str(), temp.size()));

    HANDLE hMutex = NULL;
    hMutex = ::CreateMutexA(NULL, FALSE, (temp).c_str());
    if (hMutex != NULL) {
        if (ERROR_ALREADY_EXISTS == ::GetLastError()) {
            ::ReleaseMutex(hMutex);
            return false;
        }
    }
    return true;
}

// const std::string& protocol, const std::string& path, const std::string& args
bool App::isDefaultProtocolClientApi(const v8::FunctionCallbackInfo<v8::Value>& args)
{
    OutputDebugStringA("isDefaultProtocolClientApi\n");
    return true;
}

//const std::string& protocol, const std::string& path, const std::string& args
bool App::setAsDefaultProtocolClientApi(const v8::FunctionCallbackInfo<v8::Value>& args)
{
    OutputDebugStringA("setAsDefaultProtocolClientApi\n");
    if (0 == args.Length())
        return false;

    std::string protocol;
    if (!gin_helper::ConvertFromV8(args.GetIsolate(), args[0], &protocol))
        return false;

    return true;
}

// const std::string& protocol, const std::string& path, const std::string& args
bool App::removeAsDefaultProtocolClientApi(const v8::FunctionCallbackInfo<v8::Value>& args)
{
    OutputDebugStringA("removeAsDefaultProtocolClientApi\n");
    return true;
}

bool App::setBadgeCountApi(int count)
{
    OutputDebugStringA("setBadgeCountApi\n");
    return false;
}

int App::getBadgeCountApi()
{
    OutputDebugStringA("getBadgeCountApi\n");
    return 0;
}

#if defined(_WIN32)
template <> struct gin_helper::Converter<LaunchItem> {
    static bool FromV8(v8::Isolate* isolate, v8::Local<v8::Value> val, LaunchItem* out)
    {
        gin_helper::Dictionary dict(isolate);
        if (!ConvertFromV8(isolate, val, &dict))
            return false;

        dict.Get("name", &(out->name));
        dict.Get("path", &(out->path));
        dict.Get("args", &(out->args));
        dict.Get("scope", &(out->scope));
        dict.Get("enabled", &(out->enabled));
        return true;
    }

    static v8::Local<v8::Value> ToV8(v8::Isolate* isolate, LaunchItem val)
    {
        gin_helper::Dictionary dict = gin_helper::Dictionary::CreateEmpty(isolate);
        dict.Set("name", val.name);
        dict.Set("path", val.path);
        dict.Set("args", val.args);
        dict.Set("scope", val.scope);
        dict.Set("enabled", val.enabled);
        return dict.GetHandle();
    }
};
#endif

template <> struct gin_helper::Converter<LoginItemSettings> {
    static bool FromV8(v8::Isolate* isolate, v8::Local<v8::Value> val, LoginItemSettings* out)
    {
        gin_helper::Dictionary dict(isolate);
        if (!ConvertFromV8(isolate, val, &dict))
            return false;

        dict.Get("openAtLogin", &(out->open_at_login));
        dict.Get("openAsHidden", &(out->open_as_hidden));
        dict.Get("path", &(out->path));
        dict.Get("args", &(out->args));
#if defined(_WIN32)
        dict.Get("enabled", &(out->enabled));
        dict.Get("name", &(out->name));
#endif
        return true;
    }

    static v8::Local<v8::Value> ToV8(v8::Isolate* isolate, LoginItemSettings val)
    {
        gin_helper::Dictionary dict = gin_helper::Dictionary::CreateEmpty(isolate);
        dict.Set("openAtLogin", val.open_at_login);
        dict.Set("openAsHidden", val.open_as_hidden);
        dict.Set("restoreState", val.restore_state);
        dict.Set("wasOpenedAtLogin", val.opened_at_login);
        dict.Set("wasOpenedAsHidden", val.opened_as_hidden);
#if BUILDFLAG(IS_WIN)
        dict.Set("launchItems", val.launch_items);
        dict.Set("executableWillLaunchAtLogin", val.executable_will_launch_at_login);
#endif
        return dict.GetHandle();
    }
};

void App::getLoginItemSettingsApi(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    gin_helper::Arguments args(info);
    LoginItemSettings options;
    args.GetNext(&options);
    LoginItemSettings setting = getLoginItemSettings(options);

    v8::Local<v8::Value> ret = gin_helper::Converter<LoginItemSettings>::ToV8(info.GetIsolate(), setting);
    info.GetReturnValue().Set(ret);
}

void App::setLoginItemSettingsApi(const v8::FunctionCallbackInfo<v8::Value>& args)
{
    LoginItemSettings settings;
    if (args.Length() != 1)
        return;
    if (!gin_helper::Converter<LoginItemSettings>::FromV8(args.GetIsolate(), args[0], &settings))
        return;
    setLoginItemSettings(settings);
}

bool App::setUserTasksApi(const v8::FunctionCallbackInfo<v8::Value>& args)
{
    OutputDebugStringA("setUserTasksApi\n");
    return true;
}

void App::setDesktopNameApi(const std::string& desktopName)
{
    OutputDebugStringA("App::setDesktopNameApi\n");
}

v8::Local<v8::Value> App::getJumpListSettingsApi(const v8::FunctionCallbackInfo<v8::Value>& args)
{
    OutputDebugStringA("getJumpListSettingsApi\n");
    base::Value::Dict obj;

    obj.Set("minItems", 1);

    base::Value::List removedItems;
    obj.Set("removedItems", std::move(removedItems));

    v8::Local<v8::Value> result = gin_helper::Converter<base::Value::Dict>::ToV8(args.GetIsolate(), obj);
    return result;
}

// const base::DictionaryValue&
void App::setJumpListApi(const v8::FunctionCallbackInfo<v8::Value>& args)
{
    OutputDebugStringA("setJumpListApi\n");
}

std::string App::getLocaleApi()
{
    return "zh-cn";
}

static LRESULT CALLBACK staticWindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
static void registerHiddenWindowClass(LPCWSTR lpszClassName)
{
    WNDCLASS wndClass = { 0 };
    if (!GetClassInfoW(NULL, lpszClassName, &wndClass)) {
        wndClass.style = CS_HREDRAW | CS_VREDRAW | CS_DROPSHADOW;
        wndClass.lpfnWndProc = &staticWindowProc;
        wndClass.cbClsExtra = 200;
        wndClass.cbWndExtra = 200;
        wndClass.hInstance = GetModuleHandleW(NULL);
        wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
        wndClass.hbrBackground = NULL;
        wndClass.lpszMenuName = NULL;
        wndClass.lpszClassName = lpszClassName;
        ATOM r = RegisterClass(&wndClass);
        r = r;
    }
}

static LRESULT CALLBACK staticWindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    int id = -1;
    App* self = (App*)::GetPropW(hWnd, kHiddenWindowPropName);
    if (!self && message == WM_CREATE) {
        LPCREATESTRUCTW cs = (LPCREATESTRUCTW)lParam;
        self = (App*)cs->lpCreateParams;
        ::SetPropW(hWnd, kHiddenWindowPropName, (HANDLE)self);
        return 0;
    }

    if (!self)
        return ::DefWindowProcW(hWnd, message, wParam, lParam);

    if (message == WM_COPYDATA) {
        COPYDATASTRUCT* copyData = (COPYDATASTRUCT*)lParam;
        if (copyData->dwData == WindowInterface::kSingleInstanceMessage) {
            self->onCopyData(copyData);
        }
    }

    return ::DefWindowProcW(hWnd, message, wParam, lParam);
}

void App::onCopyData(const COPYDATASTRUCT* copyData)
{
    if (copyData->dwData != WindowInterface::kSingleInstanceMessage || 0 == copyData->cbData)
        return;
    if (m_singleInstanceCall.IsEmpty())
        return;

    std::string json((const char*)copyData->lpData, copyData->cbData);

    v8::Function* callback = nullptr;
    v8::Local<v8::Value> f = m_singleInstanceCall.Get(isolate());
    callback = v8::Function::Cast(*(f));

    v8::MaybeLocal<v8::String> argString = v8::String::NewFromUtf8(isolate(), json.c_str(), v8::NewStringType::kNormal, json.length());

    v8::Local<v8::Value> argv[1];
    argv[0] = argString.ToLocalChecked();
    callback->Call(callback->GetCreationContext().ToLocalChecked(), v8::Undefined(isolate()), 1, argv);
}

static std::u16string getNormalizeFilePath()
{
    std::vector<WCHAR> path;
    path.resize(BUFSIZE + 1);
    ::GetModuleFileNameW(::GetModuleHandleW(NULL), &path[0], BUFSIZE);

    std::vector<WCHAR> buffer;
    buffer.resize(BUFSIZE + 1);
    // ::GetLongPathName(path.data(), &buffer[0], BUFSIZE);

    WCHAR** lppPart = { nullptr };
    ::GetFullPathName(&path[0], BUFSIZE, &buffer[0], lppPart);

    int i = 0;
    for (; i < BUFSIZE; ++i) {
        WCHAR c = buffer[i];
        if (c >= L'A' && c <= L'Z')
            buffer[i] += 32;
        else if (c == L'/')
            buffer[i] = L'\\';
        if (L'\0' == c)
            break;
    }

    return std::u16string((const char16_t*)buffer.data(), i);
}

static void notifSingleProcess(HWND hWnd)
{
    std::vector<std::string> argv = atom::AtomCommandLine::argv();

    std::vector<WCHAR> buffer;
    buffer.resize(MAX_PATH + 1);
    ::GetModuleFileNameW(::GetModuleHandleW(NULL), &buffer[0], MAX_PATH);
    ::PathRemoveFileSpecW(&buffer[0]);

    std::string workingDirectory = base::UTF16ToUTF8((const char16_t*)(&buffer[0]));

    base::Value::List value;
    std::string json;

    for (size_t i = 0; i < argv.size(); ++i) {
        value.Append(argv[i]);
    }

    value.Append(workingDirectory);
    base::JSONWriter::Write(value, &json);

    COPYDATASTRUCT copyData;
    copyData.dwData = WindowInterface::kSingleInstanceMessage;
    copyData.cbData = json.length();
    copyData.lpData = (PVOID)json.c_str();
    ::SendMessage(hWnd, WM_COPYDATA, (WPARAM)hWnd, (LPARAM)&copyData);
}

bool App::makeSingleInstanceImplApi(const v8::FunctionCallbackInfo<v8::Value>& args)
{
    if (args[0]->IsFunction())
        m_singleInstanceCall.Reset(args.GetIsolate(), args[0]);
    else
        m_singleInstanceCall.Reset();

    std::u16string filePath = getNormalizeFilePath();
    unsigned int pathHash = StringUtil::hashString(base::UTF16ToUTF8(filePath).c_str());

    std::vector<WCHAR> buffer;
    buffer.resize(BUFSIZE);
    swprintf(&buffer[0], L"MbAppMakeSingleInstanceHiddenWindow_%d\n", pathHash);

    m_singleInstanceHandle = ::CreateMutex(NULL, FALSE, kMutexName);
    if (GetLastError() == ERROR_ALREADY_EXISTS) {
        HWND hWnd = ::FindWindowEx(NULL, NULL, &buffer[0], nullptr);
        if (hWnd)
            notifSingleProcess(hWnd);
        ::CloseHandle(m_singleInstanceHandle);
        m_singleInstanceHandle = nullptr;
        return true;
    }

    registerHiddenWindowClass(&buffer[0]);
    m_hiddenWindow = ::CreateWindowExW(0, &buffer[0], L"title", WS_OVERLAPPED, 0, 0, 1, 1, NULL, NULL, ::GetModuleHandleW(NULL), this);
    ::ShowWindow(m_hiddenWindow, SW_HIDE);

    // NB: Ensure that if the primary app gets started as elevated
    // admin inadvertently, secondary windows running not as elevated
    // will still be able to send messages
    HMODULE hinstLib = LoadLibraryW(L"User32.dll");
    static FN_ChangeWindowMessageFilterEx ChangeWindowMessageFilterFunc = nullptr;
    static bool isFind = false;
    if (!isFind) {
        isFind = true;
        ChangeWindowMessageFilterFunc = (FN_ChangeWindowMessageFilterEx)GetProcAddress(hinstLib, "ChangeWindowMessageFilterEx");
        if (ChangeWindowMessageFilterFunc)
            ChangeWindowMessageFilterFunc(m_hiddenWindow, WM_COPYDATA, /*MSGFLT_ALLOW*/ 1, NULL);
    }

    return false;
}

void App::releaseSingleInstanceApi()
{
    ::CloseHandle(m_singleInstanceHandle);
    m_singleInstanceHandle = nullptr;
}

static std::u16string addQuoteForArg(const std::u16string& arg)
{
    // We follow the quoting rules of CommandLineToArgvW.
    // http://msdn.microsoft.com/en-us/library/17w5ykft.aspx
    std::u16string quotable_chars((const char16_t*)L" \\\"");
    if (arg.find_first_of(quotable_chars) == std::u16string::npos) {
        // No quoting necessary.
        return arg;
    }

    std::u16string out;
    out += (L'"');
    for (size_t i = 0; i < arg.size(); ++i) {
        if (arg[i] == '\\') {
            // Find the extent of this run of backslashes.
            size_t start = i, end = start + 1;
            for (; end < arg.size() && arg[end] == '\\'; ++end) {
            }
            size_t backslash_count = end - start;

            // Backslashes are escapes only if the run is followed by a double quote.
            // Since we also will end the string with a double quote, we escape for
            // either a double quote or the end of the string.
            if (end == arg.size() || arg[end] == '"') {
                // To quote, we need to output 2x as many backslashes.
                backslash_count *= 2;
            }
            for (size_t j = 0; j < backslash_count; ++j)
                out += L'\\';

            // Advance i to one before the end to balance i++ in loop.
            i = end - 1;
        } else if (arg[i] == '"') {
            out += L'\\';
            out += L'"';
        } else {
            out += (arg[i]);
        }
    }
    out += L'"';

    return out;
}

static std::u16string argvToCommandLineString(const std::vector<std::u16string>& argv)
{
    std::u16string commandLine;
    for (const std::u16string& arg : argv) {
        if (!commandLine.empty())
            commandLine += L' ';
        commandLine += addQuoteForArg(arg);
    }
    return commandLine;
}

const char* kWaitEventName = "ElectronRelauncherWaitEvent";
const WCHAR* kRelauncherTypeArg = L"--type=relauncher";
const WCHAR* kRelauncherArgSeparator = L"---";

static PROCESS_INFORMATION* launchProcess(const std::u16string& cmdline)
{
    STARTUPINFO startup_info = { 0 };
    DWORD flags = 0;

    startup_info.dwFlags = STARTF_USESHOWWINDOW;
    startup_info.wShowWindow = SW_SHOW;

    PROCESS_INFORMATION* tempProcessInfo = new PROCESS_INFORMATION();
    memset(tempProcessInfo, 0, sizeof(PROCESS_INFORMATION));
    std::u16string writableCmdline = cmdline;

    if (!::CreateProcessW(NULL, (WCHAR*)writableCmdline.data(), NULL, NULL, FALSE, flags, NULL, NULL, &startup_info, tempProcessInfo)) {
        tempProcessInfo->hProcess = INVALID_HANDLE_VALUE;
        return tempProcessInfo;
    }

    return tempProcessInfo;
}

static std::u16string getWaitEventName(DWORD pid)
{
    std::vector<char> buffer;
    buffer.resize(0x1000);
    memset(&buffer[0], 0, 0x1000);
    sprintf(&buffer[0], "%s-%d", kWaitEventName, static_cast<int>(pid));
    return base::UTF8ToUTF16(&buffer[0]);
}

static bool relaunchAppWithHelper(const base::FilePath& helper, const std::vector<std::u16string>& relauncher_args, const std::vector<std::u16string>& argv)
{
    std::vector<std::u16string> relaunchArgv;
    relaunchArgv.push_back(helper.AsUTF16Unsafe());
#if 0 // https://github.com/electron/electron/pull/5837/files
    relaunchArgv.push_back(kRelauncherTypeArg);
    relaunchArgv.insert(relaunchArgv.end(), relauncher_args.begin(), relauncher_args.end());
    relaunchArgv.push_back(kRelauncherArgSeparator);
    relaunchArgv.insert(relaunchArgv.end(), argv.begin(), argv.end());
#endif
    PROCESS_INFORMATION* process = launchProcess(argvToCommandLineString(relaunchArgv));
    if (!process || INVALID_HANDLE_VALUE == process->hProcess) {
        if (process)
            delete process;
        return false;
    }

    // The relauncher process is now starting up, or has started up. The
    // original parent process continues.
    // Synchronize with the relauncher process.
    std::u16string name = getWaitEventName(process->dwProcessId);
    HANDLE waitEvent = ::CreateEventW(NULL, TRUE, FALSE, (LPCWSTR)name.c_str());
    if (waitEvent != NULL) {
        ::WaitForSingleObject(waitEvent, 1000);
        ::CloseHandle(waitEvent);
    }

    return true;
}

static bool relaunchApp(const std::vector<std::u16string>& argv)
{
    // Use the currently-running application's helper process. The automatic
    // update feature is careful to leave the currently-running version alone,
    // so this is safe even if the relaunch is the result of an update having
    // been applied. In fact, it's safer than using the updated version of the
    // helper process, because there's no guarantee that the updated version's
    // relauncher implementation will be compatible with the running version's.
    base::FilePath childPath;
    std::vector<char16_t> currentExePath;
    currentExePath.resize(MAX_PATH);
    ::GetModuleFileNameW(NULL, (LPWSTR)currentExePath.data(), MAX_PATH);
    childPath = base::FilePath::FromUTF16Unsafe((currentExePath.data()));

    std::vector<std::u16string> relauncherArgs;
    return relaunchAppWithHelper(childPath, relauncherArgs, argv);
}

void App::relaunchApi(const base::Value::Dict& options)
{
    std::string argsStr;
    std::string execPathStr;
    bool isOverrideArgv = false;
    const base::Value* args = nullptr;
    const base::Value::List* argsList = nullptr;
    std::vector<std::u16string> argsArray;

    argsList = options.FindList("args");
    if (argsList) {
        for (size_t i = 0; argsList && i < argsList->size(); ++i) {
            const base::Value& argV = (*argsList)[i];
            if (!argV.is_string())
                continue;
            const std::string* arg = argV.GetIfString();
            if (arg->size() > 0)
                argsArray.push_back(base::UTF8ToUTF16(*arg));
        }
        if (argsArray.size() > 0)
            isOverrideArgv = true;
    }

    const std::string* execPath = nullptr;
    execPath = options.FindString("execPath");
    if (execPath) {
        if (execPath->size() > 0)
            isOverrideArgv = true;
    }

    if (!isOverrideArgv) {
        const std::vector<std::u16string>& argv = atom::AtomCommandLine::wargv();
        relaunchApp(argv);
    }

    std::vector<std::u16string> argv;
    argv.reserve(1 + argsArray.size());

    if (execPathStr.empty()) {
        std::vector<char16_t> currentExePath;
        currentExePath.resize(MAX_PATH);
        if (GetModuleFileName(NULL, (WCHAR*)currentExePath.data(), MAX_PATH))
            argv.push_back(&currentExePath[0]);
    } else {
        argv.push_back(base::UTF8ToUTF16(execPathStr));
    }

    argv.insert(argv.end(), argsArray.begin(), argsArray.end());
    relaunchApp(argv);
}

void App::setPathApi(const std::string& name, const std::string& path)
{
    if (!(name == "userData" || name == "cache" || name == "userCache" || name == "documents" || name == "downloads" || name == "music" || name == "videos"
            || name == "pepperFlashSystemPlugin"))
        return;

    std::map<std::string, std::string>::iterator it = m_pathMap.find(name);
    if (it == m_pathMap.end())
        m_pathMap.insert(std::make_pair(name, path));
    else
        it->second = path;
}

bool getTempDir(base::FilePath* path)
{
    WCHAR temp_path[MAX_PATH + 1];
    DWORD path_len = ::GetTempPath(MAX_PATH, temp_path);
    if (path_len >= MAX_PATH || path_len <= 0)
        return false;
    // TODO(evanm): the old behavior of this function was to always strip the
    // trailing slash.  We duplicate this here, but it shouldn't be necessary
    // when everyone is using the appropriate FilePath APIs.
    *path = base::FilePath(temp_path).StripTrailingSeparators();
    return true;
}

base::FilePath getHomeDir()
{
    WCHAR result[MAX_PATH];
    if (SUCCEEDED(SHGetFolderPath(NULL, CSIDL_PROFILE, NULL, SHGFP_TYPE_CURRENT, result)) && result[0])
        return base::FilePath(result);

    // Fall back to the temporary directory on failure.
    base::FilePath temp;
    if (getTempDir(&temp))
        return temp;

    // Last resort.
    return base::FilePath(L"C:\\");
}

// Generic function to call SHGetFolderPath().
bool getUserDirectory(int csidl_folder, base::FilePath* result) {
    // We need to go compute the value. It would be nice to support paths
    // with names longer than MAX_PATH, but the system functions don't seem
    // to be designed for it either, with the exception of GetTempPath
    // (but other things will surely break if the temp path is too long,
    // so we don't bother handling it.
    wchar_t pathBuf[MAX_PATH];
    pathBuf[0] = 0;
    if (FAILED(::SHGetFolderPath(nullptr, csidl_folder, nullptr,
        SHGFP_TYPE_CURRENT, pathBuf))) {
        return false;
    }
    *result = base::FilePath(pathBuf);
    return true;
}

bool getUserDocumentsDirectory(base::FilePath* result) 
{
    return getUserDirectory(CSIDL_MYDOCUMENTS, result);
}

bool getUserMusicDirectory(base::FilePath* result) 
{
    return getUserDirectory(CSIDL_MYMUSIC, result);
}

bool getUserPicturesDirectory(base::FilePath* result)
{
    return getUserDirectory(CSIDL_MYPICTURES, result);
}

bool getUserVideosDirectory(base::FilePath* result) 
{
    return getUserDirectory(CSIDL_MYVIDEO, result);
}

bool getUserRecentDirectory(base::FilePath* result)
{
    return getUserDirectory(CSIDL_RECENT, result);
}

// Return a default path for downloads that is safe.
// We just use 'Downloads' under DIR_USER_DOCUMENTS. Localizing
// 'downloads' is not a good idea because Chrome's UI language
// can be changed.
bool getUserDownloadsDirectorySafe(base::FilePath* result) 
{
    if (!getUserDocumentsDirectory(result))
        return false;

    *result = result->Append(L"Downloads");
    return true;
}

// Get the downloads known folder. Since it can be relocated to point to a
// "dangerous" folder, callers should validate that the returned path is not
// dangerous before using it.
bool getUserDownloadsDirectory(base::FilePath* result)
{
    base::win::ScopedCoMem<wchar_t> pathBuf;
    if (SUCCEEDED(::SHGetKnownFolderPath(FOLDERID_Downloads, 0, nullptr, &pathBuf))) {
        *result = base::FilePath(std::wstring(pathBuf));
        return true;
    }
    return getUserDownloadsDirectorySafe(result);
}

std::string App::getPathApi(const std::string& name) const
{
    base::FilePath path;
    std::u16string systemBuffer;
    systemBuffer.assign(MAX_PATH, L'\0');
    std::u16string pathBuffer;
    if (name == "appData") {
        if ((::SHGetFolderPathW(NULL, CSIDL_APPDATA, NULL, SHGFP_TYPE_CURRENT, (LPWSTR)(systemBuffer.data()))) < 0)
            return "";
//     } else if (name == "userData" || name == "documents" || name == "downloads" || name == "music" || name == "videos" || name == "pepperFlashSystemPlugin") {
//         std::map<std::string, std::string>::const_iterator it = m_pathMap.find(name);
//         if (it == m_pathMap.end())
//             return "";
//         return it->second;
    } else if (name == "home")
        systemBuffer = getHomeDir().AsUTF16Unsafe();
    else if (name == "temp" || name == "crashDumps") { // 暂时把crashDumps放这
        if (!getTempDir(&path))
            return "";
        systemBuffer = path.AsUTF16Unsafe();
    } else if (name == "userDesktop" || name == "desktop") {
        if (FAILED(SHGetFolderPath(NULL, CSIDL_DESKTOPDIRECTORY, NULL, SHGFP_TYPE_CURRENT, (LPWSTR)(systemBuffer.data()))))
            return "";
    } else if (name == "exe") {
        ::GetModuleFileName(NULL, (LPWSTR)(systemBuffer.data()), MAX_PATH);
    } else if (name == "module") {
        ::GetModuleFileName(NULL, (LPWSTR)(systemBuffer.data()), MAX_PATH);
    } else if (name == "cache" || name == "userCache") {
        if ((::SHGetFolderPath(NULL, CSIDL_APPDATA, NULL, SHGFP_TYPE_CURRENT, (LPWSTR)(systemBuffer.data()))) < 0)
            return "";

        pathBuffer = systemBuffer.c_str();
        pathBuffer += (const char16_t*)mbu16("\\electron");
    } else if (name == "documents") {
        if (!getUserDocumentsDirectory(&path))
            return "";
        systemBuffer = path.AsUTF16Unsafe();
    } else if (name == "music") {
        if (!getUserMusicDirectory(&path))
            return "";
        systemBuffer = path.AsUTF16Unsafe();
    } else if (name == "pictures") {
        if (!getUserPicturesDirectory(&path))
            return "";
        systemBuffer = path.AsUTF16Unsafe();
    } else if (name == "videos") {
        if (!getUserVideosDirectory(&path))
            return "";
        systemBuffer = path.AsUTF16Unsafe();
    } else if (name == "recent") {
        if (!getUserRecentDirectory(&path))
            return "";
        systemBuffer = path.AsUTF16Unsafe();
    } else if (name == "downloads") {
        if (!getUserDownloadsDirectory(&path))
            return "";
        systemBuffer = path.AsUTF16Unsafe();
    } else if (name == "userData") {
        systemBuffer = SessionMgr::get()->getRootDir().AsUTF16Unsafe();
    } else {
        return "";
    }

    pathBuffer = systemBuffer.c_str();
    return base::UTF16ToUTF8(pathBuffer);
}

void App::newFunction(const v8::FunctionCallbackInfo<v8::Value>& args)
{
    v8::Isolate* isolate = args.GetIsolate();
    if (args.IsConstructCall()) {
        new App(isolate, args.This());
        args.GetReturnValue().Set(args.This());
        return;
    }
}

void App::onWindowAllClosed()
{
    if (content::ThreadCall::isUiThread()) {
        emit("window-all-closed");
        return;
    }

    App* self = this;
    content::ThreadCall::callUiThreadAsync(FROM_HERE, [self] { self->emit("window-all-closed"); });
}

v8::Persistent<v8::Function> App::constructor;
gin::WrapperInfo App::kWrapperInfo = { gin::kEmbedderNativeGin };

static void initializeAppApi(v8::Local<v8::Object> target, v8::Local<v8::Value> unused, v8::Local<v8::Context> context, const NodeNative* native)
{
    //node::Environment* env = node::Environment::GetCurrent(context);
    App::init(target, context->GetIsolate());
}

static const char BrowserAppNative[] = "console.log('BrowserAppNative');;";
static NodeNative nativeBrowserAppNative { "App", BrowserAppNative, sizeof(BrowserAppNative) - 1 };

NODE_MODULE_CONTEXT_AWARE_BUILTIN_SCRIPT_MANUAL(electron_browser_app, initializeAppApi, &nativeBrowserAppNative)

}