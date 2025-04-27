namespace Hedgehog::Mirage
{
    inline BB_FUNCTION_PTR(void*, __thiscall, fpCRenderingDeviceSetRenderState, 0x40BB20,
        CRenderingDevice* This, D3DRENDERSTATETYPE in_Type, uint32_t in_Value);

    inline void CRenderingDevice::SetRenderState(D3DRENDERSTATETYPE in_Type, uint32_t in_Value)
    {
        fpCRenderingDeviceSetRenderState(this, in_Type, in_Value);
    }

    inline BB_FUNCTION_PTR(void*, __thiscall, fpCRenderingDevicePushRenderState, 0x6F7FD0,
        CRenderingDevice* This, D3DRENDERSTATETYPE in_Type, uint32_t in_Value);

    inline void CRenderingDevice::PushRenderState(D3DRENDERSTATETYPE in_Type, uint32_t in_Value)
    {
        fpCRenderingDevicePushRenderState(this, in_Type, in_Value);
    }

    inline BB_FUNCTION_PTR(void*, __thiscall, fpCRenderingDevicePopRenderState, 0x6F8040,
        CRenderingDevice* This, D3DRENDERSTATETYPE in_Type);

    inline void CRenderingDevice::PopRenderState(D3DRENDERSTATETYPE in_Type)
    {
        fpCRenderingDevicePopRenderState(this, in_Type);
    }

    inline BB_FUNCTION_PTR(void*, __thiscall, fpCRenderingDeviceLockRenderState, 0x6F7C60,
        CRenderingDevice* This, D3DRENDERSTATETYPE in_Type);

    inline void CRenderingDevice::LockRenderState(D3DRENDERSTATETYPE in_Type)
    {
        fpCRenderingDeviceLockRenderState(this, in_Type);
    }

    inline BB_FUNCTION_PTR(void*, __thiscall, fpCRenderingDeviceUnlockRenderState, 0x6F7C90,
        CRenderingDevice* This, D3DRENDERSTATETYPE in_Type);

    inline void CRenderingDevice::UnlockRenderState(D3DRENDERSTATETYPE in_Type)
    {
        fpCRenderingDeviceUnlockRenderState(this, in_Type);
    }

    inline BB_FUNCTION_PTR(void*, __thiscall, fpCRenderingDeviceSetPixelShaderParameterF, 0x411BF0,
        CRenderingDevice* This, const Hedgehog::Base::CStringSymbol& in_rSymbol, const float* in_pData, uint32_t in_Count, uint32_t in_Offset, const boost::shared_ptr<CPixelShaderData>& in_spPixelShaderData);

    inline void CRenderingDevice::SetPixelShaderParameterF(const Hedgehog::Base::CStringSymbol& in_rSymbol,
        const float* in_pData, uint32_t in_Count, uint32_t in_Offset,
        const boost::shared_ptr<CPixelShaderData>& in_spPixelShaderData)
    {
        fpCRenderingDeviceSetPixelShaderParameterF(this, in_rSymbol, in_pData, in_Count, in_Offset, in_spPixelShaderData);
    }

    inline BB_FUNCTION_PTR(void, __thiscall, fpCRenderingDeviceSetViewMatrix, 0x6FA760,
        CRenderingDevice* This, const Math::CMatrix& in_rViewMatrix);

    inline void CRenderingDevice::SetViewMatrix(const Math::CMatrix& in_rViewMatrix)
    {
        fpCRenderingDeviceSetViewMatrix(this, in_rViewMatrix);
    }

    inline BB_FUNCTION_PTR(void, __thiscall, fpCRenderingDeviceSetAtlasParameterData, 0x6FA080,
        CRenderingDevice* This, float* const in_pData);

    inline void CRenderingDevice::SetAtlasParameterData(float* const in_pData)
    {
        fpCRenderingDeviceSetAtlasParameterData(this, in_pData);
    }
}