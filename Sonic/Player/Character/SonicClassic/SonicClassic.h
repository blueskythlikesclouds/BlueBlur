#pragma once

#include <Sonic/Player/Character/SonicClassic/SonicClassicContext.h>
#include <Sonic/Player/Character/Speed/PlayerSpeed.h>

namespace Sonic::Player
{
    class CSonicClassic : public CPlayerSpeed
    {
    public:
        BB_INSERT_PADDING(0x140);

        CSonicClassicContext* GetContext() const;
    };

    BB_ASSERT_SIZEOF(CSonicClassic, 0x410);
}

#include <Sonic/Player/Character/SonicClassic/SonicClassic.inl>