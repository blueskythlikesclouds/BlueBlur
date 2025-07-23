#pragma once

#include <Hedgehog/Base/hhRefCountObject.h>
#include <Hedgehog/Base/Container/hhMap.h>

namespace Sonic
{
	class CParameterBank : public Hedgehog::Base::CRefCountObject
	{
	public:
		class CValueBase : public Hedgehog::Base::CRefCountObject
		{
		public:
			virtual void LoadValue(const CValueBase& in_rValueBase) {}
			virtual uint32_t GetFlag() { return 0; }
			virtual Hedgehog::Base::CRefPtr<CValueBase>* SaveValue(Hedgehog::Base::CRefPtr<CValueBase>* in_pParameterBank) { return nullptr; }
		};
	
		bool m_IsSave;
		BB_INSERT_PADDING(0x3);
		hh::map<Hedgehog::Base::CSharedString, CValueBase> m_ValueMap;
		
		void AccessParameterBankBool(const Hedgehog::Base::CSharedString& in_rName, bool* in_pValue);
		void AccessParameterBankChar(const Hedgehog::Base::CSharedString& in_rName, char* in_pValue);
		void AccessParameterBankUnsignedChar(const Hedgehog::Base::CSharedString& in_rName, unsigned char* in_pValue);
		void AccessParameterBankLong(const Hedgehog::Base::CSharedString& in_rName, long* in_pValue);
		void AccessParameterBankUnsignedLong(const Hedgehog::Base::CSharedString& in_rName, unsigned long* in_pValue);
		void AccessParameterBankInt(const Hedgehog::Base::CSharedString& in_rName, int* in_pValue);
		void AccessParameterBankUnsignedInt(const Hedgehog::Base::CSharedString& in_rName, unsigned int* in_pValue);
		void AccessParameterBankFloat(const Hedgehog::Base::CSharedString& in_rName, float* in_pValue);
	};	
	
	BB_ASSERT_OFFSETOF(CParameterBank, m_IsSave, 0x8);
	BB_ASSERT_OFFSETOF(CParameterBank, m_ValueMap, 0xC);
	BB_ASSERT_SIZEOF(CParameterBank, 0x18);
}

#include <Sonic/Tool/ParameterBank/ParameterBank.inl>