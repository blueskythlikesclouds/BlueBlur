#pragma once

#include <Hedgehog/Base/hhObject.h>

namespace Hedgehog::Mirage
{
    class CMatrixNode : public Base::CObject
    {
    public:
        BB_INSERT_PADDING(0x5C);

        CMatrixNode(const bb_null_ctor& nil) : CObject(nil) {}
        CMatrixNode();

        virtual ~CMatrixNode() = default;
        virtual void UpdateMatrix(CMatrixNode* in_pParentMatrixNode) = 0;
        virtual const Hedgehog::Math::CMatrix& GetLocalMatrix() const = 0;
        virtual const Hedgehog::Math::CMatrix& GetWorldMatrix() const = 0;

        void NotifyChanged();
    };

    BB_ASSERT_SIZEOF(CMatrixNode, 0x60);
}

#include <Hedgehog/MirageCore/MatrixNode/hhMatrixNode.inl>