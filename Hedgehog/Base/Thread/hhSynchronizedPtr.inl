namespace Hedgehog::Base
{
    template <typename T, bool ForceSync>
    TSynchronizedPtr<T, ForceSync>::TSynchronizedPtr(T* in_pObject) : m_pObject(in_pObject)
    {}

    template <typename T, bool ForceSync>
    TSynchronizedPtr<T, ForceSync>::TSynchronizedPtr() : m_pObject(nullptr)
    {}

    template <typename T, bool ForceSync>
    TSynchronizedPtr<T, ForceSync>::TSynchronizedPtr(const TSynchronizedPtr& in_rOther) = default;

    template <typename T, bool ForceSync>
    TSynchronizedPtr<T, ForceSync>::TSynchronizedPtr(TSynchronizedPtr&& io_rOther) : m_pObject(io_rOther.m_pObject)
    {
        io_rOther.m_pObject = nullptr;
    }

    template <typename T, bool ForceSync>
    TSynchronizedPtr<T, ForceSync>& TSynchronizedPtr<T, ForceSync>::operator=(T* const in_pObject)
    {
        m_pObject = in_pObject;
        return *this;
    }

    template <typename T, bool ForceSync>
    THolder<T, ForceSync> TSynchronizedPtr<T, ForceSync>::get() const
    {
        return THolder<T, ForceSync>(m_pObject);
    }

    template <typename T, bool ForceSync>
    THolder<T, ForceSync> TSynchronizedPtr<T, ForceSync>::operator->() const
    {
        return get();
    }

    template <typename T, bool ForceSync>
    THolder<T, ForceSync> TSynchronizedPtr<T, ForceSync>::operator*() const
    {
        return get();
    }

    template <typename T, bool ForceSync>
    TSynchronizedPtr<T, ForceSync>::operator bool() const
    {
        return m_pObject != nullptr;
    }
}