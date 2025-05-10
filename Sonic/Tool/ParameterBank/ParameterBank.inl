namespace Sonic
{
    inline void* const pAccessParameterBankBool = (void*)0x457B10;
	inline BB_NOINLINE void fAccessParameterBankBool
	(
		CParameterBank* in_pParameterBank,
		Hedgehog::Base::CSharedString const* in_pName,
		bool* in_pValue
	)
	{
		__asm
		{
			push	in_pValue
			push	in_pParameterBank
			mov		eax, in_pName
			call	[pAccessParameterBankBool]
		}
	}
	
	inline void CParameterBank::AccessParameterBankBool(const Hedgehog::Base::CSharedString& in_rName, bool* pValue)
	{
		fAccessParameterBankBool(this, &in_rName, pValue);
	}

	inline void* const pAccessParameterBankChar = (void*)0x627A50;
	inline BB_NOINLINE void fAccessParameterBankChar
	(
		CParameterBank* in_pParameterBank,
		Hedgehog::Base::CSharedString const* in_pName,
		char* in_pValue
	)
	{
		__asm
		{
			push	in_pValue
			push	in_pParameterBank
			mov		eax, in_pName
			call	[pAccessParameterBankChar]
		}
	}
	
	inline void CParameterBank::AccessParameterBankChar(const Hedgehog::Base::CSharedString& in_rName, char* pValue)
	{
		fAccessParameterBankChar(this, &in_rName, pValue);
	}
	
	inline void CParameterBank::AccessParameterBankUnsignedChar(const Hedgehog::Base::CSharedString& in_rName, unsigned char* pValue)
	{
		fAccessParameterBankChar(this, &in_rName, (char*)pValue);
	}

	inline BB_FUNCTION_PTR(void, __stdcall, fAccessParameterBankLong, 0x5BAB60, CParameterBank* in_pParameterBank, Hedgehog::Base::CSharedString const* in_pName, long* in_pValue);
	
	inline void CParameterBank::AccessParameterBankLong(const Hedgehog::Base::CSharedString& in_rName, long* pValue)
	{
		fAccessParameterBankLong(this, &in_rName, pValue);
	}
	
	inline BB_FUNCTION_PTR(void, __stdcall, fAccessParameterBankUnsignedLong, 0x450520, CParameterBank* in_pParameterBank, Hedgehog::Base::CSharedString const* in_pName, unsigned long* in_pValue);
	
	inline void CParameterBank::AccessParameterBankUnsignedLong(const Hedgehog::Base::CSharedString& in_rName, unsigned long* pValue)
	{
		fAccessParameterBankUnsignedLong(this, &in_rName, pValue);
	}
	
	inline void CParameterBank::AccessParameterBankInt(const Hedgehog::Base::CSharedString& in_rName, int* pValue)
	{
		fAccessParameterBankLong(this, &in_rName, (long*)pValue);
	}
	
	inline void CParameterBank::AccessParameterBankUnsignedInt(const Hedgehog::Base::CSharedString& in_rName, unsigned int* pValue)
	{
		fAccessParameterBankUnsignedLong(this, &in_rName, (unsigned long*)pValue);
	}

	inline void* const pAccessParameterBankFloat = (void*)0x493D20;
	inline BB_NOINLINE void fAccessParameterBankFloat
	(
		CParameterBank* in_pParameterBank,
		Hedgehog::Base::CSharedString const* in_pName,
		float* in_pValue
	)
	{
		__asm
		{
			push	in_pValue
			push	in_pParameterBank
			mov		eax, in_pName
			call	[pAccessParameterBankFloat]
		}
	}
	
	inline void CParameterBank::AccessParameterBankFloat(const Hedgehog::Base::CSharedString& in_rName, float* pValue)
	{
		fAccessParameterBankFloat(this, &in_rName, pValue);
	}
}