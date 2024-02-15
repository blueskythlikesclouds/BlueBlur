namespace Hedgehog::Universe
{
    inline BB_FUNCTION_PTR(void, __thiscall, fpCStateBaseCtor, 0x76DD70, CStateMachineBase::CStateBase* This);

    inline CStateMachineBase::CStateBase::CStateBase() : CStateBase(bb_null_ctor{})
    {
        fpCStateBaseCtor(this);
    }

    inline void* CStateMachineBase::CStateBase::GetContextBase() const
    {
        return m_pContext;
    }

    inline const Base::CSharedString& CStateMachineBase::CStateBase::GetStateName()
    {
        return m_Name;
    }

    inline float CStateMachineBase::CStateBase::GetDeltaTime() const
    {
        return m_pStateMachine->m_UpdateInfo.DeltaTime;
    }

    inline uint32_t pCStateBaseHoldPropertyFloatFuncAddr = 0x50DFB0;

    inline void CStateMachineBase::CStateBase::HoldPropertyFloat(const hh::Base::CSharedString& in_rName,
        const float* in_pValue) volatile
    {
        __asm
        {
            mov eax, this
            mov edi, in_rName
            push in_pValue
            call pCStateBaseHoldPropertyFloatFuncAddr
        }
    }

    inline uint32_t ppCStateBaseHoldPropertyBoolFuncAddr = 0x50DD40;

    inline void CStateMachineBase::CStateBase::HoldPropertyBool(const hh::Base::CSharedString& in_rName,
        const bool* in_pValue) volatile
    {
        __asm
        {
            mov eax, this
            mov edi, in_rName
            push in_pValue
            call ppCStateBaseHoldPropertyBoolFuncAddr
        }
    }

    inline BB_FUNCTION_PTR(void, __thiscall, fpCStateMachineBaseCtor, 0x76E3C0,
        CStateMachineBase* This);

    inline CStateMachineBase::CStateMachineBase() : CStateMachineBase(bb_null_ctor{})
    {
        fpCStateMachineBaseCtor(this);
    }

    inline BB_FUNCTION_PTR(void, __thiscall, fpCStateMachineBaseRegisterStateFactory, 0x76CAA0,
        CStateMachineBase* This, Base::CSharedString in_Name, boost::function<boost::shared_ptr<CStateMachineBase::CStateBase>()> in_Factory);

    inline void CStateMachineBase::RegisterStateFactory(Base::CSharedString in_Name,
        boost::function<boost::shared_ptr<CStateBase>()> in_Factory)
    {
        fpCStateMachineBaseRegisterStateFactory(this, std::move(in_Name), std::move(in_Factory));
    }

    template <typename TState>
    void CStateMachineBase::RegisterStateFactory()
    {
        RegisterStateFactory(std::move(Base::CSharedString(TState::ms_pStateName)), [] { return boost::make_shared<TState>(); });
    }

    inline BB_FUNCTION_PTR(void, __thiscall, fpCStateMachineBaseUpdateStateMachine, 0x76DF00,
        CStateMachineBase* This, const SUpdateInfo& in_rUpdateInfo);

    inline void CStateMachineBase::UpdateStateMachine(const SUpdateInfo& in_rUpdateInfo)
    {
        fpCStateMachineBaseUpdateStateMachine(this, in_rUpdateInfo);
    }

    inline void* CStateMachineBase::GetContextBase() const
    {
        return m_pContext;
    }

    inline void CStateMachineBase::SetContextBase(void* pContext)
    {
        m_pContext = pContext;
    }

    inline BB_FUNCTION_PTR(void, __thiscall, fpCStateMachineBaseGetCurrentState, 0x76B5C0,
        const CStateMachineBase* This, boost::shared_ptr<CStateMachineBase::CStateBase>& out_spState);

    inline boost::shared_ptr<CStateMachineBase::CStateBase> CStateMachineBase::GetCurrentState()
    {
        boost::shared_ptr<CStateBase> spState;
        fpCStateMachineBaseGetCurrentState(this, spState);
        return spState;
    }

    inline BB_FUNCTION_PTR(void, __thiscall, fpCStateMachineBaseChangeState, 0x76F230,
        CStateMachineBase* This, boost::shared_ptr<CStateMachineBase::CStateBase>& out_spState, Base::CSharedString in_Name, int in_Priority, float in_Time, bool in_Flag);

    inline boost::shared_ptr<CStateMachineBase::CStateBase> CStateMachineBase::ChangeState(Base::CSharedString in_Name,
        const int in_Priority, const float in_Time, const bool in_Flag)
    {
        boost::shared_ptr<CStateBase> spState;
        fpCStateMachineBaseChangeState(this, spState, std::move(in_Name), in_Priority, in_Time, in_Flag);
        return spState;
    }

    template <typename TState>
    boost::shared_ptr<TState> CStateMachineBase::ChangeState(const int in_Priority, const float in_Time,
        const bool in_Flag)
    {
        return boost::static_pointer_cast<TState>(ChangeState(std::move(Base::CSharedString(TState::ms_pStateName)), in_Priority, in_Time, in_Flag));
    }

    inline BB_FUNCTION_PTR(bool, __thiscall, fpCStateMachineBaseProcessMessageInStateMachine, 0x76B640,
        CStateMachineBase* This, Message& in_rMsg, bool in_Flag);

    inline bool CStateMachineBase::ProcessMessageInStateMachine(Message& in_rMsg, bool in_Flag)
    {
        return fpCStateMachineBaseProcessMessageInStateMachine(this, in_rMsg, in_Flag);
    }
}