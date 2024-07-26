#pragma once

#include <BlueBlur.inl>

namespace Sonic
{
    class CPhysicsWorld;
    struct SCollisionHitPointInfo;

    class CRayCastCollision
    {
    public:
        CPhysicsWorld* m_pPhysicsWorld{};
        void* m_pHkpAabbPhantom{};

        CRayCastCollision(const Hedgehog::Base::THolder<CWorld>& in_pWorldHolder);
        bool CheckLineCollisionClosest(const size_t in_CollisionMask, const Hedgehog::Math::CVector& in_rRayStart,
            const Hedgehog::Math::CVector& in_rRayEnd, SCollisionHitPointInfo* out_pHitInfo);
    };

    BB_ASSERT_OFFSETOF(CRayCastCollision, m_pPhysicsWorld, 0x0);
    BB_ASSERT_OFFSETOF(CRayCastCollision, m_pHkpAabbPhantom, 0x4);
    BB_ASSERT_SIZEOF(CRayCastCollision, 0x8);
}

#include <Sonic/Havok/RaycastCollision.inl>