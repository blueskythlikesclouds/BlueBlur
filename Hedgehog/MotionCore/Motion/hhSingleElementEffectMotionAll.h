#pragma once
#pragma once

#include <Hedgehog/Base/Container/hhVector.h>
#include <Hedgehog/MirageCore/Renderable/hhSingleElementEffect.h>

namespace Hedgehog::Motion
{
    class CTexcoordMotion;
    class CMaterialMotion;
    class CTexpatternMotion;
    class CVisibilityMotion;
    class CMorphMotion;

    class CSingleElementEffectMotionAll : public Mirage::CSingleElementEffect
    {
    public:
        bool m_IsInForeground{};
        hh::vector<CTexcoordMotion> m_TexcoordMotionList;
        hh::vector<CMaterialMotion> m_MaterialMotionList;
        hh::vector<CTexpatternMotion> m_TexpatternMotionList;
        hh::vector<CVisibilityMotion> m_VisibilityMotionList;
        hh::vector<CMorphMotion> m_MorphMotionList;
    };

    BB_ASSERT_OFFSETOF(CSingleElementEffectMotionAll, m_IsInForeground, 0x40);
    BB_ASSERT_OFFSETOF(CSingleElementEffectMotionAll, m_TexcoordMotionList, 0x44);
    BB_ASSERT_OFFSETOF(CSingleElementEffectMotionAll, m_MaterialMotionList, 0x54);
    BB_ASSERT_OFFSETOF(CSingleElementEffectMotionAll, m_TexpatternMotionList, 0x64);
    BB_ASSERT_OFFSETOF(CSingleElementEffectMotionAll, m_VisibilityMotionList, 0x74);
    BB_ASSERT_OFFSETOF(CSingleElementEffectMotionAll, m_MorphMotionList, 0x84);
    BB_ASSERT_SIZEOF(CSingleElementEffectMotionAll, 0xA0);
}