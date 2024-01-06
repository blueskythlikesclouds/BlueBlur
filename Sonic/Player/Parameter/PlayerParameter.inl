namespace Sonic::Player
{
    inline bool CParameter::Get(const int32_t in_Index, const boost::any** out_pValue,
        int32_t* out_ValueScaleIndex) const
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

    inline bool CParameter::Get(const int32_t in_Index, const boost::any** out_pValue, float& out_ValueScale) const
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

    template <typename T>
    T CParameter::Get(const int32_t in_Index) const
    {
        const boost::any* pValue;
        float valueScale;

        if (!Get(in_Index, &pValue, valueScale))
            return T();

        return (T)((float)boost::any_cast<T>(*pValue) * valueScale);
    }
}