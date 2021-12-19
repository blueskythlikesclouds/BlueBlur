#pragma once

#include <BlueBlur.inl>
#include <Hedgehog/Universe/Engine/hhParallelJob.h>

namespace Hedgehog::Universe
{
    class CUpdateUnit;

    static inline BB_FUNCTION_PTR(CUpdateUnit*, __thiscall, fpCUpdateUnitCtor, 0x76A950, CUpdateUnit* This);

    class CUpdateUnit : public Base::CObject, public IParallelJob
    {
    public:
        BB_INSERT_PADDING(0x24);

        CUpdateUnit(const bb_null_ctor&) : CObject(bb_null_ctor{}), IParallelJob(bb_null_ctor{}) {}

        CUpdateUnit() : CUpdateUnit(bb_null_ctor{})
        {
            fpCUpdateUnitCtor(this);
        }

        virtual void ExecuteParallelJob(const SUpdateInfo& updateInfo) override
        {
            UpdateParallel(updateInfo);
        }

        virtual void UpdateParallel(const SUpdateInfo& updateInfo) {}
        virtual void CUpdateUnit0C(void*) {}
    };

    BB_ASSERT_SIZEOF(CUpdateUnit, 0x28);
}
