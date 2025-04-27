namespace Hedgehog::Base
{
    template <typename T, bool ForceSync>
    T* THolder<T, ForceSync>::get() const
    {
        return static_cast<T*>(m_pSynchronizedObject);
    }

    template <typename T, bool ForceSync>
    T* THolder<T, ForceSync>::operator->() const
    {
        return get();
    }

    template <typename T, bool ForceSync>
    T* THolder<T, ForceSync>::operator*() const
    {
        return get();
    }
}