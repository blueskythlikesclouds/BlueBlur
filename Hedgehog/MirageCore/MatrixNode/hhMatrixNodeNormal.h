#pragma once

#include <Hedgehog/MirageCore/MatrixNode/hhMatrixNode.h>

namespace Hedgehog::Mirage
{
    class CMatrixNodeNormal : public CMatrixNode
    {
    public:
        Math::CMatrix m_Matrix;
        Math::CMatrix m_PrevMatrix;
    };

    BB_ASSERT_OFFSETOF(CMatrixNodeNormal, m_Matrix, 0x60);
    BB_ASSERT_OFFSETOF(CMatrixNodeNormal, m_PrevMatrix, 0xA0);
    BB_ASSERT_SIZEOF(CMatrixNodeNormal, 0xE0);
}