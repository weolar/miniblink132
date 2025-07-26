#ifndef patch_code_mfapi_xp_h
#define patch_code_mfapi_xp_h

#include <mfapi.h>
#include <mfidl.h>
#include <mfreadwrite.h>

#ifdef SUPPORT_XP_CODE

inline HRESULT MFTEnumXp(GUID guidCategory, UINT32 Flags, MFT_REGISTER_TYPE_INFO* pInputType, MFT_REGISTER_TYPE_INFO* pOutputType, IMFAttributes* pAttributes,
    CLSID** ppclsidMFT, UINT32* pcMFTs)
{
    typedef HRESULT(WINAPI * PFN_MFTEnum)(GUID guidCategory, UINT32 Flags, MFT_REGISTER_TYPE_INFO * pInputType, MFT_REGISTER_TYPE_INFO * pOutputType,
        IMFAttributes * pAttributes, CLSID * *ppclsidMFT, UINT32 * pcMFTs);
    static PFN_MFTEnum s_MFTEnum = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE hmod = LoadLibraryW(L"Mfplat.dll");
        s_MFTEnum = (PFN_MFTEnum)GetProcAddress(hmod, "MFTEnum");
        s_is_init = TRUE;
    }

    if (s_MFTEnum)
        return s_MFTEnum(guidCategory, Flags, pInputType, pOutputType, pAttributes, ppclsidMFT, pcMFTs);
    return -1;
}

inline HRESULT MFStartupXp(ULONG Version, DWORD dwFlags)
{
    typedef HRESULT(WINAPI * PFN_MFStartup)(ULONG Version, DWORD dwFlags);
    static PFN_MFStartup s_MFStartup = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE hmod = LoadLibraryW(L"Mfplat.dll");
        s_MFStartup = (PFN_MFStartup)GetProcAddress(hmod, "MFStartup");
        s_is_init = TRUE;
    }

    if (s_MFStartup)
        return s_MFStartup(Version, dwFlags);
    return -1;
}

inline HRESULT MFShutdownXp()
{
    typedef HRESULT(WINAPI * PFN_MFShutdown)();
    static PFN_MFShutdown s_MFShutdown = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE hmod = LoadLibraryW(L"Mfplat.dll");
        s_MFShutdown = (PFN_MFShutdown)GetProcAddress(hmod, "MFShutdown");
        s_is_init = TRUE;
    }

    if (s_MFShutdown)
        return s_MFShutdown();
    return -1;
}

inline HRESULT MFFrameRateToAverageTimePerFrameXp(UINT32 unNumerator, UINT32 unDenominator, UINT64* punAverageTimePerFrame)
{
    typedef HRESULT(WINAPI * PFN_MFFrameRateToAverageTimePerFrame)(UINT32 unNumerator, UINT32 unDenominator, UINT64 * punAverageTimePerFrame);
    static PFN_MFFrameRateToAverageTimePerFrame s_MFFrameRateToAverageTimePerFrame = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE hmod = LoadLibraryW(L"Mfplat.dll");
        s_MFFrameRateToAverageTimePerFrame = (PFN_MFFrameRateToAverageTimePerFrame)GetProcAddress(hmod, "MFFrameRateToAverageTimePerFrame");
        s_is_init = TRUE;
    }

    if (s_MFFrameRateToAverageTimePerFrame)
        return s_MFFrameRateToAverageTimePerFrame(unNumerator, unDenominator, punAverageTimePerFrame);
    return -1;
}

inline HRESULT MFCreateSampleXp(IMFSample** ppIMFSample)
{
    typedef HRESULT(WINAPI * PFN_MFCreateSample)(IMFSample * *ppIMFSample);
    static PFN_MFCreateSample s_MFCreateSample = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE hmod = LoadLibraryW(L"Mfplat.dll");
        s_MFCreateSample = (PFN_MFCreateSample)GetProcAddress(hmod, "MFCreateSample");
        s_is_init = TRUE;
    }

    if (s_MFCreateSample)
        return s_MFCreateSample(ppIMFSample);
    return -1;
}

