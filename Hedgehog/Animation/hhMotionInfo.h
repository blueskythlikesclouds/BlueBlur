#pragma once

#include <BlueBlur.inl>

namespace Hedgehog::Animation
{
    enum EMotionRepeatType
    {
        eMotionRepeatType_Loop = 0,
        eMotionRepeatType_PlayOnce = 1
    };

    struct SMotionInfo
    {
        const char* Name;
        const char* FileName;
        float Speed = 1.0f;
        int32_t RepeatType = eMotionRepeatType_Loop;
        float StartFrame = 0.0f;
        float EndFrame = -1.0f;
        float Field18 = -1.0f;
        int32_t Field1C = 0;

        // These fields are set by the game. Don't touch.
        int32_t Field20 = -1;
        int32_t Field24 = -1;
        int32_t Field28 = -1;
        int32_t Field2C = -1;
    };

    BB_ASSERT_OFFSETOF(SMotionInfo, Name, 0x00);
    BB_ASSERT_OFFSETOF(SMotionInfo, FileName, 0x04);
    BB_ASSERT_OFFSETOF(SMotionInfo, Speed, 0x08);
    BB_ASSERT_OFFSETOF(SMotionInfo, RepeatType, 0x0C);
    BB_ASSERT_OFFSETOF(SMotionInfo, StartFrame, 0x10);
    BB_ASSERT_OFFSETOF(SMotionInfo, EndFrame, 0x14);
    BB_ASSERT_OFFSETOF(SMotionInfo, Field18, 0x18);
    BB_ASSERT_OFFSETOF(SMotionInfo, Field1C, 0x1C);
    BB_ASSERT_OFFSETOF(SMotionInfo, Field20, 0x20);
    BB_ASSERT_OFFSETOF(SMotionInfo, Field24, 0x24);
    BB_ASSERT_OFFSETOF(SMotionInfo, Field28, 0x28);
    BB_ASSERT_OFFSETOF(SMotionInfo, Field2C, 0x2C);
    BB_ASSERT_SIZEOF(SMotionInfo, 0x30);
}