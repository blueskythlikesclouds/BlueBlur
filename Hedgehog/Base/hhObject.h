#pragma once

#include <Hedgehog/Base/System/hhAllocator.h>

namespace Hedgehog::Base
{
    class CObject
    {
    public:
        CObject() {}
        CObject(const bb_null_ctor&) {}

        void* operator new(const size_t in_Size)
        {
            return __HH_ALLOC(in_Size);
        }

        void* operator new(const size_t in_Size, const size_t in_Align)
        {
            return __HH_ALLOCALIGN(in_Size, in_Align);
        }

        void operator delete(void* in_pMem)
        {
            return __HH_FREE(in_pMem);
        }

        void* operator new(const size_t in_Size, void* in_pObj)
        {
            return in_pObj;
        }

        void* operator new(const size_t in_Size, const size_t in_Align, void* in_pObj)
        {
            return in_pObj;
        }

        void operator delete(void* in_pMem, void* in_pObj)
        {
        }
    };
}