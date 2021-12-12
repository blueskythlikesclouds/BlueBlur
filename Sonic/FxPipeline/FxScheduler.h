#pragma once

#include <BlueBlur.inl>
#include <Hedgehog/Yggdrasill/hhYggScheduler.h>

namespace Sonic
{
    class CFxScheduler : public Hedgehog::Yggdrasill::CYggScheduler
    {
    public:
        BB_INSERT_PADDING(0x88);
        float m_ElapsedTime;
    };

    BB_ASSERT_OFFSETOF(CFxScheduler, m_ElapsedTime, 0x94);
    BB_ASSERT_SIZEOF(CFxScheduler, 0x98);
}