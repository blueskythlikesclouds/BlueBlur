#pragma once

#include <Hedgehog/Base/System/hhSymbol.h>
#include <Hedgehog/Base/Thread/hhSynchronizedPtr.h>
#include <Hedgehog/Universe/Engine/hhMessageActor.h>
#include <Hedgehog/Universe/Engine/hhUpdateUnit.h>

namespace Hedgehog::Database
{
    class CDatabase;
}

namespace Hedgehog::Mirage
{
    class CRenderable;
}

namespace Sonic
{
    class CGameDocument;
    class CParameterBank;
    class CWorld;

    class CGameObject : public Hedgehog::Universe::CUpdateUnit, public Hedgehog::Universe::CMessageActor
    {
    public:
        class CMember
        {
        public:
            Hedgehog::Base::TSynchronizedPtr<CGameDocument> m_pGameDocument;
            Hedgehog::Base::TSynchronizedPtr<CWorld> m_pWorld;
            BB_INSERT_PADDING(0x50);
            bool m_CastShadow;
            BB_INSERT_PADDING(0x27);
        };

        CMember* m_pMember;

        CGameObject(const bb_null_ctor& nil) : CUpdateUnit(nil), CMessageActor(nil) {}
        CGameObject();
        virtual ~CGameObject();

        void UpdateParallel(const Hedgehog::Universe::SUpdateInfo& in_rUpdateInfo) override;
        bool ProcessMessage(Hedgehog::Universe::Message& in_rMsg, bool in_Flag) override;

        virtual bool CGameObject10() { return true; }
        virtual void* CGameObject14() { return 0; }

        virtual void Initialize(const Hedgehog::Base::THolder<CWorld>& in_rWorldHolder, 
            Sonic::CGameDocument* in_pGameDocument) {}

        virtual void AddCallback(const Hedgehog::Base::THolder<CWorld>& in_rWorldHolder, 
            Sonic::CGameDocument* in_pGameDocument, const boost::shared_ptr<Hedgehog::Database::CDatabase>& in_spDatabase) = 0;

        virtual void RemoveCallback(Sonic::CGameDocument* in_pGameDocument) {}

        virtual void DeathCallback(Sonic::CGameDocument* in_pGameDocument) {}
        virtual void KillCallback() {}
        virtual void GetObjectTriggerType(hh::vector<uint32_t>& in_rTriggerTypeList) {}
        virtual void AddParameterBank(const Hedgehog::Base::CRefPtr<CParameterBank>& in_rParameterBank) {}

        Hedgehog::Base::TSynchronizedPtr<CGameDocument> GetGameDocument() const;

        void AddRenderable(const Hedgehog::Base::CStringSymbol in_Category, 
            const boost::shared_ptr<Hedgehog::Mirage::CRenderable>& in_spRenderable, const bool in_CastShadow = true);

        void RemoveRenderables();
		
        void Kill();
    };

    BB_ASSERT_OFFSETOF(CGameObject::CMember, m_pGameDocument, 0x0);
    BB_ASSERT_OFFSETOF(CGameObject::CMember, m_pWorld, 0x04);
    BB_ASSERT_OFFSETOF(CGameObject::CMember, m_CastShadow, 0x58);
    BB_ASSERT_SIZEOF(CGameObject::CMember, 0x80);

    BB_ASSERT_OFFSETOF(CGameObject, m_pMember, 0xA4);
    BB_ASSERT_SIZEOF(CGameObject, 0xA8);
}


#include <Sonic/System/GameObject.inl>