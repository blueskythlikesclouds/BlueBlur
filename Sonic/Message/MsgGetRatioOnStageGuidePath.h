#pragma once

#include <Hedgehog/Universe/Engine/hhMessage.h>

namespace Sonic::Message
{
	class MsgGetRatioOnStageGuidePath : public Hedgehog::Universe::MessageTypeGet
	{
	public:
		HH_FND_MSG_MAKE_TYPE(0x015C7B8C);

		float m_Ratio;
		float m_Distance;
		float m_Field018;
	};
	BB_ASSERT_OFFSETOF(MsgGetRatioOnStageGuidePath, m_Ratio, 0x10);
	BB_ASSERT_OFFSETOF(MsgGetRatioOnStageGuidePath, m_Distance, 0x14);
	BB_ASSERT_OFFSETOF(MsgGetRatioOnStageGuidePath, m_Field018, 0x18);
	BB_ASSERT_SIZEOF(MsgGetRatioOnStageGuidePath, 0x1C);
}