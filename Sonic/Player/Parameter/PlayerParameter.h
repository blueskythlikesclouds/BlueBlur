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

        bool Get(const int32_t in_Index, const boost::any** out_pValue, int32_t* out_ValueScaleIndex) const
        {
            const CParameter* pCurrentParam = this;

            do
            {
                const auto valuePair = pCurrentParam->m_scpNode->m_ValueMap.find(in_Index);

                if (valuePair == pCurrentParam->m_scpNode->m_ValueMap.end())
                {
                    pCurrentParam = pCurrentParam->m_scpNode->m_spParent.get();
                    continue;
                }

                if (out_pValue)
                    *out_pValue = &valuePair->second;

                if (out_ValueScaleIndex)
                {
                    const auto valueScalePair = pCurrentParam->m_scpNode->m_ValueScaleMap.find(in_Index);

                    if (valueScalePair != pCurrentParam->m_scpNode->m_ValueScaleMap.end())
                        *out_ValueScaleIndex = valueScalePair->second;

                    else
                        *out_ValueScaleIndex = -1;
                }

                return true;
            } while (pCurrentParam);

            return false;
        }

        bool Get(const int32_t in_Index, const boost::any** out_pValue, float& out_ValueScale) const
        {
            int32_t valueScaleIndex;
            const boost::any* pValueScale;

            if (!Get(in_Index, out_pValue, &valueScaleIndex))
                return false;

            if (valueScaleIndex != -1 && Get(valueScaleIndex, &pValueScale, nullptr))
                out_ValueScale = boost::any_cast<float>(*pValueScale);

            else
                out_ValueScale = 1.0f;

            return true;
        }

        template<typename T>
        T Get(const int32_t in_Index) const
        {
            const boost::any* pValue;
            float valueScale;

            if (!Get(in_Index, &pValue, valueScale))
                return T();

            return (T)((float)boost::any_cast<T>(*pValue) * valueScale);
        }
    };

    BB_ASSERT_OFFSETOF(CParameter::CNode, m_ValueMap, 0x0);
    BB_ASSERT_OFFSETOF(CParameter::CNode, m_ValueScaleMap, 0xC);
    BB_ASSERT_OFFSETOF(CParameter::CNode, m_spParent, 0x18);
    BB_ASSERT_SIZEOF(CParameter::CNode, 0x20);

    BB_ASSERT_OFFSETOF(CParameter, m_scpNode, 0x0);
    BB_ASSERT_OFFSETOF(CParameter, m_Name, 0x4);
    BB_ASSERT_SIZEOF(CParameter, 0x8);
}