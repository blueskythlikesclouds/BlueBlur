#pragma once

#include <Hedgehog/Base/hhObject.h>
#include <Hedgehog/Base/Type/hhSharedString.h>
#include <Hedgehog/Universe/Engine/hhStateMachine.h>

#undef PlaySound
enum class ePlayerParameter;

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
    // TODO: Move somewhere else, or just map out all the states I guess????
    // Enum of every state name.
    enum class StateAction;

    class CParameter;
    class CPlayer;
    class CPlayerContext;
    class CInputPad;

    static inline BB_FUNCTION_PTR(const Hedgehog::Base::CSharedString&, __stdcall,
        fpCPlayerContextGetCurrentAnimationName, 0xE72CB0, CPlayerContext* This);

    static uint32_t pCPlayerContextChangeState = 0xE4FF30;

    static Hedgehog::Universe::TStateMachine<CPlayerContext>::TState* fCPlayerContextChangeState(
        CPlayerContext* This, const Hedgehog::Base::CSharedString* in_pType)
    {
        Hedgehog::Universe::TStateMachine<CPlayerContext>::TState* pResult;

        __asm
        {
            mov eax, in_pType
            mov ecx, This
            call[pCPlayerContextChangeState]
            mov pResult, eax
        }

        return pResult;
    }

    static float __cdecl fpGetFloatParameter(const void* paramList, const int param)
    {
#ifdef _USE_STATIC
        getFloatParameter_param = param;
        getFloatParameter_paramList = (uint32_t)paramList;

        fpGetFloatParameter_asm();

        return getFloatParameter_return;
#else
        uint32_t func = 0x0053A9F0;
        volatile float result = 0.0f;
        uint32_t _paramList = (uint32_t)paramList;
        uint32_t _param = param;

        __asm
        {
            push     _param
            mov eax, _paramList
            call[func]
            movss dword ptr[result], xmm0
        }

        return result;
#endif
    }

    // Helper function, please consider putting this somewhere else like in a "helpers" header in BlueBlur?
    const char* fStringFromStateAction(StateAction state);

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

        // HACK: unaligned keyword doesn't work & this is basically a 64bit int at 0x1A4 for some reason.
        // We can just make these private I guess, use a member function to acces them.
    private:
        uint32_t m_SkillsP1; // 0x1A4
        uint32_t m_SkillsP2; // 0x1A8
    public:
        uint64_t Skills()
        {
            return *(uint64_t*)&m_SkillsP1;
        }

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

        const Hedgehog::Base::CSharedString& GetCurrentAnimationName()
        {
            return fpCPlayerContextGetCurrentAnimationName(this);
        }

        Hedgehog::Universe::TStateMachine<CPlayerContext>::TState* ChangeState(const Hedgehog::Base::CSharedString& in_rType)
        {
            return fCPlayerContextChangeState(this, &in_rType);
        }

        inline Hedgehog::Universe::TStateMachine<CPlayerContext>::TState* ChangeState(StateAction in_State)
        {
            return ChangeState(fStringFromStateAction(in_State));
        }

        const float GetFloatParamByInt(const int in_Param) const
        {
            const float result = fpGetFloatParameter(this->m_spParameter.get(), in_Param);
            return result;
        }

        template<typename T>
        T* ChangeState()
        {
            return static_cast<T*>(ChangeState(T::ms_pStateName));
        }
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

    // Helper class & function. TODO: Migrate to another location.

    // Class that we use to map every valid state in Generations, leveraging intellisense for autocompletion instead of relying on strings.
    enum class StateAction
    {
        Stand,
        Walk,
        JumpShort,
        Jump,
        MoveStop,
        Brake,
        BrakeEnd,
        BrakeTurn,
        Fall,
        Land,
        LandJumpShort,
        DeadLanding,
        JumpSpring,
        JumpSpringHeadLand,
        HangOn,
        ReactionJump,    // THIS CRASHES THE GAME AND IS REALLY FUCKED UP
        ReactionLand,
        TrickJump,
        CrashWall,
        CrashWallDown,
        PressDead,
        PressDamage,
        WallJumpReady,
        WallJump,
        Battery,    // Game crashes lol
        Sliding,
        ShoesSliding,
        GoalAir,
        Goal,
        ExternalControl_Crash,
        TrickJumpSuccess,
        FinishExternalControlAir,
        PushingWall,
        PushObject,
        KickBox,
        PlayAnimation,
        NormalDamage,
        NormalDamageStandUp,
        NormalDamageAir,
        NormalDamageDead,
        NormalDamageDeadAir,
        DamageCancel,
        DamageOnRunning,
        DamageOnStomping,
        TrickAttackLand,
        TrickAttack,
        SpecialJump,
        DrowningDead,
        MoveToPositionAndWait,
        WallRunDamage,
        LookUp,
        Stagger,
        TakeBreath_Crash,
        Suffocate_Crash,
        HipSliding,
        AdlibTrick,
        AdlibTrickFailure,
        Pipe,
        AirBoost,
        Drift,
        NoStanding,
        HomingAttack,
        HomingAttackAfter,
        Grind,
        GrindJumpSide_Crash,
        GrindSquat_Crash,
        GrindJumpShort_Crash,
        GrindLandJumpShort_Crash,
        GrindSwitch_Crash,
        GrindDamageMiddle_Crash,
        GrindToWallWalk_Crash,
        OnSlipFloor,
        Stepping_Crash,
        TramRiding_Crash,
        BeforeBoundJump,
        BoundJump,
        StumbleAir,
        StumbleGround,
        QuickStep,
        RunQuickStep,
        StartDash,
        StartEvent,
        StartCrouching,
        BoardWalk,
        BoardGetOn,
        BoardGetOff,
        BoardNormalDamage,
        BoardJumpShort,
        BoardJump,
        BoardAdlibTrick,
        BoardQuickStep,
        BoardRunQuickStep,
        BoardFall,
        BoardGrind,
        BoardGrindJumpShort,
        BoardGrindJumpSide,
        BoardGrindLandJumpShort,
        BoardLandJumpShort,
        BoardAirBoost,
        BoardJumpSpring,
        BoardDrift,
        JumpHurdle,
        Squat,
        SlidingEnd,
        SelectJump,
        JumpSelector,
        Stomping_Crash,
        StompingLand,
        LightSpeedDash,
        SelectJumpAfter,
        DivingFloat,
        DivingDive,
        DivingDamage,
        SquatKick,
        OnIce,
        DamageFreeze,
        DamageShock,
        DamageNearFar,
        Spin,
        SpinCharge,
        SpinChargeSliding,
        SpinSliding,
        SquatCharge,
        FloatingBoost,
        TransformRocket,
        TransformSpike,
        TransformSp,
        TransformStandard,
        RocketIdle,
        RocketLaunch,
        RocketEnd,
        RocketOverHeat,
        SpikeIdle,
        SpikeWalk,
        SpikeFall,
        SpikeJump,
        SpikeLand,
        SpikeCharge,
        SpikeBoost,
        SpikeJumpSpring,
        SpikeSpecialJump,
        SpikeDamageShock,
        SpikeHomingAttack,
        SpikeHomingAttackAfter,
        NONE
    };
    // Helper function that takes in a "StateAction" enum, leveraging intellisense to autocomplete vanilla Generations state names.
    static inline const char* fStringFromStateAction(StateAction state)
    {
        switch (state)
        {
        default:
        case StateAction::Stand:
        {
            return "Stand";
        }
        case StateAction::Walk:
        {
            return "Walk";
        }
        case StateAction::JumpShort:
        {
            return "JumpShort";
        }
        case StateAction::Jump:
        {
            return "Jump";
        }
        case StateAction::MoveStop:
        {
            return "MoveStop";
        }
        case StateAction::Brake:
        {
            return "Brake";
        }
        case StateAction::BrakeEnd:
        {
            return "BrakeEnd";
        }
        case StateAction::BrakeTurn:
        {
            return "BrakeTurn";
        }
        case StateAction::Fall:
        {
            return "Fall";
        }
        case StateAction::Land:
        {
            return "Land";
        }
        case StateAction::LandJumpShort:
        {
            return "LandJumpShort";
        }
        case StateAction::DeadLanding:
        {
            return "DeadLanding";
        }
        case StateAction::JumpSpring:
        {
            return "JumpSpring";
        }
        case StateAction::JumpSpringHeadLand:
        {
            return "JumpSpringHeadLand";
        }
        case StateAction::HangOn:
        {
            return "HangOn";
        }
        case StateAction::ReactionJump:
        {
            return "ReactionJump";
        }
        case StateAction::ReactionLand:
        {
            return "ReactionLand";
        }
        case StateAction::TrickJump:
        {
            return "TrickJump";
        }
        case StateAction::CrashWall:
        {
            return "CrashWall";
        }
        case StateAction::CrashWallDown:
        {
            return "CrashWallDown";
        }
        case StateAction::PressDead:
        {
            return "PressDead";
        }
        case StateAction::PressDamage:
        {
            return "PressDamage";
        }
        case StateAction::WallJumpReady:
        {
            return "WallJumpReady";
        }
        case StateAction::WallJump:
        {
            return "WallJump";
        }
        case StateAction::Battery:
        {
            return "Battery";
        }
        case StateAction::Sliding:
        {
            return "Sliding";
        }
        case StateAction::ShoesSliding:
        {
            return "ShoesSliding";
        }
        case StateAction::GoalAir:
        {
            return "GoalAir";
        }
        case StateAction::Goal:
        {
            return "Goal";
        }
        case StateAction::ExternalControl_Crash:
        {
            return "ExternalControl_Crash";
        }
        case StateAction::TrickJumpSuccess:
        {
            return "TrickJumpSuccess";
        }
        case StateAction::FinishExternalControlAir:
        {
            return "FinishExternalControlAir";
        }
        case StateAction::PushingWall:
        {
            return "PushingWall";
        }
        case StateAction::PushObject:
        {
            return "PushObject";
        }
        case StateAction::KickBox:
        {
            return "KickBox";
        }
        case StateAction::PlayAnimation:
        {
            return "PlayAnimation";
        }
        case StateAction::NormalDamage:
        {
            return "NormalDamage";
        }
        case StateAction::NormalDamageStandUp:
        {
            return "NormalDamageStandUp";
        }
        case StateAction::NormalDamageAir:
        {
            return "NormalDamageAir";
        }
        case StateAction::NormalDamageDead:
        {
            return "NormalDamageDead";
        }
        case StateAction::NormalDamageDeadAir:
        {
            return "NormalDamageDeadAir";
        }
        case StateAction::DamageCancel:
        {
            return "DamageCancel";
        }
        case StateAction::DamageOnRunning:
        {
            return "DamageOnRunning";
        }
        case StateAction::DamageOnStomping:
        {
            return "DamageOnStomping";
        }
        case StateAction::TrickAttackLand:
        {
            return "TrickAttackLand";
        }
        case StateAction::TrickAttack:
        {
            return "TrickAttack";
        }
        case StateAction::SpecialJump:
        {
            return "SpecialJump";
        }
        case StateAction::DrowningDead:
        {
            return "DrowningDead";
        }
        case StateAction::MoveToPositionAndWait:
        {
            return "MoveToPositionAndWait";
        }
        case StateAction::WallRunDamage:
        {
            return "WallRunDamage";
        }
        case StateAction::LookUp:
        {
            return "LookUp";
        }
        case StateAction::Stagger:
        {
            return "Stagger";
        }
        case StateAction::TakeBreath_Crash:
        {
            return "TakeBreath_Crash";
        }
        case StateAction::Suffocate_Crash:
        {
            return "Suffocate_Crash";
        }
        case StateAction::HipSliding:
        {
            return "HipSliding";
        }
        case StateAction::AdlibTrick:
        {
            return "AdlibTrick";
        }
        case StateAction::AdlibTrickFailure:
        {
            return "AdlibTrickFailure";
        }
        case StateAction::Pipe:
        {
            return "Pipe";
        }
        case StateAction::AirBoost:
        {
            return "AirBoost";
        }
        case StateAction::Drift:
        {
            return "Drift";
        }
        case StateAction::NoStanding:
        {
            return "NoStanding";
        }
        case StateAction::HomingAttack:
        {
            return "HomingAttack";
        }
        case StateAction::HomingAttackAfter:
        {
            return "HomingAttackAfter";
        }
        case StateAction::Grind:
        {
            return "Grind";
        }
        case StateAction::GrindJumpSide_Crash:
        {
            return "GrindJumpSide_Crash";
        }
        case StateAction::GrindSquat_Crash:
        {
            return "GrindSquat_Crash";
        }
        case StateAction::GrindJumpShort_Crash:
        {
            return "GrindJumpShort_Crash";
        }
        case StateAction::GrindLandJumpShort_Crash:
        {
            return "GrindLandJumpShort_Crash";
        }
        case StateAction::GrindSwitch_Crash:
        {
            return "GrindSwitch_Crash";
        }
        case StateAction::GrindDamageMiddle_Crash:
        {
            return "GrindDamageMiddle_Crash";
        }
        case StateAction::GrindToWallWalk_Crash:
        {
            return "GrindToWallWalk_Crash";
        }
        case StateAction::OnSlipFloor:
        {
            return "OnSlipFloor";
        }
        case StateAction::Stepping_Crash:
        {
            return "Stepping_Crash";
        }
        case StateAction::TramRiding_Crash:
        {
            return "TramRiding_Crash";
        }
        case StateAction::BeforeBoundJump:
        {
            return "BeforeBoundJump";
        }
        case StateAction::BoundJump:
        {
            return "BoundJump";
        }
        case StateAction::StumbleAir:
        {
            return "StumbleAir";
        }
        case StateAction::StumbleGround:
        {
            return "StumbleGround";
        }
        case StateAction::QuickStep:
        {
            return "QuickStep";
        }
        case StateAction::RunQuickStep:
        {
            return "RunQuickStep";
        }
        case StateAction::StartDash:
        {
            return "StartDash";
        }
        case StateAction::StartEvent:
        {
            return "StartEvent";
        }
        case StateAction::StartCrouching:
        {
            return "StartCrouching";
        }
        case StateAction::BoardWalk:
        {
            return "BoardWalk";
        }
        case StateAction::BoardGetOn:
        {
            return "BoardGetOn";
        }
        case StateAction::BoardGetOff:
        {
            return "BoardGetOff";
        }
        case StateAction::BoardNormalDamage:
        {
            return "BoardNormalDamage";
        }
        case StateAction::BoardJumpShort:
        {
            return "BoardJumpShort";
        }
        case StateAction::BoardJump:
        {
            return "BoardJump";
        }
        case StateAction::BoardAdlibTrick:
        {
            return "BoardAdlibTrick";
        }
        case StateAction::BoardQuickStep:
        {
            return "BoardQuickStep";
        }
        case StateAction::BoardRunQuickStep:
        {
            return "BoardRunQuickStep";
        }
        case StateAction::BoardFall:
        {
            return "BoardFall";
        }
        case StateAction::BoardGrind:
        {
            return "BoardGrind";
        }
        case StateAction::BoardGrindJumpShort:
        {
            return "BoardGrindJumpShort";
        }
        case StateAction::BoardGrindJumpSide:
        {
            return "BoardGrindJumpSide";
        }
        case StateAction::BoardGrindLandJumpShort:
        {
            return "BoardGrindLandJumpShort";
        }
        case StateAction::BoardLandJumpShort:
        {
            return "BoardLandJumpShort";
        }
        case StateAction::BoardAirBoost:
        {
            return "BoardAirBoost";
        }
        case StateAction::BoardJumpSpring:
        {
            return "BoardJumpSpring";
        }
        case StateAction::BoardDrift:
        {
            return "BoardDrift";
        }
        case StateAction::JumpHurdle:
        {
            return "JumpHurdle";
        }
        case StateAction::Squat:
        {
            return "Squat";
        }
        case StateAction::SlidingEnd:
        {
            return "SlidingEnd";
        }
        case StateAction::SelectJump:
        {
            return "SelectJump";
        }
        case StateAction::JumpSelector:
        {
            return "JumpSelector";
        }
        case StateAction::Stomping_Crash:
        {
            return "Stomping_Crash";
        }
        case StateAction::StompingLand:
        {
            return "StompingLand";
        }
        case StateAction::LightSpeedDash:
        {
            return "LightSpeedDash";
        }
        case StateAction::SelectJumpAfter:
        {
            return "SelectJumpAfter";
        }
        case StateAction::DivingFloat:
        {
            return "DivingFloat";
        }
        case StateAction::DivingDive:
        {
            return "DivingDive";
        }
        case StateAction::DivingDamage:
        {
            return "DivingDamage";
        }
        case StateAction::SquatKick:
        {
            return "SquatKick";
        }
        case StateAction::OnIce:
        {
            return "OnIce";
        }
        case StateAction::DamageFreeze:
        {
            return "DamageFreeze";
        }
        case StateAction::DamageShock:
        {
            return "DamageShock";
        }
        case StateAction::DamageNearFar:
        {
            return "DamageNearFar";
        }
        case StateAction::Spin:
        {
            return "Spin";
        }
        case StateAction::SpinCharge:
        {
            return "SpinCharge";
        }
        case StateAction::SpinChargeSliding:
        {
            return "SpinChargeSliding";
        }
        case StateAction::SpinSliding:
        {
            return "SpinSliding";
        }
        case StateAction::SquatCharge:
        {
            return "SquatCharge";
        }
        case StateAction::FloatingBoost:
        {
            return "FloatingBoost";
        }
        case StateAction::TransformRocket:
        {
            return "TransformRocket";
        }
        case StateAction::TransformSpike:
        {
            return "TransformSpike";
        }
        case StateAction::TransformSp:
        {
            return "TransformSp";
        }
        case StateAction::TransformStandard:
        {
            return "TransformStandard";
        }
        case StateAction::RocketIdle:
        {
            return "RocketIdle";
        }
        case StateAction::RocketLaunch:
        {
            return "RocketLaunch";
        }
        case StateAction::RocketEnd:
        {
            return "RocketEnd";
        }
        case StateAction::RocketOverHeat:
        {
            return "RocketOverHeat";
        }
        case StateAction::SpikeIdle:
        {
            return "SpikeIdle";
        }
        case StateAction::SpikeWalk:
        {
            return "SpikeWalk";
        }
        case StateAction::SpikeFall:
        {
            return "SpikeFall";
        }
        case StateAction::SpikeJump:
        {
            return "SpikeJump";
        }
        case StateAction::SpikeLand:
        {
            return "SpikeLand";
        }
        case StateAction::SpikeCharge:
        {
            return "SpikeCharge";
        }
        case StateAction::SpikeBoost:
        {
            return "SpikeBoost";
        }
        case StateAction::SpikeJumpSpring:
        {
            return "SpikeJumpSpring";
        }
        case StateAction::SpikeSpecialJump:
        {
            return "SpikeSpecialJump";
        }
        case StateAction::SpikeDamageShock:
        {
            return "SpikeDamageShock";
        }
        case StateAction::SpikeHomingAttack:
        {
            return "SpikeHomingAttack";
        }
        case StateAction::SpikeHomingAttackAfter:
        {
            return "SpikeHomingAttackAfter";
        }
        }
    }
}