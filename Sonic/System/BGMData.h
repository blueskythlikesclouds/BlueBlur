#pragma once

#include <Hedgehog/Base/Type/hhSharedString.h>

namespace Hedgehog::Sound
{
    class CSoundHandleBgm;
}

namespace Sonic
{
    struct SBGMData
    {
        boost::shared_ptr<Hedgehog::Sound::CSoundHandleBgm> spSoundHandleBGM;
        Hedgehog::Base::CSharedString Name;
        BB_INSERT_PADDING(0x04);
        float Volume;
        float PlaybackSpeed;
    };

    BB_ASSERT_SIZEOF(SBGMData, 0x18);
}