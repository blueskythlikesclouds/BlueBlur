#pragma once

#include <Hedgehog/Universe/Engine/hhMessage.h>

namespace Sonic::Message
{
    class MsgGetHomingAttackPosition : public Hedgehog::Universe::MessageTypeGet
    {
    public:
        HH_FND_MSG_MAKE_TYPE(0x167FAC4);

        Hedgehog::Math::CVector* m_pPosition;

        MsgGetHomingAttackPosition(Hedgehog::Math::CVector* in_pPosition) : m_pPosition(in_pPosition) {}
        MsgGetHomingAttackPosition(Hedgehog::Math::CVector& in_rPosition) : m_pPosition(&in_rPosition) {}
    };

    BB_ASSERT_OFFSETOF(MsgGetHomingAttackPosition, m_pPosition, 0x10);
    BB_ASSERT_SIZEOF(MsgGetHomingAttackPosition, 0x14);
}