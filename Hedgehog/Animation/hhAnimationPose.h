#pragma once

#include <Hedgehog/Base/hhObject.h>
#include <Hedgehog/Base/Type/hhSharedString.h>

// Forward declarations
namespace Hedgehog
{
	namespace Database
	{
		class CDatabase;
	}
}

namespace Hedgehog::Mirage
{
	class CInstanceInfo;
	class CModelData;

	class CPose : public Hedgehog::Base::CObject
	{
		// This seemingly has no members but let's declare this thing anyway for convention's sake.
	public:
		virtual ~CPose() = default;

		CPose(const bb_null_ctor&)
			: CObject(bb_null_ctor{})
		{
		}

		CPose()
			: CPose(bb_null_ctor{})
		{
		}
	};
}

namespace Hedgehog::Animation
{
	class CAnimationPose;

	static inline BB_FUNCTION_PTR(void, __thiscall, fCAnimationPoseCtor, 0x006CB140,
		CAnimationPose* This, const boost::shared_ptr<Hedgehog::Database::CDatabase>& spDatabase, const Hedgehog::Base::CSharedString& name);
	static inline BB_FUNCTION_PTR(void*, __cdecl, fBoostCAnimCache, 0x006C9850, const boost::shared_ptr<void>& boost);

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

	class __declspec(align(16)) CAnimationPose : public Mirage::CPose
	{
	public:
		BB_INSERT_PADDING(0x2C) {};
		boost::shared_ptr<void> m_spAnimationSkeleton{}; // 0x30, boost::shared_ptr<CAnimationSkeleton>
		void* m_pHavokSkeleton{}; // 0x38, hkaAnimatedSkeleton*
		Mirage::CInstanceInfo* m_pMirageInstanceInfo{}; // 0x3C
		boost::shared_ptr<Mirage::CModelData> m_spModelData{}; // 0x40, boost is hh::db::CDatabaseData for some reason
		BB_INSERT_PADDING(0x04) {};

		boost::shared_ptr<void> m_spAnimationControlSingle; // 0x4C, boost::shared_ptr<Hedgehog::Animation::CAnimationControlSingle>
		SAnimData* m_pAnimData{};
		int m_numBones = 0;
		void* m_pMatrixListA{};
		void* m_pMatrixListB{};
		int m_UnknownMapSize = 0;

		BB_INSERT_PADDING(0x14) {};

		float m_Scale = 0;
		BB_INSERT_PADDING(0x10) {};
		boost::shared_ptr<void> m_spFootIK{}; // 0x90, boost::shared_ptr<Sonic::CFootIKDemoRaycastInterface>

		BB_INSERT_PADDING(0x78) {};
		//Hedgehog::Mirage::CMatrixNodeListener m_NodeListener;

		boost::shared_ptr<Database::CDatabase> m_spDataBase; // 0x110
		BB_INSERT_PADDING(0x18) {};
		boost::shared_ptr<void> m_spAnimationCache; // 0x130, boost::shared_ptr<Hedgehog::Animation::CAnimationCache>
		BB_INSERT_PADDING(0x14) {};

		CAnimationPose(const bb_null_ctor&)
			: CPose(bb_null_ctor{})
		{
		}
		CAnimationPose(const boost::shared_ptr<Database::CDatabase>& database, const Base::CSharedString& name)
			: CAnimationPose(bb_null_ctor{})
		{
			fCAnimationPoseCtor(this, database, name);
			boost::shared_ptr<void> ptr{};
			fBoostCAnimCache(m_spAnimationCache);
			m_spAnimationCache = ptr;
		}


		void CommitAnimLists(void* list, int count)
		{
			BB_FUNCTION_PTR(void, __thiscall, func, 0x006CBFC0, CAnimationPose * This, void* _list, int _count);
			func(this, list, count);
		}
		void Update(float deltaTime)
		{
			BB_FUNCTION_PTR(void, __thiscall, func, 0x006CCCB0, CAnimationPose * This, float _deltaTime);
			func(this, deltaTime);
		}

	};
	BB_ASSERT_OFFSETOF(CAnimationPose, m_spAnimationSkeleton, 0x30);
	BB_ASSERT_OFFSETOF(CAnimationPose, m_pHavokSkeleton, 0x38);
	BB_ASSERT_OFFSETOF(CAnimationPose, m_pMirageInstanceInfo, 0x3C);
	BB_ASSERT_OFFSETOF(CAnimationPose, m_spModelData, 0x40);
	BB_ASSERT_OFFSETOF(CAnimationPose, m_Scale, 0x7C);
	BB_ASSERT_OFFSETOF(CAnimationPose, m_spFootIK, 0x90);
	BB_ASSERT_OFFSETOF(CAnimationPose, m_spDataBase, 0x110);
	BB_ASSERT_OFFSETOF(CAnimationPose, m_spAnimationCache, 0x130);
	BB_ASSERT_SIZEOF(CAnimationPose, 0x150);
}
