#pragma once
//#include <Sonic/System/GameObject.h>
#include <BlueBlur.inl>

namespace Sonic
{
	class CRigidBody;
	class CRayCastCollision;

	static constexpr uint32_t pCRayCastCollisionCtor = 0x01182980;

	static void fpCRayCastCollisionCtor(CRayCastCollision* This, const Hedgehog::Base::THolder<CWorld>& pWorld)
	{
		__asm
		{
			mov eax, pWorld
			mov esi, This
			call[pCRayCastCollisionCtor]
		}
	}

	class CRayCastCollision
	{
	public:
		struct HitInformation;
	private:
		static constexpr uint32_t pCRayCastCollisionCastRay = 0x010BE270;
		static bool fCRayCastCollisionCastRay(uint32_t in_pWorld, uint32_t in_CollisionMask, const Hedgehog::Math::CVector& in_RayStart, const Hedgehog::Math::CVector& in_RayEnd, HitInformation* out_HitInfo)
		{
			bool result = false;

			__asm
			{
				mov edx, in_CollisionMask
				mov edi, in_pWorld
				mov esi, out_HitInfo
				mov ecx, in_RayEnd
				push in_RayStart

				call[pCRayCastCollisionCastRay]

				mov result, al
			}

			return result;
		}

	public:
		struct __declspec(align(4)) HitInformation
		{
			Eigen::Vector3f Normal{};
			Eigen::Vector3f Position{};
			CRigidBody* pRigidBody = nullptr;
			float Field1C = 0.0f;
			int Field20 = 0;
			bool hitSuccess = false;
		};

		void** m_ppHkpWorld{};
		void* m_pHkpAabbPhantom{};

		CRayCastCollision(const Hedgehog::Base::THolder<CWorld>& pWorld)
		{
			fpCRayCastCollisionCtor(this, pWorld);
		}

		bool CastRay(uint32_t collisionMask, const Hedgehog::Math::CVector& rayStart, const Hedgehog::Math::CVector& rayEnd, HitInformation* out_HitInfo)
		{
			return fCRayCastCollisionCastRay(*(uint32_t*)this, collisionMask, rayStart, rayEnd, out_HitInfo);
		}
	};
}