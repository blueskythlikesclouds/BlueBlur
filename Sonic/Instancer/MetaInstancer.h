#pragma once

#include <Hedgehog/MirageCore/Renderable/hhRenderable.h>
#include <Hedgehog/Base/System/hhSymbol.h>

namespace Sonic
{
    class CMetaInstancer : public Hedgehog::Base::CObject
    {
    public:
        template<typename T>
        class CCloneable
        {
        public:
            virtual ~CCloneable() {}
            virtual T* Clone() const = 0;
        };

        class CRenderable : public Hedgehog::Mirage::CRenderable, public CCloneable<CRenderable>
        {
        public:
            CMetaInstancer* m_pInstancer;
            Hedgehog::Base::CStringSymbol m_RenderableCategory;
            uint8_t m_Field18;
            Hedgehog::Base::CStringSymbol m_RenderLevel;
            boost::function<void()> m_RenderCallback;
        };

        class CDesc
        {

        };

        class CSceneGraph
        {
        public:
            class CVisitor
            {
            public:
                virtual ~CVisitor() {}
            };
        };
    };

    BB_ASSERT_OFFSETOF(CMetaInstancer::CRenderable, m_pInstancer, 0x10);
    BB_ASSERT_OFFSETOF(CMetaInstancer::CRenderable, m_RenderableCategory, 0x14);
    BB_ASSERT_OFFSETOF(CMetaInstancer::CRenderable, m_Field18, 0x18);
    BB_ASSERT_OFFSETOF(CMetaInstancer::CRenderable, m_RenderLevel, 0x1C);
    BB_ASSERT_OFFSETOF(CMetaInstancer::CRenderable, m_RenderCallback, 0x20);
    BB_ASSERT_SIZEOF(CMetaInstancer::CRenderable, 0x40);
}