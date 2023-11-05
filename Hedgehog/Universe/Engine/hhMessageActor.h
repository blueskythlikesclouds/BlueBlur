#pragma once

#include <Hedgehog/Base/Type/hhSharedString.h>
#include <Hedgehog/Base/Thread/hhSynchronizedPtr.h>
#include <Hedgehog/Universe/Engine/hhMessageProcess.h>
#include <Hedgehog/Universe/Thread/hhParallelJob.h>

namespace Hedgehog::Universe
{
    class Message;
    class CMessageActor;
    class CMessageManager;
    class IStateMachineMessageReceiver;

    static inline BB_FUNCTION_PTR(CMessageActor*, __thiscall, fpCMessageActorCtor, 0x768A00, CMessageActor* This);

    static inline BB_FUNCTION_PTR(void, __thiscall, fpCMessageActorExecuteParallelJob, 0x7680C0, CMessageActor* This, const SUpdateInfo& in_rUpdateInfo);

    static inline BB_FUNCTION_PTR(bool, __thiscall, fpCMessageActorSendMessageByID, 0x768340,
        CMessageActor* This, const char* in_pPath, size_t in_Line, size_t in_ActorID, const boost::shared_ptr<Message>& in_spMessage, float in_Time);   
    
    static inline BB_FUNCTION_PTR(bool, __thiscall, fpCMessageActorSendMessageByCategory, 0x7684E0,
        CMessageActor* This, const char* in_pPath, size_t in_Line, const Hedgehog::Base::CSharedString& in_rActorCategory, const boost::shared_ptr<Message>& in_spMessage, float in_Time);

    static inline BB_FUNCTION_PTR(bool, __thiscall, fpCMessageActorSendMessageImmByID, 0x767EE0,
        CMessageActor* This, const char* in_pPath, size_t in_Line, size_t in_ActorID, const boost::shared_ptr<Message>& in_spMessage);

    static inline BB_FUNCTION_PTR(CMessageActor*, __thiscall, fpCMessageActorGetActorFromID, 0x7773B0, Hedgehog::Base::CSynchronizedObject* _Obj, uint32_t id);

    static inline BB_FUNCTION_PTR(bool, __thiscall, fpCMessageActorProcessMessage, 0x00767D20, const CMessageActor* a1, const Message& a2);

    class CMessageActor : public IMessageProcess, public Base::CObject, public IParallelJob
    {
    public:
        BB_INSERT_PADDING(0x24);
        uint32_t m_ActorID;
        BB_INSERT_PADDING(0x0A);
        bool m_ActorIDCondition;
        bool m_ActorIDCondition2;
        BB_INSERT_PADDING(0x24);
        CMessageManager* m_pMessageManager;
        BB_INSERT_PADDING(0x18);

        CMessageActor(const bb_null_ctor& nil) : IMessageProcess(nil), CObject(nil), IParallelJob(nil) {}

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

        CMessageActor* GetActorFromID(uint32_t in_ActorID) const
        {
            return fpCMessageActorGetActorFromID(Hedgehog::Base::CHolderBase((Base::CSynchronizedObject*)m_pMessageManager).get(), in_ActorID);
        }

        bool SendMessage(const size_t in_ActorID, const boost::shared_ptr<Message>& in_spMessage, float in_Time = 0.0f)
        {
            return fpCMessageActorSendMessageByID(this, nullptr, 0, in_ActorID, in_spMessage, in_Time);
        }

        bool SendMessage(const Hedgehog::Base::CSharedString& in_rActorCategory, const boost::shared_ptr<Message>& in_spMessage, float in_Time = 0.0f)
        {
            return fpCMessageActorSendMessageByCategory(this, nullptr, 0, in_rActorCategory, in_spMessage, in_Time);
        }

        bool SendMessageImm(const size_t actorID, const boost::shared_ptr<Message>& spMessage)
        {
            return fpCMessageActorSendMessageImmByID(this, nullptr, 0, actorID, spMessage);
        }

        // Custom implementation that passes in a message on the *stack* if it's immediate. Much faster.
        bool SendMessageImm(const CMessageActor* actor, Message* message) const
        {
            if (!m_pMessageManager)
                return false;

            if (!actor)
                return false;

            if (!m_ActorIDCondition)
                message->m_SenderActorID = m_ActorID;

            return fpCMessageActorProcessMessage(actor, *message);
        }

        bool SendMessageImm(const CMessageActor* actor, const Message& message) const
        {
            // Forgive the const cast, this is just to be compliant with Sonic Team's standards.
            // MessageTypeSet messages don't need to be variables you keep around, but they DO need the sender's ID associated with them.
            // Hence, const-cast to set the sender actor ID for a temporary object passed into this function.
            return SendMessageImm(actor, const_cast<Message*>(&message));
        }

        bool SendMessageImm(const uint32_t actorID, const Message& message)
        {
            if (!m_pMessageManager)
                return false;

            if (!actorID)
                return false;

            CMessageActor* target = GetActorFromID(actorID);
            if (!target)
                return false;

            return SendMessageImm(target, message);
        }

        bool SendMessageImm(const uint32_t actorID, Message* message)
        {
            if (!m_pMessageManager)
                return false;

            if (!actorID)
                return false;

            CMessageActor* target = GetActorFromID(actorID);
            if (!target)
                return false;

            return SendMessageImm(target, message);
        }

        bool SendMessageSelfImm(Message& message) const
        {
            if (!m_ActorIDCondition)
                message.m_SenderActorID = m_ActorID;

            return fpCMessageActorProcessMessage(this, message);
        }

        template<typename T>
        bool SendMessageSelfImm()
        {
            static_assert(std::is_base_of<Message, T>::value, "T must inherit from Message");
            auto actorID = this->m_ActorID;

            auto spMessage = boost::make_shared<T>();
            return fpCMessageActorSendMessageImmByID(this, nullptr, 0, actorID, spMessage);
        }

        template<typename T, typename ... V>
        bool SendMessageSelfImm(V& ... messageVars)
        {
            static_assert(std::is_base_of<Message, T>::value, "T must inherit from Message");
            auto actorID = this->m_ActorID;

            auto spMessage = boost::make_shared<T>(messageVars...);
            return fpCMessageActorSendMessageImmByID(this, nullptr, 0, actorID, spMessage);
        }

        template<typename T>
        bool SendMessageImm(const size_t actorID)
        {
            static_assert(std::is_base_of<Message, T>::value, "T must inherit from Message");

            auto spMessage = boost::make_shared<T>();
            return fpCMessageActorSendMessageImmByID(this, nullptr, 0, actorID, spMessage);
        }

        template<typename T, typename ... V>
        void SendMessageImm(const size_t actorID, V& ... messageVars)
        {
            static_assert(std::is_base_of<Message, T>::value, "T must inherit from Message");

            SendMessageImm(actorID, T(messageVars...));
        }
    };

    BB_ASSERT_OFFSETOF(CMessageActor, m_ActorID, 0x2C);
    BB_ASSERT_OFFSETOF(CMessageActor, m_pMessageManager, 0x60);
    BB_ASSERT_SIZEOF(CMessageActor, 0x7C);
}

