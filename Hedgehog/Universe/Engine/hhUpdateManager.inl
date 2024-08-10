namespace Hedgehog::Universe
{
    inline BB_FUNCTION_PTR(void, __thiscall, fpCUpdateManagerAdd, 0x77AF20,
        CUpdateManager* This, const Hedgehog::Base::CSharedString& in_rCategory, CUpdateUnit* in_pUpdateUnit);

    inline void CUpdateManager::AddUpdateUnit(const Hedgehog::Base::CSharedString& in_rCategory,
        CUpdateUnit* in_pUpdateUnit)
    {
        fpCUpdateManagerAdd(this, in_rCategory, in_pUpdateUnit);
    }
}