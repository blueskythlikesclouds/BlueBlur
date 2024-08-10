#pragma once

#include <Sonic/FxPipeline/Jobs/FxJob.h>

namespace Sonic
{
    class CFxColorCorrection;

    inline BB_FUNCTION_PTR(void, __thiscall, fpCFxColorCorrectionInitialize, 0x10C2CD0, CFxColorCorrection* This);
    inline BB_FUNCTION_PTR(void, __thiscall, fpCFxColorCorrectionExecute, 0x10C2E90, CFxColorCorrection* This);

    class CFxColorCorrection : public CFxJob
    {
    public:
        BB_INSERT_PADDING(0x7C);
    };

    BB_ASSERT_SIZEOF(CFxColorCorrection, 0xC4);
}