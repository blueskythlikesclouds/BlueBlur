namespace Hedgehog::Universe
{
    inline BB_FUNCTION_PTR(CUpdateUnit*, __thiscall, fpCUpdateUnitCtor, 0x76A950, CUpdateUnit* This);

    inline CUpdateUnit::CUpdateUnit() : CUpdateUnit(bb_null_ctor{})
    {
        fpCUpdateUnitCtor(this);
    }

    inline void CUpdateUnit::ExecuteParallelJob(const SUpdateInfo& in_rUpdateInfo)
    {
        UpdateParallel(in_rUpdateInfo);
    }
}