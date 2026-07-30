#pragma once

#include <Sonic/Player/Character/Base/PlayerRenderable.h>
#include <Sonic/System/GameObject3D.h>

namespace Hedgehog::Mirage
{
    class CMatrixNodeNormal;
}

namespace Sonic::Player
{
    class CSonicSpRenderableSsn : public CPlayerRenderable
    {
    public:
        bool m_IsSonicSp;
        boost::shared_ptr<Hedgehog::Mirage::CMatrixNodeNormal> m_spField160;
        boost::shared_ptr<Hedgehog::Mirage::CMatrixNodeNormal> m_spField168;
        boost::anonymous_shared_ptr m_spField170;
        boost::anonymous_shared_ptr m_spField178;
        BB_INSERT_PADDING(0x60);
    };

    BB_ASSERT_OFFSETOF(CSonicSpRenderableSsn, m_IsSonicSp, 0x15C);
    BB_ASSERT_OFFSETOF(CSonicSpRenderableSsn, m_spField160, 0x160);
    BB_ASSERT_OFFSETOF(CSonicSpRenderableSsn, m_spField168, 0x168);
    BB_ASSERT_OFFSETOF(CSonicSpRenderableSsn, m_spField170, 0x170);
    BB_ASSERT_OFFSETOF(CSonicSpRenderableSsn, m_spField178, 0x178);
    BB_ASSERT_SIZEOF(CSonicSpRenderableSsn, 0x1E0);
}
