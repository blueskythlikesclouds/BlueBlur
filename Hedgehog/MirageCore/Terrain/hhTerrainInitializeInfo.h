#pragma once

#include <Hedgehog/Base/Container/hhMap.h>

namespace Hedgehog::Base
{
    class CCriticalSectionD3D9;
}

namespace Hedgehog::Mirage
{
    class CTerrainData;
    class CTerrainGroupSubsetInfo;

    struct STerrainInitializeInfo
    {
        BB_INSERT_PADDING(0x11C);
        boost::shared_ptr<CTerrainData> spTerrainData;
        BB_INSERT_PADDING(0x38);
        boost::shared_ptr<Base::CCriticalSectionD3D9> spCriticalSection;
        hh::map<uint32_t, boost::shared_ptr<CTerrainGroupSubsetInfo>> TerrainGroupSubsetLoadStates;
        hh::map<uint32_t, boost::shared_ptr<CTerrainGroupSubsetInfo>> TerrainGroupSubsetVisibilityStates;
        BB_INSERT_PADDING(0x4);
    };

    BB_ASSERT_OFFSETOF(STerrainInitializeInfo, spTerrainData, 0x11C);
    BB_ASSERT_OFFSETOF(STerrainInitializeInfo, spCriticalSection, 0x15C);
    BB_ASSERT_OFFSETOF(STerrainInitializeInfo, TerrainGroupSubsetLoadStates, 0x164);
    BB_ASSERT_OFFSETOF(STerrainInitializeInfo, TerrainGroupSubsetVisibilityStates, 0x170);
    BB_ASSERT_SIZEOF(STerrainInitializeInfo, 0x180);
}