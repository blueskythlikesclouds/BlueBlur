#pragma once

#include <Hedgehog/MirageCore/Misc/hhRenderStateInfo.h>

namespace Hedgehog::Base
{
    class CStringSymbol;
}

namespace Hedgehog::Mirage
{
    class CPixelShaderData;
    class CRenderingInfrastructure;
    class CGlobalParametersData;

    class CRenderingDevice
    {
    public:
        CRenderingInfrastructure* m_pRenderingInfrastructure;
        DX_PATCH::IDirect3DDevice9* m_pD3DDevice;

        CGlobalParametersData* m_pGlobalParametersData;
        uint32_t m_GlobalParameterIndex;

        SRenderStateInfo m_RenderStateInfo;
        DX_PATCH::IDirect3DVertexDeclaration9* m_pD3DVertexDeclaration;
        BB_INSERT_PADDING(0x294);
        const Base::CStringSymbol* m_pPixelShaderPermutation;
        BB_INSERT_PADDING(0x3C);

        void SetRenderState(D3DRENDERSTATETYPE in_Type, uint32_t in_Value);
        void PushRenderState(D3DRENDERSTATETYPE in_Type, uint32_t in_Value);
        void PopRenderState(D3DRENDERSTATETYPE in_Type);

        void LockRenderState(D3DRENDERSTATETYPE in_Type);
        void UnlockRenderState(D3DRENDERSTATETYPE in_Type);

        void SetPixelShaderParameterF(const Hedgehog::Base::CStringSymbol& in_rSymbol, const float* in_pData, uint32_t in_Count, uint32_t in_Offset, const boost::shared_ptr<CPixelShaderData>& in_spPixelShaderData);

        void SetViewMatrix(const Math::CMatrix& in_rViewMatrix);

        void SetAtlasParameterData(float* const in_pData);
    };

    BB_ASSERT_OFFSETOF(CRenderingDevice, m_pRenderingInfrastructure, 0x0);
    BB_ASSERT_OFFSETOF(CRenderingDevice, m_pD3DDevice, 0x4);
    BB_ASSERT_OFFSETOF(CRenderingDevice, m_pGlobalParametersData, 0x8);
    BB_ASSERT_OFFSETOF(CRenderingDevice, m_GlobalParameterIndex, 0xC);
    BB_ASSERT_OFFSETOF(CRenderingDevice, m_RenderStateInfo, 0x10);
    BB_ASSERT_OFFSETOF(CRenderingDevice, m_pD3DVertexDeclaration, 0x7318);
    BB_ASSERT_OFFSETOF(CRenderingDevice, m_pPixelShaderPermutation, 0x75B0);
    BB_ASSERT_SIZEOF(CRenderingDevice, 0x75F0);
}

#include <Hedgehog/MirageCore/Misc/hhRenderingDevice.inl>