#pragma once

#include <Hedgehog/Base/hhRefCountObject.h>
#include <Hedgehog/Base/Type/hhSharedString.h>

namespace Sonic
{
	class CParamPosition;

	static inline uint32_t pCParamPositionCtor = 0xCEE100;

	static __declspec(noinline) CParamPosition* fCParamPositionCtor(CParamPosition* This,
	                                                                const Hedgehog::Base::CSharedString* in_pDescription,
	                                                                Hedgehog::Math::CVector* in_pValue, uint32_t in_Unknown)
	{
		__asm
		{
			push in_Unknown
			push in_pDescription
			mov edi, in_pValue
			mov esi, This
			call [pCParamPositionCtor]
		}
	}

	class CParamPosition : public CParamBase
	{
	public:
		static constexpr void* ms_pVfTable = (void*)0x016E5ABC;
		BB_INSERT_PADDING(0x8C);

		static CParamPosition* Create(Hedgehog::Math::CVector* pValue, const Hedgehog::Base::CSharedString& description = "")
		{
			CParamPosition* param = static_cast<CParamPosition*>(__HH_ALLOC(sizeof(CParamPosition)));
			fCParamPositionCtor(param, &description, pValue, 0x0C);

			param->AddRef();
			return param;
		}
	};
	BB_ASSERT_SIZEOF(CParamPosition, 0xA0);
}
