#pragma once

#include <CSD/Manager/csdmRCPtr.h>

namespace Chao::CSD
{
    template<typename T>
    class CResourceBase
    {
    public:
        RCPtr<unsigned char> m_rcData;
        size_t m_DataSize;

        virtual ~CResourceBase() = default;

        virtual void CopyResource(const CResourceBase& in_rOther);
    };

    BB_ASSERT_OFFSETOF(CResourceBase<void>, m_rcData, 0x4);
    BB_ASSERT_OFFSETOF(CResourceBase<void>, m_DataSize, 0xC);
    BB_ASSERT_SIZEOF(CResourceBase<void>, 0x10);
}

#include <CSD/Manager/csdmResourceBase.inl>