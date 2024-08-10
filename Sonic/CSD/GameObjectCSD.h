#pragma once

#include <CSD/Manager/csdmRCPtr.h>
#include <Sonic/System/GameObject.h>

namespace Chao::CSD
{
    class CProject;
}

namespace Sonic
{
    class CGameObjectCSD : public CGameObject
    {
    public:
        Chao::CSD::RCPtr<Chao::CSD::CProject> m_rcProject;
        BB_INSERT_PADDING(0x38);

        CGameObjectCSD(float in_Unknown, Hedgehog::Base::CStringSymbol in_RenderableCategory); // 0x10DBBC0
        CGameObjectCSD(Chao::CSD::RCPtr<Chao::CSD::CProject> in_rcProject, float in_Unknown, Hedgehog::Base::CStringSymbol in_RenderableCategory, bool in_Flag); // 0x10DBB20
        ~CGameObjectCSD() override; // 0x10DBA90

        void AddCallback(const Hedgehog::Base::THolder<CWorld>& in_rWorldHolder, CGameDocument* in_pGameDocument, const boost::shared_ptr<Hedgehog::Database::CDatabase>& in_spDatabase) override;
    };

    BB_ASSERT_OFFSETOF(CGameObjectCSD, m_rcProject, 0xA8);
    BB_ASSERT_SIZEOF(CGameObjectCSD, 0xE8);
}

#include <Sonic/CSD/GameObjectCSD.inl>