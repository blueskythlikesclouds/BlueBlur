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
    public:
        CSynchronizedObject* m_pSynchronizedObject;
        bool m_Locked;

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
    };

    BB_ASSERT_OFFSETOF(CHolderBase, m_pSynchronizedObject, 0x0);
    BB_ASSERT_OFFSETOF(CHolderBase, m_Locked, 0x4);
    BB_ASSERT_SIZEOF(CHolderBase, 0x8);
}