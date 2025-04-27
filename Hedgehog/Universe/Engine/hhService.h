#pragma once

#include <Hedgehog/Base/hhObject.h>

#define HH_FND_MSG_MAKE_SERVICE(name, id) \
    static constexpr const char* ms_pType = (const char*)(name); \
    static constexpr uint32_t ms_ID = id; \
    \
    const char* GetType() const override \
    { \
        return ms_pType; \
    } \
    \
    bool IsOfType(const char* in_pType) const override \
    { \
        return in_pType == ms_pType; \
    }

namespace Hedgehog::Universe
{
    class CService : public Base::CObject
    {
    public:
        virtual ~CService() = default;

        virtual const char* GetType() const = 0;
        virtual bool IsOfType(const char* in_pType) const = 0;

        template<typename T>
        bool Is() const
        {
            return IsOfType(T::ms_pType);
        }
    };
}