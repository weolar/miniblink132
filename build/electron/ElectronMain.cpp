
#include "electron/common/InitGdiPlus.h"
#include "electron/common/AtomCommandLine.h"
#include "electron/common/NodeThread.h"
#include "electron/common/NodeRegisterHelp.h"
#include "third_party/libnode/src/node.h"
#include "base/command_line.h"

#include <windows.h>
#include <stdlib.h>
#include <ole2.h>

// https://releases.electronjs.org/release/v34.5.8
bool g_isElectronMode = false;

// G:\test\ele_test\electron-api-demos\main.js
// G:\test\web_test\crash\TestUtilityProcess.js
// G:\test\ele_test\utility_process\main.js
// W:\opencode\vscode-main\package.json
// G:\test\ele_test\425429337\app\dist-electron\main\index.js
// G:\test\ele_test\ziniao\app\dist\main.index.js
// G:\test\ele_test\haihai\app\main.js
// G:\test\exe_test\kane.yu\resources\app
// G:\test\exe_test\low_memory\wiredjs\WiredElements_files\main.min.js
// G:\test\web_test\crash\TestUtilityProcess.js

int wmainNode(int argc, wchar_t* wargv[]);

NODE_MODULE_INIT(/* exports, module, context */)
{
    v8::Isolate* isolate = context->GetIsolate();
    DebugBreak();

    //     AddEnvironmentCleanupHook(isolate, sanity_check, nullptr);
    //     AddEnvironmentCleanupHook(isolate, cleanup_cb2, cookie);
    //     AddEnvironmentCleanupHook(isolate, cleanup_cb1, isolate);
}

namespace atom {

#define NODE_MODULE_CONTEXT_AWARE_BUILTIN_SCRIPT_REG_IN_MAIN(fn) \
    fn(electron_browser_web_contents) \
    fn(electron_browser_app) \
    fn(electron_browser_electron) \
    fn(electron_browser_browserwindow) \
    fn(electron_browser_menu) \
    fn(electron_browser_dialog) \
    fn(electron_browser_protocol) \
    fn(electron_browser_tray) \
    fn(electron_renderer_ipc) \
    fn(electron_common_v8_util) \
    fn(electron_common_shell) \
    fn(electron_common_original_fs) \
    fn(electron_common_screen) \
    fn(electron_renerer_webframe) \
    fn(electron_renderer_contextbridge) \
    fn(electron_common_intl_collator) \
    fn(electron_common_asar) \
    fn(electron_common_nativeImage) \
    fn(electron_common_clipboard) \
    fn(electron_common_features) \
    fn(electron_browser_browserview) \
    fn(electron_browser_session) \
    fn(electron_browser_webrequest) \
    fn(electron_browser_downloaditem) \
    fn(electron_browser_utility_process) \
    fn(electron_browser_parent_port) \
    fn(electron_browser_web_frame_main) \
    fn(electron_browser_commandline) \
    fn(electron_browser_message_port) \
    fn(electron_browser_safe_storage) \
    fn(electron_browser_powermonitor)

NODE_MODULE_CONTEXT_AWARE_BUILTIN_SCRIPT_REG_IN_MAIN(NODE_MODULE_CONTEXT_AWARE_BUILTIN_SCRIPT_DECLARE_IN_MAIN)

static void registerNodeMod()
{
    NODE_MODULE_CONTEXT_AWARE_BUILTIN_SCRIPT_REG_IN_MAIN(NODE_MODULE_CONTEXT_AWARE_BUILTIN_SCRIPT_DEFINDE_IN_MAIN)
}

} // atom

namespace content {
void initV8Data();
}

// void readFile(const wchar_t* path, std::vector<char>* buffer)
// {
//     HANDLE hFile = CreateFileW(path, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
//     if (INVALID_HANDLE_VALUE == hFile) {
//         DebugBreak();
//         return;
//     }
// 
//     DWORD fileSizeHigh;
//     const DWORD bufferSize = ::GetFileSize(hFile, &fileSizeHigh);
//     if (0 == bufferSize)
//         return;
// 
//     DWORD numberOfBytesRead = 0;
//     buffer->resize(bufferSize);
//     BOOL b = ::ReadFile(hFile, &buffer->at(0), bufferSize, &numberOfBytesRead, nullptr);
//     ::CloseHandle(hFile);
//     b = b;
// }

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{
//     std::wstring cmdline = L"cmd.exe /k \"W:\\mycode\\mb132\\out\\win_Debug_x64\\resources\\extras\\clink\\clink_x64.exe\" --inject";
//     std::unique_ptr<wchar_t[]> mutableCommandline = std::make_unique<wchar_t[]>(cmdline.length() + 1);
//     memcpy(mutableCommandline.get(), cmdline.c_str(), cmdline.length() * 2);
// 
//     std::wstring cwd = L"C:\\Users\\wang";
// 
//     LPWSTR envArg = L"ALLUSERSPROFILE=C:\\ProgramData";
//     std::unique_ptr<wchar_t[]> mutableCwd = std::make_unique<wchar_t[]>(cwd.length() + 1);
//     memcpy(mutableCwd.get(), cwd.c_str(), cwd.length() * 2);
// 
//     STARTUPINFOEXW siEx = { 0 };
//     siEx.StartupInfo.cb = sizeof(STARTUPINFOEXW);
//     siEx.StartupInfo.dwFlags |= STARTF_USESTDHANDLES;
//     siEx.StartupInfo.hStdError = nullptr;
//     siEx.StartupInfo.hStdInput = nullptr;
//     siEx.StartupInfo.hStdOutput = nullptr;
// 
//     PROCESS_INFORMATION piClient = {0};
//     BOOL fSuccess = !!CreateProcessW(nullptr, 
//         mutableCommandline.get(),
//         nullptr, // lpProcessAttributes
//         nullptr, // lpThreadAttributes
//         false, // bInheritHandles VERY IMPORTANT that this is false
//         EXTENDED_STARTUPINFO_PRESENT | CREATE_UNICODE_ENVIRONMENT, // dwCreationFlags
//         nullptr, // envArg, // lpEnvironment
//         mutableCwd.get(), // lpCurrentDirectory
//         &siEx.StartupInfo, // lpStartupInfo
//         &piClient // lpProcessInformation
//     );
// 
//     WaitForSingleObject(piClient.hProcess, INFINITE);
    ///

    g_isElectronMode = true;
    ::OleInitialize(nullptr);
    atom::initGDIPlusClsids();
    atom::AtomCommandLine::initAW();
    base::CommandLine::Init(0, nullptr);
    atom::registerNodeMod();

    content::initV8Data();

    //searchHex(hInstance);

    //wmainNode(__argc, __wargv);
    [[maybe_unused]] atom::NodeArgc* node = atom::runNodeThread();

    return 0;
}
