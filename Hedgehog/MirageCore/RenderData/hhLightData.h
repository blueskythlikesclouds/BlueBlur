#pragma once

#include <Hedgehog/Database/System/hhDatabaseData.h>

namespace Hedgehog::Mirage
{
    enum ELightType : uint32_t
    {
        eLightType_Directional = 0,
        eLightType_Point = 1
    };

    class CLightData : public Hedgehog::Database::CDatabaseData
    {
    public:
        Math::CVector m_Position;
        Math::CVector4 m_Color;
        Math::CVector4 m_Range;
        Math::CVector m_Direction;
        ELightType m_Type;
        uint32_t m_Attribute;
        size_t m_Field58;

        CLightData() : m_Type(eLightType_Directional), m_Attribute(0), m_Field58(1)
        {
        }
    };

    BB_ASSERT_OFFSETOF(CLightData, m_Position, 0x10);
    BB_ASSERT_OFFSETOF(CLightData, m_Color, 0x20);
    BB_ASSERT_OFFSETOF(CLightData, m_Range, 0x30);
    BB_ASSERT_OFFSETOF(CLightData, m_Direction, 0x40);
    BB_ASSERT_OFFSETOF(CLightData, m_Type, 0x50);
    BB_ASSERT_OFFSETOF(CLightData, m_Attribute, 0x54);
    BB_ASSERT_OFFSETOF(CLightData, m_Field58, 0x58);
    BB_ASSERT_SIZEOF(CLightData, 0x60);
}
