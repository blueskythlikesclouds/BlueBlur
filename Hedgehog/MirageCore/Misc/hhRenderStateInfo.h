#pragma once

#include <BlueBlur.inl>

namespace Hedgehog::Mirage
{
    struct SRenderState
    {
        uint32_t Value;
        uint32_t LockCount;
        uint32_t StackSize;
        uint32_t Stack[32];
    };

    BB_ASSERT_OFFSETOF(SRenderState, Value, 0x0);
    BB_ASSERT_OFFSETOF(SRenderState, LockCount, 0x4);
    BB_ASSERT_OFFSETOF(SRenderState, StackSize, 0x8);
    BB_ASSERT_OFFSETOF(SRenderState, Stack, 0xC);
    BB_ASSERT_SIZEOF(SRenderState, 0x8C);

    struct SRenderStateInfo
    {
        BB_INSERT_PADDING(0x8);
        uint32_t ShaderLockCount;
        float DepthBias;
        float SlopeScaledDepthBias;
        float DepthBiasCullModeNone;
        float SlopeScaledDepthBiasCullModeNone;
        BB_INSERT_PADDING(0x10);
        bool DepthBiasEnable;
        bool RevertZ;
        BB_INSERT_PADDING(0x2);
        SRenderState RenderStates[210];
    };

    BB_ASSERT_OFFSETOF(SRenderStateInfo, ShaderLockCount, 0x8);
    BB_ASSERT_OFFSETOF(SRenderStateInfo, DepthBias, 0xC);
    BB_ASSERT_OFFSETOF(SRenderStateInfo, SlopeScaledDepthBias, 0x10);
    BB_ASSERT_OFFSETOF(SRenderStateInfo, DepthBiasCullModeNone, 0x14);
    BB_ASSERT_OFFSETOF(SRenderStateInfo, SlopeScaledDepthBiasCullModeNone, 0x18);
    BB_ASSERT_OFFSETOF(SRenderStateInfo, DepthBiasEnable, 0x2C);
    BB_ASSERT_OFFSETOF(SRenderStateInfo, RevertZ, 0x2D);
    BB_ASSERT_OFFSETOF(SRenderStateInfo, RenderStates, 0x30);
    BB_ASSERT_SIZEOF(SRenderStateInfo, 0x7308);
}