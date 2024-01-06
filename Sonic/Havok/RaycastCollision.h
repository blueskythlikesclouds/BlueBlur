#pragma once

#include <BlueBlur.inl>

namespace Sonic
{
	class CPhysicsWorld;

	class CRayCastCollision
	{
	public:
		CPhysicsWorld* m_pPhysicsWorld{};
		void* m_pHkpAabbPhantom{};

		CRayCastCollision(const Hedgehog::Base::TSynchronizedPtr<CWorld>& in_pWorld);
    };

	BB_ASSERT_OFFSETOF(CRayCastCollision, m_pPhysicsWorld, 0x0);
	BB_ASSERT_OFFSETOF(CRayCastCollision, m_pHkpAabbPhantom, 0x4);
	BB_ASSERT_SIZEOF(CRayCastCollision, 0x8);
}

#include <Sonic/Havok/RaycastCollision.inl>