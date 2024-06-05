#pragma once

#include <Hedgehog/Universe/Engine/hhMessage.h>

namespace Sonic::Message
{
	class MsgDeactivatelayer : public Hedgehog::Universe::MessageTypeSet
	{
	public:
		HH_FND_MSG_MAKE_TYPE(0x0167F0D4);
		Hedgehog::base::CSharedString m_SetLayerName;
		MsgDeactivatelayer(const Hedgehog::base::CSharedString& in_SetLayerName) : m_SetLayerName(in_SetLayerName) {}
	};

	BB_ASSERT_OFFSETOF(MsgDeactivatelayer, m_SetLayerName, 0x10);
	BB_ASSERT_SIZEOF(MsgDeactivatelayer, 0x14);
}