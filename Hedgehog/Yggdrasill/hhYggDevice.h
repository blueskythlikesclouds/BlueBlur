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

        void SetSamplerFilter(uint32_t in_Index, D3DTEXTUREFILTERTYPE in_MigFilter, D3DTEXTUREFILTERTYPE in_MagFilter, D3DTEXTUREFILTERTYPE in_MipFilter);

        void SetShader(const boost::shared_ptr<Mirage::CVertexShaderData>& in_spVertexShaderData, const boost::shared_ptr<Mirage::CPixelShaderData>& in_spPixelShaderData);
        void SetShader(const Mirage::SShaderPair& in_rShader);

        boost::shared_ptr<CYggTexture> CreateTexture(float in_WidthRatio, float in_HeightRatio, uint32_t in_Levels, uint32_t in_Usage, D3DFORMAT in_Format, D3DPOOL in_Pool, HANDLE* in_pSharedHandle) const;
        boost::shared_ptr<CYggTexture> CreateTexture(uint32_t in_Width, uint32_t in_Height, uint32_t in_Levels, uint32_t in_Usage, D3DFORMAT in_Format, D3DPOOL in_Pool, HANDLE* in_pSharedHandle) const;

        void DrawQuad2D(float* in_pBounds, float in_X, float in_Y);

        void UnsetSampler(uint32_t in_Index);

        void SetDepthStencil(const boost::shared_ptr<CYggSurface>& in_spSurface);
        void UnsetDepthStencil();

        boost::shared_ptr<CYggSurface> GetRenderTarget(uint32_t in_Index) const;
        void SetRenderTarget(uint32_t in_Index, const boost::shared_ptr<CYggSurface>& in_spSurface);
        void UnsetRenderTarget(uint32_t in_Index);

        void SetSamplerAddressMode(uint32_t in_Index, uint32_t in_Value);
        void SetTexture(uint32_t in_Index, const boost::shared_ptr<CYggTexture>& in_spTexture);

        void Clear(const SYggClearParams& in_rParams);
        void Clear(DWORD in_Flags, D3DCOLOR in_Color, float in_Z, DWORD in_Stencil);

        void GetResolution(float in_WidthRatio, float in_HeightRatio, uint32_t& out_Width, uint32_t& out_Height);

        void Flush();
    };

    BB_ASSERT_OFFSETOF(CYggDevice, m_pRenderingInfrastructure, 0x0);
    BB_ASSERT_OFFSETOF(CYggDevice, m_pD3DDevice, 0x4);
    BB_ASSERT_OFFSETOF(CYggDevice, m_pScheduler, 0x8);
    BB_ASSERT_OFFSETOF(CYggDevice, m_pAllocator, 0xC);
    BB_ASSERT_OFFSETOF(CYggDevice, m_InternalResolutionWidth, 0xC8);
    BB_ASSERT_OFFSETOF(CYggDevice, m_InternalResolutionHeight, 0xCC);
}


#include <Hedgehog/Yggdrasill/hhYggDevice.inl>