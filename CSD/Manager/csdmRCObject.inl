namespace Chao::CSD
{
    inline BB_FUNCTION_PTR(void, __thiscall, fpRCPtrAbsRCObjectRelease, 0x6745D0, RCPtrAbs::RCObject* This);

    inline void RCPtrAbs::RCObject::Release()
    {
        fpRCPtrAbsRCObjectRelease(this);
    }

    inline RCPtrAbs::~RCPtrAbs()
    {
        RCObject* pObj = m_pObject;
        m_pObject = nullptr;

        if (pObj)
            pObj->Release();
    }

    inline void* RCPtrAbs::GetAbs() const
    {
        if (!m_pObject)
            return nullptr;

        return m_pObject->m_pMemory;
    }
}