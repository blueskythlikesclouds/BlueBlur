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

    static void* const pCEditParamCreateParamBool = (void*)0xCEF4F0;
    static void* const pCEditParamCreateParamUnsignedLong = (void*)0x591300;
    static void* const pCEditParamCreateParamLong = (void*)0x590FB0;
    static void* const pCEditParamCreateParamInt = (void*)0x590DA0;
    static void* const pCEditParamCreateParamFloat = (void*)0x590770;
    static void* const pCEditParamAddParamTypeList = (void*)0xCEF700;

    static CParamBool* fCEditParamCreateParamBool(
        const SParamValueCreationParams<bool>* in_pCreationParams, CEditParam* in_pEditParam, const Hedgehog::Base::CSharedString* in_pName)
    {
        __asm
        {
            mov eax, in_pCreationParams
            push in_pName
            push in_pEditParam
            call[pCEditParamCreateParamBool]
        }
    }

    static CParamValue<unsigned long>* fCEditParamCreateParamUnsignedLong(
        const SParamValueCreationParams<unsigned long>* in_pCreationParams, CEditParam* in_pEditParam, const Hedgehog::Base::CSharedString* in_pName)
    {
        __asm
        {
            mov eax, in_pCreationParams
            push in_pName
            push in_pEditParam
            call[pCEditParamCreateParamUnsignedLong]
        }
    }

    static CParamValue<long>* fCEditParamCreateParamLong(
        const SParamValueCreationParams<long>* in_pCreationParams, CEditParam* in_pEditParam, const Hedgehog::Base::CSharedString* in_pName)
    {
        __asm
        {
            mov eax, in_pCreationParams
            push in_pName
            push in_pEditParam
            call[pCEditParamCreateParamLong]
        }
    }

    static CParamValue<int>* fCEditParamCreateParamInt(
        const SParamValueCreationParams<int>* in_pCreationParams, CEditParam* in_pEditParam, const Hedgehog::Base::CSharedString* in_pName)
    {
        __asm
        {
            mov eax, in_pCreationParams
            push in_pName
            push in_pEditParam
            call[pCEditParamCreateParamInt]
        }
    }

    static CParamValue<float>* fCEditParamCreateParamFloat(
        const SParamValueCreationParams<float>* in_pCreationParams, CEditParam* in_pEditParam, const Hedgehog::Base::CSharedString* in_pName)
    {
        __asm
        {
            mov eax, in_pCreationParams
            push in_pName
            push in_pEditParam
            call[pCEditParamCreateParamFloat]
        }
    }

    static void fCEditParamAddParamTypeList(const Hedgehog::Base::CSharedString* in_pName, CEditParam* in_pEditParam, CParamTypeList* in_pParamTypeList)
    {
        __asm
        {
            mov eax, in_pName
            mov ecx, in_pEditParam
            push in_pParamTypeList
            call[pCEditParamAddParamTypeList]
        }
    }

    class CEditParam : public Hedgehog::Base::CRefCountObject
    {
    public:
        hh::vector<CParamBase*> m_ParamList;
        BB_INSERT_PADDING(0x20);

        CParamBool* CreateParamBool(const SParamValueCreationParams<bool>& in_rCreationParams, const Hedgehog::Base::CSharedString& in_rName)
        {
            return fCEditParamCreateParamBool(&in_rCreationParams, this, &in_rName);
        }

        CParamBool* CreateParamBool(bool* pValue, const Hedgehog::Base::CSharedString& in_rName)
        {
            return CreateParamBool({ pValue, *pValue }, in_rName);
        }

        CParamValue<unsigned long>* CreateParamUnsignedLong(const SParamValueCreationParams<unsigned long>& in_rCreationParams, const Hedgehog::Base::CSharedString& in_rName)
        {
            return fCEditParamCreateParamUnsignedLong(&in_rCreationParams, this, &in_rName);
        }

        CParamValue<unsigned long>* CreateParamUnsignedLong(unsigned long* pValue, const Hedgehog::Base::CSharedString& in_rName)
        {
            return CreateParamUnsignedLong({ pValue, *pValue }, in_rName);
        }

        CParamValue<long>* CreateParamLong(const SParamValueCreationParams<long>& in_rCreationParams, const Hedgehog::Base::CSharedString& in_rName)
        {
            return fCEditParamCreateParamLong(&in_rCreationParams, this, &in_rName);
        }

        CParamValue<long>* CreateParamLong(long* pValue, const Hedgehog::Base::CSharedString& in_rName)
        {
            return CreateParamLong({ pValue, *pValue }, in_rName);
        }

        CParamValue<int>* CreateParamInt(const SParamValueCreationParams<int>& in_rCreationParams, const Hedgehog::Base::CSharedString& in_rName)
        {
            return fCEditParamCreateParamInt(&in_rCreationParams, this, &in_rName);
        }

        CParamValue<int>* CreateParamInt(int* pValue, const Hedgehog::Base::CSharedString& in_rName)
        {
            return CreateParamInt({ pValue, *pValue }, in_rName);
        }

        CParamValue<float>* CreateParamFloat(const SParamValueCreationParams<float>& in_rCreationParams, const Hedgehog::Base::CSharedString& in_rName)
        {
            return fCEditParamCreateParamFloat(&in_rCreationParams, this, &in_rName);
        }

        CParamValue<float>* CreateParamFloat(float* pValue, const Hedgehog::Base::CSharedString& in_rName)
        {
            return CreateParamFloat({ pValue, *pValue }, in_rName);
        }

        template<typename T>
        CParamTypeList* CreateParamTypeList(
            uint32_t* pValue, const Hedgehog::Base::CSharedString& in_rName, const Hedgehog::Base::CSharedString& in_rDescription, const T& in_rValues)
        {
            CParamTypeList* pParamTypeList = CParamTypeList::Create(pValue, in_rDescription);

            for (auto& value : in_rValues)
                pParamTypeList->AddValue(value.pName, value.Value);

            pParamTypeList->AddRef();
            fCEditParamAddParamTypeList(&in_rName, this, pParamTypeList);

            return pParamTypeList;
        }

        CParamTypeList* CreateParamTypeList(
            uint32_t* pValue, const Hedgehog::Base::CSharedString& in_rName, const Hedgehog::Base::CSharedString& in_rDescription, const std::initializer_list<SParamEnumValue>& in_rValues)
        {
            return CreateParamTypeList<std::initializer_list<SParamEnumValue>>(pValue, in_rName, in_rDescription, in_rValues);
        }

        CParamTypeList* CreateParamTypeList(
            uint32_t* pValue, const Hedgehog::Base::CSharedString& in_rName, const Hedgehog::Base::CSharedString& in_rDescription, const std::vector<SParamEnumValue>& in_rValues)
        {
            return CreateParamTypeList<std::vector<SParamEnumValue>>(pValue, in_rName, in_rDescription, in_rValues);
        }
    };

    BB_ASSERT_OFFSETOF(CEditParam, m_ParamList, 0x8);
    BB_ASSERT_SIZEOF(CEditParam, 0x38);
}
