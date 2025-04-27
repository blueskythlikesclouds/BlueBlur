#pragma once

#include <Hedgehog/Base/Container/hhMap.h>
#include <Hedgehog/Base/System/hhAllocator.h>
#include <Sonic/Tool/EditParam/ParamBase.h>

namespace Sonic
{
    class CParamTypeList : public CParamBase
    {
    public:
        class CMember
        {
        public:
            class FuncData : public Hedgehog::Base::CRefCountObject
            {
            public:
                hh::map<uint32_t, Hedgehog::Base::CSharedString> m_ValueMap;
                boost::function1<void, uint32_t> m_ChangedCallbackA;
                boost::function<void()> m_ChangedCallbackB;
                uint32_t* m_pValue;
                uint32_t m_Value;
                Hedgehog::Base::CSharedString m_Description;
                BB_INSERT_PADDING(0x4);
                uint32_t m_ValueMax;
                BB_INSERT_PADDING(0x4);
            };

            FuncData* m_pFuncData;
            uint32_t m_Value;

            uint32_t m_DefaultValue;
            Hedgehog::Base::CSharedString m_DefaultValueName;
        };

        CMember* m_pMember;

        void AddValue(const Hedgehog::Base::CSharedString& in_rName, uint32_t in_Value);

        static CParamTypeList* Create(uint32_t* in_pValue, const Hedgehog::Base::CSharedString& in_rDescription);
    };

    BB_ASSERT_OFFSETOF(CParamTypeList::CMember::FuncData, m_ValueMap, 0x8);
    BB_ASSERT_OFFSETOF(CParamTypeList::CMember::FuncData, m_ChangedCallbackA, 0x18);
    BB_ASSERT_OFFSETOF(CParamTypeList::CMember::FuncData, m_ChangedCallbackB, 0x38);
    BB_ASSERT_OFFSETOF(CParamTypeList::CMember::FuncData, m_pValue, 0x58);
    BB_ASSERT_OFFSETOF(CParamTypeList::CMember::FuncData, m_Value, 0x5C);
    BB_ASSERT_OFFSETOF(CParamTypeList::CMember::FuncData, m_Description, 0x60);
    BB_ASSERT_OFFSETOF(CParamTypeList::CMember::FuncData, m_ValueMax, 0x68);
    BB_ASSERT_SIZEOF(CParamTypeList::CMember::FuncData, 0x70);

    BB_ASSERT_OFFSETOF(CParamTypeList::CMember, m_pFuncData, 0x0);
    BB_ASSERT_OFFSETOF(CParamTypeList::CMember, m_Value, 0x4);
    BB_ASSERT_OFFSETOF(CParamTypeList::CMember, m_DefaultValue, 0x8);
    BB_ASSERT_OFFSETOF(CParamTypeList::CMember, m_DefaultValueName, 0xC);
    BB_ASSERT_SIZEOF(CParamTypeList::CMember, 0x10);

    BB_ASSERT_OFFSETOF(CParamTypeList, m_pMember, 0x14);
    BB_ASSERT_SIZEOF(CParamTypeList, 0x18);
}


#include <Sonic/Tool/EditParam/ParamTypeList.inl>