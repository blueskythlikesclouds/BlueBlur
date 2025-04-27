namespace Hedgehog::Universe
{
    template <typename TContext>
    TContext* TTinyStateMachine<TContext>::TState::GetContext() const
    {
        return static_cast<TContext*>(m_pContext);
    }

    template <typename TContext>
    TTinyStateMachine<TContext>* TTinyStateMachine<TContext>::TState::GetTinyStateMachine() const
    {
        return static_cast<TTinyStateMachine<TContext*>>(m_pStateMachine);
    }

    template <typename TContext>
    boost::shared_ptr<typename TTinyStateMachine<TContext>::TState> TTinyStateMachine<TContext>::GetCurrentState()
    {
        return boost::static_pointer_cast<TState>(m_spCurrentState);
    }

    template <typename TContext>
    TContext* TTinyStateMachine<TContext>::GetContext() const
    {
        return static_cast<TContext*>(m_pContext);
    }

    template <typename TContext>
    void TTinyStateMachine<TContext>::SetContext(TContext* in_pContext)
    {
        m_pContext = static_cast<void*>(in_pContext);
    }
}