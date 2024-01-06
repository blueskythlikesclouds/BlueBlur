namespace Sonic
{
    inline Hedgehog::Base::TSynchronizedPtr<CInputState> CInputState::GetInstance()
    {
        return *ms_pInstance;
    }

    inline const SPadState& CInputState::GetPadState() const
    {
        return m_PadStates[m_CurrentPadStateIndex];
    }
}