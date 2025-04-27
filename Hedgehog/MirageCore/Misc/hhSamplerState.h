#pragma once

#include <BlueBlur.inl>

namespace Hedgehog::Mirage
{
    struct SSamplerState
    {
        D3DTEXTUREADDRESS AddressU;
        D3DTEXTUREADDRESS AddressV;
        D3DTEXTUREFILTERTYPE MagFilter;
        D3DTEXTUREFILTERTYPE MinFilter;
        D3DTEXTUREFILTERTYPE MipFilter;
    };

    BB_ASSERT_OFFSETOF(SSamplerState, AddressU, 0x0);
    BB_ASSERT_OFFSETOF(SSamplerState, AddressV, 0x4);
    BB_ASSERT_OFFSETOF(SSamplerState, MagFilter, 0x8);
    BB_ASSERT_OFFSETOF(SSamplerState, MinFilter, 0xC);
    BB_ASSERT_OFFSETOF(SSamplerState, MipFilter, 0x10);
    BB_ASSERT_SIZEOF(SSamplerState, 0x14);
}