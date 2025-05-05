#pragma once

#include <Hedgehog/Base/Container/hhVector.h>
#include <Hedgehog/Universe/Engine/hhMessage.h>

namespace Sonic::Message
{
	class MsgGetObjectTriggerType : public Hedgehog::Universe::MessageTypeSet
	{
	public:
		HH_FND_MSG_MAKE_TYPE(0x1681190);

		Hedgehog::vector<uint32_t>* m_pTriggerTypeList;

		MsgGetObjectTriggerType(Hedgehog::vector<uint32_t>* in_pTriggerTypeList) : m_pTriggerTypeList(in_pTriggerTypeList) {}
		MsgGetObjectTriggerType(Hedgehog::vector<uint32_t>& in_rTriggerTypeList) : m_pTriggerTypeList(&in_rTriggerTypeList) {}
	};

	BB_ASSERT_OFFSETOF(MsgGetObjectTriggerType, m_pTriggerTypeList, 0x10);
	BB_ASSERT_SIZEOF(MsgGetObjectTriggerType, 0x14);
}