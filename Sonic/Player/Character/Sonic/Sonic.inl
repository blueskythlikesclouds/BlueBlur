namespace Sonic::Player
{
    inline CSonicContext* CSonic::GetContext() const
    {
        return static_cast<CSonicContext*>(m_spContext.get());
    }
}