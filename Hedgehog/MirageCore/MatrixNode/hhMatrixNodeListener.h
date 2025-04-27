#pragma once

#include <Hedgehog/Base/hhObject.h>

namespace Hedgehog::Mirage
{
    class CMatrixNodeListener : public Base::CObject
    {
    public:
        CMatrixNodeListener(const bb_null_ctor&) {}
        CMatrixNodeListener() {}

        virtual ~CMatrixNodeListener() = default;
        virtual bool MatrixNodeChangedCallback(const Hedgehog::Math::CMatrix& in_rMatrix, size_t in_Flags) = 0;
    };
}