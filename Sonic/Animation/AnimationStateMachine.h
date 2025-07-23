#pragma once

#include <Hedgehog/Universe/Engine/hhStateMachineBase.h>

namespace Sonic
{
    class CAnimationState;
    class CAnimationStateSingle;
    class IAnimationContext;

    class CAnimationStateMachine : public Hedgehog::Universe::TStateMachine<IAnimationContext>
    {
    public:
        hh::map<Hedgehog::Base::CSharedString, boost::shared_ptr<Sonic::CAnimationStateSingle>> m_Animations;
        BB_INSERT_PADDING(28) {};

        CAnimationStateMachine(const bb_null_ctor&) : TStateMachine(bb_null_ctor{}) {}
        CAnimationStateMachine();

        boost::shared_ptr<CAnimationState> AddAnimationState(const Hedgehog::Base::CSharedString& in_rName);
        const boost::shared_ptr<CAnimationState>& GetAnimationState(const Hedgehog::Base::CSharedString& in_rName);
        boost::shared_ptr<CAnimationState> ChangeState(const Hedgehog::Base::CSharedString& in_rName);

        void SetAnimationBlend(const Hedgehog::Base::CSharedString& in_rBaseAnim, const Hedgehog::Base::CSharedString& in_rTargetAnim, float in_BlendTime);
        void Update(const Hedgehog::Universe::SUpdateInfo& in_rUpdateInfo);
    };

    BB_ASSERT_SIZEOF(CAnimationStateMachine, 0x88);
}

#include <Sonic/Animation/AnimationStateMachine.inl>