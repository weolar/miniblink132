#ifndef patch_code_cfgmgr32_xp_h
#define patch_code_cfgmgr32_xp_h

#include <cfgmgr32.h>

#ifdef SUPPORT_XP_CODE

inline CONFIGRET CM_Get_DevNode_PropertyWXp(
    DEVINST dnDevInst, CONST DEVPROPKEY* PropertyKey, DEVPROPTYPE* PropertyType, PBYTE PropertyBuffer, PULONG PropertyBufferSize, ULONG ulFlags)
{
    typedef CONFIGRET(WINAPI * PFN_CM_Get_DevNode_PropertyW)(
        DEVINST dnDevInst, CONST DEVPROPKEY * PropertyKey, DEVPROPTYPE * PropertyType, PBYTE PropertyBuffer, PULONG PropertyBufferSize, ULONG ulFlags);
    static PFN_CM_Get_DevNode_PropertyW s_CM_Get_DevNode_PropertyW = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE hmod = LoadLibraryW(L"CfgMgr32.dll");
        s_CM_Get_DevNode_PropertyW = (PFN_CM_Get_DevNode_PropertyW)GetProcAddress(hmod, "CM_Get_DevNode_PropertyW");
        s_is_init = TRUE;
    }

    if (s_CM_Get_DevNode_PropertyW)
        return s_CM_Get_DevNode_PropertyW(dnDevInst, PropertyKey, PropertyType, PropertyBuffer, PropertyBufferSize, ulFlags);
    return CR_INVALID_API;
}

inline CONFIGRET CM_Locate_DevNodeWXp(PDEVINST pdnDevInst, DEVINSTID_W pDeviceID, ULONG ulFlags)
{
    typedef CONFIGRET(WINAPI * PFN_CM_Locate_DevNodeW)(PDEVINST pdnDevInst, DEVINSTID_W pDeviceID, ULONG ulFlags);
    static PFN_CM_Locate_DevNodeW s_CM_Locate_DevNodeW = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE hmod = LoadLibraryW(L"CfgMgr32.dll");
        s_CM_Locate_DevNodeW = (PFN_CM_Locate_DevNodeW)GetProcAddress(hmod, "CM_Locate_DevNodeW");
        s_is_init = TRUE;
    }

    if (s_CM_Locate_DevNodeW)
        return s_CM_Locate_DevNodeW(pdnDevInst, pDeviceID, ulFlags);
    return CR_INVALID_API;
}

inline CONFIGRET CM_Get_ParentXp(PDEVINST pdnDevInst, DEVINST dnDevInst, ULONG ulFlags)
{
    typedef CONFIGRET(WINAPI * PFN_CM_Get_Parent)(PDEVINST pdnDevInst, DEVINST dnDevInst, ULONG ulFlags);
    static PFN_CM_Get_Parent s_CM_Get_Parent = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE hmod = LoadLibraryW(L"CfgMgr32.dll");
        s_CM_Get_Parent = (PFN_CM_Get_Parent)GetProcAddress(hmod, "CM_Get_Parent");
        s_is_init = TRUE;
    }

    if (s_CM_Get_Parent)
        return s_CM_Get_Parent(pdnDevInst, dnDevInst, ulFlags);

    return CR_INVALID_API;
}

#else

#define CM_Get_DevNode_PropertyWXp CM_Get_DevNode_PropertyW
#define CM_Locate_DevNodeWXp CM_Locate_DevNodeW
#define CM_Get_ParentXp CM_Get_Parent

#endif // SUPPORT_XP_CODE
#endif // patch_code_cfgmgr32_xp_h