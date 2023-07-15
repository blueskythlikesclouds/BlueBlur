#pragma once

#include <Hedgehog/Base/hhObject.h>
#include <Hedgehog/Base/Type/hhSharedString.h>
#include <Hedgehog/Database/System/hhArchiveParam.h>

namespace Hedgehog::Database
{
    struct SArchiveParam;
    struct SLoadElement;

    class CArchiveList;
    class CArchiveListManager;

    class CDatabase;
    class CDatabaseLoader;

    static inline BB_FUNCTION_PTR(void, __thiscall, fpCDatabaseLoaderCreateArchiveList, 0x69C270,
        CDatabaseLoader* This, boost::shared_ptr<CArchiveList>& out_spArchiveList,
        const Hedgehog::Base::CSharedString& in_rArchiveName, const Hedgehog::Base::CSharedString& in_rArchiveListName, const SArchiveParam& in_rArchiveParam);

    static inline BB_FUNCTION_PTR(void, __thiscall, fpCDatabaseLoaderLoadArchiveList0, 0x69AFF0,
        CDatabaseLoader* This, boost::shared_ptr<CDatabase> in_spDatabase, const Hedgehog::Base::CSharedString& in_rArchiveListName);

    static inline BB_FUNCTION_PTR(void, __thiscall, fpCDatabaseLoaderLoadArchiveList1, 0x69B360,
        CDatabaseLoader* This, const boost::shared_ptr<CArchiveList>& in_spArchiveList, const uint8_t* in_pData, size_t in_DataSize);

    static inline BB_FUNCTION_PTR(void, __thiscall, fpCDatabaseLoaderLoadArchive, 0x69AB10,
        CDatabaseLoader* This, boost::shared_ptr<CDatabase> in_spDatabase, const Hedgehog::Base::CSharedString& in_rArchiveName, 
        const SArchiveParam& in_rArchiveParam, bool in_Unknown0, bool in_LoadImm);

    static inline BB_FUNCTION_PTR(void, __thiscall, fpCDatabaseLoaderLoadDirectory, 0x69B760,
        CDatabaseLoader* This, const boost::shared_ptr<CDatabase>& in_spDatabase, const Hedgehog::Base::CSharedString& in_rDirectoryPath, const SArchiveParam& in_rArchiveParam);

    static inline BB_FUNCTION_PTR(void, __thiscall, fpCDatabaseLoaderLoadFile, 0x69BAD0,
        CDatabaseLoader* This, boost::shared_ptr<SLoadElement>& out_spLoadElement, boost::shared_ptr<CDatabase> in_spDatabase, const Hedgehog::Base::CSharedString& in_rFileName, const Hedgehog::Base::CSharedString& in_rDirectoryPath, const SArchiveParam& in_rArchiveParam);

    static inline BB_FUNCTION_PTR(void, __thiscall, fpCDatabaseLoaderLoadData, 0x6999C0,
        CDatabaseLoader* This, const boost::shared_ptr<CDatabase>& in_spDatabase, const Hedgehog::Base::CSharedString& in_rName, const uint8_t* in_pData, uint32_t in_DataSize, boost::shared_ptr<uint8_t[]> in_spDataSource, const SArchiveParam& in_rArchiveParam);

    class CDatabaseLoader : public Base::CObject
    {
    public:
        BB_INSERT_PADDING(0x2C);
        boost::shared_ptr<CArchiveListManager> m_spArchiveListManager;
        BB_INSERT_PADDING(0x3C);

        virtual ~CDatabaseLoader() = default;

        virtual void LoadArchive(const boost::shared_ptr<CDatabase>& in_spDatabase, boost::shared_ptr<uint8_t[]> in_spData, uint32_t in_DataSize, uint32_t in_DataSizeDup, const SArchiveParam& in_rArchiveParam) = 0;

        boost::shared_ptr<CArchiveList> CreateArchiveList(const Hedgehog::Base::CSharedString& in_rArchiveName, const Hedgehog::Base::CSharedString& in_rArchiveListName, const SArchiveParam& in_rArchiveParam)
        {
            boost::shared_ptr<CArchiveList> spArchiveList;
            fpCDatabaseLoaderCreateArchiveList(this, spArchiveList, in_rArchiveName, in_rArchiveListName, in_rArchiveParam);
            return spArchiveList;
        }

        void LoadArchiveList(boost::shared_ptr<CDatabase> in_spDatabase, const Hedgehog::Base::CSharedString& in_rArchiveListName)
        {
            fpCDatabaseLoaderLoadArchiveList0(this, in_spDatabase, in_rArchiveListName);
        }

        void LoadArchiveList(const boost::shared_ptr<CArchiveList>& in_spArchiveList, const uint8_t* in_pData, size_t in_DataSize)
        {
            fpCDatabaseLoaderLoadArchiveList1(this, in_spArchiveList, in_pData, in_DataSize);
        }

        void LoadArchive(boost::shared_ptr<CDatabase> in_spDatabase, const Hedgehog::Base::CSharedString& in_rArchiveName, const SArchiveParam& in_rArchiveParam, bool in_Unknown0, bool in_LoadImm)
        {
            fpCDatabaseLoaderLoadArchive(this, in_spDatabase, in_rArchiveName, in_rArchiveParam, in_Unknown0, in_LoadImm);
        }

        void LoadDirectory(const boost::shared_ptr<CDatabase>& in_spDatabase, const Hedgehog::Base::CSharedString& in_rDirectoryPath, const SArchiveParam& in_rArchiveParam)
        {
            fpCDatabaseLoaderLoadDirectory(this, in_spDatabase, in_rDirectoryPath, in_rArchiveParam);
        }

        boost::shared_ptr<SLoadElement> LoadFile(boost::shared_ptr<CDatabase> in_spDatabase, const Hedgehog::Base::CSharedString& in_rName, const Hedgehog::Base::CSharedString& in_rFilePath, const SArchiveParam& in_rArchiveParam)
        {
            boost::shared_ptr<SLoadElement> spLoadElement;
            fpCDatabaseLoaderLoadFile(this, spLoadElement, in_spDatabase, in_rName, in_rFilePath, in_rArchiveParam);
            return spLoadElement;
        }

        void LoadData(const boost::shared_ptr<CDatabase>& in_spDatabase, const Hedgehog::Base::CSharedString& in_rName, const uint8_t* in_pData, uint32_t in_DataSize, boost::shared_ptr<uint8_t[]> in_spDataSource, const SArchiveParam& in_rArchiveParam)
        {
            fpCDatabaseLoaderLoadData(this, in_spDatabase, in_rName, in_pData, in_DataSize, in_spDataSource, in_rArchiveParam);
        }
    };

    BB_ASSERT_OFFSETOF(CDatabaseLoader, m_spArchiveListManager, 0x30);
    BB_ASSERT_SIZEOF(CDatabaseLoader, 0x74);
}
