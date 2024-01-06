#pragma once

#include <Hedgehog/Universe/Engine/hhStateMachine.h>
#include <Sonic/Player/Character/Speed/PlayerSpeedContext.h>

namespace Sonic::Player
{
    class CPlayerSpeedContext::CStateSpeedBase : public Hedgehog::Universe::TStateMachine<CPlayerContext>::TState
    {
    public:
        BB_INSERT_PADDING(0x8);

        CStateSpeedBase(const bb_null_ctor& nil) : TState(nil) {}
        CStateSpeedBase();

        void SetBool(const Hedgehog::Base::CSharedString& in_rName, const bool& in_rValue);

        CPlayerSpeedContext* GetContext() const;

        virtual void ProcMsgOnGround() {}
    };

    BB_ASSERT_SIZEOF(CPlayerSpeedContext::CStateSpeedBase, 0x68);
}

#include <Sonic/Player/Character/Speed/State/PlayerSpeedStateBase.inl>