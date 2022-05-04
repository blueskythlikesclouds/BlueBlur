#pragma once

#include <BlueBlur.inl>

namespace Chao::CSD
{
    template<typename TObserver, typename TObservee>
    class SubjectBase
    {
    public:
        BB_INSERT_PADDING(0xC);

        virtual ~SubjectBase() = default;
        virtual TObservee* GetObservee() const
        {
            return nullptr;
        }
    };

    BB_ASSERT_SIZEOF((SubjectBase<void, void>), 0x10);
}