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

    static inline BB_FUNCTION_PTR(void, __thiscall, fpCMessageActorSendMessageByID, 0x768340,
        CMessageActor* This, const char* in_pPath, size_t in_Line, size_t in_ActorID, const boost::shared_ptr<Message>& in_spMessage, float in_Time);   
    
    static inline BB_FUNCTION_PTR(void, __thiscall, fpCMessageActorSendMessageByCategory, 0x7684E0,
        CMessageActor* This, const char* in_pPath, size_t in_Line, const Hedgehog::Base::CSharedString& in_rActorCategory, const boost::shared_ptr<Message>& in_spMessage, float in_Time);

    static inline BB_FUNCTION_PTR(void, __thiscall, fpCMessageActorSendMessageImmByID, 0x767EE0,
        CMessageActor* This, const char* in_pPath, size_t in_Line, size_t in_ActorID, const boost::shared_ptr<Message>& in_spMessage);

    class CMessageActor : public IMessageProcess, public Base::CObject, public IParallelJob
    {
    public:
        BB_INSERT_PADDING(0x24);
        uint32_t m_ActorID;
        BB_INSERT_PADDING(0x30);
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

        void SendMessage(const size_t in_ActorID, const boost::shared_ptr<Message>& in_spMessage, float in_Time = 0.0f)
        {
            fpCMessageActorSendMessageByID(this, nullptr, 0, in_ActorID, in_spMessage, in_Time);
        }      
        
        void SendMessage(const Hedgehog::Base::CSharedString& in_rActorCategory, const boost::shared_ptr<Message>& in_spMessage, float in_Time = 0.0f)
        {
            fpCMessageActorSendMessageByCategory(this, nullptr, 0, in_rActorCategory, in_spMessage, in_Time);
        }      
        
        void SendMessageImm(const size_t in_ActorID, const boost::shared_ptr<Message>& in_spMessage)
        {
            fpCMessageActorSendMessageImmByID(this, nullptr, 0, in_ActorID, in_spMessage);
        }
    };

    BB_ASSERT_OFFSETOF(CMessageActor, m_ActorID, 0x2C);
    BB_ASSERT_OFFSETOF(CMessageActor, m_pMessageManager, 0x60);
    BB_ASSERT_SIZEOF(CMessageActor, 0x7C);
}

