#pragma once

#include <Sonic/Player/Character/Base/PlayerContext.h>

namespace Sonic
{
    class CMatrixNodeWorldOffset;
    class CRigidBody;
    class CConvexShape;
    class CSparkEffectManager;
    class CPathContainer;   // SharedPtr - Hedgehog::Database::CDatabaseData
    class CPathController;
    class CWaitHandle;
}

namespace Sonic::Player
{
    class CReactionJumpQTE;     // Inherits - Chao::CSD::RCPtr<Chao::CSD::CProject>
    class CTrickJumpSequence;   // Inherits - Sonic::Player::CTrickJumpQTE

    class CSonicHudCountDownImpl;
    class CSonicHudHomingAttackImpl;
}

namespace Hedgehog::Sound
{
    class CSoundHandleCri;
}

namespace Hedgehog::Database
{
    class CDatabaseData;
}

namespace Sonic::Player
{
    // TODO: find a better place for these
    struct eStateFlags
    {
        bool eStateFlag_EarthGround;
        bool eStateFlag_HeadToVelocity;
        bool eStateFlag_HeadUpOnly;
        bool eStateFlag_SlowHeadToUpDirection;
        bool eStateFlag_OutOfControl;
        bool eStateFlag_NoLandOutOfControl;
        bool eStateFlag_DisableForwardPathInterpolation;
        bool eStateFlag_ChangePath;
        bool eStateFlag_ChangePathCameraChange;
        bool eStateFlag_WallWalkJump;
        bool eStateFlag_SupportWalkOnCeiling;
        bool eStateFlag_NotifyWalkOnCeiling;
        bool eStateFlag_AlwaysDownForce;
        bool eStateFlag_DisableDownForce;
        bool eStateFlag_Dead;
        bool eStateFlag_Goal;
        bool eStateFlag_Boost;
        bool eStateFlag_FloatingBoost;
        bool eStateFlag_StartingBoost;
        bool eStateFlag_EndBoost;
        bool eStateFlag_DummyBoost;
        bool eStateFlag_EndDummyBoost;
        bool eStateFlag_Homing;
        bool eStateFlag_EnableHomingAttack;
        bool eStateFlag_EnableHomingAttackOnDiving;
        bool eStateFlag_EnableHomingAttackOutOfControl;
        bool eStateFlag_DisableAirBoost;
        bool eStateFlag_EnableAirOnceAction;
        bool eStateFlag_DisableStomping;
        bool eStateFlag_ForceShoesSliding;
        bool eStateFlag_DisableShoesSliding;
        bool eStateFlag_OnWater;
        bool eStateFlag_OnNoDeadWater;
        bool eStateFlag_OnAboveWater;
        bool eStateFlag_OnSurfaceWater;
        bool eStateFlag_OnShallowWater;
        bool eStateFlag_OnWaterSeEnabled;
        bool eStateFlag_TerrainCollisionEnable;
        bool eStateFlag_AirOutOfControl;
        bool eStateFlag_NoPadStopWalk;
        bool eStateFlag_DisableAirAutoDec;
        bool eStateFlag_DisableWallJumpReady;
        bool eStateFlag_GroundDistanceZero;
        bool eStateFlag_NoPitchRollHorzOnAir;
        bool eStateFlag_DisableMoonsault;
        bool eStateFlag_KeepRunning;
        bool eStateFlag_KeepRunningEnableBackForce;
        bool eStateFlag_KeepRunningOnSpiral;
        bool eStateFlag_KeepRunningPause;
        bool eStateFlag_SShapeRunning;
        bool eStateFlag_MoveOnPath;
        bool eStateFlag_IgnoreTerrain;
        bool eStateFlag_UpdateYawByVelocity;
        bool eStateFlag_NoPitchRoll;
        bool eStateFlag_NoUpdateYaw;
        bool eStateFlag_NoUpdateYawRef;
        bool eStateFlag_UpdateYawOnAir;
        bool eStateFlag_NoUpdateAdvancedDirection;
        bool eStateFlag_CameraChagedPadCorrection;
        bool eStateFlag_EnableCameraChagedPadCorrect;
        bool eStateFlag_CameraToCullingBasePosEnabled;
        bool eStateFlag_NoDamage;
        bool eStateFlag_NoDead;
        bool eStateFlag_Damaging;
        bool eStateFlag_Paralyzing;
        bool eStateFlag_ReactinJumpPathChange;
        bool eStateFlag_ForcePitchRollGround;
        bool eStateFlag_EnableAttenuateJump;
        bool eStateFlag_NoGroundFall;
        bool eStateFlag_OnStairs;
        bool eStateFlag_OnBeltConveyor;
        bool eStateFlag_MoveToPositionAndWait;
        bool eStateFlag_StopPositionCount;
        bool eStateFlag_OnNoWallWalkGround;
        bool eStateFlag_ForceLandForCaught;
        bool eStateFlag_Restarting;
        bool eStateFlag_SlidingAndSquatPressOnly;
        bool eStateFlag_SideViewNoPathMove;
        bool eStateFlag_Pushing;
        bool eStateFlag_NoChange2DPath;
        bool eStateFlag_PrepreRestart;
        bool eStateFlag_SetDirectRotation;
        bool eStateFlag_IsTakingBreath;
        bool eStateFlag_OnSpiralGound;
        bool eStateFlag_OnMovableGround;
        bool eStateFlag_OnFakeMovableGround;
        bool eStateFlag_OnMoonsaltDisableGround;
        bool eStateFlag_EnableExceptionalBoost;
        bool eStateFlag_AcceptSlidingCollision;
        bool eStateFlag_AcceptBuoyancyForce;
        bool eStateFlag_AcceptEnvForce;
        bool eStateFlag_DisableAdlibTrick;
        bool eStateFlag_StandbyAdlibTrick;
        bool eStateFlag_StandbyChangeToSpin;
        bool eStateFlag_Pressing;
        bool eStateFlag_FallEnabledInPressing;
        bool eStateFlag_OnIntersectionalWay;
        bool eStateFlag_ObserveBoostInExternalControl;
        bool eStateFlag_ObserveSpinInExternalControl;
        bool eStateFlag_ObserveInputInExternalControl;
        bool eStateFlag_EscapeEnabledInExternalControl;
        bool eStateFlag_NoDamageInExternalControl;
        bool eStateFlag_Slipping;
        bool eStateFlag_InvokeFlameBarrier;
        bool eStateFlag_InvokeAquaBarrier;
        bool eStateFlag_InvokeThunderBarrier;
        bool eStateFlag_InvokeBarrier;
        bool eStateFlag_InvokePreciousTime;
        bool eStateFlag_InvokeHighSpeed;
        bool eStateFlag_InvokeTimeBreak;
        bool eStateFlag_InvokeSkateBoard;
        bool eStateFlag_InvokeSuperSonic;
        bool eStateFlag_InvokePtmRocket;
        bool eStateFlag_InvokePtmSpike;
        bool eStateFlag_InvokeUnbeaten;
        bool eStateFlag_DoubleJumping;
        bool eStateFlag_InvokeFixedMoveOn3D;
        bool eStateFlag_KeepStateAfterChangeDimension;
        bool eStateFlag_KeepPostureAfterChangeDimension;
        bool eStateFlag_CalibrateFrontDir;
        bool eStateFlag_EnableAnimationVelocityDirect;
        bool eStateFlag_EnableGravityControl;
        bool eStateFlag_EnableAirBoostOnGravityControl;
        bool eStateFlag_EnableChaosEnergySetting;
        bool eStateFlag_ChaosEnergySubstractDisabled;
        bool eStateFlag_EnableAutoAim;
        bool eStateFlag_ThroughGoalSignboard;
        bool eStateFlag_AutoBoost;
        bool eStateFlag_MaxSpeedLimited;
        bool eStateFlag_Pause;
        bool eStateFlag_SkateBoardSlowDown;
        bool eStateFlag_ChangeCollisionLocked;
        bool eStateFlag_ReadyGoOpened;
        bool eStateFlag_SpikeSpin;
        bool eStateFlag_ChangePostureInDeadAirEnabled;
        bool eStateFlag_DisableGroundSmoke;
        bool eStateFlag_Drifting;
        bool eStateFlag_DriftingLowSpeed;
        bool eStateFlag_DriftRight;
        bool eStateFlag_Squat;
        bool eStateFlag_LightSpeedDashReady;
        bool eStateFlag_BoostKeep;
        bool eStateFlag_DisableCrashWall;
        bool eStateFlag_WallCorrection;
        bool eStateFlag_Diving;
        bool eStateFlag_DivingFloat;
        bool eStateFlag_HipSliding;
        bool eStateFlag_GrindFullBalance;
        bool eStateFlag_GrindSideJump;
        bool eStateFlag_Freeze;
        bool eStateFlag_DisableBoost;
        bool eStateFlag_NoSquatToSliding;
        bool eStateFlag_IgnorePadInput;
        bool eStateFlag_Rising;
        bool eStateFlag_SpinChargeSliding;
        bool eStateFlag_CombinationAttacking;
        bool eStateFlag_SpinDash;
        bool eStateFlag_LightAttack;
        bool eStateFlag_AtomicSpin;
        bool eStateFlag_Binding;
        bool eStateFlag_ChgPlayerDisabled;
        bool eStateFlag_EndReflection;
        bool eStateFlag_CorrectOnPath;
        bool eStateFlag_DebugDrawGroundHitPosition;
        bool eStateFlag_DebugDrawVelocity;
        bool eStateFlag_DebugDrawPath;
        bool eStateFlag_DebugDrawSpikeInfo;
        bool eStateFlag_DebugExceptionalMove;
    };
    // TODO: Further documentation on this.
    // Its main use is getting state flags right now but it's not clear *WHAT* this is, or if anything else is useful.
    struct SContainsStateFlags
    {
        char field_0;
        char field_1;
        char field_2;
        char field_3;
        eStateFlags* StateFlags;
        char field_8;
        char field_9;
        char field_A;
        char field_B;
        char field_C;
        char field_D;
        char field_E;
        char field_F;
        char field_10;
        int16_t field_11;
        BYTE gap13[37];
        bool Unknown;
        BYTE gap39[10];
        char field_43;
    };

