
#ifndef patch_code_shell_api_xp_h
#define patch_code_shell_api_xp_h

#ifdef SUPPORT_XP_CODE

#include <windows.h>
#include <shellapi.h>
#include <CommCtrl.h>
#include <Shlwapi.h>
#include <KnownFolders.h>
#include <ShlObj.h>

inline HRESULT SHGetPropertyStoreForWindowXp(HWND hwnd, REFIID riid, void** ppv)
{
    typedef HRESULT(WINAPI * PFN_SHGetPropertyStoreForWindow)(HWND hwnd, REFIID riid, void** ppv);
    static PFN_SHGetPropertyStoreForWindow s_SHGetPropertyStoreForWindow = nullptr;

    static bool isInit = false;
    if (isInit) {
        if (!s_SHGetPropertyStoreForWindow)
            return E_FAIL;
    } else {
        HMODULE modHandle = GetModuleHandle(L"SHELL32.dll");
        s_SHGetPropertyStoreForWindow = (PFN_SHGetPropertyStoreForWindow)GetProcAddress(modHandle, "SHGetPropertyStoreForWindow");
    }
    isInit = true;

    if (!s_SHGetPropertyStoreForWindow)
        return E_FAIL;

    return s_SHGetPropertyStoreForWindow(hwnd, riid, ppv);
}

// bool ShowOpenDialogDirectoryXp(HWND owner, const base::string16& title, std::vector<base::FilePath>* paths) {
//   BROWSEINFO bifolder = { 0 };
//   std::vector<WCHAR> file_name;
//   file_name.resize(MAX_PATH);
//   memset(file_name.data(), 0, file_name.size() * sizeof(WCHAR));
//
//   bifolder.hwndOwner = owner;
//   bifolder.pszDisplayName = file_name.data();
//
//   if (!title.empty())
//     bifolder.lpszTitle = title.c_str();
//
//   bifolder.ulFlags = BIF_NEWDIALOGSTYLE | BIF_EDITBOX | BIF_BROWSEINCLUDEFILES;
//
//   LPITEMIDLIST idl = ::SHBrowseForFolder(&bifolder);
//   if (idl == NULL)
//     return FALSE;
//
//   BOOL b = ::SHGetPathFromIDList(idl, file_name.data());
//   if (!b)
//     return false;
//
//   paths->push_back(base::FilePath(file_name.data()));
//   return true;
// }
//
// HRESULT SHOpenWithDialogXp(const HWND hwnd, const OPENASINFO* open_as_info) {
//   const wchar_t* lpszFilename = open_as_info->pcszFile;
//   std::wstring strCmd = L"shell32.dll,OpenAs_RunDLL ";
//   strCmd += lpszFilename;
//
//   const int nRet = (int)::ShellExecuteW(hwnd, L"open", L"Rundll32.exe", strCmd.c_str(), NULL, SW_SHOW);
//   return (nRet > 32) ? S_OK : E_FAIL;
// }

inline HRESULT SHGetKnownFolderPathXp(REFKNOWNFOLDERID rfid, DWORD dw_flags, HANDLE h_token, PWSTR* ppsz_path)
{
    typedef BOOL(WINAPI * PFN_SHGetKnownFolderPath)(REFKNOWNFOLDERID rfid, DWORD dw_flags, HANDLE h_token, PWSTR * ppsz_path);
    static PFN_SHGetKnownFolderPath s_SHGetKnownFolderPath = nullptr;
    static bool s_is_init = false;
    if (!s_is_init) {
        HMODULE modHandle = GetModuleHandle(L"Shell32.dll");
        s_SHGetKnownFolderPath = (PFN_SHGetKnownFolderPath)GetProcAddress(modHandle, "SHGetKnownFolderPath");
        s_is_init = true;
    }

    if (s_SHGetKnownFolderPath)
        return s_SHGetKnownFolderPath(rfid, dw_flags, h_token, ppsz_path);

    // xp_compatible
    wchar_t buffer[MAX_PATH] = { 0 };

    if (FOLDERID_PublicUserTiles == rfid) {
        // csidl = 0x001a;// CSIDL_APPDATA;
    } else if (FOLDERID_ProgramFilesCommon != rfid) {
        // csidl = 0x002b;// CSIDL_PROGRAM_FILES_COMMON;
    } else {
        return E_NOTIMPL;
    }

    HRESULT result = ::SHGetFolderPathW(nullptr, CSIDL_PROGRAM_FILES_COMMON, nullptr, 0, buffer);
    if (!SUCCEEDED(result))
        return result;

    (*ppsz_path) = reinterpret_cast<WCHAR*>(::CoTaskMemAlloc(MAX_PATH));
    if (!(*ppsz_path))
        return E_POINTER;

    if (0 != ::wcscpy_s((*ppsz_path), MAX_PATH, buffer))
        return E_POINTER;

    return S_OK;
}

