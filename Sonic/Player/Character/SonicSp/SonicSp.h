#pragma once

#include <Sonic/Player/Character/Speed/PlayerSpeed.h>

namespace Sonic::Player
{
    class CSonicSp : public CPlayerSpeed
    {
    public:
        BB_INSERT_PADDING(0x70);
    };

    BB_ASSERT_SIZEOF(CSonicSp, 0x340);
}