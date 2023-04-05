#pragma once

#include <Hedgehog/Base/Type/hhSharedString.h>
#include <Sonic/Tool/ParameterEditor/AbstractParameterNode.h>

namespace Sonic
{
    class CParameterGroup;

    static void* const pCParameterGroupCreateParameterCategory = (void*)0xCE90B0;

    static CEditParam* fCParameterGroupCreateParameterCategory(
        const Hedgehog::Base::CSharedString* in_pName, CParameterGroup* in_pParameterGroup, const Hedgehog::Base::CSharedString* in_pDescription, uint32_t in_Unknown)
    {
        __asm
        {
            mov eax, in_pName
            mov ecx, in_pParameterGroup
            push in_Unknown
            push in_pDescription
            call [pCParameterGroupCreateParameterCategory]
        }
    }

    static inline BB_FUNCTION_PTR(void, __stdcall, fpCParameterGroupFlush, 0xCE8EF0, CParameterGroup* in_pParameterGroup);

    class CParameterGroup : public CAbstractParameterNode
    {
    public:
        static constexpr void* ms_pVfTable = (void*)0x16E5FA4;

        CEditParam* CreateParameterCategory(
            const Hedgehog::Base::CSharedString& in_rName, const Hedgehog::Base::CSharedString& in_rDescription)
        {
            return fCParameterGroupCreateParameterCategory(&in_rName, this, &in_rDescription, 0xFF);
        }

        void Flush()
        {
            fpCParameterGroupFlush(this);
        }
    };

    BB_ASSERT_SIZEOF(CParameterGroup, 0x3C);
}