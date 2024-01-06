#pragma once

#include <Hedgehog/Sound/Handle/hhSoundHandle.h>

namespace Hedgehog::Sound
{
    class CSoundHandleCri : public CSoundHandle
    {
    public:
        uint32_t m_Field70;
        uint32_t m_Field74;
        uint32_t m_Field78;
        uint32_t m_Field7C;

        virtual void* GetSoundPlayer() { return nullptr; }
    };

    BB_ASSERT_SIZEOF(CSoundHandleCri, 0x80);
}
