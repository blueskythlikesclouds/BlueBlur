namespace Sonic::Player
{
    inline CSonicSpContext* CSonicSp::GetContext() const
    {
        return static_cast<CSonicSpContext*>(m_spContext.get());
    }
}