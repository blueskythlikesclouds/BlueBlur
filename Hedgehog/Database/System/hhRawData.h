#pragma once

#include <BlueBlur.inl>
#include <Hedgehog/Database/System/hhDatabaseData.h>

namespace Hedgehog::Database
{
    class CRawData : public CDatabaseData
    {
    public:
        uint32_t m_DataSize;
        BB_INSERT_PADDING(0x4);
        boost::shared_ptr<uint8_t> m_spData;
    };

    BB_ASSERT_OFFSETOF(CRawData, m_DataSize, 0xC);
    BB_ASSERT_OFFSETOF(CRawData, m_spData, 0x14);
    BB_ASSERT_SIZEOF(CRawData, 0x1C);
}