#pragma once

#include <BlueBlur.inl>

namespace Hedgehog::FxRenderFramework
{
    struct SScreenRenderParam
    {
        const char* pName;
        void* pCallback; // SceneTraverse or SceneRender
        int32_t ShaderIndex;
        BB_INSERT_PADDING(0x18);
    };

    BB_ASSERT_SIZEOF(SScreenRenderParam, 0x24);
}