#pragma once

#include <Hedgehog/Database/System/hhDatabaseData.h>

namespace Hedgehog::Mirage
{
    class CTerrainModelData;
    class CTerrainInstanceInfoData;
    class CTerrainCullingStatusFlagsArray;
    class CLightListData;
    class CTerrainGroupData;

    class CTerrainInstanceSubsetData
    {
    public:
        uint32_t m_SubsetId;
        uint32_t m_CurrentState;
        uint32_t m_SavedState;
    };

    BB_ASSERT_OFFSETOF(CTerrainInstanceSubsetData, m_SubsetId, 0x0);
    BB_ASSERT_OFFSETOF(CTerrainInstanceSubsetData, m_CurrentState, 0x4);
    BB_ASSERT_OFFSETOF(CTerrainInstanceSubsetData, m_SavedState, 0x8);
    BB_ASSERT_SIZEOF(CTerrainInstanceSubsetData, 0xC);

    class CTerrainGroupSubsetData
    {
    public:
        BB_INSERT_PADDING(0x50); // all 0xFFs
        hh::vector<boost::shared_ptr<CTerrainInstanceSubsetData>> m_TerrainInstanceSubsets;
        CTerrainGroupData* m_pTerrainGroupData;
        uint32_t m_TerrainGroupSubsetIndex;
    };

    BB_ASSERT_OFFSETOF(CTerrainGroupSubsetData, m_TerrainInstanceSubsets, 0x50);
    BB_ASSERT_OFFSETOF(CTerrainGroupSubsetData, m_pTerrainGroupData, 0x60);
    BB_ASSERT_OFFSETOF(CTerrainGroupSubsetData, m_TerrainGroupSubsetIndex, 0x64);
    BB_ASSERT_SIZEOF(CTerrainGroupSubsetData, 0x68);

    class CTerrainGroupData : public Database::CDatabaseData
    {
    public:
        class CTerrainGroupDynamicData : public Database::CDatabaseData
        {
        public:
            boost::shared_ptr<CTerrainModelData>* m_pTerrainModels;
            boost::shared_ptr<boost::shared_ptr<CTerrainInstanceInfoData>[]>* m_pTerrainInstances;
            uint16_t m_TerrainModelNum;
        };

        uint32_t m_TerrainGroupIndex;
        uint32_t m_Field10; // increments by 0x40 in every terrain group
        boost::shared_ptr<CTerrainCullingStatusFlagsArray> m_spTerrainCullingStatusFlagsArray;
        boost::shared_ptr<CLightListData> m_spLightListData;
        uint32_t m_Field24;
        boost::shared_ptr<CTerrainGroupDynamicData> m_spTerrainGroupDynamicData;
        std::pair<const char**, size_t>* m_pTerrainInstances;
        CTerrainGroupSubsetData* m_pTerrainGroupSubsets; // x terrain instance num
        uint32_t m_TerrainInstanceNum;
        boost::shared_ptr<Hedgehog::Base::CSharedString[]> m_spTerrainModelNames;
        uint32_t m_TerrainModelNum;
        boost::shared_ptr<CTerrainInstanceSubsetData> m_spTerrainInstanceSubsetData;
    };

    BB_ASSERT_OFFSETOF(CTerrainGroupData::CTerrainGroupDynamicData, m_pTerrainModels, 0xC);
    BB_ASSERT_OFFSETOF(CTerrainGroupData::CTerrainGroupDynamicData, m_pTerrainInstances, 0x10);
    BB_ASSERT_OFFSETOF(CTerrainGroupData::CTerrainGroupDynamicData, m_TerrainModelNum, 0x14);
    BB_ASSERT_SIZEOF(CTerrainGroupData::CTerrainGroupDynamicData, 0x18);

    BB_ASSERT_OFFSETOF(CTerrainGroupData, m_TerrainGroupIndex, 0xC);
    BB_ASSERT_OFFSETOF(CTerrainGroupData, m_Field10, 0x10);
    BB_ASSERT_OFFSETOF(CTerrainGroupData, m_spTerrainCullingStatusFlagsArray, 0x14);
    BB_ASSERT_OFFSETOF(CTerrainGroupData, m_spLightListData, 0x1C);
    BB_ASSERT_OFFSETOF(CTerrainGroupData, m_Field24, 0x24);
    BB_ASSERT_OFFSETOF(CTerrainGroupData, m_spTerrainGroupDynamicData, 0x28);
    BB_ASSERT_OFFSETOF(CTerrainGroupData, m_pTerrainInstances, 0x30);
    BB_ASSERT_OFFSETOF(CTerrainGroupData, m_pTerrainGroupSubsets, 0x34);
    BB_ASSERT_OFFSETOF(CTerrainGroupData, m_TerrainInstanceNum, 0x38);
    BB_ASSERT_OFFSETOF(CTerrainGroupData, m_spTerrainModelNames, 0x3C);
    BB_ASSERT_OFFSETOF(CTerrainGroupData, m_TerrainModelNum, 0x44);
    BB_ASSERT_OFFSETOF(CTerrainGroupData, m_spTerrainInstanceSubsetData, 0x48);
    BB_ASSERT_SIZEOF(CTerrainGroupData, 0x50);
}
