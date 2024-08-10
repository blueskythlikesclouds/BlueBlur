#pragma once

#include <Sonic/Object/ObjectBase.h>
#include <Hedgehog/MirageCore/Renderable/hhRenderable.h>

namespace Sonic
{
    class CObjWallJumpBlock : public CObjectBase
    {
    public:
        class CRender : public Hedgehog::Mirage::CRenderable
        {
        public:
            struct SVertexData
            {
                Sonic::CNoAlignVector Position;
                Sonic::CNoAlignVector Normal;
                Sonic::CNoAlignVector Tangent;
                Sonic::CNoAlignVector Binormal;
                Hedgehog::Math::CVector2 TexCoord[4];
                float Color[4];
                uint32_t BlendIndices;
                uint32_t BlendWeight;
            };

            CObjWallJumpBlock* m_pObjWallJumpBlock;
            SVertexData m_aPanelVertexData[4];
            SVertexData m_aBackVertexData[4];
            SVertexData m_aArrowVertexData[4][4];
            Hedgehog::Mirage::CVertexDeclarationPtr m_VertexDeclaration;
        };

        BB_INSERT_PADDING(0x160);
        boost::shared_ptr<Hedgehog::Mirage::CMaterialData> m_spPanelMaterial;
        boost::shared_ptr<Hedgehog::Mirage::CMaterialData> m_spBackMaterial;
        boost::shared_ptr<Hedgehog::Mirage::CMaterialData> m_spArrowMaterial;
        boost::shared_ptr<Hedgehog::Motion::CMaterialAnimationData> m_spArrowMaterialAnimation;
        boost::shared_ptr<Hedgehog::Motion::CMaterialMotion> m_spArrowMaterialMotion;
        Hedgehog::Motion::SMaterialMotionData m_ArrowMaterialMotion;
        boost::shared_ptr<CRender> m_spRenderable;
    };

    BB_ASSERT_SIZEOF(CObjWallJumpBlock::CRender::SVertexData, 0x68);

    BB_ASSERT_OFFSETOF(CObjWallJumpBlock::CRender, m_aPanelVertexData, 0x10);
    BB_ASSERT_OFFSETOF(CObjWallJumpBlock::CRender, m_aBackVertexData, 0x1B0);
    BB_ASSERT_OFFSETOF(CObjWallJumpBlock::CRender, m_aArrowVertexData, 0x350);
    BB_ASSERT_OFFSETOF(CObjWallJumpBlock::CRender, m_VertexDeclaration, 0x9D0);
    BB_ASSERT_SIZEOF(CObjWallJumpBlock::CRender, 0x9D8);

    BB_ASSERT_OFFSETOF(CObjWallJumpBlock, m_spPanelMaterial, 0x260);
    BB_ASSERT_OFFSETOF(CObjWallJumpBlock, m_spBackMaterial, 0x268);
    BB_ASSERT_OFFSETOF(CObjWallJumpBlock, m_spArrowMaterial, 0x270);
    BB_ASSERT_OFFSETOF(CObjWallJumpBlock, m_spArrowMaterialAnimation, 0x278);
    BB_ASSERT_OFFSETOF(CObjWallJumpBlock, m_spArrowMaterialMotion, 0x280);
    BB_ASSERT_OFFSETOF(CObjWallJumpBlock, m_ArrowMaterialMotion, 0x288);
    BB_ASSERT_OFFSETOF(CObjWallJumpBlock, m_spRenderable, 0x2E8);
}
