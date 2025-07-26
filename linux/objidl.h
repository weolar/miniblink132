
#include <windows.h>

typedef struct _userSTGMEDIUM {
    struct _STGMEDIUM_UNION {
        DWORD tymed;
        /* [switch_type] */ union __MIDL_IAdviseSink_0003 {
            /* Empty union arm */
            wireHMETAFILEPICT hMetaFilePict;
            wireHENHMETAFILE hHEnhMetaFile;
            GDI_OBJECT* hGdiHandle;
            wireHGLOBAL hGlobal;
            LPOLESTR lpszFileName;
            BYTE_BLOB* pstm;
            BYTE_BLOB* pstg;
        } u;
    } DUMMYUNIONNAME;
    IUnknown* pUnkForRelease;
} userSTGMEDIUM;

typedef STGMEDIUM* LPSTGMEDIUM;