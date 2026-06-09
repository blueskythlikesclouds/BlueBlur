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
    };
}