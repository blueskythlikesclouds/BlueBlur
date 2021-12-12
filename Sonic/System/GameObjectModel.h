#pragma once

#include <BlueBlur.inl>
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
        const boost::shared_ptr<Hedgehog::Database::CDatabase>* spDatabase,
        const Hedgehog::Base::CStringSymbol category,
        const Hedgehog::Base::CSharedString* modelName
    )
    {
        __asm
        {
            push modelName 
            push category.m_pSymbolNode
            push spDatabase
            mov eax, This
            call[pCGameObjectModelCtor]
        }
    }

    class CGameObjectModel : public CGameObject3D
    {
    public:
        BB_INSERT_PADDING(0x14);

        CGameObjectModel(const bb_null_ctor&) : CGameObject3D(bb_null_ctor{}) {}

        CGameObjectModel(const boost::shared_ptr<Hedgehog::Database::CDatabase>& spDatabase, 
            const Hedgehog::Base::CStringSymbol category, const Hedgehog::Base::CSharedString& modelName) : CGameObjectModel(bb_null_ctor{})
        {
            fCGameObjectModelCtor(this, &spDatabase, category, &modelName);
        }
    };

    BB_ASSERT_SIZEOF(CGameObjectModel, 0x108);
}