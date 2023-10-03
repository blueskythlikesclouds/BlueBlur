#pragma once

#include <BlueBlur.inl>

namespace Hedgehog::Base
{
    struct SSymbolNode
    {
        SSymbolNode* pPrev;
        SSymbolNode* pNext;
        size_t Hash;

        const char* GetValue() const
        {
            return reinterpret_cast<const char*>(this) + sizeof(SSymbolNode);
        }
    };

    static inline BB_FUNCTION_PTR(SSymbolNode*, __cdecl, MakeStringSymbol, 0x6643D0, const char* in_pName);

    class CStringSymbol
    {
    public:
        SSymbolNode* m_pSymbolNode;

        CStringSymbol() : m_pSymbolNode(MakeStringSymbol(""))
        {
        }

        CStringSymbol(const char* in_pName) : m_pSymbolNode(MakeStringSymbol(in_pName))
        {
        }

        const char* GetValue() const
        {
            return m_pSymbolNode->GetValue();
        }

        bool operator==(const CStringSymbol& in_rOther) const
        {
            return m_pSymbolNode == in_rOther.m_pSymbolNode;
        }

        bool operator<(const CStringSymbol& in_rOther) const
        {
            return m_pSymbolNode < in_rOther.m_pSymbolNode;
        }
    };

    BB_ASSERT_OFFSETOF(CStringSymbol, m_pSymbolNode, 0);
    BB_ASSERT_SIZEOF(CStringSymbol, 4);
}