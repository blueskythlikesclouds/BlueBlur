#pragma once

#include <Sonic/System/Application.h>

namespace Sonic
{
    class CApplicationD3D9 : public CApplication
    {
    public:
        BB_INSERT_PADDING(0x34);
        HWND m_WindowHandle;
        DX_PATCH::IDirect3DDevice9* m_pD3DDevice;
        BB_INSERT_PADDING(0x80);
    };

    BB_ASSERT_OFFSETOF(CApplicationD3D9, m_WindowHandle, 0x48);
    BB_ASSERT_OFFSETOF(CApplicationD3D9, m_pD3DDevice, 0x4C);
    BB_ASSERT_SIZEOF(CApplicationD3D9, 0xD0);
}
