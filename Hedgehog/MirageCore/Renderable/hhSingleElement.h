#pragma once

#include <Hedgehog/Base/Container/hhMap.h>
#include <Hedgehog/Base/Type/hhSharedString.h>
#include <Hedgehog/MirageCore/Renderable/hhElement.h>

namespace Hedgehog::Mirage
{
    class CInstanceInfo;
    class CSingleElement;
    class CSingleElementEffect;
    class CMaterialData;
    class CModelData;
    class CMatrixNode;
    class CMatrixNodeSingleElementNode;

    static inline BB_FUNCTION_PTR(CSingleElement*, __thiscall, fpCSingleElementCtor, 0x701D00,
        CSingleElement* This, const boost::shared_ptr<CModelData>& spModelData);

    static inline BB_FUNCTION_PTR(void, __thiscall, fpCSingleElementGetNode, 0x700B70,
        const CSingleElement* This, boost::shared_ptr<CMatrixNodeSingleElementNode>& out_spNode, const Hedgehog::Base::CSharedString& in_rName);

    static inline BB_FUNCTION_PTR(void, __thiscall, fpCSingleElementBindMatrixNode, 0x700C00,
        CSingleElement* This, const boost::shared_ptr<CMatrixNode> in_spMatrixNode);

    static inline BB_FUNCTION_PTR(void, __thiscall, fpCSingleElementBindPose, 0x700A50,
        CSingleElement* This, const boost::shared_ptr<CPose>& in_spPose);

    static inline BB_FUNCTION_PTR(void, __thiscall, fpCSingleElementBindEffect, 0x700C70,
        CSingleElement* This, const boost::shared_ptr<CSingleElementEffect>& in_spEffect);

    class CSingleElement : public CElement
    {
    public:
        boost::shared_ptr<CInstanceInfo> m_spInstanceInfo;
        hh::map<CMaterialData*, boost::shared_ptr<CMaterialData>> m_MaterialMap;
        boost::shared_ptr<CSingleElementEffect> m_spSingleElementEffect;

        CSingleElement(const bb_null_ctor& nil) : CElement(nil) {}

        CSingleElement(const boost::shared_ptr<CModelData>& spModelData) : CSingleElement(bb_null_ctor{})
        {
            fpCSingleElementCtor(this, spModelData);
        }

        boost::shared_ptr<CMatrixNodeSingleElementNode> GetNode(const Hedgehog::Base::CSharedString& in_rName) const
        {
            boost::shared_ptr<CMatrixNodeSingleElementNode> spNode;
            fpCSingleElementGetNode(this, spNode, in_rName);
            return spNode;
        }

        void BindPose(const boost::shared_ptr<CPose>& in_spPose)
        {
            fpCSingleElementBindPose(this, in_spPose);
        }

        void BindEffect(const boost::shared_ptr<CSingleElementEffect>& in_spEffect)
        {
            fpCSingleElementBindEffect(this, in_spEffect);
        }

        void BindMatrixNode(const boost::shared_ptr<CMatrixNode>& in_spMatrixNode)
        {
            fpCSingleElementBindMatrixNode(this, in_spMatrixNode);
        }
    };

    BB_ASSERT_OFFSETOF(CSingleElement, m_spInstanceInfo, 0x8C);
    BB_ASSERT_OFFSETOF(CSingleElement, m_MaterialMap, 0x94);
    BB_ASSERT_OFFSETOF(CSingleElement, m_spSingleElementEffect, 0xA0);
    BB_ASSERT_SIZEOF(CSingleElement, 0xA8);
}