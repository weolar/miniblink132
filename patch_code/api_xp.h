
#ifndef patch_code_xp_api_h
#define patch_code_xp_api_h

#ifdef SUPPORT_XP_CODE

#include <windows.h>
#include <shellapi.h>
#include <Psapi.h>

inline BOOL CloseTouchInputHandleXp(void* hTouchInput)
{
    typedef BOOL(WINAPI * PFN_CloseTouchInputHandle)(void* hTouchInput);
    static PFN_CloseTouchInputHandle s_CloseTouchInputHandle;
    static BOOL s_is_init = FALSE;

    if (!s_is_init) {
        HMODULE handle = GetModuleHandle(L"User32.dll");
        s_CloseTouchInputHandle = (PFN_CloseTouchInputHandle)(GetProcAddress(handle, "CloseTouchInputHandle"));
        s_is_init = TRUE;
    }
    if (s_CloseTouchInputHandle)
        return s_CloseTouchInputHandle(hTouchInput);

    return FALSE;
}

inline int GetUserDefaultLocaleNameXp(LPWSTR lpLocaleName, int cchLocaleName)
{
    typedef int(WINAPI * PFN_GetUserDefaultLocaleName)(LPWSTR lpLocaleName, int cchLocaleName);

    static PFN_GetUserDefaultLocaleName s_GetUserDefaultLocaleName = nullptr;
    static bool s_isInit = false;
    if (s_isInit && !s_GetUserDefaultLocaleName)
        return 0;

    if (!s_GetUserDefaultLocaleName) {
        s_isInit = true;

        HMODULE kernel32_dll = ::GetModuleHandle(L"Kernel32.dll");
        s_GetUserDefaultLocaleName = reinterpret_cast<PFN_GetUserDefaultLocaleName>(GetProcAddress(kernel32_dll, "GetUserDefaultLocaleName"));
    }
    if (!s_GetUserDefaultLocaleName)
        return 0;
    return s_GetUserDefaultLocaleName(lpLocaleName, cchLocaleName);
}

inline LONG RegDeleteKeyExXp(HKEY hKey, const wchar_t* lpSubKey, REGSAM samDesired, DWORD Reserved)
{
    typedef LSTATUS(WINAPI * RegDeleteKeyExPtr)(HKEY, LPCWSTR, REGSAM, DWORD);

    RegDeleteKeyExPtr reg_delete_key_ex_func = (RegDeleteKeyExPtr)(GetProcAddress(GetModuleHandleA("advapi32.dll"), "RegDeleteKeyExW"));

    if (reg_delete_key_ex_func)
        return reg_delete_key_ex_func(hKey, lpSubKey, samDesired, Reserved);

    // Windows XP does not support RegDeleteKeyEx, so fallback to RegDeleteKey.
    return RegDeleteKey(hKey, lpSubKey);
}

inline DWORD GetCurrentProcessorNumberXp()
{
    typedef DWORD(__stdcall * PFN_GetCurrentProcessorNumber)();
    static PFN_GetCurrentProcessorNumber s_GetCurrentProcessorNumber = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE handle = GetModuleHandle(L"User32.dll");
        s_GetCurrentProcessorNumber = (PFN_GetCurrentProcessorNumber)GetProcAddress(handle, "GetCurrentProcessorNumber");
        s_is_init = TRUE;
    }

    if (s_GetCurrentProcessorNumber)
        return s_GetCurrentProcessorNumber();

#if !defined(_WIN64)
    _asm { mov eax, 1}
    _asm
    {
        cpuid
    }
    _asm { shr ebx, 24}
    _asm
    {
        mov eax, ebx
    }
#endif
    return 0;
}

inline BOOL GetProductInfoXp(DWORD dwOSMajorVersion, DWORD dwOSMinorVersion, DWORD dwSpMajorVersion, DWORD dwSpMinorVersion, PDWORD pdwReturnedProductType)
{
    typedef BOOL(__stdcall * PFN_GetProductInfo)(
        DWORD dwOSMajorVersion, DWORD dwOSMinorVersion, DWORD dwSpMajorVersion, DWORD dwSpMinorVersion, PDWORD pdwReturnedProductType);
    static PFN_GetProductInfo s_GetProductInfo = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE handle = GetModuleHandle(L"User32.dll");
        s_GetProductInfo = (PFN_GetProductInfo)GetProcAddress(handle, "GetProductInfo");
        s_is_init = TRUE;
    }

    if (s_GetProductInfo)
        return s_GetProductInfo(dwOSMajorVersion, dwOSMinorVersion, dwSpMajorVersion, dwSpMinorVersion, pdwReturnedProductType);

    *pdwReturnedProductType = (DWORD)-1;
    return FALSE;
}

inline BOOL SetProcessDPIAwareXp()
{
    typedef BOOL(__stdcall * PFN_SetProcessDPIAware)();
    static PFN_SetProcessDPIAware s_SetProcessDPIAware = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE handle = GetModuleHandle(L"User32.dll");
        s_SetProcessDPIAware = (PFN_SetProcessDPIAware)GetProcAddress(handle, "SetProcessDPIAware");
        s_is_init = TRUE;
    }

    if (s_SetProcessDPIAware)
        return s_SetProcessDPIAware();

    return FALSE;
}

