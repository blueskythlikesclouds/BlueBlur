#pragma once

#include <Hedgehog/Base/Container/hhVector.h>
#include <Hedgehog/Database/System/hhDatabaseData.h>

namespace Hedgehog::Mirage
{
    class CMaterialData;
    class CTexsetData;
    class CShaderListData;
    class CParameterFloat4Element;
    class CParameterInt4Element;
    class CParameterBoolElement;

    enum EMaterialFlags : uint8_t
    {
        eMaterialFlags_Float4ParamsEmpty = 0x1,
        eMaterialFlags_Int4ParamsEmpty = 0x2,
        eMaterialFlags_BoolParamsEmpty = 0x4
    };

    static BB_FUNCTION_PTR(CMaterialData*, __thiscall, fpCMaterialDataCtor, 0x704CA0, CMaterialData*);

    class CMaterialData : public Database::CDatabaseData
    {
    public:
        boost::shared_ptr<CTexsetData> m_spTexsetData;
        BB_INSERT_PADDING(0xC); // Padding
        boost::shared_ptr<CShaderListData> m_spShaderListData;
        hh::vector<boost::shared_ptr<CParameterFloat4Element>> m_Float4Params;
        hh::vector<boost::shared_ptr<CParameterInt4Element>> m_Int4Params;
        hh::vector<boost::shared_ptr<CParameterBoolElement>> m_Bool4Params;
        uint8_t m_AlphaThreshold;
        bool m_DoubleSided;
        bool m_Additive;
        uint8_t m_MaterialFlags; // see EMaterialFlags
        void* m_pField5C;

        CMaterialData()
        {
            fpCMaterialDataCtor(this);
        }
    };

    BB_ASSERT_OFFSETOF(CMaterialData, m_spTexsetData, 0xC);
    BB_ASSERT_OFFSETOF(CMaterialData, m_spShaderListData, 0x20);
    BB_ASSERT_OFFSETOF(CMaterialData, m_Float4Params, 0x28);
    BB_ASSERT_OFFSETOF(CMaterialData, m_Int4Params, 0x38);
    BB_ASSERT_OFFSETOF(CMaterialData, m_Bool4Params, 0x48);
    BB_ASSERT_OFFSETOF(CMaterialData, m_AlphaThreshold, 0x58);
    BB_ASSERT_OFFSETOF(CMaterialData, m_DoubleSided, 0x59);
    BB_ASSERT_OFFSETOF(CMaterialData, m_Additive, 0x5A);
    BB_ASSERT_OFFSETOF(CMaterialData, m_MaterialFlags, 0x5B);
    BB_ASSERT_OFFSETOF(CMaterialData, m_pField5C, 0x5C);
    BB_ASSERT_SIZEOF(CMaterialData, 0x60);
}