#pragma once

#include <Hedgehog/Base/Type/hhSharedString.h>
#include <Hedgehog/Base/hhObject.h>

namespace Hedgehog::Yggdrasill
{
    class CYggScheduler;

    class CYggAbstractBuffer : public Base::CObject
    {
    public:
        BB_INSERT_PADDING(0x8);
        CYggScheduler* m_pScheduler;
        Base::CSharedString m_Name;
        BB_INSERT_PADDING(0x1);
        bool m_AutoReset;
        BB_INSERT_PADDING(0x6);

        virtual ~CYggAbstractBuffer() = default;
    };

    BB_ASSERT_OFFSETOF(CYggAbstractBuffer, m_pScheduler, 0xC);
    BB_ASSERT_OFFSETOF(CYggAbstractBuffer, m_Name, 0x10);
    BB_ASSERT_OFFSETOF(CYggAbstractBuffer, m_AutoReset, 0x15);
    BB_ASSERT_SIZEOF(CYggAbstractBuffer, 0x1C);
}