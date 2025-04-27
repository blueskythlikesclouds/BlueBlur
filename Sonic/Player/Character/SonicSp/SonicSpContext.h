#pragma once

#include <Sonic/Player/Character/Speed/PlayerSpeedContext.h>

namespace Sonic::Player
{
    class CSonicSpContext : public CPlayerSpeedContext
    {
    public:
        static constexpr CSonicSpContext** ms_pInstance = (CSonicSpContext**)0x1E5E310;

        static CSonicSpContext* GetInstance();

        BB_INSERT_PADDING(0xE0);
    };

    BB_ASSERT_SIZEOF(CSonicSpContext, 0x1310);
}

#include <Sonic/Player/Character/SonicSp/SonicSpContext.inl>