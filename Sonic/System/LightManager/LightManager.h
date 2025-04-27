#pragma once

#include <Hedgehog/MirageCore/Misc/hhLightManager.h>
#include <Hedgehog/MirageCore/RenderData/hhLightData.h>
#include <Sonic/System/LightManager/LocalLight.h>
#include <Sonic/System/GameObject.h>

namespace Sonic
{
    class CLocalLightContext;

    class CLightManager : public CGameObject, public Hedgehog::Mirage::CLightManager
    {
    public:
        CLocalLightContext* m_pLocalLightContext;
        BB_INSERT_PADDING(0xC);

        Hedgehog::Base::CRefPtr<CLocalLight> AddLocalLight(const boost::shared_ptr<Hedgehog::Mirage::CLightData>& in_spLightData);

        Hedgehog::Base::CRefPtr<CLocalLight> AddLocalLight(
            const Hedgehog::Math::CVector& in_rPosition,
            const Hedgehog::Math::CVector4& in_rColor,
            const Hedgehog::Math::CVector4& in_rRange);
    };

    BB_ASSERT_OFFSETOF(CLightManager, m_pLocalLightContext, 0x220);
    BB_ASSERT_SIZEOF(CLightManager, 0x230);
}

#include <Sonic/System/LightManager/LightManager.inl>