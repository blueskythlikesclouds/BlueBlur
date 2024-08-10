namespace Sonic::Player
{
    inline CSonicSpContext* CSonicSpContext::GetInstance()
    {
        return *ms_pInstance;
    }
}