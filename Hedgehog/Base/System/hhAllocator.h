#pragma once

#include <BlueBlur.inl>

#ifdef BB_ENABLE_ALLOCATION_TRACKER
#include <unordered_map>
#include <unordered_set>

inline struct bb_allocation_tracker
{
    std::unordered_map<std::string, std::unordered_set<void*>> AllocationsByType;
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

        for (auto& [name, allocations] : AllocationsByType)
            allEmpty &= allocations.empty();
            
        LeaveCriticalSection(&CriticalSection);

        return allEmpty;
    }

    template<typename T>
    void Add(T* pMem)
    {
        assert(pMem && "Allocation failure");

        EnterCriticalSection(&CriticalSection);
        AllocationsByType[typeid(T).name()].emplace(pMem);
        LeaveCriticalSection(&CriticalSection);
    }

    template<typename T>
    void Remove(T* pMem)
    {
        EnterCriticalSection(&CriticalSection);

        auto& allocations = AllocationsByType[typeid(T).name()];
        const auto pair = allocations.find(pMem);
        if (pair == allocations.end())
            assert(0 && "Attempted to deallocate twice");
        else
            allocations.erase(pair);

        LeaveCriticalSection(&CriticalSection);
    }

} g_bb_allocation_tracker;

#endif

inline BB_FUNCTION_PTR(void*, __cdecl, __HH_ALLOC, 0x65FC60, const size_t in_Size);
inline BB_FUNCTION_PTR(void*, __cdecl, __HH_ALLOCALIGN, 0x65FCE0, const size_t in_Size, const size_t in_Align);
inline BB_FUNCTION_PTR(void, __cdecl, __HH_FREE, 0x65FD70, void* in_pData);

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
            value_type* pMem = reinterpret_cast<value_type*>(__HH_ALLOC(n * sizeof(value_type)));

#ifdef BB_ENABLE_ALLOCATION_TRACKER
            g_bb_allocation_tracker.Add<T>(pMem);
#endif
            return pMem;
        }

        void deallocate(value_type* p, std::size_t) noexcept
        {
#ifdef BB_ENABLE_ALLOCATION_TRACKER
            if (p) g_bb_allocation_tracker.Remove<T>(p);
#endif
            __HH_FREE(p);
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