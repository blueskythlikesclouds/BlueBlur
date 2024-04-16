#pragma once

#include <Hedgehog/Database/System/hhDatabaseData.h>

namespace Hedgehog::Mirage
{
    class CTerrainModelData;
    class CTerrainGroupSubsetData;

    class CTerrainInstanceInfoData : public Database::CDatabaseData
    {
    public:
        boost::shared_ptr<CTerrainModelData> m_spTerrainModel;
        BB_INSERT_PADDING(0x8);
        uint32_t m_TerrainInstanceSubsetIndex;
        BB_INSERT_PADDING(0x4);
        boost::scoped_ptr<Math::CMatrix44> m_scpTransform; // + pos + rot
        Base::CSharedString m_Name;
        BB_INSERT_PADDING(0x5C);
        CTerrainGroupSubsetData* m_pTerrainGroupSubsetData;
        BB_INSERT_PADDING(0x4); // same as m_TerrainInstanceSubsetIndex
    };

    BB_ASSERT_OFFSETOF(CTerrainInstanceInfoData, m_spTerrainModel, 0xC);
    BB_ASSERT_OFFSETOF(CTerrainInstanceInfoData, m_TerrainInstanceSubsetIndex, 0x1C);
    BB_ASSERT_OFFSETOF(CTerrainInstanceInfoData, m_scpTransform, 0x24);
    BB_ASSERT_OFFSETOF(CTerrainInstanceInfoData, m_Name, 0x28);
    BB_ASSERT_OFFSETOF(CTerrainInstanceInfoData, m_pTerrainGroupSubsetData, 0x88);
    BB_ASSERT_SIZEOF(CTerrainInstanceInfoData, 0x90);
}