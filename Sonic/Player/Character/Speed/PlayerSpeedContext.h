#pragma once

#include <Sonic/Player/Character/Base/PlayerContext.h>

// Helper macro for accessing state flags.
// Example usage:
//   const bool boosting = pContext->StateFlag(eStateFlag_Boost);
//   pContext->StateFlag(eStateFlag_Boost) = false;

#define StateFlag(x) \
    m_pStateFlag->m_Flags[Sonic::Player::CPlayerSpeedContext::x]

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

    enum EPlayerSpeedParameter;
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
    class CPlayerSpeedProxyListener;

    class CPlayerSpeedContext : public CPlayerContext
    {
    public:
        static constexpr CPlayerSpeedContext** ms_pInstance = (CPlayerSpeedContext**)0x1E5E2F0;

        static CPlayerSpeedContext* GetInstance();

        enum EStateFlag;
        class CStateFlag;

        class CStateSpeedBase;

        Hedgehog::Math::CVector m_Velocity; //0x290
        Hedgehog::Math::CVector m_HorizontalVelocity; //0x2A0
        Hedgehog::Math::CVector m_VerticalVelocity; //0x2B0
        Hedgehog::Math::CVector m_PreviousVelocity; //0x2C0
        Hedgehog::Math::CMatrix44 m_InputMatrixTransposed; //0x2D0
        Hedgehog::Math::CMatrix44 m_InputMatrix; //0x310
        Hedgehog::Math::CVector m_HighSpeedVector; //0x350
        char m_Field360;    // Seems to be a flag for something?
        BB_INSERT_PADDING(0x0F);
        Hedgehog::Math::CVector m_FloorAndGrindRailNormal; //0x370
        Hedgehog::Math::CVector m_Field380; // Something with stick direction
        BB_INSERT_PADDING(0x10);
        Hedgehog::Math::CVector m_Field3A0; //0x3A0
        Hedgehog::Math::CVector m_Field3B0; // PathDistance?
        BB_INSERT_PADDING(0x80);
        bool m_Grounded;
        BB_INSERT_PADDING(0x0F);
        Hedgehog::Math::CVector m_UpVector;
        BB_INSERT_PADDING(0x20);
        float m_GroundDistance;
        int m_Field484;
        int m_Field488;
        int m_Field48C;
        Hedgehog::Math::CVector m_Field490;
        float m_Field4A0;
        float m_Field4A4;
        float m_Field4A8;
        int  m_Field4AC;
        char m_Field4B0;  // Related to up vector?
        BB_INSERT_PADDING(0x0F);
        Hedgehog::Math::CQuaternion m_VerticalRotation;
        Hedgehog::Math::CQuaternion m_Field4D0; // A vector or quaternion of some kind.
        Hedgehog::Math::CQuaternion m_HorizontalRotation;
        Hedgehog::Math::CVector m_ModelUpDirection;
        Hedgehog::Math::CVector m_JumpThrust; // 0x500

        boost::shared_ptr<CPathContainer>  m_sp2DPathContainer;     // 0x510
        boost::shared_ptr<CPathController> m_sp2DPathController_01; // 0x518
        boost::shared_ptr<CPathController> m_sp2DPathController_02; // 0x520
        BB_INSERT_PADDING(0x0C);

        CStateFlag* m_pStateFlag;   // 0x534
        CStateFlag* m_pField538;   // Uncertain. Similar kind of bool array...
        float m_MaxVelocity; // 0x53C
        float m_DeadHeight; // 0x540
        int  m_Field544;    // Some kind of... array size specifier
        BB_INSERT_PADDING(0x20);
        int m_NormalStrength;
        BB_INSERT_PADDING(0x20);
        bool m_Field58C; // Something to do with velocity?
        float m_Field590;
        float m_RunOnWaterTimer;
        float m_Field598;

        float m_Field59C;
        Hedgehog::Math::CVector m_CameraTargetOffset; // 0x5A0
        float m_CameraHeight;
        float m_Field5B4;
        uint32_t m_RingCount;
        float m_ChaosEnergy;
        float m_AirDragRateScale;
        float m_AirDragRateDown;
        float m_AirDragRateUp;
        float m_TimeGrounded;
        float m_TimeAirborne;
        float m_DbgScalePhysics;

        boost::shared_ptr<CPlayerSpeedProxyListener> m_spPlayerSpeedProxyListener; // 0x5D8
        BB_INSERT_PADDING(0x08);
        bool m_VelocityChanged;   // 0x5E8
        bool m_HorizontalOrVerticalVelocityChanged; // 0x5E9
        boost::shared_ptr<CRayCastCollision>   m_spRayCastCollision_01;   // 0x5EC
        boost::shared_ptr<CShapeCastCollision> m_spShapeCastCollision_01; // 0x5F4
        boost::shared_ptr<CShapeCastCollision> m_spShapeCastCollision_02; // 0x5FC
        boost::shared_ptr<CShapeCastCollision> m_spShapeCastCollision_Water; // 0x604
        boost::shared_ptr<CShapeCastCollision> m_spShapeCastCollision_04; // 0x60C
        boost::shared_ptr<CShapeCastCollision> m_spShapeCastCollision_05; // 0x614

        float m_UnkDotProduct;
        BB_INSERT_PADDING(0x04);

        boost::shared_ptr<Hedgehog::Mirage::CMatrixNodeNormal> m_spMatrixNodeNormal_04; // 0x624
        boost::shared_ptr<Hedgehog::Mirage::CMatrixNodeNormal> m_spMatrixNodeNormal_05; // 0x62C

        boost::shared_ptr<CMatrixNodeWorldOffset> m_spMatrixNodeWorldOffset; // 0x634

        BB_INSERT_PADDING(0x44);
        size_t m_ChaosEnergyGaugeSize; // 0x680
        float m_ChaosEnergySetting;    // 0x684

        //BB_INSERT_PADDING(0x58);
        BB_INSERT_PADDING(0x38);
        float m_FloatA;
        float m_FloatB;
        BB_INSERT_PADDING(0x18);

        Hedgehog::Math::CVector m_FloorNormal; //0x6E0
        BB_INSERT_PADDING(0xA0);

        Hedgehog::Math::CVector m_Gravity;
        Hedgehog::Math::CVector m_Field7A0;
        float m_GravityTimer;
        float m_Field7B4;
        float m_Field7B8;
        float m_Field7BC;
        float m_Field7C0;
        BB_INSERT_PADDING(0x14);
        bool m_CameraOnlyUseGroundTarget; // OR: HangOnActorID
        BB_INSERT_PADDING(0x07);
        Hedgehog::Math::CVector m_CameraHeightStatic;
        BB_INSERT_PADDING(0x04);

        boost::shared_ptr<CReactionJumpQTE>   m_spReactionJumpQTE_HUDPtr; // 0x7F4
        BB_INSERT_PADDING(0x04);
        boost::shared_ptr<CTrickJumpSequence> m_spTrickJumpSequence;      // 0x800
        BB_INSERT_PADDING(0x8);

        struct SGroundSearch
        {
            uint8_t isContact;
            Hedgehog::Math::CVector Normal;
            Hedgehog::Math::CVector Position;
            Sonic::CRigidBody* pRigidBody;
        };

        enum EGroundSearch
        {
            eGroundSearch_CC = 10,
            nGroundSearch = 21
        };

        SGroundSearch m_aGroundSearch[nGroundSearch];
        std::bitset<nGroundSearch> m_GroundSearchFlag; // 0xD50
        BB_INSERT_PADDING(0x50);
        size_t m_ResolveGroundNormalCompleteResultType; // 0xDA4
        int m_FieldDA8;
        int m_FieldDAC;
        int m_FieldDB0;
        int m_FieldDB4;
        int m_FieldDB8;
        int m_FieldDBC;
        int m_FieldDC0;
        int m_FieldDC4;
        int m_FieldDC8;
        int m_FieldDCC;
        int m_FieldDD0;
        int m_FieldDD4;
        int m_FieldDD8;
        int whateverThisIs;
        int m_FieldDE0;
        int m_FieldDE4;
        int m_FieldDE8;
        int m_FieldDEC;

        Hedgehog::Math::CVector m_FieldDF0;
        Hedgehog::Math::CVector m_FieldE00;
        BB_INSERT_PADDING(56);

        boost::shared_ptr<CSonicHudCountDownImpl>    m_spSonicHudCountDownImpl;    // 0xE48
        boost::shared_ptr<CSonicHudHomingAttackImpl> m_spSonicHudHomingAttackImpl; // 0xE50

        boost::shared_ptr<CShapeCastCollision> m_spHomingShapeCastCollision_3D; // 0xE58
        boost::shared_ptr<CShapeCastCollision> m_spHomingShapeCastCollision_3DNoAdLibTrick; // 0xE60
        boost::shared_ptr<CShapeCastCollision> m_spHomingShapeCastCollision_2D; // 0xE68
        boost::shared_ptr<CShapeCastCollision> m_spHomingShapeCastCollision_2DNoAdLibTrick; // 0xE70
        boost::shared_ptr<CConvexShape> m_spConvexShape_01; // 0xE78
        boost::shared_ptr<CConvexShape> m_spConvexShape_02; // 0xE80
        boost::shared_ptr<CConvexShape> m_spConvexShape_03; // 0xE88
        boost::shared_ptr<CConvexShape> m_spConvexShape_04; // 0xE90
        size_t m_HomingAttackTargetActorID;
        BB_INSERT_PADDING(0x04);

        Hedgehog::Math::CVector m_HomingAttackPosition;
        BB_INSERT_PADDING(636);

        bool m_SetModelVisibleAfterRefresh;   //0x112C
        uint32_t m_Field1130; // Referenced for mesh visibility, seemingly just zeroes.
        bool m_IsBallModel;

        CSparkEffectManager* m_pSparkEffectManager; // 0x1138
        BB_INSERT_PADDING(0x14);

        float m_TurningLeanAmount; //0x1150
        float m_Field1154;
        BB_INSERT_PADDING(0x30);
        uint32_t m_Field1188;
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

        uint8_t GetStateFlag(const EStateFlag in_stateFlag) const;
        void SetStateFlag(const EStateFlag in_stateFlag, const uint8_t in_flag) const;

        // Trick IntelliSense to suggest these macros.
#pragma push_macro("StateFlag")
#undef StateFlag
        void StateFlag(const EStateFlag in_stateFlag) const;
#pragma pop_macro("StateFlag")

        void HandleVelocityChanged();
        void HandleHorizontalOrVerticalVelocityChanged();

        const Hedgehog::Math::CVector& GetVelocity();
        void SetVelocity(const Hedgehog::Math::CVector& in_rVelocity);

        // 0x00E4F390
        const Hedgehog::Math::CVector& GetHorizontalVelocity();
        void SetHorizontalVelocity(const Hedgehog::Math::CVector& in_rVelocity);
        void SetHorizontalVelocityClearChanged(const Hedgehog::Math::CVector& in_rVelocity);

        const Hedgehog::Math::CVector& GetVerticalVelocity();
        void SetVerticalVelocity(const Hedgehog::Math::CVector& in_rVelocity);

        void AddVelocity(const Hedgehog::Math::CVector& in_rImpulse);

        // The direction of the player's current horizontal velocity. If the player is not moving, returns zero vector.
        Hedgehog::Math::CVector GetHorizontalVelocityDirection();

        // The direction of the player's movement. Defaults to the player's forward direction at a standstill. Useful for impulses.
        Hedgehog::Math::CVector GetHorizontalMovementDirection();

        Hedgehog::Math::CVector GetUpDirection();
        Hedgehog::Math::CVector GetRightDirection();
        Hedgehog::Math::CVector GetFrontDirection();

        float GetRotationSpeed();
        float GetRotationForce(
            const Hedgehog::Math::CVector& in_rFrontDirection,
            const Hedgehog::Math::CVector& in_rTargetDirection);

        void SetYawRotation(const Hedgehog::Math::CQuaternion& in_rRotation, bool in_UpdateMatrix = true);
        void SetYawRotation(float in_Angle, bool in_UpdateMatrix = true);

        float GetMaxChaosEnergy() const;
    };

    BB_ASSERT_OFFSETOF(CPlayerSpeedContext, m_Grounded, 0x440);
    BB_ASSERT_OFFSETOF(CPlayerSpeedContext, m_VerticalRotation, 0x4C0);
    BB_ASSERT_OFFSETOF(CPlayerSpeedContext, m_HorizontalRotation, 0x4E0);
    BB_ASSERT_OFFSETOF(CPlayerSpeedContext, m_ModelUpDirection, 0x4F0);
    BB_ASSERT_OFFSETOF(CPlayerSpeedContext, m_RunOnWaterTimer, 0x594);
    BB_ASSERT_OFFSETOF(CPlayerSpeedContext, m_CameraTargetOffset, 0x5A0);
    BB_ASSERT_OFFSETOF(CPlayerSpeedContext, m_spPlayerSpeedProxyListener, 0x5D8);
    BB_ASSERT_OFFSETOF(CPlayerSpeedContext, m_VelocityChanged, 0x5E8);
    BB_ASSERT_OFFSETOF(CPlayerSpeedContext, m_HorizontalOrVerticalVelocityChanged, 0x5E9);
    BB_ASSERT_OFFSETOF(CPlayerSpeedContext, m_spRayCastCollision_01, 0x5EC);
    BB_ASSERT_OFFSETOF(CPlayerSpeedContext, m_spShapeCastCollision_01, 0x5F4);
    BB_ASSERT_OFFSETOF(CPlayerSpeedContext, m_spShapeCastCollision_02, 0x5FC);
    BB_ASSERT_OFFSETOF(CPlayerSpeedContext, m_spShapeCastCollision_Water, 0x604);
    BB_ASSERT_OFFSETOF(CPlayerSpeedContext, m_spShapeCastCollision_04, 0x60C);
    BB_ASSERT_OFFSETOF(CPlayerSpeedContext, m_spShapeCastCollision_05, 0x614);
    BB_ASSERT_OFFSETOF(CPlayerSpeedContext, m_spMatrixNodeNormal_04, 0x624);
    BB_ASSERT_OFFSETOF(CPlayerSpeedContext, m_spMatrixNodeNormal_05, 0x62C);
    BB_ASSERT_OFFSETOF(CPlayerSpeedContext, m_spMatrixNodeWorldOffset, 0x634);
    BB_ASSERT_OFFSETOF(CPlayerSpeedContext, m_ChaosEnergyGaugeSize, 0x680);
    BB_ASSERT_OFFSETOF(CPlayerSpeedContext, m_ChaosEnergySetting, 0x684);
    BB_ASSERT_OFFSETOF(CPlayerSpeedContext, m_FloorNormal, 0x6E0);
    BB_ASSERT_OFFSETOF(CPlayerSpeedContext, m_CameraOnlyUseGroundTarget, 0x7D8);
    BB_ASSERT_OFFSETOF(CPlayerSpeedContext, m_spReactionJumpQTE_HUDPtr, 0x7F4);
    BB_ASSERT_OFFSETOF(CPlayerSpeedContext, m_spTrickJumpSequence, 0x800);
    BB_ASSERT_OFFSETOF(CPlayerSpeedContext, m_aGroundSearch, 0x810);
    BB_ASSERT_OFFSETOF(CPlayerSpeedContext, m_spSonicHudCountDownImpl, 0xE48);
    BB_ASSERT_OFFSETOF(CPlayerSpeedContext, m_spSonicHudHomingAttackImpl, 0xE50);
    BB_ASSERT_OFFSETOF(CPlayerSpeedContext, m_spHomingShapeCastCollision_3D, 0xE58);
    BB_ASSERT_OFFSETOF(CPlayerSpeedContext, m_spHomingShapeCastCollision_3DNoAdLibTrick, 0xE60);
    BB_ASSERT_OFFSETOF(CPlayerSpeedContext, m_spHomingShapeCastCollision_2D, 0xE68);
    BB_ASSERT_OFFSETOF(CPlayerSpeedContext, m_spHomingShapeCastCollision_2DNoAdLibTrick, 0xE70);
    BB_ASSERT_OFFSETOF(CPlayerSpeedContext, m_spConvexShape_01, 0xE78);
    BB_ASSERT_OFFSETOF(CPlayerSpeedContext, m_spConvexShape_02, 0xE80);
    BB_ASSERT_OFFSETOF(CPlayerSpeedContext, m_spConvexShape_03, 0xE88);
    BB_ASSERT_OFFSETOF(CPlayerSpeedContext, m_spConvexShape_04, 0xE90);
    BB_ASSERT_OFFSETOF(CPlayerSpeedContext, m_HomingAttackTargetActorID, 0xE98);
    BB_ASSERT_OFFSETOF(CPlayerSpeedContext, m_HomingAttackPosition, 0xEA0);
    BB_ASSERT_OFFSETOF(CPlayerSpeedContext, m_pSparkEffectManager, 0x1138);
    BB_ASSERT_OFFSETOF(CPlayerSpeedContext, m_TurningLeanAmount, 0x1150);
    BB_ASSERT_OFFSETOF(CPlayerSpeedContext, m_Field1188, 0x1188);
    BB_ASSERT_OFFSETOF(CPlayerSpeedContext, m_spShapeCastCollision_10, 0x11C4);
    BB_ASSERT_OFFSETOF(CPlayerSpeedContext, m_spShapeCastCollision_11, 0x11CC);
    BB_ASSERT_OFFSETOF(CPlayerSpeedContext, m_spSoundHandleCri, 0x11D4);
    BB_ASSERT_OFFSETOF(CPlayerSpeedContext, m_spGrindPathContainer_01, 0x11E0);
    BB_ASSERT_OFFSETOF(CPlayerSpeedContext, m_spGrindPathContainer_02, 0x11E8);
    BB_ASSERT_OFFSETOF(CPlayerSpeedContext, m_spGrindPathController, 0x11F0);
    BB_ASSERT_OFFSETOF(CPlayerSpeedContext, m_spWaitHandle, 0x1220);

    BB_ASSERT_SIZEOF(CPlayerSpeedContext, 0x1230);
}

#include <Sonic/Player/Character/Speed/PlayerSpeedContext.inl>