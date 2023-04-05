#pragma once

#include <Hedgehog/Yggdrasill/hhYggScheduler.h>

namespace Hedgehog::Mirage
{
    class CRenderingInfrastructure;
    class CVertexShaderData;
    class CPixelShaderData;
}

namespace Hedgehog::Yggdrasill
{
    class CYggAllocator;
    class CYggDevice;
    class CYggScheduler;
    class CYggSurface;
    class CYggTexture;

    struct SYggClearParams
    {
        DWORD Flags;
        D3DCOLOR Color;
        float Z;
        DWORD Stencil;
    };

    static inline BB_FUNCTION_PTR(void, __thiscall, fpCYggDeviceSetSamplerFilter, 0x411CF0, 
        CYggDevice* This, uint32_t in_Index, D3DTEXTUREFILTERTYPE in_MigFilter, D3DTEXTUREFILTERTYPE in_MagFilter, D3DTEXTUREFILTERTYPE in_MipFilter);

    static inline BB_FUNCTION_PTR(void, __thiscall, fpCYggDeviceSetShader, 0x415EE0, 
        CYggDevice* This, const boost::shared_ptr<Hedgehog::Mirage::CVertexShaderData>& in_spVertexShaderData, const boost::shared_ptr<Hedgehog::Mirage::CPixelShaderData>& in_spPixelShaderData);

    static inline BB_FUNCTION_PTR(void, __thiscall, fpCYggDeviceCreateTexture0, 0x7884C0, 
        const CYggDevice* This, boost::shared_ptr<CYggTexture>& out_spTexture, float in_WidthRatio, float in_HeightRatio, uint32_t in_Levels, uint32_t in_Usage, D3DFORMAT in_Format, D3DPOOL in_Pool, HANDLE* in_pSharedHandle);

    static inline BB_FUNCTION_PTR(void, __thiscall, fpCYggDeviceCreateTexture1, 0x788450, 
        const CYggDevice* This, boost::shared_ptr<CYggTexture>& out_spTexture, uint32_t in_Width, uint32_t in_Height, uint32_t in_Levels, uint32_t in_Usage, D3DFORMAT in_Format, D3DPOOL in_Pool, HANDLE* in_pSharedHandle);

    static inline BB_FUNCTION_PTR(void, __thiscall, fpCYggDeviceDrawQuad2D, 0x786620, 
        CYggDevice* This, float* in_pBounds, float in_X, float in_Y);

    static inline BB_FUNCTION_PTR(void, __thiscall, fpCYggDeviceUnsetSampler, 0x412120, 
        CYggDevice* This, uint32_t in_Index);

    static inline BB_FUNCTION_PTR(void, __thiscall, fpCYggDeviceSetDepthStencil, 0x785D10, 
        CYggDevice* This, const boost::shared_ptr<CYggSurface>& in_spSurface);

    static inline BB_FUNCTION_PTR(void, __thiscall, fpCYggDeviceGetRenderTarget, 0x786030,
        const CYggDevice* This, boost::shared_ptr<CYggSurface>& out_spSurface, uint32_t in_Index);

    static inline BB_FUNCTION_PTR(void, __thiscall, fpCYggDeviceSetRenderTarget, 0x785D00, 
        CYggDevice* This, uint32_t in_Index, const boost::shared_ptr<CYggSurface>& in_spSurface);

    static inline BB_FUNCTION_PTR(void, __thiscall, fpCYggDeviceSetSamplerAddressMode, 0x411CA0, 
        CYggDevice* This, uint32_t in_Index, uint32_t in_Value);

    static inline BB_FUNCTION_PTR(void, __thiscall, fpCYggDeviceSetTexture, 0x7865A0, 
        CYggDevice* This, uint32_t in_Index, const boost::shared_ptr<CYggTexture>& in_spTexture);

    static inline BB_FUNCTION_PTR(void, __thiscall, fpCYggDeviceClear0, 0x785EE0, 
        CYggDevice* This, const SYggClearParams& in_rParams);

    static inline BB_FUNCTION_PTR(void, __thiscall, fpCYggDeviceClear1, 0x416650,
        CYggDevice* This, DWORD in_Flags, D3DCOLOR in_Color, float in_Z, DWORD in_Stencil);

    static inline BB_FUNCTION_PTR(void, __thiscall, fpCYggDeviceGetResolution, 0x785A90,
        CYggDevice* This, float in_WidthRatio, float in_HeightRatio, uint32_t& out_Width, uint32_t& out_Height);

    static inline BB_FUNCTION_PTR(void, __thiscall, fpCYggDeviceFlush, 0x786070,
        CYggDevice* This);

    class CYggDevice
    {
    public:
        Mirage::CRenderingInfrastructure* m_pRenderingInfrastructure;
        DX_PATCH::IDirect3DDevice9* m_pD3DDevice;
        CYggScheduler* m_pScheduler;
        CYggAllocator* m_pAllocator;
        BB_INSERT_PADDING(0xB8);
        uint32_t m_InternalResolutionWidth;
        uint32_t m_InternalResolutionHeight;

