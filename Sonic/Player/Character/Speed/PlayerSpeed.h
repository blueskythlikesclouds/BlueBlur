#pragma once

#include <Sonic/Player/Character/Base/Player.h>

namespace Sonic::Player
{
    class CPlayerSpeed : public CPlayer
    {
    public:
        BB_INSERT_PADDING(0x40);
    };

    BB_ASSERT_SIZEOF(CPlayerSpeed, 0x2D0);
}