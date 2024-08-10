#pragma once

#include <Hedgehog/Base/hhObject.h>

namespace Hedgehog::Universe
{
    class IMessageProcess : public Base::CObject
    {
    public:
        // Can't replicate RTTI if I add any virtual functions (and an extra vtable gets added),
        // so this is going to stay empty.
        IMessageProcess() {}
        IMessageProcess(const bb_null_ctor& nil) : CObject(nil) {}
    };
}