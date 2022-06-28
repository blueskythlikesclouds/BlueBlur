﻿#pragma once

#include <BlueBlur.inl>

namespace Sonic
{
    enum EKeyState : uint32_t
    {
        eKeyState_None         = 0x0,

        eKeyState_A            = 0x1,
        eKeyState_B            = 0x2,
        eKeyState_X            = 0x8,
        eKeyState_Y            = 0x10,

        eKeyState_DpadUp       = 0x40,
        eKeyState_DpadDown     = 0x80,
        eKeyState_DpadLeft     = 0x100,
        eKeyState_DpadRight    = 0x200,

        eKeyState_Start        = 0x400,
        eKeyState_Select       = 0x800,

        eKeyState_LeftBumper   = 0x1000,
        eKeyState_RightBumper  = 0x2000,

        eKeyState_LeftTrigger  = 0x4000,
        eKeyState_RightTrigger = 0x8000,

        eKeyState_LeftStick    = 0x10000,
        eKeyState_RightStick   = 0x20000,

        eKeyState_LeftStickUp       = 0x40000,
        eKeyState_LeftStickDown     = 0x80000,
        eKeyState_LeftStickLeft     = 0x100000,
        eKeyState_LeftStickRight    = 0x200000,

        eKeyState_RightStickUp      = 0x400000,
        eKeyState_RightStickDown    = 0x800000,
        eKeyState_RightStickLeft    = 0x1000000,
        eKeyState_RightStickRight   = 0x2000000
    };

    struct SPadState
    {
        EKeyState DownState;
        EKeyState UpState;
        EKeyState TappedState;
        EKeyState ReleasedState;

        BB_INSERT_PADDING(0x4);

        float LeftStickHorizontal;
        float LeftStickVertical;

        BB_INSERT_PADDING(0x4);

        float RightStickHorizontal;
        float RightStickVertical;

        BB_INSERT_PADDING(0x2C);

        bool IsDown(const EKeyState keys) const
        {
            return (DownState & keys) == keys;
        }

        bool IsUp(const EKeyState keys) const
        {
            return (UpState & keys) == keys;
        }

        bool IsTapped(const EKeyState keys) const
        {
            return (TappedState & keys) == keys;
        }

        bool IsReleased(const EKeyState keys) const
        {
            return (ReleasedState & keys) == keys;
        }
    };

    BB_ASSERT_SIZEOF(SPadState, 0x54);
}