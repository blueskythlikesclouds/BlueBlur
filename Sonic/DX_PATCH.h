#pragma once

#include <d3d9.h>

namespace DX_PATCH
{
    class IUnknown9;

    class IDirect3D9;

    class IDirect3DDevice9;

    class IDirect3DVertexDeclaration9;

    class IDirect3DVertexShader9;

    class IDirect3DPixelShader9;

    class IDirect3DResource9;

    class IDirect3DBaseTexture9;

    class IDirect3DTexture9;

    class IDirect3DCubeTexture9;

    class IDirect3DVertexBuffer9;

    class IDirect3DIndexBuffer9;

    class IDirect3DSurface9;

    class IUnknown9
    {
    public:
        virtual HRESULT QueryInterface(REFIID riid, void** ppvObj) = 0;

        virtual ULONG AddRef() = 0;

        virtual ULONG Release() = 0;

        virtual ~IUnknown9() = default;
    };

    class IDirect3D9 : public IUnknown9
    {
    public:
        virtual HRESULT RegisterSoftwareDevice(void* pInitializeFunction) = 0;

        virtual UINT GetAdapterCount() = 0;

        virtual HRESULT GetAdapterIdentifier(UINT Adapter, DWORD Flags, D3DADAPTER_IDENTIFIER9* pIdentifier) = 0;

        virtual UINT GetAdapterModeCount(UINT Adapter, D3DFORMAT Format) = 0;

        virtual HRESULT EnumAdapterModes(UINT Adapter, D3DFORMAT Format, UINT Mode, D3DDISPLAYMODE* pMode) = 0;

        virtual HRESULT GetAdapterDisplayMode(UINT Adapter, D3DDISPLAYMODE* pMode) = 0;

        virtual HRESULT CheckDeviceType(UINT Adapter, D3DDEVTYPE DevType, D3DFORMAT AdapterFormat, D3DFORMAT BackBufferFormat, BOOL bWindowed) = 0;

        virtual HRESULT CheckDeviceFormat(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT AdapterFormat, DWORD Usage, D3DRESOURCETYPE RType, D3DFORMAT CheckFormat) = 0;

        virtual HRESULT CheckDeviceMultiSampleType(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT SurfaceFormat, BOOL Windowed, D3DMULTISAMPLE_TYPE MultiSampleType, DWORD* pQualityLevels) = 0;

        virtual HRESULT CheckDepthStencilMatch(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT AdapterFormat, D3DFORMAT RenderTargetFormat, D3DFORMAT DepthStencilFormat) = 0;

        virtual HRESULT CheckDeviceFormatConversion(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT SourceFormat, D3DFORMAT TargetFormat) = 0;

        virtual HRESULT GetDeviceCaps(UINT Adapter, D3DDEVTYPE DeviceType, D3DCAPS9* pCaps) = 0;

        virtual HMONITOR GetAdapterMonitor(UINT Adapter) = 0;

        virtual HRESULT CreateDevice(UINT Adapter, D3DDEVTYPE DeviceType, HWND hFocusWindow, DWORD BehaviorFlags, D3DPRESENT_PARAMETERS* pPresentationParameters, IDirect3DDevice9** ppReturnedDeviceInterface) = 0;
    };

    class IDirect3DDevice9 : public IUnknown9
    {
    public:
        virtual HRESULT TestCooperativeLevel() = 0;

        virtual UINT GetAvailableTextureMem() = 0;

        virtual HRESULT EvictManagedResources() = 0;

        virtual HRESULT GetDirect3D(IDirect3D9** ppD3D9) = 0;

        virtual HRESULT GetDeviceCaps(D3DCAPS9* pCaps) = 0;

        virtual HRESULT GetDisplayMode(UINT iSwapChain, D3DDISPLAYMODE* pMode) = 0;

        virtual HRESULT GetCreationParameters(D3DDEVICE_CREATION_PARAMETERS *pParameters) = 0;

        virtual HRESULT SetCursorProperties(UINT XHotSpot, UINT YHotSpot, IDirect3DSurface9* pCursorBitmap) = 0;

