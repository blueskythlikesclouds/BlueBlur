namespace Hedgehog::Mirage
{
    inline BB_FUNCTION_PTR(CSingleElement*, __thiscall, fpCSingleElementCtor, 0x701D00,
        CSingleElement* This, const boost::shared_ptr<CModelData>& spModelData);

    inline CSingleElement::CSingleElement(const boost::shared_ptr<CModelData>& spModelData) : CSingleElement(bb_null_ctor{})
    {
        fpCSingleElementCtor(this, spModelData);
    }

    inline BB_FUNCTION_PTR(void, __thiscall, fpCSingleElementGetNode, 0x700B70,
        const CSingleElement* This, boost::shared_ptr<CMatrixNodeSingleElementNode>& out_spNode, const Hedgehog::Base::CSharedString& in_rName);

    inline boost::shared_ptr<CMatrixNodeSingleElementNode> CSingleElement::GetNode(
        const Hedgehog::Base::CSharedString& in_rName) const
    {
        boost::shared_ptr<CMatrixNodeSingleElementNode> spNode;
        fpCSingleElementGetNode(this, spNode, in_rName);
        return spNode;
    }

    inline BB_FUNCTION_PTR(void, __thiscall, fpCSingleElementBindPose, 0x700A50,
        CSingleElement* This, const boost::shared_ptr<CPose>& in_spPose);

    inline void CSingleElement::BindPose(const boost::shared_ptr<CPose>& in_spPose)
    {
        fpCSingleElementBindPose(this, in_spPose);
    }

    inline BB_FUNCTION_PTR(void, __thiscall, fpCSingleElementBindEffect, 0x700C70,
        CSingleElement* This, const boost::shared_ptr<CSingleElementEffect>& in_spEffect);

    inline void CSingleElement::BindEffect(const boost::shared_ptr<CSingleElementEffect>& in_spEffect)
    {
        fpCSingleElementBindEffect(this, in_spEffect);
    }

    inline BB_FUNCTION_PTR(void, __thiscall, fpCSingleElementBindMatrixNode, 0x700C00,
        CSingleElement* This, const boost::shared_ptr<CMatrixNode> in_spMatrixNode);

    inline void CSingleElement::BindMatrixNode(const boost::shared_ptr<CMatrixNode>& in_spMatrixNode)
    {
        fpCSingleElementBindMatrixNode(this, in_spMatrixNode);
    }
}