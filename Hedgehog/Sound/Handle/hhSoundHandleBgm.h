#pragma once

#include <Hedgehog/Sound/Handle/hhSoundHandleCri.h>

namespace Hedgehog::Sound
{
    class CSoundHandleBgm : public CSoundHandleCri
    {
    public:
        uint32_t m_Field80;
        uint32_t m_Field84;
        uint32_t m_Field88;
        uint32_t m_Field8C;
    };

    BB_ASSERT_SIZEOF(CSoundHandleBgm, 0x90);
}