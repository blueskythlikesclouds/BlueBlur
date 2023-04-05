#pragma once

#include <Hedgehog/Universe/Thread/hhParallelJob.h>

namespace Hedgehog::Universe
{
    class CUpdateUnit;

    static inline BB_FUNCTION_PTR(CUpdateUnit*, __thiscall, fpCUpdateUnitCtor, 0x76A950, CUpdateUnit* This);

    class CUpdateUnit : public Base::CObject, public IParallelJob
    {
    public:
        BB_INSERT_PADDING(0x24);

        CUpdateUnit(const bb_null_ctor& nil) : CObject(nil), IParallelJob(nil) {}

        CUpdateUnit() : CUpdateUnit(bb_null_ctor{})
        {
            fpCUpdateUnitCtor(this);
        }

        virtual ~CUpdateUnit();

        virtual void ExecuteParallelJob(const SUpdateInfo& in_rUpdateInfo) override
        {
            UpdateParallel(in_rUpdateInfo);
        }

        virtual void UpdateParallel(const SUpdateInfo& in_rUpdateInfo) {}
        virtual void UpdateSerial(const SUpdateInfo& in_rUpdateInfo) {}
    };

    BB_ASSERT_SIZEOF(CUpdateUnit, 0x28);
}
