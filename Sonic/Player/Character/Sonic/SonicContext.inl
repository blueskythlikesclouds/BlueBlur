namespace Sonic::Player
{
    inline CSonicContext* CSonicContext::GetInstance()
    {
        return *ms_pInstance;
    }
}