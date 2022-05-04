#pragma once

namespace Chao::CSD
{
    template<typename TObservee>
    class CObserverBase
    {
    public:
        BB_INSERT_PADDING(0xC);

        virtual ~CObserverBase() = default;
    };

    BB_ASSERT_SIZEOF(CObserverBase<void>, 0x10);
}