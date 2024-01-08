#pragma once

#include <Hedgehog/Base/hhObject.h>

namespace Hedgehog::Mirage
{
    class CRenderInfo;

    class CRenderable : public Base::CObject
    {
    public:
        bool m_Enabled;
        float m_Field8;

        CRenderable(const bb_null_ctor& nil) : CObject(nil) {}
        CRenderable();
        virtual ~CRenderable() = default;

        virtual void Render(const CRenderInfo& in_rRenderInfo, Base::CStringSymbol in_RenderLevel, uint32_t in_Unknown) {}

        virtual void CRenderableVtbl08(size_t) {}
        virtual void CRenderableVtbl0C(size_t, size_t) {}
        virtual void CRenderableVtbl10(size_t) {}
    };

    BB_ASSERT_OFFSETOF(CRenderable, m_Enabled, 0x4);
    BB_ASSERT_OFFSETOF(CRenderable, m_Field8, 0x8);
    BB_ASSERT_SIZEOF(CRenderable, 0xC);
}


#include <Hedgehog/MirageCore/Renderable/hhRenderable.inl>