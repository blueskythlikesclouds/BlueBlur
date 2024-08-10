#pragma once

#include <Hedgehog/Base/hhObject.h>

namespace Hedgehog::Mirage
{
    class CMaterialData;
    class CRenderInfo;

    class CSingleElementEffect : public Base::CObject 
    {
    public:
        uint32_t m_Field10{};
        Math::CVector4 m_ForceAlphaColor{ 1.0f, 1.0f, 1.0f, 1.0f };
        bool m_EnableForceAlphaColor{};

        virtual ~CSingleElementEffect() {}
        virtual uint32_t ApplyEffectBeforeMaterial(const CRenderInfo& in_rRenderInfo, const CMaterialData& in_rMaterialData) { return 0; }
        virtual uint32_t ApplyEffectAfterMaterial(const CRenderInfo& in_rRenderInfo, const CMaterialData& in_rMaterialData) { return 0; }
        virtual bool HasVisibilityMotion() { return false; }
    };

    BB_ASSERT_OFFSETOF(CSingleElementEffect, m_Field10, 0x10);
    BB_ASSERT_OFFSETOF(CSingleElementEffect, m_ForceAlphaColor, 0x20);
    BB_ASSERT_OFFSETOF(CSingleElementEffect, m_EnableForceAlphaColor, 0x30);
    BB_ASSERT_SIZEOF(CSingleElementEffect, 0x40);
}