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
        hh::list<void*> m_Field4;
        hh::list<void*> m_Field10;
        BB_INSERT_PADDING(0x24);
        Hedgehog::Math::CVector m_Field40;
        Hedgehog::Math::CVector m_Field50;
        uint8_t m_Field60;
        uint8_t m_Field61;
        uint8_t m_Field62;
        BB_INSERT_PADDING(0xC);
        Hedgehog::Math::CVector m_WorldCenter;
        int32_t m_Field80;
        BB_INSERT_PADDING(0x5C);
        Hedgehog::Math::CVector m_FieldE0;
        BB_INSERT_PADDING(0x10);
        Hedgehog::Math::CVector m_Field100;
        Hedgehog::Math::CVector m_Field110;
        BB_INSERT_PADDING(0x08);
        void* m_pCollisionFilter;
        BB_INSERT_PADDING(0xA0);

        bool CheckLineCollisionClosest(
            SCollisionHitPointInfo& out_rCollisionHitPointInfo,
            const Hedgehog::Math::CVector& in_rStart,
            const Hedgehog::Math::CVector& in_rEnd,
            uint32_t in_CollisionCategory);
    };

    BB_ASSERT_OFFSETOF(CPhysicsWorld, m_pHkpWorld, 0x0);
    BB_ASSERT_OFFSETOF(CPhysicsWorld, m_Field4, 0x4);
    BB_ASSERT_OFFSETOF(CPhysicsWorld, m_Field10, 0x10);
    BB_ASSERT_OFFSETOF(CPhysicsWorld, m_Field40, 0x40);
    BB_ASSERT_OFFSETOF(CPhysicsWorld, m_Field50, 0x50);
    BB_ASSERT_OFFSETOF(CPhysicsWorld, m_Field60, 0x60);
    BB_ASSERT_OFFSETOF(CPhysicsWorld, m_Field61, 0x61);
    BB_ASSERT_OFFSETOF(CPhysicsWorld, m_Field62, 0x62);
    BB_ASSERT_OFFSETOF(CPhysicsWorld, m_WorldCenter, 0x70);
    BB_ASSERT_OFFSETOF(CPhysicsWorld, m_Field80, 0x80);
    BB_ASSERT_OFFSETOF(CPhysicsWorld, m_FieldE0, 0xE0);
    BB_ASSERT_OFFSETOF(CPhysicsWorld, m_Field100, 0x100);
    BB_ASSERT_OFFSETOF(CPhysicsWorld, m_Field110, 0x110);
    BB_ASSERT_OFFSETOF(CPhysicsWorld, m_pCollisionFilter, 0x128);
    BB_ASSERT_SIZEOF(CPhysicsWorld, 0x1D0);
}

#include <Sonic/Havok/PhysicsWorld.inl>