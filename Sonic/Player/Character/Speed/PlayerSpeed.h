#pragma once

#include <Sonic/Player/Character/Base/Player.h>
#include <Sonic/Player/Character/Speed/PlayerSpeedContext.h>

namespace Sonic::Player
{
    class CPlayerSpeed : public CPlayer
    {
    public:
        BB_INSERT_PADDING(0x40);

        CPlayerSpeedContext* GetContext() const;
    };

    BB_ASSERT_SIZEOF(CPlayerSpeed, 0x2D0);
}

#include <Sonic/Player/Character/Speed/PlayerSpeed.inl>