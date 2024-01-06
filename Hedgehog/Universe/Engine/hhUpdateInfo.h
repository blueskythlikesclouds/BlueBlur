#pragma once

#include <Hedgehog/Base/Type/hhSharedString.h>

namespace Hedgehog::Universe
{
    struct SUpdateInfo
    {
        float DeltaTime;
        uint32_t Frame;
        Base::CSharedString Category;
    };

    BB_ASSERT_OFFSETOF(SUpdateInfo, DeltaTime, 0x0);
    BB_ASSERT_OFFSETOF(SUpdateInfo, Frame, 0x4);
    BB_ASSERT_OFFSETOF(SUpdateInfo, Category, 0x8);
    BB_ASSERT_SIZEOF(SUpdateInfo, 0xC);
}