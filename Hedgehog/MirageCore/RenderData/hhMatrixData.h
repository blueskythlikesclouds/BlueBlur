#pragma once

#include <Hedgehog/Base/hhObject.h>

namespace Hedgehog::Mirage
{
    class CMatrixData : public Hedgehog::Base::CObject
    {
    public:
        Math::CMatrix44 m_Matrix;
    };

    BB_ASSERT_OFFSETOF(CMatrixData, m_Matrix, 0x0);
    BB_ASSERT_SIZEOF(CMatrixData, 0x40);
}