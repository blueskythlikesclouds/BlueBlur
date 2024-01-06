namespace Hedgehog::Base
{
    inline CCriticalSectionD3D9::CCriticalSectionD3D9()
    {
        InitializeCriticalSection(&m_CriticalSection);
    }

    inline CCriticalSectionD3D9::~CCriticalSectionD3D9()
    {
        DeleteCriticalSection(&m_CriticalSection);
    }

    inline void CCriticalSectionD3D9::Enter()
    {
        EnterCriticalSection(&m_CriticalSection);
    }

    inline void CCriticalSectionD3D9::Leave()
    {
        LeaveCriticalSection(&m_CriticalSection);
    }
}