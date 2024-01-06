#pragma once

#include <Hedgehog/MirageCore/Misc/hhDirector.h>
#include <Sonic/System/GameObject.h>

namespace Sonic
{
    class CRenderDirector : public Hedgehog::Mirage::CDirector, public CGameObject
    {
    public:
        BB_INSERT_PADDING(0x14);
    };

    BB_ASSERT_SIZEOF(CRenderDirector, 0xC0);
}