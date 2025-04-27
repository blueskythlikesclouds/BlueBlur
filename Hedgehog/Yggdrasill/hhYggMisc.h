#pragma once

#include <BlueBlur.inl>

namespace Hedgehog::Mirage
{
    class CRenderingInfrastructure;
}

namespace Hedgehog::Yggdrasill
{
    class CYggDevice;
    class CYggSceneRenderer;

    class CYggMisc
    {
    public:
        BB_INSERT_PADDING(0x8);
        Mirage::CRenderingInfrastructure* m_pRenderingInfrastructure;
        BB_INSERT_PADDING(0x4);
        CYggDevice* m_pDevice;
        boost::shared_ptr<CYggSceneRenderer> m_spSceneRenderer;
        BB_INSERT_PADDING(0x28);
    };

    BB_ASSERT_OFFSETOF(CYggMisc, m_pRenderingInfrastructure, 8);
    BB_ASSERT_OFFSETOF(CYggMisc, m_pDevice, 0x10);
    BB_ASSERT_OFFSETOF(CYggMisc, m_spSceneRenderer, 0x14);
    BB_ASSERT_SIZEOF(CYggMisc, 0x44);
}