inline POWER_PLATFORM_ROLE PowerDeterminePlatformRoleExXp(ULONG Version)
{
    typedef POWER_PLATFORM_ROLE(__stdcall * PFN_PowerDeterminePlatformRoleEx)(ULONG Version);
    static PFN_PowerDeterminePlatformRoleEx s_PowerDeterminePlatformRoleEx = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE handle = GetModuleHandle(L"Powrprof.dll");
        if (!handle)
            handle = LoadLibraryW(L"Powrprof.dll");
        s_PowerDeterminePlatformRoleEx = (PFN_PowerDeterminePlatformRoleEx)GetProcAddress(handle, "PowerDeterminePlatformRoleEx");
        s_is_init = TRUE;
    }

    if (s_PowerDeterminePlatformRoleEx)
        return s_PowerDeterminePlatformRoleEx(Version);

    return PlatformRoleDesktop;
}

inline BOOL RegisterTouchWindowXp(HWND hwnd, ULONG ulFlags)
{
    typedef BOOL(WINAPI * PFN_RegisterTouchWindow)(HWND hwnd, ULONG ulFlags);
    static PFN_RegisterTouchWindow s_RegisterTouchWindow = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE handle = GetModuleHandle(L"User32.dll");
        s_RegisterTouchWindow = (PFN_RegisterTouchWindow)(GetProcAddress(handle, "RegisterTouchWindow"));
        s_is_init = TRUE;
    }

    if (!s_RegisterTouchWindow)
        return FALSE;

    return s_RegisterTouchWindow(hwnd, ulFlags);
}

inline LONG DisplayConfigGetDeviceInfoXp(void* requestPacket)
{
    typedef LONG(WINAPI * PFN_DisplayConfigGetDeviceInfo)(void* requestPacket);
    static PFN_DisplayConfigGetDeviceInfo s_DisplayConfigGetDeviceInfo = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE handle = GetModuleHandle(L"User32.dll");
        s_DisplayConfigGetDeviceInfo = (PFN_DisplayConfigGetDeviceInfo)(GetProcAddress(handle, "DisplayConfigGetDeviceInfo"));
        s_is_init = TRUE;
    }

    if (!s_DisplayConfigGetDeviceInfo)
        return E_FAIL;

    return s_DisplayConfigGetDeviceInfo(requestPacket);
}

inline LONG GetDisplayConfigBufferSizesXp(UINT32 flags, UINT32* numPathArrayElements, UINT32* numModeInfoArrayElements)
{
    typedef LONG(WINAPI * PFN_GetDisplayConfigBufferSizes)(UINT32 flags, UINT32 * numPathArrayElements, UINT32 * numModeInfoArrayElements);
    static PFN_GetDisplayConfigBufferSizes s_GetDisplayConfigBufferSizes = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE handle = GetModuleHandle(L"User32.dll");
        s_GetDisplayConfigBufferSizes = (PFN_GetDisplayConfigBufferSizes)(GetProcAddress(handle, "GetDisplayConfigBufferSizes"));
        s_is_init = TRUE;
    }

    if (!s_GetDisplayConfigBufferSizes)
        return E_FAIL;

    return s_GetDisplayConfigBufferSizes(flags, numPathArrayElements, numModeInfoArrayElements);
}

inline LONG QueryDisplayConfigXp(
    UINT32 flags, UINT32* numPathArrayElements, void* pathArray, UINT32* numModeInfoArrayElements, void* modeInfoArray, void* currentTopologyId)
{
    typedef LONG(WINAPI * PFN_QueryDisplayConfig)(
        UINT32 flags, UINT32 * numPathArrayElements, void* pathArray, UINT32* numModeInfoArrayElements, void* modeInfoArray, void* currentTopologyId);
    static PFN_QueryDisplayConfig s_QueryDisplayConfig = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE handle = GetModuleHandle(L"User32.dll");
        s_QueryDisplayConfig = (PFN_QueryDisplayConfig)(GetProcAddress(handle, "QueryDisplayConfig"));
        s_is_init = TRUE;
    }

    if (!s_QueryDisplayConfig)
        return E_FAIL;

    return s_QueryDisplayConfig(flags, numPathArrayElements, pathArray, numModeInfoArrayElements, modeInfoArray, currentTopologyId);
}

inline BOOL ChangeWindowMessageFilterExXp(HWND hwnd, UINT message, DWORD action, void* pChangeFilterStruct)
{
    typedef BOOL(WINAPI * PFN_ChangeWindowMessageFilterEx)(HWND hwnd, UINT message, DWORD action, void* pChangeFilterStruct);
    static PFN_ChangeWindowMessageFilterEx s_ChangeWindowMessageFilterEx = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE user32 = GetModuleHandle(L"User32.dll");
        s_ChangeWindowMessageFilterEx = (PFN_ChangeWindowMessageFilterEx)GetProcAddress(user32, "ChangeWindowMessageFilterEx");
        s_is_init = TRUE;
    }

    if (s_ChangeWindowMessageFilterEx)
        return s_ChangeWindowMessageFilterEx(hwnd, message, action, pChangeFilterStruct);
    return FALSE;
}

inline BOOL ChangeWindowMessageFilterXp(UINT message, DWORD dwFlag)
{
    typedef BOOL(__stdcall * PFN_ChangeWindowMessageFilter)(UINT message, DWORD dwFlag);
    static PFN_ChangeWindowMessageFilter s_ChangeWindowMessageFilter = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE handle = GetModuleHandle(L"User32.dll");
        s_ChangeWindowMessageFilter = (PFN_ChangeWindowMessageFilter)GetProcAddress(handle, "ChangeWindowMessageFilter");
        s_is_init = TRUE;
    }

    if (s_ChangeWindowMessageFilter)
        return s_ChangeWindowMessageFilter(message, dwFlag);
    return FALSE;
}

