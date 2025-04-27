#pragma once

#include <BlueBlur.inl>

namespace Hedgehog::Base
{
    class CCriticalSectionD3D9;

    class CSynchronizedObject
    {
    public:
        boost::shared_ptr<CCriticalSectionD3D9>* m_pCriticalSection;

        void EnterCriticalSection();
        void LeaveCriticalSection();
    };

    BB_ASSERT_OFFSETOF(CSynchronizedObject, m_pCriticalSection, 0x0);
    BB_ASSERT_SIZEOF(CSynchronizedObject, 0x4);
}

#include <Hedgehog/Base/Thread/hhSynchronizedObject.inl>