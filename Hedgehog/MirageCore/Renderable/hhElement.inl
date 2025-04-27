namespace Hedgehog::Mirage
{
    inline BB_FUNCTION_PTR(CElement*, __thiscall, fpCElementCtor, 0x702050, CElement* This);

    inline CElement::CElement() : CElement(bb_null_ctor{})
    {
        fpCElementCtor(this);
    }
}