inline BOOL SetWindowDisplayAffinityXp(HWND hWnd, DWORD dwAffinity)
{
    typedef BOOL(WINAPI * PFN_SetWindowDisplayAffinity)(HWND hWnd, DWORD dwAffinity);
    static PFN_SetWindowDisplayAffinity s_SetWindowDisplayAffinity = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE user32 = GetModuleHandle(L"User32.dll");
        s_SetWindowDisplayAffinity = (PFN_SetWindowDisplayAffinity)GetProcAddress(user32, "SetWindowDisplayAffinity");
        s_is_init = TRUE;
    }

    if (s_SetWindowDisplayAffinity)
        return s_SetWindowDisplayAffinity(hWnd, dwAffinity);
    return FALSE;
}

inline BOOL CancelIoExXp(HANDLE hFile, LPOVERLAPPED lpOverlapped)
{
    typedef BOOL(WINAPI * PFN_CancelIoEx)(HANDLE hFile, LPOVERLAPPED lpOverlapped);
    static PFN_CancelIoEx s_CancelIoEx = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE kernel32 = GetModuleHandle(L"Kernel32.dll");
        s_CancelIoEx = (PFN_CancelIoEx)GetProcAddress(kernel32, "CancelIoEx");
        s_is_init = TRUE;
    }

    if (s_CancelIoEx)
        return s_CancelIoEx(hFile, lpOverlapped);

    return CancelIo(hFile);
}

inline BOOL CancelSynchronousIoXp(HANDLE hThread)
{
    typedef BOOL(WINAPI * PFN_CancelSynchronousIo)(HANDLE hThread);
    static PFN_CancelSynchronousIo s_CancelSynchronousIo = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE kernel32 = GetModuleHandle(L"Kernel32.dll");
        s_CancelSynchronousIo = (PFN_CancelSynchronousIo)GetProcAddress(kernel32, "CancelSynchronousIo");
        s_is_init = TRUE;
    }

    if (s_CancelSynchronousIo)
        return s_CancelSynchronousIo(hThread);

    return FALSE;
}

inline BOOL EnumSystemLocalesExXp(LOCALE_ENUMPROCEX lpLocaleEnumProcEx, DWORD dwFlags, LPARAM lParam, LPVOID lpReserved)
{
    typedef BOOL(WINAPI * PFN_EnumSystemLocalesEx)(LOCALE_ENUMPROCEX lpLocaleEnumProcEx, DWORD dwFlags, LPARAM lParam, LPVOID lpReserved);
    static PFN_EnumSystemLocalesEx s_EnumSystemLocalesEx = NULL;
    static BOOL s_is_init = FALSE;
    if (s_is_init && !s_EnumSystemLocalesEx)
        return FALSE;

    if (!s_EnumSystemLocalesEx) {
        s_is_init = TRUE;
        HMODULE modHandle = GetModuleHandle(L"Kernel32.dll");
        s_EnumSystemLocalesEx = (PFN_EnumSystemLocalesEx)GetProcAddress(modHandle, "EnumSystemLocalesEx");
    }
    if (s_EnumSystemLocalesEx)
        return s_EnumSystemLocalesEx(lpLocaleEnumProcEx, dwFlags, lParam, lpReserved);
    return FALSE;
}

inline HANDLE PowerCreateRequestXp(PREASON_CONTEXT Context)
{
    typedef HANDLE(__stdcall * PFN_PowerCreateRequest)(PREASON_CONTEXT Context);
    static PFN_PowerCreateRequest s_PowerCreateRequest = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE handle = GetModuleHandle(L"Kernel32.dll");
        s_PowerCreateRequest = (PFN_PowerCreateRequest)GetProcAddress(handle, "PowerCreateRequest");
        s_is_init = TRUE;
    }

    if (s_PowerCreateRequest)
        return s_PowerCreateRequest(Context);

    return INVALID_HANDLE_VALUE;
}

inline BOOL PowerClearRequestXp(HANDLE PowerRequest, POWER_REQUEST_TYPE RequestType)
{
    typedef BOOL(__stdcall * PFN_PowerClearRequest)(HANDLE PowerRequest, POWER_REQUEST_TYPE RequestType);
    static PFN_PowerClearRequest s_PowerClearRequest = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE handle = GetModuleHandle(L"Kernel32.dll");
        s_PowerClearRequest = (PFN_PowerClearRequest)GetProcAddress(handle, "PowerClearRequest");
        s_is_init = TRUE;
    }

    if (s_PowerClearRequest)
        return s_PowerClearRequest(PowerRequest, RequestType);

    return FALSE;
}

inline BOOL PowerSetRequestXp(HANDLE PowerRequest, POWER_REQUEST_TYPE RequestType)
{
    typedef BOOL(__stdcall * PFN_PowerSetRequest)(HANDLE PowerRequest, POWER_REQUEST_TYPE RequestType);
    static PFN_PowerSetRequest s_PowerSetRequest = NULL;

    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE handle = GetModuleHandle(L"Kernel32.dll");
        s_PowerSetRequest = (PFN_PowerSetRequest)GetProcAddress(handle, "PowerSetRequest");
        s_is_init = TRUE;
    }

    if (s_PowerSetRequest)
        return s_PowerSetRequest(PowerRequest, RequestType);

    return FALSE;
}

typedef BOOL(__stdcall* PFN_QueryThreadCycleTime)(HANDLE ThreadHandle, PULONG64 CycleTime);
static PFN_QueryThreadCycleTime s_QueryThreadCycleTime = NULL;

