namespace Hedgehog::Motion
{
    inline BB_FUNCTION_PTR(void, __thiscall, fpCDatabaseGetLightMotionData, 0x7599C0,
        CMotionDatabaseWrapper* This, boost::shared_ptr<CLightMotionData>& out_spLightMotionData, const Hedgehog::Base::CSharedString& in_rName, uint32_t in_Unknown);

    inline boost::shared_ptr<CLightMotionData> CMotionDatabaseWrapper::GetLightMotionData(
        const Base::CSharedString& in_rName, uint32_t in_Unknown)
    {
        boost::shared_ptr<CLightMotionData> spLightMotionData;
        fpCDatabaseGetLightMotionData(this, spLightMotionData, in_rName, in_Unknown);
        return spLightMotionData;
    }
}