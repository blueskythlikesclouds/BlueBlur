#pragma once

#include <BlueBlur.inl>
#include <Hedgehog/Yggdrasill/hhYggTexture.h>

namespace Hedgehog::Mirage
{
    class CPictureData;
}

namespace Hedgehog::Yggdrasill
{
    class CYggPicture : public CYggTexture
    {
    public:
        boost::shared_ptr<Mirage::CPictureData> m_spPictureData;
        BB_INSERT_PADDING(0x8);
    };

    BB_ASSERT_OFFSETOF(CYggPicture, m_spPictureData, 0xC0);
    BB_ASSERT_SIZEOF(CYggPicture, 0xD0);
}
