#pragma once

#include <Hedgehog/Base/hhObject.h>

#define HH_FND_MSG_MAKE_TYPE(name) \
    static constexpr const char* Type = (const char*)(name); \
    \
    bool IsOfType(const char* pType) const override \
    { \
        return pType == Type; \
    } \
    \
    const char* GetType() const override \
    { \
        return Type; \
    }

namespace Hedgehog::Universe
{
    class Message : public Base::CObject
    {
    public:
        uint32_t m_SenderActorID;
        boost::shared_ptr<const Message> m_spSelf;

        virtual ~Message() = default;

        virtual bool IsOfType(const char* pType) const = 0;
        virtual const char* GetType() const = 0;

        template<typename T>
        bool Is() const
        {
            return IsOfType(T::Type);
        }
    };

    BB_ASSERT_OFFSETOF(Message, m_SenderActorID, 0x4);
    BB_ASSERT_OFFSETOF(Message, m_spSelf, 0x8);
    BB_ASSERT_SIZEOF(Message, 0x10);

    class MessageTypeGet : public Message {};
    class MessageTypeSet : public Message {};
}