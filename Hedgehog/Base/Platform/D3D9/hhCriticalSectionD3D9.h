#pragma once

#include <Hedgehog/Base/hhObject.h>

namespace Hedgehog::Base
{
    class CCriticalSectionD3D9 : public CObject
    {
    public:
        RTL_CRITICAL_SECTION m_CriticalSection;

        CCriticalSectionD3D9();
        ~CCriticalSectionD3D9();

        void Enter();
        void Leave();
    };

    BB_ASSERT_OFFSETOF(CCriticalSectionD3D9, m_CriticalSection, 0);
    BB_ASSERT_SIZEOF(CCriticalSectionD3D9, 24);
}

#include <Hedgehog/Base/Platform/D3D9/hhCriticalSectionD3D9.inl>