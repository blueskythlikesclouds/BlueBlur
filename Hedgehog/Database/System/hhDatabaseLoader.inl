namespace Hedgehog::Database
{
    inline BB_FUNCTION_PTR(void, __thiscall, fpCDatabaseLoaderCreateArchiveList, 0x69C270,
        CDatabaseLoader* This, boost::shared_ptr<CArchiveList>& out_spArchiveList,
        const Hedgehog::Base::CSharedString& in_rArchiveName, const Hedgehog::Base::CSharedString& in_rArchiveListName, const SArchiveParam& in_rArchiveParam);

    inline boost::shared_ptr<CArchiveList> CDatabaseLoader::CreateArchiveList(
        const Hedgehog::Base::CSharedString& in_rArchiveName, const Hedgehog::Base::CSharedString& in_rArchiveListName,
        const SArchiveParam& in_rArchiveParam)
    {
        boost::shared_ptr<CArchiveList> spArchiveList;
        fpCDatabaseLoaderCreateArchiveList(this, spArchiveList, in_rArchiveName, in_rArchiveListName, in_rArchiveParam);
        return spArchiveList;
    }

    inline BB_FUNCTION_PTR(void, __thiscall, fpCDatabaseLoaderLoadArchiveList0, 0x69AFF0,
        CDatabaseLoader* This, boost::shared_ptr<CDatabase> in_spDatabase, const Hedgehog::Base::CSharedString& in_rArchiveListName);

    inline void CDatabaseLoader::LoadArchiveList(boost::shared_ptr<CDatabase> in_spDatabase,
        const Hedgehog::Base::CSharedString& in_rArchiveListName)
    {
        fpCDatabaseLoaderLoadArchiveList0(this, in_spDatabase, in_rArchiveListName);
    }

    inline BB_FUNCTION_PTR(void, __thiscall, fpCDatabaseLoaderLoadArchiveList1, 0x69B360,
        CDatabaseLoader* This, const boost::shared_ptr<CArchiveList>& in_spArchiveList, const uint8_t* in_pData, size_t in_DataSize);

    inline void CDatabaseLoader::LoadArchiveList(const boost::shared_ptr<CArchiveList>& in_spArchiveList,
        const uint8_t* in_pData, size_t in_DataSize)
    {
        fpCDatabaseLoaderLoadArchiveList1(this, in_spArchiveList, in_pData, in_DataSize);
    }

    inline BB_FUNCTION_PTR(void, __thiscall, fpCDatabaseLoaderLoadArchive, 0x69AB10,
        CDatabaseLoader* This, boost::shared_ptr<CDatabase> in_spDatabase, const Hedgehog::Base::CSharedString& in_rArchiveName,
        const SArchiveParam& in_rArchiveParam, bool in_Unknown0, bool in_LoadImm);

    inline void CDatabaseLoader::LoadArchive(boost::shared_ptr<CDatabase> in_spDatabase,
        const Hedgehog::Base::CSharedString& in_rArchiveName, const SArchiveParam& in_rArchiveParam, bool in_Unknown0,
        bool in_LoadImm)
    {
        fpCDatabaseLoaderLoadArchive(this, in_spDatabase, in_rArchiveName, in_rArchiveParam, in_Unknown0, in_LoadImm);
    }

    inline BB_FUNCTION_PTR(void, __thiscall, fpCDatabaseLoaderLoadDirectory, 0x69B760,
        CDatabaseLoader* This, const boost::shared_ptr<CDatabase>& in_spDatabase, const Hedgehog::Base::CSharedString& in_rDirectoryPath, const SArchiveParam& in_rArchiveParam);

    inline void CDatabaseLoader::LoadDirectory(const boost::shared_ptr<CDatabase>& in_spDatabase,
        const Hedgehog::Base::CSharedString& in_rDirectoryPath, const SArchiveParam& in_rArchiveParam)
    {
        fpCDatabaseLoaderLoadDirectory(this, in_spDatabase, in_rDirectoryPath, in_rArchiveParam);
    }

    inline BB_FUNCTION_PTR(void, __thiscall, fpCDatabaseLoaderLoadFile, 0x69BAD0,
        CDatabaseLoader* This, boost::shared_ptr<SLoadElement>& out_spLoadElement, boost::shared_ptr<CDatabase> in_spDatabase, const Hedgehog::Base::CSharedString& in_rFileName, const Hedgehog::Base::CSharedString& in_rDirectoryPath, const SArchiveParam& in_rArchiveParam);

    inline boost::shared_ptr<SLoadElement> CDatabaseLoader::LoadFile(boost::shared_ptr<CDatabase> in_spDatabase,
        const Hedgehog::Base::CSharedString& in_rName, const Hedgehog::Base::CSharedString& in_rFilePath,
        const SArchiveParam& in_rArchiveParam)
    {
        boost::shared_ptr<SLoadElement> spLoadElement;
        fpCDatabaseLoaderLoadFile(this, spLoadElement, in_spDatabase, in_rName, in_rFilePath, in_rArchiveParam);
        return spLoadElement;
    }

    inline BB_FUNCTION_PTR(void, __thiscall, fpCDatabaseLoaderLoadData, 0x6999C0,
        CDatabaseLoader* This, const boost::shared_ptr<CDatabase>& in_spDatabase, const Hedgehog::Base::CSharedString& in_rName, const uint8_t* in_pData, uint32_t in_DataSize, boost::shared_ptr<uint8_t[]> in_spDataSource, const SArchiveParam& in_rArchiveParam);

    inline void CDatabaseLoader::LoadData(const boost::shared_ptr<CDatabase>& in_spDatabase,
        const Hedgehog::Base::CSharedString& in_rName, const uint8_t* in_pData, uint32_t in_DataSize,
        boost::shared_ptr<uint8_t[]> in_spDataSource, const SArchiveParam& in_rArchiveParam)
    {
        fpCDatabaseLoaderLoadData(this, in_spDatabase, in_rName, in_pData, in_DataSize, in_spDataSource, in_rArchiveParam);
    }
}