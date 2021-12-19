#pragma once

#include <Hedgehog/Universe/Engine/hhMessage.h>

namespace Sonic::Message
{
    class MsgAddVelocity : public Hedgehog::Universe::MessageTypeSet
    {
    public:
        HH_FND_MSG_MAKE_TYPE(0x1681900);

        Hedgehog::Math::CVector m_Velocity;

        MsgAddVelocity(const Hedgehog::Math::CVector& impulse) : m_Velocity(impulse) {}
    };

    BB_ASSERT_OFFSETOF(MsgAddVelocity, m_Velocity, 0x10);
    BB_ASSERT_SIZEOF(MsgAddVelocity, 0x20);
}