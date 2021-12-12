#pragma once

#include <BlueBlur.inl>

namespace Hedgehog::Base
{
    class CCriticalSectionD3D9;
    class CSynchronizedObject;

    static inline BB_FUNCTION_PTR(void, __thiscall, fpCSynchronizedObjectEnterCriticalSection, 0x6652B0, CSynchronizedObject* This);
    static inline BB_FUNCTION_PTR(void, __thiscall, fpCSynchronizedObjectLeaveCriticalSection, 0x6651C0, CSynchronizedObject* This);

    class CSynchronizedObject
    {
    public:
        boost::shared_ptr<CCriticalSectionD3D9>* m_pCriticalSection;

        void EnterCriticalSection()
        {
            fpCSynchronizedObjectEnterCriticalSection(this);
        }

        void LeaveCriticalSection()
        {
            fpCSynchronizedObjectLeaveCriticalSection(this);
        }
    };

    BB_ASSERT_OFFSETOF(CSynchronizedObject, m_pCriticalSection, 0x0);
    BB_ASSERT_SIZEOF(CSynchronizedObject, 0x4);
}