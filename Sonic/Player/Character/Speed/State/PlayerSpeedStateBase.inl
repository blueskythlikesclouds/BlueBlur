namespace Sonic::Player
{
    inline uint32_t pCStateSpeedBaseCtor = 0xE497E0;

    inline void fCStateSpeedBaseCtor(CPlayerSpeedContext::CStateSpeedBase* This)
    {
        __asm
        {
            mov edi, This
            call[pCStateSpeedBaseCtor]
        }
    }

    inline CPlayerSpeedContext::CStateSpeedBase::CStateSpeedBase() : CStateSpeedBase(bb_null_ctor{})
    {
        fCStateSpeedBaseCtor(this);
    }

    inline uint32_t pCStateSpeedBaseSetBool = 0x50DD40;

    inline void fCStateSpeedBaseSetBool(CPlayerSpeedContext::CStateSpeedBase* This, const Hedgehog::Base::CSharedString& in_rName, const bool& in_rValue)
    {
        __asm
        {
            push in_rValue
            mov eax, This
            mov edi, in_rName
            call[pCStateSpeedBaseSetBool]
        }
    }

    inline void CPlayerSpeedContext::CStateSpeedBase::SetBool(const Hedgehog::Base::CSharedString& in_rName,
        const bool& in_rValue)
    {
        fCStateSpeedBaseSetBool(this, in_rName, in_rValue);
    }

    inline CPlayerSpeedContext* CPlayerSpeedContext::CStateSpeedBase::GetContext() const
    {
        return static_cast<CPlayerSpeedContext*>(m_pContext);
    }
}