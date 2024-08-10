#pragma once

#include <CSD/Platform/csdTexList.h>

namespace Hedgehog::Mirage
{
    class CTexsetData;
}

namespace Sonic
{
    class CCsdTexListMirage : public Chao::CSD::CTexList
    {
    public:
        boost::shared_ptr<Hedgehog::Mirage::CTexsetData> m_spTexsetData;
        BB_INSERT_PADDING(0x4);
    };

    BB_ASSERT_OFFSETOF(CCsdTexListMirage, m_spTexsetData, 0xC);
    BB_ASSERT_SIZEOF(CCsdTexListMirage, 0x18);
}