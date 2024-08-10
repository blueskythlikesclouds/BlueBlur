#pragma once

#include <Hedgehog/Universe/Engine/hhMessage.h>

namespace Sonic::Message
{
	class MsgActivateLayer : public Hedgehog::Universe::MessageTypeSet
	{
	public:
		HH_FND_MSG_MAKE_TYPE(0x0167F0C0);
		Hedgehog::Base::CSharedString m_SetLayerName;
		bool m_Field14;
		MsgActivateLayer(const Hedgehog::Base::CSharedString& in_rSetLayerName, const bool in_Field14) : m_SetLayerName(in_rSetLayerName), m_Field14(in_Field14) {}
	};
	BB_ASSERT_OFFSETOF(MsgActivateLayer, m_SetLayerName, 0x10);
	BB_ASSERT_OFFSETOF(MsgActivateLayer, m_Field14, 0x14);
	BB_ASSERT_SIZEOF(MsgActivateLayer, 0x18);
}