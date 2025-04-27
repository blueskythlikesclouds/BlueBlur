namespace Hedgehog::Mirage
{
    inline BB_FUNCTION_PTR(void, __thiscall, fpCMirageDatabaseWrapperCtor, 0x72EE30,
        CMirageDatabaseWrapper* This, Hedgehog::Database::CDatabase* pDatabase);

    inline BB_FUNCTION_PTR(void, __thiscall, fpCMirageDatabaseWrapperGetGIMipLevelLimitationData, 0x72EEC0,
        CMirageDatabaseWrapper* This, boost::shared_ptr<CGIMipLevelLimitationData>& out_spGIMipLevelLimitationData, const Hedgehog::Base::CSharedString& in_rName, size_t in_Unknown);

    inline BB_FUNCTION_PTR(void, __thiscall, fpCMirageDatabaseWrapperGetGITextureGroupInfoData, 0x72EE60,
        CMirageDatabaseWrapper* This, boost::shared_ptr<CGITextureGroupInfoData>& out_spGITextureGroupInfoData, const Hedgehog::Base::CSharedString& in_rName, size_t in_Unknown);

    inline BB_FUNCTION_PTR(void, __thiscall, fpCMirageDatabaseWrapperGetLightData, 0x72EF20,
        CMirageDatabaseWrapper* This, boost::shared_ptr<CLightData>& out_spLightData, const Hedgehog::Base::CSharedString& in_rName, size_t in_Unknown);

    inline BB_FUNCTION_PTR(void, __thiscall, fpCMirageDatabaseWrapperGetLightFieldTreeData, 0x72F2F0,
        CMirageDatabaseWrapper* This, boost::shared_ptr<CLightFieldTreeData>& out_spLightFieldTreeData, const Hedgehog::Base::CSharedString& in_rName, size_t in_Unknown);

    inline BB_FUNCTION_PTR(void, __thiscall, fpCMirageDatabaseWrapperGetLightListData, 0x72F6F0,
        CMirageDatabaseWrapper* This, boost::shared_ptr<CLightListData>& out_spLightListData, const Hedgehog::Base::CSharedString& in_rName, size_t in_Unknown);

    inline BB_FUNCTION_PTR(void, __thiscall, fpCMirageDatabaseWrapperGetLodModelData, 0x72F290,
        CMirageDatabaseWrapper* This, boost::shared_ptr<CLodModelData>& out_spLodModelData, const Hedgehog::Base::CSharedString& in_rName, size_t in_Unknown);

    inline BB_FUNCTION_PTR(void, __thiscall, fpCMirageDatabaseWrapperGetMaterialData, 0x72EF80,
        CMirageDatabaseWrapper* This, boost::shared_ptr<CMaterialData>& out_spMaterialData, const Hedgehog::Base::CSharedString& in_rName, size_t in_Unknown);

    inline BB_FUNCTION_PTR(void, __thiscall, fpCMirageDatabaseWrapperGetModelData, 0x72F810,
        CMirageDatabaseWrapper* This, boost::shared_ptr<CModelData>& out_spModelData, const Hedgehog::Base::CSharedString& in_rName, size_t in_Unknown);

    inline BB_FUNCTION_PTR(void, __thiscall, fpCMirageDatabaseWrapperGetPictureData, 0x72EFE0,
        CMirageDatabaseWrapper* This, boost::shared_ptr<CPictureData>& out_spPictureData, const Hedgehog::Base::CSharedString& in_rName, size_t in_Unknown);

    inline BB_FUNCTION_PTR(void, __thiscall, fpCMirageDatabaseWrapperGetPixelShaderCodeData, 0x72F350,
        CMirageDatabaseWrapper* This, boost::shared_ptr<CPixelShaderCodeData>& out_spPixelShaderCodeData, const Hedgehog::Base::CSharedString& in_rName, size_t in_Unknown);

    inline BB_FUNCTION_PTR(void, __thiscall, fpCMirageDatabaseWrapperGetPixelShaderData, 0x72F4F0,
        CMirageDatabaseWrapper* This, boost::shared_ptr<CPixelShaderData>& out_spPixelShaderData, const Hedgehog::Base::CSharedString& in_rName, size_t in_Unknown);

    inline BB_FUNCTION_PTR(void, __thiscall, fpCMirageDatabaseWrapperGetPixelShaderParameterData, 0x72F8E0,
        CMirageDatabaseWrapper* This, boost::shared_ptr<CPixelShaderParameterData>& out_spPixelShaderParameterData, const Hedgehog::Base::CSharedString& in_rName, size_t in_Unknown);

    inline BB_FUNCTION_PTR(void, __thiscall, fpCMirageDatabaseWrapperGetSceneData, 0x72F750,
        CMirageDatabaseWrapper* This, boost::shared_ptr<CSceneData>& out_spSceneData, const Hedgehog::Base::CSharedString& in_rName, size_t in_Unknown);

    inline BB_FUNCTION_PTR(void, __thiscall, fpCMirageDatabaseWrapperGetShaderListData, 0x72F040,
        CMirageDatabaseWrapper* This, boost::shared_ptr<CShaderListData>& out_spShaderListData, const Hedgehog::Base::CSharedString& in_rName, size_t in_Unknown);

    inline BB_FUNCTION_PTR(void, __thiscall, fpCMirageDatabaseWrapperGetTerrainBlockSphereTreeData, 0x72F3C0,
        CMirageDatabaseWrapper* This, boost::shared_ptr<CTerrainBlockSphereTreeData>& out_spTerrainBlockSphereTreeData, const Hedgehog::Base::CSharedString& in_rName, size_t in_Unknown);

    inline BB_FUNCTION_PTR(void, __thiscall, fpCMirageDatabaseWrapperGetTerrainData, 0x72F7B0,
        CMirageDatabaseWrapper* This, boost::shared_ptr<CTerrainData>& out_spTerrainData, const Hedgehog::Base::CSharedString& in_rName, size_t in_Unknown);

    inline BB_FUNCTION_PTR(void, __thiscall, fpCMirageDatabaseWrapperGetTerrainGroupData, 0x72F0B0,
        CMirageDatabaseWrapper* This, boost::shared_ptr<CTerrainGroupData>& out_spTerrainGroupData, const Hedgehog::Base::CSharedString& in_rName, size_t in_Unknown);

    inline BB_FUNCTION_PTR(void, __thiscall, fpCMirageDatabaseWrapperGetTerrainInstanceInfoData, 0x72F110,
        CMirageDatabaseWrapper* This, boost::shared_ptr<CTerrainInstanceInfoData>& out_spTerrainInstanceInfoData, const Hedgehog::Base::CSharedString& in_rName, size_t in_Unknown);

    inline BB_FUNCTION_PTR(void, __thiscall, fpCMirageDatabaseWrapperGetTerrainModelData, 0x72F170,
        CMirageDatabaseWrapper* This, boost::shared_ptr<CTerrainModelData>& out_spTerrainModelData, const Hedgehog::Base::CSharedString& in_rName, size_t in_Unknown);

    inline BB_FUNCTION_PTR(void, __thiscall, fpCMirageDatabaseWrapperGetTexsetData, 0x72F1D0,
        CMirageDatabaseWrapper* This, boost::shared_ptr<CTexsetData>& out_spTexsetData, const Hedgehog::Base::CSharedString& in_rName, size_t in_Unknown);

    inline BB_FUNCTION_PTR(void, __thiscall, fpCMirageDatabaseWrapperGetTextureData, 0x72F230,
        CMirageDatabaseWrapper* This, boost::shared_ptr<CTextureData>& out_spTextureData, const Hedgehog::Base::CSharedString& in_rName, size_t in_Unknown);

    inline BB_FUNCTION_PTR(void, __thiscall, fpCMirageDatabaseWrapperGetVertexShaderCodeData, 0x72F420,
        CMirageDatabaseWrapper* This, boost::shared_ptr<CVertexShaderCodeData>& out_spVertexShaderCodeData, const Hedgehog::Base::CSharedString& in_rName, size_t in_Unknown);

    inline BB_FUNCTION_PTR(void, __thiscall, fpCMirageDatabaseWrapperGetVertexShaderData, 0x72F560,
        CMirageDatabaseWrapper* This, boost::shared_ptr<CVertexShaderData>& out_spVertexShaderData, const Hedgehog::Base::CSharedString& in_rName, size_t in_Unknown);

    inline BB_FUNCTION_PTR(void, __thiscall, fpCMirageDatabaseWrapperGetVertexShaderParameterData, 0x72F870,
        CMirageDatabaseWrapper* This, boost::shared_ptr<CVertexShaderParameterData>& out_spVertexShaderParameterData, const Hedgehog::Base::CSharedString& in_rName, size_t in_Unknown);

    inline BB_FUNCTION_PTR(void, __thiscall, fpCMirageDatabaseWrapperGetVisibilityGridData, 0x72F630,
        CMirageDatabaseWrapper* This, boost::shared_ptr<CVisibilityGridData>& out_spVisibilityGridData, const Hedgehog::Base::CSharedString& in_rName, size_t in_Unknown);

    inline BB_FUNCTION_PTR(void, __thiscall, fpCMirageDatabaseWrapperGetVisibilityGridInfoData, 0x72F690,
        CMirageDatabaseWrapper* This, boost::shared_ptr<CVisibilityGridInfoData>& out_spVisibilityGridInfoData, const Hedgehog::Base::CSharedString& in_rName, size_t in_Unknown);

    inline BB_FUNCTION_PTR(void, __thiscall, fpCMirageDatabaseWrapperGetVisibilityTreeData, 0x72F490,
        CMirageDatabaseWrapper* This, boost::shared_ptr<CVisibilityTreeData>& out_spVisibilityTreeData, const Hedgehog::Base::CSharedString& in_rName, size_t in_Unknown);

    inline CMirageDatabaseWrapper::CMirageDatabaseWrapper(Hedgehog::Database::CDatabase* pDatabase)
    {
        fpCMirageDatabaseWrapperCtor(this, pDatabase);
    }

    inline boost::shared_ptr<CGIMipLevelLimitationData> CMirageDatabaseWrapper::GetGIMipLevelLimitationData(
        const Hedgehog::Base::CSharedString& in_rName, size_t in_Unknown)
    {
        boost::shared_ptr<CGIMipLevelLimitationData> spGIMipLevelLimitationData;
        fpCMirageDatabaseWrapperGetGIMipLevelLimitationData(this, spGIMipLevelLimitationData, in_rName, in_Unknown);
        return spGIMipLevelLimitationData;
    }

    inline boost::shared_ptr<CGITextureGroupInfoData> CMirageDatabaseWrapper::GetGITextureGroupInfoData(
        const Hedgehog::Base::CSharedString& in_rName, size_t in_Unknown)
    {
        boost::shared_ptr<CGITextureGroupInfoData> spGITextureGroupInfoData;
        fpCMirageDatabaseWrapperGetGITextureGroupInfoData(this, spGITextureGroupInfoData, in_rName, in_Unknown);
        return spGITextureGroupInfoData;
    }

    inline boost::shared_ptr<CLightData> CMirageDatabaseWrapper::GetLightData(
        const Hedgehog::Base::CSharedString& in_rName, size_t in_Unknown)
    {
        boost::shared_ptr<CLightData> spLightData;
        fpCMirageDatabaseWrapperGetLightData(this, spLightData, in_rName, in_Unknown);
        return spLightData;
    }

    inline boost::shared_ptr<CLightFieldTreeData> CMirageDatabaseWrapper::GetLightFieldTreeData(
        const Hedgehog::Base::CSharedString& in_rName, size_t in_Unknown)
    {
        boost::shared_ptr<CLightFieldTreeData> spLightFieldTreeData;
        fpCMirageDatabaseWrapperGetLightFieldTreeData(this, spLightFieldTreeData, in_rName, in_Unknown);
        return spLightFieldTreeData;
    }

    inline boost::shared_ptr<CLightListData> CMirageDatabaseWrapper::GetLightListData(
        const Hedgehog::Base::CSharedString& in_rName, size_t in_Unknown)
    {
        boost::shared_ptr<CLightListData> spLightListData;
        fpCMirageDatabaseWrapperGetLightListData(this, spLightListData, in_rName, in_Unknown);
        return spLightListData;
    }

    inline boost::shared_ptr<CLodModelData> CMirageDatabaseWrapper::GetLodModelData(
        const Hedgehog::Base::CSharedString& in_rName, size_t in_Unknown)
    {
        boost::shared_ptr<CLodModelData> spLodModelData;
        fpCMirageDatabaseWrapperGetLodModelData(this, spLodModelData, in_rName, in_Unknown);
        return spLodModelData;
    }

    inline boost::shared_ptr<CMaterialData> CMirageDatabaseWrapper::GetMaterialData(
        const Hedgehog::Base::CSharedString& in_rName, size_t in_Unknown)
    {
        boost::shared_ptr<CMaterialData> spMaterialData;
        fpCMirageDatabaseWrapperGetMaterialData(this, spMaterialData, in_rName, in_Unknown);
        return spMaterialData;
    }

    inline boost::shared_ptr<CModelData> CMirageDatabaseWrapper::GetModelData(
        const Hedgehog::Base::CSharedString& in_rName, size_t in_Unknown)
    {
        boost::shared_ptr<CModelData> spModelData;
        fpCMirageDatabaseWrapperGetModelData(this, spModelData, in_rName, in_Unknown);
        return spModelData;
    }

    inline boost::shared_ptr<CPictureData> CMirageDatabaseWrapper::GetPictureData(
        const Hedgehog::Base::CSharedString& in_rName, size_t in_Unknown)
    {
        boost::shared_ptr<CPictureData> spPictureData;
        fpCMirageDatabaseWrapperGetPictureData(this, spPictureData, in_rName, in_Unknown);
        return spPictureData;
    }

    inline boost::shared_ptr<CPixelShaderCodeData> CMirageDatabaseWrapper::GetPixelShaderCodeData(
        const Hedgehog::Base::CSharedString& in_rName, size_t in_Unknown)
    {
        boost::shared_ptr<CPixelShaderCodeData> spPixelShaderCodeData;
        fpCMirageDatabaseWrapperGetPixelShaderCodeData(this, spPixelShaderCodeData, in_rName, in_Unknown);
        return spPixelShaderCodeData;
    }

    inline boost::shared_ptr<CPixelShaderData> CMirageDatabaseWrapper::GetPixelShaderData(
        const Hedgehog::Base::CSharedString& in_rName, size_t in_Unknown)
    {
        boost::shared_ptr<CPixelShaderData> spPixelShaderData;
        fpCMirageDatabaseWrapperGetPixelShaderData(this, spPixelShaderData, in_rName, in_Unknown);
        return spPixelShaderData;
    }

    inline boost::shared_ptr<CPixelShaderParameterData> CMirageDatabaseWrapper::GetPixelShaderParameterData(
        const Hedgehog::Base::CSharedString& in_rName, size_t in_Unknown)
    {
        boost::shared_ptr<CPixelShaderParameterData> spPixelShaderParameterData;
        fpCMirageDatabaseWrapperGetPixelShaderParameterData(this, spPixelShaderParameterData, in_rName, in_Unknown);
        return spPixelShaderParameterData;
    }

    inline boost::shared_ptr<CSceneData> CMirageDatabaseWrapper::GetSceneData(
        const Hedgehog::Base::CSharedString& in_rName, size_t in_Unknown)
    {
        boost::shared_ptr<CSceneData> spSceneData;
        fpCMirageDatabaseWrapperGetSceneData(this, spSceneData, in_rName, in_Unknown);
        return spSceneData;
    }

    inline boost::shared_ptr<CShaderListData> CMirageDatabaseWrapper::GetShaderListData(
        const Hedgehog::Base::CSharedString& in_rName, size_t in_Unknown)
    {
        boost::shared_ptr<CShaderListData> spShaderListData;
        fpCMirageDatabaseWrapperGetShaderListData(this, spShaderListData, in_rName, in_Unknown);
        return spShaderListData;
    }

    inline boost::shared_ptr<CTerrainBlockSphereTreeData> CMirageDatabaseWrapper::GetTerrainBlockSphereTreeData(
        const Hedgehog::Base::CSharedString& in_rName, size_t in_Unknown)
    {
        boost::shared_ptr<CTerrainBlockSphereTreeData> spTerrainBlockSphereTreeData;
        fpCMirageDatabaseWrapperGetTerrainBlockSphereTreeData(this, spTerrainBlockSphereTreeData, in_rName, in_Unknown);
        return spTerrainBlockSphereTreeData;
    }

    inline boost::shared_ptr<CTerrainData> CMirageDatabaseWrapper::GetTerrainData(
        const Hedgehog::Base::CSharedString& in_rName, size_t in_Unknown)
    {
        boost::shared_ptr<CTerrainData> spTerrainData;
        fpCMirageDatabaseWrapperGetTerrainData(this, spTerrainData, in_rName, in_Unknown);
        return spTerrainData;
    }

    inline boost::shared_ptr<CTerrainGroupData> CMirageDatabaseWrapper::GetTerrainGroupData(
        const Hedgehog::Base::CSharedString& in_rName, size_t in_Unknown)
    {
        boost::shared_ptr<CTerrainGroupData> spTerrainGroupData;
        fpCMirageDatabaseWrapperGetTerrainGroupData(this, spTerrainGroupData, in_rName, in_Unknown);
        return spTerrainGroupData;
    }

    inline boost::shared_ptr<CTerrainInstanceInfoData> CMirageDatabaseWrapper::GetTerrainInstanceInfoData(
        const Hedgehog::Base::CSharedString& in_rName, size_t in_Unknown)
    {
        boost::shared_ptr<CTerrainInstanceInfoData> spTerrainInstanceInfoData;
        fpCMirageDatabaseWrapperGetTerrainInstanceInfoData(this, spTerrainInstanceInfoData, in_rName, in_Unknown);
        return spTerrainInstanceInfoData;
    }

    inline boost::shared_ptr<CTerrainModelData> CMirageDatabaseWrapper::GetTerrainModelData(
        const Hedgehog::Base::CSharedString& in_rName, size_t in_Unknown)
    {
        boost::shared_ptr<CTerrainModelData> spTerrainModelData;
        fpCMirageDatabaseWrapperGetTerrainModelData(this, spTerrainModelData, in_rName, in_Unknown);
        return spTerrainModelData;
    }

    inline boost::shared_ptr<CTexsetData> CMirageDatabaseWrapper::GetTexsetData(
        const Hedgehog::Base::CSharedString& in_rName, size_t in_Unknown)
    {
        boost::shared_ptr<CTexsetData> spTexsetData;
        fpCMirageDatabaseWrapperGetTexsetData(this, spTexsetData, in_rName, in_Unknown);
        return spTexsetData;
    }

    inline boost::shared_ptr<CTextureData> CMirageDatabaseWrapper::GetTextureData(
        const Hedgehog::Base::CSharedString& in_rName, size_t in_Unknown)
    {
        boost::shared_ptr<CTextureData> spTextureData;
        fpCMirageDatabaseWrapperGetTextureData(this, spTextureData, in_rName, in_Unknown);
        return spTextureData;
    }

    inline boost::shared_ptr<CVertexShaderCodeData> CMirageDatabaseWrapper::GetVertexShaderCodeData(
        const Hedgehog::Base::CSharedString& in_rName, size_t in_Unknown)
    {
        boost::shared_ptr<CVertexShaderCodeData> spVertexShaderCodeData;
        fpCMirageDatabaseWrapperGetVertexShaderCodeData(this, spVertexShaderCodeData, in_rName, in_Unknown);
        return spVertexShaderCodeData;
    }

    inline boost::shared_ptr<CVertexShaderData> CMirageDatabaseWrapper::GetVertexShaderData(
        const Hedgehog::Base::CSharedString& in_rName, size_t in_Unknown)
    {
        boost::shared_ptr<CVertexShaderData> spVertexShaderData;
        fpCMirageDatabaseWrapperGetVertexShaderData(this, spVertexShaderData, in_rName, in_Unknown);
        return spVertexShaderData;
    }

    inline boost::shared_ptr<CVertexShaderParameterData> CMirageDatabaseWrapper::GetVertexShaderParameterData(
        const Hedgehog::Base::CSharedString& in_rName, size_t in_Unknown)
    {
        boost::shared_ptr<CVertexShaderParameterData> spVertexShaderParameterData;
        fpCMirageDatabaseWrapperGetVertexShaderParameterData(this, spVertexShaderParameterData, in_rName, in_Unknown);
        return spVertexShaderParameterData;
    }

    inline boost::shared_ptr<CVisibilityGridData> CMirageDatabaseWrapper::GetVisibilityGridData(
        const Hedgehog::Base::CSharedString& in_rName, size_t in_Unknown)
    {
        boost::shared_ptr<CVisibilityGridData> spVisibilityGridData;
        fpCMirageDatabaseWrapperGetVisibilityGridData(this, spVisibilityGridData, in_rName, in_Unknown);
        return spVisibilityGridData;
    }

    inline boost::shared_ptr<CVisibilityGridInfoData> CMirageDatabaseWrapper::GetVisibilityGridInfoData(
        const Hedgehog::Base::CSharedString& in_rName, size_t in_Unknown)
    {
        boost::shared_ptr<CVisibilityGridInfoData> spVisibilityGridInfoData;
        fpCMirageDatabaseWrapperGetVisibilityGridInfoData(this, spVisibilityGridInfoData, in_rName, in_Unknown);
        return spVisibilityGridInfoData;
    }

    inline boost::shared_ptr<CVisibilityTreeData> CMirageDatabaseWrapper::GetVisibilityTreeData(
        const Hedgehog::Base::CSharedString& in_rName, size_t in_Unknown)
    {
        boost::shared_ptr<CVisibilityTreeData> spVisibilityTreeData;
        fpCMirageDatabaseWrapperGetVisibilityTreeData(this, spVisibilityTreeData, in_rName, in_Unknown);
        return spVisibilityTreeData;
    }
}