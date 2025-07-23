
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
    fn(electron_browser_browserview) \
    fn(electron_browser_session) \
    fn(electron_browser_webrequest) \
    fn(electron_browser_downloaditem) \
    fn(electron_browser_utility_process) \
    fn(electron_browser_parent_port) \
    fn(electron_browser_web_frame_main) \
    fn(electron_browser_commandline) \
    fn(electron_browser_message_port) \
    fn(electron_browser_safe_storage) 

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
    //MessageBoxA(0, 0, 0, 0);
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