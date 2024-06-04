#pragma once

#include <Hedgehog/Base/hhObject.h>

namespace Hedgehog::Mirage
{
    class CRenderInfo;
    class CUpdateForRenderInfo;
    class CRenderContextModifier;

    enum ERenderableEvent : uint32_t
    {
        eRenderableEvent_RemoveFromBundle,
        eRenderableEvent_AddToBundle
    };

    class CRenderable : public Base::CObject
    {
    public:
        bool m_Enabled;
        float m_SortDepth;

        CRenderable(const bb_null_ctor& nil) : CObject(nil) {}
        CRenderable();
        virtual ~CRenderable() = default;

        virtual void Render(const CRenderInfo& in_rRenderInfo, Base::CStringSymbol in_RenderLevel, uint32_t in_Unknown) {}
        virtual void UpdateForRender(const CUpdateForRenderInfo& in_rUpdateForRenderInfo) {}
        virtual void ProcEvent(CRenderContextModifier& in_rRenderContextModifier, ERenderableEvent in_Event) {}
        virtual void Update(CRenderContextModifier& in_rRenderContextModifier) {}
    };

    BB_ASSERT_OFFSETOF(CRenderable, m_Enabled, 0x4);
    BB_ASSERT_OFFSETOF(CRenderable, m_SortDepth, 0x8);
    BB_ASSERT_SIZEOF(CRenderable, 0xC);
}


#include <Hedgehog/MirageCore/Renderable/hhRenderable.inl>