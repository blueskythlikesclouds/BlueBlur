#pragma once

#include <Hedgehog/Universe/Engine/hhMessage.h>

namespace Sonic::Message
{
	class MsgGetStageGuidePathController : public Hedgehog::Universe::MessageTypeGet
	{
	public:
		HH_FND_MSG_MAKE_TYPE(0x015C7B4C);
		boost::anonymous_shared_ptr m_spStageGuidePath;
	};
	BB_ASSERT_OFFSETOF(MsgGetStageGuidePathController, m_spStageGuidePath, 0x10);
	BB_ASSERT_SIZEOF(MsgGetStageGuidePathController, 0x18);
}