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

        boost::shared_ptr<TState> GetCurrentState() const
        {
            boost::shared_ptr<CStateBase> spState;
            fpGetCurrentState(this, spState);

            return boost::static_pointer_cast<TState>(spState);
        }

        TContext* GetContext() const
        {
            return static_cast<TContext*>(m_pContext);
        }

        virtual void SetContext(TContext* in_pContext)
        {
            m_pContext = static_cast<void*>(in_pContext);
        }
    };
}