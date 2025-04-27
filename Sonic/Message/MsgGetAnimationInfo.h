#pragma once

#include <Hedgehog/Base/Type/hhSharedString.h>
#include <Hedgehog/Universe/Engine/hhMessage.h>

namespace Sonic::Message
{
    class MsgGetAnimationInfo : public Hedgehog::Universe::MessageTypeGet
    {
    public:
        HH_FND_MSG_MAKE_TYPE(0x16807FC);

        BB_INSERT_PADDING(0x4);
        Hedgehog::Base::CSharedString m_Name;
        float m_Frame;
    };

    BB_ASSERT_OFFSETOF(MsgGetAnimationInfo, m_Name, 0x14);
    BB_ASSERT_OFFSETOF(MsgGetAnimationInfo, m_Frame, 0x18);
    BB_ASSERT_SIZEOF(MsgGetAnimationInfo, 0x1C);
}