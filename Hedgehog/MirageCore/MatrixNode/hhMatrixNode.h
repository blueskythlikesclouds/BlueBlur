#pragma once

#include <BlueBlur.inl>
#include <Hedgehog/Base/hhObject.h>

namespace Hedgehog::Mirage
{
    class CMatrixNode : public Base::CObject
    {
    public:
        BB_INSERT_PADDING(0x5C);

        virtual ~CMatrixNode() = default;
    };

    BB_ASSERT_SIZEOF(CMatrixNode, 0x60);
}