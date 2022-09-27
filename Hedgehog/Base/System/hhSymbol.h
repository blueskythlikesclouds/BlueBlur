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

    static inline BB_FUNCTION_PTR(SSymbolNode*, __cdecl, MakeStringSymbol, 0x6643D0, const char* pName);

    class CStringSymbol
    {
    public:
        SSymbolNode* m_pSymbolNode;

        CStringSymbol() : m_pSymbolNode(MakeStringSymbol(""))
        {
        }

        CStringSymbol(const char* pName) : m_pSymbolNode(MakeStringSymbol(pName))
        {
        }

        const char* GetValue() const
        {
            return m_pSymbolNode->GetValue();
        }

        bool operator<(const CStringSymbol& other) const
        {
            return m_pSymbolNode < other.m_pSymbolNode;
        }
    };

    BB_ASSERT_OFFSETOF(CStringSymbol, m_pSymbolNode, 0);
    BB_ASSERT_SIZEOF(CStringSymbol, 4);
}