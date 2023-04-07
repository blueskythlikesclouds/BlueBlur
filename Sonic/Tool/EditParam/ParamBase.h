#pragma once

#include <Hedgehog/Base/hhRefCountObject.h>
#include <Hedgehog/Base/Type/hhSharedString.h>

namespace Sonic
{
    class CParamBase : public Hedgehog::Base::CRefCountObject
    {
    public:
        uint8_t m_Field8;
        Hedgehog::Base::CSharedString m_Name;
        uint8_t m_Field10;
    };

    BB_ASSERT_OFFSETOF(CParamBase, m_Field8, 0x8);
    BB_ASSERT_OFFSETOF(CParamBase, m_Name, 0xC);
    BB_ASSERT_OFFSETOF(CParamBase, m_Field10, 0x10);
    BB_ASSERT_SIZEOF(CParamBase, 0x14);
}
