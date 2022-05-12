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
    };

    BB_ASSERT_SIZEOF(CDatabase, 0xF0);
}