    class CPlayerSpeedProxyListener;

    class CPlayerSpeedContext : public CPlayerContext
    {
    public:
        static constexpr CPlayerSpeedContext** ms_pInstance = (CPlayerSpeedContext**)0x1E5E2F0;

        static CPlayerSpeedContext* GetInstance()
        {
            return *ms_pInstance;
        }

        class CStateSpeedBase;

        Hedgehog::Math::CVector m_Velocity; //0x290
        Hedgehog::Math::CVector m_HorizontalVelocity; //0x2A0
        Hedgehog::Math::CVector m_VerticalVelocity; //0x2B0
        Hedgehog::Math::CVector m_PreviousVelocity; //0x2C0
        Hedgehog::Math::CMatrix44 m_matrix2D0; //0x2D0
        Hedgehog::Math::CMatrix44 m_InputMatrix; //0x310
        Hedgehog::Math::CVector m_HighSpeedVector; //0x350
        char m_field360;    // Seems to be a flag for something?
        BB_INSERT_PADDING(0x0F);
        Hedgehog::Math::CVector m_FloorAndGrindrailNormal; //0x370
        Hedgehog::Math::CVector m_field380; // Something with stick direction
        BB_INSERT_PADDING(0x10);
        Hedgehog::Math::CVector m_field3A0; //0x3A0
        Hedgehog::Math::CVector m_field3B0; // PathDistance?
        BB_INSERT_PADDING(0x80);
        bool m_Grounded;
        BB_INSERT_PADDING(0x0F);
        Hedgehog::Math::CVector m_UpVector;
        BB_INSERT_PADDING(0x20);
        Hedgehog::Math::CVector m_field480;
        Hedgehog::Math::CVector m_field490;
        float m_field4A0;
        float m_field4A4;
        float m_field4A8;
        int  m_field4AC;
        char m_field4B0;  // Related to up vector?
        BB_INSERT_PADDING(0x0F);
        Hedgehog::Math::CQuaternion m_VerticalRotation;
        Hedgehog::Math::CQuaternion m_field4D0; // A vector or quaternion of some kind.
        Hedgehog::Math::CQuaternion m_HorizontalRotation;
        Hedgehog::Math::CVector m_ModelUpDirection;
        Hedgehog::Math::CVector m_JumpThrust; // 0x500