inline BOOL QueryThreadCycleTimeIsLoaded()
{
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE handle = GetModuleHandle(L"Kernel32.dll");
        s_QueryThreadCycleTime = (PFN_QueryThreadCycleTime)GetProcAddress(handle, "QueryThreadCycleTime");
        s_is_init = TRUE;
    }
    return NULL != s_QueryThreadCycleTime;
}

inline BOOL QueryThreadCycleTimeXp(HANDLE ThreadHandle, PULONG64 CycleTime)
{
    if (QueryThreadCycleTimeIsLoaded())
        return s_QueryThreadCycleTime(ThreadHandle, CycleTime);

    return FALSE;
}

inline BOOL QueryUnbiasedInterruptTimeXp(PULONGLONG UnbiasedTime)
{
    typedef BOOL(__stdcall * PFN_QueryUnbiasedInterruptTime)(PULONGLONG UnbiasedTime);
    static PFN_QueryUnbiasedInterruptTime s_QueryUnbiasedInterruptTime = NULL;

    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE handle = GetModuleHandle(L"Kernel32.dll");
        s_QueryUnbiasedInterruptTime = (PFN_QueryUnbiasedInterruptTime)GetProcAddress(handle, "QueryUnbiasedInterruptTime");
        s_is_init = TRUE;
    }

    *UnbiasedTime = 0;
    if (s_QueryUnbiasedInterruptTime)
        return s_QueryUnbiasedInterruptTime(UnbiasedTime);

    return FALSE;
}

inline BOOL GetModuleInformationXp(HANDLE hProcess, HMODULE hModule, void* lpmodinfo, DWORD cb)
{
    typedef BOOL(__stdcall * PFN_GetModuleInformation)(HANDLE hProcess, HMODULE hModule, void* lpmodinfo, DWORD cb);
    static PFN_GetModuleInformation s_GetModuleInformation = NULL;

    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE handle = GetModuleHandle(L"Kernel32.dll");
        s_GetModuleInformation = (PFN_GetModuleInformation)GetProcAddress(handle, "GetModuleInformation");
        if (!s_GetModuleInformation) {
            handle = LoadLibraryW(L"psapi.dll");
            s_GetModuleInformation = (PFN_GetModuleInformation)GetProcAddress(handle, "GetModuleInformation");
        }
        s_is_init = TRUE;
    }

    if (s_GetModuleInformation)
        return s_GetModuleInformation(hProcess, hModule, lpmodinfo, cb);

    return FALSE;
}

inline BOOL GetPerformanceInfoXp(void* pPerformanceInformation, DWORD cb)
{
    typedef BOOL(__stdcall * PFN_GetPerformanceInfo)(void* pPerformanceInformation, DWORD cb);
    static PFN_GetPerformanceInfo s_GetPerformanceInfo = NULL;

    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE handle = GetModuleHandle(L"Kernel32.dll");
        s_GetPerformanceInfo = (PFN_GetPerformanceInfo)GetProcAddress(handle, "GetPerformanceInfo");
        if (!s_GetPerformanceInfo) {
            handle = LoadLibraryW(L"psapi.dll");
            s_GetPerformanceInfo = (PFN_GetPerformanceInfo)GetProcAddress(handle, "GetPerformanceInfo");
        }
        s_is_init = TRUE;
    }

    if (s_GetPerformanceInfo)
        return s_GetPerformanceInfo(pPerformanceInformation, cb);

    return FALSE;
}

inline BOOL GetProcessMemoryInfoXp(HANDLE Process, void* ppsmemCounters, DWORD cb)
{
    typedef BOOL(__stdcall * PFN_GetProcessMemoryInfo)(HANDLE Process, void* ppsmemCounters, DWORD cb);
    static PFN_GetProcessMemoryInfo s_GetProcessMemoryInfo = NULL;

    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE handle = GetModuleHandle(L"Kernel32.dll");
        s_GetProcessMemoryInfo = (PFN_GetProcessMemoryInfo)GetProcAddress(handle, "GetProcessMemoryInfo");
        if (!s_GetProcessMemoryInfo) {
            handle = LoadLibraryW(L"Psapi.dll");
            s_GetProcessMemoryInfo = (PFN_GetProcessMemoryInfo)GetProcAddress(handle, "GetProcessMemoryInfo");
        }
        s_is_init = TRUE;
    }

    if (s_GetProcessMemoryInfo)
        return s_GetProcessMemoryInfo(Process, ppsmemCounters, cb);

    return FALSE;
}

inline BOOL QueryWorkingSetExXp(HANDLE hProcess, PVOID pv, DWORD cb)
{
    typedef BOOL(__stdcall * PFN_QueryWorkingSetEx)(HANDLE hProcess, PVOID pv, DWORD cb);
    static PFN_QueryWorkingSetEx s_QueryWorkingSetEx = NULL;

    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE handle = GetModuleHandle(L"Kernel32.dll");
        s_QueryWorkingSetEx = (PFN_QueryWorkingSetEx)GetProcAddress(handle, "QueryWorkingSetEx");
        if (!s_QueryWorkingSetEx) {
            handle = LoadLibraryW(L"Psapi.dll");
            s_QueryWorkingSetEx = (PFN_QueryWorkingSetEx)GetProcAddress(handle, "QueryWorkingSetEx");
        }
        s_is_init = TRUE;
    }

    if (s_QueryWorkingSetEx)
        return s_QueryWorkingSetEx(hProcess, pv, cb);

    return FALSE;
}

