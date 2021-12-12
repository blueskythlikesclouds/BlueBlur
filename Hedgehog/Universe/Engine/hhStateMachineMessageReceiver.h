#pragma once 

#include <BlueBlur.inl>

namespace Hedgehog::Universe
{
    class Message;

    class IStateMachineMessageReceiver
    {
    public:
        virtual bool ReceiveMessage(const Message& message, bool flag) = 0;
    };

    BB_ASSERT_SIZEOF(IStateMachineMessageReceiver, 4);
}