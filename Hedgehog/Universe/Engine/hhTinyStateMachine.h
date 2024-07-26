#pragma once

#include <Hedgehog/Universe/Engine/hhTinyStateMachineBase.h>

namespace Hedgehog::Universe
{
    template<typename TContext>
    class TTinyStateMachine : public CTinyStateMachineBase
    {
    public:
        class TState : public CStateBase
        {
        public:
            TState(const bb_null_ctor& nil) : CStateBase(nil) {}
            TState() {};

            TContext* GetContext() const;

            TTinyStateMachine<TContext>* GetTinyStateMachine() const;
        };

        TTinyStateMachine() : CTinyStateMachineBase() {}
        TTinyStateMachine(const bb_null_ctor& nil) : CTinyStateMachineBase(nil) {}
        boost::shared_ptr<TState> GetCurrentState();

        TContext* GetContext() const;

        virtual void SetContext(TContext* in_pContext);
    };
}

#include <Hedgehog/Universe/Engine/hhTinyStateMachine.inl>