#pragma once

#include <BlueBlur.inl>

#include <Hedgehog/Base/hhRefCountObject.h>
#include <Hedgehog/Base/Type/hhSharedString.h>

namespace Sonic
{
    class CParamBase : public Hedgehog::Base::CRefCountObject
    {
    public:
        BB_INSERT_PADDING(0x4);
        Hedgehog::Base::CSharedString m_Name;
        BB_INSERT_PADDING(0x4);
    };

    BB_ASSERT_OFFSETOF(CParamBase, m_Name, 0xC);
    BB_ASSERT_SIZEOF(CParamBase, 0x14);
}
