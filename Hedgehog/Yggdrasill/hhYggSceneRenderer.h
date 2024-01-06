#pragma once

#include <Hedgehog/Base/System/hhSymbol.h>
#include <Hedgehog/Base/hhObject.h>

namespace Hedgehog::Mirage
{
    class CCamera;
    class CLightManager;
    class CRenderingDevice;
    class CRenderingInfrastructure;
    struct SShaderPair;
}

namespace Hedgehog::Yggdrasill
{
    enum ERenderCategory : uint32_t
    {
        eRenderCategory_Terrain            = 0x2,
        eRenderCategory_Object             = 0x4,
        eRenderCategory_ObjectXlu          = 0x8,
        eRenderCategory_ObjectPreZPass     = 0x10,
        eRenderCategory_ObjectZPass        = 0x20,
        eRenderCategory_ObjectZPassConst   = 0x200000,
        eRenderCategory_ObjectOverlayZPass = 0x40,
        eRenderCategory_ObjectOverlay      = 0x80,
        eRenderCategory_ObjectIcon         = 0x100,
        eRenderCategory_Player             = 0x1,
        eRenderCategory_SparkleFramebuffer = 0x80000,
        eRenderCategory_SparkleObject      = 0x40000,
        eRenderCategory_SparkleStencil     = 0x100000,
        eRenderCategory_Effect             = 0x400,
        eRenderCategory_ShadowMapObject    = 0x4000,
        eRenderCategory_ShadowMapTerrain   = 0x8000,
        eRenderCategory_MotionBlurPlayer   = 0x10000,
        eRenderCategory_MotionBlurObject   = 0x20000,
        eRenderCategory_Debug              = 0x800,
        eRenderCategory_HUD                = 0x1000,
        eRenderCategory_SystemHUD          = 0x2000,
        eRenderCategory_Sky                = 0x200
    };

    enum ERenderLevel : uint32_t
    {
        eRenderLevel_Opaque       = 0x1,
        eRenderLevel_PunchThrough = 0x2,
        eRenderLevel_Transparent  = 0x4,
        eRenderLevel_Water        = 0x8,
        eRenderLevel_Special1     = 0x10,
        eRenderLevel_Special2     = 0x20,
        eRenderLevel_Main         = 0x40,
        eRenderLevel_Debug        = 0x80,
        eRenderLevel_Primitive    = 0x100,
        eRenderLevel_Resident     = 0x200
    };

    class CYggScheduler;

    class CYggSceneRenderer : public Base::CObject
    {
    public:
        BB_INSERT_PADDING(0xC);
        CYggScheduler* m_pScheduler;
        Mirage::CRenderingDevice* m_pRenderingDevice;
        Mirage::CRenderingInfrastructure* m_pRenderingInfrastructure;
        Mirage::CCamera* m_pCamera;
        Base::CStringSymbol m_SymbolDefault;
        BB_INSERT_PADDING(0xC);
        Mirage::CLightManager* m_pLightManager;
        
        BB_INSERT_PADDING(0x7C);

        virtual ~CYggSceneRenderer() = default;
        virtual void _4() = 0;
        virtual void _8() = 0;

        void Render(ERenderCategory in_Category, ERenderLevel in_Level);
        void Render(uint32_t in_Category, uint32_t in_Level);

        void ResetMaterialColor();

        void SetLightViewProjection(const Math::CMatrix& in_rView, const Math::CMatrix44& in_rProjection);

        void LockShader(const Hedgehog::Mirage::SShaderPair& in_rShaderPair, const size_t in_Flags);
        void UnlockShader();

        void SetCamera(Hedgehog::Mirage::CCamera* in_pCamera, const size_t in_Flags);
        void UnsetCamera();
    };

    BB_ASSERT_OFFSETOF(CYggSceneRenderer, m_pScheduler, 0x10);
    BB_ASSERT_OFFSETOF(CYggSceneRenderer, m_pRenderingDevice, 0x14);
    BB_ASSERT_OFFSETOF(CYggSceneRenderer, m_pRenderingInfrastructure, 0x18);
    BB_ASSERT_OFFSETOF(CYggSceneRenderer, m_pCamera, 0x1C);
    BB_ASSERT_OFFSETOF(CYggSceneRenderer, m_SymbolDefault, 0x20);
    BB_ASSERT_OFFSETOF(CYggSceneRenderer, m_pLightManager, 0x30);
    BB_ASSERT_SIZEOF(CYggSceneRenderer, 0xB0);
}

#include <Hedgehog/Yggdrasill/hhYggSceneRenderer.inl>