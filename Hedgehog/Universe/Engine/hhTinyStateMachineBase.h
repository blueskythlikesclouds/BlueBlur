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
        class CStateBase : public IMessageProcess
        {
        public:
            BB_INSERT_PADDING(0x4);
            void* m_pContext;
            CTinyStateMachineBase* m_pStateMachine;
            float m_Time;
            uint8_t m_Halt;
            Base::CSharedString m_Name;
            int32_t m_Frame;
            int32_t m_Field20;

            CStateBase(const bb_null_ctor& nil) : IMessageProcess(nil) {}

            CStateBase();

            virtual bool ProcessMessage(Message& in_rMsg, bool in_Flag);

            virtual ~CStateBase() = default;

            virtual void EnterState() {}
            virtual void UpdateState() {}
            virtual void CStateBase10() {}
            virtual void LeaveState() {}
            virtual const Base::CSharedString& GetName();
        };

        int32_t m_Field4;
        int32_t m_Field8;
        int32_t m_FieldC;
        void* m_pContext;
        float m_Time;
        SUpdateInfo m_UpdateInfo;
        boost::shared_ptr<CStateBase> m_spCurrentState;
        uint8_t m_Field2C;

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
    BB_ASSERT_OFFSETOF(CTinyStateMachineBase::CStateBase, m_Halt, 0x14);
    BB_ASSERT_OFFSETOF(CTinyStateMachineBase::CStateBase, m_Name, 0x18);
    BB_ASSERT_OFFSETOF(CTinyStateMachineBase::CStateBase, m_Frame, 0x1C);
    BB_ASSERT_OFFSETOF(CTinyStateMachineBase::CStateBase, m_Field20, 0x20);
    BB_ASSERT_SIZEOF(CTinyStateMachineBase::CStateBase, 0x24);

    BB_ASSERT_OFFSETOF(CTinyStateMachineBase, m_Field4, 0x4);
    BB_ASSERT_OFFSETOF(CTinyStateMachineBase, m_Field8, 0x8);
    BB_ASSERT_OFFSETOF(CTinyStateMachineBase, m_FieldC, 0xC);
    BB_ASSERT_OFFSETOF(CTinyStateMachineBase, m_pContext, 0x10);
    BB_ASSERT_OFFSETOF(CTinyStateMachineBase, m_Time, 0x14);
    BB_ASSERT_OFFSETOF(CTinyStateMachineBase, m_UpdateInfo, 0x18);
    BB_ASSERT_OFFSETOF(CTinyStateMachineBase, m_spCurrentState, 0x24);
    BB_ASSERT_OFFSETOF(CTinyStateMachineBase, m_Field2C, 0x2C);
    BB_ASSERT_SIZEOF(CTinyStateMachineBase, 0x30);
}

#include <Hedgehog/Universe/Engine/hhTinyStateMachineBase.inl>