        virtual void SetCursorPosition(int X, int Y, DWORD Flags) = 0;

        virtual BOOL ShowCursor(BOOL bShow) = 0;

        virtual HRESULT CreateAdditionalSwapChain(D3DPRESENT_PARAMETERS* pPresentationParameters, IDirect3DSwapChain9** pSwapChain) = 0;

        virtual HRESULT GetSwapChain(UINT iSwapChain, IDirect3DSwapChain9** pSwapChain) = 0;

        virtual UINT GetNumberOfSwapChains() = 0;

        virtual HRESULT Reset(D3DPRESENT_PARAMETERS* pPresentationParameters) = 0;

        virtual HRESULT Present(CONST RECT* pSourceRect, CONST RECT* pDestRect, HWND hDestWindowOverride, CONST RGNDATA* pDirtyRegion) = 0;

        virtual HRESULT GetBackBuffer(UINT iSwapChain, UINT iBackBuffer, D3DBACKBUFFER_TYPE Type, IDirect3DSurface9** ppBackBuffer) = 0;

        virtual HRESULT GetRasterStatus(UINT iSwapChain, D3DRASTER_STATUS* pRasterStatus) = 0;

        virtual HRESULT SetDialogBoxMode(BOOL bEnableDialogs) = 0;

        virtual void SetGammaRamp(UINT iSwapChain, DWORD Flags, CONST D3DGAMMARAMP* pRamp) = 0;

        virtual void GetGammaRamp(UINT iSwapChain, D3DGAMMARAMP* pRamp) = 0;

        virtual HRESULT CreateTexture(UINT Width, UINT Height, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DTexture9** ppTexture, HANDLE* pSharedHandle) = 0;

        virtual HRESULT CreateVolumeTexture(UINT Width, UINT Height, UINT Depth, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DVolumeTexture9** ppVolumeTexture, HANDLE* pSharedHandle) = 0;

        virtual HRESULT CreateCubeTexture(UINT EdgeLength, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DCubeTexture9** ppCubeTexture, HANDLE* pSharedHandle) = 0;

        virtual HRESULT CreateVertexBuffer(UINT Length, DWORD Usage, DWORD FVF, D3DPOOL Pool, IDirect3DVertexBuffer9** ppVertexBuffer, HANDLE* pSharedHandle) = 0;

        virtual HRESULT CreateIndexBuffer(UINT Length, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DIndexBuffer9** ppIndexBuffer, HANDLE* pSharedHandle) = 0;

        virtual HRESULT CreateRenderTarget(UINT Width, UINT Height, D3DFORMAT Format, D3DMULTISAMPLE_TYPE MultiSample, DWORD MultisampleQuality, BOOL Lockable, IDirect3DSurface9** ppSurface, HANDLE* pSharedHandle) = 0;

        virtual HRESULT CreateDepthStencilSurface(UINT Width, UINT Height, D3DFORMAT Format, D3DMULTISAMPLE_TYPE MultiSample, DWORD MultisampleQuality, BOOL Discard, IDirect3DSurface9** ppSurface, HANDLE* pSharedHandle) = 0;

        virtual HRESULT UpdateSurface(IDirect3DSurface9* pSourceSurface, CONST RECT* pSourceRect, IDirect3DSurface9* pDestinationSurface, CONST POINT* pDestPoint) = 0;

        virtual HRESULT UpdateTexture(IDirect3DBaseTexture9* pSourceTexture, IDirect3DBaseTexture9* pDestinationTexture) = 0;

        virtual HRESULT GetRenderTargetData(IDirect3DSurface9* pRenderTarget, IDirect3DSurface9* pDestSurface) = 0;

        virtual HRESULT GetFrontBufferData(UINT iSwapChain, IDirect3DSurface9* pDestSurface) = 0;

        virtual HRESULT StretchRect(IDirect3DSurface9* pSourceSurface, CONST RECT* pSourceRect, IDirect3DSurface9* pDestSurface, CONST RECT* pDestRect, D3DTEXTUREFILTERTYPE Filter) = 0;

