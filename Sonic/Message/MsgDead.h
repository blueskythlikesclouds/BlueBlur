#pragma once

#include <Hedgehog/Universe/Engine/hhMessage.h>

namespace Sonic::Message
{
    class MsgDead : public Hedgehog::Universe::MessageTypeSet
    {
    public:
        HH_FND_MSG_MAKE_TYPE(0x1681F1C);

        bool m_OutOfControl;

        MsgDead(const bool in_OutOfControl) : m_OutOfControl(in_OutOfControl) {}
    };

    BB_ASSERT_OFFSETOF(MsgDead, m_OutOfControl, 0x10);
    BB_ASSERT_SIZEOF(MsgDead, 0x14);
}