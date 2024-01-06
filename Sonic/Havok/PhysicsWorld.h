#pragma once

#include <BlueBlur.inl>

namespace hk2010_2_0
{
    class hkpWorld;
}

namespace Sonic
{
    struct SCollisionHitPointInfo;

    class CPhysicsWorld
    {
    public:
        hk2010_2_0::hkpWorld* m_pHkpWorld;
        BB_INSERT_PADDING(0x1CC);

        bool CheckLineCollisionClosest(
            SCollisionHitPointInfo& out_rCollisionHitPointInfo,
            const Hedgehog::Math::CVector& in_rStart,
            const Hedgehog::Math::CVector& in_rEnd,
            uint32_t in_CollisionCategory);
    };

    BB_ASSERT_OFFSETOF(CPhysicsWorld, m_pHkpWorld, 0x0);
    BB_ASSERT_SIZEOF(CPhysicsWorld, 0x1D0);
}

#include <Sonic/Havok/PhysicsWorld.inl>