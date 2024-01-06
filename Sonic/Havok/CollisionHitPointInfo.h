#pragma once

#include <BlueBlur.inl>

namespace Sonic
{
    class CPhysicsUnit;

    struct SCollisionHitPointInfo
    {
        CNoAlignVector Normal{};
        CNoAlignVector Position{};
        CPhysicsUnit* pPhysicsUnit{};
        float HitFraction{};
        size_t ShapeKey{};
        bool Valid{};
    };

    BB_ASSERT_OFFSETOF(SCollisionHitPointInfo, Normal, 0x0);
    BB_ASSERT_OFFSETOF(SCollisionHitPointInfo, Position, 0xC);
    BB_ASSERT_OFFSETOF(SCollisionHitPointInfo, pPhysicsUnit, 0x18);
    BB_ASSERT_OFFSETOF(SCollisionHitPointInfo, HitFraction, 0x1C);
    BB_ASSERT_OFFSETOF(SCollisionHitPointInfo, ShapeKey, 0x20);
    BB_ASSERT_OFFSETOF(SCollisionHitPointInfo, Valid, 0x24);
    BB_ASSERT_SIZEOF(SCollisionHitPointInfo, 0x28);
}