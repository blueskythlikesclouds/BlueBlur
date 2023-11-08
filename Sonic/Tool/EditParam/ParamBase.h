#pragma once

#include <Hedgehog/Base/hhRefCountObject.h>
#include <Hedgehog/Base/Type/hhSharedString.h>

namespace Sonic
{
    class CXMLTypeSLTxt;

    class CParamBase : public Hedgehog::Base::CRefCountObject
    {
    public:
        uint8_t m_Field8;
        Hedgehog::Base::CSharedString m_Name;
        uint8_t m_Field10;

        virtual void CParamBase04(int a1) {}
        virtual int  CParamBase08(int a1) { return 1; }
        virtual void CParamBase0C(int a1) {}
        virtual int  CParamBase10() { return 1; }
        virtual int  CParamBase14() { return 1; }
        virtual void WriteParametersToXML_NoTarget(CXMLTypeSLTxt* in_XmlText) {}
        virtual void WriteParametersToXML(CXMLTypeSLTxt* in_XmlText) {}
    };

    BB_ASSERT_OFFSETOF(CParamBase, m_Field8, 0x8);
    BB_ASSERT_OFFSETOF(CParamBase, m_Name, 0xC);
    BB_ASSERT_OFFSETOF(CParamBase, m_Field10, 0x10);
    BB_ASSERT_SIZEOF(CParamBase, 0x14);
}
