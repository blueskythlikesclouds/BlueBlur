namespace Hedgehog::Universe
{
    template <typename TContext>
    TContext* TStateMachine<TContext>::TState::GetContext() const
    {
        return static_cast<TContext*>(m_pContext);
    }

    template <typename TContext>
    TStateMachine<TContext>* TStateMachine<TContext>::TState::GetStateMachine() const
    {
        return static_cast<TStateMachine<TContext*>>(m_pStateMachine);
    }

    template <typename TContext>
    boost::shared_ptr<typename TStateMachine<TContext>::TState> TStateMachine<TContext>::GetCurrentState() const
    {
        boost::shared_ptr<CStateBase> spState;
        fpGetCurrentState(this, spState);

        return boost::static_pointer_cast<TState>(spState);
    }

    template <typename TContext>
    TContext* TStateMachine<TContext>::GetContext() const
    {
        return static_cast<TContext*>(m_pContext);
    }

    template <typename TContext>
    void TStateMachine<TContext>::SetContext(TContext* in_pContext)
    {
        m_pContext = static_cast<void*>(in_pContext);
    }
}