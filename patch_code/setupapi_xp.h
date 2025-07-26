#ifndef patch_code_xp_setupapi_xp_h
#define patch_code_xp_setupapi_xp_h

#ifdef SUPPORT_XP_CODE

#include <SetupAPI.h>

inline BOOL SetupDiGetDeviceRegistryPropertyWXp(HDEVINFO DeviceInfoSet, PSP_DEVINFO_DATA DeviceInfoData, DWORD Property, PDWORD PropertyRegDataType,
    PBYTE PropertyBuffer, DWORD PropertyBufferSize, PDWORD RequiredSize)
{
    typedef BOOL(__stdcall * PFN_SetupDiGetDeviceRegistryPropertyW)(HDEVINFO DeviceInfoSet, PSP_DEVINFO_DATA DeviceInfoData, DWORD Property,
        PDWORD PropertyRegDataType, PBYTE PropertyBuffer, DWORD PropertyBufferSize, PDWORD RequiredSize);
    static PFN_SetupDiGetDeviceRegistryPropertyW s_SetupDiGetDeviceRegistryPropertyW = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE handle = LoadLibraryW(L"SetupAPI.dll");
        s_SetupDiGetDeviceRegistryPropertyW = (PFN_SetupDiGetDeviceRegistryPropertyW)GetProcAddress(handle, "SetupDiGetDeviceRegistryPropertyW");
        s_is_init = TRUE;
    }

    if (s_SetupDiGetDeviceRegistryPropertyW)
        return s_SetupDiGetDeviceRegistryPropertyW(
            DeviceInfoSet, DeviceInfoData, Property, PropertyRegDataType, PropertyBuffer, PropertyBufferSize, RequiredSize);

    return FALSE;
}

inline BOOL SetupDiGetDevicePropertyWXp(HDEVINFO DeviceInfoSet, PSP_DEVINFO_DATA DeviceInfoData, const DEVPROPKEY* PropertyKey, DEVPROPTYPE* PropertyType,
    PBYTE PropertyBuffer, DWORD PropertyBufferSize, PDWORD RequiredSize, DWORD Flags)
{
    typedef BOOL(__stdcall * PFN_SetupDiGetDevicePropertyW)(HDEVINFO DeviceInfoSet, PSP_DEVINFO_DATA DeviceInfoData, const DEVPROPKEY* PropertyKey,
        DEVPROPTYPE* PropertyType, PBYTE PropertyBuffer, DWORD PropertyBufferSize, PDWORD RequiredSize, DWORD Flags);
    static PFN_SetupDiGetDevicePropertyW s_SetupDiGetDevicePropertyW = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE handle = LoadLibraryW(L"SetupAPI.dll");
        s_SetupDiGetDevicePropertyW = (PFN_SetupDiGetDevicePropertyW)GetProcAddress(handle, "SetupDiGetDevicePropertyW");
        s_is_init = TRUE;
    }

    if (s_SetupDiGetDevicePropertyW)
        return s_SetupDiGetDevicePropertyW(DeviceInfoSet, DeviceInfoData, PropertyKey, PropertyType, PropertyBuffer, PropertyBufferSize, RequiredSize, Flags);

    return FALSE;
}

inline BOOL SetupDiGetDeviceInterfaceDetailWXp(HDEVINFO DeviceInfoSet, PSP_DEVICE_INTERFACE_DATA DeviceInterfaceData,
    PSP_DEVICE_INTERFACE_DETAIL_DATA_W DeviceInterfaceDetailData, DWORD DeviceInterfaceDetailDataSize, PDWORD RequiredSize, PSP_DEVINFO_DATA DeviceInfoData)
{
    typedef BOOL(__stdcall * PFN_SetupDiGetDeviceInterfaceDetailW)(HDEVINFO DeviceInfoSet, PSP_DEVICE_INTERFACE_DATA DeviceInterfaceData,
        PSP_DEVICE_INTERFACE_DETAIL_DATA_W DeviceInterfaceDetailData, DWORD DeviceInterfaceDetailDataSize, PDWORD RequiredSize,
        PSP_DEVINFO_DATA DeviceInfoData);
    static PFN_SetupDiGetDeviceInterfaceDetailW s_SetupDiGetDeviceInterfaceDetailW = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE handle = LoadLibraryW(L"SetupAPI.dll");
        s_SetupDiGetDeviceInterfaceDetailW = (PFN_SetupDiGetDeviceInterfaceDetailW)GetProcAddress(handle, "SetupDiGetDeviceInterfaceDetailW");
        s_is_init = TRUE;
    }

    if (s_SetupDiGetDeviceInterfaceDetailW)
        return s_SetupDiGetDeviceInterfaceDetailW(
            DeviceInfoSet, DeviceInterfaceData, DeviceInterfaceDetailData, DeviceInterfaceDetailDataSize, RequiredSize, DeviceInfoData);

    return FALSE;
}