// inline HRESULT SHGetKnownFolderPathXp(REFKNOWNFOLDERID rfid, DWORD dw_flags, HANDLE h_token, PWSTR* ppsz_path) {
//     typedef BOOL(WINAPI* PFN_SHGetKnownFolderPath)(REFKNOWNFOLDERID rfid, DWORD dw_flags, HANDLE h_token, PWSTR* ppsz_path);
//     static PFN_SHGetKnownFolderPath s_SHGetKnownFolderPath = nullptr;
//     static bool s_is_init = false;
//     if (!s_is_init) {
//         HMODULE modHandle = GetModuleHandle(L"Shell32.dll");
//         s_SHGetKnownFolderPath = (PFN_SHGetKnownFolderPath)GetProcAddress(modHandle, "SHGetKnownFolderPath");
//         s_is_init = true;
//     }
//
//     if (s_SHGetKnownFolderPath)
//         return s_SHGetKnownFolderPath(rfid, dw_flags, h_token, ppsz_path);
//
//     return E_FAIL;
// }

inline HRESULT SHQueryUserNotificationStateXp(QUERY_USER_NOTIFICATION_STATE* pquns)
{
    typedef HRESULT(STDAPICALLTYPE * SHQueryUserNotificationStateFunc)(QUERY_USER_NOTIFICATION_STATE * pquns);
    static SHQueryUserNotificationStateFunc s_SHQueryUserNotificationState = nullptr;
    static bool is_find_func = false;
    if (!is_find_func) {
        HMODULE shell32 = LoadLibraryW(L"Shell32.dll");
        s_SHQueryUserNotificationState = (SHQueryUserNotificationStateFunc)(GetProcAddress(shell32, "SHQueryUserNotificationState"));
        is_find_func = true;
    }

    if (s_SHQueryUserNotificationState)
        return s_SHQueryUserNotificationState(pquns);
    return E_FAIL;
}

inline HRESULT SHCreateItemFromParsingNameXp(PCWSTR pszPath, IBindCtx* pbc, REFIID riid, void** ppv)
{
    typedef HRESULT(STDAPICALLTYPE * SHCreateItemFromParsingNameFunc)(PCWSTR pszPath, IBindCtx * pbc, REFIID riid, void** ppv);
    static SHCreateItemFromParsingNameFunc s_SHCreateItemFromParsingName = nullptr;
    static bool is_find_func = false;
    if (!is_find_func) {
        HMODULE shell32 = LoadLibraryW(L"Shell32.dll");
        s_SHCreateItemFromParsingName = (SHCreateItemFromParsingNameFunc)(GetProcAddress(shell32, "SHCreateItemFromParsingName"));
        is_find_func = true;
    }

    if (s_SHCreateItemFromParsingName)
        return s_SHCreateItemFromParsingName(pszPath, pbc, riid, ppv);
    return E_FAIL;
}

struct XpAppData {
    HWND hwnd;
    UINT uID;
};

