#pragma once
namespace Sonic 
{
    class CGammaController : public Hedgehog::Base::CObject
    {
        BB_INSERT_PADDING(0x40);
    };
    BB_ASSERT_SIZEOF(CGammaController, 0x40);
}
