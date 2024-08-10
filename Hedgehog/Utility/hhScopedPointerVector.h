#pragma once

#include <Hedgehog/Base/Container/hhVector.h>

namespace Hedgehog::Base
{
    template<typename T>
    class CScopedPointerVector : public hh::vector<boost::scoped_ptr<T>>
    {
    public:
        using hh::vector<boost::scoped_ptr<T>, TAllocator<boost::scoped_ptr<T>>>::vector;
    };
}