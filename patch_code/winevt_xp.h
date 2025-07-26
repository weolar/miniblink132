
#ifndef patch_code_winevt_xp_h
#define patch_code_winevt_xp_h

#ifdef SUPPORT_XP_CODE

#include <windows.h>
#include <winevt.h>
#include <evntprov.h>

inline EVT_HANDLE EvtCreateRenderContextXp(DWORD ValuePathsCount, LPCWSTR* ValuePaths, DWORD Flags)
{
    typedef EVT_HANDLE(WINAPI * PFN_EvtCreateRenderContext)(DWORD ValuePathsCount, LPCWSTR * ValuePaths, DWORD Flags);
    static PFN_EvtCreateRenderContext s_EvtCreateRenderContext;
    static BOOL s_is_init = FALSE;

    if (!s_is_init) {
        HMODULE handle = LoadLibraryW(L"WEVTAPI.dll");
        s_EvtCreateRenderContext = (PFN_EvtCreateRenderContext)(GetProcAddress(handle, "EvtCreateRenderContext"));
        s_is_init = TRUE;
    }
    if (s_EvtCreateRenderContext)
        return s_EvtCreateRenderContext(ValuePathsCount, ValuePaths, Flags);

    return (EVT_HANDLE)-1;
}

inline BOOL EvtCloseXp(EVT_HANDLE Object)
{
    typedef BOOL(WINAPI * PFN_EvtClose)(EVT_HANDLE Object);
    static PFN_EvtClose s_EvtClose;
    static BOOL s_is_init = FALSE;

    if (!s_is_init) {
        HMODULE handle = LoadLibraryW(L"WEVTAPI.dll");
        s_EvtClose = (PFN_EvtClose)(GetProcAddress(handle, "EvtClose"));
        s_is_init = TRUE;
    }
    if (s_EvtClose)
        return s_EvtClose(Object);

    return FALSE;
}

inline BOOL EvtNextXp(EVT_HANDLE ResultSet, DWORD EventsSize, PEVT_HANDLE Events, DWORD Timeout, DWORD Flags, PDWORD Returned)
{
    typedef BOOL(WINAPI * PFN_EvtNext)(EVT_HANDLE ResultSet, DWORD EventsSize, PEVT_HANDLE Events, DWORD Timeout, DWORD Flags, PDWORD Returned);
    static PFN_EvtNext s_EvtNext;
    static BOOL s_is_init = FALSE;

    if (!s_is_init) {
        HMODULE handle = LoadLibraryW(L"WEVTAPI.dll");
        s_EvtNext = (PFN_EvtNext)(GetProcAddress(handle, "EvtNext"));
        s_is_init = TRUE;
    }
    if (s_EvtNext)
        return s_EvtNext(ResultSet, EventsSize, Events, Timeout, Flags, Returned);

    return FALSE;
}

inline EVT_HANDLE EvtQueryXp(EVT_HANDLE Session, LPCWSTR Path, LPCWSTR Query, DWORD Flags)
{
    typedef EVT_HANDLE(WINAPI * PFN_EvtQuery)(EVT_HANDLE Session, LPCWSTR Path, LPCWSTR Query, DWORD Flags);
    static PFN_EvtQuery s_EvtQuery;
    static BOOL s_is_init = FALSE;

    if (!s_is_init) {
        HMODULE handle = LoadLibraryW(L"WEVTAPI.dll");
        s_EvtQuery = (PFN_EvtQuery)(GetProcAddress(handle, "EvtQuery"));
        s_is_init = TRUE;
    }
    if (s_EvtQuery)
        return s_EvtQuery(Session, Path, Query, Flags);

    return (EVT_HANDLE)-1;
}

inline BOOL EvtRenderXp(EVT_HANDLE Context, EVT_HANDLE Fragment, DWORD Flags, DWORD BufferSize, PVOID Buffer, PDWORD BufferUsed, PDWORD PropertyCount)
{
    typedef BOOL(WINAPI * PFN_EvtRender)(
        EVT_HANDLE Context, EVT_HANDLE Fragment, DWORD Flags, DWORD BufferSize, PVOID Buffer, PDWORD BufferUsed, PDWORD PropertyCount);
    static PFN_EvtRender s_EvtRender;
    static BOOL s_is_init = FALSE;

    if (!s_is_init) {
        HMODULE handle = LoadLibraryW(L"WEVTAPI.dll");
        s_EvtRender = (PFN_EvtRender)(GetProcAddress(handle, "EvtRender"));
        s_is_init = TRUE;
    }
    if (s_EvtRender)
        return s_EvtRender(Context, Fragment, Flags, BufferSize, Buffer, BufferUsed, PropertyCount);

    return FALSE;
}

