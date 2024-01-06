#pragma once

#include <Hedgehog/Base/Type/hhSharedString.h>
#include <Hedgehog/Base/Thread/hhSynchronizedPtr.h>
#include <Hedgehog/Universe/Engine/hhMessageProcess.h>
#include <Hedgehog/Universe/Thread/hhParallelJob.h>
#include <Hedgehog/Universe/Engine/hhMessageManager.h>

namespace Hedgehog::Universe
{
    class Message;
    class CMessageActor;
    class CMessageManager;
    class IStateMachineMessageReceiver;

    static inline BB_FUNCTION_PTR(CMessageActor*, __thiscall, fpCMessageActorCtor, 0x768A00, CMessageActor* This);

    static inline BB_FUNCTION_PTR(void, __thiscall, fpCMessageActorExecuteParallelJob, 0x7680C0, CMessageActor* This, const SUpdateInfo& in_rUpdateInfo);

    static inline BB_FUNCTION_PTR(bool, __thiscall, fpCMessageActorSendMessageByID, 0x768340,
        CMessageActor* This, const char* in_pPath, size_t in_Line, size_t in_ActorID, const boost::shared_ptr<Message>& in_spMsg, float in_Time);   
    
    static inline BB_FUNCTION_PTR(bool, __thiscall, fpCMessageActorSendMessageByCategory, 0x7684E0,
        CMessageActor* This, const char* in_pPath, size_t in_Line, const Hedgehog::Base::CSharedString& in_rActorCategory, const boost::shared_ptr<Message>& in_spMsg, float in_Time);

    static inline BB_FUNCTION_PTR(bool, __thiscall, fpCMessageActorSendMessageImmByID, 0x767EE0,
        CMessageActor* This, const char* in_pPath, size_t in_Line, size_t in_ActorID, const boost::shared_ptr<Message>& in_spMsg);

    static inline BB_FUNCTION_PTR(bool, __thiscall, fpCMessageActorProcessMessage, 0x767D20, 
        CMessageActor* This, Message& in_rMsg);

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

        CMessageActor() : CMessageActor(bb_null_ctor{})
        {
            fpCMessageActorCtor(this);
        }

        virtual ~CMessageActor();

        virtual void ExecuteParallelJob(const SUpdateInfo& in_rUpdateInfo) override
        {
            fpCMessageActorExecuteParallelJob(this, in_rUpdateInfo);
        }

        virtual bool ProcessMessage(Message& in_rMsg, bool in_Flag)
        {
            return false;
        }

        virtual IStateMachineMessageReceiver* GetStateMachineMessageReceiver(bool in_Flag)
        {
            return nullptr;
        }

#undef SendMessage

        bool SendMessage(const size_t in_ActorID, const boost::shared_ptr<Message>& in_spMsg, float in_Time = 0.0f)
        {
            return fpCMessageActorSendMessageByID(this, nullptr, 0, in_ActorID, in_spMsg, in_Time);
        }

        bool SendMessage(const Hedgehog::Base::CSharedString& in_rActorCategory, const boost::shared_ptr<Message>& in_spMsg, float in_Time = 0.0f)
        {
            return fpCMessageActorSendMessageByCategory(this, nullptr, 0, in_rActorCategory, in_spMsg, in_Time);
        }

        bool SendMessageImm(const size_t in_ActorID, const boost::shared_ptr<Message>& in_spMsg)
        {
            return fpCMessageActorSendMessageImmByID(this, nullptr, 0, in_ActorID, in_spMsg);
        }

        // Custom implementation that passes in a message on the *stack* if it's immediate. Much faster.
        bool SendMessageImm(CMessageActor* in_pActor, Message& in_rMsg) const
        {
            if (!m_pMessageManager)
                return false;

            if (!in_pActor)
                return false;

            if (!m_ActorIDCondition)
                in_rMsg.m_SenderActorID = m_ActorID;

            return fpCMessageActorProcessMessage(in_pActor, in_rMsg);
        }

        bool SendMessageImm(const uint32_t in_ActorID, Message& in_rMsg) const
        {
            if (!m_pMessageManager)
                return false;

            if (!in_ActorID)
                return false;

            CMessageActor* pActor = m_pMessageManager->GetMessageActor(in_ActorID);
            if (!pActor)
                return false;

            return SendMessageImm(pActor, in_rMsg);
        }

        bool SendMessageSelfImm(Message& in_rMsg)
        {
            if (!m_ActorIDCondition)
                in_rMsg.m_SenderActorID = m_ActorID;

            return fpCMessageActorProcessMessage(this, in_rMsg);
        }

        template<typename T>
        bool SendMessageSelfImm()
        {
            static_assert(std::is_base_of<Message, T>::value, "T must inherit from Message");

            auto spMsg = boost::make_shared<T>();
            return fpCMessageActorSendMessageImmByID(this, nullptr, 0, m_ActorID, spMsg);
        }

        template<typename T, typename... Args>
        bool SendMessageSelfImm(Args&... args)
        {
            static_assert(std::is_base_of<Message, T>::value, "T must inherit from Message");

            auto spMsg = boost::make_shared<T>(std::forward<Args>(args)...);
            return fpCMessageActorSendMessageImmByID(this, nullptr, 0, m_ActorID, spMsg);
        }

        template<typename T>
        bool SendMessageImm(const size_t in_ActorID)
        {
            static_assert(std::is_base_of<Message, T>::value, "T must inherit from Message");

            auto spMsg = boost::make_shared<T>();
            return fpCMessageActorSendMessageImmByID(this, nullptr, 0, in_ActorID, spMsg);
        }

        template<typename T, typename... Args>
        void SendMessageImm(const size_t in_ActorID, Args&... args)
        {
            static_assert(std::is_base_of<Message, T>::value, "T must inherit from Message");

            T msg(std::forward<Args>(args)...);
            SendMessageImm(in_ActorID, msg);
        }
    };

    BB_ASSERT_OFFSETOF(CMessageActor, m_ActorID, 0x2C);
    BB_ASSERT_OFFSETOF(CMessageActor, m_pMessageManager, 0x60);
    BB_ASSERT_SIZEOF(CMessageActor, 0x7C);
}

