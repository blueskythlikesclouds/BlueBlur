#pragma once

#include <Hedgehog/Base/hhObject.h>
#include <Hedgehog/Base/Type/hhSharedString.h>
#include <Hedgehog/Universe/Engine/hhStateMachine.h>

#include "Sonic/Player/Character/Speed/State/PlayerSpeedState.h"

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
    class CCharacterProxy;
}

namespace Sonic::Player
{
    class CParameter;
    class CPlayer;
    class CInputPad;

    class CPlayerContext : public Hedgehog::Base::CObject
    {
    public:
        boost::shared_ptr<CMatrixNodeTransform> m_spMatrixNode; // 0x10
        boost::shared_ptr<Hedgehog::Mirage::CMatrixNodeNormal> m_spModelMatrixNode; // 0x18
        boost::shared_ptr<Hedgehog::Mirage::CMatrixNodeNormal> m_spField20; // 0x20
        boost::shared_ptr<Hedgehog::Mirage::CMatrixNodeNormal> m_spField28; // 0x28
        boost::shared_ptr<CMatrixNodeTransform> m_spField30; // 0x30

        boost::shared_ptr<CRayCastCollision> m_spRayCastCollision; // 0x38
        boost::shared_ptr<CRayCastCollision> m_spShapeCastCollision; // 0x40

        Hedgehog::Mirage::CTransform m_StartTransform; // 0x50
        Hedgehog::Mirage::CTransform m_RestartPosition; // 0xB0

        CPlayer* m_pPlayer; // 0x110

        boost::shared_ptr<CCharacterProxy> m_spCharacterProxy; //0x114
        boost::shared_ptr<CInputPad> m_spInputPad; //0x11C

        BB_INSERT_PADDING(0x0C);

        Hedgehog::Math::CVector m_WorldInput; //0x130
        Hedgehog::Math::CVector m_Field140; //0x140
        Hedgehog::Math::CVector m_PathInput2D; //0x150

        uint8_t m_Field160;
        size_t m_GroundAttribute;
        uint8_t m_Field168;
        size_t m_RestartCount; // 0x16C

        uint8_t m_Field170;
        uint8_t m_Field171;
        bool m_Is2DMode;
        uint8_t m_Field173;

        size_t m_Field174;
        size_t m_Field178;

        Hedgehog::Math::CVector m_Field180;
        Hedgehog::Math::CVector m_Field190;

        size_t m_SuperRenderableActorID; // 0x1A0

#pragma pack(push, 1)
        std::bitset<64> m_Skills;
#pragma pack(pop)

        uint8_t m_Field1AC[172];

        float m_Field258;

        hh::map<void*, void*> m_Field25C;
        hh::map<void*, void*> m_Field268;

        boost::shared_ptr<CParameter> m_spParentParameter; // 0x274
        boost::shared_ptr<CParameter> m_spParameter; // 0x27C

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

        virtual void ChangeAnimation(const Hedgehog::Base::CSharedString& in_rName) = 0;

        virtual void CPlayerContext60() {}
        virtual void CPlayerContext64() {}
        virtual void CPlayerContext68() {}
        virtual void CPlayerContext6C() {}
        virtual void CPlayerContext70() {}

        virtual boost::shared_ptr<Hedgehog::Sound::CSoundHandle> PlaySound(size_t in_CueId, bool in_Loop) = 0;

        virtual void CPlayerContext78() {}
        virtual void CPlayerContext7C() {}
        virtual void CPlayerContext80() {}
        virtual void CPlayerContext84() {}
        virtual void CPlayerContext88() {}
        virtual void CPlayerContext8C() {}
        virtual void CPlayerContext90() {}

        const Hedgehog::Base::CSharedString& GetCurrentAnimationName();

        Hedgehog::Universe::TStateMachine<CPlayerContext>::TState* ChangeState(const Hedgehog::Base::CSharedString& in_rType);
        Hedgehog::Universe::TStateMachine<CPlayerContext>::TState* ChangeState(EPlayerSpeedState in_PlayerSpeedState);

