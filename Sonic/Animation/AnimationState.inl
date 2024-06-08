namespace Sonic
{
    inline void CAnimationState::SetTransitionState(const Hedgehog::Base::CSharedString& in_rTargetStateName, bool in_IsTransition, float in_Unknown01)
    {
        m_TransitionState = in_rTargetStateName;
        m_Field90 = in_IsTransition;
        m_Field8C = in_Unknown01;
    }

    inline float CAnimationState::GetDuration()
    {
        return m_spAnimationControlSingle->m_hkaDefaultAnimationControl->m_binding->m_animation->m_duration;
    }

    inline float CAnimationState::GetLocalTime()
    {
        return m_spAnimationControlSingle->m_hkaDefaultAnimationControl->m_localTime;
    }
}