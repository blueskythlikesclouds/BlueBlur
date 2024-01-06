namespace Sonic
{
    inline BB_FUNCTION_PTR(void, __stdcall, fpCFxShadowMapInitializeCameras, 0x10C6A10, CFxShadowMap* This);

    inline void CFxShadowMap::InitializeCameras()
    {
        fpCFxShadowMapInitializeCameras(this);
    }

    inline void* const pCFxShadowMapSetRenderStates = (void*)0x10C61D0;

    inline void fCFxShadowMapSetRenderStates(Hedgehog::Yggdrasill::CYggDevice* in_pDevice, uint32_t in_EnableReverseCull)
    {
        __asm
        {
            mov eax, in_pDevice
            push in_EnableReverseCull
            call[pCFxShadowMapSetRenderStates]
            add esp, 4
        }
    }

    inline void CFxShadowMap::SetRenderStates(const bool in_EnableReverseCull)
    {
        fCFxShadowMapSetRenderStates(m_pScheduler->m_pMisc->m_pDevice, in_EnableReverseCull);
    }

    inline void* const pCFxShadowMapUnsetRenderStates = (void*)0x10C6160;

    inline void fCFxShadowMapUnsetRenderStates(Hedgehog::Yggdrasill::CYggDevice* in_pDevice, uint32_t in_EnableReverseCull)
    {
        __asm
        {
            mov eax, in_pDevice
            push in_EnableReverseCull
            call[pCFxShadowMapUnsetRenderStates]
            add esp, 4
        }
    }

    inline void CFxShadowMap::UnsetRenderStates(const bool in_EnableReverseCull)
    {
        fCFxShadowMapUnsetRenderStates(m_pScheduler->m_pMisc->m_pDevice, in_EnableReverseCull);
    }
}