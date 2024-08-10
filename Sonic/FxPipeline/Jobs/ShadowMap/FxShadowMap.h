#pragma once

#include <Hedgehog/Base/Container/hhVector.h>
#include <Sonic/FxPipeline/Jobs/FxJob.h>

namespace Hedgehog::Mirage
{
    class CCamera;
}

namespace Hedgehog::Yggdrasill
{
    class CYggDevice;
    class CYggSurface;
    class CYggTexture;
}

namespace Sonic
{
    class CFxShadowMap;

    inline BB_FUNCTION_PTR(void, __thiscall, fpCFxShadowMapInitialize, 0x10C6CE0, CFxShadowMap* This);
    inline BB_FUNCTION_PTR(void, __thiscall, fpCFxShadowMapExecute, 0x10C68D0, CFxShadowMap* This);

    class CFxShadowMap : public CFxJob
    {
    public:
        boost::shared_ptr<Hedgehog::Yggdrasill::CYggSurface> m_spColorSurface;
        boost::shared_ptr<Hedgehog::Yggdrasill::CYggTexture> m_spShadowMapTex;
        boost::shared_ptr<Hedgehog::Yggdrasill::CYggTexture> m_spShadowMapNoTerrainTex;
        Hedgehog::Mirage::SShaderPair m_MakeShadowMapShader;
        Hedgehog::Mirage::SShaderPair m_MakeShadowMapTransparentShader;
        Hedgehog::Mirage::CCamera* m_pCurrentShadowMapCamera;
        hh::vector<boost::shared_ptr<Hedgehog::Mirage::CCamera>> m_ShadowMapCameras;
        boost::shared_ptr<Hedgehog::Mirage::CCamera> m_spDirectionalShadowMapCamera;
        boost::shared_ptr<Hedgehog::Mirage::CCamera> m_spVerticalShadowMapCamera;
        uint32_t m_ShadowMapSize;
        BB_INSERT_PADDING(0x4);

        void InitializeCameras();

        void SetRenderStates(const bool in_EnableReverseCull);
        void UnsetRenderStates(const bool in_EnableReverseCull);
    };

    BB_ASSERT_OFFSETOF(CFxShadowMap, m_spColorSurface, 0x48);
    BB_ASSERT_OFFSETOF(CFxShadowMap, m_spShadowMapTex, 0x50);
    BB_ASSERT_OFFSETOF(CFxShadowMap, m_spShadowMapNoTerrainTex, 0x58);
    BB_ASSERT_OFFSETOF(CFxShadowMap, m_MakeShadowMapShader, 0x60);
    BB_ASSERT_OFFSETOF(CFxShadowMap, m_MakeShadowMapTransparentShader, 0x70);
    BB_ASSERT_OFFSETOF(CFxShadowMap, m_pCurrentShadowMapCamera, 0x80);
    BB_ASSERT_OFFSETOF(CFxShadowMap, m_ShadowMapCameras, 0x84);
    BB_ASSERT_OFFSETOF(CFxShadowMap, m_spDirectionalShadowMapCamera, 0x94);
    BB_ASSERT_OFFSETOF(CFxShadowMap, m_spVerticalShadowMapCamera, 0x9C);
    BB_ASSERT_OFFSETOF(CFxShadowMap, m_ShadowMapSize, 0xA4);
    BB_ASSERT_SIZEOF(CFxShadowMap, 0xAC);
}

#include <Sonic/FxPipeline/Jobs/ShadowMap/FxShadowMap.inl>