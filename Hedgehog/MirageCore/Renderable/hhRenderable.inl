namespace Hedgehog::Mirage
{
    inline BB_FUNCTION_PTR(CRenderable*, __thiscall, fpCRenderableCtor, 0x6F49C0, CRenderable* This);

    inline CRenderable::CRenderable() : CRenderable(bb_null_ctor{})
    {
        fpCRenderableCtor(this);
    }
}