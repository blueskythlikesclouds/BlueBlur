#pragma once

#include <Hedgehog/MirageCore/MatrixNode/hhMatrixNodeListener.h>

namespace Hedgehog::Mirage
{
    class CInstanceInfo : public CMatrixNodeListener
    {
    public:
        BB_INSERT_PADDING(0x24C);
        Math::CMatrix m_Transform;
        BB_INSERT_PADDING(0xB0);
    };

    BB_ASSERT_OFFSETOF(CInstanceInfo, m_Transform, 0x250);
    BB_ASSERT_SIZEOF(CInstanceInfo, 0x340);
}