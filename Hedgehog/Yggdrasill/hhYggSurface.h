#pragma once

#include <Hedgehog/Yggdrasill/hhYggAbstractBuffer.h>

namespace Hedgehog::Yggdrasill
{
    class CYggSurface : public CYggAbstractBuffer
    {
    public:
        DX_PATCH::IDirect3DSurface9* m_pD3DSurface;
        BB_INSERT_PADDING(0x48);
    };

    BB_ASSERT_OFFSETOF(CYggSurface, m_pD3DSurface, 0x1C);
    BB_ASSERT_SIZEOF(CYggSurface, 0x68);
}
