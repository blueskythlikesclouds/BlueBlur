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
        hh::list<boost::shared_ptr<CRenderable>> m_RenderablesToAdd;
        hh::list<boost::shared_ptr<CRenderable>> m_RenderablesToRemove;

        CBundle(); // 0x6FA910

        void AddRenderable(const boost::shared_ptr<CRenderable>& in_spRenderable);
        void RemoveRenderable(const boost::shared_ptr<CRenderable>& in_spRenderable);
    };

    BB_ASSERT_OFFSETOF(CBundle, m_RenderableList, 0xC);
    BB_ASSERT_OFFSETOF(CBundle, m_RenderablesToAdd, 0x1C);
    BB_ASSERT_OFFSETOF(CBundle, m_RenderablesToRemove, 0x28);
    BB_ASSERT_SIZEOF(CBundle, 0x34);
}

#include <Hedgehog/MirageCore/Renderable/hhBundle.inl>