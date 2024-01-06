#pragma once

#include <Hedgehog/Base/Thread/hhHolder.h>

namespace Hedgehog::Base
{
    template<typename T, bool ForceSync = false>
    class TSynchronizedPtr
    {
        T* m_pObject;

    public:
        TSynchronizedPtr(T* in_pObject) : m_pObject(in_pObject) {}
        TSynchronizedPtr() : m_pObject(nullptr) {}

        TSynchronizedPtr(const TSynchronizedPtr& in_rOther) = default;
        TSynchronizedPtr(TSynchronizedPtr&& io_rOther) : m_pObject(io_rOther.m_pObject)
        {
            io_rOther.m_pObject = nullptr;
        }

        TSynchronizedPtr<T, ForceSync>& operator=(T* const in_pObject)
        {
            m_pObject = in_pObject;
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

        explicit operator bool() const
        {
            return m_pObject != nullptr;
        }
    };
}