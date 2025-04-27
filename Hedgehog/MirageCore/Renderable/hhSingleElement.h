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

    class CSingleElement : public CElement
    {
    public:
        boost::shared_ptr<CInstanceInfo> m_spInstanceInfo;
        hh::map<CMaterialData*, boost::shared_ptr<CMaterialData>> m_MaterialMap;
        boost::shared_ptr<CSingleElementEffect> m_spSingleElementEffect;

        CSingleElement(const bb_null_ctor& nil) : CElement(nil) {}
        CSingleElement(const boost::shared_ptr<CModelData>& spModelData);

        boost::shared_ptr<CMatrixNodeSingleElementNode> GetNode(const Hedgehog::Base::CSharedString& in_rName) const;

        void BindPose(const boost::shared_ptr<CPose>& in_spPose);
        void BindEffect(const boost::shared_ptr<CSingleElementEffect>& in_spEffect);
        void BindMatrixNode(const boost::shared_ptr<CMatrixNode>& in_spMatrixNode);
    };

    BB_ASSERT_OFFSETOF(CSingleElement, m_spInstanceInfo, 0x8C);
    BB_ASSERT_OFFSETOF(CSingleElement, m_MaterialMap, 0x94);
    BB_ASSERT_OFFSETOF(CSingleElement, m_spSingleElementEffect, 0xA0);
    BB_ASSERT_SIZEOF(CSingleElement, 0xA8);
}

#include <Hedgehog/MirageCore/Renderable/hhSingleElement.inl>