#pragma once

#include <Hedgehog/Base/hhObject.h>
#include <Hedgehog/Base/Type/hhSharedString.h>

namespace Hedgehog::Database
{
    class CDatabase;
}

namespace Hedgehog::Mirage
{
    class CGIMipLevelLimitationData;
    class CGITextureGroupInfoData;
    class CLightData;
    class CLightFieldTreeData;
    class CLightListData;
    class CLodModelData;
    class CMaterialData;
    class CModelData;
    class CPictureData;
    class CPixelShaderCodeData;
    class CPixelShaderData;
    class CPixelShaderParameterData;
    class CSceneData;
    class CShaderListData;
    class CTerrainBlockSphereTreeData;
    class CTerrainData;
    class CTerrainGroupData;
    class CTerrainInstanceInfoData;
    class CTerrainModelData;
    class CTexsetData;
    class CTextureData;
    class CVertexShaderCodeData;
    class CVertexShaderData;
    class CVertexShaderParameterData;
    class CVisibilityGridData;
    class CVisibilityGridInfoData;
    class CVisibilityTreeData;

    class CMirageDatabaseWrapper : public Hedgehog::Base::CObject
    {
    public:
        Hedgehog::Database::CDatabase* m_pDatabase;
        bool m_Flag;

        CMirageDatabaseWrapper(Hedgehog::Database::CDatabase* pDatabase);
        virtual ~CMirageDatabaseWrapper() = default;

        boost::shared_ptr<CGIMipLevelLimitationData> GetGIMipLevelLimitationData(const Hedgehog::Base::CSharedString& in_rName, size_t in_Unknown = 0);
        boost::shared_ptr<CGITextureGroupInfoData> GetGITextureGroupInfoData(const Hedgehog::Base::CSharedString& in_rName, size_t in_Unknown = 0);

        boost::shared_ptr<CLightData> GetLightData(const Hedgehog::Base::CSharedString& in_rName, size_t in_Unknown = 0);
        boost::shared_ptr<CLightFieldTreeData> GetLightFieldTreeData(const Hedgehog::Base::CSharedString& in_rName, size_t in_Unknown = 0);
        boost::shared_ptr<CLightListData> GetLightListData(const Hedgehog::Base::CSharedString& in_rName, size_t in_Unknown = 0);

        boost::shared_ptr<CLodModelData> GetLodModelData(const Hedgehog::Base::CSharedString& in_rName, size_t in_Unknown = 0);
        boost::shared_ptr<CMaterialData> GetMaterialData(const Hedgehog::Base::CSharedString& in_rName, size_t in_Unknown = 0);
        boost::shared_ptr<CModelData> GetModelData(const Hedgehog::Base::CSharedString& in_rName, size_t in_Unknown = 0);
        boost::shared_ptr<CPictureData> GetPictureData(const Hedgehog::Base::CSharedString& in_rName, size_t in_Unknown = 0);

        boost::shared_ptr<CPixelShaderCodeData> GetPixelShaderCodeData(const Hedgehog::Base::CSharedString& in_rName, size_t in_Unknown = 0);
        boost::shared_ptr<CPixelShaderData> GetPixelShaderData(const Hedgehog::Base::CSharedString& in_rName, size_t in_Unknown = 0);
        boost::shared_ptr<CPixelShaderParameterData> GetPixelShaderParameterData(const Hedgehog::Base::CSharedString& in_rName, size_t in_Unknown = 0);

        boost::shared_ptr<CSceneData> GetSceneData(const Hedgehog::Base::CSharedString& in_rName, size_t in_Unknown = 0);

        boost::shared_ptr<CShaderListData> GetShaderListData(const Hedgehog::Base::CSharedString& in_rName, size_t in_Unknown = 0);

        boost::shared_ptr<CTerrainBlockSphereTreeData> GetTerrainBlockSphereTreeData(const Hedgehog::Base::CSharedString& in_rName, size_t in_Unknown = 0);
        boost::shared_ptr<CTerrainData> GetTerrainData(const Hedgehog::Base::CSharedString& in_rName, size_t in_Unknown = 0);
        boost::shared_ptr<CTerrainGroupData> GetTerrainGroupData(const Hedgehog::Base::CSharedString& in_rName, size_t in_Unknown = 0);
        boost::shared_ptr<CTerrainInstanceInfoData> GetTerrainInstanceInfoData(const Hedgehog::Base::CSharedString& in_rName, size_t in_Unknown = 0);

        boost::shared_ptr<CTerrainModelData> GetTerrainModelData(const Hedgehog::Base::CSharedString& in_rName, size_t in_Unknown = 0);

        boost::shared_ptr<CTexsetData> GetTexsetData(const Hedgehog::Base::CSharedString& in_rName, size_t in_Unknown = 0);
        boost::shared_ptr<CTextureData> GetTextureData(const Hedgehog::Base::CSharedString& in_rName, size_t in_Unknown = 0);

        boost::shared_ptr<CVertexShaderCodeData> GetVertexShaderCodeData(const Hedgehog::Base::CSharedString& in_rName, size_t in_Unknown = 0);
        boost::shared_ptr<CVertexShaderData> GetVertexShaderData(const Hedgehog::Base::CSharedString& in_rName, size_t in_Unknown = 0);
        boost::shared_ptr<CVertexShaderParameterData> GetVertexShaderParameterData(const Hedgehog::Base::CSharedString& in_rName, size_t in_Unknown = 0);

        boost::shared_ptr<CVisibilityGridData> GetVisibilityGridData(const Hedgehog::Base::CSharedString& in_rName, size_t in_Unknown = 0);
        boost::shared_ptr<CVisibilityGridInfoData> GetVisibilityGridInfoData(const Hedgehog::Base::CSharedString& in_rName, size_t in_Unknown = 0);
        boost::shared_ptr<CVisibilityTreeData> GetVisibilityTreeData(const Hedgehog::Base::CSharedString& in_rName, size_t in_Unknown = 0);
    };

    BB_ASSERT_OFFSETOF(CMirageDatabaseWrapper, m_pDatabase, 0x4);
    BB_ASSERT_OFFSETOF(CMirageDatabaseWrapper, m_Flag, 0x8);
    BB_ASSERT_SIZEOF(CMirageDatabaseWrapper, 0xC);
}

#include <Hedgehog/MirageCore/RenderData/hhMirageDatabaseWrapper.inl>