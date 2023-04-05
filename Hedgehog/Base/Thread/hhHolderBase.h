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

        CHolderBase(CSynchronizedObject* in_pSynchronizedObject, bool in_ForceSync = false)
        {
            fpCHolderBaseCtor(this, in_pSynchronizedObject, in_ForceSync);
        }

        CHolderBase(CHolderBase&& io_rOther)
        {
            m_pSynchronizedObject = io_rOther.m_pSynchronizedObject;
            m_Locked = io_rOther.m_Locked;

            io_rOther.m_pSynchronizedObject = nullptr;
            io_rOther.m_Locked = false;
        }

        CHolderBase(const CHolderBase& in_rOther) = delete;

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