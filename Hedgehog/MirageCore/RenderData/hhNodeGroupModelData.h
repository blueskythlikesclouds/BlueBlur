#pragma once

#include <Hedgehog/Base/Container/hhVector.h>
#include <Hedgehog/Base/Type/hhSharedString.h>
#include <Hedgehog/Database/System/hhDatabaseData.h>

namespace Hedgehog::Mirage
{
    class CMeshData;

    class CNodeGroupModelData : public Database::CDatabaseData
    {
    public:
        vector<boost::shared_ptr<CMeshData>> m_OpaqueMeshes;
        vector<boost::shared_ptr<CMeshData>> m_PunchThroughMeshes;
        vector<boost::shared_ptr<CMeshData>> m_TransparentMeshes;
        size_t m_SpecialMeshGroupNum;
        boost::shared_ptr<size_t[]> m_SpecialMeshGroupModes;
        vector<vector<boost::shared_ptr<CMeshData>>> m_SpecialMeshGroups;
        Base::CSharedString m_Name;
        bool m_Visible;
    };

    BB_ASSERT_OFFSETOF(CNodeGroupModelData, m_OpaqueMeshes, 0xC);
    BB_ASSERT_OFFSETOF(CNodeGroupModelData, m_PunchThroughMeshes, 0x1C);
    BB_ASSERT_OFFSETOF(CNodeGroupModelData, m_TransparentMeshes, 0x2C);
    BB_ASSERT_OFFSETOF(CNodeGroupModelData, m_SpecialMeshGroupNum, 0x3C);
    BB_ASSERT_OFFSETOF(CNodeGroupModelData, m_SpecialMeshGroupModes, 0x40);
    BB_ASSERT_OFFSETOF(CNodeGroupModelData, m_SpecialMeshGroups, 0x48);
    BB_ASSERT_OFFSETOF(CNodeGroupModelData, m_Name, 0x58);
    BB_ASSERT_OFFSETOF(CNodeGroupModelData, m_Visible, 0x5C);
    BB_ASSERT_SIZEOF(CNodeGroupModelData, 0x60);
}