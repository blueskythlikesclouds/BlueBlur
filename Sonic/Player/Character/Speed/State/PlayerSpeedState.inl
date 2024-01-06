namespace Sonic::Player
{
    inline const char* ConvertPlayerSpeedStateToString(EPlayerSpeedState in_PlayerSpeedState)
    {
        switch (in_PlayerSpeedState)
        {
        default:
        case ePlayerSpeedState_Stand:
        {
            return "Stand";
        }
        case ePlayerSpeedState_Walk:
        {
            return "Walk";
        }
        case ePlayerSpeedState_JumpShort:
        {
            return "JumpShort";
        }
        case ePlayerSpeedState_Jump:
        {
            return "Jump";
        }
        case ePlayerSpeedState_MoveStop:
        {
            return "MoveStop";
        }
        case ePlayerSpeedState_Brake:
        {
            return "Brake";
        }
        case ePlayerSpeedState_BrakeEnd:
        {
            return "BrakeEnd";
        }
        case ePlayerSpeedState_BrakeTurn:
        {
            return "BrakeTurn";
        }
        case ePlayerSpeedState_Fall:
        {
            return "Fall";
        }
        case ePlayerSpeedState_Land:
        {
            return "Land";
        }
        case ePlayerSpeedState_LandJumpShort:
        {
            return "LandJumpShort";
        }
        case ePlayerSpeedState_DeadLanding:
        {
            return "DeadLanding";
        }
        case ePlayerSpeedState_JumpSpring:
        {
            return "JumpSpring";
        }
        case ePlayerSpeedState_JumpSpringHeadLand:
        {
            return "JumpSpringHeadLand";
        }
        case ePlayerSpeedState_HangOn:
        {
            return "HangOn";
        }
        case ePlayerSpeedState_ReactionJump:
        {
            return "ReactionJump";
        }
        case ePlayerSpeedState_ReactionLand:
        {
            return "ReactionLand";
        }
        case ePlayerSpeedState_TrickJump:
        {
            return "TrickJump";
        }
        case ePlayerSpeedState_CrashWall:
        {
            return "CrashWall";
        }
        case ePlayerSpeedState_CrashWallDown:
        {
            return "CrashWallDown";
        }
        case ePlayerSpeedState_PressDead:
        {
            return "PressDead";
        }
        case ePlayerSpeedState_PressDamage:
        {
            return "PressDamage";
        }
        case ePlayerSpeedState_WallJumpReady:
        {
            return "WallJumpReady";
        }
        case ePlayerSpeedState_WallJump:
        {
            return "WallJump";
        }
        case ePlayerSpeedState_Battery:
        {
            return "Battery";
        }
        case ePlayerSpeedState_Sliding:
        {
            return "Sliding";
        }
        case ePlayerSpeedState_ShoesSliding:
        {
            return "ShoesSliding";
        }
        case ePlayerSpeedState_GoalAir:
        {
            return "GoalAir";
        }
        case ePlayerSpeedState_Goal:
        {
            return "Goal";
        }
        case ePlayerSpeedState_ExternalControl_Crash:
        {
            return "ExternalControl_Crash";
        }
        case ePlayerSpeedState_TrickJumpSuccess:
        {
            return "TrickJumpSuccess";
        }
        case ePlayerSpeedState_FinishExternalControlAir:
        {
            return "FinishExternalControlAir";
        }
        case ePlayerSpeedState_PushingWall:
        {
            return "PushingWall";
        }
        case ePlayerSpeedState_PushObject:
        {
            return "PushObject";
        }
        case ePlayerSpeedState_KickBox:
        {
            return "KickBox";
        }
        case ePlayerSpeedState_PlayAnimation:
        {
            return "PlayAnimation";
        }
        case ePlayerSpeedState_NormalDamage:
        {
            return "NormalDamage";
        }
        case ePlayerSpeedState_NormalDamageStandUp:
        {
            return "NormalDamageStandUp";
        }
        case ePlayerSpeedState_NormalDamageAir:
        {
            return "NormalDamageAir";
        }
        case ePlayerSpeedState_NormalDamageDead:
        {
            return "NormalDamageDead";
        }
        case ePlayerSpeedState_NormalDamageDeadAir:
        {
            return "NormalDamageDeadAir";
        }
        case ePlayerSpeedState_DamageCancel:
        {
            return "DamageCancel";
        }
        case ePlayerSpeedState_DamageOnRunning:
        {
            return "DamageOnRunning";
        }
        case ePlayerSpeedState_DamageOnStomping:
        {
            return "DamageOnStomping";
        }
        case ePlayerSpeedState_TrickAttackLand:
        {
            return "TrickAttackLand";
        }
        case ePlayerSpeedState_TrickAttack:
        {
            return "TrickAttack";
        }
        case ePlayerSpeedState_SpecialJump:
        {
            return "SpecialJump";
        }
        case ePlayerSpeedState_DrowningDead:
        {
            return "DrowningDead";
        }
        case ePlayerSpeedState_MoveToPositionAndWait:
        {
            return "MoveToPositionAndWait";
        }
        case ePlayerSpeedState_WallRunDamage:
        {
            return "WallRunDamage";
        }
        case ePlayerSpeedState_LookUp:
        {
            return "LookUp";
        }
        case ePlayerSpeedState_Stagger:
        {
            return "Stagger";
        }
        case ePlayerSpeedState_TakeBreath_Crash:
        {
            return "TakeBreath_Crash";
        }
        case ePlayerSpeedState_Suffocate_Crash:
        {
            return "Suffocate_Crash";
        }
        case ePlayerSpeedState_HipSliding:
        {
            return "HipSliding";
        }
        case ePlayerSpeedState_AdlibTrick:
        {
            return "AdlibTrick";
        }
        case ePlayerSpeedState_AdlibTrickFailure:
        {
            return "AdlibTrickFailure";
        }
        case ePlayerSpeedState_Pipe:
        {
            return "Pipe";
        }
        case ePlayerSpeedState_AirBoost:
        {
            return "AirBoost";
        }
        case ePlayerSpeedState_Drift:
        {
            return "Drift";
        }
        case ePlayerSpeedState_NoStanding:
        {
            return "NoStanding";
        }
        case ePlayerSpeedState_HomingAttack:
        {
            return "HomingAttack";
        }
        case ePlayerSpeedState_HomingAttackAfter:
        {
            return "HomingAttackAfter";
        }
        case ePlayerSpeedState_Grind:
        {
            return "Grind";
        }
        case ePlayerSpeedState_GrindJumpSide_Crash:
        {
            return "GrindJumpSide_Crash";
        }
        case ePlayerSpeedState_GrindSquat_Crash:
        {
            return "GrindSquat_Crash";
        }
        case ePlayerSpeedState_GrindJumpShort_Crash:
        {
            return "GrindJumpShort_Crash";
        }
        case ePlayerSpeedState_GrindLandJumpShort_Crash:
        {
            return "GrindLandJumpShort_Crash";
        }
        case ePlayerSpeedState_GrindSwitch_Crash:
        {
            return "GrindSwitch_Crash";
        }
        case ePlayerSpeedState_GrindDamageMiddle_Crash:
        {
            return "GrindDamageMiddle_Crash";
        }
        case ePlayerSpeedState_GrindToWallWalk_Crash:
        {
            return "GrindToWallWalk_Crash";
        }
        case ePlayerSpeedState_OnSlipFloor:
        {
            return "OnSlipFloor";
        }
        case ePlayerSpeedState_Stepping_Crash:
        {
            return "Stepping_Crash";
        }
        case ePlayerSpeedState_TramRiding_Crash:
        {
            return "TramRiding_Crash";
        }
        case ePlayerSpeedState_BeforeBoundJump:
        {
            return "BeforeBoundJump";
        }
        case ePlayerSpeedState_BoundJump:
        {
            return "BoundJump";
        }
        case ePlayerSpeedState_StumbleAir:
        {
            return "StumbleAir";
        }
        case ePlayerSpeedState_StumbleGround:
        {
            return "StumbleGround";
        }
        case ePlayerSpeedState_QuickStep:
        {
            return "QuickStep";
        }
        case ePlayerSpeedState_RunQuickStep:
        {
            return "RunQuickStep";
        }
        case ePlayerSpeedState_StartDash:
        {
            return "StartDash";
        }
        case ePlayerSpeedState_StartEvent:
        {
            return "StartEvent";
        }
        case ePlayerSpeedState_StartCrouching:
        {
            return "StartCrouching";
        }
        case ePlayerSpeedState_BoardWalk:
        {
            return "BoardWalk";
        }
        case ePlayerSpeedState_BoardGetOn:
        {
            return "BoardGetOn";
        }
        case ePlayerSpeedState_BoardGetOff:
        {
            return "BoardGetOff";
        }
        case ePlayerSpeedState_BoardNormalDamage:
        {
            return "BoardNormalDamage";
        }
        case ePlayerSpeedState_BoardJumpShort:
        {
            return "BoardJumpShort";
        }
        case ePlayerSpeedState_BoardJump:
        {
            return "BoardJump";
        }
        case ePlayerSpeedState_BoardAdlibTrick:
        {
            return "BoardAdlibTrick";
        }
        case ePlayerSpeedState_BoardQuickStep:
        {
            return "BoardQuickStep";
        }
        case ePlayerSpeedState_BoardRunQuickStep:
        {
            return "BoardRunQuickStep";
        }
        case ePlayerSpeedState_BoardFall:
        {
            return "BoardFall";
        }
        case ePlayerSpeedState_BoardGrind:
        {
            return "BoardGrind";
        }
        case ePlayerSpeedState_BoardGrindJumpShort:
        {
            return "BoardGrindJumpShort";
        }
        case ePlayerSpeedState_BoardGrindJumpSide:
        {
            return "BoardGrindJumpSide";
        }
        case ePlayerSpeedState_BoardGrindLandJumpShort:
        {
            return "BoardGrindLandJumpShort";
        }
        case ePlayerSpeedState_BoardLandJumpShort:
        {
            return "BoardLandJumpShort";
        }
        case ePlayerSpeedState_BoardAirBoost:
        {
            return "BoardAirBoost";
        }
        case ePlayerSpeedState_BoardJumpSpring:
        {
            return "BoardJumpSpring";
        }
        case ePlayerSpeedState_BoardDrift:
        {
            return "BoardDrift";
        }
        case ePlayerSpeedState_JumpHurdle:
        {
            return "JumpHurdle";
        }
        case ePlayerSpeedState_Squat:
        {
            return "Squat";
        }
        case ePlayerSpeedState_SlidingEnd:
        {
            return "SlidingEnd";
        }
        case ePlayerSpeedState_SelectJump:
        {
            return "SelectJump";
        }
        case ePlayerSpeedState_JumpSelector:
        {
            return "JumpSelector";
        }
        case ePlayerSpeedState_Stomping_Crash:
        {
            return "Stomping_Crash";
        }
        case ePlayerSpeedState_StompingLand:
        {
            return "StompingLand";
        }
        case ePlayerSpeedState_LightSpeedDash:
        {
            return "LightSpeedDash";
        }
        case ePlayerSpeedState_SelectJumpAfter:
        {
            return "SelectJumpAfter";
        }
        case ePlayerSpeedState_DivingFloat:
        {
            return "DivingFloat";
        }
        case ePlayerSpeedState_DivingDive:
        {
            return "DivingDive";
        }
        case ePlayerSpeedState_DivingDamage:
        {
            return "DivingDamage";
        }
        case ePlayerSpeedState_SquatKick:
        {
            return "SquatKick";
        }
        case ePlayerSpeedState_OnIce:
        {
            return "OnIce";
        }
        case ePlayerSpeedState_DamageFreeze:
        {
            return "DamageFreeze";
        }
        case ePlayerSpeedState_DamageShock:
        {
            return "DamageShock";
        }
        case ePlayerSpeedState_DamageNearFar:
        {
            return "DamageNearFar";
        }
        case ePlayerSpeedState_Spin:
        {
            return "Spin";
        }
        case ePlayerSpeedState_SpinCharge:
        {
            return "SpinCharge";
        }
        case ePlayerSpeedState_SpinChargeSliding:
        {
            return "SpinChargeSliding";
        }
        case ePlayerSpeedState_SpinSliding:
        {
            return "SpinSliding";
        }
        case ePlayerSpeedState_SquatCharge:
        {
            return "SquatCharge";
        }
        case ePlayerSpeedState_FloatingBoost:
        {
            return "FloatingBoost";
        }
        case ePlayerSpeedState_TransformRocket:
        {
            return "TransformRocket";
        }
        case ePlayerSpeedState_TransformSpike:
        {
            return "TransformSpike";
        }
        case ePlayerSpeedState_TransformSp:
        {
            return "TransformSp";
        }
        case ePlayerSpeedState_TransformStandard:
        {
            return "TransformStandard";
        }
        case ePlayerSpeedState_RocketIdle:
        {
            return "RocketIdle";
        }
        case ePlayerSpeedState_RocketLaunch:
        {
            return "RocketLaunch";
        }
        case ePlayerSpeedState_RocketEnd:
        {
            return "RocketEnd";
        }
        case ePlayerSpeedState_RocketOverHeat:
        {
            return "RocketOverHeat";
        }
        case ePlayerSpeedState_SpikeIdle:
        {
            return "SpikeIdle";
        }
        case ePlayerSpeedState_SpikeWalk:
        {
            return "SpikeWalk";
        }
        case ePlayerSpeedState_SpikeFall:
        {
            return "SpikeFall";
        }
        case ePlayerSpeedState_SpikeJump:
        {
            return "SpikeJump";
        }
        case ePlayerSpeedState_SpikeLand:
        {
            return "SpikeLand";
        }
        case ePlayerSpeedState_SpikeCharge:
        {
            return "SpikeCharge";
        }
        case ePlayerSpeedState_SpikeBoost:
        {
            return "SpikeBoost";
        }
        case ePlayerSpeedState_SpikeJumpSpring:
        {
            return "SpikeJumpSpring";
        }
        case ePlayerSpeedState_SpikeSpecialJump:
        {
            return "SpikeSpecialJump";
        }
        case ePlayerSpeedState_SpikeDamageShock:
        {
            return "SpikeDamageShock";
        }
        case ePlayerSpeedState_SpikeHomingAttack:
        {
            return "SpikeHomingAttack";
        }
        case ePlayerSpeedState_SpikeHomingAttackAfter:
        {
            return "SpikeHomingAttackAfter";
        }
        }
    }
}