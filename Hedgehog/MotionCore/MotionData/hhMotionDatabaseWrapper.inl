namespace Hedgehog::Motion
{
	inline BB_FUNCTION_PTR(void, __thiscall, fpCDatabaseGetLightMotionData, 0x7599C0,
		CMotionDatabaseWrapper* This, boost::shared_ptr<CLightMotionData>& out_spLightMotionData, const Hedgehog::Base::CSharedString& in_rName, uint32_t in_Unknown);

	inline BB_FUNCTION_PTR(void, __thiscall, fpCDatabaseGetCameraMotionData, 0x759960,
		CMotionDatabaseWrapper* This, boost::shared_ptr<CCameraMotionData>& out_spCameraMotionData, const Hedgehog::Base::CSharedString& in_rName, size_t in_Unknown);

	inline BB_FUNCTION_PTR(void, __thiscall, fpCDatabaseGetMaterialAnimationData, 0x759720,
		CMotionDatabaseWrapper* This, boost::shared_ptr<CMaterialAnimationData>& out_spCameraMotionData, const Hedgehog::Base::CSharedString& in_rName, size_t in_Unknown);

	inline BB_FUNCTION_PTR(void, __thiscall, fpCDatabaseGetMorphMotionData, 0x759780,
		CMotionDatabaseWrapper* This, boost::shared_ptr<CMorphMotionData>& out_spCameraMotionData, const Hedgehog::Base::CSharedString& in_rName, size_t in_Unknown);

	inline BB_FUNCTION_PTR(void, __thiscall, fpCDatabaseGetTexcoordAnimationData, 0x7597E0,
		CMotionDatabaseWrapper* This, boost::shared_ptr<CTexcoordAnimationData>& out_spCameraMotionData, const Hedgehog::Base::CSharedString& in_rName, size_t in_Unknown);

	inline boost::shared_ptr<CLightMotionData> CMotionDatabaseWrapper::GetLightMotionData(
		const Base::CSharedString& in_rName, uint32_t in_Unknown)
	{
		boost::shared_ptr<CLightMotionData> spLightMotionData;
		fpCDatabaseGetLightMotionData(this, spLightMotionData, in_rName, in_Unknown);
		return spLightMotionData;
	}
	inline boost::shared_ptr<CCameraMotionData> CMotionDatabaseWrapper::GetCameraMotionData(
		const Base::CSharedString& in_rName, size_t in_Unknown)
	{
		boost::shared_ptr<CCameraMotionData> spCameraMotionData;
		fpCDatabaseGetCameraMotionData(this, spCameraMotionData, in_rName, in_Unknown);
		return spCameraMotionData;
	}
	inline boost::shared_ptr<CMaterialAnimationData> CMotionDatabaseWrapper::GetMaterialAnimationData(
		const Base::CSharedString& in_rName, size_t in_Unknown)
	{
		boost::shared_ptr<CMaterialAnimationData> spMaterialMotionData;
		fpCDatabaseGetMaterialAnimationData(this, spMaterialMotionData, in_rName, in_Unknown);
		return spMaterialMotionData;
	}
	inline boost::shared_ptr<CMorphMotionData> CMotionDatabaseWrapper::GetMorphMotionData(
		const Base::CSharedString& in_rName, size_t in_Unknown)
	{
		boost::shared_ptr<CMorphMotionData> spMorpherMotionData;
		fpCDatabaseGetMorphMotionData(this, spMorpherMotionData, in_rName, in_Unknown);
		return spMorpherMotionData;
	}
	inline boost::shared_ptr<CTexcoordAnimationData> CMotionDatabaseWrapper::GetTexcoordAnimationData(
		const Base::CSharedString& in_rName, size_t in_Unknown)
	{
		boost::shared_ptr<CTexcoordAnimationData> spUVMotionData;
		fpCDatabaseGetTexcoordAnimationData(this, spUVMotionData, in_rName, in_Unknown);
		return spUVMotionData;
	}
}