        boost::shared_ptr<CPathContainer>  m_sp2DPathContainer;     // 0x510
        boost::shared_ptr<CPathController> m_sp2DPathController_01; // 0x518
        boost::shared_ptr<CPathController> m_sp2DPathController_02; // 0x520
        BB_INSERT_PADDING(0x0C);

        SContainsStateFlags* m_pStateInfo;   // 0x534
        void* m_pfield538;   // unknownMemRegion
        float m_MaxVelocity; // 0x53C
        bool m_field540;     // Looks like a kind of height-check.
        bool m_field541;     // The rest of these might not be fields.
        bool m_field542;
        bool m_field543;
        int  m_field544;    // Some kind of... array size specifier
        BB_INSERT_PADDING(0x20);
        int NormalStrength;
        BB_INSERT_PADDING(0x20);
        bool m_field58C; // Something to do with velocity?
        BB_INSERT_PADDING(0x13);
        Hedgehog::Math::CVector CameraTargetOffset;
        float CameraHeight;
        float m_field5B4;
        uint32_t RingCount;
        float ChaosEnergy;
        float AirDragRateScale;
        float AirDragRateDown;
        float AirDragRateUp;
        float TimeGrounded;
        float TimeAirborne;
        float DbgScalePhysics;

        boost::shared_ptr<CPlayerSpeedProxyListener> m_spPlayerSpeedProxyListener; // 0x5D8
        BB_INSERT_PADDING(0x08);
        bool m_VelocityDirty;
        boost::shared_ptr<CRayCastCollision>   m_spRayCastCollision_01;   // 0x5EC
        boost::shared_ptr<CShapeCastCollision> m_spShapeCastCollision_01; // 0x5F4
        boost::shared_ptr<CShapeCastCollision> m_spShapeCastCollision_02; // 0x5FC
        boost::shared_ptr<CShapeCastCollision> m_spShapeCastCollision_03; // 0x604
        boost::shared_ptr<CShapeCastCollision> m_spShapeCastCollision_04; // 0x60C
        boost::shared_ptr<CShapeCastCollision> m_spShapeCastCollision_05; // 0x614

