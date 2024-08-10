#pragma once

#include <Sonic/Tool/EditParam/ParamBase.h>

namespace Sonic
{
    class CParamBool : public CParamBase
    {
    public:
        class FuncData : public Hedgehog::Base::CRefCountObject
        {
        public:
            bool* m_pValue;
            bool m_Value;
            boost::function1<void, bool> m_ChangedCallback;
            Hedgehog::Base::CSharedString m_Description;
        };

        FuncData* m_pFuncData;
        bool m_DefaultValue;
    };

    BB_ASSERT_OFFSETOF(CParamBool::FuncData, m_pValue, 0x8);
    BB_ASSERT_OFFSETOF(CParamBool::FuncData, m_Value, 0xC);
    BB_ASSERT_OFFSETOF(CParamBool::FuncData, m_ChangedCallback, 0x10);
    BB_ASSERT_OFFSETOF(CParamBool::FuncData, m_Description, 0x30);
    BB_ASSERT_SIZEOF(CParamBool::FuncData, 0x38);

    BB_ASSERT_OFFSETOF(CParamBool, m_pFuncData, 0x14);
    BB_ASSERT_OFFSETOF(CParamBool, m_DefaultValue, 0x18);
    BB_ASSERT_SIZEOF(CParamBool, 0x1C);
}