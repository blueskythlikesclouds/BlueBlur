#pragma once

#include <Hedgehog/MirageCore/Renderable/hhRenderable.h>

namespace Hedgehog::Mirage
{
    class CModelData;

    class CElement : public CRenderable
    {
    public:
        boost::shared_ptr<CModelData> m_spModel;
        BB_INSERT_PADDING(0x78);

        CElement(const bb_null_ctor& nil) : CRenderable(nil) {}
        CElement();
    };

    BB_ASSERT_OFFSETOF(CElement, m_spModel, 0xC);
    BB_ASSERT_SIZEOF(CElement, 0x8C);
}

#include <Hedgehog/MirageCore/Renderable/hhElement.inl>