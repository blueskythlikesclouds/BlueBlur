namespace Sonic::Player
{
    inline CSonicClassicContext* CSonicClassicContext::GetInstance()
    {
        return *ms_pInstance;
    }
}