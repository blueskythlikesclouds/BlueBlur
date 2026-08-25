namespace Sonic
{
    inline BB_NOINLINE void fpCConverseStringRenderableCtor(
        CConverseStringRenderable* This,
        const CConverseStringRenderable::SConfig& in_rConfig,
        Hedgehog::Base::CStringSymbol in_rRenderCategory)
    {
        static const uint32_t funcAddr = 0x00CF85C0;
        __asm
        {
            mov eax, This
            mov esi, in_rConfig
            push in_rRenderCategory
            call funcAddr
        }
    }

	inline CConverseStringRenderable::CConverseStringRenderable(const SConfig& in_rConfig, const Hedgehog::Base::CStringSymbol in_rRenderCategory)
    {
        fpCConverseStringRenderableCtor(this, in_rConfig, in_rRenderCategory);
    }

    inline CConverseStringRenderable::CConverseStringRenderable(const SConfig& in_rConfig, Hedgehog::Mirage::ERenderCategory in_rRenderCategory)
    {
        fpCConverseStringRenderableCtor(this, in_rConfig, Hedgehog::Mirage::g_RenderCategories[in_rRenderCategory]);
    }
}