inline ULONG EventRegisterXp(LPCGUID ProviderId, PENABLECALLBACK EnableCallback, PVOID CallbackContext, PREGHANDLE RegHandle)
{
    typedef ULONG(WINAPI * PFN_EventRegister)(LPCGUID ProviderId, PENABLECALLBACK EnableCallback, PVOID CallbackContext, PREGHANDLE RegHandle);
    static PFN_EventRegister s_EventRegister;
    static BOOL s_is_init = FALSE;

    if (!s_is_init) {
        HMODULE handle = LoadLibraryW(L"WEVTAPI.dll");
        s_EventRegister = (PFN_EventRegister)(GetProcAddress(handle, "EventRegister"));
        s_is_init = TRUE;
    }
    if (s_EventRegister)
        return s_EventRegister(ProviderId, EnableCallback, CallbackContext, RegHandle);

    return (ULONG)E_FAIL;
}

inline ULONG EventWriteXp(REGHANDLE RegHandle, PCEVENT_DESCRIPTOR EventDescriptor, ULONG UserDataCount, PEVENT_DATA_DESCRIPTOR UserData)
{
    typedef ULONG(WINAPI * PFN_EventWrite)(REGHANDLE RegHandle, PCEVENT_DESCRIPTOR EventDescriptor, ULONG UserDataCount, PEVENT_DATA_DESCRIPTOR UserData);
    static PFN_EventWrite s_EventWrite;
    static BOOL s_is_init = FALSE;

    if (!s_is_init) {
        HMODULE handle = LoadLibraryW(L"WEVTAPI.dll");
        s_EventWrite = (PFN_EventWrite)(GetProcAddress(handle, "EventWrite"));
        s_is_init = TRUE;
    }
    if (s_EventWrite)
        return s_EventWrite(RegHandle, EventDescriptor, UserDataCount, UserData);

    return (ULONG)E_FAIL;
}

inline void EventDataDescCreateXp(PEVENT_DATA_DESCRIPTOR EventDataDescriptor, const void* DataPtr, ULONG DataSize)
{
    typedef void(WINAPI * PFN_EventDataDescCreate)(PEVENT_DATA_DESCRIPTOR EventDataDescriptor, const void* DataPtr, ULONG DataSize);
    static PFN_EventDataDescCreate s_EventDataDescCreate;
    static BOOL s_is_init = FALSE;

    if (!s_is_init) {
        HMODULE handle = LoadLibraryW(L"WEVTAPI.dll");
        s_EventDataDescCreate = (PFN_EventDataDescCreate)(GetProcAddress(handle, "EventDataDescCreate"));
        s_is_init = TRUE;
    }
    if (s_EventDataDescCreate)
        s_EventDataDescCreate(EventDataDescriptor, DataPtr, DataSize);
}

inline ULONG EventUnregisterXp(REGHANDLE RegHandle)
{
    typedef ULONG(WINAPI * PFN_EventUnregister)(REGHANDLE RegHandle);
    static PFN_EventUnregister s_EventUnregister;
    static BOOL s_is_init = FALSE;

    if (!s_is_init) {
        HMODULE handle = LoadLibraryW(L"WEVTAPI.dll");
        s_EventUnregister = (PFN_EventUnregister)(GetProcAddress(handle, "EventUnregister"));
        s_is_init = TRUE;
    }
    if (s_EventUnregister)
        return s_EventUnregister(RegHandle);

    return (ULONG)E_FAIL;
}

#else

#define EvtCreateRenderContextXp EvtCreateRenderContext
#define EvtCloseXp EvtClose
#define EvtNextXp EvtNext
#define EvtQueryXp EvtQuery
#define EvtRenderXp EvtRender
#define EventRegisterXp EventRegister
#define EventUnregisterXp EventUnregister
#define EventWriteXp EventWrite
#define EventDataDescCreateXp EventDataDescCreate

#endif // SUPPORT_XP_CODE
#endif // patch_code_winevt_xp_h