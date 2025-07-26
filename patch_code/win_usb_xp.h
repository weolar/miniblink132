#ifndef patch_code_win_usb_xp_h
#define patch_code_win_usb_xp_h

#ifdef SUPPORT_XP_CODE

#include <windows.h>
#include <winusb.h>

inline BOOL WinUsb_AbortPipeXp(WINUSB_INTERFACE_HANDLE InterfaceHandle, UCHAR PipeID)
{
    typedef BOOL(__stdcall * PFN_WinUsb_AbortPipe)(WINUSB_INTERFACE_HANDLE InterfaceHandle, UCHAR PipeID);
    static PFN_WinUsb_AbortPipe s_WinUsb_AbortPipe = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE mod_handle = LoadLibraryW(L"winusb.dll");
        s_WinUsb_AbortPipe = (PFN_WinUsb_AbortPipe)GetProcAddress(mod_handle, "WinUsb_AbortPipe");
        s_is_init = TRUE;
    }

    if (s_WinUsb_AbortPipe)
        return s_WinUsb_AbortPipe(InterfaceHandle, PipeID);

    return FALSE;
}

inline BOOL WinUsb_FlushPipeXp(WINUSB_INTERFACE_HANDLE InterfaceHandle, UCHAR PipeID)
{
    typedef BOOL(__stdcall * PFN_WinUsb_FlushPipe)(WINUSB_INTERFACE_HANDLE InterfaceHandle, UCHAR PipeID);
    static PFN_WinUsb_FlushPipe s_WinUsb_FlushPipe = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE mod_handle = LoadLibraryW(L"winusb.dll");
        s_WinUsb_FlushPipe = (PFN_WinUsb_FlushPipe)GetProcAddress(mod_handle, "WinUsb_FlushPipe");
        s_is_init = TRUE;
    }

    if (s_WinUsb_FlushPipe)
        return s_WinUsb_FlushPipe(InterfaceHandle, PipeID);

    return FALSE;
}

inline BOOL WinUsb_ResetPipeXp(WINUSB_INTERFACE_HANDLE InterfaceHandle, UCHAR PipeID)
{
    typedef BOOL(__stdcall * PFN_WinUsb_ResetPipe)(WINUSB_INTERFACE_HANDLE InterfaceHandle, UCHAR PipeID);
    static PFN_WinUsb_ResetPipe s_WinUsb_ResetPipe = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE mod_handle = LoadLibraryW(L"winusb.dll");
        s_WinUsb_ResetPipe = (PFN_WinUsb_ResetPipe)GetProcAddress(mod_handle, "WinUsb_ResetPipe");
        s_is_init = TRUE;
    }

    if (s_WinUsb_ResetPipe)
        return s_WinUsb_ResetPipe(InterfaceHandle, PipeID);

    return FALSE;
}

inline BOOL WinUsb_SetPipePolicyXp(WINUSB_INTERFACE_HANDLE InterfaceHandle, UCHAR PipeID, ULONG PolicyType, ULONG ValueLength, PVOID Value)
{
    typedef BOOL(__stdcall * PFN_WinUsb_SetPipePolicy)(WINUSB_INTERFACE_HANDLE InterfaceHandle, UCHAR PipeID, ULONG PolicyType, ULONG ValueLength, PVOID Value);
    static PFN_WinUsb_SetPipePolicy s_WinUsb_SetPipePolicy = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE mod_handle = LoadLibraryW(L"winusb.dll");
        s_WinUsb_SetPipePolicy = (PFN_WinUsb_SetPipePolicy)GetProcAddress(mod_handle, "WinUsb_SetPipePolicy");
        s_is_init = TRUE;
    }

    if (s_WinUsb_SetPipePolicy)
        return s_WinUsb_SetPipePolicy(InterfaceHandle, PipeID, PolicyType, ValueLength, Value);

    return FALSE;
}

