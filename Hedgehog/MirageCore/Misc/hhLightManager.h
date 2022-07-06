#pragma once

#include <Hedgehog/Base/hhObject.h>

namespace Hedgehog::Mirage
{
    class CLightData;
    class CLightManager;
    class CStaticLightContext;

    static inline BB_FUNCTION_PTR(void, __thiscall, fpCLightManagerAddPointLight, 0x71EF20, 
        CLightManager* This, boost::shared_ptr<CLightData> in_spLightData);

    class CLightManager : public Base::CObject
    {
    public:
        virtual ~CLightManager() = default;

        BB_INSERT_PADDING(0xB0);
        Math::CVector m_GlobalLightDiffuse;
        Math::CVector m_GlobalLightSpecular;
        Math::CVector m_GlobalLightDirection;
        BB_INSERT_PADDING(0x54);
        CStaticLightContext* m_pStaticLightContext;
        BB_INSERT_PADDING(0x28);

        void AddPointLight(const boost::shared_ptr<CLightData>& in_spLightData)
        {
            fpCLightManagerAddPointLight(this, in_spLightData);
        }
    };

    BB_ASSERT_OFFSETOF(CLightManager, m_GlobalLightDiffuse, 0xC0);
    BB_ASSERT_OFFSETOF(CLightManager, m_GlobalLightSpecular, 0xD0);
    BB_ASSERT_OFFSETOF(CLightManager, m_GlobalLightDirection, 0xE0);
    BB_ASSERT_OFFSETOF(CLightManager, m_pStaticLightContext, 0x144);
    BB_ASSERT_SIZEOF(CLightManager, 0x170);
}