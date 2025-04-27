#pragma once

#include <Hedgehog/MirageCore/Misc/hhRenderStateInfo.h>

namespace Hedgehog::Base
{
    class CStringSymbol;
}

namespace Hedgehog::Mirage
{
    class CVertexShaderData;
    class CPixelShaderData;
    class CRenderingInfrastructure;
    class CGlobalParametersData;
    class CMaterialData;
    class CSingleElementEffect;

    class CRenderingDevice
    {
    public:
        CRenderingInfrastructure* m_pRenderingInfrastructure;
        DX_PATCH::IDirect3DDevice9* m_pD3DDevice;

        CGlobalParametersData* m_pGlobalParametersData;
        uint32_t m_GlobalParameterIndex;

        SRenderStateInfo m_RenderStateInfo;
        DX_PATCH::IDirect3DVertexDeclaration9* m_pD3DVertexDeclaration;
        DX_PATCH::IDirect3DVertexShader9* m_pD3DVertexShader;
        DX_PATCH::IDirect3DPixelShader9* m_pD3DPixelShader;
        uint32_t m_Field7324;
        CVertexShaderData* m_pVertexShaderData;
        CPixelShaderData* m_pPixelShaderData;
        Hedgehog::Mirage::CMaterialData* m_pMaterialData;
        Hedgehog::Mirage::CSingleElementEffect* m_pSingleElementEffect;
        uint32_t m_ShaderPermutations;
        uint32_t m_VertexShaderPermutation;
        BB_INSERT_PADDING(0xD0);
        Hedgehog::Math::CMatrix44 m_aProjection[3];
        BB_INSERT_PADDING(0x50);
        Hedgehog::Math::CMatrix44 m_LightViewProjection;
        Hedgehog::Math::CMatrix44 m_VerticalLightViewProjection;
        BB_INSERT_PADDING(0x8);
        bool m_LocalLightEnable[4];
        bool m_HasBone;
        const Base::CStringSymbol* m_pPixelShaderPermutation; // PriorShaderPurpose
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
    BB_ASSERT_OFFSETOF(CRenderingDevice, m_pD3DVertexShader, 0x731C);
    BB_ASSERT_OFFSETOF(CRenderingDevice, m_pD3DPixelShader, 0x7320);
    BB_ASSERT_OFFSETOF(CRenderingDevice, m_Field7324, 0x7324);
    BB_ASSERT_OFFSETOF(CRenderingDevice, m_pVertexShaderData, 0x7328);
    BB_ASSERT_OFFSETOF(CRenderingDevice, m_pPixelShaderData, 0x732C);
    BB_ASSERT_OFFSETOF(CRenderingDevice, m_pMaterialData, 0x7330);
    BB_ASSERT_OFFSETOF(CRenderingDevice, m_pSingleElementEffect, 0x7334);
    BB_ASSERT_OFFSETOF(CRenderingDevice, m_ShaderPermutations, 0x7338);
    BB_ASSERT_OFFSETOF(CRenderingDevice, m_VertexShaderPermutation, 0x733C);
    BB_ASSERT_OFFSETOF(CRenderingDevice, m_aProjection, 0x7410);
    BB_ASSERT_OFFSETOF(CRenderingDevice, m_LightViewProjection, 0x7520);
    BB_ASSERT_OFFSETOF(CRenderingDevice, m_VerticalLightViewProjection, 0x7560);
    BB_ASSERT_OFFSETOF(CRenderingDevice, m_LocalLightEnable, 0x75A8);
    BB_ASSERT_OFFSETOF(CRenderingDevice, m_HasBone, 0x75AC);
    BB_ASSERT_OFFSETOF(CRenderingDevice, m_pPixelShaderPermutation, 0x75B0);
    BB_ASSERT_SIZEOF(CRenderingDevice, 0x75F0);
}

#include <Hedgehog/MirageCore/Misc/hhRenderingDevice.inl>