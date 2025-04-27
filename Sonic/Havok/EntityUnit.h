#pragma once

#include <Sonic/Collision/PhysicsUnit.h>

namespace Sonic
{
    class CEntityUnit : public CPhysicsUnit
    {
    public:
        BB_INSERT_PADDING(0x8);
    };

    BB_ASSERT_SIZEOF(CEntityUnit, 0x50);
}