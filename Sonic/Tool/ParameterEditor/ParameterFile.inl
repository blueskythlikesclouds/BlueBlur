namespace Sonic
{
    inline BB_FUNCTION_PTR(void, __stdcall, fpCParameterFileCreateParameterGroup, 0x1257EF0,
        CParameterFile* in_pParameterFile, boost::shared_ptr<CParameterGroup>& out_spParameterGroup, const Hedgehog::Base::CSharedString& in_rName, const Hedgehog::Base::CSharedString& in_rDescription);

    inline boost::shared_ptr<CParameterGroup> CParameterFile::CreateParameterGroup(
        const Hedgehog::Base::CSharedString& in_rName, const Hedgehog::Base::CSharedString& in_rDescription)
    {
        boost::shared_ptr<CParameterGroup> spParameterGroup;
        fpCParameterFileCreateParameterGroup(this, spParameterGroup, in_rName, in_rDescription);
        return spParameterGroup;
    }
}