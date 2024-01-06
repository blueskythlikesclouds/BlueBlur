#pragma once

#include <Hedgehog/Base/hhObject.h>
#include <Hedgehog/Universe/Engine/hhMessageProcess.h>
#include <Hedgehog/Universe/Engine/hhStateMachineMessageReceiver.h>
#include <Hedgehog/Universe/Engine/hhUpdateInfo.h>

namespace Hedgehog::Universe
{
    class Message;

    class CStateMachineBase : public IStateMachineMessageReceiver, public Base::CObject
    {
    public:
        class CStateBase : public IMessageProcess
        {
        public:
            BB_INSERT_PADDING(0x4);
            void* m_pContext;
            CStateMachineBase* m_pStateMachine;
            float m_Time;
            BB_INSERT_PADDING(0x4);
            Base::CSharedString m_Name;
            int m_Field1C;
            float m_DeactivateTime;
            BB_INSERT_PADDING(0x34);
            boost::shared_ptr<CStateBase> m_spNextState;

            CStateBase(const bb_null_ctor& nil) : IMessageProcess(nil) {}
            CStateBase();

            void* GetContextBase() const;

            virtual bool ProcessMessage(Message& in_rMsg, bool in_Flag) { return false; }

            virtual ~CStateBase();

            virtual void EnterState() {}
            virtual void UpdateState() {}

            virtual void CStateBase10() {}

            virtual void LeaveState() {}

            virtual void CStateBase18() {}
            virtual void CStateBase1C(float deltaTime, bool flag) {}

            virtual const Base::CSharedString& GetStateName();

            float GetDeltaTime() const;

            __declspec(noinline) void HoldPropertyFloat(const hh::Base::CSharedString& in_rName, const float* in_pValue) volatile;
            __declspec(noinline) void HoldPropertyBool(const hh::Base::CSharedString& in_rName, const bool* in_pValue) volatile;
        };

        class CInterpolateStrategy;

        class CInterpolator
        {
        public:
            float m_OnePointZero = 0.0f;
            float m_EaseTime = 0.0f;
            float m_Time = 0.0f;
            int m_BlendAmountMaybe = 0;
            BB_INSERT_PADDING(0x04) {};
            boost::shared_ptr<CInterpolator> m_spPrevInterpolator;
            boost::shared_ptr<CStateBase> m_spState;
            boost::shared_ptr<CInterpolateStrategy> m_spInterpolateStrategy;
            BB_INSERT_PADDING(0x04) {};
        };

        hh::map<Hedgehog::Base::CSharedString, boost::function<boost::shared_ptr<CStateBase>()>> m_StateFactoryMap;
        BB_INSERT_PADDING(0xC);
        void* m_pContext;
        float m_Time;
        SUpdateInfo m_UpdateInfo;
        hh::map<void*, void*> m_StateMap;
        size_t m_StateNum;
        BB_INSERT_PADDING(0x18);
        boost::shared_ptr<CInterpolator> m_spInterpolator;

        CStateMachineBase(const bb_null_ctor& nil) : IStateMachineMessageReceiver(nil), CObject(nil) {}
        CStateMachineBase();

        void RegisterStateFactory(Base::CSharedString in_Name, boost::function<boost::shared_ptr<CStateBase>()> in_Factory);

        template<typename TState>
        void RegisterStateFactory();

        void UpdateStateMachine(const SUpdateInfo& in_rUpdateInfo);

        void* GetContextBase() const;
        void SetContextBase(void* pContext);

        boost::shared_ptr<CStateBase> GetCurrentState();

        boost::shared_ptr<CStateBase> ChangeState(Base::CSharedString in_Name, const int in_Priority = 0, const float in_Time = 0, const bool in_Flag = false);

        template<typename TState>
        boost::shared_ptr<TState> ChangeState(const int in_Priority = 0, const float in_Time = 0, const bool in_Flag = false);

        virtual bool ProcessMessageInStateMachine(Message& in_rMsg, bool in_Flag) override;

        virtual ~CStateMachineBase();
    };

    BB_ASSERT_OFFSETOF(CStateMachineBase::CStateBase, m_pContext, 0x8);
    BB_ASSERT_OFFSETOF(CStateMachineBase::CStateBase, m_pStateMachine, 0xC);
    BB_ASSERT_OFFSETOF(CStateMachineBase::CStateBase, m_Time, 0x10);
    BB_ASSERT_OFFSETOF(CStateMachineBase::CStateBase, m_Name, 0x18);
    BB_ASSERT_OFFSETOF(CStateMachineBase::CStateBase, m_Field1C, 0x1C);
    BB_ASSERT_OFFSETOF(CStateMachineBase::CStateBase, m_DeactivateTime, 0x20);
    BB_ASSERT_OFFSETOF(CStateMachineBase::CStateBase, m_spNextState, 0x58);
    BB_ASSERT_SIZEOF(CStateMachineBase::CStateBase, 0x60);

    BB_ASSERT_OFFSETOF(CStateMachineBase, m_StateFactoryMap, 0x4);
    BB_ASSERT_OFFSETOF(CStateMachineBase, m_pContext, 0x1C);
    BB_ASSERT_OFFSETOF(CStateMachineBase, m_Time, 0x20);
    BB_ASSERT_OFFSETOF(CStateMachineBase, m_UpdateInfo, 0x24);
    BB_ASSERT_SIZEOF(CStateMachineBase, 0x60);
}

#include <Hedgehog/Universe/Engine/hhStateMachineBase.inl>