inline BOOL WinUsb_ControlTransferXp(WINUSB_INTERFACE_HANDLE InterfaceHandle, WINUSB_SETUP_PACKET SetupPacket, PUCHAR Buffer, ULONG BufferLength,
    PULONG LengthTransferred, LPOVERLAPPED Overlapped)
{
    typedef BOOL(__stdcall * PFN_WinUsb_ControlTransfer)(WINUSB_INTERFACE_HANDLE InterfaceHandle, WINUSB_SETUP_PACKET SetupPacket, PUCHAR Buffer,
        ULONG BufferLength, PULONG LengthTransferred, LPOVERLAPPED Overlapped);
    static PFN_WinUsb_ControlTransfer s_WinUsb_ControlTransfer = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE mod_handle = LoadLibraryW(L"winusb.dll");
        s_WinUsb_ControlTransfer = (PFN_WinUsb_ControlTransfer)GetProcAddress(mod_handle, "WinUsb_ControlTransfer");
        s_is_init = TRUE;
    }

    if (s_WinUsb_ControlTransfer)
        return s_WinUsb_ControlTransfer(InterfaceHandle, SetupPacket, Buffer, BufferLength, LengthTransferred, Overlapped);

    return FALSE;
}

inline BOOL WinUsb_FreeXp(WINUSB_INTERFACE_HANDLE InterfaceHandle)
{
    typedef BOOL(__stdcall * PFN_WinUsb_Free)(WINUSB_INTERFACE_HANDLE InterfaceHandle);
    static PFN_WinUsb_Free s_WinUsb_Free = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE mod_handle = LoadLibraryW(L"winusb.dll");
        s_WinUsb_Free = (PFN_WinUsb_Free)GetProcAddress(mod_handle, "WinUsb_Free");
        s_is_init = TRUE;
    }

    if (s_WinUsb_Free)
        return s_WinUsb_Free(InterfaceHandle);

    return FALSE;
}

inline BOOL WinUsb_GetAssociatedInterfaceXp(
    WINUSB_INTERFACE_HANDLE InterfaceHandle, UCHAR AssociatedInterfaceIndex, PWINUSB_INTERFACE_HANDLE AssociatedInterfaceHandle)
{
    typedef BOOL(__stdcall * PFN_WinUsb_GetAssociatedInterface)(
        WINUSB_INTERFACE_HANDLE InterfaceHandle, UCHAR AssociatedInterfaceIndex, PWINUSB_INTERFACE_HANDLE AssociatedInterfaceHandle);
    static PFN_WinUsb_GetAssociatedInterface s_WinUsb_GetAssociatedInterface = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE mod_handle = LoadLibraryW(L"winusb.dll");
        s_WinUsb_GetAssociatedInterface = (PFN_WinUsb_GetAssociatedInterface)GetProcAddress(mod_handle, "WinUsb_GetAssociatedInterface");
        s_is_init = TRUE;
    }

    if (s_WinUsb_GetAssociatedInterface)
        return s_WinUsb_GetAssociatedInterface(InterfaceHandle, AssociatedInterfaceIndex, AssociatedInterfaceHandle);

    return FALSE;
}

inline BOOL WinUsb_GetOverlappedResultXp(WINUSB_INTERFACE_HANDLE InterfaceHandle, LPOVERLAPPED lpOverlapped, LPDWORD lpNumberOfBytesTransferred, BOOL bWait)
{
    typedef BOOL(__stdcall * PFN_WinUsb_GetOverlappedResult)(
        WINUSB_INTERFACE_HANDLE InterfaceHandle, LPOVERLAPPED lpOverlapped, LPDWORD lpNumberOfBytesTransferred, BOOL bWait);
    static PFN_WinUsb_GetOverlappedResult s_WinUsb_GetOverlappedResult = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE mod_handle = LoadLibraryW(L"winusb.dll");
        s_WinUsb_GetOverlappedResult = (PFN_WinUsb_GetOverlappedResult)GetProcAddress(mod_handle, "WinUsb_GetOverlappedResult");
        s_is_init = TRUE;
    }

    if (s_WinUsb_GetOverlappedResult)
        return s_WinUsb_GetOverlappedResult(InterfaceHandle, lpOverlapped, lpNumberOfBytesTransferred, bWait);

    return FALSE;
}

inline BOOL WinUsb_InitializeXp(HANDLE DeviceHandle, PWINUSB_INTERFACE_HANDLE InterfaceHandle)
{
    typedef BOOL(__stdcall * PFN_WinUsb_Initialize)(HANDLE DeviceHandle, PWINUSB_INTERFACE_HANDLE InterfaceHandle);
    static PFN_WinUsb_Initialize s_WinUsb_Initialize = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE mod_handle = LoadLibraryW(L"winusb.dll");
        s_WinUsb_Initialize = (PFN_WinUsb_Initialize)GetProcAddress(mod_handle, "WinUsb_Initialize");
        s_is_init = TRUE;
    }

    if (s_WinUsb_Initialize)
        return s_WinUsb_Initialize(DeviceHandle, InterfaceHandle);

    return FALSE;
}

