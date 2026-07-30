#pragma once

#include <Sonic/Animation/AnimationContext.h>
#include <Sonic/Player/Character/Base/SpinObject.h>

namespace Sonic::Player
{
    class CSonicSpin : public CSpinObject, public IAnimationContext
    {
    public:
        bool m_IsGhost;
        boost::shared_ptr<Hedgehog::Mirage::CSingleElement> m_spElement;
        BB_INSERT_PADDING(0x2C);
    };

    BB_ASSERT_OFFSETOF(CSonicSpin, m_IsGhost, 0xF8);
    BB_ASSERT_OFFSETOF(CSonicSpin, m_spElement, 0xFC);
    BB_ASSERT_SIZEOF(CSonicSpin, 0x130);
}
