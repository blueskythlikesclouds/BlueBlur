#pragma once

#include <Hedgehog/Database/System/hhDatabaseData.h>

namespace Hedgehog::Mirage
{
    class CTerrainModelData;

    class CTerrainInstanceInfoData : public Database::CDatabaseData
    {
    public:
        boost::shared_ptr<CTerrainModelData> m_spTerrainModel;
        BB_INSERT_PADDING(0x10);
        boost::scoped_ptr<Math::CMatrix44> m_scpTransform; // + pos + rot
        Base::CSharedString m_Name;
        BB_INSERT_PADDING(0x64);
    };

    BB_ASSERT_OFFSETOF(CTerrainInstanceInfoData, m_spTerrainModel, 0xC);
    BB_ASSERT_OFFSETOF(CTerrainInstanceInfoData, m_scpTransform, 0x24);
    BB_ASSERT_OFFSETOF(CTerrainInstanceInfoData, m_Name, 0x28);
    BB_ASSERT_SIZEOF(CTerrainInstanceInfoData, 0x90);
}
