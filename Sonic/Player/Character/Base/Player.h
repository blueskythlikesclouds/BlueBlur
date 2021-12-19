#pragma once

#include <BlueBlur.inl>

#include <Sonic/Animation/AnimationContext.h>
#include <Sonic/System/GameObject.h>

namespace Sonic::Player
{
    class CPlayer : public CGameObject, public IAnimationContext
    {
    public:
        BB_INSERT_PADDING(0x1E4);
    };

    BB_ASSERT_SIZEOF(CPlayer, 0x290);
}