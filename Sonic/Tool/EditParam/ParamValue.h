#pragma once

#include <Sonic/Tool/EditParam/ParamBase.h>

namespace Sonic
{
    template<typename T>
    class CParamValue : public CParamBase
    {
    public:
        class FuncData : public Hedgehog::Base::CRefCountObject
        {
        public:
            T* m_pValue;
            T m_Value;
            boost::function1<void, T> m_ChangedCallback;
            uint32_t m_Field30;
        };

        FuncData* m_pFuncData;
        T m_DefaultValue;

        BB_ASSERT_OFFSETOF(FuncData, m_pValue, 0x8);
        BB_ASSERT_OFFSETOF(FuncData, m_Value, 0xC);
        BB_ASSERT_OFFSETOF(FuncData, m_ChangedCallback, 0x10);
        BB_ASSERT_OFFSETOF(FuncData, m_Field30, 0x30);
        BB_ASSERT_SIZEOF(FuncData, 0x38);

        BB_ASSERT_OFFSETOF(CParamValue, m_pFuncData, 0x14);
        BB_ASSERT_OFFSETOF(CParamValue, m_DefaultValue, 0x18);
        BB_ASSERT_SIZEOF(CParamValue, 0x1C);
    };
}
