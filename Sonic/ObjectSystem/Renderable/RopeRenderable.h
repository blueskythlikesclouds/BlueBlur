#pragma once

#include <Hedgehog/MirageCore/Renderable/hhRenderable.h>
#include <Hedgehog/MirageCore/Misc/hhVertexDeclarationPtr.h>

namespace Hedgehog::Mirage
{
    class CVertexShaderData;
    class CPixelShaderData;
    class CPictureData;
}

namespace Sonic
{
    class CRopeRenderable : public Hedgehog::Mirage::CRenderable
    {
    public:
        struct SVertexData
        {
            CNoAlignVector Position;
            Hedgehog::Math::CVector2 TexCoord;
            CNoAlignVector Normal;
            uint32_t Color;
        };

        uint32_t m_VertexNum;
        boost::shared_ptr<Hedgehog::Mirage::CVertexShaderData> m_spVertexShader;
        boost::shared_ptr<Hedgehog::Mirage::CVertexShaderData> m_spPixelShader;
        BB_INSERT_PADDING(0x8);
        boost::shared_ptr<Hedgehog::Mirage::CPictureData> m_spDiffusePicture;
        boost::shared_ptr<Hedgehog::Mirage::CPictureData> m_spGlossPicture;
        Hedgehog::Mirage::CVertexDeclarationPtr m_VertexDeclaration;
        DX_PATCH::IDirect3DVertexBuffer9* m_pD3DVertexBuffer;
    };

    BB_ASSERT_OFFSETOF(CRopeRenderable::SVertexData, Position, 0x0);
    BB_ASSERT_OFFSETOF(CRopeRenderable::SVertexData, TexCoord, 0xC);
    BB_ASSERT_OFFSETOF(CRopeRenderable::SVertexData, Normal, 0x14);
    BB_ASSERT_OFFSETOF(CRopeRenderable::SVertexData, Color, 0x20);
    BB_ASSERT_SIZEOF(CRopeRenderable::SVertexData, 0x24);

    BB_ASSERT_OFFSETOF(CRopeRenderable, m_VertexNum, 0xC);
    BB_ASSERT_OFFSETOF(CRopeRenderable, m_spVertexShader, 0x10);
    BB_ASSERT_OFFSETOF(CRopeRenderable, m_spPixelShader, 0x18);
    BB_ASSERT_OFFSETOF(CRopeRenderable, m_spDiffusePicture, 0x28);
    BB_ASSERT_OFFSETOF(CRopeRenderable, m_spGlossPicture, 0x30);
    BB_ASSERT_OFFSETOF(CRopeRenderable, m_VertexDeclaration, 0x38);
    BB_ASSERT_OFFSETOF(CRopeRenderable, m_pD3DVertexBuffer, 0x40);
    BB_ASSERT_SIZEOF(CRopeRenderable, 0x44);
}