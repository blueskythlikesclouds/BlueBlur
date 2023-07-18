#pragma once

#include <Hedgehog/Database/System/hhCompressor.h>

namespace Hedgehog::Database
{
	class CDecompressCAB : public Base::CCompressor
	{
	public:
		boost::shared_ptr<Base::CCriticalSectionD3D9> m_spCriticalSectionD3D9;
		BB_INSERT_PADDING(0x30);

		CDecompressCAB(); // 0x006A0FC0
		~CDecompressCAB(); // 0x006A1760

		void CheckDecompressed(const boost::shared_ptr<Database::CDatabase>& in_spDatabase, const Hedgehog::Base::CSharedString& in_rName, const boost::shared_ptr<uint8_t[]>& in_spSrc, size_t in_SrcSize, const boost::shared_ptr<Database::CCallback>& in_spCallback, const Database::SArchiveParam& in_rParam) override;
		void Decompress(const boost::shared_ptr<Database::CDatabase>& in_spDatabase, const Hedgehog::Base::CSharedString& in_rName, const boost::shared_ptr<uint8_t[]>& in_spSrc, size_t in_SrcSize, size_t in_SrcSize2, const boost::shared_ptr<Database::CCallback>& in_spCallback, const Database::SArchiveParam& in_rParam) override;
		void WaitAll() override;
		void Update() override;
	};

	BB_ASSERT_OFFSETOF(CDecompressCAB, m_spCriticalSectionD3D9, 12);
	BB_ASSERT_SIZEOF(CDecompressCAB, 68);
}