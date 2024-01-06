namespace Hedgehog::Database
{
    inline BB_FUNCTION_PTR(void, __thiscall, fpCArchiveListManagerGetArchiveList, 0x6AAF00,
        const CArchiveListManager* This, boost::shared_ptr<CArchiveList>& out_spArchiveList, const Base::CSharedString& in_rName);

    inline boost::shared_ptr<CArchiveList> CArchiveListManager::GetArchiveList(
        const Base::CSharedString& in_rName) const
    {
        boost::shared_ptr<CArchiveList> spArchiveList;
        fpCArchiveListManagerGetArchiveList(this, spArchiveList, in_rName);
        return spArchiveList;
    }

    inline BB_FUNCTION_PTR(void, __thiscall, fpCArchiveListManagerAddArchiveList, 0x6AB010,
        CArchiveListManager* This, const Base::CSharedString& in_rName, boost::shared_ptr<CArchiveList> in_spArchiveList);

    inline void CArchiveListManager::AddArchiveList(const Base::CSharedString& in_rName,
        const boost::shared_ptr<CArchiveList>& in_spArchiveList)
    {
        fpCArchiveListManagerAddArchiveList(this, in_rName, in_spArchiveList);
    }
}