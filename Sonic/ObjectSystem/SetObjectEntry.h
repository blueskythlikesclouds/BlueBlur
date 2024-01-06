#pragma once

#include <Hedgehog/Base/Type/hhSharedString.h>

namespace Sonic
{
    struct SSetObjectInfo;

    class CSetObjectEntry
    {
    public:
        boost::shared_ptr<SSetObjectInfo> m_spSetObjectInfo;
        Hedgehog::Base::CSharedString m_Name;

        CSetObjectEntry(const boost::shared_ptr<SSetObjectInfo>& in_spSetObjectInfo, const Hedgehog::Base::CSharedString& in_rName)
            : m_spSetObjectInfo(in_spSetObjectInfo), m_Name(in_rName)
        {
        }
    };

    BB_ASSERT_OFFSETOF(CSetObjectEntry, m_spSetObjectInfo, 0x0);
    BB_ASSERT_OFFSETOF(CSetObjectEntry, m_Name, 0x8);
    BB_ASSERT_SIZEOF(CSetObjectEntry, 0xC);
}