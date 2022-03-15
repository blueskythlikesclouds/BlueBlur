#pragma once

#include <Sonic/Player/Character/Speed/State/PlayerSpeedStateBase.h>

namespace Sonic::Player
{
    class CPlayerSpeedStateReactionLand : public CPlayerSpeedContext::CStateSpeedBase
    {
    public:
        static inline const char* ms_StateName = (const char*)0x15F5094;

        enum EAnimationType : uint32_t
        {
            eAnimationType_JumpSpring = 0,
            eAnimationType_ReactionJumpU = 1,
            eAnimationType_ReactionJumpL = 2,
            eAnimationType_ReactionJumpR = 3
        };

        uint32_t m_TargetActorID;
        BB_INSERT_PADDING(0x4);
        float m_JumpMinVelocity;
        float m_JumpMaxVelocity;
        BB_INSERT_PADDING(0xC);
        EAnimationType m_AnimationType;
    };

    BB_ASSERT_OFFSETOF(CPlayerSpeedStateReactionLand, m_TargetActorID, 0x68);
    BB_ASSERT_OFFSETOF(CPlayerSpeedStateReactionLand, m_JumpMinVelocity, 0x70);
    BB_ASSERT_OFFSETOF(CPlayerSpeedStateReactionLand, m_JumpMaxVelocity, 0x74);
    BB_ASSERT_OFFSETOF(CPlayerSpeedStateReactionLand, m_AnimationType, 0x84);
    BB_ASSERT_SIZEOF(CPlayerSpeedStateReactionLand, 0x88);
}