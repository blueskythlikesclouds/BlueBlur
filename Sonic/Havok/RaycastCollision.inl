namespace Sonic
{
    inline uint32_t pCRayCastCollisionCtor = 0x01182980;

    inline void fpCRayCastCollisionCtor(CRayCastCollision* This, const Hedgehog::Base::THolder<CWorld>& in_pWorld)
    {
        __asm
        {
            mov eax, in_pWorld
            mov esi, This
            call[pCRayCastCollisionCtor]
        }
    }

    inline CRayCastCollision::CRayCastCollision(const Hedgehog::Base::THolder<CWorld>& in_pWorld)
    {
        fpCRayCastCollisionCtor(this, in_pWorld);
    }
}