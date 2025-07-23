#pragma once

#include <Hedgehog/Base/Type/hhSharedString.h>
#include <Hedgehog/Database/System/hhDatabaseData.h>
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
    struct SMotionInfo;

    // TODO: MOVE THESE TO THEIR OWN LOCATIONS.
    class hkQsTransform
    {
    public:
        Hedgehog::Math::CVector     m_Position {};
        Hedgehog::Math::CQuaternion m_Rotation {};
        Hedgehog::Math::CVector     m_Scale {};
    };

    struct SAnimData
    {
        void* m_pSkeleton{}; // type hkaSkeleton
        hk2010_2_0::hkArray<hkQsTransform> m_TransformArray{};
        hk2010_2_0::hkArray<hkQsTransform> m_TransformArray2{};
        BB_INSERT_PADDING(0x04) {};
    };

    class alignas(0x10) CAnimationPose : public Mirage::CPose
    {
    public:
        BB_INSERT_PADDING(0x28) {};
        bool m_Field2C;
        boost::shared_ptr<CAnimationSkeleton> m_spAnimationSkeleton; // 0x30
        hk2010_2_0::hkaAnimatedSkeleton* m_pHavokSkeleton{}; // 0x38
        Mirage::CInstanceInfo* m_pInstanceInfo{}; // 0x3C
        boost::shared_ptr<Mirage::CModelData> m_spModelData; // 0x40
        BB_INSERT_PADDING(0x04) {};

        boost::shared_ptr<CAnimationControlSingle> m_spAnimationControlSingle; // 0x4C
        SAnimData* m_pAnimData{};
        int m_numBones = 0;
        Hedgehog::Math::CMatrix* m_pMatrixListA{};
        Hedgehog::Math::CMatrix* m_pMatrixListB{};
        int m_UnknownMapSize = 0;

        BB_INSERT_PADDING(0x14) {};

        float m_Scale = 0;
        BB_INSERT_PADDING(0x10) {};
        boost::shared_ptr<CIkRaycastInterface> m_spFootIK; // 0x90
        BB_INSERT_PADDING(0x4);
        float m_Field9C;
        float m_FieldA0;

        BB_INSERT_PADDING(0x6C) {};

        boost::shared_ptr<Database::CDatabase> m_spDatabase; // 0x110
        BB_INSERT_PADDING(0x18) {};
        boost::shared_ptr<CAnimationCache> m_spAnimationCache; // 0x130
        BB_INSERT_PADDING(0x18) {};

        BB_OVERRIDE_FUNCTION_PTR_CONST_NOARG(size_t, Mirage::CPose, GetMatrixNum, 0x6CCB60);
        BB_OVERRIDE_FUNCTION_PTR_CONST_NOARG(const Math::CMatrix*, Mirage::CPose, GetMatrixList, 0x6CCBB0);
        BB_OVERRIDE_FUNCTION_PTR_CONST_NOARG(const Math::CMatrix*, Mirage::CPose, GetPrevMatrixList, 0x6C7A60);
        BB_OVERRIDE_FUNCTION_PTR_CONST(void, Mirage::CPose, GetMatrix, 0x6C7A70, (size_t, in_Index), (Math::CMatrix&, out_rMatrix))
        BB_OVERRIDE_FUNCTION_PTR(void, Mirage::CPose, SetModel,  0x6C8E90, (const boost::shared_ptr<Mirage::CModelData>&, in_spModelData))
        BB_OVERRIDE_FUNCTION_PTR(void, Mirage::CPose, SetInstanceInfo, 0x6C7950, (Mirage::CInstanceInfo*, in_pInstanceInfo))

        static boost::shared_ptr<CAnimationCache> CreateAnimationCache();

        CAnimationPose(const bb_null_ctor&) {}
        CAnimationPose(const boost::shared_ptr<Database::CDatabase>& in_spDatabase, const Base::CSharedString& in_rName);

        void AddMotionInfo(SMotionInfo* in_pMotionInfo, size_t in_NumMotionInfo);
        void Update(float in_DeltaTime);
    };

    BB_ASSERT_OFFSETOF(CAnimationPose, m_spAnimationSkeleton, 0x30);
    BB_ASSERT_OFFSETOF(CAnimationPose, m_pHavokSkeleton, 0x38);
    BB_ASSERT_OFFSETOF(CAnimationPose, m_pInstanceInfo, 0x3C);
    BB_ASSERT_OFFSETOF(CAnimationPose, m_spModelData, 0x40);
    BB_ASSERT_OFFSETOF(CAnimationPose, m_Scale, 0x7C);
    BB_ASSERT_OFFSETOF(CAnimationPose, m_spFootIK, 0x90);
    BB_ASSERT_OFFSETOF(CAnimationPose, m_Field9C, 0x9C);
    BB_ASSERT_OFFSETOF(CAnimationPose, m_FieldA0, 0xA0);
    BB_ASSERT_OFFSETOF(CAnimationPose, m_spDatabase, 0x110);
    BB_ASSERT_OFFSETOF(CAnimationPose, m_spAnimationCache, 0x130);
    BB_ASSERT_SIZEOF(CAnimationPose, 0x150);
}

#include <Hedgehog/Animation/hhAnimationPose.inl>