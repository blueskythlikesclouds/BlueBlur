#pragma once

#include <Hedgehog/Base/hhObject.h>
#include <Hedgehog/Base/Type/hhSharedString.h>

#undef PlaySound

namespace Hedgehog::Sound
{
    class CSoundHandle;
}

namespace Sonic::Player
{
    class CPlayer;
    class CPlayerContext;

    static inline BB_FUNCTION_PTR(const Hedgehog::Base::CSharedString&, __stdcall, 
        fpCPlayerContextGetAnimationName, 0xE72CB0, CPlayerContext* This);

    class CPlayerContext : public Hedgehog::Base::CObject
    {
    public:
        BB_INSERT_PADDING(0x10C);
        CPlayer* m_pPlayer;
        BB_INSERT_PADDING(0x17C);

        virtual ~CPlayerContext() = default;

        virtual void CPlayerContext04() {}
        virtual void CPlayerContext08() {}
        virtual void CPlayerContext0C() {}
        virtual void CPlayerContext10() {}
        virtual void CPlayerContext14() {}
        virtual void CPlayerContext18() {}
        virtual void CPlayerContext1C() {}
        virtual void CPlayerContext20() {}
        virtual void CPlayerContext24() {}
        virtual void CPlayerContext28() {}
        virtual void CPlayerContext2C() {}
        virtual void CPlayerContext30() {}
        virtual void CPlayerContext34() {}
        virtual void CPlayerContext38() {}
        virtual void CPlayerContext3C() {}
        virtual void CPlayerContext40() {}
        virtual void CPlayerContext44() {}
        virtual void CPlayerContext48() {}
        virtual void CPlayerContext4C() {}
        virtual void CPlayerContext50() {}
        virtual void CPlayerContext54() {}
        virtual void CPlayerContext58() {}

        const Hedgehog::Base::CSharedString& GetAnimationName()
        {
            return fpCPlayerContextGetAnimationName(this);
        }

        virtual void SetAnimation(const Hedgehog::Base::CSharedString& name) = 0;

        virtual void CPlayerContext60() {}
        virtual void CPlayerContext64() {}
        virtual void CPlayerContext68() {}
        virtual void CPlayerContext6C() {}
        virtual void CPlayerContext70() {}

        virtual boost::shared_ptr<Hedgehog::Sound::CSoundHandle> PlaySound(size_t cueId, bool loop) = 0;

        virtual void CPlayerContext78() {}
        virtual void CPlayerContext7C() {}
        virtual void CPlayerContext80() {}
        virtual void CPlayerContext84() {}
        virtual void CPlayerContext88() {}
        virtual void CPlayerContext8C() {}
        virtual void CPlayerContext90() {}
    };

    BB_ASSERT_OFFSETOF(CPlayerContext, m_pPlayer, 0x110);
    BB_ASSERT_SIZEOF(CPlayerContext, 0x290);
}