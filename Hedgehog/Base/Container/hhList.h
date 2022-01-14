#pragma once

#include <list>
#include <Hedgehog/Base/System/hhAllocator.h>

namespace Hedgehog
{
    template<typename T, typename TAllocator = Base::TAllocator<T>>
    class list :

#if _ITERATOR_DEBUG_LEVEL == 0
        bb_insert_padding<4>,
#endif

        public std::list<T, TAllocator>
    {
    public:
        using std::list<T, TAllocator>::list;
    };

    BB_ASSERT_SIZEOF(list<void*>, 0xC);
}

namespace hh = Hedgehog;