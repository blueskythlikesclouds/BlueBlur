namespace Hedgehog::Base
{
    inline const char* SSymbolNode::GetValue() const
    {
        return reinterpret_cast<const char*>(this) + sizeof(SSymbolNode);
    }

    inline BB_FUNCTION_PTR(SSymbolNode*, __cdecl, MakeStringSymbol, 0x6643D0, const char* in_pName);

    inline CStringSymbol::CStringSymbol(): m_pSymbolNode(MakeStringSymbol(""))
    {
    }

    inline CStringSymbol::CStringSymbol(const char* in_pName): m_pSymbolNode(MakeStringSymbol(in_pName))
    {
    }

    inline const char* CStringSymbol::GetValue() const
    {
        return m_pSymbolNode->GetValue();
    }

    inline bool CStringSymbol::operator==(const CStringSymbol& in_rOther) const
    {
        return m_pSymbolNode == in_rOther.m_pSymbolNode;
    }

    inline bool CStringSymbol::operator<(const CStringSymbol& in_rOther) const
    {
        return m_pSymbolNode < in_rOther.m_pSymbolNode;
    }
}
