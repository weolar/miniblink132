
#ifndef patch_code_query_full_process_image_name_h
#define patch_code_query_full_process_image_name_h

#include <windows.h>
#include <tlhelp32.h>
#include <tchar.h>
#include <Psapi.h>
#include <vector>

#ifdef SUPPORT_XP_CODE

inline BOOL DosPathToNtPath(WCHAR* dos_path, WCHAR* nt_path)
{
    std::vector<WCHAR> drive_str(MAX_PATH + 1);
    std::vector<WCHAR> dev_name(MAX_PATH + 1);
    std::vector<WCHAR> dos_path_copy(MAX_PATH + 1);
    WCHAR drive_char[3] = { 0 };
    memset(drive_str.data(), 0, sizeof(WCHAR) * (MAX_PATH + 1));
    memset(dev_name.data(), 0, sizeof(WCHAR) * (MAX_PATH + 1));
    memset(dos_path_copy.data(), 0, sizeof(WCHAR) * (MAX_PATH + 1));

    if (!dos_path)
        return FALSE;

    // wcscpy

    // 获取本地磁盘所有盘符,以'\0'分隔,所以下面 + 4
    if (::GetLogicalDriveStrings(MAX_PATH, drive_str.data())) {
        for (int i = 0; drive_str[i]; i += 4) {
            if (!lstrcmpiW(&(drive_str[i]), L"A:\\") || !lstrcmpi(&(drive_str[i]), L"B:\\"))
                continue; // 从C盘开始

            // 盘符
            drive_char[0] = drive_str[i];
            drive_char[1] = drive_str[i + 1];
            drive_char[2] = L'\0';
            if (!::QueryDosDevice(drive_char, dev_name.data(), MAX_PATH)) // 查询 Dos 设备名(盘符由NT查询DOS)
                return FALSE;

            int dev_name_len = lstrlen(dev_name.data()); // L"\\Device\\HarddiskVolume1"
            int dos_path_len = lstrlen(dos_path); // L"\\Device\\HarddiskVolume11\\Windows\\System32\\taskhost.exe"

            if (dev_name[dev_name_len] != L'\\') {
                dev_name[dev_name_len] = L'\\';
                ++dev_name_len;
            }
            if (dos_path_len <= dev_name_len)
                continue;

            if (_tcsnicmp(dos_path, dev_name.data(), dev_name_len) == 0) { // 是否为此盘
                lstrcpyW(nt_path, drive_char); // 复制驱动器
                lstrcatW(nt_path, L"\\");
                lstrcatW(nt_path, dos_path + dev_name_len); // 复制路径

                return TRUE;
            }
        }
    }

    lstrcpyW(nt_path, dos_path);
    return FALSE;
}

inline DWORD WINAPI GetProcessImageFileNameWXp(HANDLE hProcess, LPWSTR lpImageFileName, DWORD nSize)
{
    typedef BOOL(__stdcall * PFN_GetProcessImageFileNameW)(HANDLE hProcess, LPWSTR lpImageFileName, DWORD nSize);
    static PFN_GetProcessImageFileNameW s_GetProcessImageFileNameW = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE handle = GetModuleHandle(L"Kernel32.dll");
        s_GetProcessImageFileNameW = (PFN_GetProcessImageFileNameW)GetProcAddress(handle, "GetProcessImageFileNameW");

        if (!s_GetProcessImageFileNameW) {
            handle = LoadLibraryW(L"Psapi.dll");
            s_GetProcessImageFileNameW = (PFN_GetProcessImageFileNameW)GetProcAddress(handle, "GetProcessImageFileNameW");
        }
        s_is_init = TRUE;
    }

    if (s_GetProcessImageFileNameW)
        return s_GetProcessImageFileNameW(hProcess, lpImageFileName, nSize);

    return 0;
}

inline BOOL QueryFullProcessImageNameWXp(HANDLE hProcess, DWORD dwFlags, LPWSTR lpExeName, DWORD* lpdwSize)
{
    if (*lpdwSize < MAX_PATH)
        return FALSE;
    if (0 != dwFlags)
        DebugBreak();

    std::vector<WCHAR> image_path(MAX_PATH + 1);
    memset(image_path.data(), 0, sizeof(WCHAR) * (MAX_PATH + 1));

    if (!::GetProcessImageFileNameWXp(hProcess, image_path.data(), MAX_PATH)) {
        ::CloseHandle(hProcess);
        return FALSE;
    }

    std::vector<WCHAR> buf(MAX_PATH + 1);
    memset(buf.data(), 0, sizeof(WCHAR) * (MAX_PATH + 1));
    if (!DosPathToNtPath(image_path.data(), buf.data())) {
        ::CloseHandle(hProcess);
        return FALSE;
    }

    wcscpy(lpExeName, buf.data());

    ::CloseHandle(hProcess);

    return TRUE;
}

#else

#define QueryFullProcessImageNameWXp QueryFullProcessImageNameW
#define GetProcessImageFileNameWXp GetProcessImageFileNameW

#endif // SUPPORT_XP_CODE
#endif // patch_code_query_full_process_image_name_h
