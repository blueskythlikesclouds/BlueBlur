namespace Hedgehog::Base
{
    inline CSynchronizedPtrBase::CSynchronizedPtrBase(CSynchronizedObject* in_pObject) : m_pObject(in_pObject)
    {}

    inline CSynchronizedPtrBase::CSynchronizedPtrBase(const CSynchronizedPtrBase& in_rOther) = default;

    inline CSynchronizedPtrBase::CSynchronizedPtrBase(CSynchronizedPtrBase&& io_rOther) : m_pObject(io_rOther.m_pObject)
    {
        io_rOther.m_pObject = nullptr;
    }

    inline CSynchronizedPtrBase& CSynchronizedPtrBase::operator=(CSynchronizedObject* const in_pObject)
    {
        m_pObject = in_pObject;
        return *this;
    }

    inline CHolderBase CSynchronizedPtrBase::get() const
    {
        return CHolderBase(m_pObject);
    }

    inline CHolderBase CSynchronizedPtrBase::operator->() const
    {
        return get();
    }

    inline CHolderBase CSynchronizedPtrBase::operator*() const
    {
        return get();
    }

    inline CSynchronizedPtrBase::operator bool() const
    {
        return m_pObject != nullptr;
    }
}