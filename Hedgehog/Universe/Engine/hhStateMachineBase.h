#pragma once

#include <Hedgehog/Base/hhObject.h>
#include <Hedgehog/Universe/Engine/hhMessageProcess.h>
#include <Hedgehog/Universe/Engine/hhStateMachineMessageReceiver.h>
#include <Hedgehog/Universe/Engine/hhUpdateInfo.h>

namespace Hedgehog::Universe
{
    class Message;
    class CStateMachineBase;

    static inline BB_FUNCTION_PTR(bool, __thiscall, fpCStateMachineBaseReceiveMessage, 0x76B640,
        CStateMachineBase* This, Message& message, bool flag);

    static inline BB_FUNCTION_PTR(void, __thiscall, fpCStateMachineBaseUpdate, 0x76DF00,
        CStateMachineBase* This, const SUpdateInfo& updateInfo);

    class CStateMachineBase : public IStateMachineMessageReceiver, public Base::CObject
    {
    public:
        class CStateBase : public IMessageProcess, public Base::CObject
        {
        public:
            void* m_pOwner;
            CStateMachineBase* m_pStateMachine;
            float m_TotalTime;
            BB_INSERT_PADDING(0x4);
            Base::CSharedString m_Name;
            BB_INSERT_PADDING(0x44);

            virtual bool ProcessMessage(Message& message, bool flag)
            {
                return false;
            }

            virtual ~CStateBase() = default;

            virtual void Enter() {}
            virtual void Update() {}

            virtual void CStateBase10() {}

            virtual void Leave() {}

            virtual void CStateBase18() {}
            virtual void CStateBase1C() {}

            virtual const Base::CSharedString& GetName() 
            {
                return m_Name;
            }
        };

        BB_INSERT_PADDING(0x18);
        void* m_pOwner;
        float m_TotalTime;
        SUpdateInfo m_UpdateInfo;
        BB_INSERT_PADDING(0x34);

        virtual bool ReceiveMessage(Message& message, bool flag) override
        {
            return fpCStateMachineBaseReceiveMessage(this, message, flag);
        }

        virtual ~CStateMachineBase() = default;

        void Update(const SUpdateInfo& updateInfo)
        {
            fpCStateMachineBaseUpdate(this, updateInfo);
        }
    };

    BB_ASSERT_OFFSETOF(CStateMachineBase::CStateBase, m_pOwner, 0x8);
    BB_ASSERT_OFFSETOF(CStateMachineBase::CStateBase, m_pStateMachine, 0xC);
    BB_ASSERT_OFFSETOF(CStateMachineBase::CStateBase, m_TotalTime, 0x10);
    BB_ASSERT_OFFSETOF(CStateMachineBase::CStateBase, m_Name, 0x18);
    BB_ASSERT_SIZEOF(CStateMachineBase::CStateBase, 0x60);
    BB_ASSERT_OFFSETOF(CStateMachineBase, m_pOwner, 0x1C);
    BB_ASSERT_OFFSETOF(CStateMachineBase, m_TotalTime, 0x20);
    BB_ASSERT_OFFSETOF(CStateMachineBase, m_UpdateInfo, 0x24);
    BB_ASSERT_SIZEOF(CStateMachineBase, 0x64);
}