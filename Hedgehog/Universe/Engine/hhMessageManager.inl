namespace Hedgehog::Universe
{
    inline CMessageActor* CMessageManager::GetMessageActor(size_t in_ActorID) const
    {
        const auto findResult = m_MessageActorMap.find(in_ActorID);
        if (findResult != m_MessageActorMap.end())
            return findResult->second;
        else
            return nullptr;
    }

    inline BB_FUNCTION_PTR(bool, __thiscall, fpCMessageManagerAddMessageActor, 0x777B10,
        CMessageManager* This, const Hedgehog::Base::CSharedString& in_rCategory, CMessageActor* in_pMessageActor);

    inline bool CMessageManager::AddMessageActor(const Hedgehog::Base::CSharedString& in_rCategory,
        CMessageActor* in_pMessageActor)
    {
        return fpCMessageManagerAddMessageActor(this, in_rCategory, in_pMessageActor);
    }
}