        void SetSamplerFilter(uint32_t in_Index, D3DTEXTUREFILTERTYPE in_MigFilter, D3DTEXTUREFILTERTYPE in_MagFilter, D3DTEXTUREFILTERTYPE in_MipFilter)
        {
            fpCYggDeviceSetSamplerFilter(this, in_Index, in_MigFilter, in_MagFilter, in_MipFilter);
        }

        void SetShader(const boost::shared_ptr<Mirage::CVertexShaderData>& in_spVertexShaderData, const boost::shared_ptr<Mirage::CPixelShaderData>& in_spPixelShaderData)
        {
            fpCYggDeviceSetShader(this, in_spVertexShaderData, in_spPixelShaderData);
        }

        void SetShader(const Mirage::SShaderPair& in_rShader)
        {
            SetShader(in_rShader.m_spVertexShader, in_rShader.m_spPixelShader);
        }

        boost::shared_ptr<CYggTexture> CreateTexture(float in_WidthRatio, float in_HeightRatio, uint32_t in_Levels, uint32_t in_Usage, D3DFORMAT in_Format, D3DPOOL in_Pool, HANDLE* in_pSharedHandle) const
        {
            boost::shared_ptr<CYggTexture> spTexture;
            fpCYggDeviceCreateTexture0(this, spTexture, in_WidthRatio, in_HeightRatio, in_Levels, in_Usage, in_Format, in_Pool, in_pSharedHandle);
            return spTexture;
        }

        boost::shared_ptr<CYggTexture> CreateTexture(uint32_t in_Width, uint32_t in_Height, uint32_t in_Levels, uint32_t in_Usage, D3DFORMAT in_Format, D3DPOOL in_Pool, HANDLE* in_pSharedHandle) const
        {
            boost::shared_ptr<CYggTexture> spTexture;
            fpCYggDeviceCreateTexture1(this, spTexture, in_Width, in_Height, in_Levels, in_Usage, in_Format, in_Pool, in_pSharedHandle);
            return spTexture;
        }

        void DrawQuad2D(float* in_pBounds, float in_X, float in_Y)
        {
            fpCYggDeviceDrawQuad2D(this, in_pBounds, in_X, in_Y);
        }

        void UnsetSampler(uint32_t in_Index)
        {
            fpCYggDeviceUnsetSampler(this, in_Index);
        }

        void SetDepthStencil(const boost::shared_ptr<CYggSurface>& in_spSurface)
        {
            fpCYggDeviceSetDepthStencil(this, in_spSurface);
        }

        void UnsetDepthStencil()
        {
            SetDepthStencil(boost::shared_ptr<CYggSurface>());
        }

        boost::shared_ptr<CYggSurface> GetRenderTarget(uint32_t in_Index) const
        {
            boost::shared_ptr<CYggSurface> spSurface;
            fpCYggDeviceGetRenderTarget(this, spSurface, in_Index);
            return spSurface;
        }

        void SetRenderTarget(uint32_t in_Index, const boost::shared_ptr<CYggSurface>& in_spSurface)
        {
            fpCYggDeviceSetRenderTarget(this, in_Index, in_spSurface);
        }

        void UnsetRenderTarget(uint32_t in_Index)
        {
            SetRenderTarget(in_Index, boost::shared_ptr<CYggSurface>());
        }

        void SetSamplerAddressMode(uint32_t in_Index, uint32_t in_Value)
        {
            fpCYggDeviceSetSamplerAddressMode(this, in_Index, in_Value);
        }

        void SetTexture(uint32_t in_Index, const boost::shared_ptr<CYggTexture>& in_spTexture)
        {
            fpCYggDeviceSetTexture(this, in_Index, in_spTexture);
        }

        void Clear(const SYggClearParams& in_rParams)
        {
            fpCYggDeviceClear0(this, in_rParams);
        }

        void Clear(DWORD in_Flags, D3DCOLOR in_Color, float in_Z, DWORD in_Stencil)
        {
            fpCYggDeviceClear1(this, in_Flags, in_Color, in_Z, in_Stencil);
        }

        void GetResolution(float in_WidthRatio, float in_HeightRatio, uint32_t& out_Width, uint32_t& out_Height)
        {
            fpCYggDeviceGetResolution(this, in_WidthRatio, in_HeightRatio, out_Width, out_Height);
        }

        void Flush()
        {
            fpCYggDeviceFlush(this);
        }
    };

    BB_ASSERT_OFFSETOF(CYggDevice, m_pRenderingInfrastructure, 0x0);
    BB_ASSERT_OFFSETOF(CYggDevice, m_pD3DDevice, 0x4);
    BB_ASSERT_OFFSETOF(CYggDevice, m_pScheduler, 0x8);
    BB_ASSERT_OFFSETOF(CYggDevice, m_pAllocator, 0xC);
    BB_ASSERT_OFFSETOF(CYggDevice, m_InternalResolutionWidth, 0xC8);
    BB_ASSERT_OFFSETOF(CYggDevice, m_InternalResolutionHeight, 0xCC);
}
