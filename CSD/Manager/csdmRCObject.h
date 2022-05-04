#pragma once

#include <CSD/Manager/csdmRCPtrAbs.h>

namespace Chao::CSD
{
    static inline BB_FUNCTION_PTR(void, __thiscall, fpRCPtrAbsRCObjectRelease, 0x6745D0, RCPtrAbs::RCObject* This);

    class RCPtrAbs::RCObject
    {
    public:
        void* m_pMemory;
        size_t m_RefCount;
        void* m_pDealloctor;
        size_t m_eDealloctor;

        virtual ~RCObject();
        virtual void Deallocate(void* in_pMemory) = 0;

        void Release()
        {
            fpRCPtrAbsRCObjectRelease(this);
        }
    };

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
