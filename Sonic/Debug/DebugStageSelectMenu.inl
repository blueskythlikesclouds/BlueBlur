namespace Sonic::StageSelectMenu
{
    inline CDebugStageSelectMenuXml::CDebugStageSelectMenuXml() : m_Name("Select")
    {
        *reinterpret_cast<size_t*>(this) = 0x16A081C;
        *reinterpret_cast<size_t*>(static_cast<CMessageActor*>(this)) = 0x16A085C;

        m_StateMachine.SetContext(this);
    }
}