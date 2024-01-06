#pragma once

#include <BlueBlur.inl>

namespace Sonic
{
	class CRayCastCollision;

	static constexpr uint32_t pCRayCastCollisionCtor = 0x01182980;

	static void fpCRayCastCollisionCtor(CRayCastCollision* This, const Hedgehog::Base::TSynchronizedPtr<CWorld>& in_pWorld)
	{
		__asm
		{
			mov eax, in_pWorld
			mov esi, This
			call[pCRayCastCollisionCtor]
		}
	}

	class CPhysicsWorld;

	class CRayCastCollision
	{
	public:
		CPhysicsWorld* m_pPhysicsWorld{};
		void* m_pHkpAabbPhantom{};

		CRayCastCollision(const Hedgehog::Base::TSynchronizedPtr<CWorld>& in_pWorld)
		{
			fpCRayCastCollisionCtor(this, in_pWorld);
		}
	};

	BB_ASSERT_OFFSETOF(CRayCastCollision, m_pPhysicsWorld, 0x0);
	BB_ASSERT_OFFSETOF(CRayCastCollision, m_pHkpAabbPhantom, 0x4);
	BB_ASSERT_SIZEOF(CRayCastCollision, 0x8);
}