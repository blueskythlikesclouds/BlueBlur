#pragma once

#include <Hedgehog/Universe/Engine/hhMessage.h>

namespace Sonic::Message
{
    class MsgSetVisible : public Hedgehog::Universe::MessageTypeSet
    {
    public:
        HH_FND_MSG_MAKE_TYPE(0x1681F38);

        bool m_Visible;
        
        MsgSetVisible(bool in_Visible) : m_Visible(in_Visible) {}
    };

    BB_ASSERT_OFFSETOF(MsgSetVisible, m_Visible, 0x10);
    BB_ASSERT_SIZEOF(MsgSetVisible, 0x14);
}