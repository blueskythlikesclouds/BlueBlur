#pragma once

#include <BlueBlur.inl>

namespace Hedgehog::FxRenderFramework
{
    struct SDrawInstanceParam
    {
        uint32_t Reserved0; // Temporarily set by game
        uint32_t Reserved1; // Temporarily set by game

        const char* pName;
        uint32_t Id;

        void* pCallback; // ScreenTraverse

        void* ChildParams;
        uint32_t ChildParamCount;

        BB_INSERT_PADDING(0x4);

        uint8_t DepthStencilSurface;
        uint8_t RenderTargetSurface;

        uint8_t TemporaryDepthStencilSurface;
        uint8_t TemporaryRenderTargetSurface;

        union
        {
            struct
            {
                uint8_t ReflectionMap2Sampler;
                uint8_t ReflectionMapSampler;

                uint8_t VerticalShadowMapSampler;
                uint8_t ShadowMapSampler;
            };

            struct
            {
                uint8_t S3Sampler;
                uint8_t S2Sampler;
                uint8_t S1Sampler;
                uint8_t S0Sampler;
            };
        };

        uint32_t Unk0;
        uint32_t Unk1;
        uint32_t Unk2;
        uint32_t Unk3;
        uint32_t Unk4;
        uint32_t Unk5;
    };

    BB_ASSERT_SIZEOF(SDrawInstanceParam, 0x40);
}