inline BOOL DwmDefWindowProcXp(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam, LRESULT* plResult)
{
    typedef BOOL(__stdcall * PFN_DwmDefWindowProc)(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam, LRESULT * plResult);
    static PFN_DwmDefWindowProc s_DwmDefWindowProc = NULL;

    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE handle = LoadLibraryW(L"DWMAPI.dll");
        if (handle)
            s_DwmDefWindowProc = (PFN_DwmDefWindowProc)GetProcAddress(handle, "DwmDefWindowProc");
        s_is_init = TRUE;
    }

    if (s_DwmDefWindowProc)
        return s_DwmDefWindowProc(hWnd, msg, wParam, lParam, plResult);

    return FALSE;
}

inline HRESULT DwmExtendFrameIntoClientAreaXp(HWND hWnd, const void* pMarInset)
{
    typedef HRESULT(__stdcall * PFN_DwmExtendFrameIntoClientArea)(HWND hWnd, const void* pMarInset);
    static PFN_DwmExtendFrameIntoClientArea s_DwmExtendFrameIntoClientArea = NULL;

    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE handle = LoadLibraryW(L"DWMAPI.dll");
        if (handle)
            s_DwmExtendFrameIntoClientArea = (PFN_DwmExtendFrameIntoClientArea)GetProcAddress(handle, "DwmExtendFrameIntoClientArea");
        s_is_init = TRUE;
    }

    if (s_DwmExtendFrameIntoClientArea)
        return s_DwmExtendFrameIntoClientArea(hWnd, pMarInset);

    return E_FAIL;
}

inline HRESULT DwmGetColorizationColorXp(DWORD* pcrColorization, BOOL* pfOpaqueBlend)
{
    typedef HRESULT(__stdcall * PFN_DwmGetColorizationColor)(DWORD * pcrColorization, BOOL * pfOpaqueBlend);
    static PFN_DwmGetColorizationColor s_DwmGetColorizationColor = NULL;

    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE handle = LoadLibraryW(L"DWMAPI.dll");
        if (handle)
            s_DwmGetColorizationColor = (PFN_DwmGetColorizationColor)GetProcAddress(handle, "DwmGetColorizationColor");
        s_is_init = TRUE;
    }

    if (s_DwmGetColorizationColor)
        return s_DwmGetColorizationColor(pcrColorization, pfOpaqueBlend);

    return E_FAIL;
}

inline HRESULT DwmGetCompositionTimingInfoXp(HWND hwnd, void* pTimingInfo)
{
    typedef HRESULT(__stdcall * PFN_DwmGetCompositionTimingInfo)(HWND hwnd, void* pTimingInfo);
    static PFN_DwmGetCompositionTimingInfo s_DwmGetCompositionTimingInfo = NULL;

    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE handle = LoadLibraryW(L"DWMAPI.dll");
        if (handle)
            s_DwmGetCompositionTimingInfo = (PFN_DwmGetCompositionTimingInfo)GetProcAddress(handle, "DwmGetCompositionTimingInfo");
        s_is_init = TRUE;
    }

    if (s_DwmGetCompositionTimingInfo)
        return s_DwmGetCompositionTimingInfo(hwnd, pTimingInfo);

    return E_FAIL;
}

inline HRESULT DwmIsCompositionEnabledXp(BOOL* pfEnabled)
{
    typedef HRESULT(__stdcall * PFN_DwmIsCompositionEnabled)(BOOL * pfEnabled);
    static PFN_DwmIsCompositionEnabled s_DwmIsCompositionEnabled = NULL;

    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE handle = LoadLibraryW(L"DWMAPI.dll");
        if (handle)
            s_DwmIsCompositionEnabled = (PFN_DwmIsCompositionEnabled)GetProcAddress(handle, "DwmIsCompositionEnabled");
        s_is_init = TRUE;
    }

    if (s_DwmIsCompositionEnabled)
        return s_DwmIsCompositionEnabled(pfEnabled);

    *pfEnabled = FALSE;
    return E_FAIL;
}

inline HRESULT DwmSetWindowAttributeXp(HWND hwnd, DWORD dwAttribute, LPCVOID pvAttribute, DWORD cbAttribute)
{
    typedef HRESULT(__stdcall * PFN_DwmSetWindowAttribute)(HWND hwnd, DWORD dwAttribute, LPCVOID pvAttribute, DWORD cbAttribute);
    static PFN_DwmSetWindowAttribute s_DwmSetWindowAttribute = NULL;

    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE handle = LoadLibraryW(L"DWMAPI.dll");
        if (handle)
            s_DwmSetWindowAttribute = (PFN_DwmSetWindowAttribute)GetProcAddress(handle, "DwmSetWindowAttribute");
        s_is_init = TRUE;
    }

    if (s_DwmSetWindowAttribute)
        return s_DwmSetWindowAttribute(hwnd, dwAttribute, pvAttribute, cbAttribute);

    return E_FAIL;
}

inline HRESULT DwmGetWindowAttributeXp(HWND hwnd, DWORD dwAttribute, PVOID pvAttribute, DWORD cbAttribute)
{
    typedef HRESULT(__stdcall * PFN_DwmGetWindowAttribute)(HWND hwnd, DWORD dwAttribute, PVOID pvAttribute, DWORD cbAttribute);
    static PFN_DwmGetWindowAttribute s_DwmGetWindowAttribute = NULL;

    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE handle = LoadLibraryW(L"DWMAPI.dll");
        if (handle)
            s_DwmGetWindowAttribute = (PFN_DwmGetWindowAttribute)GetProcAddress(handle, "DwmGetWindowAttribute");
        s_is_init = TRUE;
    }

    if (s_DwmGetWindowAttribute)
        return s_DwmGetWindowAttribute(hwnd, dwAttribute, pvAttribute, cbAttribute);

    return E_FAIL;
}

