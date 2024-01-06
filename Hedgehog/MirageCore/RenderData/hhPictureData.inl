namespace Hedgehog::Mirage
{
    inline BB_FUNCTION_PTR(void, __cdecl, fpCPictureDataMake0, 0x743DE0,
        CPictureData* in_pPictureData, uint8_t* in_pData, size_t in_DataSize, CRenderingInfrastructure* in_pRenderingInfrastructure);

    inline void CPictureData::Make(CPictureData* in_pPictureData, uint8_t* in_pData, size_t in_DataSize,
        CRenderingInfrastructure* in_pRenderingInfrastructure)
    {
        fpCPictureDataMake0(in_pPictureData, in_pData, in_DataSize, in_pRenderingInfrastructure);
    }

    inline BB_FUNCTION_PTR(void, __cdecl, fpCPictureDataMake1, 0x734590, const Base::CSharedString& in_rName, uint8_t* in_pData, size_t in_DataSize,
        const boost::shared_ptr<Database::CDatabase>& in_spDatabase, CRenderingInfrastructure* in_pRenderingInfrastructure);

    inline void CPictureData::Make(const Base::CSharedString& in_rName, uint8_t* in_pData, size_t in_DataSize,
        const boost::shared_ptr<Database::CDatabase>& in_spDatabase,
        CRenderingInfrastructure* in_pRenderingInfrastructure)
    {
        fpCPictureDataMake1(in_rName, in_pData, in_DataSize, in_spDatabase, in_pRenderingInfrastructure);
    }
}