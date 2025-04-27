#pragma once

#include <Hedgehog/Base/hhObject.h>
#include <Hedgehog/Base/Container/hhList.h>
#include <Hedgehog/Base/Container/hhMap.h>
#include <Hedgehog/Base/System/hhSymbol.h>

namespace Hedgehog::Mirage
{
    class CBundle;
    class COptimalBundle;

    class CRenderScene : public Base::CObject
    {
    public:
        hh::map<Base::CStringSymbol, boost::shared_ptr<CBundle>> m_BundleMap;
        hh::map<Base::CStringSymbol, boost::shared_ptr<CBundle>> m_ResidentBundleMap; // used during FxPipeline Renderer alphabet jumpscare
        hh::list<void*> m_Field1C;

        virtual ~CRenderScene() = default;
    };

    BB_ASSERT_OFFSETOF(CRenderScene, m_BundleMap, 0x4);
    BB_ASSERT_OFFSETOF(CRenderScene, m_ResidentBundleMap, 0x10);
    BB_ASSERT_OFFSETOF(CRenderScene, m_Field1C, 0x1C);
    BB_ASSERT_SIZEOF(CRenderScene, 0x28);
}