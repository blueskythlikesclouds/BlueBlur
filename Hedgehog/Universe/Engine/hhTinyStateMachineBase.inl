namespace Hedgehog::Universe
{
    static inline BB_FUNCTION_PTR(void, __thiscall, fpCTinyStateMachineBaseCtor, 0x773410,
        CTinyStateMachineBase* This);
    static inline BB_FUNCTION_PTR(void, __thiscall, ffpCTinyStateMachineBaseCStateBaseCtor, 0x772BA0, CTinyStateMachineBase::CStateBase* This);

    static inline BB_FUNCTION_PTR(void, __thiscall, fpRegisterStateFactory, 0x773280,
        CTinyStateMachineBase* This, Base::CSharedString in_Name, boost::function<boost::shared_ptr<CTinyStateMachineBase::CStateBase>()> in_Factory);

    static inline BB_FUNCTION_PTR(void, __thiscall, fpChangeState, 0x7731D0,
        CTinyStateMachineBase* This, boost::shared_ptr<CTinyStateMachineBase::CStateBase>& out_spState, Base::CSharedString in_Name);

    inline CTinyStateMachineBase::CStateBase::CStateBase() : CStateBase(bb_null_ctor{})
    {
        ffpCTinyStateMachineBaseCStateBaseCtor(this);
    }

    inline bool CTinyStateMachineBase::CStateBase::ProcessMessage(Message& message, bool flag)
    {
        return false;
    }

    inline const Base::CSharedString& CTinyStateMachineBase::CStateBase::GetName()
    {
        return m_Name;
    }

    inline CTinyStateMachineBase::CTinyStateMachineBase() : CTinyStateMachineBase(bb_null_ctor{})
    {
        fpCTinyStateMachineBaseCtor(this);
    }

    inline void CTinyStateMachineBase::RegisterStateFactory(Base::CSharedString in_Name, boost::function<boost::shared_ptr<CStateBase>()> in_Factory)
    {
        fpRegisterStateFactory(this, std::move(in_Name), std::move(in_Factory));
    }

    template <typename TState>
    void CTinyStateMachineBase::RegisterStateFactory()
    {
        RegisterStateFactory(std::move(Base::CSharedString(TState::ms_pStateName)), [] { return boost::make_shared<TState>(); });
    }

    inline boost::shared_ptr<CTinyStateMachineBase::CStateBase> CTinyStateMachineBase::ChangeState(Base::CSharedString in_Name)
    {
        boost::shared_ptr<CStateBase> spState;
        fpChangeState(this, spState, std::move(in_Name));
        return spState;
    }

    template <typename TState>
    boost::shared_ptr<TState> CTinyStateMachineBase::ChangeState()
    {
        return boost::static_pointer_cast<TState>(ChangeState(std::move(Base::CSharedString(TState::ms_pStateName))));
    }

    inline bool CTinyStateMachineBase::ProcessMessageInStateMachine(Message& in_rMsg, bool in_Flag)
    {
        return false;
    }
}