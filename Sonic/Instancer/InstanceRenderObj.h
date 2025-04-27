#pragma once

#include <Sonic/Instancer/MetaInstancer.h>

namespace Sonic
{
    class CObjInstancer;
    class CInstanceModelData;

    class CInstanceRenderObj : public CMetaInstancer::CRenderable
    {
    public:
        CObjInstancer* m_pObjInstancer;
        boost::shared_ptr<CInstanceModelData> m_aInstanceModelData[4];
        D3DVERTEXELEMENT9 m_VertexElements[0x10];
        uint8_t m_FieldE4;
    };

    BB_ASSERT_OFFSETOF(CInstanceRenderObj, m_pObjInstancer, 0x40);
    BB_ASSERT_OFFSETOF(CInstanceRenderObj, m_aInstanceModelData, 0x44);
    BB_ASSERT_OFFSETOF(CInstanceRenderObj, m_VertexElements, 0x64);
    BB_ASSERT_OFFSETOF(CInstanceRenderObj, m_FieldE4, 0xE4);
    BB_ASSERT_SIZEOF(CInstanceRenderObj, 0xE8);
}