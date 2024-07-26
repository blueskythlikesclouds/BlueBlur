#pragma once

#include <Hedgehog/Universe/Engine/hhService.h>

namespace Sonic
{
    class CServiceGamePlay : public Hedgehog::Universe::CService
    {
    public:
        HH_FND_MSG_MAKE_SERVICE(0x15B812C, 0);

        uint32_t m_PlayerID;
    };

    BB_ASSERT_OFFSETOF(CServiceGamePlay, m_PlayerID, 0x4);
    BB_ASSERT_SIZEOF(CServiceGamePlay, 0x8);
}