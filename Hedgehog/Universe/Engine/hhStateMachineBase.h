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
        CStateMachineBase* This, Message& message, bool flag);

    static inline BB_FUNCTION_PTR(void, __thiscall, fpCStateMachineBaseUpdateStateMachine, 0x76DF00,
        CStateMachineBase* This, const SUpdateInfo& updateInfo);

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
            BB_INSERT_PADDING(0x44);

            static inline BB_FUNCTION_PTR(void, __thiscall, fpCtor, 0x76DD70, CStateBase* This);

            CStateBase(const bb_null_ctor&) : IMessageProcess(bb_null_ctor{}), CObject(bb_null_ctor{}) {}

            CStateBase() : CStateBase(bb_null_ctor{})
            {
                fpCtor(this);
            }

            void* GetContextBase() const
            {
                return m_pContext;
            }

            virtual bool ProcessMessage(Message& message, bool flag)
            {
                return false;
            }

            virtual ~CStateBase() = default;

            virtual void EnterState() {}
            virtual void UpdateState() {}

            virtual void CStateBase10() {}

            virtual void LeaveState() {}

            virtual void CStateBase18() {}
            virtual void CStateBase1C() {}

            virtual const Base::CSharedString& GetStateName() 
            {
                return m_Name;
            }
        };

        BB_INSERT_PADDING(0x18);
        void* m_pContext;
        float m_Time;
        SUpdateInfo m_UpdateInfo;
        BB_INSERT_PADDING(0x30);

        CStateMachineBase(const bb_null_ctor&) : IStateMachineMessageReceiver(bb_null_ctor{}), CObject(bb_null_ctor{}) {}

        CStateMachineBase() : CStateMachineBase(bb_null_ctor{})
        {
            fpCStateMachineBaseCtor(this);
        }

        static inline BB_FUNCTION_PTR(void, __thiscall, fpRegisterStateFactory, 0x76CAA0,
            CStateMachineBase* This, const Base::CSharedString& name, boost::function<boost::shared_ptr<CStateBase>()> factory);

        void RegisterStateFactory(const Base::CSharedString& name, boost::function<boost::shared_ptr<CStateBase>()> factory)
        {
            fpRegisterStateFactory(this, name, std::move(factory));
        }

        template<typename TState>
        void RegisterStateFactory()
        {
            RegisterStateFactory(TState::ms_pStateName, [] { return boost::make_shared<TState>(); });
        }

        void UpdateStateMachine(const SUpdateInfo& updateInfo)
        {
            fpCStateMachineBaseUpdateStateMachine(this, updateInfo);
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
            CStateMachineBase* This, boost::shared_ptr<CStateBase>& spState);

        boost::shared_ptr<CStateBase> GetCurrentState()
        {
            boost::shared_ptr<CStateBase> spState;
            fpGetCurrentState(this, spState);
            return spState;
        }

        static inline BB_FUNCTION_PTR(void, __thiscall, fpChangeState, 0x76F230,
            CStateMachineBase* This, boost::shared_ptr<CStateBase>& spState, const Base::CSharedString& name, int priority, float time, bool flag);

        boost::shared_ptr<CStateBase> ChangeState(const Base::CSharedString& name, const int priority = 0, const float time = 0, const bool flag = false)
        {
            boost::shared_ptr<CStateBase> spState;
            fpChangeState(this, spState, name, priority, time, flag);
            return spState;
        }

        template<typename TState>
        boost::shared_ptr<TState> ChangeState(const int priority = 0, const float time = 0, const bool flag = false)
        {
            return boost::static_pointer_cast<TState>(CStateMachineBase::ChangeState(TState::ms_pStateName, priority, time, flag));
        }

        virtual bool ProcessMessageInStateMachine(Message& message, bool flag) override
        {
            return fpCStateMachineBaseProcessMessageInStateMachine(this, message, flag);
        }

        virtual ~CStateMachineBase() = default;
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