#pragma once

#include <BlueBlur.inl>
#include <Hedgehog/Universe/Engine/hhUpdateInfo.h>

namespace Hedgehog::Universe
{
    class IParallelJob
    {
    public:
        IParallelJob() {}
        IParallelJob(const bb_null_ctor&) {}

        virtual ~IParallelJob() = default;

        virtual void ExecuteParallelJob(const SUpdateInfo& updateInfo) = 0;
    };

    BB_ASSERT_SIZEOF(IParallelJob, 0x4);
}