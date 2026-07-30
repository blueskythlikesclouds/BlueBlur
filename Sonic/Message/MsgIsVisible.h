#pragma once

#include <Hedgehog/Universe/Engine/hhMessage.h>

namespace Sonic::Message
{
    class MsgIsVisible : public Hedgehog::Universe::MessageTypeGet
    {
	public:
		HH_FND_MSG_MAKE_TYPE(0x1681F48);

        bool* m_pIsVisible;

        MsgIsVisible(bool* in_pIsVisible) : m_pIsVisible(in_pIsVisible) {}
        MsgIsVisible(bool& in_rIsVisible) : m_pIsVisible(&in_rIsVisible) {}
    };

    BB_ASSERT_OFFSETOF(MsgIsVisible, m_pIsVisible, 0x10);
    BB_ASSERT_SIZEOF(MsgIsVisible, 0x14);
}
