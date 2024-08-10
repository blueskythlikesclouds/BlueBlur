namespace Hedgehog::Mirage
{
    inline BB_FUNCTION_PTR(void, __thiscall, fpCBundleAddRenderable, 0x6FAA00, CBundle* This, const boost::shared_ptr<CRenderable>& in_spRenderable);
    
    inline void CBundle::AddRenderable(const boost::shared_ptr<CRenderable>& in_spRenderable)
    {
        fpCBundleAddRenderable(this, in_spRenderable);
    }

    inline BB_FUNCTION_PTR(void, __thiscall, fpCBundleRemoveRenderable, 0x6FAA50, CBundle* This, const boost::shared_ptr<CRenderable>& in_spRenderable);

    inline void CBundle::RemoveRenderable(const boost::shared_ptr<CRenderable>& in_spRenderable)
    {
        fpCBundleRemoveRenderable(this, in_spRenderable);
    }
}