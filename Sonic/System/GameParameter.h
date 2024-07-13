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
			byte m_Field10;
			byte m_Field11;
			byte m_Field12;
			byte m_Field13;
			int m_Field14;
			int m_Field18;
			BB_INSERT_PADDING(0xA0E0);
			int m_FieldA0FC;
			BB_INSERT_PADDING(0x120);
			BB_INSERT_PADDING(0x80);
			BB_INSERT_PADDING(0x20);
			int m_FieldA2C0;
			int m_FieldA2C4;
		};
		struct SStageParameters
		{
		public:
			int m_Field00;
			int m_Field04;
			int m_Field08;
			int m_Field0C;
			int m_Field10;
			hh::list<int> m_Field14;
			Hedgehog::Base::CSharedString m_TerrainArchiveName;
			Hedgehog::Base::CSharedString m_ModeName;
			int m_Field28;
			Hedgehog::Base::CSharedString m_Field2C;
			Hedgehog::Base::CSharedString m_Field30;
			int m_Field34;
			int m_Field38;
			int m_Field3C;
			int m_Field40;
			BB_INSERT_PADDING(0x18);
			int m_Field5C;
			int m_Field60;
			BB_INSERT_PADDING(0x134);
			int m_Field198;
			int m_Field19C;
			int* m_MissionFlags;
			int m_Field1A4;
			int m_Field1A8;
			int m_Field1AC;
			Hedgehog::Base::CSharedString m_BGMCueNodeName;
			int m_Field1B4;
			int m_Field1B8;
			int m_Field1BC;

		};
		SField7C* m_Field7C;
		SStageParameters* m_pStageParameters;
		int m_Field84;
		int m_Field88;
	};
	BB_ASSERT_OFFSETOF(CGameParameter, m_Field7C, 0x7C);
	BB_ASSERT_OFFSETOF(CGameParameter, m_pStageParameters, 0x80);
	BB_ASSERT_OFFSETOF(CGameParameter, m_Field84, 0x84);
	BB_ASSERT_OFFSETOF(CGameParameter, m_Field88, 0x88);
	BB_ASSERT_OFFSETOF(CGameParameter::SField7C, m_Field10, 0x10);
	BB_ASSERT_OFFSETOF(CGameParameter::SField7C, m_Field11, 0x11);
	BB_ASSERT_OFFSETOF(CGameParameter::SField7C, m_Field12, 0x12);
	BB_ASSERT_OFFSETOF(CGameParameter::SField7C, m_Field13, 0x13);
	BB_ASSERT_OFFSETOF(CGameParameter::SField7C, m_Field14, 0x14);
	BB_ASSERT_OFFSETOF(CGameParameter::SField7C, m_Field18, 0x18);
	BB_ASSERT_OFFSETOF(CGameParameter::SField7C, m_FieldA0FC, 0xA0FC);
	BB_ASSERT_OFFSETOF(CGameParameter::SField7C, m_FieldA2C0, 0xA2C0);
	BB_ASSERT_OFFSETOF(CGameParameter::SField7C, m_FieldA2C4, 0xA2C4);
	BB_ASSERT_OFFSETOF(CGameParameter::SStageParameters, m_Field00, 0);
	BB_ASSERT_OFFSETOF(CGameParameter::SStageParameters, m_Field04, 0x4);
	BB_ASSERT_OFFSETOF(CGameParameter::SStageParameters, m_Field08, 0x8);
	BB_ASSERT_OFFSETOF(CGameParameter::SStageParameters, m_Field0C, 0xC);
	BB_ASSERT_OFFSETOF(CGameParameter::SStageParameters, m_Field10, 0x10);
	BB_ASSERT_OFFSETOF(CGameParameter::SStageParameters, m_Field14, 0x14);
	BB_ASSERT_OFFSETOF(CGameParameter::SStageParameters, m_TerrainArchiveName, 0x20);
	BB_ASSERT_OFFSETOF(CGameParameter::SStageParameters, m_ModeName, 0x24);
	BB_ASSERT_OFFSETOF(CGameParameter::SStageParameters, m_Field28, 0x28);
	BB_ASSERT_OFFSETOF(CGameParameter::SStageParameters, m_Field2C, 0x2C);
	BB_ASSERT_OFFSETOF(CGameParameter::SStageParameters, m_Field30, 0x30);
	BB_ASSERT_OFFSETOF(CGameParameter::SStageParameters, m_Field34, 0x34);
	BB_ASSERT_OFFSETOF(CGameParameter::SStageParameters, m_Field38, 0x38);
	BB_ASSERT_OFFSETOF(CGameParameter::SStageParameters, m_Field3C, 0x3C);
	BB_ASSERT_OFFSETOF(CGameParameter::SStageParameters, m_Field40, 0x40);
	BB_ASSERT_OFFSETOF(CGameParameter::SStageParameters, m_Field5C, 0x5C);
	BB_ASSERT_OFFSETOF(CGameParameter::SStageParameters, m_Field60, 0x60);
	BB_ASSERT_OFFSETOF(CGameParameter::SStageParameters, m_Field198, 0x198);
	BB_ASSERT_OFFSETOF(CGameParameter::SStageParameters, m_Field19C, 0x19C);
	BB_ASSERT_OFFSETOF(CGameParameter::SStageParameters, m_MissionFlags, 0x1A0);
	BB_ASSERT_OFFSETOF(CGameParameter::SStageParameters, m_Field1A4, 0x1A4);
	BB_ASSERT_OFFSETOF(CGameParameter::SStageParameters, m_Field1A8, 0x1A8);
	BB_ASSERT_OFFSETOF(CGameParameter::SStageParameters, m_Field1AC, 0x1AC);
	BB_ASSERT_OFFSETOF(CGameParameter::SStageParameters, m_BGMCueNodeName, 0x1B0);
	BB_ASSERT_OFFSETOF(CGameParameter::SStageParameters, m_Field1B4, 0x1B4);
	BB_ASSERT_OFFSETOF(CGameParameter::SStageParameters, m_Field1B8, 0x1B8);
	BB_ASSERT_OFFSETOF(CGameParameter::SStageParameters, m_Field1BC, 0x1BC);
}