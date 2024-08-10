#pragma once

#include <Hedgehog/Base/Container/hhVector.h>
#include <Hedgehog/Database/System/hhDatabaseData.h>

namespace Hedgehog::Mirage
{
    class CTerrainGroupInfoData;

    class CTerrainData : public Database::CDatabaseData
    {
    public:
        hh::vector<boost::shared_ptr<CTerrainGroupInfoData>> m_TerrainGroupInfos;
    };

    BB_ASSERT_OFFSETOF(CTerrainData, m_TerrainGroupInfos, 0xC);
    BB_ASSERT_SIZEOF(CTerrainData, 0x1C);
}
