#pragma once

#include <Hedgehog/MirageCore/MatrixNode/hhMatrixNode.h>

namespace Hedgehog::Mirage
{
    class CMatrixNodeNormal : public CMatrixNode
    {
    public:
        static constexpr size_t ms_pVtbl = 0x13E7018;

        Math::CMatrix m_LocalMatrix {};
        Math::CMatrix m_WorldMatrix {};

        CMatrixNodeNormal();
        CMatrixNodeNormal(const Math::CMatrix& in_rMatrix);

        void UpdateMatrix(CMatrixNode* in_pParentMatrixNode) override;

        const Math::CMatrix& GetLocalMatrix() const override;
        const Math::CMatrix& GetWorldMatrix() const override;
    };

    BB_ASSERT_OFFSETOF(CMatrixNodeNormal, m_LocalMatrix, 0x60);
    BB_ASSERT_OFFSETOF(CMatrixNodeNormal, m_WorldMatrix, 0xA0);
    BB_ASSERT_SIZEOF(CMatrixNodeNormal, 0xE0);
}

#include <Hedgehog/MirageCore/MatrixNode/hhMatrixNodeNormal.inl>