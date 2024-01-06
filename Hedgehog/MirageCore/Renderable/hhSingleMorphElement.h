#pragma once

#include <Hedgehog/MirageCore/Renderable/hhSingleElement.h>

namespace Hedgehog::Mirage
{
    class CSingleMorphElement : public CSingleElement
    {
    public:
        CSingleMorphElement(const bb_null_ctor& nil) : CSingleElement(nil) {}
        CSingleMorphElement(const boost::shared_ptr<CModelData>& in_spModelData);
    };
}

#include <Hedgehog/MirageCore/Renderable/hhSingleMorphElement.inl>