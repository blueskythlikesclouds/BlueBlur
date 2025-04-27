#pragma once

#include <Hedgehog/Base/Container/hhVector.h>

namespace Sonic
{
    template<typename T>
    class TFuncList
    {
    public:
        hh::vector<boost::function1<void, T>> m_Container;
    };
}