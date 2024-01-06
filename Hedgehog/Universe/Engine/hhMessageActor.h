#pragma once

#include <Hedgehog/Base/Type/hhSharedString.h>
#include <Hedgehog/Base/Thread/hhSynchronizedPtr.h>
#include <Hedgehog/Universe/Engine/hhMessageProcess.h>
#include <Hedgehog/Universe/Thread/hhParallelJob.h>
#include <Hedgehog/Universe/Engine/hhMessageManager.h>

namespace Hedgehog::Universe
{
    class Message;
    class CMessageManager;
    class IStateMachineMessageReceiver;

    class CMessageActor : public IMessageProcess, public IParallelJob
    {
    public:
        BB_INSERT_PADDING(0x28);
        uint32_t m_ActorID;
        BB_INSERT_PADDING(0x0A);
        bool m_ActorIDCondition;
        bool m_ActorIDCondition2;
        BB_INSERT_PADDING(0x24);
        Base::TSynchronizedPtr<CMessageManager> m_pMessageManager;
        BB_INSERT_PADDING(0x18);

        CMessageActor(const bb_null_ctor& nil) : IMessageProcess(nil), IParallelJob(nil) {}
        CMessageActor();
        virtual ~CMessageActor();

        virtual void ExecuteParallelJob(const SUpdateInfo& in_rUpdateInfo) override;
        virtual bool ProcessMessage(Message& in_rMsg, bool in_Flag) { return false; }
        virtual IStateMachineMessageReceiver* GetStateMachineMessageReceiver(bool in_Flag) { return nullptr; }

#undef SendMessage

        bool SendMessage(const size_t in_ActorID, const boost::shared_ptr<Message>& in_spMsg, float in_Time = 0.0f);
        bool SendMessage(const Hedgehog::Base::CSharedString& in_rActorCategory, const boost::shared_ptr<Message>& in_spMsg, float in_Time = 0.0f);

        bool SendMessageImm(const size_t in_ActorID, const boost::shared_ptr<Message>& in_spMsg);

        // Custom implementation that passes in a message on the *stack* if it's immediate. Much faster.
        bool SendMessageImm(CMessageActor* in_pActor, Message& in_rMsg) const;

        bool SendMessageImm(const uint32_t in_ActorID, Message& in_rMsg) const;

        bool SendMessageSelfImm(Message& in_rMsg);

        template<typename T>
        bool SendMessageSelfImm();

        template<typename T, typename... Args>
        bool SendMessageSelfImm(Args&... args);

        template<typename T>
        bool SendMessageImm(const size_t in_ActorID);

        template<typename T, typename... Args>
        void SendMessageImm(const size_t in_ActorID, Args&... args);
    };

    BB_ASSERT_OFFSETOF(CMessageActor, m_ActorID, 0x2C);
    BB_ASSERT_OFFSETOF(CMessageActor, m_pMessageManager, 0x60);
    BB_ASSERT_SIZEOF(CMessageActor, 0x7C);
}

#include <Hedgehog/Universe/Engine/hhMessageActor.inl>