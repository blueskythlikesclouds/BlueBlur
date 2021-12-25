#pragma once

#include <Hedgehog/Base/Thread/hhHolder.h>

namespace Hedgehog::Base
{
    template<typename T, bool ForceSync = false>
    class TSynchronizedPtr
    {
        T* m_pObject;

    public:
        TSynchronizedPtr(T* pObject) : m_pObject(pObject) {}

        TSynchronizedPtr(const TSynchronizedPtr& other) = default;
        TSynchronizedPtr(TSynchronizedPtr&& other) : m_pObject(other.m_pObject)
        {
            other.m_pObject = nullptr;
        }

        TSynchronizedPtr<T, ForceSync>& operator=(T* const pObject)
        {
            m_pObject = pObject;
            return *this;
        }

        THolder<T, ForceSync> get() const
        {
            return THolder<T, ForceSync>(m_pObject);
        }

        THolder<T, ForceSync> operator->() const
        {
            return get();
        }

        THolder<T, ForceSync> operator*() const
        {
            return get();
        }
    };
}