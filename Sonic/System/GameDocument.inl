namespace Sonic
{
    inline Hedgehog::Base::TSynchronizedPtr<CGameDocument> CGameDocument::GetInstance()
    {
        return *ms_pInstance;
    }

    inline Hedgehog::Base::TSynchronizedPtr<CWorld> CGameDocument::GetWorld(
        const Hedgehog::Base::CSharedString& in_rName) const
    {
        const auto pair = m_pMember->m_Worlds.find(in_rName);
        return pair != m_pMember->m_Worlds.end() ? pair->second.get() : nullptr;
    }

    inline BB_FUNCTION_PTR(void, __stdcall, fpAddGameObject, 0xD631A0,
        CGameDocument* in_pGameDocument, const Hedgehog::Base::THolder<CWorld>& in_rWorldHolder,
        const boost::shared_ptr<CGameObject>& in_spGameObject, boost::shared_ptr<Hedgehog::Database::CDatabase>& in_spDatabase,
        CGameObject* in_pParentGameObject);

    inline void CGameDocument::AddGameObject(const boost::shared_ptr<CGameObject>& in_spGameObject,
        const char* in_pWorldName, CGameObject* in_pParentGameObject)
    {
        fpAddGameObject(this, *GetWorld(in_pWorldName), in_spGameObject, m_pMember->m_spDatabase, in_pParentGameObject);
    }

    inline void CGameDocument::AddUpdateUnit(const Hedgehog::Base::CSharedString& in_rCategory,
        Hedgehog::Universe::CUpdateUnit* in_pUpdateUnit)
    {
        m_pMember->m_spUpdateManager->AddUpdateUnit(in_rCategory, in_pUpdateUnit);
    }
}