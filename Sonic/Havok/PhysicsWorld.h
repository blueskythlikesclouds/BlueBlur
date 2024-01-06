#pragma once

#include <BlueBlur.inl>

namespace hk2010_2_0
{
	class hkpWorld;
}

namespace Sonic
{
	class CPhysicsWorld;
	struct SCollisionHitPointInfo;

	static constexpr uint32_t pCPhysicsWorldCheckLineCollisionClosest = 0x10BE270;

	static bool fPhysicsWorldCheckLineCollisionClosest(
		CPhysicsWorld* This,
		SCollisionHitPointInfo* out_pCollisionHitPointInfo,
		const Hedgehog::Math::CVector& in_rStart,
		const Hedgehog::Math::CVector& in_rEnd,
		uint32_t in_CollisionCategory)
	{
		volatile bool result;

		__asm
		{
			mov edx, in_CollisionCategory
			mov ecx, in_rEnd
			push in_rStart
			mov esi, out_pCollisionHitPointInfo
			mov edi, This

			call[pCPhysicsWorldCheckLineCollisionClosest]
			mov result, al
		}

		return result;
	}

    class CPhysicsWorld
    {
	public:
		hk2010_2_0::hkpWorld* m_pHkpWorld;
		BB_INSERT_PADDING(0x1CC);

		bool CheckLineCollisionClosest(
			SCollisionHitPointInfo& out_rCollisionHitPointInfo,
			const Hedgehog::Math::CVector& in_rStart,
			const Hedgehog::Math::CVector& in_rEnd,
			uint32_t in_CollisionCategory)
		{
			return fPhysicsWorldCheckLineCollisionClosest(this, &out_rCollisionHitPointInfo, in_rStart, in_rEnd, in_CollisionCategory);
		}
    };

	BB_ASSERT_OFFSETOF(CPhysicsWorld, m_pHkpWorld, 0x0);
	BB_ASSERT_SIZEOF(CPhysicsWorld, 0x1D0);
}