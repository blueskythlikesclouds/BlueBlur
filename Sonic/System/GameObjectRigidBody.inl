namespace Sonic
{
    inline uint32_t pCGameObjectRigidBodyCtor = 0x1106D20;

    inline void fCGameObjectRigidBodyCtor(
        CGameObjectRigidBody* This,
        const Hedgehog::Base::CStringSymbol in_Category,
        const Hedgehog::Base::CSharedString* in_pModelName,
        const Hedgehog::Base::CSharedString* in_pRigidBodyContainerName,
        const Hedgehog::Base::CSharedString* in_pRigidBodyName)
    {
        __asm
        {
            push in_pRigidBodyName
            push in_pRigidBodyContainerName
            push in_pModelName
            push in_Category.m_pSymbolNode
            mov eax, This
            call[pCGameObjectRigidBodyCtor]
        }
    }

    inline CGameObjectRigidBody::CGameObjectRigidBody(const Hedgehog::Base::CStringSymbol in_Category,
        const Hedgehog::Base::CSharedString& in_rModelName,
        const Hedgehog::Base::CSharedString& in_rRigidBodyContainerName,
        const Hedgehog::Base::CSharedString& in_rRigidBodyName) : CGameObjectRigidBody(bb_null_ctor{})
    {
        fCGameObjectRigidBodyCtor(this, in_Category, &in_rModelName, &in_rRigidBodyContainerName, &in_rRigidBodyName);
    }

    inline BB_FUNCTION_PTR(void, __thiscall, fpCGameObjectRigidBodyAddCallback, 0x1106F30,
        CGameObjectRigidBody* This, const Hedgehog::Base::THolder<CWorld>& in_rWorldHolder,
        Sonic::CGameDocument* in_pGameDocument, const boost::shared_ptr<Hedgehog::Database::CDatabase>& in_spDatabase);

    inline void CGameObjectRigidBody::AddCallback(const Hedgehog::Base::THolder<CWorld>& in_rWorldHolder,
        Sonic::CGameDocument* in_pGameDocument, const boost::shared_ptr<Hedgehog::Database::CDatabase>& in_spDatabase)
    {
        fpCGameObjectRigidBodyAddCallback(this, in_rWorldHolder, in_pGameDocument, in_spDatabase);
    }
}