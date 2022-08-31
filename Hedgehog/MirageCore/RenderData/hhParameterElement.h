#pragma once

#include <Hedgehog/Base/System/hhSymbol.h>

namespace Hedgehog::Mirage
{
    template<typename T>
    class TParameterElement
    {
    public:
        Base::CStringSymbol m_Name;
        size_t m_ValueNum;
        boost::shared_ptr<T[]> m_spValue;
    };

    class CParameterFloat4Element : public TParameterElement<float> {};
    class CParameterInt4Element : public TParameterElement<int> {};
    class CParameterBoolElement : public TParameterElement<bool> {};
}