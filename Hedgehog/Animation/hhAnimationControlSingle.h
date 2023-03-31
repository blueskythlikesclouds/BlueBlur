#pragma once

#include <Hedgehog/Animation/hhAnimationControl.h>

namespace Hedgehog::Animation
{
	class CAnimationData;

	class CAnimationControlSingle : public CAnimationControl
	{
	public:
		boost::shared_ptr<CAnimationData> m_spAnimationData;
	};

	BB_ASSERT_OFFSETOF(CAnimationControlSingle, m_spAnimationData, 0xE8);
	BB_ASSERT_SIZEOF(CAnimationControlSingle, 0xF0);
}
