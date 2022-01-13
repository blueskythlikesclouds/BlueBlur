#pragma once

#include <Hedgehog/Yggdrasill/hhYggScheduler.h>

namespace Sonic
{
    class CFxScheduler : public Hedgehog::Yggdrasill::CYggScheduler
    {
    public:
        BB_INSERT_PADDING(0x88);
        float m_DeltaTime;
    };

    BB_ASSERT_OFFSETOF(CFxScheduler, m_DeltaTime, 0x94);
    BB_ASSERT_SIZEOF(CFxScheduler, 0x98);
}