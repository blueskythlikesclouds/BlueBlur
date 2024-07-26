#pragma once

#include <Hedgehog/Base/hhRefCountObject.h>
#include <Hedgehog/Base/Type/hhSharedString.h>

namespace Sonic
{
	class CParamRotation;

	static inline uint32_t pCParamRotationCtor = 0xCED5D0;

	static __declspec(noinline) CParamRotation* fCParamRotationCtor(CParamRotation* This,
	                                                                const Hedgehog::Base::CSharedString* in_pDescription,
	                                                                Hedgehog::Math::CQuaternion* in_pValue)
	{
		__asm
		{
			push in_pDescription
			mov edi, in_pValue
			mov esi, This
			call [pCParamRotationCtor]
		}
	}

	class CParamRotation : public CParamBase
	{
	public:
		static constexpr void* ms_pVfTable = (void*)0x016E5B1C;
		BB_INSERT_PADDING(0x8C);

		static CParamRotation* Create(Hedgehog::Math::CQuaternion* pValue, const Hedgehog::Base::CSharedString& description = "")
		{
			CParamRotation* param = static_cast<CParamRotation*>(__HH_ALLOC(sizeof(CParamRotation)));
			fCParamRotationCtor(param, &description, pValue);

			param->AddRef();
			return param;
		}
	};
	BB_ASSERT_SIZEOF(CParamRotation, 0xA0);
}
