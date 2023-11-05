#pragma once

#include <Hedgehog/Base/Container/hhMap.h>
#include <Hedgehog/Base/Type/hhSharedString.h>
#include <Hedgehog/MirageCore/Renderable/hhElement.h>

namespace Hedgehog::Motion
{
    class CSingleElementEffectMotionAll;
}

namespace Hedgehog::Mirage
{
    class CInstanceInfo;
    class CSingleElement;
    class CSingleMorphElement;
    class CMaterialData;
    class CModelData;
    class CMatrixNode;
    class CMatrixNodeSingleElementNode;

    static inline BB_FUNCTION_PTR(CSingleElement*, __thiscall, fpCSingleElementCtor, 0x701D00,
        CSingleElement* This, const boost::shared_ptr<CModelData>& spModelData);

    static inline BB_FUNCTION_PTR(CSingleMorphElement*, __thiscall, fpCSingleMorphElementCtor, 0x007040B0,
        CSingleMorphElement* This, const boost::shared_ptr<CModelData>& _spModelData);

    static inline BB_FUNCTION_PTR(void, __thiscall, fpCSingleElementGetNode, 0x700B70,
        const CSingleElement* This, boost::shared_ptr<CMatrixNodeSingleElementNode>& out_spNode, const Hedgehog::Base::CSharedString& in_rName);

    static inline BB_FUNCTION_PTR(void, __thiscall, fpCSingleElementBindMatrixNode, 0x700C00,
        const CSingleElement* This, boost::shared_ptr<CMatrixNode> in_spMatrixNode);

    static inline BB_FUNCTION_PTR(void, __thiscall, fBindAnimationPose, 0x700A50,
        const CSingleElement* This, boost::shared_ptr<Hedgehog::Animation::CAnimationPose>& pose);

    static inline BB_FUNCTION_PTR(void, __thiscall, fBindEffectMotion, 0x700C70,
        const CSingleElement* This, boost::shared_ptr<Hedgehog::Motion::CSingleElementEffectMotionAll>& motion);

    class CSingleElement : public CElement
    {
    public:
        boost::shared_ptr<CInstanceInfo> m_spInstanceInfo;
        hh::map<CMaterialData*, boost::shared_ptr<CMaterialData>> m_MaterialMap;
        BB_INSERT_PADDING(0x8);

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

        void BindAnimationPose(boost::shared_ptr<Hedgehog::Animation::CAnimationPose>& pose)
        {
            fBindAnimationPose(this, pose);
        }

        void BindEffectMotion(boost::shared_ptr<Hedgehog::Motion::CSingleElementEffectMotionAll>& motion)
        {
            fBindEffectMotion(this, motion);
        }

        void BindMatrixNode(const boost::shared_ptr<CMatrixNode>& in_spMatrixNode)
        {
            fpCSingleElementBindMatrixNode(this, in_spMatrixNode);
        }
    };

    BB_ASSERT_OFFSETOF(CSingleElement, m_spInstanceInfo, 0x8C);
    BB_ASSERT_OFFSETOF(CSingleElement, m_MaterialMap, 0x94);
    BB_ASSERT_SIZEOF(CSingleElement, 0xA8);

    class CSingleMorphElement : public CSingleElement
    {
    public:
        CSingleMorphElement(const bb_null_ctor& nil) : CSingleElement(nil) {}

        CSingleMorphElement(const boost::shared_ptr<CModelData>& spModelData) : CSingleMorphElement(bb_null_ctor{})
        {
            fpCSingleMorphElementCtor(this, spModelData);
        }
    };
}