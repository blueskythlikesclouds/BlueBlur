#pragma once

#include <Hedgehog/Universe/Engine/hhUpdateInfo.h>

namespace Hedgehog::Universe
{
    class IParallelJob
    {
    public:
        IParallelJob() {}
        IParallelJob(const bb_null_ctor&) {}

        virtual ~IParallelJob() = default;

        virtual void ExecuteParallelJob(const SUpdateInfo& in_rUpdateInfo) = 0;
    };

    BB_ASSERT_SIZEOF(IParallelJob, 0x4);
}