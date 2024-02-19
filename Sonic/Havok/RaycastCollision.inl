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
}