inline HRESULT Shell_NotifyIconGetRectXp(const NOTIFYICONIDENTIFIER* notifyIconData, RECT* iconLocation)
{
    RECT emptyRect = { 0, 0, 0, 0 };
    *iconLocation = emptyRect;

    HRESULT hr = E_FAIL;
    TBBUTTON buttonData = { 0 };
    DWORD processID = 0;
    HWND trayHandle = FindWindow(L"Shell_TrayWnd", NULL);

    // find the toolbar used in the notification area
    if (trayHandle) {
        trayHandle = FindWindowEx(trayHandle, NULL, L"TrayNotifyWnd", NULL);
        if (trayHandle) {
            HWND hwnd = FindWindowEx(trayHandle, NULL, L"SysPager", NULL);
            if (hwnd) {
                hwnd = FindWindowEx(hwnd, NULL, L"ToolbarWindow32", NULL);
                if (hwnd)
                    trayHandle = hwnd;
            }
        }
    }

    if (!trayHandle)
        return E_FAIL;

    GetWindowThreadProcessId(trayHandle, &processID);
    if (processID <= 0)
        return E_FAIL;

    HANDLE trayProcess = OpenProcess(PROCESS_VM_OPERATION | PROCESS_VM_READ, 0, processID);
    if (!trayProcess)
        return E_FAIL;

    int buttonCount = SendMessage(trayHandle, TB_BUTTONCOUNT, 0, 0);
    LPVOID data = VirtualAllocEx(trayProcess, NULL, sizeof(TBBUTTON), MEM_COMMIT, PAGE_READWRITE);

    if (buttonCount < 1 || !data) {
        CloseHandle(trayProcess);
        return E_FAIL;
    }

    // search for our icon among all toolbar buttons
    for (int toolbarButton = 0; toolbarButton < buttonCount; ++toolbarButton) {
        SIZE_T numBytes = 0;
        XpAppData appData = { 0, 0 };
        SendMessage(trayHandle, TB_GETBUTTON, (WPARAM)toolbarButton, (LPARAM)data);

        if (!ReadProcessMemory(trayProcess, data, &buttonData, sizeof(TBBUTTON), &numBytes))
            continue;

        if (!ReadProcessMemory(trayProcess, (LPVOID)buttonData.dwData, &appData, sizeof(XpAppData), &numBytes))
            continue;

        BOOL isHidden = buttonData.fsState & TBSTATE_HIDDEN;

        if (notifyIconData->hWnd == appData.hwnd && appData.uID == notifyIconData->uID && !isHidden) {
            SendMessage(trayHandle, TB_GETITEMRECT, (WPARAM)toolbarButton, (LPARAM)data);
            RECT iconRect = { 0, 0, 0, 0 };
            if (ReadProcessMemory(trayProcess, data, &iconRect, sizeof(RECT), &numBytes)) {
                MapWindowPoints(trayHandle, NULL, (LPPOINT)&iconRect, 2);
                RECT geometry = { iconRect.left + 1, iconRect.top + 1, iconRect.right - 1, iconRect.bottom - 1 };
                if (geometry.left < iconRect.right && geometry.top < iconRect.bottom) {
                    *iconLocation = geometry;
                    hr = S_OK;
                }
                break;
            }
        }
    }

    VirtualFreeEx(trayProcess, data, 0, MEM_RELEASE);
    CloseHandle(trayProcess);

    return hr;
}

#else

#define Shell_NotifyIconGetRectXp Shell_NotifyIconGetRect
#define SHCreateItemFromParsingNameXp SHCreateItemFromParsingName
#define SHQueryUserNotificationStateXp SHQueryUserNotificationState
#define SHGetKnownFolderPathXp SHGetKnownFolderPath
#define SHGetPropertyStoreForWindowXp SHGetPropertyStoreForWindow
// #define SHOpenWithDialogXp SHOpenWithDialog

#endif // SUPPORT_XP_CODE
#endif // patch_code_shell_api_h