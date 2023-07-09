#pragma once

#include <Hedgehog/Base/hhObject.h>
#include <Hedgehog/Base/Type/hhSharedString.h>

#include "hhArchiveParam.h"

namespace Hedgehog::Database
{
    struct SArchiveParam;
    struct SLoadElement;
    class CArchiveList;

    class CDatabase;
    class CDatabaseLoader;

    static inline BB_FUNCTION_PTR(void, __thiscall, fpCDatabaseLoaderCreateArchiveList, 0x69C270,
        CDatabaseLoader* This, boost::shared_ptr<CArchiveList>& out_spArchiveList,
        const Hedgehog::Base::CSharedString& in_rArchiveName, const Hedgehog::Base::CSharedString& in_rArchiveListName, const SArchiveParam& in_rArchiveParam);

    static inline BB_FUNCTION_PTR(void, __thiscall, fpCDatabaseLoaderLoadArchiveList, 0x69AFF0,
        CDatabaseLoader* This, boost::shared_ptr<CDatabase> in_spDatabase, const Hedgehog::Base::CSharedString& in_rArchiveListName);

    static inline BB_FUNCTION_PTR(void, __thiscall, fpCDatabaseLoaderLoadArchive, 0x69AB10,
        CDatabaseLoader* This, boost::shared_ptr<CDatabase> in_spDatabase, const Hedgehog::Base::CSharedString& in_rArchiveName, 
        const SArchiveParam& in_rArchiveParam, bool in_Unknown0, bool in_Unknown1);

    static inline BB_FUNCTION_PTR(void, __thiscall, fpCDatabaseLoaderLoadDirectory, 0x69B760,
        CDatabaseLoader* This, const boost::shared_ptr<CDatabase>& in_spDatabase, const Hedgehog::Base::CSharedString& in_rDirectoryPath, const SArchiveParam& in_rArchiveParam);

    static inline BB_FUNCTION_PTR(void, __thiscall, fpCDatabaseLoaderLoadFile, 0x69BAD0,
        CDatabaseLoader* This, boost::shared_ptr<SLoadElement>& out_spLoadElement, boost::shared_ptr<CDatabase> in_spDatabase, const Hedgehog::Base::CSharedString& in_rFileName, const Hedgehog::Base::CSharedString& in_rDirectoryPath, const SArchiveParam& in_rArchiveParam);

    class CDatabaseLoader : public Base::CObject
    {
    public:
        BB_INSERT_PADDING(0x70);

        virtual ~CDatabaseLoader() = default;

        virtual void LoadArchive(const boost::shared_ptr<CDatabase>& in_spDatabase, boost::shared_ptr<uint8_t[]> in_spData, uint32_t in_DataSize, uint32_t in_DataSize1, void* in_pFileReader) = 0;

        boost::shared_ptr<CArchiveList> CreateArchiveList(const Hedgehog::Base::CSharedString& in_rArchiveName, const Hedgehog::Base::CSharedString& in_rArchiveListName, const SArchiveParam& in_rArchiveParam)
        {
            boost::shared_ptr<CArchiveList> spArchiveList;
            fpCDatabaseLoaderCreateArchiveList(this, spArchiveList, in_rArchiveName, in_rArchiveListName, in_rArchiveParam);
            return spArchiveList;
        }

        void LoadArchiveList(boost::shared_ptr<CDatabase> in_spDatabase, const Hedgehog::Base::CSharedString& in_rArchiveListName)
        {
            fpCDatabaseLoaderLoadArchiveList(this, in_spDatabase, in_rArchiveListName);
        }

        void LoadArchive(boost::shared_ptr<CDatabase> in_spDatabase, const Hedgehog::Base::CSharedString& in_rArchiveName, const SArchiveParam& in_rArchiveParam, bool in_Unknown0, bool in_Unknown1)
        {
            fpCDatabaseLoaderLoadArchive(this, in_spDatabase, in_rArchiveName, in_rArchiveParam, in_Unknown0, in_Unknown1);
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
    };

    BB_ASSERT_SIZEOF(CDatabaseLoader, 0x74);
}
