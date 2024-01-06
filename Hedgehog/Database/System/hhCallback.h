#pragma once

#include <Hedgehog/Base/hhObject.h>
#include <Hedgehog/Base/Type/hhSharedString.h>

namespace Hedgehog::Database
{
    class CDatabase;
    struct SArchiveParam;

    class CCallback : public Hedgehog::Base::CObject
    {
    public:
        virtual ~CCallback() = default;
        virtual void InvokeOld(const boost::shared_ptr<CDatabase>& in_spDatabase, const Base::CSharedString& in_rName, boost::shared_ptr<uint8_t[]> in_spData, size_t in_DataSize, size_t in_DataSize2, const SArchiveParam& in_rParam) { }
        virtual void Invoke(const boost::shared_ptr<CDatabase>& in_spDatabase, const Base::CSharedString& in_rName, boost::shared_ptr<uint8_t[]> in_spData, size_t in_DataSize, const SArchiveParam& in_rParam) = 0;
    };
}