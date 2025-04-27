#pragma once
namespace Sonic
{
	class CPlayerProperty
	{
	public:
		int m_PlayerActorID;
		int m_PlayerType;
		int m_Field08;
		int m_Field0C;
		int m_Field10;
		int m_Field14;
	};
	BB_ASSERT_OFFSETOF(CPlayerProperty, m_PlayerActorID, 0x0);
	BB_ASSERT_OFFSETOF(CPlayerProperty, m_PlayerType, 0x4);
	BB_ASSERT_OFFSETOF(CPlayerProperty, m_Field08, 0x8);
	BB_ASSERT_OFFSETOF(CPlayerProperty, m_Field0C, 0xC);
	BB_ASSERT_OFFSETOF(CPlayerProperty, m_Field10, 0x10);
	BB_ASSERT_OFFSETOF(CPlayerProperty, m_Field14, 0x14);
}