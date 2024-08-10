#pragma once

#include <Hedgehog/Database/System/hhDatabaseLoader.h>

namespace Hedgehog::Database
{
    class CArchiveDatabaseLoader;

    inline BB_FUNCTION_PTR(void, __thiscall, fpCArchiveDatabaseLoaderLoadArchive, 0x6A1A80, CArchiveDatabaseLoader* This,
        const boost::shared_ptr<CDatabase>& in_spDatabase, boost::shared_ptr<uint8_t[]> in_spData, uint32_t in_DataSize, uint32_t in_DataSize1, void* in_pFileReader);

    class CArchiveDatabaseLoader : public CDatabaseLoader
    {
    public:
        BB_INSERT_PADDING(0x8);
    };

    BB_ASSERT_SIZEOF(CArchiveDatabaseLoader, 0x7C);
}