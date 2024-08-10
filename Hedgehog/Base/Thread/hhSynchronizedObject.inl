namespace Hedgehog::Base
{
    inline BB_FUNCTION_PTR(void, __thiscall, fpCSynchronizedObjectEnterCriticalSection, 0x6652B0, CSynchronizedObject* This);

    inline void CSynchronizedObject::EnterCriticalSection()
    {
        fpCSynchronizedObjectEnterCriticalSection(this);
    }

    inline BB_FUNCTION_PTR(void, __thiscall, fpCSynchronizedObjectLeaveCriticalSection, 0x6651C0, CSynchronizedObject* This);

    inline void CSynchronizedObject::LeaveCriticalSection()
    {
        fpCSynchronizedObjectLeaveCriticalSection(this);
    }
}