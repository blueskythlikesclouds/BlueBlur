#pragma once

#include <Hedgehog/Universe/Engine/hhStateMachineBase.h>

namespace Hedgehog::Universe
{
    template<typename TContext>
    class TStateMachine : public CStateMachineBase
    {
    public:
        class TState : public CStateBase
        {
        public:
            TState(const bb_null_ctor& nil) : CStateBase(nil) {}
            TState() {}

            TContext* GetContext() const;

            TStateMachine<TContext>* GetStateMachine() const;
        };

        TStateMachine() {}
        TStateMachine(const bb_null_ctor& nil) : CStateMachineBase(nil) {}

        boost::shared_ptr<TState> GetCurrentState() const;

        TContext* GetContext() const;
        virtual void SetContext(TContext* in_pContext);
    };
}

#include <Hedgehog/Universe/Engine/hhStateMachine.inl>