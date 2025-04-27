#pragma once

#include <Sonic/Instancer/InstanceRenderObj.h>
#include <Hedgehog/MirageCore/Misc/hhVertexDeclarationPtr.h>

namespace Sonic
{
    class CInstanceRenderObjDX9 : public CInstanceRenderObj
    {
    public:
        Hedgehog::Mirage::CRenderingInfrastructure* m_pRenderingInfrastructure;
        Hedgehog::Mirage::CVertexDeclarationPtr m_VertexDeclarations[4];
        DX_PATCH::IDirect3DVertexBuffer9* m_pD3DVertexBuffers[1];
        uint32_t m_VertexSize;
        uint32_t m_VertexBufferIndex;
        void* m_pVertexData;
        uint32_t m_aInstanceNum[4];
        uint32_t m_VertexOffsets[4];
    };

    BB_ASSERT_OFFSETOF(CInstanceRenderObjDX9, m_pRenderingInfrastructure, 0xE8);
    BB_ASSERT_OFFSETOF(CInstanceRenderObjDX9, m_VertexDeclarations, 0xEC);
    BB_ASSERT_OFFSETOF(CInstanceRenderObjDX9, m_pD3DVertexBuffers, 0x10C);
    BB_ASSERT_OFFSETOF(CInstanceRenderObjDX9, m_VertexSize, 0x110);
    BB_ASSERT_OFFSETOF(CInstanceRenderObjDX9, m_VertexBufferIndex, 0x114);
    BB_ASSERT_OFFSETOF(CInstanceRenderObjDX9, m_pVertexData, 0x118);
    BB_ASSERT_OFFSETOF(CInstanceRenderObjDX9, m_aInstanceNum, 0x11C);
    BB_ASSERT_OFFSETOF(CInstanceRenderObjDX9, m_VertexOffsets, 0x12C);
    BB_ASSERT_SIZEOF(CInstanceRenderObjDX9, 0x140);
}