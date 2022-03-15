#pragma once 

#include <BlueBlur.inl>

namespace Hedgehog::Universe
{
    class Message;

    class IStateMachineMessageReceiver
    {
    public:
        IStateMachineMessageReceiver(const bb_null_ctor&) {}

        virtual bool ProcessMessageInStateMachine(Message& message, bool flag) = 0;
    };

    BB_ASSERT_SIZEOF(IStateMachineMessageReceiver, 4);
}