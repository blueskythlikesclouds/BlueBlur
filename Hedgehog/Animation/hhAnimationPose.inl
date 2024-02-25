namespace Hedgehog::Animation
{
    inline BB_FUNCTION_PTR(void*, __cdecl, fpCAnimationPoseCreateAnimationCache, 0x6C9850,
        const boost::shared_ptr<CAnimationCache>& out_spAnimationCache);

    inline boost::shared_ptr<CAnimationCache> CAnimationPose::CreateAnimationCache()
    {
        boost::shared_ptr<CAnimationCache> spAnimationCache;
        fpCAnimationPoseCreateAnimationCache(spAnimationCache);
        return spAnimationCache;
    }

    inline BB_FUNCTION_PTR(void, __thiscall, fpCAnimationPoseCtor, 0x6CB140,
        CAnimationPose* This, const boost::shared_ptr<Hedgehog::Database::CDatabase>& in_spDatabase, const Hedgehog::Base::CSharedString& in_rName);

    inline CAnimationPose::CAnimationPose(const boost::shared_ptr<Database::CDatabase>& in_spDatabase,
        const Base::CSharedString& in_rName) : CAnimationPose(bb_null_ctor{})
    {
        fpCAnimationPoseCtor(this, in_spDatabase, in_rName);
        m_spAnimationCache = CreateAnimationCache();
    }

    inline BB_FUNCTION_PTR(void, __thiscall, fpCAnimationPoseAddMotionInfo, 0x6CBFC0,
        CAnimationPose* This, SMotionInfo* in_pMotionInfo, size_t in_NumMotionInfo);

    inline void CAnimationPose::AddMotionInfo(SMotionInfo* in_pMotionInfo, size_t in_NumMotionInfo)
    {
        fpCAnimationPoseAddMotionInfo(this, in_pMotionInfo, in_NumMotionInfo);
    }

    inline BB_FUNCTION_PTR(void, __thiscall, fpCAnimationPoseUpdate, 0x6CCCB0,
        CAnimationPose* This, float in_DeltaTime);

    inline void CAnimationPose::Update(float in_DeltaTime)
    {
        fpCAnimationPoseUpdate(this, in_DeltaTime);
    }
}