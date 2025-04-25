namespace Sonic
{
    inline uint32_t pCAnimationStateMachineCtor = 0xCDF720;

    inline BB_NOINLINE void fCAnimationStateMachineCtor(CAnimationStateMachine* This)
    {
        __asm
        {
            mov esi, This
            call[pCAnimationStateMachineCtor]
        }
    }

    inline CAnimationStateMachine::CAnimationStateMachine() : CAnimationStateMachine(bb_null_ctor{})
    {
        fCAnimationStateMachineCtor(this);
    }

    inline BB_FUNCTION_PTR(void, __stdcall, fpCAnimationStateMachineAddAnimationState, 0xCDFA20,
        CAnimationStateMachine* This, const boost::shared_ptr<CAnimationState>& out_spAnimationState, const Hedgehog::Base::CSharedString& in_rName, const Hedgehog::Base::CSharedString& in_rAlsoName);

    inline boost::shared_ptr<CAnimationState> CAnimationStateMachine::AddAnimationState(
        const Hedgehog::Base::CSharedString& in_rName)
    {
        boost::shared_ptr<CAnimationState> spAnimationState;
        fpCAnimationStateMachineAddAnimationState(this, spAnimationState, in_rName, in_rName);
        return spAnimationState;
    }

    inline BB_FUNCTION_PTR(const boost::shared_ptr<CAnimationState>&, __stdcall, fpCAnimationStateMachineGetAnimationState, 0xCDFB40,
        CAnimationStateMachine* This, const Hedgehog::Base::CSharedString& in_rName);

    inline const boost::shared_ptr<CAnimationState>& CAnimationStateMachine::GetAnimationState(
        const Hedgehog::Base::CSharedString& in_rName)
    {
        return fpCAnimationStateMachineGetAnimationState(this, in_rName);
    }

    inline BB_FUNCTION_PTR(void, __stdcall, fpCAnimationStateMachineChangeState, 0xCDFC80,
        CAnimationStateMachine* This, boost::shared_ptr<CAnimationState>& out_spAnimationState, const Hedgehog::Base::CSharedString& in_rName);

    inline boost::shared_ptr<CAnimationState> CAnimationStateMachine::ChangeState(
        const Hedgehog::Base::CSharedString& in_rName)
    {
        boost::shared_ptr<CAnimationState> spAnimationState;
        fpCAnimationStateMachineChangeState(this, spAnimationState, in_rName);
        return spAnimationState;
    }

    inline uint32_t pCAnimationStateMachineUpdate = 0xCE0810;

    inline BB_NOINLINE void fCAnimationStateMachineUpdate(CAnimationStateMachine* This, const Hedgehog::Universe::SUpdateInfo& in_rUpdateInfo)
    {
        __asm
        {
            mov ecx, This
            mov eax, in_rUpdateInfo
            call[pCAnimationStateMachineUpdate]
        }
    }

    inline void CAnimationStateMachine::Update(const Hedgehog::Universe::SUpdateInfo& in_rUpdateInfo)
    {
        fCAnimationStateMachineUpdate(this, in_rUpdateInfo);
    }
}