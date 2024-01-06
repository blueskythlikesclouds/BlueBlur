#pragma once

#include <Hedgehog/Base/hhObject.h>
#include <Hedgehog/Database/System/hhCallback.h>

namespace Hedgehog::Database
{
	class CDatabase;
	class CCallback;
	class CSharedString;
	struct SArchiveParam;
}

namespace Hedgehog::Base
{
	class CEventWait;

	class CCompressor : public Hedgehog::Base::CObject
	{
	public:
		boost::shared_ptr<CEventWait> m_spEventWait;

		virtual ~CCompressor() = default;

		virtual void CheckDecompressed(const boost::shared_ptr<Database::CDatabase>& in_spDatabase, const Hedgehog::Base::CSharedString& in_rName, const boost::shared_ptr<uint8_t[]>& in_spSrc,
			size_t in_SrcSize, const boost::shared_ptr<Database::CCallback>& in_spCallback, const Database::SArchiveParam& in_rParam) = 0;

		virtual void Decompress(const boost::shared_ptr<Database::CDatabase>& in_spDatabase, const Hedgehog::Base::CSharedString& in_rName, const boost::shared_ptr<uint8_t[]>& in_spSrc, 
			size_t in_SrcSize, size_t in_SrcSize2, const boost::shared_ptr<Database::CCallback>& in_spCallback, const Database::SArchiveParam& in_rParam) = 0;

		virtual void WaitAll() = 0;
		virtual void Update() = 0;
	};

	BB_ASSERT_OFFSETOF(CCompressor, m_spEventWait, 4);
	BB_ASSERT_SIZEOF(CCompressor, 12);
}