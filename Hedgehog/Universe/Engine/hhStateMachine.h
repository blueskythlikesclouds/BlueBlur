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
            TState(const bb_null_ctor&) : CStateBase(bb_null_ctor{}) {}
            TState() : CStateBase() {}

            TContext* GetContext() const
            {
                return static_cast<TContext*>(m_pContext);
            }

            TStateMachine<TContext>* GetStateMachine() const
            {
                return static_cast<TStateMachine<TContext*>>(m_pStateMachine);
            }
        };

        TStateMachine() : CStateMachineBase() {}
        TStateMachine(const bb_null_ctor& nil) : CStateMachineBase(nil) {}

        TContext* GetContext() const
        {
            return static_cast<TContext*>(m_pContext);
        }

        virtual void SetContext(TContext* pContext)
        {
            m_pContext = static_cast<void*>(pContext);
        }
    };
}