#pragma once

#include <CSD/Manager/csdmBase.h>
#include <CSD/Manager/csdmRCPtr.h>

namespace Chao::CSD
{
    class CTexList : public CBase
    {
    public:
        RCPtr<unsigned char> m_rcData;

        virtual ~CTexList() = default;
    };

    BB_ASSERT_OFFSETOF(CTexList, m_rcData, 0x4);
    BB_ASSERT_SIZEOF(CTexList, 0xC);
}