#pragma once

namespace Hedgehog::Mirage
{
    class CBundle;
    class COptimalBundle;

    class CBundlePair
    {
    public:
        boost::shared_ptr<Hedgehog::Mirage::CBundle> m_pBundle;
        boost::shared_ptr<Hedgehog::Mirage::COptimalBundle> m_pOptimalBundle;
    };

    BB_ASSERT_OFFSETOF(CBundlePair, m_pBundle, 0x0);
    BB_ASSERT_OFFSETOF(CBundlePair, m_pOptimalBundle, 0x8);
    BB_ASSERT_SIZEOF(CBundlePair, 0x10);
}
