
#ifndef patch_code_ui_automation_core_xp_h
#define patch_code_ui_automation_core_xp_h

#ifdef SUPPORT_XP_CODE

#include <windows.h>

inline BOOL UiaClientsAreListeningXp()
{
    typedef BOOL(__stdcall * PFN_UiaClientsAreListening)();
    static PFN_UiaClientsAreListening s_UiaClientsAreListening = nullptr;

    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE mod_handle = LoadLibraryW(L"UIAUTOMATIONCORE.dll");
        if (mod_handle)
            s_UiaClientsAreListening = (PFN_UiaClientsAreListening)GetProcAddress(mod_handle, "UiaClientsAreListening");
        s_is_init = TRUE;
    }

    if (s_UiaClientsAreListening)
        return s_UiaClientsAreListening();

    return FALSE;
}

inline HRESULT UiaHostProviderFromHwndXp(HWND hwnd, IRawElementProviderSimple** ppProvider)
{
    typedef HRESULT(__stdcall * PFN_UiaHostProviderFromHwnd)(HWND hwnd, IRawElementProviderSimple * *ppProvider);
    static PFN_UiaHostProviderFromHwnd s_UiaHostProviderFromHwnd = nullptr;

    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE mod_handle = LoadLibraryW(L"UIAUTOMATIONCORE.dll");
        if (mod_handle)
            s_UiaHostProviderFromHwnd = (PFN_UiaHostProviderFromHwnd)GetProcAddress(mod_handle, "UiaHostProviderFromHwnd");
        s_is_init = TRUE;
    }

    if (s_UiaHostProviderFromHwnd)
        return s_UiaHostProviderFromHwnd(hwnd, ppProvider);

    return E_FAIL;
}

inline LRESULT UiaReturnRawElementProviderXp(HWND hwnd, WPARAM wParam, LPARAM lParam, IRawElementProviderSimple* el)
{
    typedef HRESULT(__stdcall * PFN_UiaReturnRawElementProvider)(HWND hwnd, WPARAM wParam, LPARAM lParam, IRawElementProviderSimple * el);
    static PFN_UiaReturnRawElementProvider s_UiaReturnRawElementProvider = nullptr;

    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE mod_handle = LoadLibraryW(L"UIAUTOMATIONCORE.dll");
        if (mod_handle)
            s_UiaReturnRawElementProvider = (PFN_UiaReturnRawElementProvider)GetProcAddress(mod_handle, "UiaReturnRawElementProvider");
        s_is_init = TRUE;
    }

    if (s_UiaReturnRawElementProvider)
        return s_UiaReturnRawElementProvider(hwnd, wParam, lParam, el);

    return E_FAIL;
}

inline HRESULT UiaGetReservedMixedAttributeValueXp(IUnknown** punkMixedAttributeValue)
{
    typedef HRESULT(__stdcall * PFN_UiaGetReservedMixedAttributeValue)(IUnknown * *punkMixedAttributeValue);
    static PFN_UiaGetReservedMixedAttributeValue s_UiaGetReservedMixedAttributeValue = nullptr;

    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE mod_handle = LoadLibraryW(L"UIAUTOMATIONCORE.dll");
        if (mod_handle)
            s_UiaGetReservedMixedAttributeValue = (PFN_UiaGetReservedMixedAttributeValue)GetProcAddress(mod_handle, "UiaGetReservedMixedAttributeValue");
        s_is_init = TRUE;
    }

    if (s_UiaGetReservedMixedAttributeValue)
        return s_UiaGetReservedMixedAttributeValue(punkMixedAttributeValue);

    return E_FAIL;
}

inline HRESULT UiaGetReservedNotSupportedValueXp(IUnknown** punkNotSupportedValue)
{
    typedef HRESULT(__stdcall * PFN_UiaGetReservedNotSupportedValue)(IUnknown * *punkNotSupportedValue);
    static PFN_UiaGetReservedNotSupportedValue s_UiaGetReservedNotSupportedValue = nullptr;

    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE mod_handle = LoadLibraryW(L"UIAUTOMATIONCORE.dll");
        if (mod_handle)
            s_UiaGetReservedNotSupportedValue = (PFN_UiaGetReservedNotSupportedValue)GetProcAddress(mod_handle, "UiaGetReservedNotSupportedValue");
        s_is_init = TRUE;
    }

    if (s_UiaGetReservedNotSupportedValue)
        return s_UiaGetReservedNotSupportedValue(punkNotSupportedValue);

    return E_FAIL;
}

