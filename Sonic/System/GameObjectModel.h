#pragma once

#include <Sonic/System/GameObject3D.h>

namespace Hedgehog::Database
{
    class CDatabase;
}

namespace Sonic
{
    class CGameObjectModel : public CGameObject3D
    {
    public:
        BB_INSERT_PADDING(0x14);

        CGameObjectModel(const bb_null_ctor& nil) : CGameObject3D(nil) {}

        CGameObjectModel(const boost::shared_ptr<Hedgehog::Database::CDatabase>& in_spDatabase, 
            const Hedgehog::Base::CStringSymbol in_Category, const Hedgehog::Base::CSharedString& in_rModelName);

        virtual ~CGameObjectModel();
    };

    BB_ASSERT_SIZEOF(CGameObjectModel, 0x108);
}

#include <Sonic/System/GameObjectModel.inl>