#pragma once

#include <Hedgehog/Base/hhObject.h>
#include <Hedgehog/Universe/Engine/hhMessageProcess.h>
#include <Hedgehog/Universe/Engine/hhStateMachineMessageReceiver.h>
#include <Hedgehog/Universe/Engine/hhUpdateInfo.h>

#define BB_STATE_NAME(x) static constexpr const char* ms_pStateName = x;

namespace Hedgehog::Universe
{
    class Message;
    class CTinyStateMachineBase;

    class CTinyStateMachineBase : public IStateMachineMessageReceiver, public Base::CObject
    {
    public:
        class CStateBase : public IMessageProcess, public CObject
        {
        public:
            void* m_pContext;
            CTinyStateMachineBase* m_pStateMachine;
            float m_Time;
            char m_Halt;
            Base::CSharedString m_Name;
            int m_Frame;
            int m_Field020;

            CStateBase(const bb_null_ctor& nil) : IMessageProcess(nil), CObject(nil) {}

            CStateBase();

            virtual bool ProcessMessage(Message& message, bool flag);

            virtual ~CStateBase() = default;

            virtual void EnterState() {}
            virtual void UpdateState() {}
            virtual void CStateBase10() {}
            virtual void LeaveState() {}
            virtual const Base::CSharedString& GetName();
        };

        int m_Field04;
        int m_Field08;
        int m_Field0C;
        void* m_pContext;
        float m_CurrentTime;
        SUpdateInfo m_UpdateInfo;
        boost::shared_ptr<CStateBase> m_spCurrentState;
        char m_Field2C;

        CTinyStateMachineBase(const bb_null_ctor& nil) : IStateMachineMessageReceiver(nil), CObject(nil) {}

        CTinyStateMachineBase();

        virtual ~CTinyStateMachineBase() = default;

        void RegisterStateFactory(Base::CSharedString in_Name, boost::function<boost::shared_ptr<CStateBase>()> in_Factory);

        template<typename TState>
        void RegisterStateFactory();

        boost::shared_ptr<CStateBase> ChangeState(Base::CSharedString in_Name);

        template<typename TState>
        boost::shared_ptr<TState> ChangeState();

        bool ProcessMessageInStateMachine(Message& in_rMsg, bool in_Flag) override;
    };

    BB_ASSERT_OFFSETOF(CTinyStateMachineBase::CStateBase, m_pContext, 0x8);
    BB_ASSERT_OFFSETOF(CTinyStateMachineBase::CStateBase, m_pStateMachine, 0xC);
    BB_ASSERT_OFFSETOF(CTinyStateMachineBase::CStateBase, m_Time, 0x10);
    BB_ASSERT_OFFSETOF(CTinyStateMachineBase::CStateBase, m_Name, 0x18);
    BB_ASSERT_SIZEOF(CTinyStateMachineBase::CStateBase, 0x24);

    BB_ASSERT_OFFSETOF(CTinyStateMachineBase, m_UpdateInfo, 0x18);
    BB_ASSERT_OFFSETOF(CTinyStateMachineBase, m_spCurrentState, 0x24);
    BB_ASSERT_SIZEOF(CTinyStateMachineBase, 0x30);
}

#include <Hedgehog/Universe/Engine/hhTinyStateMachineBase.inl>