#pragma once

#include <BlueBlur.inl>
#include <Sonic/FxPipeline/Jobs/FxJob.h>

namespace Sonic
{
    class CFxBloomGlare;

    static inline BB_FUNCTION_PTR(void, __thiscall, fpCFxBloomGlareInitialize, 0x10D4130, CFxBloomGlare* This);
    static inline BB_FUNCTION_PTR(void, __thiscall, fpCFxBloomGlareExecute, 0x10D3C20, CFxBloomGlare* This);

    class CFxBloomGlare : public CFxJob
    {
    public:
        BB_INSERT_PADDING(0x98);
        Hedgehog::Mirage::SShaderPair m_Bloom_BrightPassHDRShader;
        BB_INSERT_PADDING(0x300);
    };

    BB_ASSERT_OFFSETOF(CFxBloomGlare, m_Bloom_BrightPassHDRShader, 0xE0);
    BB_ASSERT_SIZEOF(CFxBloomGlare, 0x3F0);
}