#pragma once

#include <Hedgehog/Base/hhObject.h>

namespace Hedgehog::Mirage
{
    class CPixelShaderData;
    class CVertexShaderData;

    struct SShaderPair
    {
        boost::shared_ptr<CVertexShaderData> m_spVertexShader;
        boost::shared_ptr<CPixelShaderData> m_spPixelShader;
    };
}

namespace Hedgehog::Yggdrasill
{
    class CYggMisc;
    class CYggPicture;

    class CYggScheduler : public Base::CObject
    {
    public:
        CYggMisc* m_pMisc;
        BB_INSERT_PADDING(0x4);

        virtual ~CYggScheduler() = default;

        Mirage::SShaderPair GetShader(const char* in_pVertexShaderName, const char* in_pPixelShaderName) const;
        boost::shared_ptr<CYggPicture> GetPicture(const char* in_pName) const;
    };

    BB_ASSERT_OFFSETOF(CYggScheduler, m_pMisc, 0x4);
    BB_ASSERT_SIZEOF(CYggScheduler, 0xC);
}


#include <Hedgehog/Yggdrasill/hhYggScheduler.inl>