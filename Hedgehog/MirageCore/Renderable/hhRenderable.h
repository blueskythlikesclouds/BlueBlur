#pragma once

#include <BlueBlur.inl>
#include <Hedgehog/Base/hhObject.h>

namespace Hedgehog::Mirage
{
    class CRenderable;

    static inline BB_FUNCTION_PTR(CRenderable*, __thiscall, fpCRenderableCtor, 0x6F49C0, CRenderable* This);

    class CRenderable : public Base::CObject
    {
    public:
        BB_INSERT_PADDING(0x8);

        CRenderable(const bb_null_ctor&) : CObject(bb_null_ctor{}) {}

        CRenderable() : CRenderable(bb_null_ctor{})
        {
            fpCRenderableCtor(this);
        }

        virtual ~CRenderable() = default;
    };

    BB_ASSERT_SIZEOF(CRenderable, 0xC);
}