#pragma once

#include <Hedgehog/MirageCore/MatrixNode/hhMatrixNode.h>

namespace Hedgehog::Mirage
{
    class CMatrixNodeNormal : public CMatrixNode
    {
    public:
        Math::CMatrix m_LocalMatrix;
        Math::CMatrix m_WorldMatrix;
    };

    BB_ASSERT_OFFSETOF(CMatrixNodeNormal, m_LocalMatrix, 0x60);
    BB_ASSERT_OFFSETOF(CMatrixNodeNormal, m_WorldMatrix, 0xA0);
    BB_ASSERT_SIZEOF(CMatrixNodeNormal, 0xE0);
}