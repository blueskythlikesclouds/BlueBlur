#pragma once

#include <Hedgehog/Base/hhRefCountObject.h>
#include <Hedgehog/Base/Type/hhSharedString.h>

namespace Sonic
{
	class CParamTarget;

	static inline uint32_t pCParamTargetCtor = 0xCECDE0;

	static __declspec(noinline) CParamTarget* fCParamTargetCtor
	(
		CParamTarget* This,
		const Hedgehog::Base::CSharedString* in_pDescription,
		uint32_t* in_pValue, 
		uint32_t in_Unknown
	)
	
	{
		__asm
		{
			push in_Unknown
			push in_pDescription
			mov edi, in_pValue
			mov esi, This
			call [pCParamTargetCtor]
		}
	}

	class CParamTarget : public CParamBase
	{
	public:
		static constexpr void* ms_pVfTable = (void*)0x16E5B7C;
		BB_INSERT_PADDING(0x2C);
		Hedgehog::Base::CSharedString m_Description;
		BB_INSERT_PADDING(0x2C);

		static CParamTarget* Create(uint32_t* pValue, const Hedgehog::Base::CSharedString& description = "")
		{
			CParamTarget* param = static_cast<CParamTarget*>(__HH_ALLOC(sizeof(CParamTarget)));
			fCParamTargetCtor(param, &description, pValue, 2);

			param->AddRef();
			return param;
		}
	};
	BB_ASSERT_OFFSETOF(CParamTarget, m_Description, 0x40);
	BB_ASSERT_SIZEOF(CParamTarget, 0x70);
}
