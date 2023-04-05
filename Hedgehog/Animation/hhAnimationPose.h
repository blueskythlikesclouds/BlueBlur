#pragma once

#include <Hedgehog/Base/Type/hhSharedString.h>
#include <Hedgehog/MirageCore/Misc/hhPose.h>

namespace Hedgehog::Database
{
    class CDatabase;
}

namespace Hedgehog::Animation
{
    class CAnimationCache;
    class CAnimationControlSingle;
    class CAnimationSkeleton;
    class CAnimationPose;
    class CIkRaycastInterface;

    static inline BB_FUNCTION_PTR(void, __thiscall, fpCAnimationPoseCtor, 0x6CB140,
        CAnimationPose* This, const boost::shared_ptr<Hedgehog::Database::CDatabase>& in_spDatabase, const Hedgehog::Base::CSharedString& in_rName);

    static inline BB_FUNCTION_PTR(void*, __cdecl, fpCAnimationPoseCreateAnimationCache, 0x6C9850, 
        const boost::shared_ptr<CAnimationCache>& out_spAnimationCache);

    static inline BB_FUNCTION_PTR(void, __thiscall, fpCAnimationPoseAddAnimationList, 0x6CBFC0, 
        CAnimationPose* This, void* in_pList, int in_Count);

    static inline BB_FUNCTION_PTR(void, __thiscall, fpCAnimationPoseUpdate, 0x6CCCB0,
        CAnimationPose* This, float in_DeltaTime);

    // TODO: MOVE THESE TO THEIR OWN LOCATIONS.

    template <typename T>
    class hvkArray
    {
    public:
        T* m_ptr;
        uint32_t m_numElements;
        uint32_t m_maxElements;

        template <typename E>
        T* GetIndex(E i)
        {
            return (T*)((uint32_t)m_ptr + ((int)i * sizeof(T)));
        }
    };

    class hvkQsTransform
    {
    public:
        Hedgehog::Math::CVector     m_Position {};
        Hedgehog::Math::CQuaternion m_Rotation {};
        Hedgehog::Math::CVector     m_Scale {};
    };

    struct SAnimData
    {
        void* m_pSkeleton{}; // type hkaSkeleton
        hvkArray<hvkQsTransform> m_TransformArray{};
        hvkArray<hvkQsTransform> m_TransformArray2{};
        BB_INSERT_PADDING(0x04) {};
    };

    class CAnimationPose : public Mirage::CPose
    {
    public:
        BB_INSERT_PADDING(0x2C) {};
        boost::shared_ptr<CAnimationSkeleton> m_spAnimationSkeleton; // 0x30
        void* m_pHavokSkeleton{}; // 0x38, hkaAnimatedSkeleton*
        Mirage::CInstanceInfo* m_pInstanceInfo{}; // 0x3C
        boost::shared_ptr<Mirage::CModelData> m_spModelData; // 0x40
        BB_INSERT_PADDING(0x04) {};

        boost::shared_ptr<CAnimationControlSingle> m_spAnimationControlSingle; // 0x4C
        SAnimData* m_pAnimData{};
        int m_numBones = 0;
        void* m_pMatrixListA{};
        void* m_pMatrixListB{};
        int m_UnknownMapSize = 0;

        BB_INSERT_PADDING(0x14) {};

        float m_Scale = 0;
        BB_INSERT_PADDING(0x10) {};
        boost::shared_ptr<CIkRaycastInterface> m_spFootIK; // 0x90

        BB_INSERT_PADDING(0x78) {};

        boost::shared_ptr<Database::CDatabase> m_spDatabase; // 0x110
        BB_INSERT_PADDING(0x18) {};
        boost::shared_ptr<CAnimationCache> m_spAnimationCache; // 0x130
        BB_INSERT_PADDING(0x18) {};

        static boost::shared_ptr<CAnimationCache> CreateAnimationCache()
        {
            boost::shared_ptr<CAnimationCache> spAnimationCache;
            fpCAnimationPoseCreateAnimationCache(spAnimationCache);
            return spAnimationCache;
        }

        CAnimationPose(const bb_null_ctor&)
        {
        }

        CAnimationPose(const boost::shared_ptr<Database::CDatabase>& in_spDatabase, const Base::CSharedString& in_rName) : CAnimationPose(bb_null_ctor{})
        {
            fpCAnimationPoseCtor(this, in_spDatabase, in_rName);
            m_spAnimationCache = CreateAnimationCache();
        }

        void AddAnimationList(void* in_pList, int in_Count)
        {
            fpCAnimationPoseAddAnimationList(this, in_pList, in_Count);
        }

        void Update(float in_DeltaTime)
        {
            fpCAnimationPoseUpdate(this, in_DeltaTime);
        }
    };

    BB_ASSERT_OFFSETOF(CAnimationPose, m_spAnimationSkeleton, 0x30);
    BB_ASSERT_OFFSETOF(CAnimationPose, m_pHavokSkeleton, 0x38);
    BB_ASSERT_OFFSETOF(CAnimationPose, m_pInstanceInfo, 0x3C);
    BB_ASSERT_OFFSETOF(CAnimationPose, m_spModelData, 0x40);
    BB_ASSERT_OFFSETOF(CAnimationPose, m_Scale, 0x7C);
    BB_ASSERT_OFFSETOF(CAnimationPose, m_spFootIK, 0x90);
    BB_ASSERT_OFFSETOF(CAnimationPose, m_spDatabase, 0x110);
    BB_ASSERT_OFFSETOF(CAnimationPose, m_spAnimationCache, 0x130);
    BB_ASSERT_SIZEOF(CAnimationPose, 0x150);
}
