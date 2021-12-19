#pragma once

#include <Hedgehog/Universe/Engine/hhMessage.h>

namespace Sonic::Message
{
    class MsgGetRotation : public Hedgehog::Universe::MessageTypeGet
    {
    public:
        HH_FND_MSG_MAKE_TYPE(0x1681880);

        Hedgehog::Math::CQuaternion* m_pRotation;

        MsgGetRotation(Hedgehog::Math::CQuaternion* rotation) : m_pRotation(rotation) {}
        MsgGetRotation(Hedgehog::Math::CQuaternion& rotation) : m_pRotation(&rotation) {}
    };

    BB_ASSERT_OFFSETOF(MsgGetRotation, m_pRotation, 0x10);
    BB_ASSERT_SIZEOF(MsgGetRotation, 0x14);
}