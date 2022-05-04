#pragma once

#include <BlueBlur.inl>

namespace Chao::CSD
{
    class RCPtrAbs;

    static inline BB_FUNCTION_PTR(void, __thiscall, fpRCPtrAbsAttachAbs, 0x6747D0, RCPtrAbs* This, void* in_pMemory);
    static inline BB_FUNCTION_PTR(void, __thiscall, fpRCPtrSetAbs, 0x674810, RCPtrAbs* This, const RCPtrAbs& in_rPtr);

    class RCPtrAbs
    {
    public:
        class RCObject;

        RCObject* m_pObject{};

        RCPtrAbs()
        {
            AttachAbs(nullptr);
        }

        RCPtrAbs(const RCPtrAbs& in_rOther)
        {
            SetAbs(in_rOther);
        }

        RCPtrAbs(RCPtrAbs&& in_rPtr) : m_pObject(in_rPtr.m_pObject)
        {
            in_rPtr.m_pObject = nullptr;
        }

        virtual ~RCPtrAbs();
        virtual RCObject* CreateRCObject() = 0;

        void AttachAbs(void* in_pMemory)
        {
            fpRCPtrAbsAttachAbs(this, in_pMemory);
        }

        void* GetAbs() const;

        void SetAbs(const RCPtrAbs& in_rPtr)
        {
            fpRCPtrSetAbs(this, in_rPtr);
        }

        void* operator*() const
        {
            return GetAbs();
        }

        void* operator->() const
        {
            return GetAbs();
        }

        RCPtrAbs& operator=(const RCPtrAbs& in_rPtr)
        {
            SetAbs(in_rPtr);
            return *this;
        }
    };
}