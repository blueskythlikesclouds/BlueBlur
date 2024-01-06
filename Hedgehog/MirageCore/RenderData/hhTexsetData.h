#pragma once

#include <Hedgehog/Database/System/hhDatabaseData.h>

namespace Hedgehog::Mirage
{
    class CTextureData;
    class CTexsetData;

    static inline BB_FUNCTION_PTR(CTexsetData*, __thiscall, fpCTexsetDataCtor, 0x6F8730, CTexsetData*);

    class CTexsetData : public Database::CDatabaseData
    {
    public:
        hh::vector<boost::shared_ptr<CTextureData>> m_TextureList;
        hh::vector<Base::CSharedString> m_TextureNameList;
        BB_INSERT_PADDING(0x4);

        CTexsetData()
        {
            fpCTexsetDataCtor(this);
        }
    };

    BB_ASSERT_OFFSETOF(CTexsetData, m_TextureList, 0xC);
    BB_ASSERT_OFFSETOF(CTexsetData, m_TextureNameList, 0x1C);
    BB_ASSERT_SIZEOF(CTexsetData, 0x30);
}