        template<typename T>
        T* ChangeState();
    };

    BB_ASSERT_OFFSETOF(CPlayerContext, m_spMatrixNode, 0x10);
    BB_ASSERT_OFFSETOF(CPlayerContext, m_spModelMatrixNode, 0x18);
    BB_ASSERT_OFFSETOF(CPlayerContext, m_spField20, 0x20);
    BB_ASSERT_OFFSETOF(CPlayerContext, m_spField28, 0x28);
    BB_ASSERT_OFFSETOF(CPlayerContext, m_spField30, 0x30);
    BB_ASSERT_OFFSETOF(CPlayerContext, m_spRayCastCollision, 0x38);
    BB_ASSERT_OFFSETOF(CPlayerContext, m_spShapeCastCollision, 0x40);
    BB_ASSERT_OFFSETOF(CPlayerContext, m_StartTransform, 0x50);
    BB_ASSERT_OFFSETOF(CPlayerContext, m_RestartPosition, 0xB0);
    BB_ASSERT_OFFSETOF(CPlayerContext, m_pPlayer, 0x110);
    BB_ASSERT_OFFSETOF(CPlayerContext, m_spCharacterProxy, 0x114);
    BB_ASSERT_OFFSETOF(CPlayerContext, m_spInputPad, 0x11C);
    BB_ASSERT_OFFSETOF(CPlayerContext, m_WorldInput, 0x130);
    BB_ASSERT_OFFSETOF(CPlayerContext, m_Field140, 0x140);
    BB_ASSERT_OFFSETOF(CPlayerContext, m_PathInput2D, 0x150);
    BB_ASSERT_OFFSETOF(CPlayerContext, m_Field160, 0x160);
    BB_ASSERT_OFFSETOF(CPlayerContext, m_GroundAttribute, 0x164);
    BB_ASSERT_OFFSETOF(CPlayerContext, m_Field168, 0x168);
    BB_ASSERT_OFFSETOF(CPlayerContext, m_RestartCount, 0x16C);
    BB_ASSERT_OFFSETOF(CPlayerContext, m_Field170, 0x170);
    BB_ASSERT_OFFSETOF(CPlayerContext, m_Field171, 0x171);
    BB_ASSERT_OFFSETOF(CPlayerContext, m_Is2DMode, 0x172);
    BB_ASSERT_OFFSETOF(CPlayerContext, m_Field173, 0x173);
    BB_ASSERT_OFFSETOF(CPlayerContext, m_Field174, 0x174);
    BB_ASSERT_OFFSETOF(CPlayerContext, m_Field178, 0x178);
    BB_ASSERT_OFFSETOF(CPlayerContext, m_Field180, 0x180);
    BB_ASSERT_OFFSETOF(CPlayerContext, m_Field190, 0x190);
    BB_ASSERT_OFFSETOF(CPlayerContext, m_SuperRenderableActorID, 0x1A0);

    // Because they're private, these assertions don't work.
    // Set them to public & uncomment these if you want to verify these specifically work.
    //BB_ASSERT_OFFSETOF(CPlayerContext, m_SkillsP1, 0x1A4);
    //BB_ASSERT_OFFSETOF(CPlayerContext, m_SkillsP2, 0x1A8);

    BB_ASSERT_OFFSETOF(CPlayerContext, m_Field1AC, 0x1AC);
    BB_ASSERT_OFFSETOF(CPlayerContext, m_Field258, 0x258);
    BB_ASSERT_OFFSETOF(CPlayerContext, m_Field25C, 0x25C);
    BB_ASSERT_OFFSETOF(CPlayerContext, m_Field268, 0x268);
    BB_ASSERT_OFFSETOF(CPlayerContext, m_spParentParameter, 0x274);
    BB_ASSERT_OFFSETOF(CPlayerContext, m_spParameter, 0x27C);
    BB_ASSERT_SIZEOF(CPlayerContext, 0x290);
}

#include <Sonic/Player/Character/Base/PlayerContext.inl>