#pragma once

#include <CSD/Manager/csdmRCPtrAbs.h>

namespace Chao::CSD
{
    class RCPtrAbs::RCObject
    {
    public:
        void* m_pMemory;
        size_t m_RefCount;
        void* m_pDealloctor;
        size_t m_eDealloctor;

        virtual ~RCObject();
        virtual void Deallocate(void* in_pMemory) = 0;

        void Release();
    };
}


#include <CSD/Manager/csdmRCObject.inl>