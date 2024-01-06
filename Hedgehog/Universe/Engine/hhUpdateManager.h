#pragma once

#include <BlueBlur.inl>

namespace Hedgehog::Base
{
    class CSharedString;
}

namespace Hedgehog::Universe
{
    class CUpdateUnit;
    class CUpdateManager;

    static inline BB_FUNCTION_PTR(void, __thiscall, fpCUpdateManagerAdd, 0x77AF20,
        CUpdateManager* This, const Hedgehog::Base::CSharedString& in_rCategory, CUpdateUnit* in_pUpdateUnit);

    class CUpdateManager
    {
    public:
        void AddUpdateUnit(const Hedgehog::Base::CSharedString& in_rCategory, CUpdateUnit* in_pUpdateUnit)
        {
            fpCUpdateManagerAdd(this, in_rCategory, in_pUpdateUnit);
        }
    };
}