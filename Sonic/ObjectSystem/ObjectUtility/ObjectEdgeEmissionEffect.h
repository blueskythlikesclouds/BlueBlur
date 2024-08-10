#pragma once

#include <Hedgehog/MirageCore/Renderable/hhSingleElementEffect.h>

namespace Sonic
{
    class CObjectEdgeEmissionEffect : public Hedgehog::Mirage::CSingleElementEffect
    {
    public:
        static constexpr size_t ms_pVtbl = 0x16CFB8C;

        float m_EdgeEmissionParam;
        float m_RateOfChange;
        float m_CurrentValue;
        float m_MaxValue;
    };

    CObjectEdgeEmissionEffect();
    CObjectEdgeEmissionEffect(float in_RateOfChange);

    BB_ASSERT_OFFSETOF(CObjectEdgeEmissionEffect, m_EdgeEmissionParam, 0x40);
    BB_ASSERT_OFFSETOF(CObjectEdgeEmissionEffect, m_RateOfChange, 0x44);
    BB_ASSERT_OFFSETOF(CObjectEdgeEmissionEffect, m_CurrentValue, 0x48);
    BB_ASSERT_OFFSETOF(CObjectEdgeEmissionEffect, m_MaxValue, 0x4C);
    BB_ASSERT_SIZEOF(CObjectEdgeEmissionEffect, 0x50);
}

#include <Sonic/ObjectSystem/ObjectUtility/CObjectEdgeEmissionEffect.inl>
