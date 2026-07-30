#pragma once

#include <Sonic/Animation/AnimationContext.h>
#include <Sonic/System/GameObject3D.h>

namespace Sonic::Player
{
    class CPlayerRenderable : public CGameObject3D, public IAnimationContext
    {
    public:
        uint32_t m_PlayerActorID;
        BB_INSERT_PADDING(0x60);
    };

    BB_ASSERT_OFFSETOF(CPlayerRenderable, m_PlayerActorID, 0xF8);
    BB_ASSERT_SIZEOF(CPlayerRenderable, 0x15C);
}
