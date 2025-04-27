namespace Hedgehog::Base
{
    inline BB_FUNCTION_PTR(void, __thiscall, fpCHolderBaseCtor, 0x65FBE0, CHolderBase* This, CSynchronizedObject* pSynchronizedObject, bool forceSync);

    inline CHolderBase::CHolderBase(CSynchronizedObject* in_pSynchronizedObject, bool in_ForceSync)
    {
        fpCHolderBaseCtor(this, in_pSynchronizedObject, in_ForceSync);
    }

    inline CHolderBase::CHolderBase(CHolderBase&& io_rOther)
    {
        m_pSynchronizedObject = io_rOther.m_pSynchronizedObject;
        m_Locked = io_rOther.m_Locked;

        io_rOther.m_pSynchronizedObject = nullptr;
        io_rOther.m_Locked = false;
    }

    inline CHolderBase::CHolderBase(const CHolderBase& in_rOther)
    {
        m_pSynchronizedObject = in_rOther.m_pSynchronizedObject;
        m_Locked = false;
    }

    inline BB_FUNCTION_PTR(void, __thiscall, fpCHolderBaseDtor, 0x65FC40, CHolderBase* This);

    inline CHolderBase::~CHolderBase()
    {
        fpCHolderBaseDtor(this);
    }

    inline CSynchronizedObject* CHolderBase::get() const
    {
        return m_pSynchronizedObject;
    }

    inline CSynchronizedObject* CHolderBase::operator->() const
    {
        return get();
    }

    inline CSynchronizedObject* CHolderBase::operator*() const
    {
        return get();
    }

    inline CHolderBase::operator bool() const
    {
        return m_pSynchronizedObject != nullptr;
    }
}