#pragma once

#include <Hedgehog/Base/Container/hhVector.h>
#include <Hedgehog/Base/Container/hhList.h>
#include <Hedgehog/MirageCore/Renderable/hhRenderable.h>

namespace Hedgehog::Mirage
{
    class CBundle : public CRenderable
    {
    public:
        hh::vector<boost::shared_ptr<CRenderable>> m_RenderableList;
        hh::list<void*> m_Field1C;
        hh::list<void*> m_Field28;
    };

    BB_ASSERT_OFFSETOF(CBundle, m_RenderableList, 0xC);
    BB_ASSERT_OFFSETOF(CBundle, m_Field1C, 0x1C);
    BB_ASSERT_OFFSETOF(CBundle, m_Field28, 0x28);
    BB_ASSERT_SIZEOF(CBundle, 0x34);
}