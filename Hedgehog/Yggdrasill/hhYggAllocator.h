#pragma once

#include <Hedgehog/Base/hhObject.h>

namespace Hedgehog::Yggdrasill
{
    class CYggAllocator : public Base::CObject
    {
    public:
        BB_INSERT_PADDING(0x1C);

        virtual ~CYggAllocator() = default;
    };

    BB_ASSERT_SIZEOF(CYggAllocator, 0x20);
}