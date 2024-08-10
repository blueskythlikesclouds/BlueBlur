#pragma once

#include <Sonic/Instancer/ObjInstancer.h>

namespace Sonic
{
    class CObjGrassInstancer : public CObjInstancer, public CMetaInstancer::CSceneGraph::CVisitor
    {
    public:
        float* m_scpInstanceTypes;
        BB_INSERT_PADDING(0x14);
        float m_Misc;
        BB_INSERT_PADDING(0x38);
    };

    BB_ASSERT_OFFSETOF(CObjGrassInstancer, m_scpInstanceTypes, 0x10C);
    BB_ASSERT_OFFSETOF(CObjGrassInstancer, m_Misc, 0x124);
    BB_ASSERT_SIZEOF(CObjGrassInstancer, 0x160);
}