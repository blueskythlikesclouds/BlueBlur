#pragma once

#include <Sonic/Player/Character/Speed/PlayerSpeedContext.h>
namespace Hedgehog::Glitter
{
    class CHandle;
};
namespace Sonic::Player
{
    class CSonicContext : public CPlayerSpeedContext
    {
    public:
        static constexpr CSonicContext** ms_pInstance = (CSonicContext**)0x1E5E2F8;

        static CSonicContext* GetInstance();

        BB_INSERT_PADDING(0x48);
        boost::shared_ptr<void> m_spForwardPathController;
        BB_INSERT_PADDING(0x214);
        boost::shared_ptr<Hedgehog::Glitter::CHandle> m_spBoostParticle;
        boost::shared_ptr<Hedgehog::Glitter::CHandle> m_spBoostParticle2;
        BB_INSERT_PADDING(0x20);
    };

    BB_ASSERT_OFFSETOF(CSonicContext, m_spForwardPathController, 0x1494);
    BB_ASSERT_OFFSETOF(CSonicContext, m_spBoostParticle, 0x1494);
    BB_ASSERT_OFFSETOF(CSonicContext, m_spBoostParticle2, 0x149C);
    BB_ASSERT_SIZEOF(CSonicContext, 0x14D0);
}

#include <Sonic/Player/Character/Sonic/SonicContext.inl>