inline HDEVINFO SetupDiGetClassDevsWXp(CONST GUID* ClassGuid, PCWSTR Enumerator, HWND hwndParent, DWORD Flags)
{
    typedef HDEVINFO(__stdcall * PFN_SetupDiGetClassDevsW)(CONST GUID * ClassGuid, PCWSTR Enumerator, HWND hwndParent, DWORD Flags);
    static PFN_SetupDiGetClassDevsW s_SetupDiGetClassDevsW = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE handle = LoadLibraryW(L"SetupAPI.dll");
        s_SetupDiGetClassDevsW = (PFN_SetupDiGetClassDevsW)GetProcAddress(handle, "SetupDiGetClassDevsW");
        s_is_init = TRUE;
    }

    if (s_SetupDiGetClassDevsW)
        return s_SetupDiGetClassDevsW(ClassGuid, Enumerator, hwndParent, Flags);

    return NULL;
}

inline BOOL SetupDiEnumDeviceInterfacesXp(
    HDEVINFO DeviceInfoSet, PSP_DEVINFO_DATA DeviceInfoData, CONST GUID* InterfaceClassGuid, DWORD MemberIndex, PSP_DEVICE_INTERFACE_DATA DeviceInterfaceData)
{
    typedef BOOL(__stdcall * PFN_SetupDiEnumDeviceInterfaces)(HDEVINFO DeviceInfoSet, PSP_DEVINFO_DATA DeviceInfoData, CONST GUID * InterfaceClassGuid,
        DWORD MemberIndex, PSP_DEVICE_INTERFACE_DATA DeviceInterfaceData);
    static PFN_SetupDiEnumDeviceInterfaces s_SetupDiEnumDeviceInterfaces = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE handle = LoadLibraryW(L"SetupAPI.dll");
        s_SetupDiEnumDeviceInterfaces = (PFN_SetupDiEnumDeviceInterfaces)GetProcAddress(handle, "SetupDiEnumDeviceInterfaces");
        s_is_init = TRUE;
    }

    if (s_SetupDiEnumDeviceInterfaces)
        return s_SetupDiEnumDeviceInterfaces(DeviceInfoSet, DeviceInfoData, InterfaceClassGuid, MemberIndex, DeviceInterfaceData);

    return FALSE;
}

inline HDEVINFO SetupDiCreateDeviceInfoListXp(CONST GUID* ClassGuid, HWND hwndParent)
{
    typedef HDEVINFO(__stdcall * PFN_SetupDiCreateDeviceInfoList)(CONST GUID * ClassGuid, HWND hwndParent);
    static PFN_SetupDiCreateDeviceInfoList s_SetupDiCreateDeviceInfoList = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE handle = LoadLibraryW(L"SetupAPI.dll");
        s_SetupDiCreateDeviceInfoList = (PFN_SetupDiCreateDeviceInfoList)GetProcAddress(handle, "SetupDiCreateDeviceInfoList");
        s_is_init = TRUE;
    }

    if (s_SetupDiCreateDeviceInfoList)
        return s_SetupDiCreateDeviceInfoList(ClassGuid, hwndParent);

    return NULL;
}

