#pragma once

#include <Hedgehog/MirageCore/Renderable/hhSingleElementEffect.h>

namespace Sonic
{
    class CObjectEdgeEmissionEffect : public Hedgehog::Mirage::CSingleElementEffect
    {
    public:
        float m_EdgeEmissionParam;
        float m_Field44;
        float m_Field48;
        float m_Field4C;
    };

    BB_ASSERT_OFFSETOF(CObjectEdgeEmissionEffect, m_EdgeEmissionParam, 0x40);
    BB_ASSERT_SIZEOF(CObjectEdgeEmissionEffect, 0x50);
}