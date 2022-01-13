#pragma once

#include <Hedgehog/Base/hhObject.h>
#include <Hedgehog/Base/Type/hhSharedString.h>
#include <Hedgehog/Universe/Engine/hhStateMachine.h>

#undef PlaySound

namespace Hedgehog::Mirage
{
    class CMatrixNodeNormal;
}

namespace Hedgehog::Sound
{
    class CSoundHandle;
}

namespace Sonic
{
    class CMatrixNodeTransform;
    class CRayCastCollision;
    class CShapeCastCollision;
}

namespace Sonic::Player
{
    class CParameter;
    class CPlayer;
    class CPlayerContext;
    class CInputPad;

    static inline BB_FUNCTION_PTR(const Hedgehog::Base::CSharedString&, __stdcall,
        fpCPlayerContextGetCurrentAnimationName, 0xE72CB0, CPlayerContext* This);

    static uint32_t pCPlayerContextChangeState = 0xE4FF30;

    static Hedgehog::Universe::TStateMachine<CPlayerContext>::TState* fCPlayerContextChangeState(
        CPlayerContext* This, const Hedgehog::Base::CSharedString* pType)
    {
        Hedgehog::Universe::TStateMachine<CPlayerContext>::TState* pResult;

        __asm
        {
            mov eax, pType
            mov ecx, This
            call[pCPlayerContextChangeState]
            mov pResult, eax
        }

        return pResult;
    }

    class CPlayerContext : public Hedgehog::Base::CObject
    {
    public:
        boost::shared_ptr<CMatrixNodeTransform> m_spMatrixNode; // 0x10
        boost::shared_ptr<Hedgehog::Mirage::CMatrixNodeNormal> m_spModelMatrixNode;
        boost::shared_ptr<Hedgehog::Mirage::CMatrixNodeNormal> m_Field20;
        boost::shared_ptr<Hedgehog::Mirage::CMatrixNodeNormal> m_Field28;
        boost::shared_ptr<CMatrixNodeTransform> m_Field30;

        boost::shared_ptr<CRayCastCollision> m_spRayCastCollision; // 0x38
        boost::shared_ptr<CRayCastCollision> m_spShapeCastCollision; // 0x40

        Hedgehog::Mirage::CTransform m_Field50;
        Hedgehog::Mirage::CTransform m_FieldB0;

        CPlayer* m_pPlayer;

        boost::shared_ptr<CInputPad> m_spInputPad;
        size_t m_Field11C;
        size_t m_Field120;

        Hedgehog::Math::CVector m_Field130;
        Hedgehog::Math::CVector m_Field140;
        Hedgehog::Math::CVector m_Field150;

        uint8_t m_Field160;
        size_t m_Field164;
        uint8_t m_Field168;
        size_t m_Field16C;

        uint8_t m_Field170;
        uint8_t m_Field171;
        uint8_t m_Field172;
        uint8_t m_Field173;

        size_t m_Field174;
        size_t m_Field178;

        Hedgehog::Math::CVector m_Field180;
        Hedgehog::Math::CVector m_Field190;

        size_t m_Field1A0;
        size_t m_Field1A4[2];
        uint8_t m_Field1AC[172];

        float m_Field258;

        Hedgehog::map<void*, void*> m_Field25C;
        Hedgehog::map<void*, void*> m_Field268;

        boost::shared_ptr<CParameter> m_spPlayerCommonParameter; // 0x274
        boost::shared_ptr<CParameter> m_spRootParameter; // 0x27C

        BB_INSERT_PADDING(0xC);

        virtual ~CPlayerContext() = default;

        virtual void CPlayerContext04() {}
        virtual void CPlayerContext08() {}
        virtual void CPlayerContext0C() {}
        virtual void CPlayerContext10() {}
        virtual void CPlayerContext14() {}
        virtual void CPlayerContext18() {}
        virtual void CPlayerContext1C() {}
        virtual void CPlayerContext20() {}
        virtual void CPlayerContext24() {}
        virtual void CPlayerContext28() {}
        virtual void CPlayerContext2C() {}
        virtual void CPlayerContext30() {}
        virtual void CPlayerContext34() {}
        virtual void CPlayerContext38() {}
        virtual void CPlayerContext3C() {}
        virtual void CPlayerContext40() {}
        virtual void CPlayerContext44() {}
        virtual void CPlayerContext48() {}
        virtual void CPlayerContext4C() {}
        virtual void CPlayerContext50() {}
        virtual void CPlayerContext54() {}
        virtual void CPlayerContext58() {}

        virtual void ChangeAnimation(const Hedgehog::Base::CSharedString& name) = 0;

