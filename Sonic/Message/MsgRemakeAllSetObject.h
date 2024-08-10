#pragma once

#include <Hedgehog/Universe/Engine/hhMessage.h>

namespace Sonic::Message
{
	class MsgRemakeAllSetObject : public Hedgehog::Universe::MessageTypeSet
	{
	public:
		HH_FND_MSG_MAKE_TYPE(0x0167EE98);
		MsgRemakeAllSetObject() {}
	};
	BB_ASSERT_SIZEOF(MsgRemakeAllSetObject, 0x10);
}