#pragma once

#include <Hedgehog/Base/hhObject.h>
#include <Hedgehog/Base/Type/hhSharedString.h>
#include <Hedgehog/Database/System/hhArchiveParam.h>
#include <Hedgehog/Database/System/hhCompressor.h>

namespace Hedgehog::Base
{
    class CEventWaitD3D9;
    class CCompressor;
    class CThread;
}

namespace Hedgehog::Database
{
    struct SArchiveParam;
    struct SLoadElement;

    class CArchiveList;
    class CArchiveListManager;

    class CDatabase;
    class CDatabaseLoader;
    class CLoadScheduler;
    class CDataCreator;

    class CDatabaseLoader : public Base::CObject
    {
    public:
        boost::shared_ptr<Hedgehog::Base::CThread> m_spThread;
        boost::shared_ptr<Base::CEventWaitD3D9> m_spEventWait;
        bool m_CreatingData;
        boost::shared_ptr<CLoadScheduler> m_spLoadScheduler;
        boost::shared_ptr<Base::CCompressor> m_spCompressor;
        boost::shared_ptr<CDataCreator> m_spDataCreator;
        boost::shared_ptr<CArchiveListManager> m_spArchiveListManager;
        boost::shared_ptr<CCallback> m_spDecompressionCallback;
        boost::shared_ptr<CCallback> m_spDecompressionCallback2; // Points to the same type as m_spDecompressionCallback
        BB_INSERT_PADDING(0x2C);

        virtual ~CDatabaseLoader() = default;

        boost::shared_ptr<CArchiveList> CreateArchiveList(const Hedgehog::Base::CSharedString& in_rArchiveName, const Hedgehog::Base::CSharedString& in_rArchiveListName, const SArchiveParam& in_rArchiveParam);
        void LoadArchiveList(boost::shared_ptr<CDatabase> in_spDatabase, const Hedgehog::Base::CSharedString& in_rArchiveListName);
        void LoadArchiveList(const boost::shared_ptr<CArchiveList>& in_spArchiveList, const uint8_t* in_pData, size_t in_DataSize);

        virtual void LoadArchive(const boost::shared_ptr<CDatabase>& in_spDatabase, boost::shared_ptr<uint8_t[]> in_spData, uint32_t in_DataSize, uint32_t in_DataSizeDup, const SArchiveParam& in_rArchiveParam) = 0;
        void LoadArchive(boost::shared_ptr<CDatabase> in_spDatabase, const Hedgehog::Base::CSharedString& in_rArchiveName, const SArchiveParam& in_rArchiveParam, bool in_Unknown0, bool in_LoadImm);
        void LoadDirectory(const boost::shared_ptr<CDatabase>& in_spDatabase, const Hedgehog::Base::CSharedString& in_rDirectoryPath, const SArchiveParam& in_rArchiveParam);

        boost::shared_ptr<SLoadElement> LoadFile(boost::shared_ptr<CDatabase> in_spDatabase, const Hedgehog::Base::CSharedString& in_rName, const Hedgehog::Base::CSharedString& in_rFilePath, const SArchiveParam& in_rArchiveParam);
        void LoadData(const boost::shared_ptr<CDatabase>& in_spDatabase, const Hedgehog::Base::CSharedString& in_rName, const uint8_t* in_pData, uint32_t in_DataSize, boost::shared_ptr<uint8_t[]> in_spDataSource, const SArchiveParam& in_rArchiveParam);
    };

    BB_ASSERT_OFFSETOF(CDatabaseLoader, m_spThread, 0x4);
    BB_ASSERT_OFFSETOF(CDatabaseLoader, m_spEventWait, 0xC);
    BB_ASSERT_OFFSETOF(CDatabaseLoader, m_CreatingData, 0x14);
    BB_ASSERT_OFFSETOF(CDatabaseLoader, m_spLoadScheduler, 0x18);
    BB_ASSERT_OFFSETOF(CDatabaseLoader, m_spCompressor, 0x20);
    BB_ASSERT_OFFSETOF(CDatabaseLoader, m_spDataCreator, 0x28);
    BB_ASSERT_OFFSETOF(CDatabaseLoader, m_spArchiveListManager, 0x30);
    BB_ASSERT_OFFSETOF(CDatabaseLoader, m_spDecompressionCallback, 0x38);
    BB_ASSERT_OFFSETOF(CDatabaseLoader, m_spDecompressionCallback2, 0x40);
    BB_ASSERT_SIZEOF(CDatabaseLoader, 0x74);
}


#include <Hedgehog/Database/System/hhDatabaseLoader.inl>