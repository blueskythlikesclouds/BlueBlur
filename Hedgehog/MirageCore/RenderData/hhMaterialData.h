#pragma once

#include <Hedgehog/Base/Container/hhVector.h>
#include <Hedgehog/Database/System/hhDatabaseData.h>

namespace Hedgehog::Mirage
{
    class CTexsetData;
    class CShaderListData;

    class CParameterFloat4Element;
    class CParameterInt4Element;
    class CParameterBoolElement;

    class CMaterialData : public Database::CDatabaseData
    {
    public:
        boost::shared_ptr<CTexsetData> m_spTexsetData;
        BB_INSERT_PADDING(0xC);
        boost::shared_ptr<CShaderListData> m_spShaderListData;
        hh::vector<boost::shared_ptr<CParameterFloat4Element>> m_Float4Params;
        hh::vector<boost::shared_ptr<CParameterInt4Element>> m_Int4Params;
        hh::vector<boost::shared_ptr<CParameterBoolElement>> m_Bool4Params;
        BB_INSERT_PADDING(0x8);
    };

    BB_ASSERT_OFFSETOF(CMaterialData, m_spTexsetData, 0xC);
    BB_ASSERT_OFFSETOF(CMaterialData, m_spShaderListData, 0x20);
    BB_ASSERT_OFFSETOF(CMaterialData, m_Float4Params, 0x28);
    BB_ASSERT_OFFSETOF(CMaterialData, m_Int4Params, 0x38);
    BB_ASSERT_OFFSETOF(CMaterialData, m_Bool4Params, 0x48);
    BB_ASSERT_SIZEOF(CMaterialData, 0x60);
}