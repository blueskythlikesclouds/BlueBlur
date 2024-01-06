#pragma once

#include <Hedgehog/Base/hhObject.h>

namespace Hedgehog::Mirage
{
    class CDirector : public Hedgehog::Base::CObject
    {
    public:
        virtual ~CDirector() = default;
    };

    BB_ASSERT_SIZEOF(CDirector, 0x4);
}