#pragma once
#include <Hedgehog/Base/hhObject.h>
#include <Hedgehog/Base/Type/hhSharedString.h>

namespace Hedgehog::Mirage
{
    class CModelNodeData : public Hedgehog::Base::CObject
    {
    public:
        uint32_t m_ParentIndex;
        Base::CSharedString m_Name;
        BB_INSERT_PADDING(0x4);
    };

    BB_ASSERT_OFFSETOF(CModelNodeData, m_ParentIndex, 0x0);
    BB_ASSERT_OFFSETOF(CModelNodeData, m_Name, 0x4);
    BB_ASSERT_SIZEOF(CModelNodeData, 0xC);
}
