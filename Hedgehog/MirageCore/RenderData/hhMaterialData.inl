namespace Hedgehog::Mirage
{
    inline BB_FUNCTION_PTR(CMaterialData*, __thiscall, fpCMaterialDataCtor, 0x704CA0, CMaterialData*);

    inline CMaterialData::CMaterialData()
    {
        fpCMaterialDataCtor(this);
    }
}