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
        hh::list<void*> m_List04;
        hh::list<void*> m_List10;
        BB_INSERT_PADDING(0x24);
        Hedgehog::Math::CVector m_Field040;
        Hedgehog::Math::CVector m_Field050;
        char m_Field060;
        char m_Field061;
        char m_Field062;
        BB_INSERT_PADDING(0x0C);
        Hedgehog::Math::CVector m_WorldCenter;
        int m_Field080;
        BB_INSERT_PADDING(0x5C);
        Hedgehog::Math::CVector m_Field0E0;
        BB_INSERT_PADDING(0x10);
        Hedgehog::Math::CVector m_Field100;
        Hedgehog::Math::CVector m_Field110;
        BB_INSERT_PADDING(0x08);
        int m_pCollisionFilter;
        BB_INSERT_PADDING(0xA0);

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