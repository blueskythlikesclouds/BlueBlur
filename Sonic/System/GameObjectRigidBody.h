#pragma once

#include <Sonic/System/GameObject.h>

namespace Sonic
{
    class alignas(16) CGameObjectRigidBody : public CGameObject
    {
    public:
        BB_INSERT_PADDING(0x98);

        CGameObjectRigidBody(const bb_null_ctor& nil) : CGameObject(nil) {}

        CGameObjectRigidBody(const Hedgehog::Base::CStringSymbol in_Category, const Hedgehog::Base::CSharedString& in_rModelName,
            const Hedgehog::Base::CSharedString& in_rRigidBodyContainerName, const Hedgehog::Base::CSharedString& in_rRigidBodyName);

        virtual ~CGameObjectRigidBody();

        void AddCallback(const Hedgehog::Base::THolder<CWorld>& in_rWorldHolder,
            Sonic::CGameDocument* in_pGameDocument, const boost::shared_ptr<Hedgehog::Database::CDatabase>& in_spDatabase) override;
    };

    BB_ASSERT_SIZEOF(CGameObjectRigidBody, 0x140);
}

#include <Sonic/System/GameObjectRigidBody.inl>