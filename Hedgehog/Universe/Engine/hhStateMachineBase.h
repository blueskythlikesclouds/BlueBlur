#pragma once

#include <Hedgehog/Base/hhObject.h>
#include <Hedgehog/Universe/Engine/hhMessageProcess.h>
#include <Hedgehog/Universe/Engine/hhStateMachineMessageReceiver.h>
#include <Hedgehog/Universe/Engine/hhUpdateInfo.h>

namespace Hedgehog::Universe
{
    class Message;
    class CStateMachineBase;

    static inline BB_FUNCTION_PTR(bool, __thiscall, fpCStateMachineBaseProcessMessageInStateMachine, 0x76B640,
        CStateMachineBase* This, Message& in_rMsg, bool in_Flag);

    static inline BB_FUNCTION_PTR(void, __thiscall, fpCStateMachineBaseUpdateStateMachine, 0x76DF00,
        CStateMachineBase* This, const SUpdateInfo& in_rUpdateInfo);

    static inline BB_FUNCTION_PTR(void, __thiscall, fpCStateMachineBaseCtor, 0x76E3C0,
        CStateMachineBase* This);

    class CStateMachineBase : public IStateMachineMessageReceiver, public Base::CObject
    {
    public:
        class CStateBase : public IMessageProcess, public Base::CObject
        {
        public:
            void* m_pContext;
            CStateMachineBase* m_pStateMachine;
            float m_Time;
            BB_INSERT_PADDING(0x4);
            Base::CSharedString m_Name;
            int m_Field01C;
            float m_DeactivateTime;
            BB_INSERT_PADDING(0x34);
            boost::shared_ptr<Hedgehog::Universe::CStateMachineBase::CStateBase> m_spNextState;

            static inline BB_FUNCTION_PTR(void, __thiscall, fpCtor, 0x76DD70, CStateBase* This);

            CStateBase(const bb_null_ctor& nil) : IMessageProcess(nil), CObject(nil) {}

            CStateBase() : CStateBase(bb_null_ctor{})
            {
                fpCtor(this);
            }

            void* GetContextBase() const
            {
                return m_pContext;
            }

            virtual bool ProcessMessage(Message& in_rMsg, bool in_Flag)
            {
                return false;
            }

            virtual ~CStateBase();

            virtual void EnterState() {}
            virtual void UpdateState() {}

            virtual void CStateBase10() {}

            virtual void LeaveState() {}

            virtual void CStateBase18() {}
            virtual void CStateBase1C(float deltaTime, bool flag) {}

            virtual const Base::CSharedString& GetStateName() 
            {
                return m_Name;
            }

            float GetDeltaTime()
            {
                return m_pStateMachine->m_UpdateInfo.DeltaTime;
            }

            __declspec(noinline) void HoldPropertyFloat(const hh::Base::CSharedString& name, const float* value) volatile
            {
                static constexpr uint32_t func = 0x0050DFB0;
                __asm
                {
                    mov eax, this
                    mov edi, name
                    push value
                    call func
                }
            }

            __declspec(noinline) void HoldPropertyBool(const hh::Base::CSharedString& name, const bool* value) volatile
            {
                static constexpr uint32_t func = 0x0050DD40;
                __asm
                {
                    mov eax, this
                    mov edi, name
                    push value
                    call func
                }
            }

        };

        class CInterpolator
        {
        public:
            float m_OnePointZero = 0.0f;
            float m_EaseTime = 0.0f;
            float m_Time = 0.0f;
            int m_BlendAmountMaybe = 0;
            BB_INSERT_PADDING(0x04) {};
            boost::shared_ptr<CInterpolator> m_spPreviousInterpolator;
            boost::shared_ptr<CStateBase> m_spState;
            boost::shared_ptr<void> m_spInterpolationStrategy;
            BB_INSERT_PADDING(0x04) {};
        };

        BB_INSERT_PADDING(0x18);
        void* m_pContext;
        float m_Time;
        SUpdateInfo m_UpdateInfo;
        hh::map<void*, void*> m_StatesMap;
        int m_NumStates;
        BB_INSERT_PADDING(0x18);
        boost::shared_ptr<CInterpolator> m_spInterpolator;

