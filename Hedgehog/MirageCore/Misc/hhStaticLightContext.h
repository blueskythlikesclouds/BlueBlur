#pragma once

#include <BlueBlur.inl>
#include <Hedgehog/Base/hhRefCountObject.h>

namespace Hedgehog::Mirage
{
    class CLightListData;

    class CStaticLightContext : public Base::CRefCountObject
    {
    public:
        BB_INSERT_PADDING(0x20);
        boost::shared_ptr<CLightListData> m_spLightListData;
        BB_INSERT_PADDING(0x4);
        uint32_t m_LightCount;
        BB_INSERT_PADDING(0x8);
    };

    BB_ASSERT_OFFSETOF(CStaticLightContext, m_spLightListData, 0x28);
    BB_ASSERT_OFFSETOF(CStaticLightContext, m_LightCount, 0x34);
    BB_ASSERT_SIZEOF(CStaticLightContext, 0x40);
}
