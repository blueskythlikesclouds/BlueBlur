namespace Sonic
{
    inline void* const pCEditParamCreateParamBool = (void*)0xCEF4F0;

    inline CParamBool* fCEditParamCreateParamBool(
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

    inline CParamBool* CEditParam::CreateParamBool(const SParamValueCreationParams<bool>& in_rCreationParams,
        const Hedgehog::Base::CSharedString& in_rName)
    {
        return fCEditParamCreateParamBool(&in_rCreationParams, this, &in_rName);
    }

    inline CParamBool* CEditParam::CreateParamBool(bool* pValue, const Hedgehog::Base::CSharedString& in_rName)
    {
        return CreateParamBool({ pValue, *pValue }, in_rName);
    }

    inline void* const pCEditParamCreateParamUnsignedLong = (void*)0x591300;

    inline CParamValue<unsigned long>* fCEditParamCreateParamUnsignedLong(
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

    inline CParamValue<unsigned long>* CEditParam::CreateParamUnsignedLong(
        const SParamValueCreationParams<unsigned long>& in_rCreationParams,
        const Hedgehog::Base::CSharedString& in_rName)
    {
        return fCEditParamCreateParamUnsignedLong(&in_rCreationParams, this, &in_rName);
    }

    inline CParamValue<unsigned long>* CEditParam::CreateParamUnsignedLong(unsigned long* pValue,
        const Hedgehog::Base::CSharedString& in_rName)
    {
        return CreateParamUnsignedLong({ pValue, *pValue }, in_rName);
    }

    inline void* const pCEditParamCreateParamLong = (void*)0x590FB0;

    inline CParamValue<long>* fCEditParamCreateParamLong(
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

    inline CParamValue<long>* CEditParam::CreateParamLong(const SParamValueCreationParams<long>& in_rCreationParams,
        const Hedgehog::Base::CSharedString& in_rName)
    {
        return fCEditParamCreateParamLong(&in_rCreationParams, this, &in_rName);
    }

    inline CParamValue<long>* CEditParam::CreateParamLong(long* pValue, const Hedgehog::Base::CSharedString& in_rName)
    {
        return CreateParamLong({ pValue, *pValue }, in_rName);
    }

    inline void* const pCEditParamCreateParamInt = (void*)0x590DA0;

    inline CParamValue<int>* fCEditParamCreateParamInt(
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

    inline CParamValue<int>* CEditParam::CreateParamInt(const SParamValueCreationParams<int>& in_rCreationParams,
        const Hedgehog::Base::CSharedString& in_rName)
    {
        return fCEditParamCreateParamInt(&in_rCreationParams, this, &in_rName);
    }

    inline CParamValue<int>* CEditParam::CreateParamInt(int* pValue, const Hedgehog::Base::CSharedString& in_rName)
    {
        return CreateParamInt({ pValue, *pValue }, in_rName);
    }

    inline void* const pCEditParamCreateParamFloat = (void*)0x590770;

    inline CParamValue<float>* fCEditParamCreateParamFloat(
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

    inline CParamValue<float>* CEditParam::CreateParamFloat(const SParamValueCreationParams<float>& in_rCreationParams,
        const Hedgehog::Base::CSharedString& in_rName)
    {
        return fCEditParamCreateParamFloat(&in_rCreationParams, this, &in_rName);
    }

    inline CParamValue<float>* CEditParam::CreateParamFloat(float* pValue,
        const Hedgehog::Base::CSharedString& in_rName)
    {
        return CreateParamFloat({ pValue, *pValue }, in_rName);
    }

    inline void* const pCEditParamAddParamTypeList = (void*)0xCEF700;

    inline void fCEditParamAddParamTypeList(const Hedgehog::Base::CSharedString* in_pName, CEditParam* in_pEditParam, CParamTypeList* in_pParamTypeList)
    {
        __asm
        {
            mov eax, in_pName
            mov ecx, in_pEditParam
            push in_pParamTypeList
            call[pCEditParamAddParamTypeList]
        }
    }

    template <typename T>
    CParamTypeList* CEditParam::CreateParamTypeList(uint32_t* pValue, const Hedgehog::Base::CSharedString& in_rName,
        const Hedgehog::Base::CSharedString& in_rDescription, const T& in_rValues)
    {
        CParamTypeList* pParamTypeList = CParamTypeList::Create(pValue, in_rDescription);

        for (auto& value : in_rValues)
            pParamTypeList->AddValue(value.pName, value.Value);

        pParamTypeList->AddRef();
        fCEditParamAddParamTypeList(&in_rName, this, pParamTypeList);

        return pParamTypeList;
    }

    inline CParamTypeList* CEditParam::CreateParamTypeList(uint32_t* pValue,
        const Hedgehog::Base::CSharedString& in_rName, const Hedgehog::Base::CSharedString& in_rDescription,
        const std::initializer_list<SParamEnumValue>& in_rValues)
    {
        return CreateParamTypeList<std::initializer_list<SParamEnumValue>>(pValue, in_rName, in_rDescription, in_rValues);
    }

    inline CParamTypeList* CEditParam::CreateParamTypeList(uint32_t* pValue,
        const Hedgehog::Base::CSharedString& in_rName, const Hedgehog::Base::CSharedString& in_rDescription,
        const std::vector<SParamEnumValue>& in_rValues)
    {
        return CreateParamTypeList<std::vector<SParamEnumValue>>(pValue, in_rName, in_rDescription, in_rValues);
    }

    inline void* pCEditParamAddParamBase = (void*)0xCEF700;
    inline void fCEditParamAddParamBase(CEditParam* in_pEditParam, Sonic::CParamBase* param, const Hedgehog::Base::CSharedString& name)
    {
        __asm
        {
            mov eax, name
            mov ecx, in_pEditParam
            push param
            call[pCEditParamAddParamBase]
        }
    }

    inline void CEditParam::CreateParamBase(CParamBase* param, const Hedgehog::Base::CSharedString& name)
    {
        fCEditParamAddParamBase(this, param, name);
    }

}