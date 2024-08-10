namespace Chao::CSD
{
    template <typename T>
    void CResourceBase<T>::CopyResource(const CResourceBase& in_rOther)
    {
        m_rcData = in_rOther.m_rcData;
        m_DataSize = in_rOther.m_DataSize;
    }
}