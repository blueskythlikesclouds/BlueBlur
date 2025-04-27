namespace Sonic
{
    inline uint32_t pCMatrixNodeTransformCtor = 0xD172B0;

    inline BB_NOINLINE void fCMatrixNodeTransformCtor(CMatrixNodeTransform* This)
    {
        __asm
        {
            mov edi, This
            call[pCMatrixNodeTransformCtor]
        }
    }

    inline CMatrixNodeTransform::CMatrixNodeTransform()
    {
        fCMatrixNodeTransformCtor(this);
    }

    inline BB_FUNCTION_PTR(void, __thiscall, fpCMatrixNodeTransformUpdateMatrix, 0xD17170,
        Hedgehog::Mirage::CMatrixNode* This, Hedgehog::Mirage::CMatrixNode* in_pParentMatrixNode);

    inline void CMatrixNodeTransform::UpdateMatrix(CMatrixNode* in_pParentMatrixNode)
    {
        fpCMatrixNodeTransformUpdateMatrix(this, in_pParentMatrixNode);
    }

    inline const Hedgehog::Math::CMatrix& CMatrixNodeTransform::GetLocalMatrix() const
    {
        return m_Transform.m_Matrix;
    }

    inline const Hedgehog::Math::CMatrix& CMatrixNodeTransform::GetWorldMatrix() const
    {
        return m_WorldMatrix;
    }
}