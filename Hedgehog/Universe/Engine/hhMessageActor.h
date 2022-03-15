#pragma once

#include <Hedgehog/Base/Type/hhSharedString.h>
#include <Hedgehog/Universe/Engine/hhMessageProcess.h>
#include <Hedgehog/Universe/Thread/hhParallelJob.h>

namespace Hedgehog::Universe
{
    class Message;
    class CMessageActor;
    class IStateMachineMessageReceiver;

    static inline BB_FUNCTION_PTR(CMessageActor*, __thiscall, fpCMessageActorCtor, 0x768A00, CMessageActor* This);

    static inline BB_FUNCTION_PTR(void, __thiscall, fpCMessageActorExecuteParallelJob, 0x7680C0, CMessageActor* This, const SUpdateInfo& updateInfo);

    static inline BB_FUNCTION_PTR(void, __thiscall, fpCMessageActorSendMessageByID, 0x768340,
        CMessageActor* This, const char* path, size_t line, size_t actorID, const boost::shared_ptr<Message>& spMessage, float time);   
    
    static inline BB_FUNCTION_PTR(void, __thiscall, fpCMessageActorSendMessageByCategory, 0x7684E0,
        CMessageActor* This, const char* path, size_t line, const Hedgehog::Base::CSharedString& actorCategory, const boost::shared_ptr<Message>& spMessage, float time);

    static inline BB_FUNCTION_PTR(void, __thiscall, fpCMessageActorSendMessageImmByID, 0x767EE0,
        CMessageActor* This, const char* path, size_t line, size_t actorID, const boost::shared_ptr<Message>& spMessage);

    class CMessageActor : public IMessageProcess, public Base::CObject, public IParallelJob
    {
    public:
        BB_INSERT_PADDING(0x24);
        uint32_t m_ActorID;
        BB_INSERT_PADDING(0x4C);

        CMessageActor(const bb_null_ctor&) : IMessageProcess(bb_null_ctor{}), CObject(bb_null_ctor{}), IParallelJob(bb_null_ctor{}) {}

        CMessageActor() : CMessageActor(bb_null_ctor{})
        {
            fpCMessageActorCtor(this);
        }

        virtual ~CMessageActor();

        virtual void ExecuteParallelJob(const SUpdateInfo& updateInfo) override
        {
            fpCMessageActorExecuteParallelJob(this, updateInfo);
        }

        virtual bool ProcessMessage(Message& message, bool flag)
        {
            return false;
        }

        virtual IStateMachineMessageReceiver* GetStateMachineMessageReceiver(bool flag)
        {
            return nullptr;
        }

#undef SendMessage

        void SendMessage(const size_t actorID, const boost::shared_ptr<Message>& spMessage, float time = 0.0f)
        {
            fpCMessageActorSendMessageByID(this, nullptr, 0, actorID, spMessage, time);
        }      
        
        void SendMessage(const Hedgehog::Base::CSharedString& actorCategory, const boost::shared_ptr<Message>& spMessage, float time = 0.0f)
        {
            fpCMessageActorSendMessageByCategory(this, nullptr, 0, actorCategory, spMessage, time);
        }      
        
        void SendMessageImm(const size_t actorID, const boost::shared_ptr<Message>& spMessage)
        {
            fpCMessageActorSendMessageImmByID(this, nullptr, 0, actorID, spMessage);
        }
    };

    //BB_ASSERT_OFFSETOF(CMessageActor, m_Category, 0x14);
    BB_ASSERT_OFFSETOF(CMessageActor, m_ActorID, 0x2C);
    BB_ASSERT_SIZEOF(CMessageActor, 0x7C);
}