inline HRESULT MFCreateMemoryBufferXp(DWORD cbMaxLength, IMFMediaBuffer** ppBuffer)
{
    typedef HRESULT(WINAPI * PFN_MFCreateMemoryBuffer)(DWORD cbMaxLength, IMFMediaBuffer * *ppBuffer);
    static PFN_MFCreateMemoryBuffer s_MFCreateMemoryBuffer = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE hmod = LoadLibraryW(L"Mfplat.dll");
        s_MFCreateMemoryBuffer = (PFN_MFCreateMemoryBuffer)GetProcAddress(hmod, "MFCreateMemoryBuffer");
        s_is_init = TRUE;
    }

    if (s_MFCreateMemoryBuffer)
        return s_MFCreateMemoryBuffer(cbMaxLength, ppBuffer);
    return -1;
}

inline HRESULT MFCreateMediaTypeXp(IMFMediaType** ppMFType)
{
    typedef HRESULT(WINAPI * PFN_MFCreateMediaType)(IMFMediaType * *ppMFType);
    static PFN_MFCreateMediaType s_MFCreateMediaType = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE hmod = LoadLibraryW(L"Mfplat.dll");
        s_MFCreateMediaType = (PFN_MFCreateMediaType)GetProcAddress(hmod, "MFCreateMediaType");
        s_is_init = TRUE;
    }

    if (s_MFCreateMediaType)
        return s_MFCreateMediaType(ppMFType);
    return -1;
}

inline HRESULT MFCreateAttributesXp(IMFAttributes** ppMFAttributes, UINT32 cInitialSize)
{
    typedef HRESULT(WINAPI * PFN_MFCreateAttributes)(IMFAttributes * *ppMFAttributes, UINT32 cInitialSize);
    static PFN_MFCreateAttributes s_MFCreateAttributes = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE hmod = LoadLibraryW(L"Mfplat.dll");
        s_MFCreateAttributes = (PFN_MFCreateAttributes)GetProcAddress(hmod, "MFCreateAttributes");
        s_is_init = TRUE;
    }

    if (s_MFCreateAttributes)
        return s_MFCreateAttributes(ppMFAttributes, cInitialSize);
    return -1;
}

inline HRESULT MFCreateAlignedMemoryBufferXp(DWORD cbMaxLength, DWORD cbAligment, IMFMediaBuffer** ppBuffer)
{
    typedef HRESULT(WINAPI * PFN_MFCreateAlignedMemoryBuffer)(DWORD cbMaxLength, DWORD cbAligment, IMFMediaBuffer * *ppBuffer);
    static PFN_MFCreateAlignedMemoryBuffer s_MFCreateAlignedMemoryBuffer = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE hmod = LoadLibraryW(L"Mfplat.dll");
        s_MFCreateAlignedMemoryBuffer = (PFN_MFCreateAlignedMemoryBuffer)GetProcAddress(hmod, "MFCreateAlignedMemoryBuffer");
        s_is_init = TRUE;
    }

    if (s_MFCreateAlignedMemoryBuffer)
        return s_MFCreateAlignedMemoryBuffer(cbMaxLength, cbAligment, ppBuffer);
    return -1;
}

inline HRESULT MFTEnumExXp(GUID guidCategory, UINT32 Flags, const MFT_REGISTER_TYPE_INFO* pInputType, const MFT_REGISTER_TYPE_INFO* pOutputType,
    IMFActivate*** pppMFTActivate, UINT32* pnumMFTActivate)
{
    typedef HRESULT(WINAPI * PFN_MFTEnumEx)(GUID guidCategory, UINT32 Flags, const MFT_REGISTER_TYPE_INFO* pInputType,
        const MFT_REGISTER_TYPE_INFO* pOutputType, IMFActivate*** pppMFTActivate, UINT32* pnumMFTActivate);
    static PFN_MFTEnumEx s_MFTEnumEx = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE hmod = LoadLibraryW(L"Mfplat.dll");
        s_MFTEnumEx = (PFN_MFTEnumEx)GetProcAddress(hmod, "MFTEnumEx");
        s_is_init = TRUE;
    }

    if (s_MFTEnumEx)
        return s_MFTEnumEx(guidCategory, Flags, pInputType, pOutputType, pppMFTActivate, pnumMFTActivate);
    return -1;
}

