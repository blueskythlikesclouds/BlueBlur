namespace Hedgehog::Mirage
{
    inline CMatrixNodeNormal::CMatrixNodeNormal()
    {
        *reinterpret_cast<size_t*>(this) = ms_pVtbl;
    }

    inline CMatrixNodeNormal::CMatrixNodeNormal(const Math::CMatrix& in_rMatrix) : m_LocalMatrix(in_rMatrix), m_WorldMatrix(in_rMatrix)
    {
        *reinterpret_cast<size_t*>(this) = ms_pVtbl;
    }

    inline BB_FUNCTION_PTR(void, __thiscall, fpCMatrixNodeNormalUpdateMatrix, 0x6F3A30, CMatrixNodeNormal* This, CMatrixNode* in_pParent);

    inline void CMatrixNodeNormal::UpdateMatrix(CMatrixNode* in_pParentMatrixNode)
    {
        fpCMatrixNodeNormalUpdateMatrix(this, in_pParentMatrixNode);
    }

    inline const Math::CMatrix& CMatrixNodeNormal::GetLocalMatrix() const
    {
        return m_LocalMatrix;
    }

    inline const Math::CMatrix& CMatrixNodeNormal::GetWorldMatrix() const
    {
        return m_WorldMatrix;
    }
}