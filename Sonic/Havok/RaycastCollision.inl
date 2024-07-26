namespace Sonic
{
    inline uint32_t pCRayCastCollisionCtor = 0x01182980;

    inline void fpCRayCastCollisionCtor(CRayCastCollision* This, const Hedgehog::Base::THolder<CWorld>& in_pWorldHolder)
    {
        __asm
        {
            mov eax, in_pWorldHolder
            mov esi, This
            call[pCRayCastCollisionCtor]
        }
    }

    inline CRayCastCollision::CRayCastCollision(const Hedgehog::Base::THolder<CWorld>& in_pWorldHolder)
    {
        fpCRayCastCollisionCtor(this, in_pWorldHolder);
    }

    static constexpr uint32_t pCRayCastCollisionCheckLineCollisionClosest = 0x010BE270;
    static bool fCRayCastCollisionCheckLineCollisionClosest(uint32_t in_pWorld, const size_t in_CollisionMask, const Hedgehog::Math::CVector& in_RayStart,
        const Hedgehog::Math::CVector& in_RayEnd, SCollisionHitPointInfo* out_pHitInfo)
    {
        bool result = false;

        __asm
        {
            mov edx, in_CollisionMask
            mov edi, in_pWorld
            mov esi, out_pHitInfo
            mov ecx, in_RayEnd
            push in_RayStart

            call[pCRayCastCollisionCheckLineCollisionClosest]

            mov result, al
        }

        return result;
    }

    inline bool CRayCastCollision::CheckLineCollisionClosest(const size_t in_CollisionMask, const Hedgehog::Math::CVector& in_rRayStart,
        const Hedgehog::Math::CVector& in_rRayEnd, SCollisionHitPointInfo* out_pHitInfo)
    {
        return fCRayCastCollisionCheckLineCollisionClosest(*(uint32_t*)this, in_CollisionMask, in_rRayStart, in_rRayEnd, out_pHitInfo);
    }
}