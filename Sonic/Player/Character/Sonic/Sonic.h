#pragma once

#include <Sonic/Player/Character/Sonic/SonicContext.h>
#include <Sonic/Player/Character/Speed/PlayerSpeed.h>

namespace Sonic::Player
{
    class CSonic : public CPlayerSpeed
    {
    public:
        BB_INSERT_PADDING(0x130);

        CSonicContext* GetContext() const
        {
            return static_cast<CSonicContext*>(m_spContext.get());
        }
    };

    BB_ASSERT_SIZEOF(CSonic, 0x400);
}