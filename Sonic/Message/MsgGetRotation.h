#pragma once

#include <Hedgehog/Universe/Engine/hhMessage.h>

namespace Sonic::Message
{
    class MsgGetRotation : public Hedgehog::Universe::MessageTypeGet
    {
    public:
        HH_FND_MSG_MAKE_TYPE(0x1681880);

        Hedgehog::Math::CQuaternion* m_pRotation;

        MsgGetRotation(Hedgehog::Math::CQuaternion* in_pRotation) : m_pRotation(in_pRotation) {}
        MsgGetRotation(Hedgehog::Math::CQuaternion& in_rRotation) : m_pRotation(&in_rRotation) {}
    };

    BB_ASSERT_OFFSETOF(MsgGetRotation, m_pRotation, 0x10);
    BB_ASSERT_SIZEOF(MsgGetRotation, 0x14);
}