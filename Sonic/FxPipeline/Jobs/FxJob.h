#pragma once

#include <BlueBlur.inl>
#include <Sonic/FxPipeline/Jobs/FxJobBase.h>

namespace Sonic
{
    class CFxJob : public CFxJobBase
    {
    };

    BB_ASSERT_SIZEOF(CFxJob, 0x48);
}