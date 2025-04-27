#pragma once

#include <Hedgehog/Universe/Engine/hhMessage.h>

namespace Sonic::Message
{
	class MsgStartCommonButtonSign : public Hedgehog::Universe::MessageTypeSet
	{
	public:
		HH_FND_MSG_MAKE_TYPE(0x01680730);
		int32_t m_ButtonType;
		int32_t m_ButtonType2;
		int32_t m_Direction;
		MsgStartCommonButtonSign(const int32_t in_ButtonType, const int32_t in_ButtonType2, const int32_t in_Direction) : m_ButtonType(in_ButtonType), m_ButtonType2(in_ButtonType2), m_Direction(in_Direction) {}
	};
	BB_ASSERT_OFFSETOF(MsgStartCommonButtonSign, m_ButtonType, 0x10);
	BB_ASSERT_OFFSETOF(MsgStartCommonButtonSign, m_ButtonType2, 0x14);
	BB_ASSERT_OFFSETOF(MsgStartCommonButtonSign, m_Direction, 0x18);
	BB_ASSERT_SIZEOF(MsgStartCommonButtonSign, 0x1C);
}