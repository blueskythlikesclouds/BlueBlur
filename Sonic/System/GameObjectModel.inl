namespace Sonic
{
    inline uint32_t pCGameObjectModelCtor = 0x11D1790;

    inline void fCGameObjectModelCtor(
        CGameObjectModel* This,
        const boost::shared_ptr<Hedgehog::Database::CDatabase>* in_spDatabase,
        const Hedgehog::Base::CStringSymbol in_Category,
        const Hedgehog::Base::CSharedString* in_pModelName
    )
    {
        __asm
        {
            push in_pModelName
            push in_Category.m_pSymbolNode
            push in_spDatabase
            mov eax, This
            call[pCGameObjectModelCtor]
        }
    }

    inline CGameObjectModel::CGameObjectModel(const boost::shared_ptr<Hedgehog::Database::CDatabase>& in_spDatabase,
        const Hedgehog::Base::CStringSymbol in_Category, const Hedgehog::Base::CSharedString& in_rModelName) : CGameObjectModel(bb_null_ctor{})
    {
        fCGameObjectModelCtor(this, &in_spDatabase, in_Category, &in_rModelName);
    }
}