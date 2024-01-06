namespace Chao::CSD
{
    inline BB_FUNCTION_PTR(void, __thiscall, fpRCPtrSetAbs, 0x674810, RCPtrAbs* This, const RCPtrAbs& in_rPtr);

    inline RCPtrAbs::RCPtrAbs()
    {
        AttachAbs(nullptr);
    }

    inline RCPtrAbs::RCPtrAbs(void* in_pMemory)
    {
        AttachAbs(in_pMemory);
    }

    inline RCPtrAbs::RCPtrAbs(const RCPtrAbs& in_rOther)
    {
        SetAbs(in_rOther);
    }

    inline RCPtrAbs::RCPtrAbs(RCPtrAbs&& in_rPtr) : m_pObject(in_rPtr.m_pObject)
    {
        in_rPtr.m_pObject = nullptr;
    }

    inline BB_FUNCTION_PTR(void, __thiscall, fpRCPtrAbsAttachAbs, 0x6747D0, RCPtrAbs* This, void* in_pMemory);

    inline void RCPtrAbs::AttachAbs(void* in_pMemory)
    {
        fpRCPtrAbsAttachAbs(this, in_pMemory);
    }

    inline void RCPtrAbs::SetAbs(const RCPtrAbs& in_rPtr)
    {
        fpRCPtrSetAbs(this, in_rPtr);
    }

    inline void* RCPtrAbs::operator*() const
    {
        return GetAbs();
    }

    inline void* RCPtrAbs::operator->() const
    {
        return GetAbs();
    }

    inline RCPtrAbs& RCPtrAbs::operator=(const RCPtrAbs& in_rPtr)
    {
        SetAbs(in_rPtr);
        return *this;
    }

    inline RCPtrAbs::operator bool() const
    {
        return m_pObject != nullptr;
    }
}