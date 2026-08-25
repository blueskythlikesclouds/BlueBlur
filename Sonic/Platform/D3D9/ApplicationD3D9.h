#pragma once

#include <Sonic/System/Application.h>

namespace Sonic
{
    class CApplicationD3D9 : public CApplication
    {
    public:
        BB_INSERT_PADDING(0x2C);
        uint32_t m_WindowStyle;
        uint8_t m_Field44;
        HWND m_WindowHandle;
        DX_PATCH::IDirect3DDevice9* m_pD3DDevice;
        BB_INSERT_PADDING(0x40);
        bool m_IsWindowActive;
        BB_INSERT_PADDING(0x3C);
    };

    BB_ASSERT_OFFSETOF(CApplicationD3D9, m_WindowStyle, 0x40);
    BB_ASSERT_OFFSETOF(CApplicationD3D9, m_WindowHandle, 0x48);
    BB_ASSERT_OFFSETOF(CApplicationD3D9, m_pD3DDevice, 0x4C);
    BB_ASSERT_OFFSETOF(CApplicationD3D9, m_IsWindowActive, 0x90);
    BB_ASSERT_SIZEOF(CApplicationD3D9, 0xD0);
}
