#pragma once

#include <BlueBlur.inl>

namespace Hedgehog::Mirage
{
    class CCamera;
    class CRenderingDevice;
    class CRenderingInfrastructure;

    class CRenderInfo
    {
    public:
        CRenderingDevice* m_pRenderingDevice;
        CRenderingInfrastructure* m_pRenderingInfrastructure;
        CCamera* m_pCamera;
    };

    BB_ASSERT_OFFSETOF(CRenderInfo, m_pRenderingDevice, 0x00);
    BB_ASSERT_OFFSETOF(CRenderInfo, m_pRenderingInfrastructure, 0x04);
    BB_ASSERT_OFFSETOF(CRenderInfo, m_pCamera, 0x08);
}