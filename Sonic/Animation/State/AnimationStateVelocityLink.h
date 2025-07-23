#pragma once

#include <Sonic/Animation/AnimationState.h>

namespace Sonic
{
	class CAnimationStateVelocityLink : public Sonic::CAnimationState
	{
	public:
		struct SVelocityTransitionPoint
		{
			int Field00;
			float PreviousPointValue;
			float PointValue;
			char t2;
		};
		hh::vector<SVelocityTransitionPoint> m_Transitions;
		float m_Field1AC;
		float m_Field1B0;
		int m_Field1B4;
		float m_Field1B8;

		inline BB_NOINLINE void* fpCAnimationStateVelocityLinkCtor
		(
			CAnimationStateVelocityLink* This,
			float a2,
			float a3
		)
		{
			uint32_t pCAnimationStateVelocityLinkCtor = 0xCDE120;
			__asm
			{
				push a3
				push a2
				mov eax, This
				call[pCAnimationStateVelocityLinkCtor]
			}
		}
		CAnimationStateVelocityLink(float a2, float a3)
		{
			fpCAnimationStateVelocityLinkCtor(this, a2, a3);
		}
	};
	BB_ASSERT_OFFSETOF(CAnimationStateVelocityLink, m_Transitions, 0x19C);
	BB_ASSERT_OFFSETOF(CAnimationStateVelocityLink, m_Field1AC, 0x1AC);
	BB_ASSERT_OFFSETOF(CAnimationStateVelocityLink, m_Field1B0, 0x1B0);
	BB_ASSERT_OFFSETOF(CAnimationStateVelocityLink, m_Field1B4, 0x1B4);
	BB_ASSERT_OFFSETOF(CAnimationStateVelocityLink, m_Field1B8, 0x1B8);
}