inline HRESULT UiaRaiseAutomationEventXp(IRawElementProviderSimple* pProvider, EVENTID id)
{
    typedef HRESULT(__stdcall * PFN_UiaRaiseAutomationEvent)(IRawElementProviderSimple * pProvider, EVENTID id);
    static PFN_UiaRaiseAutomationEvent s_UiaRaiseAutomationEvent = nullptr;

    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE mod_handle = LoadLibraryW(L"UIAUTOMATIONCORE.dll");
        if (mod_handle)
            s_UiaRaiseAutomationEvent = (PFN_UiaRaiseAutomationEvent)GetProcAddress(mod_handle, "UiaRaiseAutomationEvent");
        s_is_init = TRUE;
    }

    if (s_UiaRaiseAutomationEvent)
        return s_UiaRaiseAutomationEvent(pProvider, id);

    return E_FAIL;
}

inline HRESULT UiaRaiseAutomationPropertyChangedEventXp(IRawElementProviderSimple* pProvider, PROPERTYID id, VARIANT oldValue, VARIANT newValue)
{
    typedef HRESULT(__stdcall * PFN_UiaRaiseAutomationPropertyChangedEvent)(
        IRawElementProviderSimple * pProvider, PROPERTYID id, VARIANT oldValue, VARIANT newValue);
    static PFN_UiaRaiseAutomationPropertyChangedEvent s_UiaRaiseAutomationPropertyChangedEvent = nullptr;

    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE mod_handle = LoadLibraryW(L"UIAUTOMATIONCORE.dll");
        if (mod_handle)
            s_UiaRaiseAutomationPropertyChangedEvent
                = (PFN_UiaRaiseAutomationPropertyChangedEvent)GetProcAddress(mod_handle, "UiaRaiseAutomationPropertyChangedEvent");
        s_is_init = TRUE;
    }

    if (s_UiaRaiseAutomationPropertyChangedEvent)
        return s_UiaRaiseAutomationPropertyChangedEvent(pProvider, id, oldValue, newValue);

    return E_FAIL;
}

inline HRESULT UiaRaiseStructureChangedEventXp(
    IRawElementProviderSimple* pProvider, StructureChangeType structureChangeType, int* pRuntimeId, int cRuntimeIdLen)
{
    typedef HRESULT(__stdcall * PFN_UiaRaiseStructureChangedEvent)(
        IRawElementProviderSimple * pProvider, StructureChangeType structureChangeType, int* pRuntimeId, int cRuntimeIdLen);
    static PFN_UiaRaiseStructureChangedEvent s_UiaRaiseStructureChangedEvent = nullptr;

    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE mod_handle = LoadLibraryW(L"UIAUTOMATIONCORE.dll");
        if (mod_handle)
            s_UiaRaiseStructureChangedEvent = (PFN_UiaRaiseStructureChangedEvent)GetProcAddress(mod_handle, "UiaRaiseStructureChangedEvent");
        s_is_init = TRUE;
    }

    if (s_UiaRaiseStructureChangedEvent)
        return s_UiaRaiseStructureChangedEvent(pProvider, structureChangeType, pRuntimeId, cRuntimeIdLen);

    return E_FAIL;
}

#else

#define UiaClientsAreListeningXp UiaClientsAreListening
#define UiaHostProviderFromHwndXp UiaHostProviderFromHwnd
#define UiaReturnRawElementProviderXp UiaReturnRawElementProvider
#define UiaGetReservedMixedAttributeValueXp UiaGetReservedMixedAttributeValue
#define UiaGetReservedNotSupportedValueXp UiaGetReservedNotSupportedValue
#define UiaRaiseAutomationEventXp UiaRaiseAutomationEvent
#define UiaRaiseAutomationPropertyChangedEventXp UiaRaiseAutomationPropertyChangedEvent
#define UiaRaiseStructureChangedEventXp UiaRaiseStructureChangedEvent

#endif // SUPPORT_XP_CODE
#endif // patch_code_shell_api_h