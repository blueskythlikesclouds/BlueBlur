#pragma once

#include <Hedgehog/Universe/Engine/hhMessage.h>

namespace Sonic::Message
{
    class MsgStartHomingChase : public Hedgehog::Universe::MessageTypeSet
    {
    public:
        HH_FND_MSG_MAKE_TYPE(0x1680130);
    };

    BB_ASSERT_SIZEOF(MsgStartHomingChase, 0x10);
}