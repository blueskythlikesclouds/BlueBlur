#pragma once

#include <BlueBlur.inl>

namespace hk2010_2_0
{
	// Typedefs - Taken from Havok header-only SDK
	//--------------------------------------------
	typedef unsigned short  hkUint16;
	typedef unsigned __w64 hk_size_t;

	// Forward declarations (only one so far)
	//---------------------------------------
	class hkpRigidBody;

	// Memory management
	//----------------------
	class hkMemoryRouter
	{
	public:
		BB_INSERT_PADDING(44);
		class Heap
		{
		public:
			BB_INSERT_PADDING(0x04);

			virtual ~Heap();

			/// Allocate numBytes.
			virtual void* blockAlloc(int numBytes) = 0;

			/// Free numBytes.
			virtual void blockFree(void* p, int numBytes) = 0;

		};

		Heap* m_heap;
		// Havok SDK method syntax
		Heap& heap() { return *m_heap; }
	};
	class hkMemoryTracker
	{
	protected:
		~hkMemoryTracker() = default;

	public:
		/// New hkReferenced derived object
		virtual void onNewReferencedObject(const char* typeName, hk_size_t size, void* ptr) = 0;
		/// Delete hkReferenced derived object
		virtual void onDeleteReferencedObject(void* ptr) = 0;
	};

	inline hkMemoryRouter* getMemoryRouter()
	{
		uint32_t m_slotID = *(int*)0x01CFCBE0;
		return (hkMemoryRouter*)(unsigned long)TlsGetValue(m_slotID);
	}
	inline hkMemoryTracker* getTrackerInstancePtr()
	{
		BB_FUNCTION_PTR(void*, __cdecl, GET, 0x00898640);
		return (hkMemoryTracker*)GET();
	}


	// Basic Types
	//----------------------
	class hkReferencedObject
	{
		__int16 m_memSizeAndFlags {};
		__int16 m_referenceCount {};

	public:
		virtual ~hkReferencedObject() {}

		__forceinline static const char* getTypeIdentifier() { return __FUNCTION__; }

		__forceinline void* __cdecl operator new(hk_size_t nbytes)
		{
			hkReferencedObject* b = static_cast<hkReferencedObject*>(getMemoryRouter()->heap().blockAlloc(static_cast<int>(nbytes)));
			b->m_memSizeAndFlags = static_cast<hkUint16>(nbytes);
			if (hkMemoryTracker* _trk = getTrackerInstancePtr())
				_trk->onNewReferencedObject(getTypeIdentifier(), nbytes, b);
			return b;
		}

		__forceinline void __cdecl operator delete(void* p)
		{
			hkReferencedObject* b = static_cast<hkReferencedObject*>(p);
			if (hkMemoryTracker* _trk = getTrackerInstancePtr())
				_trk->onDeleteReferencedObject(b);
			getMemoryRouter()->heap().blockFree(p, b->m_memSizeAndFlags);
		}

		__forceinline void* __cdecl operator new(hk_size_t, void* p) { return p; }
		__forceinline void* __cdecl operator new[](hk_size_t, void* p)
		{
			__asm { int 3 };
			return p;
		}
		__forceinline void __cdecl operator delete(void*, void*)
		{
		}
		__forceinline void __cdecl operator delete[](void*, void*)
		{
			__asm { int 3 };
		}

		void addReference()
		{
			BB_FUNCTION_PTR(void, __thiscall, func, 0x008720D0, hkReferencedObject * This);
			func(this);
		}

		void removeReference()
		{
			BB_FUNCTION_PTR(void, __thiscall, func, 0x00872170, hkReferencedObject * This);
			func(this);
		}
	};

	template <typename T>
	class hkArray
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

	class hkFinishLoadedObjectFlag
	{
		//+hk.hkMemoryTracker(ignore=True)
	public:
		hkFinishLoadedObjectFlag() : m_finishing(0) {}
		int m_finishing;
	};

	class hkStringPtr
	{
	public:

