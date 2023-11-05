#pragma once

#include <Hedgehog/Universe/Engine/hhStateMachine.h>

#include <Sonic/Animation/AnimationContext.h>
#include <Sonic/System/GameObject.h>

namespace Hedgehog::Mirage
{
    class CSingleElement;
}
namespace Hedgehog::Animation
{
    class CAnimationPose;
}

namespace Sonic::Player
{
    class CPlayerContext;
    
    class CPlayer : public CGameObject, public IAnimationContext
    {
    public:
        boost::shared_ptr<CPlayerContext> m_spContext;
        Hedgehog::Universe::TStateMachine<CPlayerContext> m_StateMachine;
        boost::shared_ptr<void> m_spPluginController1;
        boost::shared_ptr<void> m_spPluginController2;
        Hedgehog::Universe::TStateMachine<CPlayerContext> m_PostureStateMachine; // 0x124 - size 0x60, || end 0x184
        BB_INSERT_PADDING(0xB0);
        boost::shared_ptr<Hedgehog::Mirage::CSingleElement>    m_spCharacterModel;
        boost::shared_ptr<Hedgehog::Animation::CAnimationPose> m_spAnimationPose;
        BB_INSERT_PADDING(0x4C);
    };

    BB_ASSERT_OFFSETOF(CPlayer, m_spContext, 0xAC);
    BB_ASSERT_OFFSETOF(CPlayer, m_StateMachine, 0xB4);
    BB_ASSERT_OFFSETOF(CPlayer, m_spCharacterModel, 0x234);
    BB_ASSERT_OFFSETOF(CPlayer, m_spAnimationPose, 0x23C);
    BB_ASSERT_SIZEOF(CPlayer, 0x290);
}