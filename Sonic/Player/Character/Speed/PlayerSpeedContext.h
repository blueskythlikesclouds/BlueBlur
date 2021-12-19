#pragma once

#include <Sonic/Player/Character/Base/PlayerContext.h>

namespace Sonic::Player
{
    class CPlayerSpeedContext : public CPlayerContext
    {
    public:
        static constexpr CPlayerSpeedContext** ms_pInstance = (CPlayerSpeedContext**)0x1E5E2F0;

        static CPlayerSpeedContext* GetInstance()
        {
            return *ms_pInstance;
        }

        BB_INSERT_PADDING(0xFA0);
    };

    BB_ASSERT_SIZEOF(CPlayerSpeedContext, 0x1230);
}