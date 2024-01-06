#pragma once

#include <Hedgehog/Base/Thread/hhHolderBase.h>

namespace Hedgehog::Base
{
    class CSynchronizedObject;

    class CSynchronizedPtrBase
    {
        CSynchronizedObject* m_pObject;

    public:
        CSynchronizedPtrBase(CSynchronizedObject* in_pObject);
        CSynchronizedPtrBase(const CSynchronizedPtrBase& in_rOther);
        CSynchronizedPtrBase(CSynchronizedPtrBase&& io_rOther);

        CSynchronizedPtrBase& operator=(CSynchronizedObject* const in_pObject);

        CHolderBase get() const;
        CHolderBase operator->() const;
        CHolderBase operator*() const;

        explicit operator bool() const;
    };
}

#include <Hedgehog/Base/Thread/hhSynchronizedPtrBase.inl>