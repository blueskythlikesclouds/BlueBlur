#pragma once

#include <Hedgehog/Base/hhRefCountObject.h>
#include <Hedgehog/Base/Type/hhSharedString.h>

namespace Sonic
{
	class CParamTargetList;

	static inline uint32_t pCParamTargetListCtor = 0xCEC3F0;

	static __declspec(noinline) CParamTargetList* fCParamTargetListCtor
	(
		CParamTargetList* This,
		const Hedgehog::Base::CSharedString* in_pDescription
	)
	{
		__asm
		{
			push in_pDescription
			mov esi, This
			call [pCParamTargetListCtor]
		}
	}

	class CParamTargetList : public CParamBase
	{
	public:
		static constexpr void* ms_pVfTable = (void*)0x16E5BDC;
		BB_INSERT_PADDING(0x4);
		uint32_t* m_ListStart;
		uint32_t* m_ListEnd;
		BB_INSERT_PADDING(0x14);
		Hedgehog::Base::CSharedString m_Description;
		BB_INSERT_PADDING(0x20);

		static CParamTargetList* Create(const Hedgehog::Base::CSharedString& description = "")
		{
			CParamTargetList* param = static_cast<CParamTargetList*>(__HH_ALLOC(sizeof(CParamTargetList)));
			fCParamTargetListCtor(param, &description);

			param->AddRef();
			return param;
		}
	};
	BB_ASSERT_OFFSETOF(CParamTargetList, m_ListStart, 0x18);
	BB_ASSERT_OFFSETOF(CParamTargetList, m_ListEnd, 0x1C);
	BB_ASSERT_OFFSETOF(CParamTargetList, m_Description, 0x34);
	BB_ASSERT_SIZEOF(CParamTargetList, 0x58);
}
