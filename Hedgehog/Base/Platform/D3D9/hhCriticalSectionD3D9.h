#pragma once

#include <Hedgehog/Base/hhObject.h>

namespace Hedgehog::Base
{
    class CCriticalSectionD3D9 : public CObject
    {
    public:
        RTL_CRITICAL_SECTION m_CriticalSection;

        CCriticalSectionD3D9()
        {
            InitializeCriticalSection(&m_CriticalSection);
        }

        ~CCriticalSectionD3D9()
        {
            DeleteCriticalSection(&m_CriticalSection);
        }

        void Enter()
        {
            EnterCriticalSection(&m_CriticalSection);
        }

        void Leave()
        {
            LeaveCriticalSection(&m_CriticalSection);
        }
    };

    BB_ASSERT_OFFSETOF(CCriticalSectionD3D9, m_CriticalSection, 0);
    BB_ASSERT_SIZEOF(CCriticalSectionD3D9, 24);
}