		///
		enum hkStringFlags
		{
			/// If we own it, we free it.
			OWNED_FLAG = 0x1,
		};

		const char* cString() const
		{
			return reinterpret_cast<char*>(unsigned long(m_stringAndFlag) & ~OWNED_FLAG);
		}

		/// m_stringAndFlag&~1 is the real pointer, m_stringAndFlag&1 is the deallocate flag.
		const char* m_stringAndFlag{};
	};


	// Animation
	//--------------------------

	class hkTransform
	{
	public:
		Hedgehog::Math::CVector     m_translation;
		Hedgehog::Math::CQuaternion m_rotation;
		Hedgehog::Math::CVector     m_scale;
	};

	class hkaBone
	{
	public:
		static const struct InternalClassMember Members[];

		__forceinline hkaBone() : m_lockTranslation(false) {}
		__forceinline hkaBone(const hkaBone& other)
		{
			*this = other;
		}
		__forceinline hkaBone& operator=(const hkaBone& other)
		{
			if (this == &other)
			{
				return *this;
			}
			m_name = other.m_name;
			m_lockTranslation = other.m_lockTranslation;
			return *this;
		}

		/// The name of the bone from the toolchain
		hkStringPtr m_name;

		/// Whether or not this bone can move relative to its parent
		int m_lockTranslation;
	};

	class hkaSkeleton
	{
	public:

		virtual ~hkaSkeleton() = default;

		unsigned short m_memSizeAndFlags;

		/// Reference count. Note that if m_memSizeAndFlags == 0,
		/// reference counting is disabled for this object.
		mutable signed short m_referenceCount;

		/// Get the local frame that is attached to a bone. Returns HK_NULL if there isn't one.
		void* getLocalFrameForBone(int boneIndex) const;

		//
		// Members
		//

			/// A user name to aid in identifying the skeleton
		hkStringPtr m_name;

		/// Parent relationship
		hkArray<signed short> m_parentIndices;

		/// Bones for this skeleton
		hkArray<hkaBone> m_bones;
	};

	// Required thing
	class hkaAnimationControlListener
	{
		//+hk.hkMemoryTracker(ignore=True)
	public:

		/// Called whenever the control is destroyed
		virtual void controlDeletedCallback(class hkaAnimationControl* control) {}

		/// Virtual destructor for derived objects
		virtual ~hkaAnimationControlListener() {}
	};

	class hkaAnimatedSkeleton : public hkReferencedObject, protected hkaAnimationControlListener
	{
	public:
		hkaAnimatedSkeleton(const hkaSkeleton* skeleton);

	private:
		// Array of controls. TODO: Investigate & implement their types.
		__declspec(align(16)) hkArray<void*> m_animationControls;

	public:
		/// The skeleton associated with all animations/controls.
		const hkaSkeleton* m_skeleton;

		inline const hkaSkeleton* getSkeleton()
		{
			return m_skeleton;
		}

		/// The fill threshold below which the reference pose will be blending in when the sum of the control weights is small.
		float m_referencePoseWeightThreshold;

		/// An hkaAnimatedSkeleton consisting of only hkaQuantizedAnimation can be executed more efficiently. Keep track of the number here.
		signed int m_numQuantizedAnimations;

	};

