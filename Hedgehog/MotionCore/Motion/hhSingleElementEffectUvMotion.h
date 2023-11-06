#pragma once

#include <Hedgehog/Base/Container/hhVector.h>
#include <Hedgehog/MirageCore/Renderable/hhSingleElementEffect.h>

namespace Hedgehog::Motion
{
    class CTexcoordMotion;

    class CSingleElementEffectUvMotion : public Mirage::CSingleElementEffect
    {
    public:
        hh::vector<CTexcoordMotion> m_TexcoordMotionList;
    };

    BB_ASSERT_OFFSETOF(CSingleElementEffectUvMotion, m_TexcoordMotionList, 0x40);
    BB_ASSERT_SIZEOF(CSingleElementEffectUvMotion, 0x50);
}
