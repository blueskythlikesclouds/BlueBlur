#pragma once

#include <BlueBlur.inl>

namespace Hedgehog::Math
{
    struct CSphere
    {
    public:
        CVector m_Position;
        float m_Radius;
    };

    BB_ASSERT_OFFSETOF(CSphere, m_Position, 0x0);
    BB_ASSERT_OFFSETOF(CSphere, m_Radius, 0x10);
    BB_ASSERT_SIZEOF(CSphere, 0x20);
}
