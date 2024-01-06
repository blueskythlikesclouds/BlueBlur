#pragma once

#include <Hedgehog/Base/hhObject.h>

namespace Hedgehog::Mirage
{
    class CMatrixNode;

    static inline BB_FUNCTION_PTR(void, __thiscall, fpCMatrixNodeCtor, 0x6F4530, CMatrixNode* This);
    static inline BB_FUNCTION_PTR(void, __thiscall, fpCMatrixNodeNotifyChanged, 0x6F3CB0, CMatrixNode* This);

    class CMatrixNode : public Base::CObject
    {
    public:
        BB_INSERT_PADDING(0x5C);

        CMatrixNode(const bb_null_ctor& nil) : CObject(nil) {}

        CMatrixNode()
        {
            fpCMatrixNodeCtor(this);
        }

        virtual ~CMatrixNode() = default;
        virtual void UpdateMatrix(CMatrixNode* in_pParentMatrixNode) = 0;
        virtual const Hedgehog::Math::CMatrix& GetLocalMatrix() const = 0;
        virtual const Hedgehog::Math::CMatrix& GetWorldMatrix() const = 0;

        void NotifyChanged()
        {
            fpCMatrixNodeNotifyChanged(this);
        }
    };

    BB_ASSERT_SIZEOF(CMatrixNode, 0x60);
}