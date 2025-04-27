#pragma once

#include <Hedgehog/Base/Container/hhMap.h>
#include <Hedgehog/Base/Type/hhSharedString.h>

namespace Sonic::Player
{
    class CParameter
    {
    public:
        class CNode
        {
        public:
            hh::map<int32_t, boost::any> m_ValueMap;
            hh::map<int32_t, int32_t> m_ValueScaleMap;
            boost::shared_ptr<CParameter> m_spParent;
        };

        boost::scoped_ptr<CNode> m_scpNode;
        Hedgehog::Base::CSharedString m_Name;

        bool Get(const int32_t in_Index, const boost::any** out_pValue, int32_t* out_ValueScaleIndex) const;
        bool Get(const int32_t in_Index, const boost::any** out_pValue, float& out_ValueScale) const;

        template<typename T>
        T Get(const int32_t in_Index) const;
    };

    BB_ASSERT_OFFSETOF(CParameter::CNode, m_ValueMap, 0x0);
    BB_ASSERT_OFFSETOF(CParameter::CNode, m_ValueScaleMap, 0xC);
    BB_ASSERT_OFFSETOF(CParameter::CNode, m_spParent, 0x18);
    BB_ASSERT_SIZEOF(CParameter::CNode, 0x20);

    BB_ASSERT_OFFSETOF(CParameter, m_scpNode, 0x0);
    BB_ASSERT_OFFSETOF(CParameter, m_Name, 0x4);
    BB_ASSERT_SIZEOF(CParameter, 0x8);
}

#include <Sonic/Player/Parameter/PlayerParameter.inl>