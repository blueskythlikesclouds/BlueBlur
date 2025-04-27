#pragma once

#include <Sonic/System/GameObject.h>

namespace Hedgehog::Mirage
{
    struct STerrainInitializeInfo;
}

namespace Sonic
{
    class CTerrainManager2nd : public CGameObject
    {
    public:
        BB_INSERT_PADDING(0x448);
        Hedgehog::Mirage::STerrainInitializeInfo* m_pTerrainInitializeInfo;
        BB_INSERT_PADDING(0x2FC);
    };

    BB_ASSERT_OFFSETOF(CTerrainManager2nd, m_pTerrainInitializeInfo, 0x4F0);
    BB_ASSERT_SIZEOF(CTerrainManager2nd, 0x7F0);
}