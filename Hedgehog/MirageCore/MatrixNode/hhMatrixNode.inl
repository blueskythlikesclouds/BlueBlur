namespace Hedgehog::Mirage
{
    inline BB_FUNCTION_PTR(void, __thiscall, fpCMatrixNodeCtor, 0x6F4530, CMatrixNode* This);

    inline CMatrixNode::CMatrixNode()
    {
        fpCMatrixNodeCtor(this);
    }

    inline BB_FUNCTION_PTR(void, __thiscall, fpCMatrixNodeNotifyChanged, 0x6F3CB0, CMatrixNode* This);

    inline void CMatrixNode::NotifyChanged()
    {
        fpCMatrixNodeNotifyChanged(this);
    }

    inline BB_FUNCTION_PTR(void, __thiscall, fpCMatrixNodeSetChild, 0x6F46B0,
        Hedgehog::Mirage::CMatrixNode* This, Hedgehog::Mirage::CMatrixNode* in_pChildMatrixNode);

    inline void CMatrixNode::SetParent(CMatrixNode* in_pParentNode)
    {
        fpCMatrixNodeSetChild(in_pParentNode, this);
    }

    inline void CMatrixNode::SetChild(CMatrixNode* in_pChildNode)
    {
        fpCMatrixNodeSetChild(this, in_pChildNode);
    }

    static inline BB_FUNCTION_PTR(void, __thiscall, fpCMatrixNodeAddListener, 0x6F4310,
        Hedgehog::Mirage::CMatrixNode* This, Hedgehog::Mirage::CMatrixNodeListener* in_pListener);

    inline void CMatrixNode::AddListener(CMatrixNodeListener* in_pListener)
    {
        fpCMatrixNodeAddListener(this, in_pListener);
    }
}