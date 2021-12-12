#pragma once

#include <BlueBlur.inl>

namespace Hedgehog::Base
{
    class CSharedString;
}

namespace Hedgehog::Universe
{
    class CMessageActor;
    class CMessageManager;
    
    static inline BB_FUNCTION_PTR(bool, __thiscall, fpCMessageManagerAdd, 0x777B10,
        CMessageManager* This, const Hedgehog::Base::CSharedString& category, CMessageActor* pMessageActor);

    class CMessageManager
    {
    public:
        bool Add(const Hedgehog::Base::CSharedString& category, CMessageActor* pMessageActor)
        {
            return fpCMessageManagerAdd(this, category, pMessageActor);
        }
    };
}