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
    class CGameObject;
    class CWorld;

    static uint32_t pCGameObjectCtor = 0xD601F0;

    static void fCGameObjectCtor(CGameObject* This)
    {
        __asm
        {
            mov edi, This
            call[pCGameObjectCtor]
        }
    }

    static inline BB_FUNCTION_PTR(void, __thiscall, fpCGameObjectUpdateParallel, 0xD5F2A0,
        CGameObject* This, const Hedgehog::Universe::SUpdateInfo& in_rUpdateInfo);

    static inline BB_FUNCTION_PTR(bool, __thiscall, fpCGameObjectProcessMessage, 0xD60590,
        Hedgehog::Universe::CMessageActor* This, Hedgehog::Universe::Message& in_rMsg, bool in_Flag);

    static inline BB_FUNCTION_PTR(void, __thiscall, fpCGameObjectAddRenderable, 0xD5F620,
        CGameObject* This, const Hedgehog::Base::CStringSymbol in_Category, const boost::shared_ptr<Hedgehog::Mirage::CRenderable>& in_spRenderable, const bool in_CastShadow);

    class CGameObject : public Hedgehog::Universe::CUpdateUnit, public Hedgehog::Universe::CMessageActor
    {
    public:
        class CMember
        {
        public:
            Hedgehog::Base::TSynchronizedPtr<CGameDocument> m_pGameDocument;
            Hedgehog::Base::TSynchronizedPtr<CWorld> m_pWorld;
            BB_INSERT_PADDING(0x78);
        };

        CMember* m_pMember;

        CGameObject(const bb_null_ctor& nil) : CUpdateUnit(nil), CMessageActor(nil) {}

        CGameObject() : CGameObject(bb_null_ctor{})
        {
            fCGameObjectCtor(this);
        }

        virtual ~CGameObject();

        void UpdateParallel(const Hedgehog::Universe::SUpdateInfo& in_rUpdateInfo) override
        {
            fpCGameObjectUpdateParallel(this, in_rUpdateInfo);
        }

        bool ProcessMessage(Hedgehog::Universe::Message& in_rMsg, bool in_Flag) override
        {
            return fpCGameObjectProcessMessage(this, in_rMsg, in_Flag);
        }

        virtual bool CGameObject10() { return true; }
        virtual void* CGameObject14() { return 0; }

        virtual void Initialize(const Hedgehog::Base::THolder<CWorld>& in_rWorldHolder, 
            Sonic::CGameDocument* in_pGameDocument) {}

        virtual void AddCallback(const Hedgehog::Base::THolder<CWorld>& in_rWorldHolder, 
            Sonic::CGameDocument* in_pGameDocument, const boost::shared_ptr<Hedgehog::Database::CDatabase>& in_spDatabase) = 0;

        virtual void RemoveCallback(Sonic::CGameDocument* in_pGameDocument) {}

        virtual void CGameObject24(void*) {}
        virtual void KillCallback() {}
        virtual void CGameObject2C(void*) {}
        virtual void CGameObject30(void*) {}

        Hedgehog::Base::TSynchronizedPtr<CGameDocument> GetGameDocument() const
        {
            return m_pMember->m_pGameDocument;
        }

        void AddRenderable(const Hedgehog::Base::CStringSymbol in_Category, 
            const boost::shared_ptr<Hedgehog::Mirage::CRenderable>& in_spRenderable, const bool in_CastShadow = true)
        {
            fpCGameObjectAddRenderable(this, in_Category, in_spRenderable, in_CastShadow);
        }
    };

    BB_ASSERT_OFFSETOF(CGameObject::CMember, m_pGameDocument, 0x0);
    BB_ASSERT_OFFSETOF(CGameObject::CMember, m_pWorld, 0x04);
    BB_ASSERT_SIZEOF(CGameObject::CMember, 0x80);

    BB_ASSERT_OFFSETOF(CGameObject, m_pMember, 0xA4);
    BB_ASSERT_SIZEOF(CGameObject, 0xA8);
}
