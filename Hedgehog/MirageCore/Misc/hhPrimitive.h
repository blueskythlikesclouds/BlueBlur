#pragma once

#include <BlueBlur.inl>

namespace Hedgehog::Mirage
{
    class CPrimitive
    {
    public:
        uint8_t m_VertexSizes[8];
        size_t m_VertexOffsets[8];
        DX_PATCH::IDirect3DVertexBuffer9* m_D3DVertexBuffers[8];
        DX_PATCH::IDirect3DIndexBuffer9* m_pD3DIndexBuffer;
        BB_INSERT_PADDING(0x4);
    };

    BB_ASSERT_OFFSETOF(CPrimitive, m_VertexSizes, 0x0);
    BB_ASSERT_OFFSETOF(CPrimitive, m_VertexOffsets, 0x8);
    BB_ASSERT_OFFSETOF(CPrimitive, m_D3DVertexBuffers, 0x28);
    BB_ASSERT_OFFSETOF(CPrimitive, m_pD3DIndexBuffer, 0x48);
    BB_ASSERT_SIZEOF(CPrimitive, 0x50);
}