        float m_unkDotProduct;
        BB_INSERT_PADDING(0x04);

        boost::shared_ptr<Hedgehog::Mirage::CMatrixNodeNormal> m_spMatrixNodeNormal_04; // 0x624
        boost::shared_ptr<Hedgehog::Mirage::CMatrixNodeNormal> m_spMatrixNodeNormal_05; // 0x62C

        boost::shared_ptr<CMatrixNodeWorldOffset> m_spMatrixNodeWorldOffset; // 0x634
        BB_INSERT_PADDING(0xA4);

        Hedgehog::Math::CVector m_FloorNormal; //0x6E0
        BB_INSERT_PADDING(0xA0);

        Hedgehog::Math::CVector m_Gravity;
        Hedgehog::Math::CVector m_field7A0;
        float m_GravityTimer;
        float m_field7B4;
        float m_field7B8;
        float m_field7BC;
        float m_field7C0;
        BB_INSERT_PADDING(0x14);
        bool m_CameraOnlyUseGroundTarget;
        BB_INSERT_PADDING(0x07);
        Hedgehog::Math::CVector m_CameraHeightStatic;
        BB_INSERT_PADDING(0x04);

        boost::shared_ptr<CReactionJumpQTE>   m_spReactionJumpQTE_HUDPtr; // 0x7F4
        BB_INSERT_PADDING(0x04);
        boost::shared_ptr<CTrickJumpSequence> m_spTrickJumpSequence;      // 0x800
        BB_INSERT_PADDING(0x178);

        CRigidBody* m_pRigidBody_01; // 0x980
        BB_INSERT_PADDING(0xFC);
        CRigidBody* m_pRigidBody_02; // 0xA80
        BB_INSERT_PADDING(0x3C);
        CRigidBody* m_pRigidBody_03; // 0xAC0
        BB_INSERT_PADDING(0x3C);
        CRigidBody* m_pRigidBody_04; // 0xB00
        BB_INSERT_PADDING(0xFC);
        CRigidBody* m_pRigidBody_05; // 0xC00
        BB_INSERT_PADDING(0x244);

