#pragma once

#include <Sonic/Animation/AnimationContext.h>
#include <Sonic/System/GameObject3D.h>

namespace Sonic::Player
{
    class CPlayerRenderable : public CGameObject3D, public IAnimationContext
    {
    public:
        size_t m_ActorID;
        BB_INSERT_PADDING(0x60);
    };

    BB_ASSERT_OFFSETOF(CPlayerRenderable, m_ActorID, 0xF8);
    BB_ASSERT_SIZEOF(CPlayerRenderable, 0x15C);
}