inline HRESULT SetCurrentProcessExplicitAppUserModelIDXp(PCWSTR AppID)
{
    typedef BOOL(WINAPI * PFN_SetCurrentProcessExplicitAppUserModelID)(PCWSTR AppID);
    static PFN_SetCurrentProcessExplicitAppUserModelID s_SetCurrentProcessExplicitAppUserModelIDXp = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE handle = GetModuleHandle(L"Shell32.dll");
        s_SetCurrentProcessExplicitAppUserModelIDXp
            = (PFN_SetCurrentProcessExplicitAppUserModelID)GetProcAddress(handle, "SetCurrentProcessExplicitAppUserModelID");
        s_is_init = TRUE;
    }

    if (s_SetCurrentProcessExplicitAppUserModelIDXp)
        return s_SetCurrentProcessExplicitAppUserModelIDXp(AppID);
    return E_FAIL;
}

inline HRESULT GetCurrentProcessExplicitAppUserModelIDXp(PWSTR* AppID)
{
    typedef HRESULT(WINAPI * PFN_GetCurrentProcessExplicitAppUserModelID)(PWSTR * AppID);
    static PFN_GetCurrentProcessExplicitAppUserModelID s_GetCurrentProcessExplicitAppUserModelID;
    static BOOL s_is_init = FALSE;

    if (!s_is_init) {
        HMODULE handle = GetModuleHandle(L"shell32.dll");
        s_GetCurrentProcessExplicitAppUserModelID
            = (PFN_GetCurrentProcessExplicitAppUserModelID)(GetProcAddress(handle, "GetCurrentProcessExplicitAppUserModelID"));
        s_is_init = TRUE;
    }
    if (s_GetCurrentProcessExplicitAppUserModelID)
        return s_GetCurrentProcessExplicitAppUserModelID(AppID);

    return E_FAIL;
}

inline BOOLEAN CreateSymbolicLinkWXp(LPCWSTR lpSymlinkFileName, LPCWSTR lpTargetFileName, DWORD dwFlags)
{
    typedef BOOLEAN(WINAPI * PFN_CreateSymbolicLinkW)(LPCWSTR lpSymlinkFileName, LPCWSTR lpTargetFileName, DWORD dwFlags);
    static PFN_CreateSymbolicLinkW s_CreateSymbolicLinkWXp = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE modHandle = GetModuleHandle(L"Kernel32.dll");
        s_CreateSymbolicLinkWXp = (PFN_CreateSymbolicLinkW)GetProcAddress(modHandle, "CreateSymbolicLinkW");
        s_is_init = TRUE;
    }

    if (s_CreateSymbolicLinkWXp)
        return s_CreateSymbolicLinkWXp(lpSymlinkFileName, lpTargetFileName, dwFlags);
    return FALSE;
}

inline DWORD GetFinalPathNameByHandleWXp(HANDLE hFile, LPWSTR lpszFilePath, DWORD cchFilePath, DWORD dwFlags)
{
    typedef DWORD(WINAPI * PFN_GetFinalPathNameByHandleW)(HANDLE hFile, LPWSTR lpszFilePath, DWORD cchFilePath, DWORD dwFlags);
    static PFN_GetFinalPathNameByHandleW s_GetFinalPathNameByHandleW;
    static BOOL s_is_init = FALSE;

    if (!s_is_init) {
        HMODULE handle = GetModuleHandle(L"Kernel32.dll");
        s_GetFinalPathNameByHandleW = (PFN_GetFinalPathNameByHandleW)(GetProcAddress(handle, "GetFinalPathNameByHandleW"));
        s_is_init = TRUE;
    }
    if (s_GetFinalPathNameByHandleW)
        return s_GetFinalPathNameByHandleW(hFile, lpszFilePath, cchFilePath, dwFlags);

    return 0;
}

inline BOOL EmptyWorkingSetXp(HANDLE hProcess)
{
    typedef BOOL(WINAPI * PFN_EmptyWorkingSet)(HANDLE hProcess);
    static PFN_EmptyWorkingSet s_EmptyWorkingSet;
    static BOOL s_is_init = FALSE;

    if (!s_is_init) {
        HMODULE handle = GetModuleHandle(L"Kernel32.dll");
        s_EmptyWorkingSet = (PFN_EmptyWorkingSet)(GetProcAddress(handle, "EmptyWorkingSet"));
        if (!s_EmptyWorkingSet) {
            handle = LoadLibraryW(L"Psapi.dll");
            s_EmptyWorkingSet = (PFN_EmptyWorkingSet)(GetProcAddress(handle, "EmptyWorkingSet"));
        }
        s_is_init = TRUE;
    }
    if (s_EmptyWorkingSet)
        return s_EmptyWorkingSet(hProcess);

    return FALSE;
}

inline BOOL EnumProcessModulesXp(HANDLE hProcess, HMODULE* lphModule, DWORD cb, LPDWORD lpcbNeeded)
{
    typedef BOOL(WINAPI * PFN_EnumProcessModules)(HANDLE hProcess, HMODULE * lphModule, DWORD cb, LPDWORD lpcbNeeded);
    static PFN_EnumProcessModules s_EnumProcessModules;
    static BOOL s_is_init = FALSE;

    if (!s_is_init) {
        HMODULE handle = GetModuleHandle(L"Kernel32.dll");
        s_EnumProcessModules = (PFN_EnumProcessModules)(GetProcAddress(handle, "EnumProcessModules"));
        if (!s_EnumProcessModules) {
            handle = LoadLibraryW(L"Psapi.dll");
            s_EnumProcessModules = (PFN_EnumProcessModules)(GetProcAddress(handle, "EnumProcessModules"));
        }
        s_is_init = TRUE;
    }
    if (s_EnumProcessModules)
        return s_EnumProcessModules(hProcess, lphModule, cb, lpcbNeeded);

    return 0;
}

