namespace Sonic
{
    inline void* const pCParamTypeListAddValue = (void*)0xCEBD70;

    inline void fCParamTypeListAddValue(CParamTypeList* in_pParamTypeList, const Hedgehog::Base::CSharedString* in_pName, uint32_t in_Value)
    {
        __asm
        {
            mov eax, in_pName
            mov edi, in_pParamTypeList
            mov esi, in_Value
            call[pCParamTypeListAddValue]
        }
    }

    inline void CParamTypeList::AddValue(const Hedgehog::Base::CSharedString& in_rName, uint32_t in_Value)
    {
        fCParamTypeListAddValue(this, &in_rName, in_Value);
    }

    inline void* const pCParamTypeListConstructor = (void*)0xCEBF90;

    inline CParamTypeList* fCParamTypeListConstructor(
        CParamTypeList* in_pParamTypeList, const Hedgehog::Base::CSharedString* in_pDescription, uint32_t* in_pValue, uint32_t in_Unknown)
    {
        __asm
        {
            mov esi, in_pParamTypeList
            push in_Unknown
            push in_pValue
            push in_pDescription
            call[pCParamTypeListConstructor]
        }
    }

    inline CParamTypeList* CParamTypeList::Create(uint32_t* in_pValue,
        const Hedgehog::Base::CSharedString& in_rDescription)
    {
        CParamTypeList* pParamTypeList = (CParamTypeList*)__HH_ALLOC(sizeof(CParamTypeList));
        fCParamTypeListConstructor(pParamTypeList, &in_rDescription, in_pValue, 0);

        pParamTypeList->AddRef();
        return pParamTypeList;
    }
}