#pragma once

#include <Hedgehog/Base/hhObject.h>

namespace Hedgehog::Base
{
    class CSharedString;
}

namespace Hedgehog::Database
{
    class CArchiveList;
    class CDatabase;
    class CRawData;

    static inline BB_FUNCTION_PTR(void, __cdecl, fpCDatabaseCreateDatabase, 0x696C30, boost::shared_ptr<CDatabase>& out_spDatabase, size_t in_Unknown);
    
    static inline BB_FUNCTION_PTR(void, __thiscall, fpCDatabaseGetRawData, 0x40F010,
        CDatabase* This, boost::shared_ptr<CRawData>& out_spRawData, const Hedgehog::Base::CSharedString& in_rName, uint32_t in_Unknown);

    static inline BB_FUNCTION_PTR(void, __thiscall, fpCDatabaseGetDatabaseDataNames, 0x692FD0,
        const CDatabase* This, hh::vector<Hedgehog::Base::CSharedString>& out_rDatabaseDataNames);

    static inline BB_FUNCTION_PTR(void, __thiscall, fpCDatabaseAddArchiveList, 0x691900,
        CDatabase* This, const boost::shared_ptr<CArchiveList>& in_spArchiveList);

    class CDatabase : public Base::CObject
    {
    public:
        BB_INSERT_PADDING(0xEC);

        virtual ~CDatabase() = default;

        static boost::shared_ptr<CDatabase> CreateDatabase(size_t in_Unknown = 0)
        {
            boost::shared_ptr<CDatabase> spDatabase;
            fpCDatabaseCreateDatabase(spDatabase, in_Unknown);
            return spDatabase;
        }

        boost::shared_ptr<CRawData> GetRawData(const Base::CSharedString& in_rName, uint32_t in_Unknown = 0)
        {
            boost::shared_ptr<CRawData> spRawData;
            fpCDatabaseGetRawData(this, spRawData, in_rName, in_Unknown);
            return spRawData;
        }

        hh::vector<Hedgehog::Base::CSharedString> GetDatabaseDataNames() const
        {
            hh::vector<Hedgehog::Base::CSharedString> databaseDataNames;
            fpCDatabaseGetDatabaseDataNames(this, databaseDataNames);
            return databaseDataNames;
        }

        void AddArchiveList(const boost::shared_ptr<CArchiveList>& in_spArchiveList)
        {
            fpCDatabaseAddArchiveList(this, in_spArchiveList);
        }
    };

    BB_ASSERT_SIZEOF(CDatabase, 0xF0);
}