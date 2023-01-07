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
        T* m_pValue;
        T m_DefaultValue;
        alignas(4) BB_INSERT_PADDING(0x24);
    };

    struct SParamEnumValue
    {
        const char* Name;
        uint32_t Value;
    };

    static void* const pCEditParamCreateParamBool = (void*)0xCEF4F0;
    static void* const pCEditParamCreateParamUnsignedLong = (void*)0x591300;
    static void* const pCEditParamCreateParamLong = (void*)0x590FB0;
    static void* const pCEditParamCreateParamInt = (void*)0x590DA0;
    static void* const pCEditParamCreateParamFloat = (void*)0x590770;
    static void* const pCEditParamAddParamTypeList = (void*)0xCEF700;

    static CParamBool* fCEditParamCreateParamBool(
        const SParamValueCreationParams<bool>* pCreationParams, CEditParam* pEditParam, const Hedgehog::Base::CSharedString* pName)
    {
        __asm
        {
            mov eax, pCreationParams
            push pName
            push pEditParam
            call[pCEditParamCreateParamBool]
        }
    }

    static CParamValue<unsigned long>* fCEditParamCreateParamUnsignedLong(
        const SParamValueCreationParams<unsigned long>* pCreationParams, CEditParam* pEditParam, const Hedgehog::Base::CSharedString* pName)
    {
        __asm
        {
            mov eax, pCreationParams
            push pName
            push pEditParam
            call[pCEditParamCreateParamUnsignedLong]
        }
    }

    static CParamValue<long>* fCEditParamCreateParamLong(
        const SParamValueCreationParams<long>* pCreationParams, CEditParam* pEditParam, const Hedgehog::Base::CSharedString* pName)
    {
        __asm
        {
            mov eax, pCreationParams
            push pName
            push pEditParam
            call[pCEditParamCreateParamLong]
        }
    }

    static CParamValue<int>* fCEditParamCreateParamInt(
        const SParamValueCreationParams<int>* pCreationParams, CEditParam* pEditParam, const Hedgehog::Base::CSharedString* pName)
    {
        __asm
        {
            mov eax, pCreationParams
            push pName
            push pEditParam
            call[pCEditParamCreateParamInt]
        }
    }

    static CParamValue<float>* fCEditParamCreateParamFloat(
        const SParamValueCreationParams<float>* pCreationParams, CEditParam* pEditParam, const Hedgehog::Base::CSharedString* pName)
    {
        __asm
        {
            mov eax, pCreationParams
            push pName
            push pEditParam
            call[pCEditParamCreateParamFloat]
        }
    }

    static void fCEditParamAddParamTypeList(const Hedgehog::Base::CSharedString* pName, CEditParam* pEditParam, CParamTypeList* pParamTypeList)
    {
        __asm
        {
            mov eax, pName
            mov ecx, pEditParam
            push pParamTypeList
            call[pCEditParamAddParamTypeList]
        }
    }

    class CEditParam : public Hedgehog::Base::CRefCountObject
    {
    public:
        hh::vector<CParamBase*> m_ParamList;
        BB_INSERT_PADDING(0x20);

        CParamBool* CreateParamBool(const SParamValueCreationParams<bool>& creationParams, const Hedgehog::Base::CSharedString& name)
        {
            return fCEditParamCreateParamBool(&creationParams, this, &name);
        }

        CParamBool* CreateParamBool(bool* pValue, const Hedgehog::Base::CSharedString& name)
        {
            return CreateParamBool({ pValue, *pValue }, name);
        }

        CParamValue<unsigned long>* CreateParamUnsignedLong(const SParamValueCreationParams<unsigned long>& creationParams, const Hedgehog::Base::CSharedString& name)
        {
            return fCEditParamCreateParamUnsignedLong(&creationParams, this, &name);
        }

        CParamValue<unsigned long>* CreateParamUnsignedLong(unsigned long* pValue, const Hedgehog::Base::CSharedString& name)
        {
            return CreateParamUnsignedLong({ pValue, *pValue }, name);
        }

        CParamValue<long>* CreateParamLong(const SParamValueCreationParams<long>& creationParams, const Hedgehog::Base::CSharedString& name)
        {
            return fCEditParamCreateParamLong(&creationParams, this, &name);
        }

        CParamValue<long>* CreateParamLong(long* pValue, const Hedgehog::Base::CSharedString& name)
        {
            return CreateParamLong({ pValue, *pValue }, name);
        }

        CParamValue<int>* CreateParamInt(const SParamValueCreationParams<int>& creationParams, const Hedgehog::Base::CSharedString& name)
        {
            return fCEditParamCreateParamInt(&creationParams, this, &name);
        }

        CParamValue<int>* CreateParamInt(int* pValue, const Hedgehog::Base::CSharedString& name)
        {
            return CreateParamInt({ pValue, *pValue }, name);
        }

        CParamValue<float>* CreateParamFloat(const SParamValueCreationParams<float>& creationParams, const Hedgehog::Base::CSharedString& name)
        {
            return fCEditParamCreateParamFloat(&creationParams, this, &name);
        }

        CParamValue<float>* CreateParamFloat(float* pValue, const Hedgehog::Base::CSharedString& name)
        {
            return CreateParamFloat({ pValue, *pValue }, name);
        }

        template<typename T>
        CParamTypeList* CreateParamTypeList(
            uint32_t* pValue, const Hedgehog::Base::CSharedString& name, const Hedgehog::Base::CSharedString& description, const T& values)
        {
            CParamTypeList* pParamTypeList = CParamTypeList::Create(pValue, description);

            for (auto& value : values)
                pParamTypeList->AddValue(value.Name, value.Value);

            pParamTypeList->AddRef();
            fCEditParamAddParamTypeList(&name, this, pParamTypeList);

            return pParamTypeList;
        }

        CParamTypeList* CreateParamTypeList(
            uint32_t* pValue, const Hedgehog::Base::CSharedString& name, const Hedgehog::Base::CSharedString& description, const std::initializer_list<SParamEnumValue>& values)
        {
            return CreateParamTypeList<std::initializer_list<SParamEnumValue>>(pValue, name, description, values);
        }

        CParamTypeList* CreateParamTypeList(
            uint32_t* pValue, const Hedgehog::Base::CSharedString& name, const Hedgehog::Base::CSharedString& description, const std::vector<SParamEnumValue>& values)
        {
            return CreateParamTypeList<std::vector<SParamEnumValue>>(pValue, name, description, values);
        }
    };

    BB_ASSERT_OFFSETOF(CEditParam, m_ParamList, 0x8);
    BB_ASSERT_SIZEOF(CEditParam, 0x38);
}
