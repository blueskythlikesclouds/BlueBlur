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

    static inline BB_FUNCTION_PTR(bool, __thiscall, fpCMessageManagerAddMessageActor, 0x777B10,
        CMessageManager* This, const Hedgehog::Base::CSharedString& in_rCategory, CMessageActor* in_pMessageActor);

    class CMessageManager : public Hedgehog::Base::CSynchronizedObject
    {
    public:
        hh::map<size_t, CMessageActor*> m_MessageActorMap;

        CMessageActor* GetMessageActor(size_t in_ActorID) const
        {
            const auto findResult = m_MessageActorMap.find(in_ActorID);
            if (findResult != m_MessageActorMap.end())
                return findResult->second;
            else
                return nullptr;
        }

        bool AddMessageActor(const Hedgehog::Base::CSharedString& in_rCategory, CMessageActor* in_pMessageActor)
        {
            return fpCMessageManagerAddMessageActor(this, in_rCategory, in_pMessageActor);
        }
    };

    BB_ASSERT_OFFSETOF(CMessageManager, m_MessageActorMap, 0x4);
}