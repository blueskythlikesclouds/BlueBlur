#pragma once

#include <Hedgehog/Base/Type/hhSharedString.h>
namespace Sonic
{
	class CGameParameter : public Hedgehog::Universe::CMessageActor
	{
	public:
		struct SField7C
		{
		public:
			BB_INSERT_PADDING(0x10);
			uint8_t Field10;
			uint8_t Field11;
			uint8_t Field12;
			uint8_t Field13;
			int32_t Field14;
			int32_t Field18;
			BB_INSERT_PADDING(0xA0E0);
			int32_t FieldA0FC;
			BB_INSERT_PADDING(0x120);
			BB_INSERT_PADDING(0x80);
			BB_INSERT_PADDING(0x20);
			int32_t FieldA2C0;
			int32_t FieldA2C4;
		};
		struct SStageParameter
		{
		public:
			int32_t Field00;
			int32_t Field04;
			int32_t Field08;
			int32_t Field0C;
			int32_t Field10;
			hh::list<int32_t> Field14;
			Hedgehog::Base::CSharedString TerrainArchiveName;
			Hedgehog::Base::CSharedString ModeName;
			int32_t Field28;
			Hedgehog::Base::CSharedString Field2C;
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
		SField7C* m_pField7C;
		SStageParameter* m_pStageParameter;
		int32_t m_Field84;
		int32_t m_Field88;
	};
	BB_ASSERT_OFFSETOF(CGameParameter, m_pField7C, 0x7C);
	BB_ASSERT_OFFSETOF(CGameParameter, m_pStageParameter, 0x80);
	BB_ASSERT_OFFSETOF(CGameParameter, m_Field84, 0x84);
	BB_ASSERT_OFFSETOF(CGameParameter, m_Field88, 0x88);
	BB_ASSERT_OFFSETOF(CGameParameter::SField7C, Field10, 0x10);
	BB_ASSERT_OFFSETOF(CGameParameter::SField7C, Field11, 0x11);
	BB_ASSERT_OFFSETOF(CGameParameter::SField7C, Field12, 0x12);
	BB_ASSERT_OFFSETOF(CGameParameter::SField7C, Field13, 0x13);
	BB_ASSERT_OFFSETOF(CGameParameter::SField7C, Field14, 0x14);
	BB_ASSERT_OFFSETOF(CGameParameter::SField7C, Field18, 0x18);
	BB_ASSERT_OFFSETOF(CGameParameter::SField7C, FieldA0FC, 0xA0FC);
	BB_ASSERT_OFFSETOF(CGameParameter::SField7C, FieldA2C0, 0xA2C0);
	BB_ASSERT_OFFSETOF(CGameParameter::SField7C, FieldA2C4, 0xA2C4);
	BB_ASSERT_OFFSETOF(CGameParameter::SStageParameter, Field00, 0);
	BB_ASSERT_OFFSETOF(CGameParameter::SStageParameter, Field04, 0x4);
	BB_ASSERT_OFFSETOF(CGameParameter::SStageParameter, Field08, 0x8);
	BB_ASSERT_OFFSETOF(CGameParameter::SStageParameter, Field0C, 0xC);
	BB_ASSERT_OFFSETOF(CGameParameter::SStageParameter, Field10, 0x10);
	BB_ASSERT_OFFSETOF(CGameParameter::SStageParameter, Field14, 0x14);
	BB_ASSERT_OFFSETOF(CGameParameter::SStageParameter, TerrainArchiveName, 0x20);
	BB_ASSERT_OFFSETOF(CGameParameter::SStageParameter, ModeName, 0x24);
	BB_ASSERT_OFFSETOF(CGameParameter::SStageParameter, Field28, 0x28);
	BB_ASSERT_OFFSETOF(CGameParameter::SStageParameter, Field2C, 0x2C);
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
}