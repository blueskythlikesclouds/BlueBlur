#pragma once

#include <Hedgehog/Base/hhObject.h>
#include <Hedgehog/Base/hhRefCountObject.h>
#include <Hedgehog/Base/Container/hhVector.h>

namespace Hedgehog::Mirage
{
    class CLightData;
}

namespace Sonic
{
    // When constructing a local light, always assign it to a Hedgehog::Base::CRefPtr first.
    //
    // Example:
    //  Hedgehog::Base::CRefPtr<Sonic::CLightData> rcLight = new Sonic::CLightData();
    //
    // Local light automatically gets removed from the light manager when all external references
    // are released. This means you need to store the reference to keep the local light alive.

    class CLocalLight : public Hedgehog::Base::CObject
    {
    public:
        boost::shared_ptr<Hedgehog::Mirage::CLightData> m_spLight;
        size_t m_RefCount;
        bool m_Dirty;

        CLocalLight();

        size_t AddRef();
        size_t Release();

        void SetPosition(const Hedgehog::Math::CVector& in_rPosition);
        void SetRange(const Hedgehog::Math::CVector4& in_rRange);
    };

    BB_ASSERT_OFFSETOF(CLocalLight, m_spLight, 0x0);
    BB_ASSERT_OFFSETOF(CLocalLight, m_RefCount, 0x8);
    BB_ASSERT_OFFSETOF(CLocalLight, m_Dirty, 0xC);
    BB_ASSERT_SIZEOF(CLocalLight, 0x10);

    class CLocalLightContext : public Hedgehog::Base::CObject
    {
    public:
        BB_INSERT_PADDING(0x8);
        hh::vector<Hedgehog::Base::CRefPtr<CLocalLight>> m_LocalLights;
    };

    BB_ASSERT_OFFSETOF(CLocalLightContext, m_LocalLights, 0x8);
    BB_ASSERT_SIZEOF(CLocalLightContext, 0x18);
}

#include <Sonic/System/LightManager/LocalLight.inl>