inline BOOL WinUsb_ReadPipeXp(
    WINUSB_INTERFACE_HANDLE InterfaceHandle, UCHAR PipeID, PUCHAR Buffer, ULONG BufferLength, PULONG LengthTransferred, LPOVERLAPPED Overlapped)
{
    typedef BOOL(__stdcall * PFN_WinUsb_ReadPipe)(
        WINUSB_INTERFACE_HANDLE InterfaceHandle, UCHAR PipeID, PUCHAR Buffer, ULONG BufferLength, PULONG LengthTransferred, LPOVERLAPPED Overlapped);
    static PFN_WinUsb_ReadPipe s_WinUsb_ReadPipe = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE mod_handle = LoadLibraryW(L"winusb.dll");
        s_WinUsb_ReadPipe = (PFN_WinUsb_ReadPipe)GetProcAddress(mod_handle, "WinUsb_ReadPipe");
        s_is_init = TRUE;
    }

    if (s_WinUsb_ReadPipe)
        return s_WinUsb_ReadPipe(InterfaceHandle, PipeID, Buffer, BufferLength, LengthTransferred, Overlapped);

    return FALSE;
}

inline BOOL WinUsb_WritePipeXp(
    WINUSB_INTERFACE_HANDLE InterfaceHandle, UCHAR PipeID, PUCHAR Buffer, ULONG BufferLength, PULONG LengthTransferred, LPOVERLAPPED Overlapped)
{
    typedef BOOL(__stdcall * PFN_WinUsb_WritePipe)(
        WINUSB_INTERFACE_HANDLE InterfaceHandle, UCHAR PipeID, PUCHAR Buffer, ULONG BufferLength, PULONG LengthTransferred, LPOVERLAPPED Overlapped);
    static PFN_WinUsb_WritePipe s_WinUsb_WritePipe = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE mod_handle = LoadLibraryW(L"winusb.dll");
        s_WinUsb_WritePipe = (PFN_WinUsb_WritePipe)GetProcAddress(mod_handle, "WinUsb_WritePipe");
        s_is_init = TRUE;
    }

    if (s_WinUsb_WritePipe)
        return s_WinUsb_WritePipe(InterfaceHandle, PipeID, Buffer, BufferLength, LengthTransferred, Overlapped);

    return FALSE;
}

inline BOOL WinUsb_SetCurrentAlternateSettingXp(WINUSB_INTERFACE_HANDLE InterfaceHandle, UCHAR SettingNumber)
{
    typedef BOOL(__stdcall * PFN_WinUsb_SetCurrentAlternateSetting)(WINUSB_INTERFACE_HANDLE InterfaceHandle, UCHAR SettingNumber);
    static PFN_WinUsb_SetCurrentAlternateSetting s_WinUsb_SetCurrentAlternateSetting = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE mod_handle = LoadLibraryW(L"winusb.dll");
        s_WinUsb_SetCurrentAlternateSetting = (PFN_WinUsb_SetCurrentAlternateSetting)GetProcAddress(mod_handle, "WinUsb_SetCurrentAlternateSetting");
        s_is_init = TRUE;
    }

    if (s_WinUsb_SetCurrentAlternateSetting)
        return s_WinUsb_SetCurrentAlternateSetting(InterfaceHandle, SettingNumber);

    return FALSE;
}

#else

#define WinUsb_ControlTransferXp WinUsb_ControlTransfer
#define WinUsb_FreeXp WinUsb_Free
#define WinUsb_GetAssociatedInterfaceXp WinUsb_GetAssociatedInterface
#define WinUsb_GetOverlappedResultXp WinUsb_GetOverlappedResult
#define WinUsb_InitializeXp WinUsb_Initialize
#define WinUsb_ReadPipeXp WinUsb_ReadPipe
#define WinUsb_WritePipeXp WinUsb_WritePipe
#define WinUsb_SetPipePolicyXp WinUsb_SetPipePolicy
#define WinUsb_FlushPipeXp WinUsb_FlushPipe
#define WinUsb_AbortPipeXp WinUsb_AbortPipe
#define WinUsb_ResetPipeXp WinUsb_ResetPipe
#define WinUsb_SetCurrentAlternateSettingXp WinUsb_SetCurrentAlternateSetting

#endif // SUPPORT_XP_CODE

#endif // patch_code_win_usb_xp_h
