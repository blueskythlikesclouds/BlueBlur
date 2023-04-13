#pragma once

#include <BlueBlur.inl>

#include "hhArchiveParam.h"

namespace Hedgehog::Database
{
    struct SArchiveParam;

    static inline BB_FUNCTION_PTR(void, __thiscall, fpSArchiveParamCtor, 0x446F90, SArchiveParam* This, int in_Priority, size_t in_Flags);
    static inline BB_FUNCTION_PTR(void, __thiscall, fpSArchiveParamDtor, 0x446E30, SArchiveParam* This);

    struct SArchiveParam
    {
        BB_INSERT_PADDING(0xD4);

        SArchiveParam(int in_Priority, size_t in_Flags)
        {
            fpSArchiveParamCtor(this, in_Priority, in_Flags);
        }

        ~SArchiveParam()
        {
            fpSArchiveParamDtor(this);
        }
    };
}
