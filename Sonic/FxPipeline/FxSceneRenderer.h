#pragma once

#include <BlueBlur.inl>
#include <Hedgehog/Yggdrasill/hhYggSceneRenderer.h>

namespace Sonic
{
    class CFxSceneRenderer : public Hedgehog::Yggdrasill::CYggSceneRenderer
    {
    public:
        BB_INSERT_PADDING(0xC);
        uint8_t m_BackgroundColor[4];
        BB_INSERT_PADDING(0x40);
        Hedgehog::Math::CMatrix m_LightView;
        Hedgehog::Math::CMatrix m_VerticalLightView;
        Hedgehog::Math::CMatrix44 m_LightProjection;
        Hedgehog::Math::CMatrix44 m_VerticalLightProjection;
        BB_INSERT_PADDING(0x10);
    };

    BB_ASSERT_OFFSETOF(CFxSceneRenderer, m_BackgroundColor, 0xBC);
    BB_ASSERT_OFFSETOF(CFxSceneRenderer, m_LightView, 0x100);
    BB_ASSERT_OFFSETOF(CFxSceneRenderer, m_VerticalLightView, 0x140);
    BB_ASSERT_OFFSETOF(CFxSceneRenderer, m_LightProjection, 0x180);
    BB_ASSERT_OFFSETOF(CFxSceneRenderer, m_VerticalLightProjection, 0x1C0);
    BB_ASSERT_SIZEOF(CFxSceneRenderer, 0x210);
}