	// Collision
	// -----------------------------
	class hkpShape : public hkReferencedObject
	{
	public:
		enum ShapeType
		{
			HK_SHAPE_INVALID = 0x0,
			HK_SHAPE_SPHERE = 0x1,
			HK_FIRST_SHAPE_TYPE = 0x1,
			HK_SHAPE_CYLINDER = 0x2,
			HK_SHAPE_TRIANGLE = 0x3,
			HK_SHAPE_BOX = 0x4,
			HK_SHAPE_CAPSULE = 0x5,
			HK_SHAPE_CONVEX_VERTICES = 0x6,
			HK_SHAPE_COLLECTION = 0x7,
			HK_SHAPE_BV_TREE = 0x8,
			HK_SHAPE_LIST = 0x9,
			HK_SHAPE_MOPP = 0xA,
			HK_SHAPE_CONVEX_TRANSLATE = 0xB,
			HK_SHAPE_CONVEX_TRANSFORM = 0xC,
			HK_SHAPE_SAMPLED_HEIGHT_FIELD = 0xD,
			HK_SHAPE_EXTENDED_MESH = 0xE,
			HK_SHAPE_TRANSFORM = 0xF,
			HK_SHAPE_COMPRESSED_MESH = 0x10,
			HK_SHAPE_COMPOUND = 0x11,
			HK_SHAPE_MAX_ID_SPU = 0x12,
			HK_SHAPE_CONVEX = 0x13,
			HK_SHAPE_MOPP_EMBEDDED = 0x14,
			HK_SHAPE_CONVEX_PIECE = 0x15,
			HK_SHAPE_MULTI_SPHERE = 0x16,
			HK_SHAPE_CONVEX_LIST = 0x17,
			HK_SHAPE_TRIANGLE_COLLECTION = 0x18,
			HK_SHAPE_MULTI_RAY = 0x19,
			HK_SHAPE_HEIGHT_FIELD = 0x1A,
			HK_SHAPE_SPHERE_REP = 0x1B,
			HK_SHAPE_BV = 0x1C,
			HK_SHAPE_PLANE = 0x1D,
			HK_SHAPE_PHANTOM_CALLBACK = 0x1E,
			HK_SHAPE_USER0 = 0x1F,
			HK_SHAPE_USER1 = 0x20,
			HK_SHAPE_USER2 = 0x21,
			HK_SHAPE_MAX_ID = 0x22,
			HK_SHAPE_ALL = 0xFFFFFFFF,
		};

		uint32_t m_userData = 0;
		ShapeType m_shapeType = HK_SHAPE_INVALID;

	};

	class hkpSphereShape : public hkpShape
	{
	public:
		float m_Radius = 1.0f;
	private:
		int m_Field14{};
		int m_Field18{};
		int m_Field1C{};

	public:

		hkpSphereShape(float radius)
		{
			BB_FUNCTION_PTR(void*, __thiscall, ctor, 0x008C2D30, hkpSphereShape * This, float _radius);
			//m_Unk = 32;
			ctor(this, radius);
		}
	};
	BB_ASSERT_SIZEOF(hkpSphereShape, 0x20);

	class hkpBoxShape : public hkpShape
	{
	public:
		float m_ConvexShapeRadius = 0.050000001f;
		Hedgehog::Math::CVector m_HalfExtents{};

		hkpBoxShape(const Hedgehog::Math::CVector& halfExtents, float radius = 0.050000001f)
		{
			BB_FUNCTION_PTR(void*, __thiscall, ctor, 0x008CC880, hkpBoxShape* This, const Hedgehog::Math::CVector& _halfExtents, float _radius);
			ctor(this, halfExtents, radius);
		}
		hkpBoxShape(float Width, float Height, float Length, float radius = 0.050000001f)
		{
			BB_FUNCTION_PTR(void*, __thiscall, ctor, 0x008CC880, hkpBoxShape* This, const Hedgehog::Math::CVector& _halfExtents, float _radius);
			ctor(this, Hedgehog::Math::CVector(Width * 0.5f, Height * 0.5f, Length * 0.5f), radius);
		}
	};
	BB_ASSERT_SIZEOF(hkpBoxShape, 0x30);

	class hkpRigidBody : public hkReferencedObject
	{
		class hkpCollideable
		{
		public:
			hkpShape* m_Shape{};
			uint32_t m_ShapeKey{};
			const void* m_Motion{};
			const hkpCollideable* m_Parent{};
		};

	public:
		int m_Unk1;
		int m_Unk2;
		hkpCollideable m_Collideable;
	};
	BB_ASSERT_OFFSETOF(hkpRigidBody, m_Collideable, 0x10);
}