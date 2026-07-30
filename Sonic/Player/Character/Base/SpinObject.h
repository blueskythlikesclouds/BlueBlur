#pragma once

#include <Sonic/System/GameObject3D.h>

namespace Sonic::Player
{
    class CSpinObject : public CGameObject3D {};

    BB_ASSERT_SIZEOF(CSpinObject, 0xF4);
}