typedef struct _XP_CLIENT_ID {
    HANDLE UniqueProcess;
    HANDLE UniqueThread;
} XP_CLIENT_ID;

typedef struct _XP_THREAD_BASIC_INFORMATION {
    LONG ExitStatus;
    void* Teb;
    XP_CLIENT_ID ClientId;
    KAFFINITY AffinityMask;
    LONG Priority;
    LONG BasePriority;
} XP_THREAD_BASIC_INFORMATION;

inline DWORD GetThreadIdXp(HANDLE hThreadhandle)
{
    typedef DWORD(WINAPI * PFN_GetThreadId)(HANDLE hThreadhandle);
    typedef LONG(WINAPI * PFN_NtQueryInformationThread)(
        HANDLE ThreadHandle, DWORD ThreadInformationClass, PVOID ThreadInformation, ULONG ThreadInformationLength, PULONG ReturnLength);

    static PFN_NtQueryInformationThread s_NtQueryInformationThread = NULL;
    static PFN_GetThreadId s_GetThreadId;
    static BOOL s_is_init = FALSE;

    if (!s_is_init) {
        HMODULE handle = GetModuleHandle(L"Kernel32.dll");
        s_GetThreadId = (PFN_GetThreadId)(GetProcAddress(handle, "GetThreadId"));

        handle = GetModuleHandle(L"Ntdll.dll");
        s_NtQueryInformationThread = (PFN_NtQueryInformationThread)(GetProcAddress(handle, "NtQueryInformationThread"));

        s_is_init = TRUE;
    }
    if (s_GetThreadId)
        return s_GetThreadId(hThreadhandle);

    XP_THREAD_BASIC_INFORMATION thread_basic_information;
    LONG hr = s_NtQueryInformationThread(hThreadhandle, /*ThreadBasicInformation*/ 0, &thread_basic_information, sizeof(XP_THREAD_BASIC_INFORMATION), NULL);
    if (S_OK != hr)
        return 0;

    return (DWORD)(thread_basic_information.ClientId.UniqueThread);
}

typedef struct _XP_IO_STATUS_BLOCK {
    PVOID Pointer;
    ULONG_PTR Information;
} XP_IO_STATUS_BLOCK;

inline BOOL SetFileInformationByHandleXp(HANDLE file_handle, FILE_INFO_BY_HANDLE_CLASS file_information_class, LPVOID file_information, DWORD buffer_size)
{
    typedef BOOL(WINAPI * PFN_SetFileInformationByHandle)(
        HANDLE file_handle, FILE_INFO_BY_HANDLE_CLASS file_information_class, LPVOID file_information, DWORD buffer_size);
    static PFN_SetFileInformationByHandle s_SetFileInformationByHandle;
    static BOOL s_is_init = FALSE;

    typedef LONG(WINAPI * PFN_NtSetInformationFile)(
        HANDLE FileHandle, XP_IO_STATUS_BLOCK * IoStatusBlock, PVOID FileInformation, ULONG Length, DWORD FileInformationClass);
    static PFN_NtSetInformationFile s_NtSetInformationFile = NULL;

    if (!s_is_init) {
        HMODULE handle = GetModuleHandle(L"Ntdll.dll");
        s_SetFileInformationByHandle = (PFN_SetFileInformationByHandle)(GetProcAddress(handle, "SetFileInformationByHandle"));
        s_NtSetInformationFile = (PFN_NtSetInformationFile)(GetProcAddress(handle, "NtSetInformationFile"));
        s_is_init = TRUE;
    }
    if (s_SetFileInformationByHandle)
        return s_SetFileInformationByHandle(file_handle, file_information_class, file_information, buffer_size);

    if (FileDispositionInfo != file_information_class)
        return FALSE;

    XP_IO_STATUS_BLOCK status_block = { 0, 0 };
    LONG result = s_NtSetInformationFile(file_handle, &status_block, file_information, buffer_size, 13 /*FileDispositionInformation*/);
    if (result < 0) {
        return FALSE;
    }

    return FALSE;
}

inline DWORD GetMappedFileNameWXp(HANDLE hProcess, LPVOID lpv, LPWSTR lpFilename, DWORD nSize)
{
    typedef DWORD(WINAPI * PFN_GetMappedFileNameW)(HANDLE hProcess, LPVOID lpv, LPWSTR lpFilename, DWORD nSize);
    static PFN_GetMappedFileNameW s_GetMappedFileNameW;
    static BOOL s_is_init = FALSE;

    if (!s_is_init) {
        HMODULE handle = GetModuleHandle(L"Kernel32.dll");
        s_GetMappedFileNameW = (PFN_GetMappedFileNameW)(GetProcAddress(handle, "GetMappedFileNameW"));
        if (!s_GetMappedFileNameW) {
            handle = LoadLibraryW(L"Psapi.dll");
            s_GetMappedFileNameW = (PFN_GetMappedFileNameW)(GetProcAddress(handle, "GetMappedFileNameW"));
        }
        s_is_init = TRUE;
    }
    if (s_GetMappedFileNameW)
        return s_GetMappedFileNameW(hProcess, lpv, lpFilename, nSize);

    return 0;
}

