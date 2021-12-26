#pragma once

#include <Hedgehog/Universe/Engine/hhStateMachine.h>

#include <Sonic/Animation/AnimationContext.h>
#include <Sonic/System/GameObject.h>

namespace Sonic::Player
{
    class CPlayerContext;
    
    class CPlayer : public CGameObject, public IAnimationContext
    {
    public:
        boost::shared_ptr<CPlayerContext> m_spContext;
        Hedgehog::Universe::TStateMachine<CPlayerContext> m_StateMachine;
        BB_INSERT_PADDING(0x17C);
    };

    BB_ASSERT_OFFSETOF(CPlayer, m_spContext, 0xAC);
    BB_ASSERT_OFFSETOF(CPlayer, m_StateMachine, 0xB4);
    BB_ASSERT_SIZEOF(CPlayer, 0x290);
}