#pragma once

#include <Hedgehog/Base/hhObject.h>
#include <Hedgehog/Base/Container/hhVector.h>

namespace Hedgehog::Mirage
{
    class CLightData;
}

namespace Sonic
{
    class CLocalLight : public Hedgehog::Base::CObject
    {
    public:
        boost::shared_ptr<Hedgehog::Mirage::CLightData> m_spLightData;
        BB_INSERT_PADDING(0x8);
    };

    BB_ASSERT_OFFSETOF(CLocalLight, m_spLightData, 0x0);
    BB_ASSERT_SIZEOF(CLocalLight, 0x10);

    class CLocalLightContext : public Hedgehog::Base::CObject
    {
    public:
        BB_INSERT_PADDING(0x8);
        hh::vector<CLocalLight*> m_LocalLights; 
    };

    BB_ASSERT_OFFSETOF(CLocalLightContext, m_LocalLights, 0x8);
    BB_ASSERT_SIZEOF(CLocalLightContext, 0x18);
}