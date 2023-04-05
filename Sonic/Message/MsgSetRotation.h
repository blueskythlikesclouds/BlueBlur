#pragma once

#include <Hedgehog/Universe/Engine/hhMessage.h>

namespace Sonic::Message
{
    class MsgSetRotation : public Hedgehog::Universe::MessageTypeSet
    {
    public:
        HH_FND_MSG_MAKE_TYPE(0x168181C);

        Hedgehog::Math::CQuaternion m_Rotation;

        MsgSetRotation(const Hedgehog::Math::CQuaternion& in_rRotation) : m_Rotation(in_rRotation) {}
    };

    BB_ASSERT_OFFSETOF(MsgSetRotation, m_Rotation, 0x10);
    BB_ASSERT_SIZEOF(MsgSetRotation, 0x20);
}