        CStateMachineBase(const bb_null_ctor& nil) : IStateMachineMessageReceiver(nil), CObject(nil) {}

        CStateMachineBase() : CStateMachineBase(bb_null_ctor{})
        {
            fpCStateMachineBaseCtor(this);
        }

        static inline BB_FUNCTION_PTR(void, __thiscall, fpRegisterStateFactory, 0x76CAA0,
            CStateMachineBase* This, Base::CSharedString in_Name, boost::function<boost::shared_ptr<CStateBase>()> in_Factory);

        void RegisterStateFactory(Base::CSharedString in_Name, boost::function<boost::shared_ptr<CStateBase>()> in_Factory)
        {
            fpRegisterStateFactory(this, std::move(in_Name), std::move(in_Factory));
        }

        template<typename TState>
        void RegisterStateFactory()
        {
            RegisterStateFactory(std::move(Base::CSharedString(TState::ms_pStateName)), [] { return boost::make_shared<TState>(); });
        }

        void UpdateStateMachine(const SUpdateInfo& in_rUpdateInfo)
        {
            fpCStateMachineBaseUpdateStateMachine(this, in_rUpdateInfo);
        }

        void* GetContextBase() const
        {
            return m_pContext;
        }

        void SetContextBase(void* pContext)
        {
            m_pContext = pContext;
        }

        static inline BB_FUNCTION_PTR(void, __thiscall, fpGetCurrentState, 0x76B5C0,
            CStateMachineBase* This, boost::shared_ptr<CStateBase>& out_spState);

        boost::shared_ptr<CStateBase> GetCurrentState()
        {
            boost::shared_ptr<CStateBase> spState;
            fpGetCurrentState(this, spState);
            return spState;
        }

        static inline BB_FUNCTION_PTR(void, __thiscall, fpChangeState, 0x76F230,
            CStateMachineBase* This, boost::shared_ptr<CStateBase>& out_spState, Base::CSharedString in_Name, int in_Priority, float in_Time, bool in_Flag);

        boost::shared_ptr<CStateBase> ChangeState(Base::CSharedString in_Name, const int in_Priority = 0, const float in_Time = 0, const bool in_Flag = false)
        {
            boost::shared_ptr<CStateBase> spState;
            fpChangeState(this, spState, std::move(in_Name), in_Priority, in_Time, in_Flag);
            return spState;
        }

        template<typename TState>
        boost::shared_ptr<TState> ChangeState(const int in_Priority = 0, const float in_Time = 0, const bool in_Flag = false)
        {
            return boost::static_pointer_cast<TState>(ChangeState(std::move(Base::CSharedString(TState::ms_pStateName)), in_Priority, in_Time, in_Flag));
        }

        virtual bool ProcessMessageInStateMachine(Message& in_rMsg, bool in_Flag) override
        {
            return fpCStateMachineBaseProcessMessageInStateMachine(this, in_rMsg, in_Flag);
        }

        virtual ~CStateMachineBase();
    };

    BB_ASSERT_OFFSETOF(CStateMachineBase::CStateBase, m_pContext, 0x8);
    BB_ASSERT_OFFSETOF(CStateMachineBase::CStateBase, m_pStateMachine, 0xC);
    BB_ASSERT_OFFSETOF(CStateMachineBase::CStateBase, m_Time, 0x10);
    BB_ASSERT_OFFSETOF(CStateMachineBase::CStateBase, m_Name, 0x18);
    BB_ASSERT_SIZEOF(CStateMachineBase::CStateBase, 0x60);

    BB_ASSERT_OFFSETOF(CStateMachineBase, m_pContext, 0x1C);
    BB_ASSERT_OFFSETOF(CStateMachineBase, m_Time, 0x20);
    BB_ASSERT_OFFSETOF(CStateMachineBase, m_UpdateInfo, 0x24);
    BB_ASSERT_SIZEOF(CStateMachineBase, 0x60);
}