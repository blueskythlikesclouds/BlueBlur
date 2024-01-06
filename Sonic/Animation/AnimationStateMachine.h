#pragma once

#include <Hedgehog/Universe/Engine/hhStateMachineBase.h>

namespace Sonic
{
    class CAnimationState;
    class CAnimationStateMachine;

    class IAnimationContext;

    static uint32_t pCAnimationStateMachineCtor = 0xCDF720;

    static void fCAnimationStateMachineCtor(CAnimationStateMachine* This)
    {
        __asm
        {
            mov esi, This
            call [pCAnimationStateMachineCtor]
        }
    }

    static uint32_t pCAnimationStateMachineUpdate = 0xCE0810;

    static void fCAnimationStateMachineUpdate(CAnimationStateMachine* This, const Hedgehog::Universe::SUpdateInfo& in_rUpdateInfo)
    {
        __asm
        {
            mov ecx, This
            mov eax, in_rUpdateInfo
            call [pCAnimationStateMachineUpdate]
        }
    }

    static inline BB_FUNCTION_PTR(void, __stdcall, fpCAnimationStateMachineAddAnimationState, 0xCDFA20,
        CAnimationStateMachine* This, const boost::shared_ptr<CAnimationState>& out_spAnimationState, const Hedgehog::Base::CSharedString& in_rName, const Hedgehog::Base::CSharedString& in_rAlsoName);

    static inline BB_FUNCTION_PTR(const boost::shared_ptr<CAnimationState>&, __stdcall, fpCAnimationStateMachineGetAnimationState, 0xCDFB40, 
        CAnimationStateMachine* This, const Hedgehog::Base::CSharedString& in_rName);

    static inline BB_FUNCTION_PTR(void, __stdcall, fpCAnimationStateMachineChangeState, 0xCDFC80,
        CAnimationStateMachine* This, boost::shared_ptr<CAnimationState>& out_spAnimationState, const Hedgehog::Base::CSharedString& in_rName);

    class CAnimationStateMachine : public Hedgehog::Universe::TStateMachine<IAnimationContext>
    {
    public:
        BB_INSERT_PADDING(0x28) {};

        CAnimationStateMachine(const bb_null_ctor&)
            : TStateMachine(bb_null_ctor{})
        {
        }

        CAnimationStateMachine()
            : CAnimationStateMachine(bb_null_ctor{})
        {
            fCAnimationStateMachineCtor(this);
        }

        boost::shared_ptr<CAnimationState> AddAnimationState(const Hedgehog::Base::CSharedString& in_rName)
        {
            boost::shared_ptr<CAnimationState> spAnimationState;
            fpCAnimationStateMachineAddAnimationState(this, spAnimationState, in_rName, in_rName);
            return spAnimationState;
        }

        const boost::shared_ptr<CAnimationState>& GetAnimationState(const Hedgehog::Base::CSharedString& in_rName)
        {
            return fpCAnimationStateMachineGetAnimationState(this, in_rName);
        }

        boost::shared_ptr<CAnimationState> ChangeState(const Hedgehog::Base::CSharedString& in_rName)
        {
            boost::shared_ptr<CAnimationState> spAnimationState;
            fpCAnimationStateMachineChangeState(this, spAnimationState, in_rName);
            return spAnimationState;
        }

        void Update(const Hedgehog::Universe::SUpdateInfo& in_rUpdateInfo)
        {
            fCAnimationStateMachineUpdate(this, in_rUpdateInfo);
        }
    };

    BB_ASSERT_SIZEOF(CAnimationStateMachine, 0x88);
}