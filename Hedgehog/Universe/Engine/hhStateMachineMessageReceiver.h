#pragma once 

#include <BlueBlur.inl>

namespace Hedgehog::Universe
{
    class Message;

    class IStateMachineMessageReceiver
    {
    public:
        IStateMachineMessageReceiver(const bb_null_ctor&) {}

        virtual bool ProcessMessageInStateMachine(Message& in_rMsg, bool in_Flag) = 0;
    };

    BB_ASSERT_SIZEOF(IStateMachineMessageReceiver, 4);
}