inline HRESULT MFCreateSourceReaderFromMediaSourceXp(IMFMediaSource* pMediaSource, IMFAttributes* pAttributes, IMFSourceReader** ppSourceReader)
{
    typedef HRESULT(WINAPI * PFN_MFCreateSourceReaderFromMediaSource)(
        IMFMediaSource * pMediaSource, IMFAttributes * pAttributes, IMFSourceReader * *ppSourceReader);
    static PFN_MFCreateSourceReaderFromMediaSource s_MFCreateSourceReaderFromMediaSource = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE hmod = LoadLibraryW(L"Mfreadwrite.dll");
        s_MFCreateSourceReaderFromMediaSource = (PFN_MFCreateSourceReaderFromMediaSource)GetProcAddress(hmod, "MFCreateSourceReaderFromMediaSource");
        s_is_init = TRUE;
    }

    if (s_MFCreateSourceReaderFromMediaSource)
        return s_MFCreateSourceReaderFromMediaSource(pMediaSource, pAttributes, ppSourceReader);
    return -1;
}

inline HRESULT MFCreateDeviceSourceXp(IMFAttributes* pAttributes, IMFMediaSource** ppSource)
{
    typedef HRESULT(WINAPI * PFN_MFCreateDeviceSource)(IMFAttributes * pAttributes, IMFMediaSource * *ppSource);
    static PFN_MFCreateDeviceSource s_MFCreateDeviceSource = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE hmod = LoadLibraryW(L"Mfreadwrite.dll");
        s_MFCreateDeviceSource = (PFN_MFCreateDeviceSource)GetProcAddress(hmod, "MFCreateDeviceSource");
        s_is_init = TRUE;
    }

    if (s_MFCreateDeviceSource)
        return s_MFCreateDeviceSource(pAttributes, ppSource);
    return -1;
}

inline HRESULT MFEnumDeviceSourcesXp(IMFAttributes* pAttributes, IMFActivate*** pppSourceActivate, UINT32* pcSourceActivate)
{
    typedef HRESULT(WINAPI * PFN_MFEnumDeviceSources)(IMFAttributes * pAttributes, IMFActivate * **pppSourceActivate, UINT32 * pcSourceActivate);
    static PFN_MFEnumDeviceSources s_MFEnumDeviceSources = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE hmod = LoadLibraryW(L"Mfreadwrite.dll");
        s_MFEnumDeviceSources = (PFN_MFEnumDeviceSources)GetProcAddress(hmod, "MFEnumDeviceSources");
        s_is_init = TRUE;
    }

    if (s_MFEnumDeviceSources)
        return s_MFEnumDeviceSources(pAttributes, pppSourceActivate, pcSourceActivate);
    return -1;
}

inline HRESULT MFGetServiceXp(IUnknown* punkObject, REFGUID guidService, REFIID riid, LPVOID* ppvObject)
{
    typedef HRESULT(WINAPI * PFN_MFGetService)(IUnknown * punkObject, REFGUID guidService, REFIID riid, LPVOID * ppvObject);
    static PFN_MFGetService s_MFGetService = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE hmod = LoadLibraryW(L"Mfreadwrite.dll");
        s_MFGetService = (PFN_MFGetService)GetProcAddress(hmod, "MFGetService");
        s_is_init = TRUE;
    }

    if (s_MFGetService)
        return s_MFGetService(punkObject, guidService, riid, ppvObject);
    return -1;
}

#else

#define MFCreateAlignedMemoryBufferXp MFCreateAlignedMemoryBuffer
#define MFCreateAttributesXp MFCreateAttributes
#define MFCreateMediaTypeXp MFCreateMediaType
#define MFCreateMemoryBufferXp MFCreateMemoryBuffer
#define MFCreateSampleXp MFCreateSample
#define MFFrameRateToAverageTimePerFrameXp MFFrameRateToAverageTimePerFrame
#define MFShutdownXp MFShutdown
#define MFStartupXp MFStartup
#define MFTEnumXp MFTEnum
#define MFGetServiceXp MFGetService
#define MFCreateSourceReaderFromMediaSourceXp MFCreateSourceReaderFromMediaSource
#define MFCreateDeviceSourceXp MFCreateDeviceSource
#define MFEnumDeviceSourcesXp MFEnumDeviceSources
#define MFGetServiceXp MFGetService
#define MFTEnumExXp MFTEnumEx

#endif // SUPPORT_XP_CODE
#endif // patch_code_mfapi_xp_h