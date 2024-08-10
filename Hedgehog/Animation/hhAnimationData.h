#pragma once

#include <Hedgehog/Database/System/hhDatabaseData.h>
#include <Hedgehog/Base/Container/hhMap.h>

namespace Hedgehog::Animation
{
	class CAnimationData : public Hedgehog::Database::CDatabaseData
	{
	public:
		BB_INSERT_PADDING(0x04);
		hk2010_2_0::hkaAnimationBinding* m_pHkaAnimationBinding;
		BB_INSERT_PADDING(0x04);
		Hedgehog::map<CDatabaseData*, boost::shared_ptr<CDatabaseData>> m_Field18;
		BB_INSERT_PADDING(0x20);
		float m_Field44;
		BB_INSERT_PADDING(0x04);
	};
	BB_ASSERT_OFFSETOF(CAnimationData, m_pHkaAnimationBinding, 0x10);
	BB_ASSERT_OFFSETOF(CAnimationData, m_Field18, 0x18);
	BB_ASSERT_OFFSETOF(CAnimationData, m_Field44, 0x44);
	BB_ASSERT_SIZEOF(CAnimationData, 0x4C);
}