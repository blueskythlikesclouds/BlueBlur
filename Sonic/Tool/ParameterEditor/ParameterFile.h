#pragma once

#include <Hedgehog/Base/Type/hhSharedString.h>
#include <Sonic/Tool/ParameterEditor/AbstractParameter.h>

namespace Sonic
{
    class CParameterFile;
    class CParameterGroup;

    static inline BB_FUNCTION_PTR(void, __stdcall, fpCParameterFileCreateParameterGroup, 0x1257EF0,
        CParameterFile* in_pParameterFile, boost::shared_ptr<CParameterGroup>& out_spParameterGroup, const Hedgehog::Base::CSharedString& in_rName, const Hedgehog::Base::CSharedString& in_rDescription);

    class CParameterFile : public CAbstractParameter
    {
    public:
        static constexpr void* ms_pVfTable = (void*)0x16E5E88;

        void CreateParameterGroup(boost::shared_ptr<CParameterGroup>& out_spParameterGroup, const Hedgehog::Base::CSharedString& in_rName, const Hedgehog::Base::CSharedString& in_rDescription)
        {
            fpCParameterFileCreateParameterGroup(this, out_spParameterGroup, in_rName, in_rDescription);
        }

        boost::shared_ptr<CParameterGroup> CreateParameterGroup(const Hedgehog::Base::CSharedString& in_rName, const Hedgehog::Base::CSharedString& in_rDescription)
        {
            boost::shared_ptr<CParameterGroup> spParameterGroup;
            fpCParameterFileCreateParameterGroup(this, spParameterGroup, in_rName, in_rDescription);
            return spParameterGroup;
        }
    };

    BB_ASSERT_SIZEOF(CParameterFile, 0x34);
}