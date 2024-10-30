#pragma once

#include <Hedgehog/Base/Type/hhSharedString.h>
namespace Sonic
{
	class CGameParameter : public Hedgehog::Universe::CMessageActor
	{
	public:
		struct SSaveData
		{
			enum ESettings : uint32_t
			{
				eSettings_None = 0x0,
				eSettings_ControllerHints = 0x1,
				eSettings_OmochaoHints = 0x2,
				eSettings_Subtitles = 0x10,
				eSettings_Stereoscopic3D = 0x40
			};
			enum ERank : uint32_t
			{
				eRank_D,
				eRank_C,
				eRank_B,
				eRank_A,
				eRank_S,
			};
			enum ESkills : int32_t
			{
				eSkills_None = -1,
				eSkills_PowerBrake = 4,
				eSkills_SureFooted = 5,
				eSkills_SafetyNet = 6,
				eSkills_LastChance = 7,
				eSkills_TenSecondRings = 9,
				eSkills_Athleticism = 10,
				eSkills_TimeBrake = 11,
				eSkills_SuperSonic = 12,
				eSkills_FlameShield = 13,
				eSkills_AquaShield = 14,
				eSkills_ThunderShield = 15,
				eSkills_TwinSpinAttack = 16,
				eSkills_InvincibleStart = 17,
				eSkills_Shield = 18,
				eSkills_PowerSneakers = 19,
				eSkills_LongSpinDash = 20,
				eSkills_TreasureScanner = 21,
				eSkills_HomingAttack = 22,
				eSkills_HerculesMuscles = 23,
				eSkills_BreathHolder = 24,
				eSkills_BoardMaster = 25,
				eSkills_RingTime = 26,
				eSkills_BlastOff = 27,
				eSkills_SpeedUp = 28,
				eSkills_DirectJump = 29,
				eSkills_PowerStomp = 30,
				eSkills_QuickSlide = 31,
				eSkills_Acceleration = 32,
				eSkills_SmasherBonus = 33,
				eSkills_RingEnergyBonus = 34,
				eSkills_BoostGaugeUp = 35,
				eSkills_SerialHoming = 36,
				eSkills_AutoGauge = 37,
				eSkills_GaugeRebooter = 38,
				eSkills_TrickMastery = 39,
				eSkills_EndlessBoost = 40
			};
			enum EBossKeyState
			{
				eBossKeyState_Inactive,
				eBossKeyState_Active,
				eBossKeyState_Collectable,
				eBossKeyState_Collected,
				eBossKeyState_Placed,
				eBossKeyState_Used
			};
			enum EEmeraldState : int32_t
			{
				eEmeraldState_Inactive,
				eEmeraldState_Ready,
				eEmeraldState_Active,
				eEmeraldState_Collected,
				eEmeraldState_Gear1,
				eEmeraldState_Gear2,
				eEmeraldState_Gear3,
				eEmeraldState_Gear4,
				eEmeraldState_Gear5,
				eEmeraldState_Gear6,
				eEmeraldState_Gear7
			};
			struct SStageInfo
			{
				struct SCheckpointInfo
				{
					float Time;
					int32_t Field04;
				};
				int32_t Score;
				float BestTime1;
				float BestTime2;
				float BestTime3;
				ERank Rank;
				int32_t BestRings;
				int32_t AltTrackNum;
				SCheckpointInfo Checkpoints[32];
				int32_t LevelCompletionFlag;
			};
			struct SSkillInfo
			{
				struct SSkillInfoProfile
				{
					ESkills Skills[5];
				};
				struct SSkillInfoProfileName
				{
					int32_t Name1;
					int32_t Name2;
				};
				int32_t PreferredProfile;
				SSkillInfoProfile Profiles[5];
				SSkillInfoProfileName Names[5];
			};
			struct SRecordsInfo
			{
				float Distance;
				short ClearCount;
				short Enemies;
				int32_t TotalRings;
				int32_t TrickCombos;
			};

