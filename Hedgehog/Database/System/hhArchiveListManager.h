#pragma once

#include <Hedgehog/Base/hhObject.h>
#include <Hedgehog/Base/Container/hhMap.h>
#include <Hedgehog/Base/Platform/D3D9/hhCriticalSectionD3D9.h>

namespace Hedgehog::Database
{
    class CArchiveList;
    class CArchiveListManager;

    static inline BB_FUNCTION_PTR(void, __thiscall, fpCArchiveListManagerGetArchiveList, 0x6AAF00,
        const CArchiveListManager* This, boost::shared_ptr<CArchiveList>& out_spArchiveList, const Base::CSharedString& in_rName);

    static inline BB_FUNCTION_PTR(void, __thiscall, fpCArchiveListManagerAddArchiveList, 0x6AB010,
        CArchiveListManager* This, const Base::CSharedString& in_rName, boost::shared_ptr<CArchiveList> in_spArchiveList);

    class CArchiveListManager : public Base::CObject
    {
    public:
        hh::map<Base::CSharedString, boost::shared_ptr<CArchiveList>> m_ArchiveListMap;
        boost::shared_ptr<Base::CCriticalSectionD3D9> m_spCriticalSection;

        boost::shared_ptr<CArchiveList> GetArchiveList(const Base::CSharedString& in_rName) const
        {
            boost::shared_ptr<CArchiveList> spArchiveList;
            fpCArchiveListManagerGetArchiveList(this, spArchiveList, in_rName);
            return spArchiveList;
        }

        void AddArchiveList(const Base::CSharedString& in_rName, const boost::shared_ptr<CArchiveList>& in_spArchiveList)
        {
            fpCArchiveListManagerAddArchiveList(this, in_rName, in_spArchiveList);
        }
    };

    BB_ASSERT_OFFSETOF(CArchiveListManager, m_ArchiveListMap, 0x0);
    BB_ASSERT_OFFSETOF(CArchiveListManager, m_spCriticalSection, 0xC);
    BB_ASSERT_SIZEOF(CArchiveListManager, 0x14);
}