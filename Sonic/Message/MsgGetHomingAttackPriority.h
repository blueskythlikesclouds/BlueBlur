#pragma once

#include <Hedgehog/Universe/Engine/hhMessage.h>

namespace Sonic::Message
{
    class MsgGetHomingAttackPriority : public Hedgehog::Universe::MessageTypeGet
    {
    public:
        HH_FND_MSG_MAKE_TYPE(0x167FAA8);

        size_t* m_pPriority;

        MsgGetHomingAttackPriority(size_t* in_pPriority) : m_pPriority(in_pPriority) {}
        MsgGetHomingAttackPriority(size_t& in_rPriority) : m_pPriority(&in_rPriority) {}
    };

    BB_ASSERT_OFFSETOF(MsgGetHomingAttackPriority, m_pPriority, 0x10);
    BB_ASSERT_SIZEOF(MsgGetHomingAttackPriority, 0x14);
}