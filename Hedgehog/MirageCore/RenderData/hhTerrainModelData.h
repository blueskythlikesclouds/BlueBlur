#pragma once

#include <Hedgehog/Base/Container/hhVector.h>
#include <Hedgehog/Database/System/hhDatabaseData.h>

namespace Hedgehog::Mirage
{
    class CSphereData;
    class CNodeGroupModelData;
    class CMeshData;

    class CTerrainModelData : public Database::CDatabaseData
    {
    public:
        Base::CSharedString m_Name;
        size_t m_Flags;
        hh::vector<boost::shared_ptr<CNodeGroupModelData>> m_NodeGroupModels;
        hh::vector<boost::shared_ptr<CMeshData>> m_OpaqueMeshes;
        hh::vector<boost::shared_ptr<CMeshData>> m_TransparentMeshes;
        hh::vector<boost::shared_ptr<CMeshData>> m_PunchThroughMeshes;
        boost::shared_ptr<CSphereData> m_spSphere;
    };

    BB_ASSERT_OFFSETOF(CTerrainModelData, m_Name, 0xC);
    BB_ASSERT_OFFSETOF(CTerrainModelData, m_Flags, 0x10);
    BB_ASSERT_OFFSETOF(CTerrainModelData, m_NodeGroupModels, 0x14);
    BB_ASSERT_OFFSETOF(CTerrainModelData, m_OpaqueMeshes, 0x24);
    BB_ASSERT_OFFSETOF(CTerrainModelData, m_TransparentMeshes, 0x34);
    BB_ASSERT_OFFSETOF(CTerrainModelData, m_PunchThroughMeshes, 0x44);
    BB_ASSERT_OFFSETOF(CTerrainModelData, m_spSphere, 0x54);
    BB_ASSERT_SIZEOF(CTerrainModelData, 0x5C);
}
