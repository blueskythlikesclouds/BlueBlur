#pragma once

#include <Hedgehog/Universe/Engine/hhMessage.h>

namespace Sonic::Message
{
    class MsgAddImpulse : public Hedgehog::Universe::MessageTypeSet
    {
    public:
        HH_FND_MSG_MAKE_TYPE(0x168184C);

        Hedgehog::Math::CVector m_Impulse;

        MsgAddImpulse(const Hedgehog::Math::CVector& in_rImpulse) : m_Impulse(in_rImpulse) {}
    };

    BB_ASSERT_OFFSETOF(MsgAddImpulse, m_Impulse, 0x10);
    BB_ASSERT_SIZEOF(MsgAddImpulse, 0x20);
}