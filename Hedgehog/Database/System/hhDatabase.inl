namespace Hedgehog::Database
{
    inline BB_FUNCTION_PTR(void, __cdecl, fpCDatabaseCreateDatabase, 0x696C30, boost::shared_ptr<CDatabase>& out_spDatabase, size_t in_Unknown);

    inline boost::shared_ptr<CDatabase> CDatabase::CreateDatabase(size_t in_Unknown)
    {
        boost::shared_ptr<CDatabase> spDatabase;
        fpCDatabaseCreateDatabase(spDatabase, in_Unknown);
        return spDatabase;
    }

    inline BB_FUNCTION_PTR(void, __thiscall, fpCDatabaseGetRawData, 0x40F010,
        CDatabase* This, boost::shared_ptr<CRawData>& out_spRawData, const Hedgehog::Base::CSharedString& in_rName, uint32_t in_Unknown);

    inline boost::shared_ptr<CRawData> CDatabase::GetRawData(const Base::CSharedString& in_rName, uint32_t in_Unknown)
    {
        boost::shared_ptr<CRawData> spRawData;
        fpCDatabaseGetRawData(this, spRawData, in_rName, in_Unknown);
        return spRawData;
    }

    inline BB_FUNCTION_PTR(void, __thiscall, fpCDatabaseGetDatabaseDataNames, 0x692FD0,
        const CDatabase* This, hh::vector<Hedgehog::Base::CSharedString>& out_rDatabaseDataNames);

    inline hh::vector<Hedgehog::Base::CSharedString> CDatabase::GetDatabaseDataNames() const
    {
        hh::vector<Hedgehog::Base::CSharedString> databaseDataNames;
        fpCDatabaseGetDatabaseDataNames(this, databaseDataNames);
        return databaseDataNames;
    }

    inline BB_FUNCTION_PTR(void, __thiscall, fpCDatabaseAddArchiveList, 0x691900,
        CDatabase* This, const boost::shared_ptr<CArchiveList>& in_spArchiveList);

    inline void CDatabase::AddArchiveList(const boost::shared_ptr<CArchiveList>& in_spArchiveList)
    {
        fpCDatabaseAddArchiveList(this, in_spArchiveList);
    }
}