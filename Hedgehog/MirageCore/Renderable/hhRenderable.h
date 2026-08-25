#pragma once

#include <Hedgehog/Base/hhObject.h>
#include <Hedgehog/Base/System/hhSymbol.h>

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

    enum ERenderCategory : uint32_t
    {
        eRenderCategory_Object,
        eRenderCategory_Object_Xlu,
        eRenderCategory_Object_PreZPass,
        eRenderCategory_Object_ZPass,
        eRenderCategory_Object_OverlayZPass,
        eRenderCategory_Object_Overlay,
        eRenderCategory_Object_Icon,
        eRenderCategory_Player,
        eRenderCategory_Terrain,
        eRenderCategory_Effect,
        eRenderCategory_Sky,
        eRenderCategory_SetEditor,
        eRenderCategory_HUD_B2,
        eRenderCategory_HUD_B1,
        eRenderCategory_HUD,
        eRenderCategory_HUD_A1,
        eRenderCategory_HUD_A2,
        eRenderCategory_HUD_AfterModel,
        eRenderCategory_HUD_OverlayModel,
        eRenderCategory_HUD_Pause,
        eRenderCategory_HUD_PauseA,
        eRenderCategory_HUD_Loading,
        eRenderCategory_HUD_LoadingTitleToPam,
        eRenderCategory_HUD_LoadingAfter,
        eRenderCategory_HUD_ResidentLoading,
        eRenderCategory_HUD_Save,
        eRenderCategory_COL,
        eRenderCategory_Debug,
        eRenderCategory_ShadowMapObject,
        eRenderCategory_ShadowMapTerrain,
        eRenderCategory_MotionBlurPlayer,
        eRenderCategory_MotionBlurObject,
        eRenderCategory_SparkleObject,
        eRenderCategory_Sparkle_FB,
        eRenderCategory_Sparkle_Stencil,
        eRenderCategory_Object_ZPassConst,
        eRenderCategory_COUNT
    };

    static const Hedgehog::Base::CStringSymbol* g_RenderCategories = (Hedgehog::Base::CStringSymbol*)0x01E66BCC;

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