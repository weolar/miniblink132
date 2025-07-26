
#ifndef patch_code_dxgi_xp_h
#define patch_code_dxgi_xp_h

#ifdef SUPPORT_XP_CODE
#include <windows.h>
#include <d3d9.h>
#include <d3d11.h>
#include <dxva2api.h>
#include <dxgi.h>
#include <d3dcommon.h>

inline HRESULT CreateDXGIFactory1Xp(REFIID riid, void** ppFactory)
{
    typedef HRESULT(__stdcall * PFN_CreateDXGIFactory1)(REFIID riid, void** ppFactory);
    static PFN_CreateDXGIFactory1 s_CreateDXGIFactory1 = nullptr;

    static bool isInit = false;
    if (!isInit) {
        HMODULE hModule = LoadLibraryW(L"DXGI.dll");
        if (hModule)
            s_CreateDXGIFactory1 = (PFN_CreateDXGIFactory1)GetProcAddress(hModule, "CreateDXGIFactory1");
        isInit = true;
    }

    if (s_CreateDXGIFactory1)
        return s_CreateDXGIFactory1(riid, ppFactory);

    return E_FAIL;
}

inline HRESULT CreateDXGIFactoryXp(REFIID riid, void** ppFactory)
{
    typedef HRESULT(__stdcall * PFN_CreateDXGIFactory)(REFIID riid, void** ppFactory);
    static PFN_CreateDXGIFactory s_CreateDXGIFactory = nullptr;

    static bool isInit = false;
    if (!isInit) {
        HMODULE hModule = LoadLibraryW(L"DXGI.dll");
        if (hModule)
            s_CreateDXGIFactory = (PFN_CreateDXGIFactory)GetProcAddress(hModule, "CreateDXGIFactory");
        isInit = true;
    }

    if (s_CreateDXGIFactory)
        return s_CreateDXGIFactory(riid, ppFactory);

    return E_FAIL;
}

inline HRESULT D3D11CreateDeviceXp(IDXGIAdapter* pAdapter, D3D_DRIVER_TYPE DriverType, HMODULE Software, UINT Flags, CONST D3D_FEATURE_LEVEL* pFeatureLevels,
    UINT FeatureLevels, UINT SDKVersion, ID3D11Device** ppDevice, D3D_FEATURE_LEVEL* pFeatureLevel, ID3D11DeviceContext** ppImmediateContext)
{
    typedef HRESULT(__stdcall * PFN_D3D11CreateDevice)(IDXGIAdapter * pAdapter, D3D_DRIVER_TYPE DriverType, HMODULE Software, UINT Flags,
        CONST D3D_FEATURE_LEVEL * pFeatureLevels, UINT FeatureLevels, UINT SDKVersion, ID3D11Device * *ppDevice, D3D_FEATURE_LEVEL * pFeatureLevel,
        ID3D11DeviceContext * *ppImmediateContext);
    static PFN_D3D11CreateDevice s_D3D11CreateDevice = nullptr;

    static bool isInit = false;
    if (!isInit) {
        HMODULE hModule = LoadLibraryW(L"D3D11.dll");
        if (hModule)
            s_D3D11CreateDevice = (PFN_D3D11CreateDevice)GetProcAddress(hModule, "D3D11CreateDevice");
        isInit = true;
    }

    if (s_D3D11CreateDevice)
        return s_D3D11CreateDevice(
            pAdapter, DriverType, Software, Flags, pFeatureLevels, FeatureLevels, SDKVersion, ppDevice, pFeatureLevel, ppImmediateContext);

    return E_FAIL;
}

inline HRESULT Direct3DCreate9ExXp(UINT SDKVersion, IDirect3D9Ex** ptr)
{
    typedef HRESULT(__stdcall * PFN_Direct3DCreate9Ex)(UINT SDKVersion, IDirect3D9Ex * *ptr);
    static PFN_Direct3DCreate9Ex s_Direct3DCreate9Ex = nullptr;

    static bool isInit = false;
    if (!isInit) {
        HMODULE hModule = LoadLibraryW(L"D3d9.dll");
        if (hModule)
            s_Direct3DCreate9Ex = (PFN_Direct3DCreate9Ex)GetProcAddress(hModule, "Direct3DCreate9Ex");
        isInit = true;
    }

    if (s_Direct3DCreate9Ex)
        return s_Direct3DCreate9Ex(SDKVersion, ptr);

    return E_FAIL;
}

inline HRESULT DXVA2CreateDirect3DDeviceManager9Xp(UINT* pResetToken, IDirect3DDeviceManager9** ppDeviceManager)
{
    typedef HRESULT(__stdcall * PFN_DXVA2CreateDirect3DDeviceManager9)(UINT * pResetToken, IDirect3DDeviceManager9 * *ppDeviceManager);
    static PFN_DXVA2CreateDirect3DDeviceManager9 s_DXVA2CreateDirect3DDeviceManager9 = nullptr;

    static bool isInit = false;
    if (!isInit) {
        HMODULE hModule = LoadLibraryW(L"DXVA2.dll");
        if (hModule)
            s_DXVA2CreateDirect3DDeviceManager9 = (PFN_DXVA2CreateDirect3DDeviceManager9)GetProcAddress(hModule, "DXVA2CreateDirect3DDeviceManager9");
        isInit = true;
    }

    if (s_DXVA2CreateDirect3DDeviceManager9)
        return s_DXVA2CreateDirect3DDeviceManager9(pResetToken, ppDeviceManager);

    return E_FAIL;
}

inline HRESULT DXVA2CreateVideoServiceXp(IDirect3DDevice9* pDD, REFIID riid, void** ppService)
{
    typedef HRESULT(__stdcall * PFN_DXVA2CreateVideoService)(IDirect3DDevice9 * pDD, REFIID riid, void** ppService);
    static PFN_DXVA2CreateVideoService s_DXVA2CreateVideoService = nullptr;

    static bool isInit = false;
    if (!isInit) {
        HMODULE hModule = LoadLibraryW(L"DXVA2.dll");
        if (hModule)
            s_DXVA2CreateVideoService = (PFN_DXVA2CreateVideoService)GetProcAddress(hModule, "DXVA2CreateVideoService");
        isInit = true;
    }

    if (s_DXVA2CreateVideoService)
        return s_DXVA2CreateVideoService(pDD, riid, ppService);

    return E_FAIL;
}

#else

#define CreateDXGIFactory1Xp CreateDXGIFactory1
#define CreateDXGIFactoryXp CreateDXGIFactory
#define D3D11CreateDeviceXp D3D11CreateDevice
#define Direct3DCreate9ExXp Direct3DCreate9Ex
#define DXVA2CreateDirect3DDeviceManager9Xp DXVA2CreateDirect3DDeviceManager9
#define DXVA2CreateVideoServiceXp DXVA2CreateVideoService

#endif // SUPPORT_XP_CODE
#endif