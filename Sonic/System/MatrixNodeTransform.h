#pragma once

#include <Hedgehog/MirageCore/MatrixNode/hhMatrixNode.h>
#include <Hedgehog/MirageCore/Misc/hhTransform.h>

namespace Sonic
{
    class CMatrixNodeTransform : public Hedgehog::Mirage::CMatrixNode
    {
    public:
        Hedgehog::Mirage::CTransform m_Transform;
        Hedgehog::Math::CMatrix m_WorldMatrix;

        CMatrixNodeTransform();

        void SetParent(CMatrixNode* in_pParentNode);
        void SetChild(CMatrixNode* in_pChildNode);

        void UpdateMatrix(CMatrixNode* in_pParentMatrixNode) override;

        const Hedgehog::Math::CMatrix& GetLocalMatrix() const override;
        const Hedgehog::Math::CMatrix& GetWorldMatrix() const override;
    };

    BB_ASSERT_OFFSETOF(CMatrixNodeTransform, m_Transform, 0x60);
    BB_ASSERT_OFFSETOF(CMatrixNodeTransform, m_WorldMatrix, 0xC0);
    BB_ASSERT_SIZEOF(CMatrixNodeTransform, 0x100);
}

#include <Sonic/System/MatrixNodeTransform.inl>