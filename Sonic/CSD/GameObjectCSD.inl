namespace Sonic
{
    inline BB_FUNCTION_PTR(void, __thiscall, fpCGameObjectCSDAddCallback, 0x10DB680,
        CGameObjectCSD* This, const Hedgehog::Base::THolder<CWorld>& in_rWorldHolder,
        Sonic::CGameDocument* in_pGameDocument, const boost::shared_ptr<Hedgehog::Database::CDatabase>& in_spDatabase);

    inline void CGameObjectCSD::AddCallback(const Hedgehog::Base::THolder<CWorld>& in_rWorldHolder,
        CGameDocument* in_pGameDocument, const boost::shared_ptr<Hedgehog::Database::CDatabase>& in_spDatabase)
    {
        fpCGameObjectCSDAddCallback(this, in_rWorldHolder, in_pGameDocument, in_spDatabase);
    }
}