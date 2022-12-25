#pragma once

#include <BlueBlur.inl>

namespace Hedgehog::Base
{
    class CHolderBase;
    class CSynchronizedObject;

    static inline BB_FUNCTION_PTR(void, __thiscall, fpCHolderBaseCtor, 0x65FBE0, CHolderBase* This, CSynchronizedObject* pSynchronizedObject, bool forceSync);
    static inline BB_FUNCTION_PTR(void, __thiscall, fpCHolderBaseDtor, 0x65FC40, CHolderBase* This);

    class CHolderBase
    {
    protected:
        CSynchronizedObject* m_pSynchronizedObject;
        bool m_Locked;

    public:
        CHolderBase() : m_pSynchronizedObject(nullptr), m_Locked(false)
        {
            
        }

        CHolderBase(CSynchronizedObject* pSynchronizedObject, bool forceSync = false)
        {
            fpCHolderBaseCtor(this, pSynchronizedObject, forceSync);
        }

        CHolderBase(CHolderBase&& other)
        {
            m_pSynchronizedObject = other.m_pSynchronizedObject;
            m_Locked = other.m_Locked;

            other.m_pSynchronizedObject = nullptr;
            other.m_Locked = false;
        }

        CHolderBase(const CHolderBase& other) = delete;

        ~CHolderBase()
        {
            fpCHolderBaseDtor(this);
        }

        CSynchronizedObject* get() const
        {
            return m_pSynchronizedObject;
        }

        CSynchronizedObject* operator->() const
        {
            return get();
        }

        CSynchronizedObject* operator*() const
        {
            return get();
        }

        explicit operator bool() const
        {
            return m_pSynchronizedObject != nullptr;
        }
    };

    BB_ASSERT_SIZEOF(CHolderBase, 0x8);
}