#pragma once

#include <Hedgehog/MirageCore/Renderable/hhSingleElement.h>

namespace Hedgehog::Mirage
{
    class CSingleMorphElement;

    static inline BB_FUNCTION_PTR(CSingleMorphElement*, __thiscall, fpCSingleMorphElementCtor, 0x007040B0,
        CSingleMorphElement* This, const boost::shared_ptr<CModelData>& in_spModelData);

    class CSingleMorphElement : public CSingleElement
    {
    public:
        CSingleMorphElement(const bb_null_ctor& nil) : CSingleElement(nil) {}

        CSingleMorphElement(const boost::shared_ptr<CModelData>& in_spModelData) : CSingleMorphElement(bb_null_ctor{})
        {
            fpCSingleMorphElementCtor(this, in_spModelData);
        }
    };
}
