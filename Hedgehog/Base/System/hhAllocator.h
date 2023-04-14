#pragma once

#include <BlueBlur.inl>

static inline BB_FUNCTION_PTR(void*, __cdecl, __HH_ALLOC, 0x65FC60, const size_t in_Size);
static inline BB_FUNCTION_PTR(void*, __cdecl, __HH_ALLOCALIGN, 0x65FCE0, const size_t in_Size, const size_t in_Align);
static inline BB_FUNCTION_PTR(void, __cdecl, __HH_FREE, 0x65FD70, void* in_pData);

namespace Hedgehog::Base
{
    template <class T>
    class TAllocator
    {
    public:
        using value_type = T;

        TAllocator() noexcept {} 
        template <class U> TAllocator(TAllocator<U> const&) noexcept {}

        value_type* allocate(std::size_t n)
        {
            return reinterpret_cast<value_type*>(__HH_ALLOC(n * sizeof(value_type)));
        }

        void deallocate(value_type* p, std::size_t) noexcept
        {
            __HH_FREE(reinterpret_cast<void*>(p));
        }
    };

    template <class T, class U>
    bool operator==(TAllocator<T> const&, TAllocator<U> const&) noexcept
    {
        return true;
    }

    template <class T, class U>
    bool operator!=(TAllocator<T> const& x, TAllocator<U> const& y) noexcept
    {
        return !(x == y);
    }
}