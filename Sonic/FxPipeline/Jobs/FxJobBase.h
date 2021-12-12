#pragma once

#include <BlueBlur.inl>
#include <Hedgehog/Yggdrasill/hhYggJob.h>

namespace Sonic
{
    class CFxJobBase : public Hedgehog::Yggdrasill::CYggJob
    {
    public:
        BB_INSERT_PADDING(0x8);
    };

    BB_ASSERT_SIZEOF(CFxJobBase, 0x48);
}