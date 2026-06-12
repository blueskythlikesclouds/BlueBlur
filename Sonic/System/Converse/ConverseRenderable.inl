namespace Sonic
{
	inline BB_FUNCTION_PTR(void, __stdcall, fpCConverseRenderableCtor, 0x00CF8A90, 
		CConverseRenderable* This, 
		const boost::shared_ptr<Hedgehog::Database::CDatabase>& in_spDatabase, 
		const CConverseRenderable::SConfig& config);

	inline CConverseRenderable::CConverseRenderable(const boost::shared_ptr<Hedgehog::Database::CDatabase>& in_spDatabase, const SConfig& in_rConfig)
	{
		fpCConverseRenderableCtor(this, in_spDatabase, in_rConfig);
	}
}