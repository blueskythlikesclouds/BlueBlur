namespace Sonic
{
    inline uint32_t pCGameObjectCtor = 0xD601F0;

    inline BB_NOINLINE void fCGameObjectCtor(CGameObject* This)
    {
        __asm
        {
            mov edi, This
            call[pCGameObjectCtor]
        }
    }

    inline CGameObject::CGameObject() : CGameObject(bb_null_ctor{})
    {
        fCGameObjectCtor(this);
    }

    inline BB_FUNCTION_PTR(void, __thiscall, fpCGameObjectUpdateParallel, 0xD5F2A0,
        CGameObject* This, const Hedgehog::Universe::SUpdateInfo& in_rUpdateInfo);

    inline void CGameObject::UpdateParallel(const Hedgehog::Universe::SUpdateInfo& in_rUpdateInfo)
    {
        fpCGameObjectUpdateParallel(this, in_rUpdateInfo);
    }

    inline BB_FUNCTION_PTR(bool, __thiscall, fpCGameObjectProcessMessage, 0xD60590,
        Hedgehog::Universe::CMessageActor* This, Hedgehog::Universe::Message& in_rMsg, bool in_Flag);

    inline bool CGameObject::ProcessMessage(Hedgehog::Universe::Message& in_rMsg, bool in_Flag)
    {
        return fpCGameObjectProcessMessage(this, in_rMsg, in_Flag);
    }

    inline Hedgehog::Base::TSynchronizedPtr<CGameDocument> CGameObject::GetGameDocument() const
    {
        return m_pMember->m_pGameDocument;
    }

    inline BB_FUNCTION_PTR(void, __thiscall, fpCGameObjectAddRenderable, 0xD5F620,
        CGameObject* This, const Hedgehog::Base::CStringSymbol in_Category, const boost::shared_ptr<Hedgehog::Mirage::CRenderable>& in_spRenderable, const bool in_CastShadow);

    inline void CGameObject::AddRenderable(const Hedgehog::Base::CStringSymbol in_Category,
        const boost::shared_ptr<Hedgehog::Mirage::CRenderable>& in_spRenderable, const bool in_CastShadow)
    {
        fpCGameObjectAddRenderable(this, in_Category, in_spRenderable, in_CastShadow);
    }

    inline BB_FUNCTION_PTR(void, __stdcall, fpCGameObjectRemoveRenderables, 0xD5EE50, CGameObject* This);

    inline void CGameObject::RemoveRenderables()
    {
        fpCGameObjectRemoveRenderables(this);
    }
}