#pragma once

#include <Sonic/Player/Character/Base/Player.h>
#include <Sonic/Player/Character/Speed/PlayerSpeedContext.h>

namespace Sonic::Player
{
    class CSonicSkateBoard;
    class CPlayerSpeed : public CPlayer
    {
    public:
        boost::shared_ptr<CSonicSkateBoard> m_spSkateBoard;
        int m_Field298;
        hh::map<int, boost::anonymous_shared_ptr> m_Map1;
        float m_Field2AC;
        int m_Field2B0;
        int m_Field2B4;
        int m_Field2B8;
        int m_Field2BC;
        int m_Field2BC2;
        hh::map<int, boost::anonymous_shared_ptr> m_Map2C4;
        int m_Field2BC3;

        CPlayerSpeedContext* GetContext() const;
    };
    BB_ASSERT_OFFSETOF(CPlayerSpeed, m_Map2C4, 0x2C0);
    BB_ASSERT_SIZEOF(CPlayerSpeed, 0x2D0);
}

#include <Sonic/Player/Character/Speed/PlayerSpeed.inl>