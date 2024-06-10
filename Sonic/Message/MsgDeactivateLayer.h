﻿#pragma once

#include <Hedgehog/Universe/Engine/hhMessage.h>

namespace Sonic::Message
{
	class MsgDeactivateLayer : public Hedgehog::Universe::MessageTypeSet
	{
	public:
		HH_FND_MSG_MAKE_TYPE(0x0167F0D4);
		Hedgehog::Base::CSharedString m_SetLayerName;
		MsgDeactivateLayer(const Hedgehog::Base::CSharedString& in_rSetLayerName) : m_SetLayerName(in_rSetLayerName) {}
	};

	BB_ASSERT_OFFSETOF(MsgDeactivateLayer, m_SetLayerName, 0x10);
	BB_ASSERT_SIZEOF(MsgDeactivateLayer, 0x14);
}