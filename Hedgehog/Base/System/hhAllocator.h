#pragma once

#include <BlueBlur.inl>

#ifdef BB_ENABLE_ALLOCATION_TRACKER
#include <unordered_map>

static inline struct bb_allocation_tracker
{
    std::unordered_map<std::string, size_t> AllocationCounts;
    mutable CRITICAL_SECTION CriticalSection;

    bb_allocation_tracker()
    {
        InitializeCriticalSection(&CriticalSection);
    }

    ~bb_allocation_tracker()
    {
        DeleteCriticalSection(&CriticalSection);
    }

    bool IsAllEmpty() const
    {
        bool allEmpty = true;

        EnterCriticalSection(&CriticalSection);

        for (auto& [key, value] : AllocationCounts)
            allEmpty &= value == 0;
            
        LeaveCriticalSection(&CriticalSection);

        return allEmpty;
    }

    template<typename T>
    void Increment()
    {
        EnterCriticalSection(&CriticalSection);
        ++AllocationCounts[typeid(T).name()];
        LeaveCriticalSection(&CriticalSection);
    }

    template<typename T>
    void Decrement()
    {
        EnterCriticalSection(&CriticalSection);
        --AllocationCounts[typeid(T).name()];
        LeaveCriticalSection(&CriticalSection);
    }

} g_bb_allocation_tracker;

#endif

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
#ifdef BB_ENABLE_ALLOCATION_TRACKER
            g_bb_allocation_tracker.Increment<T>();
#endif
            return reinterpret_cast<value_type*>(__HH_ALLOC(n * sizeof(value_type)));
        }

        void deallocate(value_type* p, std::size_t) noexcept
        {
#ifdef BB_ENABLE_ALLOCATION_TRACKER
            if (p) g_bb_allocation_tracker.Decrement<T>();
#endif
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