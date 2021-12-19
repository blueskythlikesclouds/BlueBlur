#pragma once

#include <Hedgehog/Base/Type/hhSharedString.h>

namespace Hedgehog::Universe
{
    struct SUpdateInfo
    {
        float ElapsedTime;
        uint32_t Frame;
        Base::CSharedString Category;
    };

    BB_ASSERT_OFFSETOF(SUpdateInfo, ElapsedTime, 0x0);
    BB_ASSERT_OFFSETOF(SUpdateInfo, Frame, 0x4);
    BB_ASSERT_OFFSETOF(SUpdateInfo, Category, 0x8);
    BB_ASSERT_SIZEOF(SUpdateInfo, 0xC);
}
