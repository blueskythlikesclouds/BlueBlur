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
}