#pragma once

#include <Hedgehog/Universe/Engine/hhMessage.h>

namespace Sonic::Message
{
    class MsgSetPosition : public Hedgehog::Universe::MessageTypeSet
    {
    public:
        HH_FND_MSG_MAKE_TYPE(0x168180C);

        Hedgehog::Math::CVector m_Position;

        MsgSetPosition(const Hedgehog::Math::CVector& in_rPosition) : m_Position(in_rPosition) {}
    };

    BB_ASSERT_OFFSETOF(MsgSetPosition, m_Position, 0x10);
    BB_ASSERT_SIZEOF(MsgSetPosition, 0x20);
}