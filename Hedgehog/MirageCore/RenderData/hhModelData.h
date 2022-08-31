#pragma once

#include <Hedgehog/Base/Container/hhVector.h>
#include <Hedgehog/Database/System/hhDatabaseData.h>

namespace Hedgehog::Mirage
{
    class CNodeGroupModelData;
    class CMeshData;
    class CModelNodeData;
    class CMatrixData;
    class CAabbData;
    class CSphereData;
    class CMorphModelData;

    class CModelData : public Database::CDatabaseData
    {
    public:
        size_t m_NodeGroupModelNum;
        size_t m_MorphModelNum;
        hh::vector<boost::shared_ptr<CNodeGroupModelData>> m_NodeGroupModels;
        hh::vector<boost::shared_ptr<CMeshData>> m_OpaqueMeshes;
        hh::vector<boost::shared_ptr<CMeshData>> m_PunchThroughMeshes;
        hh::vector<boost::shared_ptr<CMeshData>> m_TransparentMeshes;
        size_t m_NodeNum;
        boost::shared_ptr<uint8_t[]> m_spNodeParentIndices;
        boost::shared_ptr<CModelNodeData[]> m_spNodes;
        boost::shared_ptr<CMatrixData[]> m_spNodeMatrices;
        boost::shared_ptr<CAabbData> m_spAabb;
        boost::shared_ptr<CSphereData> m_spSphere;
        hh::vector<boost::shared_ptr<CMorphModelData>> m_MorphModels;
    };

    BB_ASSERT_OFFSETOF(CModelData, m_NodeGroupModelNum, 0xC);
    BB_ASSERT_OFFSETOF(CModelData, m_MorphModelNum, 0x10);
    BB_ASSERT_OFFSETOF(CModelData, m_NodeGroupModels, 0x14);
    BB_ASSERT_OFFSETOF(CModelData, m_OpaqueMeshes, 0x24);
    BB_ASSERT_OFFSETOF(CModelData, m_PunchThroughMeshes, 0x34);
    BB_ASSERT_OFFSETOF(CModelData, m_TransparentMeshes, 0x44);
    BB_ASSERT_OFFSETOF(CModelData, m_NodeNum, 0x54);
    BB_ASSERT_OFFSETOF(CModelData, m_spNodeParentIndices, 0x58);
    BB_ASSERT_OFFSETOF(CModelData, m_spNodes, 0x60);
    BB_ASSERT_OFFSETOF(CModelData, m_spNodeMatrices, 0x68);
    BB_ASSERT_OFFSETOF(CModelData, m_spAabb, 0x70);
    BB_ASSERT_OFFSETOF(CModelData, m_spSphere, 0x78);
    BB_ASSERT_OFFSETOF(CModelData, m_MorphModels, 0x80);
    BB_ASSERT_SIZEOF(CModelData, 0x90);
}