        virtual HRESULT ColorFill(IDirect3DSurface9* pSurface, CONST RECT* pRect, D3DCOLOR color) = 0;

        virtual HRESULT CreateOffscreenPlainSurface(UINT Width, UINT Height, D3DFORMAT Format, D3DPOOL Pool, IDirect3DSurface9** ppSurface, HANDLE* pSharedHandle) = 0;

        virtual HRESULT SetRenderTarget(DWORD RenderTargetIndex, IDirect3DSurface9* pRenderTarget) = 0;

        virtual HRESULT GetRenderTarget(DWORD RenderTargetIndex, IDirect3DSurface9** ppRenderTarget) = 0;

        virtual HRESULT SetDepthStencilSurface(IDirect3DSurface9* pNewZStencil) = 0;

        virtual HRESULT GetDepthStencilSurface(IDirect3DSurface9** ppZStencilSurface) = 0;

        virtual HRESULT BeginScene() = 0;

        virtual HRESULT EndScene() = 0;

        virtual HRESULT Clear(DWORD Count, CONST D3DRECT* pRects, DWORD Flags, D3DCOLOR Color, float Z, DWORD Stencil) = 0;

        virtual HRESULT SetTransform(D3DTRANSFORMSTATETYPE State, CONST D3DMATRIX* pMatrix) = 0;

        virtual HRESULT GetTransform(D3DTRANSFORMSTATETYPE State, D3DMATRIX* pMatrix) = 0;

        virtual HRESULT MultiplyTransform(D3DTRANSFORMSTATETYPE, CONST D3DMATRIX*) = 0;

        virtual HRESULT SetViewport(CONST D3DVIEWPORT9* pViewport) = 0;

        virtual HRESULT GetViewport(D3DVIEWPORT9* pViewport) = 0;

        virtual HRESULT SetMaterial(CONST D3DMATERIAL9* pMaterial) = 0;

        virtual HRESULT GetMaterial(D3DMATERIAL9* pMaterial) = 0;

        virtual HRESULT SetLight(DWORD Index, CONST D3DLIGHT9*) = 0;

        virtual HRESULT GetLight(DWORD Index, D3DLIGHT9*) = 0;

        virtual HRESULT LightEnable(DWORD Index, BOOL Enable) = 0;

        virtual HRESULT GetLightEnable(DWORD Index, BOOL* pEnable) = 0;

        virtual HRESULT SetClipPlane(DWORD Index, CONST float* pPlane) = 0;

        virtual HRESULT GetClipPlane(DWORD Index, float* pPlane) = 0;

        virtual HRESULT SetRenderState(D3DRENDERSTATETYPE State, DWORD Value) = 0;

        virtual HRESULT GetRenderState(D3DRENDERSTATETYPE State, DWORD* pValue) = 0;

        virtual HRESULT CreateStateBlock(D3DSTATEBLOCKTYPE Type, IDirect3DStateBlock9** ppSB) = 0;

        virtual HRESULT BeginStateBlock() = 0;

        virtual HRESULT EndStateBlock(IDirect3DStateBlock9** ppSB) = 0;

        virtual HRESULT SetClipStatus(CONST D3DCLIPSTATUS9* pClipStatus) = 0;

        virtual HRESULT GetClipStatus(D3DCLIPSTATUS9* pClipStatus) = 0;

        virtual HRESULT GetTexture(DWORD Stage, IDirect3DBaseTexture9** ppTexture) = 0;

        virtual HRESULT SetTexture(DWORD Stage, IDirect3DBaseTexture9* pTexture) = 0;

        virtual HRESULT GetTextureStageState(DWORD Stage, D3DTEXTURESTAGESTATETYPE Type, DWORD* pValue) = 0;

        virtual HRESULT SetTextureStageState(DWORD Stage, D3DTEXTURESTAGESTATETYPE Type, DWORD Value) = 0;

        virtual HRESULT GetSamplerState(DWORD Sampler, D3DSAMPLERSTATETYPE Type, DWORD* pValue) = 0;

