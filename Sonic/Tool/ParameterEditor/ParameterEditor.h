#pragma once

#include <Sonic/System/GameObject.h>

namespace Sonic
{
    class CGlobalParameterManager;

    class CParameterEditor : public Sonic::CGameObject
    {
    public:
        BB_INSERT_PADDING(0x4);
        boost::shared_ptr<CGlobalParameterManager> m_spGlobalParameterManager;
        BB_INSERT_PADDING(0x4);
    };

    BB_ASSERT_OFFSETOF(CParameterEditor, m_spGlobalParameterManager, 0xAC);
    BB_ASSERT_SIZEOF(CParameterEditor, 0xB8);
}