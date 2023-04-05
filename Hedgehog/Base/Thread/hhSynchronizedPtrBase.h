#pragma once

#include <Hedgehog/Base/Thread/hhHolderBase.h>

namespace Hedgehog::Base
{
    class CSynchronizedObject;

    class CSynchronizedPtrBase
    {
        CSynchronizedObject* m_pObject;

    public:
        CSynchronizedPtrBase(CSynchronizedObject* in_pObject) : m_pObject(in_pObject) {}

        CSynchronizedPtrBase(const CSynchronizedPtrBase& in_rOther) = default;
        CSynchronizedPtrBase(CSynchronizedPtrBase&& io_rOther) : m_pObject(io_rOther.m_pObject)
        {
            io_rOther.m_pObject = nullptr;
        }

        CSynchronizedPtrBase& operator=(CSynchronizedObject* const in_pObject)
        {
            m_pObject = in_pObject;
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