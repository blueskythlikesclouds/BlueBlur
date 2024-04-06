#pragma once

#include <Hedgehog/MirageCore/Renderable/hhRenderable.h>
#include <Hedgehog/MirageCore/Misc/hhVertexDeclarationPtr.h>
#include <Sonic/Object/ObjectBase.h>

namespace Hedgehog::Mirage
{
    class CPictureData;
}

namespace Sonic
{
    class CObjUpReel : public CObjectBase
    {
    public:
        class CReelRenderer : public Hedgehog::Mirage::CRenderable
        {
        public:
            struct SVertexData
            {
                CNoAlignVector Position;
                Hedgehog::Math::CVector2 TexCoord;
                CNoAlignVector Normal;
            };

            CObjUpReel* m_pObjUpReel;
            SVertexData m_aVertexData[14u];
            Hedgehog::Math::CMatrix m_WorldMatrix;
            float m_Field210;
            Hedgehog::Mirage::CVertexDeclarationPtr m_VertexDeclaration;
        };

        BB_INSERT_PADDING(0xC8);
        boost::shared_ptr<Hedgehog::Mirage::CPictureData> m_spDiffusePicture;
        boost::shared_ptr<Hedgehog::Mirage::CPictureData> m_spGlossPicture;
        BB_INSERT_PADDING(0x20);
    };

    BB_ASSERT_OFFSETOF(CObjUpReel::CReelRenderer::SVertexData, Position, 0x0);
    BB_ASSERT_OFFSETOF(CObjUpReel::CReelRenderer::SVertexData, TexCoord, 0xC);
    BB_ASSERT_OFFSETOF(CObjUpReel::CReelRenderer::SVertexData, Normal, 0x14);
    BB_ASSERT_SIZEOF(CObjUpReel::CReelRenderer::SVertexData, 0x20);

    BB_ASSERT_OFFSETOF(CObjUpReel::CReelRenderer, m_pObjUpReel, 0xC);
    BB_ASSERT_OFFSETOF(CObjUpReel::CReelRenderer, m_aVertexData, 0x10);
    BB_ASSERT_OFFSETOF(CObjUpReel::CReelRenderer, m_WorldMatrix, 0x1D0);
    BB_ASSERT_OFFSETOF(CObjUpReel::CReelRenderer, m_Field210, 0x210);
    BB_ASSERT_OFFSETOF(CObjUpReel::CReelRenderer, m_VertexDeclaration, 0x214);

    BB_ASSERT_OFFSETOF(CObjUpReel, m_spDiffusePicture, 0x1C8);
    BB_ASSERT_OFFSETOF(CObjUpReel, m_spGlossPicture, 0x1D0);
    BB_ASSERT_SIZEOF(CObjUpReel, 0x1F8);
}
