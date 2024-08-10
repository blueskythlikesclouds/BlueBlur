#pragma once

#include <Hedgehog/Universe/Engine/hhMessage.h>

namespace Sonic::Message
{
    class MsgHitReactionPlate : public Hedgehog::Universe::MessageTypeSet
    {
    public:
        HH_FND_MSG_MAKE_TYPE(0x1680DC0);

        uint32_t m_Type;
        Hedgehog::Math::CVector m_Position;
        Hedgehog::Math::CVector m_Direction;
        uint32_t m_TargetActorID;
        BB_INSERT_PADDING(0x4);
        float m_JumpMinVelocity;
        float m_JumpMaxVelocity;
        BB_INSERT_PADDING(0x4);
        int32_t m_Score;
        BB_INSERT_PADDING(0x8);
    };

    BB_ASSERT_OFFSETOF(MsgHitReactionPlate, m_Type, 0x10);
    BB_ASSERT_OFFSETOF(MsgHitReactionPlate, m_Position, 0x20);
    BB_ASSERT_OFFSETOF(MsgHitReactionPlate, m_Direction, 0x30);
    BB_ASSERT_OFFSETOF(MsgHitReactionPlate, m_TargetActorID, 0x40);
    BB_ASSERT_OFFSETOF(MsgHitReactionPlate, m_JumpMinVelocity, 0x48);
    BB_ASSERT_OFFSETOF(MsgHitReactionPlate, m_JumpMaxVelocity, 0x4C);
    BB_ASSERT_OFFSETOF(MsgHitReactionPlate, m_Score, 0x54);
    BB_ASSERT_SIZEOF(MsgHitReactionPlate, 0x60);
}