#pragma once

#include <Hedgehog/MirageCore/MatrixNode/hhMatrixNode.h>
#include <Hedgehog/MirageCore/Misc/hhTransform.h>

namespace Sonic
{
    class CMatrixNodeTransform;

    static uint32_t pCMatrixNodeTransformCtor = 0xD172B0;

    static void fCMatrixNodeTransformCtor(CMatrixNodeTransform* This)
    {
        __asm
        {
            mov edi, This
            call[pCMatrixNodeTransformCtor]
        }
    }

    static inline BB_FUNCTION_PTR(void, __thiscall, fpCMatrixNodeTransformSetChild, 0x6F46B0,
        Hedgehog::Mirage::CMatrixNode* This, Hedgehog::Mirage::CMatrixNode* in_pChildMatrixNode);

    static inline BB_FUNCTION_PTR(void, __thiscall, fpCMatrixNodeTransformUpdateMatrix, 0xD17170,
        Hedgehog::Mirage::CMatrixNode* This, Hedgehog::Mirage::CMatrixNode* in_pParentMatrixNode);

    class CMatrixNodeTransform : public Hedgehog::Mirage::CMatrixNode
    {
    public:
        Hedgehog::Mirage::CTransform m_Transform;
        Hedgehog::Math::CMatrix m_WorldMatrix;

        CMatrixNodeTransform()
        {
            fCMatrixNodeTransformCtor(this);
        }

        void SetParent(CMatrixNode* in_pParentNode)
        {
            fpCMatrixNodeTransformSetChild(in_pParentNode, this);
        }
        void SetChild(CMatrixNode* in_pChildNode)
        {
            fpCMatrixNodeTransformSetChild(this, in_pChildNode);
        }

        void UpdateMatrix(CMatrixNode* in_pParentMatrixNode) override
        {
            fpCMatrixNodeTransformUpdateMatrix(this, in_pParentMatrixNode);
        }

        const Hedgehog::Math::CMatrix& GetLocalMatrix() const override
        {
            return m_Transform.m_Matrix;
        }
        const Hedgehog::Math::CMatrix& GetWorldMatrix() const override
        {
            return m_WorldMatrix;
        }
    };

    BB_ASSERT_OFFSETOF(CMatrixNodeTransform, m_Transform, 0x60);
    BB_ASSERT_OFFSETOF(CMatrixNodeTransform, m_WorldMatrix, 0xC0);
    BB_ASSERT_SIZEOF(CMatrixNodeTransform, 0x100);
}