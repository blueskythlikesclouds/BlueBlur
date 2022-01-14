#pragma once

#include <vector>
#include <Hedgehog/Base/System/hhAllocator.h>

namespace Hedgehog
{
    template<typename T, typename TAllocator = Base::TAllocator<T>>
    class vector : 

#if !_HAS_ITERATOR_DEBUGGING
        bb_insert_padding<4>, 
#endif

        public std::vector<T, TAllocator>
    {
    public:
        using std::vector<T, TAllocator>::vector;
    };

    BB_ASSERT_SIZEOF(vector<void*>, 0x10);
}

namespace hh = Hedgehog;