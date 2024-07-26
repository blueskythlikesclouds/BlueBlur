namespace Hedgehog::Universe
{
    inline BB_FUNCTION_PTR(CMessageActor*, __thiscall, fpCMessageActorCtor, 0x768A00, CMessageActor* This);

    inline CMessageActor::CMessageActor() : CMessageActor(bb_null_ctor{})
    {
        fpCMessageActorCtor(this);
    }

    inline BB_FUNCTION_PTR(void, __thiscall, fpCMessageActorExecuteParallelJob, 0x7680C0, CMessageActor* This, const SUpdateInfo& in_rUpdateInfo);

    inline void CMessageActor::ExecuteParallelJob(const SUpdateInfo& in_rUpdateInfo)
    {
        fpCMessageActorExecuteParallelJob(this, in_rUpdateInfo);
    }

    inline BB_FUNCTION_PTR(bool, __thiscall, fpCMessageActorSendMessageByID, 0x768340,
        CMessageActor* This, const char* in_pPath, size_t in_Line, size_t in_ActorID, const boost::shared_ptr<Message>& in_spMsg, float in_Time);

    inline bool CMessageActor::SendMessage(const size_t in_ActorID, const boost::shared_ptr<Message>& in_spMsg,
        float in_Time)
    {
        return fpCMessageActorSendMessageByID(this, nullptr, 0, in_ActorID, in_spMsg, in_Time);
    }

    inline BB_FUNCTION_PTR(bool, __thiscall, fpCMessageActorSendMessageByCategory, 0x7684E0,
        CMessageActor* This, const char* in_pPath, size_t in_Line, const Hedgehog::Base::CSharedString& in_rActorCategory, const boost::shared_ptr<Message>& in_spMsg, float in_Time);

    inline bool CMessageActor::SendMessage(const Hedgehog::Base::CSharedString& in_rActorCategory,
        const boost::shared_ptr<Message>& in_spMsg, float in_Time)
    {
        return fpCMessageActorSendMessageByCategory(this, nullptr, 0, in_rActorCategory, in_spMsg, in_Time);
    }

    inline BB_FUNCTION_PTR(bool, __thiscall, fpCMessageActorSendMessageImmByID, 0x767EE0,
        CMessageActor* This, const char* in_pPath, size_t in_Line, size_t in_ActorID, const boost::shared_ptr<Message>& in_spMsg);

    inline bool CMessageActor::SendMessageImm(const size_t in_ActorID, const boost::shared_ptr<Message>& in_spMsg)
    {
        return fpCMessageActorSendMessageImmByID(this, nullptr, 0, in_ActorID, in_spMsg);
    }

    inline BB_FUNCTION_PTR(bool, __thiscall, fpCMessageActorProcessMessage, 0x767D20,
        CMessageActor* This, Message& in_rMsg);

    // Messages carry the actor ID of their sender meaning even if the message is discarded, it gets mutated and cannot be const.
    // Maintainer wants to avoid const_cast, so here's a workaround.
    // Note that the version of SendMessageImm that takes in a shared ptr takes in a *const* shared pointer,
    // so... we're really not doing anything different here...

    inline BB_FUNCTION_PTR(bool, __thiscall, fpCMessageActorProcessConstMessage, 0x767D20,
        CMessageActor* This, const Message& in_rMsg);

    static void __fastcall MessageSetActorID(Message& in_rMsg, const size_t in_ActorID)
    {
        in_rMsg.m_SenderActorID = in_ActorID;
    }
    static BB_FUNCTION_PTR(void, __fastcall, ConstMessageSetActorID, MessageSetActorID, const Message& in_rMsg, const size_t in_ActorID);

    // ---------------------------------------------------------------------------------------------------------------------------------

    inline bool CMessageActor::SendMessageImm(CMessageActor* in_pActor, Message& in_rMsg) const
    {
        if (!m_pMessageManager)
            return false;

        if (!in_pActor)
            return false;

        if (!m_ActorIDCondition)
            in_rMsg.m_SenderActorID = m_ActorID;

        return fpCMessageActorProcessMessage(in_pActor, in_rMsg);
    }
    inline bool CMessageActor::SendMessageImm(CMessageActor* in_pActor, const Message& in_rMsg) const
    {
        if (!m_pMessageManager)
            return false;

        if (!in_pActor)
            return false;

        if (!m_ActorIDCondition)
            ConstMessageSetActorID(in_rMsg, m_ActorID);

        return fpCMessageActorProcessConstMessage(in_pActor, in_rMsg);
    }
    inline bool CMessageActor::SendMessageImm(const uint32_t in_ActorID, Message& in_rMsg) const
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
    inline bool CMessageActor::SendMessageImm(const uint32_t in_ActorID, const Message& in_rMsg) const
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

    inline bool CMessageActor::SendMessageSelfImm(Message& in_rMsg)
    {
        if (!m_ActorIDCondition)
            in_rMsg.m_SenderActorID = m_ActorID;

        return fpCMessageActorProcessMessage(this, in_rMsg);
    }
    inline bool CMessageActor::SendMessageSelfImm(const Message& in_rMsg)
    {
        if (!m_ActorIDCondition)
            ConstMessageSetActorID(in_rMsg, m_ActorID);

        return fpCMessageActorProcessConstMessage(this, in_rMsg);
    }

    // Templated methods that might not work...
    // ----------------------------------------

    template <typename T>
    bool CMessageActor::SendMessageSelfImm()
    {
        static_assert(std::is_base_of<Message, T>::value, "T must inherit from Message");

        auto spMsg = boost::make_shared<T>();
        return fpCMessageActorSendMessageImmByID(this, nullptr, 0, m_ActorID, spMsg);
    }

    template <typename T, typename ... Args>
    bool CMessageActor::SendMessageSelfImm(Args&... args)
    {
        static_assert(std::is_base_of<Message, T>::value, "T must inherit from Message");

        auto spMsg = boost::make_shared<T>(std::forward<Args>(args)...);
        return fpCMessageActorSendMessageImmByID(this, nullptr, 0, m_ActorID, spMsg);
    }

    template <typename T>
    bool CMessageActor::SendMessageImm(const size_t in_ActorID)
    {
        static_assert(std::is_base_of<Message, T>::value, "T must inherit from Message");

        auto spMsg = boost::make_shared<T>();
        return fpCMessageActorSendMessageImmByID(this, nullptr, 0, in_ActorID, spMsg);
    }

    template <typename T, typename ... Args>
    void CMessageActor::SendMessageImm(const size_t in_ActorID, Args&... args)
    {
        static_assert(std::is_base_of<Message, T>::value, "T must inherit from Message");

        T msg(std::forward<Args>(args)...);
        SendMessageImm(in_ActorID, msg);
    }
}