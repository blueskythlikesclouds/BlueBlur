#pragma once

#include <Hedgehog/Base/Container/hhVector.h>
#include <Hedgehog/MirageCore/Renderable/hhSingleElementEffect.h>

namespace Hedgehog::Motion
{
    class CMaterialMotion;

    class CSingleElementEffectMatMotion : public Mirage::CSingleElementEffect
    {
    public:
        hh::vector<CMaterialMotion> m_MaterialMotionList;
    };

    BB_ASSERT_OFFSETOF(CSingleElementEffectMatMotion, m_MaterialMotionList, 0x40);
    BB_ASSERT_SIZEOF(CSingleElementEffectMatMotion, 0x50);
}
