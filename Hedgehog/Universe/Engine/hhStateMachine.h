#pragma once

#include <Hedgehog/Universe/Engine/hhStateMachineBase.h>

namespace Hedgehog::Universe
{
    template<typename T>
    class TStateMachine : public CStateMachineBase
    {
    public:
        class TState : public CStateBase
        {
        public:
            T* GetOwner() const
            {
                return static_cast<T*>(m_pOwner);
            }

            TStateMachine<T>* GetStateMachine() const
            {
                return static_cast<TStateMachine<T*>>(m_pStateMachine);
            }
        };

        boost::shared_ptr<TState> GetCurrentState()
        {
            boost::shared_ptr<CStateBase> spState;
            fpGetCurrentState(this, spState);

            return boost::static_pointer_cast<TState>(spState);
        }

        T* GetOwner() const
        {
            return static_cast<T*>(m_pOwner);
        }

        virtual void SetOwner(T* pOwner)
        {
            m_pOwner = static_cast<void*>(pOwner);
        }
    };
}