#pragma once

#include <Hedgehog/MirageCore/MatrixNode/hhMatrixNode.h>

namespace Hedgehog::Mirage
{
    class CMatrixNodeSingleElementNode : public CMatrixNode
    {
    public:
        Math::CMatrix m_LocalMatrix;
        Math::CMatrix m_WorldMatrix;
        BB_INSERT_PADDING(0x60);
    };

    BB_ASSERT_OFFSETOF(CMatrixNodeSingleElementNode, m_LocalMatrix, 0x60);
    BB_ASSERT_OFFSETOF(CMatrixNodeSingleElementNode, m_WorldMatrix, 0xA0);
    BB_ASSERT_SIZEOF(CMatrixNodeSingleElementNode, 0x140);
}