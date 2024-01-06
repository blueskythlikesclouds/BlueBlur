namespace Sonic
{
    inline void CFxRenderScene::RenderScene(Hedgehog::Yggdrasill::ERenderCategory in_Category,
        Hedgehog::Yggdrasill::ERenderLevel in_Level)
    {
        m_pScheduler->m_pMisc->m_spSceneRenderer->Render(in_Category & m_RenderCategories, in_Level & m_RenderLevels);
    }

    inline void CFxRenderScene::RenderScene(uint32_t in_Category, uint32_t in_Level)
    {
        m_pScheduler->m_pMisc->m_spSceneRenderer->Render(in_Category & m_RenderCategories, in_Level & m_RenderLevels);
    }
}