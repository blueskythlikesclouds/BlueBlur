#pragma once

#include <Hedgehog/Database/System/hhDatabaseData.h>

namespace Hedgehog::Mirage
{
    class CTextureData;

    class CTexsetData : public Database::CDatabaseData
    {
    public:
        hh::vector<boost::shared_ptr<CTextureData>> m_TextureList;
        hh::vector<Base::CSharedString> m_TextureNameList;
        BB_INSERT_PADDING(0x2);
        bool m_ConstTexCoord;
        BB_INSERT_PADDING(0x1);

        CTexsetData();
    };

    BB_ASSERT_OFFSETOF(CTexsetData, m_TextureList, 0xC);
    BB_ASSERT_OFFSETOF(CTexsetData, m_TextureNameList, 0x1C);
    BB_ASSERT_OFFSETOF(CTexsetData, m_ConstTexCoord, 0x2E);
    BB_ASSERT_SIZEOF(CTexsetData, 0x30);
}

#include <Hedgehog/MirageCore/RenderData/hhTexsetData.inl>