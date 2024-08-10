namespace Sonic
{
    inline uint32_t pCPhysicsWorldCheckLineCollisionClosest = 0x10BE270;

    inline bool fPhysicsWorldCheckLineCollisionClosest(
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

    inline bool CPhysicsWorld::CheckLineCollisionClosest(SCollisionHitPointInfo& out_rCollisionHitPointInfo,
        const Hedgehog::Math::CVector& in_rStart, const Hedgehog::Math::CVector& in_rEnd, uint32_t in_CollisionCategory)
    {
        return fPhysicsWorldCheckLineCollisionClosest(this, &out_rCollisionHitPointInfo, in_rStart, in_rEnd, in_CollisionCategory);
    }
}