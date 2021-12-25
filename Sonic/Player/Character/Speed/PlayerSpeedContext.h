#pragma once

#include <Sonic/Player/Character/Base/PlayerContext.h>

namespace Sonic::Player
{
    class CPlayerSpeedContext : public CPlayerContext
    {
    public:
        static constexpr CPlayerSpeedContext** ms_pInstance = (CPlayerSpeedContext**)0x1E5E2F0;

        static CPlayerSpeedContext* GetInstance()
        {
            return *ms_pInstance;
        }

        class CStateSpeedBase;

        BB_INSERT_PADDING(0x230);
        Hedgehog::Math::CQuaternion m_VerticalRotation;
        BB_INSERT_PADDING(0x10);
        Hedgehog::Math::CQuaternion m_HorizontalRotation;
        BB_INSERT_PADDING(0xD40);
    };

    BB_ASSERT_OFFSETOF(CPlayerSpeedContext, m_VerticalRotation, 0x4C0);
    BB_ASSERT_OFFSETOF(CPlayerSpeedContext, m_HorizontalRotation, 0x4E0);
    BB_ASSERT_SIZEOF(CPlayerSpeedContext, 0x1230);
}