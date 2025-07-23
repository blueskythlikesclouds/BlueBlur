#pragma once

#include <Hedgehog/Base/Type/hhSharedString.h>

namespace Sonic::Sequence
{
	class CSequenceMode;

	class CModeCreaterListImpl
	{
	public:
		hh::map<Hedgehog::Base::CSharedString, boost::function<Sonic::Sequence::CSequenceMode* ()>> m_SequenceModes;

		virtual void CModeCreaterListImpl00(const char*, void*);
		virtual boost::function<Sonic::Sequence::CSequenceMode* ()> CModeCreaterListImpl04(const char*);

		static inline CModeCreaterListImpl* ms_pInstance = (CModeCreaterListImpl*)0x01E78908;
		static CModeCreaterListImpl* GetInstance();
	};
	BB_ASSERT_OFFSETOF(CModeCreaterListImpl, m_SequenceModes, 0x4);
	BB_ASSERT_SIZEOF(CModeCreaterListImpl, 0x10);
}
#include <Sonic/Sequence/ModeCreaterList.inl>