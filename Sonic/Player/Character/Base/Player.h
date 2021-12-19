#pragma once

#include <Sonic/Animation/AnimationContext.h>
#include <Sonic/System/GameObject.h>

namespace Sonic::Player
{
    class CPlayerContext;
    
    class CPlayer : public CGameObject, public IAnimationContext
    {
    public:
        boost::shared_ptr<CPlayerContext> m_spContext;
        BB_INSERT_PADDING(0x1DC);
    };

    BB_ASSERT_OFFSETOF(CPlayer, m_spContext, 0xAC);
    BB_ASSERT_SIZEOF(CPlayer, 0x290);
}