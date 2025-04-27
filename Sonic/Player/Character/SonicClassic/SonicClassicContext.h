#pragma once

#include <Sonic/Player/Character/Speed/PlayerSpeedContext.h>

namespace Sonic::Player
{
    class CSonicClassicContext : public CPlayerSpeedContext
    {
    public:
        static constexpr CSonicClassicContext** ms_pInstance = (CSonicClassicContext**)0x1E5E304;

        static CSonicClassicContext* GetInstance();

        BB_INSERT_PADDING(0x200);
    };

    BB_ASSERT_SIZEOF(CSonicClassicContext, 0x1430);
}

#include <Sonic/Player/Character/SonicClassic/SonicClassicContext.inl>