        virtual HRESULT SetSamplerState(DWORD Sampler, D3DSAMPLERSTATETYPE Type, DWORD Value) = 0;

        virtual HRESULT ValidateDevice(DWORD* pNumPasses) = 0;

        virtual HRESULT SetPaletteEntries(UINT PaletteNumber, CONST PALETTEENTRY* pEntries) = 0;

        virtual HRESULT GetPaletteEntries(UINT PaletteNumber, PALETTEENTRY* pEntries) = 0;

        virtual HRESULT SetCurrentTexturePalette(UINT PaletteNumber) = 0;

        virtual HRESULT GetCurrentTexturePalette(UINT *PaletteNumber) = 0;

        virtual HRESULT SetScissorRect(CONST RECT* pRect) = 0;

        virtual HRESULT GetScissorRect(RECT* pRect) = 0;

        virtual HRESULT SetSoftwareVertexProcessing(BOOL bSoftware) = 0;

        virtual BOOL GetSoftwareVertexProcessing() = 0;

        virtual HRESULT SetNPatchMode(float nSegments) = 0;

        virtual float GetNPatchMode() = 0;

        virtual HRESULT DrawPrimitive(D3DPRIMITIVETYPE PrimitiveType, UINT StartVertex, UINT PrimitiveCount) = 0;

        virtual HRESULT DrawIndexedPrimitive(D3DPRIMITIVETYPE, INT BaseVertexIndex, UINT MinVertexIndex, UINT NumVertices, UINT startIndex, UINT primCount) = 0;

        virtual HRESULT DrawPrimitiveUP(D3DPRIMITIVETYPE PrimitiveType, UINT PrimitiveCount, CONST void* pVertexStreamZeroData, UINT VertexStreamZeroStride) = 0;

        virtual HRESULT DrawIndexedPrimitiveUP(D3DPRIMITIVETYPE PrimitiveType, UINT MinVertexIndex, UINT NumVertices, UINT PrimitiveCount, CONST void* pIndexData, D3DFORMAT IndexDataFormat, CONST void* pVertexStreamZeroData, UINT VertexStreamZeroStride) = 0;

        virtual HRESULT ProcessVertices(UINT SrcStartIndex, UINT DestIndex, UINT VertexCount, IDirect3DVertexBuffer9* pDestBuffer, IDirect3DVertexDeclaration9* pVertexDecl, DWORD Flags) = 0;

        virtual HRESULT CreateVertexDeclaration(CONST D3DVERTEXELEMENT9* pVertexElements, IDirect3DVertexDeclaration9** ppDecl) = 0;

        virtual HRESULT SetVertexDeclaration(IDirect3DVertexDeclaration9* pDecl) = 0;

        virtual HRESULT GetVertexDeclaration(IDirect3DVertexDeclaration9** ppDecl) = 0;

        virtual HRESULT SetFVF(DWORD FVF) = 0;

        virtual HRESULT GetFVF(DWORD* pFVF) = 0;

        virtual HRESULT CreateVertexShader(CONST DWORD* pFunction, IDirect3DVertexShader9** ppShader, DWORD FunctionSize) = 0;

        virtual HRESULT SetVertexShader(IDirect3DVertexShader9* pShader) = 0;

        virtual HRESULT GetVertexShader(IDirect3DVertexShader9** ppShader) = 0;

        virtual HRESULT SetVertexShaderConstantF(UINT StartRegister, CONST float* pConstantData, UINT Vector4fCount) = 0;

        virtual HRESULT GetVertexShaderConstantF(UINT StartRegister, float* pConstantData, UINT Vector4fCount) = 0;

        virtual HRESULT SetVertexShaderConstantI(UINT StartRegister, CONST int* pConstantData, UINT Vector4iCount) = 0;

        virtual HRESULT GetVertexShaderConstantI(UINT StartRegister, int* pConstantData, UINT Vector4iCount) = 0;

        virtual HRESULT SetVertexShaderConstantB(UINT StartRegister, CONST BOOL* pConstantData, UINT  BoolCount) = 0;

