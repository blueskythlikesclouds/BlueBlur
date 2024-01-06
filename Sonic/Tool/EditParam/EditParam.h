#pragma once

#include <Hedgehog/Base/hhRefCountObject.h>
#include <Hedgehog/Base/Container/hhVector.h>
#include <Hedgehog/Base/Type/hhSharedString.h>
#include <Sonic/Tool/EditParam/ParamTypeList.h>

namespace Sonic
{
    template<typename T>
    class CParamValue;
    class CParamBool;
    class CParamBase;

    template<typename T>
    struct SParamValueCreationParams
    {
        T* pValue;
        T DefaultValue;
        boost::function1<void, T> ChangedCallback;
        Hedgehog::Base::CSharedString Description;
    };

    struct SParamEnumValue
    {
        const char* pName;
        uint32_t Value;
    };

    class CEditParam : public Hedgehog::Base::CRefCountObject
    {
    public:
        hh::vector<CParamBase*> m_ParamList;
        BB_INSERT_PADDING(0x20);

        CParamBool* CreateParamBool(const SParamValueCreationParams<bool>& in_rCreationParams, const Hedgehog::Base::CSharedString& in_rName);
        CParamBool* CreateParamBool(bool* pValue, const Hedgehog::Base::CSharedString& in_rName);

        CParamValue<unsigned long>* CreateParamUnsignedLong(const SParamValueCreationParams<unsigned long>& in_rCreationParams, const Hedgehog::Base::CSharedString& in_rName);
        CParamValue<unsigned long>* CreateParamUnsignedLong(unsigned long* pValue, const Hedgehog::Base::CSharedString& in_rName);

        CParamValue<long>* CreateParamLong(const SParamValueCreationParams<long>& in_rCreationParams, const Hedgehog::Base::CSharedString& in_rName);
        CParamValue<long>* CreateParamLong(long* pValue, const Hedgehog::Base::CSharedString& in_rName);

        CParamValue<int>* CreateParamInt(const SParamValueCreationParams<int>& in_rCreationParams, const Hedgehog::Base::CSharedString& in_rName);
        CParamValue<int>* CreateParamInt(int* pValue, const Hedgehog::Base::CSharedString& in_rName);

        CParamValue<float>* CreateParamFloat(const SParamValueCreationParams<float>& in_rCreationParams, const Hedgehog::Base::CSharedString& in_rName);
        CParamValue<float>* CreateParamFloat(float* pValue, const Hedgehog::Base::CSharedString& in_rName);

        template<typename T>
        CParamTypeList* CreateParamTypeList(uint32_t* pValue, const Hedgehog::Base::CSharedString& in_rName, 
            const Hedgehog::Base::CSharedString& in_rDescription, const T& in_rValues);

        CParamTypeList* CreateParamTypeList(uint32_t* pValue, const Hedgehog::Base::CSharedString& in_rName, 
            const Hedgehog::Base::CSharedString& in_rDescription, const std::initializer_list<SParamEnumValue>& in_rValues);

        CParamTypeList* CreateParamTypeList(uint32_t* pValue, const Hedgehog::Base::CSharedString& in_rName,
            const Hedgehog::Base::CSharedString& in_rDescription, const std::vector<SParamEnumValue>& in_rValues);
    };

    BB_ASSERT_OFFSETOF(CEditParam, m_ParamList, 0x8);
    BB_ASSERT_SIZEOF(CEditParam, 0x38);
}

#include <Sonic/Tool/EditParam/EditParam.inl>