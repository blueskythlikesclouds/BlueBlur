namespace Sonic
{
    inline void* const pCParameterGroupCreateParameterCategory = (void*)0xCE90B0;

    inline CEditParam* fCParameterGroupCreateParameterCategory(
        const Hedgehog::Base::CSharedString* in_pName, CParameterGroup* in_pParameterGroup, const Hedgehog::Base::CSharedString* in_pDescription, uint32_t in_Unknown)
    {
        __asm
        {
            mov eax, in_pName
            mov ecx, in_pParameterGroup
            push in_Unknown
            push in_pDescription
            call[pCParameterGroupCreateParameterCategory]
        }
    }

    inline CEditParam* CParameterGroup::CreateParameterCategory(const Hedgehog::Base::CSharedString& in_rName,
        const Hedgehog::Base::CSharedString& in_rDescription)
    {
        return fCParameterGroupCreateParameterCategory(&in_rName, this, &in_rDescription, 0xFF);
    }

    inline BB_FUNCTION_PTR(void, __stdcall, fpCParameterGroupFlush, 0xCE8EF0, CParameterGroup* in_pParameterGroup);

    inline void CParameterGroup::Flush()
    {
        fpCParameterGroupFlush(this);
    }
}