﻿#pragma once

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
        CGameObject* This, const Hedgehog::Universe::SUpdateInfo& updateInfo);

    static inline BB_FUNCTION_PTR(bool, __thiscall, fpCGameObjectProcessMessage, 0xD60590,
        Hedgehog::Universe::CMessageActor* This, Hedgehog::Universe::Message& message, bool flag);

    static inline BB_FUNCTION_PTR(void, __thiscall, fpCGameObjectAddRenderable, 0xD5F620,
        CGameObject* This, const Hedgehog::Base::CStringSymbol category, const boost::shared_ptr<Hedgehog::Mirage::CRenderable>& spRenderable, const bool castShadow);

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

        CGameObject(const bb_null_ctor&) : CUpdateUnit(bb_null_ctor{}), CMessageActor(bb_null_ctor{}) {}

        CGameObject() : CGameObject(bb_null_ctor{})
        {
            fCGameObjectCtor(this);
        }

        virtual ~CGameObject();

        void UpdateParallel(const Hedgehog::Universe::SUpdateInfo& updateInfo) override
        {
            fpCGameObjectUpdateParallel(this, updateInfo);
        }

        bool ProcessMessage(Hedgehog::Universe::Message& message, bool flag) override
        {
            return fpCGameObjectProcessMessage(this, message, flag);
        }

        virtual bool CGameObject10() { return true; }
        virtual void* CGameObject14() { return 0; }

        virtual void* Initialize(const Hedgehog::Base::THolder<CWorld>& worldHolder, 
            Sonic::CGameDocument* pGameDocument) { return nullptr; }

        virtual void AddCallback(const Hedgehog::Base::THolder<CWorld>& worldHolder, 
            Sonic::CGameDocument* pGameDocument, const boost::shared_ptr<Hedgehog::Database::CDatabase>& spDatabase) = 0;

        virtual void RemoveCallback(Sonic::CGameDocument* pGameDocument) {}

        virtual void CGameObject24(void*) {}
        virtual void KillCallback() {}
        virtual void CGameObject2C(void*) {}
        virtual void CGameObject30(void*) {}

        Hedgehog::Base::TSynchronizedPtr<CGameDocument> GetGameDocument() const
        {
            return m_pMember->m_pGameDocument;
        }

        void AddRenderable(const Hedgehog::Base::CStringSymbol category, 
            const boost::shared_ptr<Hedgehog::Mirage::CRenderable>& spRenderable, const bool castShadow)
        {
            fpCGameObjectAddRenderable(this, category, spRenderable, castShadow);
        }
    };

    BB_ASSERT_OFFSETOF(CGameObject::CMember, m_pGameDocument, 0x0);
    BB_ASSERT_OFFSETOF(CGameObject::CMember, m_pWorld, 0x04);
    BB_ASSERT_SIZEOF(CGameObject::CMember, 0x80);

    BB_ASSERT_OFFSETOF(CGameObject, m_pMember, 0xA4);
    BB_ASSERT_SIZEOF(CGameObject, 0xA8);
}
