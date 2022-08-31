#pragma once

#include <Hedgehog/Base/System/hhSymbol.h>
#include <Hedgehog/Database/System/hhDatabaseData.h>
#include <Hedgehog/MirageCore/Misc/hhSamplerState.h>

namespace Hedgehog::Mirage
{
    class CPictureData;

    class CTextureData : public Database::CDatabaseData
    {
    public:
        boost::shared_ptr<CPictureData> m_spPictureData;
        uint8_t m_TexcoordIndex;
        SSamplerState m_SamplerState;
        Base::CStringSymbol m_Type;
    };

    BB_ASSERT_OFFSETOF(CTextureData, m_spPictureData, 0xC);
    BB_ASSERT_OFFSETOF(CTextureData, m_TexcoordIndex, 0x14);
    BB_ASSERT_OFFSETOF(CTextureData, m_SamplerState, 0x18);
    BB_ASSERT_OFFSETOF(CTextureData, m_Type, 0x2C);
    BB_ASSERT_SIZEOF(CTextureData, 0x30);
}