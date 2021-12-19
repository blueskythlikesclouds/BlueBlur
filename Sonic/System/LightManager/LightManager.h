#pragma once

#include <Hedgehog/MirageCore/Misc/hhLightManager.h>
#include <Sonic/System/GameObject.h>

namespace Sonic
{
    class CLocalLightContext;

    class CLightManager : public CGameObject, public Hedgehog::Mirage::CLightManager
    {
    public:
        CLocalLightContext* m_pLocalLightContext;
        BB_INSERT_PADDING(0xC);
    };

    BB_ASSERT_OFFSETOF(CLightManager, m_pLocalLightContext, 0x220);
    BB_ASSERT_SIZEOF(CLightManager, 0x230);
}