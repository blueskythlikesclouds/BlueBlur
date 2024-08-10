#pragma once

#include <Hedgehog/MotionCore/Motion/hhMotionBase.h>

namespace Hedgehog::Motion
{
    class CMorphMotion : public CMotionBase
    {
    public:
        BB_INSERT_PADDING(0x10);
    };

    BB_ASSERT_SIZEOF(CMorphMotion, 0x28);
}