        boost::shared_ptr<CSonicHudCountDownImpl>    m_spSonicHudCountDownImpl;    // 0xE48
        boost::shared_ptr<CSonicHudHomingAttackImpl> m_spSonicHudHomingAttackImpl; // 0xE50

        boost::shared_ptr<CShapeCastCollision> m_spShapeCastCollision_06; // 0xE58
        boost::shared_ptr<CShapeCastCollision> m_spShapeCastCollision_07; // 0xE60
        boost::shared_ptr<CShapeCastCollision> m_spShapeCastCollision_08; // 0xE68
        boost::shared_ptr<CShapeCastCollision> m_spShapeCastCollision_09; // 0xE70
        boost::shared_ptr<CConvexShape> m_spConvexShape_01; // 0xE78
        boost::shared_ptr<CConvexShape> m_spConvexShape_02; // 0xE80
        boost::shared_ptr<CConvexShape> m_spConvexShape_03; // 0xE88
        boost::shared_ptr<CConvexShape> m_spConvexShape_04; // 0xE90
        BB_INSERT_PADDING(0x08);

        Hedgehog::Math::CVector m_fieldEA0;
        BB_INSERT_PADDING(636);

        bool m_SetModelVisibleAfterRefresh;   //0x112C
        uint32_t m_field1130; // Referenced for mesh visibility, seemingly just zeroes.
        bool m_isBallModel;

        CSparkEffectManager* m_pSparkEffectManager; // 0x1138
        BB_INSERT_PADDING(0x14);

        float m_turningLeanAmount; //0x1150
        float m_field1154;
        BB_INSERT_PADDING(0x30);
        uint32_t m_field1188;
        BB_INSERT_PADDING(0x08);

        boost::shared_ptr<Hedgehog::Sound::CSoundHandleCri> m_spHomingAttackSoundHandle; // 0x1194 - May be used for other things i.e. tricks
                                                                                         //        - Alt name: m_psHudSoundHandle
        BB_INSERT_PADDING(0x28);

        boost::shared_ptr<CShapeCastCollision> m_spShapeCastCollision_10; // 0x11C4
        boost::shared_ptr<CShapeCastCollision> m_spShapeCastCollision_11; // 0x11CC

        boost::shared_ptr<Hedgehog::Sound::CSoundHandleCri> m_spSoundHandleCri; // 0x11D4
        BB_INSERT_PADDING(0x04);

        boost::shared_ptr<CPathContainer> m_spGrindPathContainer_01; // 0x11E0
        boost::shared_ptr<CPathContainer> m_spGrindPathContainer_02; // 0x11E8
        boost::shared_ptr<CPathController> m_spGrindPathController; // 0x11F0
        BB_INSERT_PADDING(0x28);
        boost::shared_ptr<CWaitHandle>     m_spWaitHandle;     // 0x1220
        BB_INSERT_PADDING(0x08);
    };

