#pragma once

#include <CSD/Manager/csdmRCPtr.h>

namespace Chao::CSD
{
    template<typename T>
    class CResourceBase
    {
    public:
        RCPtr<unsigned char> m_rcResourceHolder;
        T* m_pResource;

        virtual ~CResourceBase() = default;

        virtual void CopyResource(const CResourceBase& in_rOther);
    };

    BB_ASSERT_OFFSETOF(CResourceBase<void>, m_rcResourceHolder, 0x4);
    BB_ASSERT_OFFSETOF(CResourceBase<void>, m_pResource, 0xC);
    BB_ASSERT_SIZEOF(CResourceBase<void>, 0x10);
}

#include <CSD/Manager/csdmResourceBase.inl>