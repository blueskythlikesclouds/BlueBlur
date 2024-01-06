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

    class CDatabase : public Base::CObject
    {
    public:
        BB_INSERT_PADDING(0xEC);

        virtual ~CDatabase() = default;

        static boost::shared_ptr<CDatabase> CreateDatabase(size_t in_Unknown = 0);

        boost::shared_ptr<CRawData> GetRawData(const Base::CSharedString& in_rName, uint32_t in_Unknown = 0);

        hh::vector<Hedgehog::Base::CSharedString> GetDatabaseDataNames() const;

        void AddArchiveList(const boost::shared_ptr<CArchiveList>& in_spArchiveList);
    };

    BB_ASSERT_SIZEOF(CDatabase, 0xF0);
}

#include <Hedgehog/Database/System/hhDatabase.inl>