			BB_INSERT_PADDING(0x10);
			ELanguage VoiceLanguage;
			uint8_t MusicVolume;
			uint8_t SEVolume;
			uint8_t Brightness;
			int32_t StereoscopicScale;
			uint32_t EnabledSettings; //The values for this are the ones in ESettings
			SStageInfo Stages[142];
			int32_t Lives;
			uint8_t SonicType;
			Hedgehog::Math::CVector4 WhiteWorldPosition;
			EBossKeyState BossKeys[18];
			EEmeraldState Emeralds[7];
			std::bitset<90> RedRings; //The redrings values may be aligned incorrectly
			BB_INSERT_PADDING(0x78);
			int32_t SkillPoints;
			BB_INSERT_PADDING(0xC);
			SSkillInfo ClassicSkillInfo;
			SSkillInfo ModernSkillInfo;
			BB_INSERT_PADDING(0x80);
			SRecordsInfo ModernRecords;
			SRecordsInfo ClassicRecords;
			int32_t FieldA2C0;
			int32_t FieldA2C4;
		};
		struct SStageParameter
		{
			int32_t Field00;
			int32_t Field04;
			int32_t Field08;
			int32_t Field0C;
			int32_t Field10;
			hh::list<int32_t> Field14;
			Hedgehog::Base::CSharedString TerrainArchiveName;
			Hedgehog::Base::CSharedString ModeName;
			int32_t Field28;
			Hedgehog::Base::CSharedString EventName;
			Hedgehog::Base::CSharedString Field30;
			int32_t Field34;
			int32_t Field38;
			int32_t Field3C;
			int32_t Field40;
			BB_INSERT_PADDING(0x18);
			int32_t Field5C;
			int32_t Field60;
			BB_INSERT_PADDING(0x134);
			int32_t Field198;
			int32_t Field19C;
			int32_t* pMissionFlags;
			int32_t Field1A4;
			int32_t Field1A8;
			int32_t Field1AC;
			Hedgehog::Base::CSharedString BGMCueNodeName;
			int32_t Field1B4;
			int32_t Field1B8;
			int32_t Field1BC;
		};
		SSaveData* m_pSaveData;
		SStageParameter* m_pStageParameter;
		int32_t m_Field84;
		int32_t m_Field88;
	};
	BB_ASSERT_OFFSETOF(CGameParameter, m_pSaveData, 0x7C);
	BB_ASSERT_OFFSETOF(CGameParameter, m_pStageParameter, 0x80);
	BB_ASSERT_OFFSETOF(CGameParameter, m_Field84, 0x84);
	BB_ASSERT_OFFSETOF(CGameParameter, m_Field88, 0x88);
	BB_ASSERT_OFFSETOF(CGameParameter::SSaveData, VoiceLanguage, 0x10);
	BB_ASSERT_OFFSETOF(CGameParameter::SSaveData, MusicVolume, 0x11);
	BB_ASSERT_OFFSETOF(CGameParameter::SSaveData, SEVolume, 0x12);
	BB_ASSERT_OFFSETOF(CGameParameter::SSaveData, Brightness, 0x13);
	BB_ASSERT_OFFSETOF(CGameParameter::SSaveData, StereoscopicScale, 0x14);
	BB_ASSERT_OFFSETOF(CGameParameter::SSaveData, EnabledSettings, 0x18);
	BB_ASSERT_OFFSETOF(CGameParameter::SSaveData, Stages, 0x1C);
	BB_ASSERT_OFFSETOF(CGameParameter::SSaveData, Lives, 0x9FDC);
	BB_ASSERT_OFFSETOF(CGameParameter::SSaveData, SonicType, 0x9FE0);
	BB_ASSERT_OFFSETOF(CGameParameter::SSaveData, WhiteWorldPosition, 0x9FF0);
	BB_ASSERT_OFFSETOF(CGameParameter::SSaveData, BossKeys, 0xA000);
	BB_ASSERT_OFFSETOF(CGameParameter::SSaveData, Emeralds, 0xA048);
	BB_ASSERT_OFFSETOF(CGameParameter::SSaveData, RedRings, 0xA068);
	BB_ASSERT_OFFSETOF(CGameParameter::SSaveData, SkillPoints, 0xA0F0);
	BB_ASSERT_OFFSETOF(CGameParameter::SSaveData, ClassicSkillInfo, 0xA100);
	BB_ASSERT_OFFSETOF(CGameParameter::SSaveData, ModernSkillInfo, 0xA190);
	BB_ASSERT_OFFSETOF(CGameParameter::SSaveData, ModernRecords, 0xA2A0);
	BB_ASSERT_OFFSETOF(CGameParameter::SSaveData, ClassicRecords, 0xA2B0);
	BB_ASSERT_OFFSETOF(CGameParameter::SSaveData, FieldA2C0, 0xA2C0);
	BB_ASSERT_OFFSETOF(CGameParameter::SSaveData, FieldA2C4, 0xA2C4);
	BB_ASSERT_OFFSETOF(CGameParameter::SStageParameter, Field00, 0);
	BB_ASSERT_OFFSETOF(CGameParameter::SStageParameter, Field04, 0x4);
	BB_ASSERT_OFFSETOF(CGameParameter::SStageParameter, Field08, 0x8);
	BB_ASSERT_OFFSETOF(CGameParameter::SStageParameter, Field0C, 0xC);
	BB_ASSERT_OFFSETOF(CGameParameter::SStageParameter, Field10, 0x10);
	BB_ASSERT_OFFSETOF(CGameParameter::SStageParameter, Field14, 0x14);
	BB_ASSERT_OFFSETOF(CGameParameter::SStageParameter, TerrainArchiveName, 0x20);
	BB_ASSERT_OFFSETOF(CGameParameter::SStageParameter, ModeName, 0x24);
	BB_ASSERT_OFFSETOF(CGameParameter::SStageParameter, Field28, 0x28);
	BB_ASSERT_OFFSETOF(CGameParameter::SStageParameter, EventName, 0x2C);
	BB_ASSERT_OFFSETOF(CGameParameter::SStageParameter, Field30, 0x30);
	BB_ASSERT_OFFSETOF(CGameParameter::SStageParameter, Field34, 0x34);
	BB_ASSERT_OFFSETOF(CGameParameter::SStageParameter, Field38, 0x38);
	BB_ASSERT_OFFSETOF(CGameParameter::SStageParameter, Field3C, 0x3C);
	BB_ASSERT_OFFSETOF(CGameParameter::SStageParameter, Field40, 0x40);
	BB_ASSERT_OFFSETOF(CGameParameter::SStageParameter, Field5C, 0x5C);
	BB_ASSERT_OFFSETOF(CGameParameter::SStageParameter, Field60, 0x60);
	BB_ASSERT_OFFSETOF(CGameParameter::SStageParameter, Field198, 0x198);
	BB_ASSERT_OFFSETOF(CGameParameter::SStageParameter, Field19C, 0x19C);
	BB_ASSERT_OFFSETOF(CGameParameter::SStageParameter, pMissionFlags, 0x1A0);
	BB_ASSERT_OFFSETOF(CGameParameter::SStageParameter, Field1A4, 0x1A4);
	BB_ASSERT_OFFSETOF(CGameParameter::SStageParameter, Field1A8, 0x1A8);
	BB_ASSERT_OFFSETOF(CGameParameter::SStageParameter, Field1AC, 0x1AC);
	BB_ASSERT_OFFSETOF(CGameParameter::SStageParameter, BGMCueNodeName, 0x1B0);
	BB_ASSERT_OFFSETOF(CGameParameter::SStageParameter, Field1B4, 0x1B4);
	BB_ASSERT_OFFSETOF(CGameParameter::SStageParameter, Field1B8, 0x1B8);
	BB_ASSERT_OFFSETOF(CGameParameter::SStageParameter, Field1BC, 0x1BC);
	BB_ASSERT_SIZEOF(CGameParameter::SSaveData::SStageInfo, 0x120);
	BB_ASSERT_SIZEOF(CGameParameter::SSaveData::SSkillInfo, 0x90);
}