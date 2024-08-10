namespace Hedgehog::Yggdrasill
{
    inline BB_FUNCTION_PTR(void, __thiscall, fpCYggJobGetDefaultTexture, 0x784A60, const CYggJob* This, boost::shared_ptr<CYggTexture>& out_spTexture);

    inline boost::shared_ptr<CYggTexture> CYggJob::GetDefaultTexture() const
    {
        boost::shared_ptr<CYggTexture> spTexture;
        fpCYggJobGetDefaultTexture(this, spTexture);
        return spTexture;
    }

    inline BB_FUNCTION_PTR(void, __thiscall, fpCYggJobGetTexture, 0x7848D0, const CYggJob* This, boost::shared_ptr<CYggTexture>& out_spTexture, const Hedgehog::Base::CStringSymbol& in_rSymbol);

    inline boost::shared_ptr<CYggTexture> CYggJob::GetTexture(const Base::CStringSymbol& in_rSymbol) const
    {
        boost::shared_ptr<CYggTexture> spTexture;
        fpCYggJobGetTexture(this, spTexture, in_rSymbol);
        return spTexture;
    }

    inline BB_FUNCTION_PTR(void, __thiscall, fpCYggJobGetSurface, 0x7847B0, const CYggJob* This, boost::shared_ptr<CYggSurface>& out_spSurface, const Hedgehog::Base::CStringSymbol& in_rSymbol);

    inline boost::shared_ptr<CYggSurface> CYggJob::GetSurface(const Base::CStringSymbol& in_rSymbol) const
    {
        boost::shared_ptr<CYggSurface> spSurface;
        fpCYggJobGetSurface(this, spSurface, in_rSymbol);
        return spSurface;
    }

    inline BB_FUNCTION_PTR(void, __thiscall, fpCYggJobSetDefaultTexture, 0x784D00, CYggJob* This, const boost::shared_ptr<CYggTexture>& in_spTexture);

    inline void CYggJob::SetDefaultTexture(const boost::shared_ptr<CYggTexture>& in_spTexture)
    {
        fpCYggJobSetDefaultTexture(this, in_spTexture);
    }

    inline BB_FUNCTION_PTR(void, __thiscall, fpCYggJobSetBuffer, 0x784BF0, CYggJob* This, const Hedgehog::Base::CStringSymbol& in_rSymbol, const boost::shared_ptr<CYggAbstractBuffer>& in_spBuffer);

    inline void CYggJob::SetBuffer(const Base::CStringSymbol& in_rSymbol,
        const boost::shared_ptr<CYggAbstractBuffer>& in_spBuffer)
    {
        fpCYggJobSetBuffer(this, in_rSymbol, in_spBuffer);
    }
}