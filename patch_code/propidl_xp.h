
#ifndef patch_code_propidl_xp_h
#define patch_code_propidl_xp_h

#ifdef SUPPORT_XP_CODE

#include <PropIdl.h>

inline HRESULT InitPropVariantFromCLSID_XP(const CLSID& clsid, PROPVARIANT* ppropvar)
{
    __int32 v3;

    ppropvar->vt = 0;
    ppropvar->puuid = (CLSID*)CoTaskMemAlloc(0x10u);
    if (!(ppropvar->puuid))
        return E_FAIL;

    v3 = ppropvar->lVal;
    ppropvar->vt = 72;
    *(DWORD*)v3 = clsid.Data1;
    v3 += 4;
    *(DWORD*)v3 = *(DWORD*)&(clsid.Data2);
    v3 += 4;
    *(DWORD*)v3 = *(DWORD*)&(clsid.Data4[0]);
    *(DWORD*)(v3 + 4) = *(DWORD*)&(clsid.Data4[4]);
    return S_OK;
}

#else
#define InitPropVariantFromCLSID_XP InitPropVariantFromCLSID
#endif

#endif // patch_code_propidl_xp_h