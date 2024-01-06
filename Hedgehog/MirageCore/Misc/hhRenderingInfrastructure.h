#pragma once

#include <Hedgehog/Base/hhObject.h>
#include <Hedgehog/MirageCore/Misc/hhRenderingDevice.h>

namespace Hedgehog::Mirage
{
    class CRenderingInfrastructure : public Hedgehog::Base::CObject
    {
    public:
        virtual ~CRenderingInfrastructure() = default;

        BB_INSERT_PADDING(0x50);
        CRenderingDevice m_RenderingDevice;
    };

    BB_ASSERT_OFFSETOF(CRenderingInfrastructure, m_RenderingDevice, 0x60);
    BB_ASSERT_SIZEOF(CRenderingInfrastructure, 0x7650);
}