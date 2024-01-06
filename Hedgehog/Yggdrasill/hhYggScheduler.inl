namespace Hedgehog::Yggdrasill
{
    inline BB_FUNCTION_PTR(void*, __thiscall, fpCYggSchedulerGetShader, 0x789DB0,
        const CYggScheduler* This, Hedgehog::Mirage::SShaderPair& out_rPair, const char* in_pVertexShaderName, const char* in_pPixelShaderName);

    inline Mirage::SShaderPair CYggScheduler::GetShader(const char* in_pVertexShaderName,
        const char* in_pPixelShaderName) const
    {
        Mirage::SShaderPair pair;
        fpCYggSchedulerGetShader(this, pair, in_pVertexShaderName, in_pPixelShaderName);
        return pair;
    }

    inline BB_FUNCTION_PTR(void*, __thiscall, fpCYggSchedulerGetPicture, 0x789DD0,
        const CYggScheduler* This, boost::shared_ptr<CYggPicture>& out_spPicture, const char* in_pName);

    inline boost::shared_ptr<CYggPicture> CYggScheduler::GetPicture(const char* in_pName) const
    {
        boost::shared_ptr<CYggPicture> spPicture;
        fpCYggSchedulerGetPicture(this, spPicture, in_pName);
        return spPicture;
    }
}