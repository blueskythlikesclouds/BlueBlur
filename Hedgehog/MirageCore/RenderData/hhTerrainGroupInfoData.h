#pragma once

#include <Hedgehog/Database/System/hhDatabaseData.h>
#include <Hedgehog/Math/hhSphere.h>

namespace Hedgehog::Mirage
{
    class CSphereData;

    class CTerrainGroupInfoData : public Database::CDatabaseData
    {
    public:
        Math::CSphere m_BoundingSphere;
        uint32_t m_MemorySize;
        Hedgehog::Base::CSharedString m_TerrainGroupName;
        uint32_t m_TerrainInstanceNum;
        boost::shared_ptr<CSphereData[]> m_spTerrainInstanceBoundingSpheres;
    };

    BB_ASSERT_OFFSETOF(CTerrainGroupInfoData, m_BoundingSphere, 0x10);
    BB_ASSERT_OFFSETOF(CTerrainGroupInfoData, m_MemorySize, 0x30);
    BB_ASSERT_OFFSETOF(CTerrainGroupInfoData, m_TerrainGroupName, 0x34);
    BB_ASSERT_OFFSETOF(CTerrainGroupInfoData, m_TerrainInstanceNum, 0x38);
    BB_ASSERT_OFFSETOF(CTerrainGroupInfoData, m_spTerrainInstanceBoundingSpheres, 0x3C);
    BB_ASSERT_SIZEOF(CTerrainGroupInfoData, 0x50);
}