    BB_ASSERT_OFFSETOF(CPlayerSpeedContext, m_VerticalRotation, 0x4C0);
    BB_ASSERT_OFFSETOF(CPlayerSpeedContext, m_HorizontalRotation, 0x4E0);
    BB_ASSERT_OFFSETOF(CPlayerSpeedContext, m_ModelUpDirection, 0x4F0);
    BB_ASSERT_OFFSETOF(CPlayerSpeedContext, m_spPlayerSpeedProxyListener, 0x5D8);
    BB_ASSERT_OFFSETOF(CPlayerSpeedContext, m_VelocityDirty, 0x5E8);
    BB_ASSERT_OFFSETOF(CPlayerSpeedContext, m_spRayCastCollision_01, 0x5EC);
    BB_ASSERT_OFFSETOF(CPlayerSpeedContext, m_spShapeCastCollision_01, 0x5F4);
    BB_ASSERT_OFFSETOF(CPlayerSpeedContext, m_spShapeCastCollision_02, 0x5FC);
    BB_ASSERT_OFFSETOF(CPlayerSpeedContext, m_spShapeCastCollision_03, 0x604);
    BB_ASSERT_OFFSETOF(CPlayerSpeedContext, m_spShapeCastCollision_04, 0x60C);
    BB_ASSERT_OFFSETOF(CPlayerSpeedContext, m_spShapeCastCollision_05, 0x614);
    BB_ASSERT_OFFSETOF(CPlayerSpeedContext, m_spMatrixNodeNormal_04, 0x624);
    BB_ASSERT_OFFSETOF(CPlayerSpeedContext, m_spMatrixNodeNormal_05, 0x62C);
    BB_ASSERT_OFFSETOF(CPlayerSpeedContext, m_spMatrixNodeWorldOffset, 0x634);
    BB_ASSERT_OFFSETOF(CPlayerSpeedContext, m_FloorNormal, 0x6E0);
    BB_ASSERT_OFFSETOF(CPlayerSpeedContext, m_spReactionJumpQTE_HUDPtr, 0x7F4);
    BB_ASSERT_OFFSETOF(CPlayerSpeedContext, m_spTrickJumpSequence, 0x800);
    BB_ASSERT_OFFSETOF(CPlayerSpeedContext, m_pRigidBody_01, 0x980);
    BB_ASSERT_OFFSETOF(CPlayerSpeedContext, m_pRigidBody_02, 0xA80);
    BB_ASSERT_OFFSETOF(CPlayerSpeedContext, m_pRigidBody_03, 0xAC0);
    BB_ASSERT_OFFSETOF(CPlayerSpeedContext, m_pRigidBody_04, 0xB00);
    BB_ASSERT_OFFSETOF(CPlayerSpeedContext, m_pRigidBody_05, 0xC00);
    BB_ASSERT_OFFSETOF(CPlayerSpeedContext, m_spSonicHudCountDownImpl, 0xE48);
    BB_ASSERT_OFFSETOF(CPlayerSpeedContext, m_spSonicHudHomingAttackImpl, 0xE50);
    BB_ASSERT_OFFSETOF(CPlayerSpeedContext, m_spShapeCastCollision_06, 0xE58);
    BB_ASSERT_OFFSETOF(CPlayerSpeedContext, m_spShapeCastCollision_07, 0xE60);
    BB_ASSERT_OFFSETOF(CPlayerSpeedContext, m_spShapeCastCollision_08, 0xE68);
    BB_ASSERT_OFFSETOF(CPlayerSpeedContext, m_spShapeCastCollision_09, 0xE70);
    BB_ASSERT_OFFSETOF(CPlayerSpeedContext, m_spConvexShape_01, 0xE78);
    BB_ASSERT_OFFSETOF(CPlayerSpeedContext, m_spConvexShape_02, 0xE80);
    BB_ASSERT_OFFSETOF(CPlayerSpeedContext, m_spConvexShape_03, 0xE88);
    BB_ASSERT_OFFSETOF(CPlayerSpeedContext, m_spConvexShape_04, 0xE90);
    BB_ASSERT_OFFSETOF(CPlayerSpeedContext, m_fieldEA0, 0xEA0);
    BB_ASSERT_OFFSETOF(CPlayerSpeedContext, m_pSparkEffectManager, 0x1138);
    BB_ASSERT_OFFSETOF(CPlayerSpeedContext, m_turningLeanAmount, 0x1150);
    BB_ASSERT_OFFSETOF(CPlayerSpeedContext, m_field1188, 0x1188);
    BB_ASSERT_OFFSETOF(CPlayerSpeedContext, m_spShapeCastCollision_10, 0x11C4);
    BB_ASSERT_OFFSETOF(CPlayerSpeedContext, m_spShapeCastCollision_11, 0x11CC);
    BB_ASSERT_OFFSETOF(CPlayerSpeedContext, m_spSoundHandleCri, 0x11D4);
    BB_ASSERT_OFFSETOF(CPlayerSpeedContext, m_spGrindPathContainer_01, 0x11E0);
    BB_ASSERT_OFFSETOF(CPlayerSpeedContext, m_spGrindPathContainer_02, 0x11E8);
    BB_ASSERT_OFFSETOF(CPlayerSpeedContext, m_spGrindPathController, 0x11F0);
    BB_ASSERT_OFFSETOF(CPlayerSpeedContext, m_spWaitHandle, 0x1220);

    BB_ASSERT_SIZEOF(CPlayerSpeedContext, 0x1230);
}