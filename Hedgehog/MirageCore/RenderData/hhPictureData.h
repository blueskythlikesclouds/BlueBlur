#pragma once

#include <BlueBlur.inl>
#include <Hedgehog/Database/System/hhDatabaseData.h>

namespace Hedgehog::Mirage
{
    enum EPictureType : uint32_t
    {
        ePictureType_Invalid = (uint32_t)-1,
        ePictureType_Texture = 0,
        ePictureType_CubeTexture = 1,
        ePictureType_VolumeTexture = 2
    };

    class CPictureData : public Database::CDatabaseData
    {
    public:
        DX_PATCH::IDirect3DBaseTexture9* m_pD3DTexture;
        EPictureType m_Type;
        BB_INSERT_PADDING(0x8);
    };

    BB_ASSERT_OFFSETOF(CPictureData, m_pD3DTexture, 0xC);
    BB_ASSERT_OFFSETOF(CPictureData, m_Type, 0x10);
    BB_ASSERT_SIZEOF(CPictureData, 0x1C);
}