        virtual void CPlayerContext60() {}
        virtual void CPlayerContext64() {}
        virtual void CPlayerContext68() {}
        virtual void CPlayerContext6C() {}
        virtual void CPlayerContext70() {}

        virtual boost::shared_ptr<Hedgehog::Sound::CSoundHandle> PlaySound(size_t cueId, bool loop) = 0;

        virtual void CPlayerContext78() {}
        virtual void CPlayerContext7C() {}
        virtual void CPlayerContext80() {}
        virtual void CPlayerContext84() {}
        virtual void CPlayerContext88() {}
        virtual void CPlayerContext8C() {}
        virtual void CPlayerContext90() {}

        const Hedgehog::Base::CSharedString& GetCurrentAnimationName()
        {
            return fpCPlayerContextGetCurrentAnimationName(this);
        }

        Hedgehog::Universe::TStateMachine<CPlayerContext>::TState* ChangeState(const Hedgehog::Base::CSharedString& type)
        {
            return fCPlayerContextChangeState(this, &type);
        }

        template<typename T>
        T* ChangeState()
        {
            return static_cast<T*>(ChangeState(T::ms_Type));
        }
    };

    BB_ASSERT_OFFSETOF(CPlayerContext, m_spMatrixNode, 0x10);
    BB_ASSERT_OFFSETOF(CPlayerContext, m_spModelMatrixNode, 0x18);
    BB_ASSERT_OFFSETOF(CPlayerContext, m_Field20, 0x20);
    BB_ASSERT_OFFSETOF(CPlayerContext, m_Field28, 0x28);
    BB_ASSERT_OFFSETOF(CPlayerContext, m_Field30, 0x30);
    BB_ASSERT_OFFSETOF(CPlayerContext, m_spRayCastCollision, 0x38);
    BB_ASSERT_OFFSETOF(CPlayerContext, m_spShapeCastCollision, 0x40);
    BB_ASSERT_OFFSETOF(CPlayerContext, m_Field50, 0x50);
    BB_ASSERT_OFFSETOF(CPlayerContext, m_FieldB0, 0xB0);
    BB_ASSERT_OFFSETOF(CPlayerContext, m_pPlayer, 0x110);
    BB_ASSERT_OFFSETOF(CPlayerContext, m_spInputPad, 0x114);
    BB_ASSERT_OFFSETOF(CPlayerContext, m_Field11C, 0x11C);
    BB_ASSERT_OFFSETOF(CPlayerContext, m_Field120, 0x120);
    BB_ASSERT_OFFSETOF(CPlayerContext, m_Field130, 0x130);
    BB_ASSERT_OFFSETOF(CPlayerContext, m_Field140, 0x140);
    BB_ASSERT_OFFSETOF(CPlayerContext, m_Field150, 0x150);
    BB_ASSERT_OFFSETOF(CPlayerContext, m_Field160, 0x160);
    BB_ASSERT_OFFSETOF(CPlayerContext, m_Field164, 0x164);
    BB_ASSERT_OFFSETOF(CPlayerContext, m_Field168, 0x168);
    BB_ASSERT_OFFSETOF(CPlayerContext, m_Field16C, 0x16C);
    BB_ASSERT_OFFSETOF(CPlayerContext, m_Field170, 0x170);
    BB_ASSERT_OFFSETOF(CPlayerContext, m_Field171, 0x171);
    BB_ASSERT_OFFSETOF(CPlayerContext, m_Field172, 0x172);
    BB_ASSERT_OFFSETOF(CPlayerContext, m_Field173, 0x173);
    BB_ASSERT_OFFSETOF(CPlayerContext, m_Field174, 0x174);
    BB_ASSERT_OFFSETOF(CPlayerContext, m_Field178, 0x178);
    BB_ASSERT_OFFSETOF(CPlayerContext, m_Field180, 0x180);
    BB_ASSERT_OFFSETOF(CPlayerContext, m_Field190, 0x190);
    BB_ASSERT_OFFSETOF(CPlayerContext, m_Field1A0, 0x1A0);
    BB_ASSERT_OFFSETOF(CPlayerContext, m_Field1A4, 0x1A4);
    BB_ASSERT_OFFSETOF(CPlayerContext, m_Field1AC, 0x1AC);
    BB_ASSERT_OFFSETOF(CPlayerContext, m_Field258, 0x258);
    BB_ASSERT_OFFSETOF(CPlayerContext, m_Field25C, 0x25C);
    BB_ASSERT_OFFSETOF(CPlayerContext, m_Field268, 0x268);
    BB_ASSERT_OFFSETOF(CPlayerContext, m_spPlayerCommonParameter, 0x274);
    BB_ASSERT_OFFSETOF(CPlayerContext, m_spRootParameter, 0x27C);
    BB_ASSERT_SIZEOF(CPlayerContext, 0x290);
}