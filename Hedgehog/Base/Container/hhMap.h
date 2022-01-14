#pragma once

#include "detail/xtree"
#include <map>

#include <Hedgehog/Base/System/hhAllocator.h>

namespace Hedgehog
{
    template<class TKey, class TValue, class TComparer = std::less<TKey>,
        class TAllocator = Base::TAllocator<std::pair<const TKey, TValue>>>
    class map :

#if _ITERATOR_DEBUG_LEVEL == 0
        bb_insert_padding<4>,
#endif

        public std::map<TKey, TValue, TComparer, TAllocator>
    {
    public:
        using std::map<TKey, TValue, TComparer, TAllocator>::map;
    };

    BB_ASSERT_SIZEOF((map<void*, void*>), 0xC);
}

namespace hh = Hedgehog;