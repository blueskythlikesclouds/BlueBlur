#pragma once

#include <Hedgehog/Base/Container/hhMap.h>
#include <Hedgehog/Base/Thread/hhSynchronizedObject.h>

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

    class CMessageManager : public Hedgehog::Base::CSynchronizedObject
    {
    public:
        hh::map<size_t, CMessageActor*> m_ActorMap;

        bool Add(const Hedgehog::Base::CSharedString& category, CMessageActor* pMessageActor)
        {
            return fpCMessageManagerAdd(this, category, pMessageActor);
        }
    };
}