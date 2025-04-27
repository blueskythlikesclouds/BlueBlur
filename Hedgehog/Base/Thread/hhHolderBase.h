#pragma once

#include <BlueBlur.inl>

namespace Hedgehog::Base
{
    class CSynchronizedObject;

    class CHolderBase
    {
    protected:
        CSynchronizedObject* m_pSynchronizedObject;
        bool m_Locked;

    public:
        CHolderBase() : m_pSynchronizedObject(nullptr), m_Locked(false) {}
        CHolderBase(CSynchronizedObject* in_pSynchronizedObject, bool in_ForceSync = false);
        CHolderBase(CHolderBase&& io_rOther);
        CHolderBase(const CHolderBase& in_rOther);
        ~CHolderBase();

        CSynchronizedObject* get() const;
        CSynchronizedObject* operator->() const;
        CSynchronizedObject* operator*() const;

        explicit operator bool() const;
    };

    BB_ASSERT_SIZEOF(CHolderBase, 0x8);
}

#include <Hedgehog/Base/Thread/hhHolderBase.inl>