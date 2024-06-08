#pragma once

#include <Hedgehog/Database/System/hhDatabaseData.h>

namespace Hedgehog::Animation
{
    class CAnimationSkeleton : public Database::CDatabaseData
    {
    public:
        hk2010_2_0::hkaSkeleton* m_pHavokSkeleton;
        BB_INSERT_PADDING(0x34);
    };
    BB_ASSERT_SIZEOF(CAnimationSkeleton, 0x44);
}
