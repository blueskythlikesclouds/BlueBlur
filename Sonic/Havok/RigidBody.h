#pragma once

#include <Hedgehog/MirageCore/MatrixNode/hhMatrixNodeListener.h>
#include <Sonic/Havok/EntityUnit.h>

namespace Sonic
{
	class CRigidBody : public CEntityUnit, public Hedgehog::Mirage::CMatrixNodeListener
	{
	public:
		uint32_t m_Field54;
		uint32_t m_Field58;
		uint32_t m_Field5C;
		Hedgehog::Math::CMatrix44 m_Field60;
		Hedgehog::Math::CMatrix44 m_FieldA0;
		uint32_t m_FieldE0;
		uint32_t m_FieldE4;
		uint32_t m_FieldE8;
		uint32_t m_FieldEC;
		uint32_t m_FieldF0;
		uint32_t m_FieldF4;
		uint32_t m_FieldF8;
		uint32_t m_FieldFC;
		uint32_t m_Field100;
		uint32_t m_Field104;
		uint32_t m_Field108;
		uint32_t m_Field10C;

		hk2010_2_0::hkpShape* GetShape() const
		{
			return m_pHkpRigidBody->m_Collideable.m_Shape;
		}
	};

	BB_ASSERT_OFFSETOF(CRigidBody, m_Field60, 0x60);
	BB_ASSERT_SIZEOF(CRigidBody, 0x110);
}
