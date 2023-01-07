#pragma once

#include <Hedgehog/Base/Type/hhSharedString.h>
#include <Sonic/Tool/ParameterEditor/AbstractParameter.h>

namespace Sonic
{
    class CParameterFile;
    class CParameterGroup;

    static inline BB_FUNCTION_PTR(void, __stdcall, fpCParameterFileCreateParameterGroup, 0x1257EF0,
        CParameterFile* pParameterFile, boost::shared_ptr<CParameterGroup>& spParameterGroup, const Hedgehog::Base::CSharedString& name, const Hedgehog::Base::CSharedString& description);

    class CParameterFile : public CAbstractParameter
    {
    public:
        static constexpr void* ms_pVfTable = (void*)0x16E5E88;

        void CreateParameterGroup(boost::shared_ptr<CParameterGroup>& spParameterGroup, const Hedgehog::Base::CSharedString& name, const Hedgehog::Base::CSharedString& description)
        {
            fpCParameterFileCreateParameterGroup(this, spParameterGroup, name, description);
        }

        boost::shared_ptr<CParameterGroup> CreateParameterGroup(const Hedgehog::Base::CSharedString& name, const Hedgehog::Base::CSharedString& description)
        {
            boost::shared_ptr<CParameterGroup> spParameterGroup;
            fpCParameterFileCreateParameterGroup(this, spParameterGroup, name, description);
            return spParameterGroup;
        }
    };

    BB_ASSERT_SIZEOF(CParameterFile, 0x34);
}