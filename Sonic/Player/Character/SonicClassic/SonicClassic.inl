namespace Sonic::Player
{
    inline CSonicClassicContext* CSonicClassic::GetContext() const
    {
        return static_cast<CSonicClassicContext*>(m_spContext.get());
    }
}