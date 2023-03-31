#pragma once

#include <Hedgehog/Universe/Engine/hhStateMachine.h>

namespace Hedgehog::Animation
{
    class CAnimationControlSingle;
}

namespace Sonic
{
    class IAnimationContext;

    class CAnimationState : public Hedgehog::Universe::TStateMachine<IAnimationContext>::TState
    {
    public:
        BB_INSERT_PADDING(0x20) {};
        boost::shared_ptr<Hedgehog::Animation::CAnimationControlSingle> m_spAnimationControlSingle;
        Hedgehog::Base::CSharedString m_TransitionState;
        float m_Field8C;
        uint32_t m_Field90;
        BB_INSERT_PADDING(0x108) {};
    };

    BB_ASSERT_OFFSETOF(CAnimationState, m_TransitionState, 0x88);
    BB_ASSERT_SIZEOF(CAnimationState, 0x19C);
}
