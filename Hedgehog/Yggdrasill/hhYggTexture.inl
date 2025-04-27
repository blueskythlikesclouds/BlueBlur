namespace Hedgehog::Yggdrasill
{
    inline BB_FUNCTION_PTR(void, __thiscall, fpCYggTextureGetSurface, 0x78AE30,
        const CYggTexture* This, boost::shared_ptr<CYggSurface>& out_spSurface, uint32_t in_MipIndex, uint32_t in_LevelIndex);

    inline boost::shared_ptr<CYggSurface> CYggTexture::GetSurface(uint32_t in_MipIndex, uint32_t in_LevelIndex) const
    {
        boost::shared_ptr<CYggSurface> spSurface;
        fpCYggTextureGetSurface(this, spSurface, in_MipIndex, in_LevelIndex);
        return spSurface;
    }
}