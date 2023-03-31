#pragma once

#include <Sonic/Animation/AnimationState.h>

namespace Sonic
{
    class CAnimationStateSingle : public CAnimationState
    {
    public:
        BB_INSERT_PADDING(0x4);
    };

    BB_ASSERT_SIZEOF(CAnimationStateSingle, 0x1A0);
}