#pragma once

#include <Hedgehog/MirageCore/Renderable/hhRenderable.h>

namespace Hedgehog::Mirage
{
    class CElement;

    static inline BB_FUNCTION_PTR(CElement*, __thiscall, fpCElementCtor, 0x702050, CElement* This);

    class CElement : public CRenderable
    {
    public:
        BB_INSERT_PADDING(0x80);

        CElement(const bb_null_ctor&) : CRenderable(bb_null_ctor{}) {}

        CElement() : CElement(bb_null_ctor{})
        {
            fpCElementCtor(this);
        }
    };

    BB_ASSERT_SIZEOF(CElement, 0x8C);
}