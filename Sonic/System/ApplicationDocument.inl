namespace Sonic
{
    inline Hedgehog::Base::TSynchronizedPtr<CApplicationDocument> CApplicationDocument::GetInstance()
    {
        return *ms_pInstance;
    }

    inline void CApplicationDocument::AddMessageActor(const Hedgehog::Base::CSharedString& in_rCategory,
        Hedgehog::Universe::CMessageActor* in_pMessageActor)
    {
        m_pMember->m_pMessageManager->AddMessageActor(in_rCategory, in_pMessageActor);
    }

    template<typename T>
    inline T* Sonic::CApplicationDocument::GetService() const
    {
        auto findResult = m_ServiceMap.find(T::ms_ID);
        return findResult != m_ServiceMap.end() && findResult->second->Is<T>() ? static_cast<T*>(findResult->second.get()) : nullptr;
    }
}