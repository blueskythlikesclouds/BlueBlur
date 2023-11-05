#pragma once
#include <Sonic/System/GameObject.h>

namespace Sonic
{
	class __declspec(align(4)) CPhysicsUnit : public Hedgehog::Base::CObject
	{
	public:
		virtual ~CPhysicsUnit() = default;

		hk2010_2_0::hkpRigidBody* m_pHkpRigidBody;
		void* m_World;
		void* m_Field0C;
		int m_ColID;
		int m_Field14;
		int m_Field18;
		hh::map<void*, void*> m_Map1C;
		hh::map<void*, void*> m_Map28;
		char m_Field34;
		char m_Field35;
		char m_Field36;
		char m_Field37;
		int m_Field38;
		Hedgehog::Universe::CMessageActor* m_pMessageActor;
		boost::shared_ptr<Hedgehog::Base::CCriticalSectionD3D9> m_spCriticalSectionD3D9;
	};

	class CRigidBody : public CPhysicsUnit
	{
	public:

		virtual void* GetCollider(void* a1) { return a1; }
		virtual void* fn02(void* a1) { return a1; }
		virtual void ApplyPropertyID(int id, uint64_t* weird) {}
		virtual void fn04(int a, int b) {}
		virtual void fn05(int a, int b) {}
		virtual void GetPropertyValue(uint64_t* weird, int hash) {}
		virtual bool VerifyPropertyID(int hash) { return false; }

		void ApplyPropertyID(int id, int value)
		{
			struct
			{
				int value;
				int buffer;
			} data;
			data.value = value;
			ApplyPropertyID(id, (uint64_t*)&data);
		}

		void AddBoolProperty(int hashedName, int id)
		{
			if (!VerifyPropertyID(hashedName))
				return;

			uint64_t data = 0;
			GetPropertyValue(&data, hashedName);

			data = data != 0;
			ApplyPropertyID(id, &data);
		}

		bool GetBoolProperty(int id)
		{
			if (!VerifyPropertyID(id))
				return false;

			uint64_t data = 0;
			GetPropertyValue(&data, id);

			return data != 0;
		}

		hk2010_2_0::hkpShape* GetShape() const
		{
			return m_pHkpRigidBody->m_Collideable.m_Shape;
		}

		// Extra unknown stuff put at the bottom for now.
		void* m_Field48;
		void* m_Field4C;
		void* m_Field50;
		void* m_Field54;
		void* m_Field58;
		void* m_Field5C;
		Hedgehog::Math::CMatrix44 m_Field60;
		Hedgehog::Math::CMatrix44 m_FieldA0;
		void* m_FieldE0;
		void* m_FieldE4;
		void* m_FieldE8;
		void* m_FieldEC;
		void* m_FieldF0;
		void* m_FieldF4;
		void* m_FieldF8;
		void* m_FieldFC;
		void* m_Field100;
		void* m_Field104;
		void* m_Field108;
		void* m_Field10C;
	};
	BB_ASSERT_OFFSETOF(CPhysicsUnit, m_pHkpRigidBody, 0x04);
	BB_ASSERT_OFFSETOF(CPhysicsUnit, m_pMessageActor, 0x3C);
}
