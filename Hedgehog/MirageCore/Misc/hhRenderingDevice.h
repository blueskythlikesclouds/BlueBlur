#pragma once

#include <Hedgehog/MirageCore/Misc/hhRenderStateInfo.h>

namespace Hedgehog::Base
{
    class CStringSymbol;
}

namespace Hedgehog::Mirage
{
    class CPixelShaderData;

    class CRenderingDevice;
    class CRenderingInfrastructure;

    static inline BB_FUNCTION_PTR(void*, __thiscall, fpCRenderingDeviceSetRenderState, 0x40BB20,
        CRenderingDevice* This, D3DRENDERSTATETYPE in_Type, uint32_t in_Value);

    static inline BB_FUNCTION_PTR(void*, __thiscall, fpCRenderingDevicePushRenderState, 0x6F7FD0,
        CRenderingDevice* This, D3DRENDERSTATETYPE in_Type, uint32_t in_Value);

    static inline BB_FUNCTION_PTR(void*, __thiscall, fpCRenderingDevicePopRenderState, 0x6F8040,
        CRenderingDevice* This, D3DRENDERSTATETYPE in_Type);

    static inline BB_FUNCTION_PTR(void*, __thiscall, fpCRenderingDeviceLockRenderState, 0x6F7C60,
        CRenderingDevice* This, D3DRENDERSTATETYPE in_Type);

    static inline BB_FUNCTION_PTR(void*, __thiscall, fpCRenderingDeviceUnlockRenderState, 0x6F7C90,
        CRenderingDevice* This, D3DRENDERSTATETYPE in_Type);

    static inline BB_FUNCTION_PTR(void*, __thiscall, fpCRenderingDeviceSetPixelShaderParameterF, 0x411BF0,
        CRenderingDevice* This, const Hedgehog::Base::CStringSymbol& in_rSymbol, const float* in_pData, uint32_t in_Count, uint32_t in_Offset, const boost::shared_ptr<CPixelShaderData>& in_spPixelShaderData);

    static inline BB_FUNCTION_PTR(void, __thiscall, fpCRenderingDeviceSetViewMatrix, 0x6FA760,
        CRenderingDevice* This, const Math::CMatrix& in_rViewMatrix);

    static inline BB_FUNCTION_PTR(void, __thiscall, fpCRenderingDeviceSetAtlasParameterData, 0x6FA080,
        CRenderingDevice* This, float* const in_pData);

    class CRenderingDevice
    {
    public:
        CRenderingInfrastructure* m_pRenderingInfrastructure;
        DX_PATCH::IDirect3DDevice9* m_pD3DDevice;

        void* m_pGlobalParametersData;
        uint32_t m_GlobalParameterIndex;

        SRenderStateInfo m_RenderStateInfo;
        BB_INSERT_PADDING(0x298);
        const Base::CStringSymbol* m_pPixelShaderPermutation;
        BB_INSERT_PADDING(0x3C);

        void SetRenderState(D3DRENDERSTATETYPE in_Type, uint32_t in_Value)
        {
            fpCRenderingDeviceSetRenderState(this, in_Type, in_Value);
        }

        void PushRenderState(D3DRENDERSTATETYPE in_Type, uint32_t in_Value)
        {
            fpCRenderingDevicePushRenderState(this, in_Type, in_Value);
        }

        void PopRenderState(D3DRENDERSTATETYPE in_Type)
        {
            fpCRenderingDevicePopRenderState(this, in_Type);
        }

        void LockRenderState(D3DRENDERSTATETYPE in_Type)
        {
            fpCRenderingDeviceLockRenderState(this, in_Type);
        }

        void UnlockRenderState(D3DRENDERSTATETYPE in_Type)
        {
            fpCRenderingDeviceUnlockRenderState(this, in_Type);
        }

        void SetPixelShaderParameterF(const Hedgehog::Base::CStringSymbol& in_rSymbol, const float* in_pData, uint32_t in_Count, uint32_t in_Offset, const boost::shared_ptr<CPixelShaderData>& in_spPixelShaderData)
        {
            fpCRenderingDeviceSetPixelShaderParameterF(this, in_rSymbol, in_pData, in_Count, in_Offset, in_spPixelShaderData);
        }

        void SetViewMatrix(const Math::CMatrix& in_rViewMatrix)
        {
            fpCRenderingDeviceSetViewMatrix(this, in_rViewMatrix);
        }

        void SetAtlasParameterData(float* const in_pData)
        {
            fpCRenderingDeviceSetAtlasParameterData(this, in_pData);
        }
    };

    BB_ASSERT_OFFSETOF(CRenderingDevice, m_pRenderingInfrastructure, 0x0);
    BB_ASSERT_OFFSETOF(CRenderingDevice, m_pD3DDevice, 0x4);
    BB_ASSERT_OFFSETOF(CRenderingDevice, m_pGlobalParametersData, 0x8);
    BB_ASSERT_OFFSETOF(CRenderingDevice, m_GlobalParameterIndex, 0xC);
    BB_ASSERT_OFFSETOF(CRenderingDevice, m_RenderStateInfo, 0x10);
    BB_ASSERT_OFFSETOF(CRenderingDevice, m_pPixelShaderPermutation, 0x75B0);
    BB_ASSERT_SIZEOF(CRenderingDevice, 0x75F0);
}