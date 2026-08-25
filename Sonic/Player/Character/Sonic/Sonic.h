#pragma once

#include <Sonic/Player/Character/Sonic/SonicContext.h>
#include <Sonic/Player/Character/Speed/PlayerSpeed.h>

class hkpCylinderShape;
namespace Hedgehog::Mirage
{
	class CSingleElementEffectZOffset;
}
namespace Sonic::Player
{
	class CSonic : public CPlayerSpeed
	{
	public:
		struct SPlayerStruct1
		{
			int Field00;
			int Field04;
			int Field08;
			int Field0C;
		};

		int m_Field2D0;
		int m_Field2D4;
		int m_Field2D8;
		int m_Field2DC;
		boost::shared_ptr<Hedgehog::Mirage::CMatrixNodeNormal> m_Field2E0;
		boost::shared_ptr<Hedgehog::Mirage::CMatrixNodeNormal> m_Field2E8;
		boost::shared_ptr<Sonic::CRigidBody> m_spRigidbody1;
		boost::shared_ptr<Sonic::CRigidBody> m_spRigidbody2;
		boost::shared_ptr<Sonic::CRigidBody> m_spRigidbody3;
		int m_ColID1_usedToBe_TimeSinceHitObject;
		int m_ColID2_Item;
		int m_ColID3_ItemBoost;
		int m_ColID4;
		int m_ColID5;
		hkpCylinderShape* m_Field31C;
		hkpCylinderShape* m_pItemCollider;
		hkpCylinderShape* m_Field324;
		hkpCylinderShape* m_pShapeSquatKick;
		hkpCylinderShape* m_Field32C;
		Hedgehog::Math::CVector m_Field330;
		Hedgehog::Math::CVector m_Field340;
		int m_Field350;
		int m_Field354;
		int m_Field358;
		int m_Field35C;
		int m_Field360;
		int m_Field364;
		boost::shared_ptr<Hedgehog::Mirage::CMaterialData> m_spEyeMaterial1;
		boost::shared_ptr<Hedgehog::Mirage::CMaterialData> m_spEyeMaterial2;
		boost::shared_ptr<Hedgehog::Motion::CTexcoordAnimationData> m_spEyeMotion1;
		boost::shared_ptr<Hedgehog::Motion::CTexcoordAnimationData> m_spEyeMotion2;
		int m_Field388;
		int m_Field38C;
		int m_Field390;
		int m_AnimTimeInFrames01;
		int m_Field398;
		Hedgehog::Base::CSharedString m_AnimationName;
		boost::shared_ptr<Hedgehog::Mirage::CSingleElementEffectZOffset> m_Field3A0;
		SPlayerStruct1 m_Array1[5];

		CSonicContext* GetContext() const;
	};

	BB_ASSERT_SIZEOF(CSonic, 0x400);
}

#include <Sonic/Player/Character/Sonic/Sonic.inl>