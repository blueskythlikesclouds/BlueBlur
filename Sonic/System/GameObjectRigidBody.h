#pragma once

#include <Sonic/System/GameObject.h>

namespace Sonic
{
    class CGameObjectRigidBody;

    static uint32_t pCGameObjectRigidBodyCtor = 0x1106D20;

    static void fCGameObjectRigidBodyCtor(
        CGameObjectRigidBody* This,
        const Hedgehog::Base::CStringSymbol category,
        const Hedgehog::Base::CSharedString* pModelName,
        const Hedgehog::Base::CSharedString* pRigidBodyContainerName,
        const Hedgehog::Base::CSharedString* pRigidBodyName)
    {
        __asm
        {
            push pRigidBodyName
            push pRigidBodyContainerName
            push pModelName
            push category.m_pSymbolNode
            mov eax, This
            call[pCGameObjectRigidBodyCtor]
        }
    }

    static inline BB_FUNCTION_PTR(void, __thiscall, fpCGameObjectRigidBodyAddCallback, 0x1106F30,
        CGameObjectRigidBody* This, const Hedgehog::Base::THolder<CWorld>& worldHolder,
        Sonic::CGameDocument* pGameDocument, const boost::shared_ptr<Hedgehog::Database::CDatabase>& spDatabase);

    class alignas(16) CGameObjectRigidBody : public CGameObject
    {
    public:
        BB_INSERT_PADDING(0x98);

        CGameObjectRigidBody(const bb_null_ctor&) : CGameObject(bb_null_ctor{}) {}

        CGameObjectRigidBody(const Hedgehog::Base::CStringSymbol category, const Hedgehog::Base::CSharedString& modelName,
            const Hedgehog::Base::CSharedString& rigidBodyContainerName, const Hedgehog::Base::CSharedString& rigidBodyName) : CGameObjectRigidBody(bb_null_ctor{})
        {
            fCGameObjectRigidBodyCtor(this, category, &modelName, &rigidBodyContainerName, &rigidBodyName);
        }

        void AddCallback(const Hedgehog::Base::THolder<CWorld>& worldHolder,
            Sonic::CGameDocument* pGameDocument, const boost::shared_ptr<Hedgehog::Database::CDatabase>& spDatabase) override
        {
            fpCGameObjectRigidBodyAddCallback(this, worldHolder, pGameDocument, spDatabase);
        }
    };

    BB_ASSERT_SIZEOF(CGameObjectRigidBody, 0x140);
}