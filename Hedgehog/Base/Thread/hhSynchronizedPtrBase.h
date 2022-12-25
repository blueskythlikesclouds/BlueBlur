#pragma once

#include <Hedgehog/Base/Thread/hhHolderBase.h>

namespace Hedgehog::Base
{
    class CSynchronizedObject;

    class CSynchronizedPtrBase
    {
        CSynchronizedObject* m_pObject;

    public:
        CSynchronizedPtrBase(CSynchronizedObject* pObject) : m_pObject(pObject) {}

        CSynchronizedPtrBase(const CSynchronizedPtrBase& other) = default;
        CSynchronizedPtrBase(CSynchronizedPtrBase&& other) : m_pObject(other.m_pObject)
        {
            other.m_pObject = nullptr;
        }

        CSynchronizedPtrBase& operator=(CSynchronizedObject* const pObject)
        {
            m_pObject = pObject;
            return *this;
        }

        CHolderBase get() const
        {
            return CHolderBase(m_pObject);
        }

        CHolderBase operator->() const
        {
            return get();
        }

        CHolderBase operator*() const
        {
            return get();
        }

        explicit operator bool() const
        {
            return m_pObject != nullptr;
        }
    };
}