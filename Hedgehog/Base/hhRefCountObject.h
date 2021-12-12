#pragma once

#include <BlueBlur.inl>
#include <Hedgehog/Base/hhObject.h>

namespace Hedgehog::Base
{
    class CRefCountObject;

    static inline BB_FUNCTION_PTR(LONG, __thiscall, fpCRefCountObjectAddRef, 0x660180, CRefCountObject* This);
    static inline BB_FUNCTION_PTR(LONG, __thiscall, fpCRefCountObjectRelease, 0x660190, CRefCountObject* This);

    class CRefCountObject
    {
    public:
        uint32_t m_RefCount;

        virtual ~CRefCountObject() = default;

        LONG AddRef()
        {
            return fpCRefCountObjectAddRef(this);
        }

        LONG Release()
        {
            return fpCRefCountObjectRelease(this);
        }
    };

    BB_ASSERT_OFFSETOF(CRefCountObject, m_RefCount, 0x4);
    BB_ASSERT_SIZEOF(CRefCountObject, 0x8);
}