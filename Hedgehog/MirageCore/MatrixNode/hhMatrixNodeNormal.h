#pragma once

#include <Hedgehog/MirageCore/MatrixNode/hhMatrixNode.h>

namespace Hedgehog::Mirage
{
    class CMatrixNodeNormal;

    static inline BB_FUNCTION_PTR(void, __thiscall, fpCMatrixNodeNormalUpdateMatrix, 0x6F3A30, CMatrixNodeNormal* This, CMatrixNode* in_pParent);

    class CMatrixNodeNormal : public CMatrixNode
    {
    private:
        static constexpr size_t ms_pVtbl = 0x13E7018;
    public:
        Math::CMatrix m_LocalMatrix {};
        Math::CMatrix m_WorldMatrix {};

        CMatrixNodeNormal()
        {
            *reinterpret_cast<size_t*>(this) = ms_pVtbl;
        }

        CMatrixNodeNormal(const Math::CMatrix& in_rMatrix) : m_LocalMatrix(in_rMatrix), m_WorldMatrix(in_rMatrix)
        {
            *reinterpret_cast<size_t*>(this) = ms_pVtbl;
        }

        void UpdateMatrix(CMatrixNode* in_pParentMatrixNode) override
        {
            fpCMatrixNodeNormalUpdateMatrix(this, in_pParentMatrixNode);
        }

        const Math::CMatrix& GetLocalMatrix() const override
        {
            return m_LocalMatrix;
        }
        const Math::CMatrix& GetWorldMatrix() const override
        {
            return m_WorldMatrix;
        }
    };

    BB_ASSERT_OFFSETOF(CMatrixNodeNormal, m_LocalMatrix, 0x60);
    BB_ASSERT_OFFSETOF(CMatrixNodeNormal, m_WorldMatrix, 0xA0);
    BB_ASSERT_SIZEOF(CMatrixNodeNormal, 0xE0);
}