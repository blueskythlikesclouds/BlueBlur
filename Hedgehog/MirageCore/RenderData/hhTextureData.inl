namespace Hedgehog::Mirage
{
    inline BB_FUNCTION_PTR(void, __thiscall, fpCTextureDataCtor, 0x6F88B0, CTextureData* This);

    inline CTextureData::CTextureData()
    {
        fpCTextureDataCtor(this);
    }
}