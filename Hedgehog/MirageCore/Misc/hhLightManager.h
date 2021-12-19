#pragma once

#include <Hedgehog/Base/hhObject.h>

namespace Hedgehog::Mirage
{
    class CStaticLightContext;

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
    };

    BB_ASSERT_OFFSETOF(CLightManager, m_GlobalLightDiffuse, 0xC0);
    BB_ASSERT_OFFSETOF(CLightManager, m_GlobalLightSpecular, 0xD0);
    BB_ASSERT_OFFSETOF(CLightManager, m_GlobalLightDirection, 0xE0);
    BB_ASSERT_OFFSETOF(CLightManager, m_pStaticLightContext, 0x144);
    BB_ASSERT_SIZEOF(CLightManager, 0x170);
}