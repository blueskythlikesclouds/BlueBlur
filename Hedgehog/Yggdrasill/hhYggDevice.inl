namespace Hedgehog::Yggdrasill
{
    inline BB_FUNCTION_PTR(void, __thiscall, fpCYggDeviceSetSamplerFilter, 0x411CF0,
        CYggDevice* This, uint32_t in_Index, D3DTEXTUREFILTERTYPE in_MigFilter, D3DTEXTUREFILTERTYPE in_MagFilter, D3DTEXTUREFILTERTYPE in_MipFilter);

    inline void CYggDevice::SetSamplerFilter(uint32_t in_Index, D3DTEXTUREFILTERTYPE in_MigFilter,
        D3DTEXTUREFILTERTYPE in_MagFilter, D3DTEXTUREFILTERTYPE in_MipFilter)
    {
        fpCYggDeviceSetSamplerFilter(this, in_Index, in_MigFilter, in_MagFilter, in_MipFilter);
    }

    inline BB_FUNCTION_PTR(void, __thiscall, fpCYggDeviceSetShader, 0x415EE0,
        CYggDevice* This, const boost::shared_ptr<Hedgehog::Mirage::CVertexShaderData>& in_spVertexShaderData, const boost::shared_ptr<Hedgehog::Mirage::CPixelShaderData>& in_spPixelShaderData);

    inline void CYggDevice::SetShader(const boost::shared_ptr<Mirage::CVertexShaderData>& in_spVertexShaderData,
        const boost::shared_ptr<Mirage::CPixelShaderData>& in_spPixelShaderData)
    {
        fpCYggDeviceSetShader(this, in_spVertexShaderData, in_spPixelShaderData);
    }

    inline void CYggDevice::SetShader(const Mirage::SShaderPair& in_rShader)
    {
        SetShader(in_rShader.m_spVertexShader, in_rShader.m_spPixelShader);
    }

    inline BB_FUNCTION_PTR(void, __thiscall, fpCYggDeviceCreateTexture0, 0x7884C0,
        const CYggDevice* This, boost::shared_ptr<CYggTexture>& out_spTexture, float in_WidthRatio, float in_HeightRatio, uint32_t in_Levels, uint32_t in_Usage, D3DFORMAT in_Format, D3DPOOL in_Pool, HANDLE* in_pSharedHandle);

    inline boost::shared_ptr<CYggTexture> CYggDevice::CreateTexture(float in_WidthRatio, float in_HeightRatio,
        uint32_t in_Levels, uint32_t in_Usage, D3DFORMAT in_Format, D3DPOOL in_Pool, HANDLE* in_pSharedHandle) const
    {
        boost::shared_ptr<CYggTexture> spTexture;
        fpCYggDeviceCreateTexture0(this, spTexture, in_WidthRatio, in_HeightRatio, in_Levels, in_Usage, in_Format, in_Pool, in_pSharedHandle);
        return spTexture;
    }

    inline BB_FUNCTION_PTR(void, __thiscall, fpCYggDeviceCreateTexture1, 0x788450,
        const CYggDevice* This, boost::shared_ptr<CYggTexture>& out_spTexture, uint32_t in_Width, uint32_t in_Height, uint32_t in_Levels, uint32_t in_Usage, D3DFORMAT in_Format, D3DPOOL in_Pool, HANDLE* in_pSharedHandle);

    inline boost::shared_ptr<CYggTexture> CYggDevice::CreateTexture(uint32_t in_Width, uint32_t in_Height,
        uint32_t in_Levels, uint32_t in_Usage, D3DFORMAT in_Format, D3DPOOL in_Pool, HANDLE* in_pSharedHandle) const
    {
        boost::shared_ptr<CYggTexture> spTexture;
        fpCYggDeviceCreateTexture1(this, spTexture, in_Width, in_Height, in_Levels, in_Usage, in_Format, in_Pool, in_pSharedHandle);
        return spTexture;
    }

    inline BB_FUNCTION_PTR(void, __thiscall, fpCYggDeviceDrawQuad2D, 0x786620,
        CYggDevice* This, float* in_pBounds, float in_X, float in_Y);

    inline void CYggDevice::DrawQuad2D(float* in_pBounds, float in_X, float in_Y)
    {
        fpCYggDeviceDrawQuad2D(this, in_pBounds, in_X, in_Y);
    }

    inline BB_FUNCTION_PTR(void, __thiscall, fpCYggDeviceUnsetSampler, 0x412120,
        CYggDevice* This, uint32_t in_Index);

    inline void CYggDevice::UnsetSampler(uint32_t in_Index)
    {
        fpCYggDeviceUnsetSampler(this, in_Index);
    }

    inline BB_FUNCTION_PTR(void, __thiscall, fpCYggDeviceSetDepthStencil, 0x785D10,
        CYggDevice* This, const boost::shared_ptr<CYggSurface>& in_spSurface);

    inline void CYggDevice::SetDepthStencil(const boost::shared_ptr<CYggSurface>& in_spSurface)
    {
        fpCYggDeviceSetDepthStencil(this, in_spSurface);
    }

    inline void CYggDevice::UnsetDepthStencil()
    {
        SetDepthStencil(boost::shared_ptr<CYggSurface>());
    }

    inline BB_FUNCTION_PTR(void, __thiscall, fpCYggDeviceGetRenderTarget, 0x786030,
        const CYggDevice* This, boost::shared_ptr<CYggSurface>& out_spSurface, uint32_t in_Index);

    inline boost::shared_ptr<CYggSurface> CYggDevice::GetRenderTarget(uint32_t in_Index) const
    {
        boost::shared_ptr<CYggSurface> spSurface;
        fpCYggDeviceGetRenderTarget(this, spSurface, in_Index);
        return spSurface;
    }

    inline BB_FUNCTION_PTR(void, __thiscall, fpCYggDeviceSetRenderTarget, 0x785D00,
        CYggDevice* This, uint32_t in_Index, const boost::shared_ptr<CYggSurface>& in_spSurface);

    inline void CYggDevice::SetRenderTarget(uint32_t in_Index, const boost::shared_ptr<CYggSurface>& in_spSurface)
    {
        fpCYggDeviceSetRenderTarget(this, in_Index, in_spSurface);
    }

    inline void CYggDevice::UnsetRenderTarget(uint32_t in_Index)
    {
        SetRenderTarget(in_Index, boost::shared_ptr<CYggSurface>());
    }

    inline BB_FUNCTION_PTR(void, __thiscall, fpCYggDeviceSetSamplerAddressMode, 0x411CA0,
        CYggDevice* This, uint32_t in_Index, uint32_t in_Value);

    inline void CYggDevice::SetSamplerAddressMode(uint32_t in_Index, uint32_t in_Value)
    {
        fpCYggDeviceSetSamplerAddressMode(this, in_Index, in_Value);
    }

    inline BB_FUNCTION_PTR(void, __thiscall, fpCYggDeviceSetTexture, 0x7865A0,
        CYggDevice* This, uint32_t in_Index, const boost::shared_ptr<CYggTexture>& in_spTexture);

    inline void CYggDevice::SetTexture(uint32_t in_Index, const boost::shared_ptr<CYggTexture>& in_spTexture)
    {
        fpCYggDeviceSetTexture(this, in_Index, in_spTexture);
    }

    inline BB_FUNCTION_PTR(void, __thiscall, fpCYggDeviceClear0, 0x785EE0,
        CYggDevice* This, const SYggClearParams& in_rParams);

    inline void CYggDevice::Clear(const SYggClearParams& in_rParams)
    {
        fpCYggDeviceClear0(this, in_rParams);
    }

    inline BB_FUNCTION_PTR(void, __thiscall, fpCYggDeviceClear1, 0x416650,
        CYggDevice* This, DWORD in_Flags, D3DCOLOR in_Color, float in_Z, DWORD in_Stencil);

    inline void CYggDevice::Clear(DWORD in_Flags, D3DCOLOR in_Color, float in_Z, DWORD in_Stencil)
    {
        fpCYggDeviceClear1(this, in_Flags, in_Color, in_Z, in_Stencil);
    }

    inline BB_FUNCTION_PTR(void, __thiscall, fpCYggDeviceGetResolution, 0x785A90,
        CYggDevice* This, float in_WidthRatio, float in_HeightRatio, uint32_t& out_Width, uint32_t& out_Height);

    inline void CYggDevice::GetResolution(float in_WidthRatio, float in_HeightRatio, uint32_t& out_Width,
        uint32_t& out_Height)
    {
        fpCYggDeviceGetResolution(this, in_WidthRatio, in_HeightRatio, out_Width, out_Height);
    }

    inline BB_FUNCTION_PTR(void, __thiscall, fpCYggDeviceFlush, 0x786070,
        CYggDevice* This);

    inline void CYggDevice::Flush()
    {
        fpCYggDeviceFlush(this);
    }
}