        virtual HRESULT GetVertexShaderConstantB(UINT StartRegister, BOOL* pConstantData, UINT BoolCount) = 0;

        virtual HRESULT SetStreamSource(UINT StreamNumber, IDirect3DVertexBuffer9* pStreamData, UINT OffsetInBytes, UINT Stride) = 0;

        virtual HRESULT GetStreamSource(UINT StreamNumber, IDirect3DVertexBuffer9** ppStreamData, UINT* pOffsetInBytes, UINT* pStride) = 0;

        virtual HRESULT SetStreamSourceFreq(UINT StreamNumber, UINT Setting) = 0;

        virtual HRESULT GetStreamSourceFreq(UINT StreamNumber, UINT* pSetting) = 0;

        virtual HRESULT SetIndices(IDirect3DIndexBuffer9* pIndexData) = 0;

        virtual HRESULT GetIndices(IDirect3DIndexBuffer9** ppIndexData) = 0;

        virtual HRESULT CreatePixelShader(CONST DWORD* pFunction, IDirect3DPixelShader9** ppShader, DWORD FunctionSize) = 0;

        virtual HRESULT SetPixelShader(IDirect3DPixelShader9* pShader) = 0;

        virtual HRESULT GetPixelShader(IDirect3DPixelShader9** ppShader) = 0;

        virtual HRESULT SetPixelShaderConstantF(UINT StartRegister, CONST float* pConstantData, UINT Vector4fCount) = 0;

        virtual HRESULT GetPixelShaderConstantF(UINT StartRegister, float* pConstantData, UINT Vector4fCount) = 0;

        virtual HRESULT SetPixelShaderConstantI(UINT StartRegister, CONST int* pConstantData, UINT Vector4iCount) = 0;

        virtual HRESULT GetPixelShaderConstantI(UINT StartRegister, int* pConstantData, UINT Vector4iCount) = 0;

        virtual HRESULT SetPixelShaderConstantB(UINT StartRegister, CONST BOOL* pConstantData, UINT  BoolCount) = 0;

        virtual HRESULT GetPixelShaderConstantB(UINT StartRegister, BOOL* pConstantData, UINT BoolCount) = 0;

        virtual HRESULT DrawRectPatch(UINT Handle, CONST float* pNumSegs, CONST D3DRECTPATCH_INFO* pRectPatchInfo) = 0;

        virtual HRESULT DrawTriPatch(UINT Handle, CONST float* pNumSegs, CONST D3DTRIPATCH_INFO* pTriPatchInfo) = 0;

        virtual HRESULT DeletePatch(UINT Handle) = 0;

        virtual HRESULT CreateQuery(D3DQUERYTYPE Type, IDirect3DQuery9** ppQuery) = 0;
    };

    class IDirect3DResource9 : public IUnknown9
    {
    public:
        virtual HRESULT GetDevice(IDirect3DDevice9** ppDevice) = 0;

        virtual HRESULT SetPrivateData(REFGUID refguid, CONST void* pData, DWORD SizeOfData, DWORD Flags) = 0;

        virtual HRESULT GetPrivateData(REFGUID refguid, void* pData, DWORD* pSizeOfData) = 0;

        virtual HRESULT FreePrivateData(REFGUID refguid) = 0;

        virtual DWORD SetPriority(DWORD PriorityNew) = 0;

        virtual DWORD GetPriority() = 0;

        virtual void PreLoad() = 0;

        virtual D3DRESOURCETYPE GetType() = 0;
    };

    class IDirect3DVertexDeclaration9 : public IUnknown9
    {
    public:
        virtual HRESULT GetDevice(IDirect3DDevice9** ppDevice) = 0;

        virtual HRESULT GetDeclaration(D3DVERTEXELEMENT9* pElement, UINT* pNumElements) = 0;
    };

    class IDirect3DVertexShader9 : public IUnknown9
    {
    public:
        virtual HRESULT GetDevice(IDirect3DDevice9** ppDevice) = 0;

