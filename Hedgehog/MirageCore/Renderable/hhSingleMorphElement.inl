namespace Hedgehog::Mirage
{
    inline BB_FUNCTION_PTR(CSingleMorphElement*, __thiscall, fpCSingleMorphElementCtor, 0x007040B0,
        CSingleMorphElement* This, const boost::shared_ptr<CModelData>& in_spModelData);

    inline CSingleMorphElement::CSingleMorphElement(const boost::shared_ptr<CModelData>& in_spModelData) : CSingleMorphElement(bb_null_ctor{})
    {
        fpCSingleMorphElementCtor(this, in_spModelData);
    }
}