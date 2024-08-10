#pragma once

#include <Hedgehog/Base/Type/hhSharedString.h>

namespace Hedgehog::Database
{
    class CDatabase;
}

namespace Hedgehog::Motion
{
    class CLightMotionData;

    class CMotionDatabaseWrapper
    {
    public:
        Hedgehog::Database::CDatabase* m_pDatabase;

        CMotionDatabaseWrapper(Hedgehog::Database::CDatabase* in_pDatabase) : m_pDatabase(in_pDatabase) {}

        boost::shared_ptr<CLightMotionData> GetLightMotionData(const Base::CSharedString& in_rName, uint32_t in_Unknown = 0);
    };

    BB_ASSERT_OFFSETOF(CMotionDatabaseWrapper, m_pDatabase, 0x0);
    BB_ASSERT_SIZEOF(CMotionDatabaseWrapper, 0x4);
}

#include <Hedgehog/MotionCore/MotionData/hhMotionDatabaseWrapper.inl>