        virtual HRESULT GetFunction(void*, UINT* pSizeOfData) = 0;
    };

    class IDirect3DPixelShader9 : public IUnknown9
    {
    public:
        virtual HRESULT GetDevice(IDirect3DDevice9** ppDevice) = 0;

        virtual HRESULT GetFunction(void*, UINT* pSizeOfData) = 0;
    };

    class IDirect3DBaseTexture9 : public IDirect3DResource9
    {
    public:
        virtual DWORD SetLOD(DWORD LODNew) = 0;

        virtual DWORD GetLOD() = 0;

        virtual DWORD GetLevelCount() = 0;

        virtual HRESULT SetAutoGenFilterType(D3DTEXTUREFILTERTYPE FilterType) = 0;

        virtual D3DTEXTUREFILTERTYPE GetAutoGenFilterType() = 0;

        virtual void GenerateMipSubLevels() = 0;

        // Extra function added by game. Purpose unknown.
        virtual void FUN_48() = 0;

        // Extra function added by game. Purpose unknown.
        virtual HRESULT FUN_4C(void* A1) = 0;
    };

    class IDirect3DTexture9 : public IDirect3DBaseTexture9
    {
    public:
        virtual HRESULT GetLevelDesc(UINT Level, D3DSURFACE_DESC *pDesc) = 0;

        virtual HRESULT GetSurfaceLevel(UINT Level, IDirect3DSurface9** ppSurfaceLevel) = 0;

        virtual HRESULT LockRect(UINT Level, D3DLOCKED_RECT* pLockedRect, CONST RECT* pRect, DWORD Flags) = 0;

        virtual HRESULT UnlockRect(UINT Level) = 0;

        virtual HRESULT AddDirtyRect(CONST RECT* pDirtyRect) = 0;
    };

    class IDirect3DCubeTexture9 : public IDirect3DBaseTexture9
    {
    public:
        virtual HRESULT GetLevelDesc(UINT Level, D3DSURFACE_DESC *pDesc) = 0;

        virtual HRESULT GetCubeMapSurface(D3DCUBEMAP_FACES FaceType, UINT Level, IDirect3DSurface9** ppCubeMapSurface) = 0;

        virtual HRESULT LockRect(D3DCUBEMAP_FACES FaceType, UINT Level, D3DLOCKED_RECT* pLockedRect, CONST RECT* pRect, DWORD Flags) = 0;

        virtual HRESULT UnlockRect(D3DCUBEMAP_FACES FaceType, UINT Level) = 0;

        virtual HRESULT AddDirtyRect(D3DCUBEMAP_FACES FaceType, CONST RECT* pDirtyRect) = 0;
    };

    class IDirect3DVertexBuffer9 : public IDirect3DResource9
    {
    public:
        virtual HRESULT Lock(UINT OffsetToLock, UINT SizeToLock, void** ppbData, DWORD Flags) = 0;

        virtual HRESULT Unlock() = 0;

        virtual HRESULT GetDesc(D3DVERTEXBUFFER_DESC *pDesc) = 0;
    };

    class IDirect3DIndexBuffer9 : public IDirect3DResource9
    {
    public:
        virtual HRESULT Lock(UINT OffsetToLock, UINT SizeToLock, void** ppbData, DWORD Flags) = 0;

        virtual HRESULT Unlock() = 0;

        virtual HRESULT GetDesc(D3DINDEXBUFFER_DESC *pDesc) = 0;
    };

    class IDirect3DSurface9 : public IDirect3DResource9
    {
    public:
        virtual HRESULT GetContainer(REFIID riid, void** ppContainer) = 0;

        virtual HRESULT GetDesc(D3DSURFACE_DESC *pDesc) = 0;

        virtual HRESULT LockRect(D3DLOCKED_RECT* pLockedRect, CONST RECT* pRect, DWORD Flags) = 0;

        virtual HRESULT UnlockRect() = 0;

        virtual HRESULT GetDC(HDC *phdc) = 0;

        virtual HRESULT ReleaseDC(HDC hdc) = 0;
    };
};