inline BOOL SetupDiOpenDeviceInfoXp(HDEVINFO DeviceInfoSet, PCWSTR DeviceInstanceId, HWND hwndParent, DWORD OpenFlags, PSP_DEVINFO_DATA DeviceInfoData)
{
    typedef BOOL(__stdcall * PFN_SetupDiOpenDeviceInfo)(
        HDEVINFO DeviceInfoSet, PCWSTR DeviceInstanceId, HWND hwndParent, DWORD OpenFlags, PSP_DEVINFO_DATA DeviceInfoData);
    static PFN_SetupDiOpenDeviceInfo s_SetupDiOpenDeviceInfo = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE handle = LoadLibraryW(L"SetupAPI.dll");
        s_SetupDiOpenDeviceInfo = (PFN_SetupDiOpenDeviceInfo)GetProcAddress(handle, "SetupDiOpenDeviceInfo");
        s_is_init = TRUE;
    }

    if (s_SetupDiOpenDeviceInfo)
        return s_SetupDiOpenDeviceInfo(DeviceInfoSet, DeviceInstanceId, hwndParent, OpenFlags, DeviceInfoData);

    return FALSE;
}

inline HKEY SetupDiOpenDevRegKeyXp(HDEVINFO DeviceInfoSet, PSP_DEVINFO_DATA DeviceInfoData, DWORD Scope, DWORD HwProfile, DWORD KeyType, REGSAM samDesired)
{
    typedef HKEY(__stdcall * PFN_SetupDiOpenDevRegKey)(
        HDEVINFO DeviceInfoSet, PSP_DEVINFO_DATA DeviceInfoData, DWORD Scope, DWORD HwProfile, DWORD KeyType, REGSAM samDesired);
    static PFN_SetupDiOpenDevRegKey s_SetupDiOpenDevRegKey = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE handle = LoadLibraryW(L"SetupAPI.dll");
        s_SetupDiOpenDevRegKey = (PFN_SetupDiOpenDevRegKey)GetProcAddress(handle, "SetupDiOpenDevRegKey");
        s_is_init = TRUE;
    }

    if (s_SetupDiOpenDevRegKey)
        return s_SetupDiOpenDevRegKey(DeviceInfoSet, DeviceInfoData, Scope, HwProfile, KeyType, samDesired);

    return NULL;
}

inline BOOL SetupDiOpenDeviceInterfaceWXp(HDEVINFO DeviceInfoSet, PCWSTR DevicePath, DWORD OpenFlags, PSP_DEVICE_INTERFACE_DATA DeviceInterfaceData)
{
    typedef BOOL(__stdcall * PFN_SetupDiOpenDeviceInterfaceW)(
        HDEVINFO DeviceInfoSet, PCWSTR DevicePath, DWORD OpenFlags, PSP_DEVICE_INTERFACE_DATA DeviceInterfaceData);
    static PFN_SetupDiOpenDeviceInterfaceW s_SetupDiOpenDeviceInterfaceW = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE handle = LoadLibraryW(L"SetupAPI.dll");
        s_SetupDiOpenDeviceInterfaceW = (PFN_SetupDiOpenDeviceInterfaceW)GetProcAddress(handle, "SetupDiOpenDeviceInterfaceW");
        s_is_init = TRUE;
    }

    if (s_SetupDiOpenDeviceInterfaceW)
        return s_SetupDiOpenDeviceInterfaceW(DeviceInfoSet, DevicePath, OpenFlags, DeviceInterfaceData);

    return FALSE;
}

inline BOOL WINAPI SetupDiEnumDeviceInfoXp(HDEVINFO DeviceInfoSet, DWORD MemberIndex, PSP_DEVINFO_DATA DeviceInfoData)
{
    typedef BOOL(__stdcall * PFN_SetupDiEnumDeviceInfo)(HDEVINFO DeviceInfoSet, DWORD MemberIndex, PSP_DEVINFO_DATA DeviceInfoData);
    static PFN_SetupDiEnumDeviceInfo s_SetupDiEnumDeviceInfo = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE handle = LoadLibraryW(L"SetupAPI.dll");
        s_SetupDiEnumDeviceInfo = (PFN_SetupDiEnumDeviceInfo)GetProcAddress(handle, "SetupDiEnumDeviceInfo");
        s_is_init = TRUE;
    }

    if (s_SetupDiEnumDeviceInfo)
        return s_SetupDiEnumDeviceInfo(DeviceInfoSet, MemberIndex, DeviceInfoData);

    return FALSE;
}

