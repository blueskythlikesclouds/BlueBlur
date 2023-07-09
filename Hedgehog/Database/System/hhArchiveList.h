#pragma once

#include <Hedgehog/Base/hhObject.h>

namespace Hedgehog::Database
{
    class CDatabaseData;

    class CArchiveList : public Base::CObject
    {
    public:
        boost::shared_ptr<Base::CCriticalSectionD3D9> m_spCriticalSection;
        hh::map<Base::CSharedString, boost::shared_ptr<CDatabaseData>> m_DatabaseEntryMap; // TODO: value type is wrong
        bool m_Loaded;
        hh::vector<uint32_t> m_ArchiveSizes;

        CArchiveList(); // 0x6AA7D0
        ~CArchiveList(); // 0x69D9D0
    };

    BB_ASSERT_OFFSETOF(CArchiveList, m_spCriticalSection, 0x0);
    BB_ASSERT_OFFSETOF(CArchiveList, m_DatabaseEntryMap, 0x8);
    BB_ASSERT_OFFSETOF(CArchiveList, m_Loaded, 0x14);
    BB_ASSERT_OFFSETOF(CArchiveList, m_ArchiveSizes, 0x18);
    BB_ASSERT_SIZEOF(CArchiveList, 0x28);
}