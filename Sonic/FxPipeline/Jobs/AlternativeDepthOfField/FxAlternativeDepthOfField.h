#pragma once

#include <BlueBlur.inl>
#include <Sonic/FxPipeline/Jobs/FxJob.h>

namespace Sonic
{
    class CFxAlternativeDepthOfField;

    static inline BB_FUNCTION_PTR(void, __thiscall, fpCFxAlternativeDepthOfFieldInitialize, 0x1228620, CFxAlternativeDepthOfField* This);
    static inline BB_FUNCTION_PTR(void, __thiscall, fpCFxAlternativeDepthOfFieldExecute, 0x1228960, CFxAlternativeDepthOfField* This);

    class CFxAlternativeDepthOfField : public CFxJob
    {
    public:
        BB_INSERT_PADDING(0x70);
    };

    BB_ASSERT_SIZEOF(CFxAlternativeDepthOfField, 0xB8);
}