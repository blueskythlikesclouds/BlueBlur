namespace Hedgehog::Mirage
{
    inline BB_FUNCTION_PTR(void, __thiscall, fpCLightManagerAddPointLight, 0x71EF20,
        CLightManager* This, boost::shared_ptr<CLightData> in_spLightData);

    inline void CLightManager::AddPointLight(const boost::shared_ptr<CLightData>& in_spLightData)
    {
        fpCLightManagerAddPointLight(this, in_spLightData);
    }
}