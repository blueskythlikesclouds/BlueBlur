#pragma once

#include <BlueBlur.inl>

namespace Hedgehog::Base
{
    struct SSymbolNode
    {
        SSymbolNode* pPrev;
        SSymbolNode* pNext;
        size_t Hash;

        const char* GetValue() const;
    };

    class CStringSymbol
    {
    public:
        SSymbolNode* m_pSymbolNode;

        CStringSymbol();
        CStringSymbol(const char* in_pName);

        const char* GetValue() const;

        bool operator==(const CStringSymbol& in_rOther) const;
        bool operator<(const CStringSymbol& in_rOther) const;
    };

    BB_ASSERT_OFFSETOF(CStringSymbol, m_pSymbolNode, 0);
    BB_ASSERT_SIZEOF(CStringSymbol, 4);
}

#include <Hedgehog/Base/System/hhSymbol.inl>