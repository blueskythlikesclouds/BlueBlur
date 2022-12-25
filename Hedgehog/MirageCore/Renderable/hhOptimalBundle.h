#pragma once

#include <Hedgehog/Base/Container/hhList.h>
#include <Hedgehog/Base/Container/hhVector.h>
#include <Hedgehog/MirageCore/Renderable/hhRenderable.h>

namespace Hedgehog::Mirage
{
    class COptimalBundle : public CRenderable
    {
    public:
        hh::vector<void*> m_FieldC[6];
        hh::vector<void*> m_Field6C[6];
        hh::list<boost::anonymous_shared_ptr> m_FieldCC;
        hh::list<boost::anonymous_shared_ptr> m_FieldD8;
        hh::vector<CRenderable*> m_RenderableList;
        hh::list<boost::anonymous_shared_ptr> m_FieldF4;
        hh::list<std::pair<boost::anonymous_shared_ptr, boost::anonymous_shared_ptr>> m_Field100;
    };

    BB_ASSERT_OFFSETOF(COptimalBundle, m_FieldC, 0xC);
    BB_ASSERT_OFFSETOF(COptimalBundle, m_Field6C, 0x6C);
    BB_ASSERT_OFFSETOF(COptimalBundle, m_FieldCC, 0xCC);
    BB_ASSERT_OFFSETOF(COptimalBundle, m_FieldD8, 0xD8);
    BB_ASSERT_OFFSETOF(COptimalBundle, m_RenderableList, 0xE4);
    BB_ASSERT_OFFSETOF(COptimalBundle, m_FieldF4, 0xF4);
    BB_ASSERT_OFFSETOF(COptimalBundle, m_Field100, 0x100);
    BB_ASSERT_SIZEOF(COptimalBundle, 0x10C);
}