#pragma once

#include <Hedgehog/Yggdrasill/hhYggAbstractBuffer.h>

namespace Hedgehog::Yggdrasill
{
    struct SYggTextureCreationParams
    {
        BB_INSERT_PADDING(0x4);
        uint32_t Format;
        uint32_t Usage;
        uint32_t Width;
        uint32_t Height;
        BB_INSERT_PADDING(0x4);
        uint32_t Levels;
        uint32_t Pool;
        BB_INSERT_PADDING(0x8);
    };

    class CYggSurface;
    class CYggTexture;

    static inline BB_FUNCTION_PTR(void, __thiscall, fpCYggTextureGetSurface, 0x78AE30,
        const CYggTexture* This, boost::shared_ptr<CYggSurface>& spSurface, uint32_t mipIndex, uint32_t levelIndex);

    class CYggTexture : public CYggAbstractBuffer
    {
    public:
        DX_PATCH::IDirect3DBaseTexture9* m_pD3DTexture;
        BB_INSERT_PADDING(0x10);
        SYggTextureCreationParams m_CreationParams;
        BB_INSERT_PADDING(0x68);

        boost::shared_ptr<CYggSurface> GetSurface(uint32_t mipIndex = 0, uint32_t levelIndex = 0) const
        {
            boost::shared_ptr<CYggSurface> spSurface;
            fpCYggTextureGetSurface(this, spSurface, mipIndex, levelIndex);
            return spSurface;
        }
    };

    BB_ASSERT_OFFSETOF(CYggTexture, m_pD3DTexture, 0x1C);
    BB_ASSERT_OFFSETOF(CYggTexture, m_CreationParams, 0x30);
    BB_ASSERT_SIZEOF(CYggTexture, 0xC0);
}
