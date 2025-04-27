namespace Sonic
{
    inline CObjectEdgeEmissionEffect::CObjectEdgeEmissionEffect()
    {
        *reinterpret_cast<size_t*>(this) = ms_pVtbl;
    }

    inline CObjectEdgeEmissionEffect::CObjectEdgeEmissionEffect(float in_RateOfChange) : m_RateOfChange(in_RateOfChange)
    {
        *reinterpret_cast<size_t*>(this) = ms_pVtbl;
    }
}
