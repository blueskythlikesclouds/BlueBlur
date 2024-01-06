#pragma once

#include <BlueBlur.inl>

namespace Hedgehog::Base
{
    class CSharedString;
}

namespace Hedgehog::Universe
{
    class CUpdateUnit;

    class CUpdateManager
    {
    public:
        void AddUpdateUnit(const Hedgehog::Base::CSharedString& in_rCategory, CUpdateUnit* in_pUpdateUnit);
    };
}

#include <Hedgehog/Universe/Engine/hhUpdateManager.inl>