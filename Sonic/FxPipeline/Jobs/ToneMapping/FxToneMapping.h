#pragma once

#include <BlueBlur.inl>
#include <Sonic/FxPipeline/Jobs/FxJob.h>

namespace Hedgehog::Yggdrasill
{
    class CYggPicture;
}

namespace Sonic
{
    class CFxToneMapping;

    static inline BB_FUNCTION_PTR(void, __thiscall, fpCFxToneMappingInitialize, 0x10C5420, CFxToneMapping* This);
    static inline BB_FUNCTION_PTR(void, __thiscall, fpCFxToneMappingExecute, 0x10C5BB0, CFxToneMapping* This);

    class CFxToneMapping : public CFxJob
    {
    public:
        BB_INSERT_PADDING(0x8);
        boost::shared_ptr<Hedgehog::Yggdrasill::CYggTexture> m_spLuAvgTex;
        BB_INSERT_PADDING(0xF8);
        boost::shared_ptr<Hedgehog::Yggdrasill::CYggPicture> m_spDummyWhiteTex;
        BB_INSERT_PADDING(0xBC);
    };

    BB_ASSERT_OFFSETOF(CFxToneMapping, m_spLuAvgTex, 0x50);
    BB_ASSERT_OFFSETOF(CFxToneMapping, m_spDummyWhiteTex, 0x150);
    BB_ASSERT_SIZEOF(CFxToneMapping, 0x214);
}