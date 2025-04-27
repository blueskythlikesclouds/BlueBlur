#pragma once

#include <BlueBlur.h>

namespace Hedgehog::Mirage
{
    class CTerrainGroupSubsetInfo
    {
    public:
        uint32_t m_SubsetId;
        uint32_t m_CurrentState;
        uint32_t m_SavedState;
    };

    BB_ASSERT_OFFSETOF(CTerrainGroupSubsetInfo, m_SubsetId, 0x0);
    BB_ASSERT_OFFSETOF(CTerrainGroupSubsetInfo, m_CurrentState, 0x4);
    BB_ASSERT_OFFSETOF(CTerrainGroupSubsetInfo, m_SavedState, 0x8);
    BB_ASSERT_SIZEOF(CTerrainGroupSubsetInfo, 0xC);
}