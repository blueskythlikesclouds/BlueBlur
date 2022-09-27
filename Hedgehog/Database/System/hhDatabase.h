#pragma once

#include <Hedgehog/Base/hhObject.h>

namespace Hedgehog::Base
{
    class CSharedString;
}

namespace Hedgehog::Database
{
    class CDatabase;
    class CRawData;

    static inline BB_FUNCTION_PTR(void, __thiscall, fpCDatabaseGetRawData, 0x40F010,
        CDatabase* This, boost::shared_ptr<CRawData>& spRawData, const Hedgehog::Base::CSharedString& name, uint32_t unknown);

    static inline BB_FUNCTION_PTR(void, __thiscall, fpCDatabaseGetDatabaseDataNames, 0x692FD0,
        const CDatabase* This, hh::vector<Hedgehog::Base::CSharedString>& out_rDatabaseDataNames);

    class CDatabase : public Base::CObject
    {
    public:
        BB_INSERT_PADDING(0xEC);

        virtual ~CDatabase() = default;

        boost::shared_ptr<CRawData> GetRawData(const Base::CSharedString& name, uint32_t unknown = 0)
        {
            boost::shared_ptr<CRawData> spRawData;
            fpCDatabaseGetRawData(this, spRawData, name, unknown);
            return spRawData;
        }

        hh::vector<Hedgehog::Base::CSharedString> GetDatabaseDataNames() const
        {
            hh::vector<Hedgehog::Base::CSharedString> databaseDataNames;
            fpCDatabaseGetDatabaseDataNames(this, databaseDataNames);
            return databaseDataNames;
        }
    };

    BB_ASSERT_SIZEOF(CDatabase, 0xF0);
}