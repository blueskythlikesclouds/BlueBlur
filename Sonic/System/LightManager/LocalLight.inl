namespace Sonic
{
    inline CLocalLight::CLocalLight() : m_RefCount(0), m_Dirty(true)
    {
    }

    inline size_t CLocalLight::AddRef()
    {
        return ++m_RefCount;
    }

    inline size_t CLocalLight::Release()
    {
        if (--m_RefCount == 0)
        {
            delete this;
            return 0;
        }

        return m_RefCount;
    }

    inline void CLocalLight::SetPosition(const Hedgehog::Math::CVector& in_rPosition)
    {
        m_Dirty |= m_spLight->m_Position != in_rPosition;
        m_spLight->m_Position = in_rPosition;
    }

    inline void CLocalLight::SetRange(const Hedgehog::Math::CVector4& in_rRange)
    {
        m_Dirty |= m_spLight->m_Range != in_rRange;
        m_spLight->m_Range = in_rRange;
    }
}