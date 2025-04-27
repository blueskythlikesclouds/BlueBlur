#pragma once

#include <Sonic/FxPipeline/Jobs/FxJob.h>

namespace Sonic
{
    class CFxCrossFade;

    inline BB_FUNCTION_PTR(void, __thiscall, fpCFxCrossFadeInitialize, 0x10C21A0, CFxCrossFade* This);
    inline BB_FUNCTION_PTR(void, __thiscall, fpCFxCrossFadeExecute, 0x10C22D0, CFxCrossFade* This);

    class CFxCrossFade : public CFxJob
    {
    public:
        BB_INSERT_PADDING(0x20);
    };

    BB_ASSERT_SIZEOF(CFxCrossFade, 0x68);
}