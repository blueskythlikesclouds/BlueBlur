namespace Hedgehog::Mirage
{
    inline void CPose::GetMatrix(size_t in_Index, Math::CMatrix& out_rMatrix) const
    {
        out_rMatrix = GetMatrixList()[in_Index];
    }
}