inline BOOL WINAPI SetupDiDeleteDeviceInfoXp(HDEVINFO DeviceInfoSet, PSP_DEVINFO_DATA DeviceInfoData)
{
    typedef BOOL(__stdcall * PFN_SetupDiDeleteDeviceInfo)(HDEVINFO DeviceInfoSet, PSP_DEVINFO_DATA DeviceInfoData);
    static PFN_SetupDiDeleteDeviceInfo s_SetupDiDeleteDeviceInfo = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE handle = LoadLibraryW(L"SetupAPI.dll");
        s_SetupDiDeleteDeviceInfo = (PFN_SetupDiDeleteDeviceInfo)GetProcAddress(handle, "SetupDiDeleteDeviceInfo");
        s_is_init = TRUE;
    }

    if (s_SetupDiDeleteDeviceInfo)
        return s_SetupDiDeleteDeviceInfo(DeviceInfoSet, DeviceInfoData);

    return FALSE;
}

inline BOOL WINAPI SetupDiDestroyDeviceInfoListXp(HDEVINFO DeviceInfoSet)
{
    typedef BOOL(__stdcall * PFN_SetupDiDestroyDeviceInfoList)(HDEVINFO DeviceInfoSet);
    static PFN_SetupDiDestroyDeviceInfoList s_SetupDiDestroyDeviceInfoList = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE handle = LoadLibraryW(L"SetupAPI.dll");
        s_SetupDiDestroyDeviceInfoList = (PFN_SetupDiDestroyDeviceInfoList)GetProcAddress(handle, "SetupDiDestroyDeviceInfoList");
        s_is_init = TRUE;
    }

    if (s_SetupDiDestroyDeviceInfoList)
        return s_SetupDiDestroyDeviceInfoList(DeviceInfoSet);

    return FALSE;
}

inline BOOL SetupDiGetDeviceInstanceIdWXp(
    HDEVINFO DeviceInfoSet, PSP_DEVINFO_DATA DeviceInfoData, PWSTR DeviceInstanceId, DWORD DeviceInstanceIdSize, PDWORD RequiredSize)
{
    typedef BOOL(__stdcall * PFN_SetupDiGetDeviceInstanceIdW)(
        HDEVINFO DeviceInfoSet, PSP_DEVINFO_DATA DeviceInfoData, PWSTR DeviceInstanceId, DWORD DeviceInstanceIdSize, PDWORD RequiredSize);
    static PFN_SetupDiGetDeviceInstanceIdW s_SetupDiGetDeviceInstanceIdW = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE handle = LoadLibraryW(L"SetupAPI.dll");
        s_SetupDiGetDeviceInstanceIdW = (PFN_SetupDiGetDeviceInstanceIdW)GetProcAddress(handle, "SetupDiGetDeviceInstanceIdW");
        s_is_init = TRUE;
    }

    if (s_SetupDiGetDeviceInstanceIdW)
        return s_SetupDiGetDeviceInstanceIdW(DeviceInfoSet, DeviceInfoData, DeviceInstanceId, DeviceInstanceIdSize, RequiredSize);

    return FALSE;
}

#else

#define SetupDiGetDeviceRegistryPropertyWXp SetupDiGetDeviceRegistryPropertyW
#define SetupDiGetDevicePropertyWXp SetupDiGetDevicePropertyW
#define SetupDiGetDeviceInterfaceDetailWXp SetupDiGetDeviceInterfaceDetailW
#define SetupDiGetClassDevsWXp SetupDiGetClassDevsW
#define SetupDiEnumDeviceInterfacesXp SetupDiEnumDeviceInterfaces
#define SetupDiCreateDeviceInfoListXp SetupDiCreateDeviceInfoList
#define SetupDiOpenDeviceInfoXp SetupDiOpenDeviceInfo
#define SetupDiOpenDevRegKeyXp SetupDiOpenDevRegKey
#define SetupDiOpenDeviceInterfaceWXp SetupDiOpenDeviceInterfaceW
#define SetupDiEnumDeviceInfoXp SetupDiEnumDeviceInfo
#define SetupDiDeleteDeviceInfoXp SetupDiDeleteDeviceInfo
#define SetupDiDestroyDeviceInfoListXp SetupDiDestroyDeviceInfoList
#define SetupDiGetDeviceInstanceIdWXp SetupDiGetDeviceInstanceIdW

#endif // SUPPORT_XP_CODE
#endif // patch_code_xp_setupapi_xp_h
