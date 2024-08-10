namespace Hedgehog::Mirage
{
    inline BB_FUNCTION_PTR(void, __thiscall, fpCOptimalBundleAddRenderable, 0x71B070, COptimalBundle* This, const boost::shared_ptr<CRenderable>& in_spRenderable);

    inline void COptimalBundle::AddRenderable(const boost::shared_ptr<CRenderable>& in_spRenderable)
    {
        fpCOptimalBundleAddRenderable(this, in_spRenderable);
    }

    inline BB_FUNCTION_PTR(void, __thiscall, fpCOptimalBundleRemoveRenderable, 0x71B0F0, COptimalBundle* This, const boost::shared_ptr<CRenderable>& in_spRenderable);

    inline void COptimalBundle::RemoveRenderable(const boost::shared_ptr<CRenderable>& in_spRenderable)
    {
        fpCOptimalBundleRemoveRenderable(this, in_spRenderable);
    }
}