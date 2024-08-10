namespace Hedgehog::Yggdrasill
{
    inline BB_FUNCTION_PTR(void, __thiscall, fpCYggSceneRendererRender, 0x789890, CYggSceneRenderer* This, ERenderCategory in_Category, ERenderLevel in_Level);

    inline void CYggSceneRenderer::Render(ERenderCategory in_Category, ERenderLevel in_Level)
    {
        fpCYggSceneRendererRender(this, in_Category, in_Level);
    }

    inline void CYggSceneRenderer::Render(uint32_t in_Category, uint32_t in_Level)
    {
        fpCYggSceneRendererRender(this, (ERenderCategory)in_Category, (ERenderLevel)in_Level);
    }

    inline BB_FUNCTION_PTR(void, __thiscall, fpCYggSceneRendererResetMaterialColor, 0x10D4EB0, CYggSceneRenderer* This);

    inline void CYggSceneRenderer::ResetMaterialColor()
    {
        fpCYggSceneRendererResetMaterialColor(this);
    }

    inline BB_FUNCTION_PTR(void, __thiscall, fpCYggSceneRendererSetLightViewProjection, 0x789360, CYggSceneRenderer* This, const Math::CMatrix& in_rView, const Math::CMatrix44& in_rProjection);

    inline void CYggSceneRenderer::SetLightViewProjection(const Math::CMatrix& in_rView,
        const Math::CMatrix44& in_rProjection)
    {
        fpCYggSceneRendererSetLightViewProjection(this, in_rView, in_rProjection);
    }

    inline BB_FUNCTION_PTR(void, __thiscall, fpCYggSceneRendererLockShader, 0x789BE0, CYggSceneRenderer* This, const Hedgehog::Mirage::SShaderPair& in_rShaderPair, size_t in_Flags);

    inline void CYggSceneRenderer::LockShader(const Hedgehog::Mirage::SShaderPair& in_rShaderPair,
        const size_t in_Flags)
    {
        fpCYggSceneRendererLockShader(this, in_rShaderPair, in_Flags);
    }

    inline BB_FUNCTION_PTR(void, __thiscall, fpCYggSceneRendererUnlockShader, 0x789860, CYggSceneRenderer* This);

    inline void CYggSceneRenderer::UnlockShader()
    {
        fpCYggSceneRendererUnlockShader(this);
    }

    inline BB_FUNCTION_PTR(void, __thiscall, fpCYggSceneRendererSetCamera, 0x7890F0, CYggSceneRenderer* This, Hedgehog::Mirage::CCamera* in_pCamera, size_t in_Flags);

    inline void CYggSceneRenderer::SetCamera(Hedgehog::Mirage::CCamera* in_pCamera, const size_t in_Flags)
    {
        fpCYggSceneRendererSetCamera(this, in_pCamera, in_Flags);
    }

    inline BB_FUNCTION_PTR(void, __thiscall, fpCYggSceneRendererUnsetCamera, 0x789110, CYggSceneRenderer* This);

    inline void CYggSceneRenderer::UnsetCamera()
    {
        fpCYggSceneRendererUnsetCamera(this);
    }
}