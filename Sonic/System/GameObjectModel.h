#pragma once

#include <Sonic/System/GameObject3D.h>

namespace Hedgehog::Database
{
    class CDatabase;
}

namespace Sonic
{
    class CGameObjectModel;

    static uint32_t pCGameObjectModelCtor = 0x11D1790;

    static void fCGameObjectModelCtor(
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

    class CGameObjectModel : public CGameObject3D
    {
    public:
        BB_INSERT_PADDING(0x14);

        CGameObjectModel(const bb_null_ctor& nil) : CGameObject3D(nil) {}

        CGameObjectModel(const boost::shared_ptr<Hedgehog::Database::CDatabase>& in_spDatabase, 
            const Hedgehog::Base::CStringSymbol in_Category, const Hedgehog::Base::CSharedString& in_rModelName) : CGameObjectModel(bb_null_ctor{})
        {
            fCGameObjectModelCtor(this, &in_spDatabase, in_Category, &in_rModelName);
        }

        virtual ~CGameObjectModel();
    };

    BB_ASSERT_SIZEOF(CGameObjectModel, 0x108);
}