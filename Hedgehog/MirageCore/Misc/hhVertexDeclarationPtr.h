#pragma once

#include <BlueBlur.inl>

namespace Hedgehog::Mirage
{
    class CRenderingInfrastructure;

    class CVertexDeclarationPtr
    {
    public:
        DX_PATCH::IDirect3DVertexDeclaration9* m_pD3DVertexDeclaration;
        CRenderingInfrastructure* m_pRenderingInfrastructure;
    };

    BB_ASSERT_OFFSETOF(CVertexDeclarationPtr, m_pD3DVertexDeclaration, 0x0);
    BB_ASSERT_OFFSETOF(CVertexDeclarationPtr, m_pRenderingInfrastructure, 0x4);
    BB_ASSERT_SIZEOF(CVertexDeclarationPtr, 0x8);
}