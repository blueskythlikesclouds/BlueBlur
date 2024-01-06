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
}