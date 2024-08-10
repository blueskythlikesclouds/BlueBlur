namespace Sonic::Player
{
    inline CPlayerSpeedContext* CPlayerSpeed::GetContext() const
    {
        return static_cast<CPlayerSpeedContext*>(m_spContext.get());
    }
}