inline BOOL GetModuleFileNameExWXp(HANDLE hProcess, HMODULE hModule, LPWSTR lpFilename, DWORD nSize)
{
    typedef BOOL(WINAPI * PFN_GetModuleFileNameExW)(HANDLE hProcess, HMODULE hModule, LPWSTR lpFilename, DWORD nSize);
    static PFN_GetModuleFileNameExW s_GetModuleFileNameExW;
    static BOOL s_is_init = FALSE;

    if (!s_is_init) {
        HMODULE handle = GetModuleHandle(L"Kernel32.dll");
        s_GetModuleFileNameExW = (PFN_GetModuleFileNameExW)(GetProcAddress(handle, "GetModuleFileNameExW"));
        if (!s_GetModuleFileNameExW) {
            handle = LoadLibraryW(L"Psapi.dll");
            s_GetModuleFileNameExW = (PFN_GetModuleFileNameExW)(GetProcAddress(handle, "GetModuleFileNameExW"));
        }
        s_is_init = TRUE;
    }
    if (s_GetModuleFileNameExW)
        return s_GetModuleFileNameExW(hProcess, hModule, lpFilename, nSize);

    return 0;
}

inline DWORD GetModuleFileNameWXp(HMODULE hModule, LPWSTR lpFilename, DWORD nSize)
{
    typedef DWORD(WINAPI * PFN_GetModuleFileNameW)(HMODULE hModule, LPWSTR lpFilename, DWORD nSize);
    static PFN_GetModuleFileNameW s_GetModuleFileNameW;
    static BOOL s_is_init = FALSE;

    if (!s_is_init) {
        HMODULE handle = GetModuleHandle(L"Kernel32.dll");
        s_GetModuleFileNameW = (PFN_GetModuleFileNameW)(GetProcAddress(handle, "GetModuleFileNameW"));
        if (!s_GetModuleFileNameW) {
            handle = LoadLibraryW(L"Psapi.dll");
            s_GetModuleFileNameW = (PFN_GetModuleFileNameW)(GetProcAddress(handle, "GetModuleFileNameW"));
        }
        s_is_init = TRUE;
    }
    if (s_GetModuleFileNameW)
        return s_GetModuleFileNameW(hModule, lpFilename, nSize);

    return 0;
}

#else

#define RegDeleteKeyExXp RegDeleteKeyEx
#define GetCurrentProcessorNumberXp GetCurrentProcessorNumber

#define GetProductInfoXp GetProductInfo

#define PowerDeterminePlatformRoleExXp PowerDeterminePlatformRoleEx

#define SetProcessDPIAwareXp SetProcessDPIAware

#define GetModuleFileNameWXp GetModuleFileNameW
#define GetMappedFileNameWXp GetMappedFileNameW

#define SetFileInformationByHandleXp SetFileInformationByHandle

#define CreateSymbolicLinkWXp CreateSymbolicLinkW

#define RegisterTouchWindowXp RegisterTouchWindow

#define DisplayConfigGetDeviceInfoXp DisplayConfigGetDeviceInfo
#define GetDisplayConfigBufferSizesXp GetDisplayConfigBufferSizes
#define QueryDisplayConfigXp QueryDisplayConfig

#define ChangeWindowMessageFilterExXp ChangeWindowMessageFilterEx
#define ChangeWindowMessageFilterXp ChangeWindowMessageFilter
#define SetWindowDisplayAffinityXp SetWindowDisplayAffinity

#define CancelIoExXp CancelIoEx
#define CancelSynchronousIoXp CancelSynchronousIo

#define EnumSystemLocalesExXp EnumSystemLocalesEx

#define PowerCreateRequestXp PowerCreateRequest
#define PowerClearRequestXp PowerClearRequest
#define PowerSetRequestXp PowerSetRequest

#define QueryThreadCycleTimeXp QueryThreadCycleTime
#define QueryThreadCycleTimeIsLoaded TRUE
#define QueryUnbiasedInterruptTimeXp QueryUnbiasedInterruptTime

#define GetModuleInformationXp GetModuleInformation
#define GetPerformanceInfoXp GetPerformanceInfo
#define GetProcessMemoryInfoXp GetProcessMemoryInfo
#define QueryWorkingSetExXp QueryWorkingSetEx

#define DwmDefWindowProcXp DwmDefWindowProc
#define DwmExtendFrameIntoClientAreaXp DwmExtendFrameIntoClientArea
#define DwmGetColorizationColorXp DwmGetColorizationColor
#define DwmGetCompositionTimingInfoXp DwmGetCompositionTimingInfo
#define DwmIsCompositionEnabledXp DwmIsCompositionEnabled
#define DwmSetWindowAttributeXp DwmSetWindowAttribute
#define DwmGetWindowAttributeXp DwmGetWindowAttribute

#define SetCurrentProcessExplicitAppUserModelIDXp SetCurrentProcessExplicitAppUserModelID
#define GetCurrentProcessExplicitAppUserModelIDXp GetCurrentProcessExplicitAppUserModelID

#define GetFinalPathNameByHandleWXp GetFinalPathNameByHandleW
#define EmptyWorkingSetXp EmptyWorkingSet
#define EnumProcessModulesXp EnumProcessModules
#define GetModuleFileNameExWXp GetModuleFileNameExW

#define GetThreadIdXp GetThreadId

#define GetUserDefaultLocaleNameXp GetUserDefaultLocaleName
#define CloseTouchInputHandleXp CloseTouchInputHandle

#endif // SUPPORT_XP_CODE

#endif