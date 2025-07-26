#ifndef windows_for_linux_Unknwn_h
#define windows_for_linux_Unknwn_h

#include "windows.h"

typedef struct _GUID {
    unsigned long Data1;
    unsigned short Data2;
    unsigned short Data3;
    unsigned char Data4[8];
} GUID;

typedef GUID IID;
#define REFIID const IID&

class IUnknown {
public:
    virtual HRESULT QueryInterface(
        /* [in] */ REFIID riid,
        /* [iid_is][out] */ void** ppvObject)
        = 0;

    virtual ULONG AddRef(void) = 0;

    virtual ULONG Release(void) = 0;
};

#endif // windows_for_linux_Unknwn_h