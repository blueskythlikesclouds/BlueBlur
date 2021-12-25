#pragma once

#include <Sonic/Player/Character/SonicSp/SonicSpContext.h>
#include <Sonic/Player/Character/Speed/PlayerSpeed.h>

namespace Sonic::Player
{
    class CSonicSp : public CPlayerSpeed
    {
    public:
        BB_INSERT_PADDING(0x70);

        CSonicSpContext* GetContext() const
        {
            return static_cast<CSonicSpContext*>(m_spContext.get());
        }
    };

    BB_ASSERT_SIZEOF(CSonicSp, 0x340);
}