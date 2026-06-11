namespace Hedgehog::Font
{
	inline BB_FUNCTION_PTR(void, __thiscall, fpCFontDatabaseWrapperCtor, 0x6B0560,
		CFontDatabaseWrapper* This, Hedgehog::Database::CDatabase* pDatabase);

	inline BB_FUNCTION_PTR(void, __thiscall, fpCFontDatabaseWrapperGetFontConverseData, 0x6B0580,
		CFontDatabaseWrapper* This, boost::shared_ptr<CFontConverseData>& out_spGIMipLevelLimitationData, const Hedgehog::Base::CSharedString& in_rName, size_t in_Unknown);

	inline BB_FUNCTION_PTR(void, __thiscall, fpCFontDatabaseWrapperGetFontTextureData, 0x6B05E0,
		CFontDatabaseWrapper* This, boost::shared_ptr<CFontTextureData>& out_spGIMipLevelLimitationData, const Hedgehog::Base::CSharedString& in_rName, size_t in_Unknown);

	inline CFontDatabaseWrapper::CFontDatabaseWrapper(Hedgehog::Database::CDatabase* pDatabase)
	{
		fpCFontDatabaseWrapperCtor(this, pDatabase);
	}

	inline boost::shared_ptr<CFontConverseData> CFontDatabaseWrapper::GetFontConverseData(
		const Hedgehog::Base::CSharedString& in_rName, size_t in_Unknown)
	{
		boost::shared_ptr<CFontConverseData> spFontConverseData;
		fpCFontDatabaseWrapperGetFontConverseData(this, spFontConverseData, in_rName, in_Unknown);
		return spFontConverseData;
	}

	inline boost::shared_ptr<CFontTextureData> CFontDatabaseWrapper::GetFontTextureData(
		const Hedgehog::Base::CSharedString& in_rName, size_t in_Unknown)
	{
		boost::shared_ptr<CFontTextureData> spFontTextureData;
		fpCFontDatabaseWrapperGetFontTextureData(this, spFontTextureData, in_rName, in_Unknown);
		return spFontTextureData;
	}
}