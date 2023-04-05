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
    class CYggScheduler;

    static inline BB_FUNCTION_PTR(void*, __thiscall, fpCYggSchedulerGetShader, 0x789DB0,
        const CYggScheduler* This, Hedgehog::Mirage::SShaderPair& out_rPair, const char* in_pVertexShaderName, const char* in_pPixelShaderName);

    static inline BB_FUNCTION_PTR(void*, __thiscall, fpCYggSchedulerGetPicture, 0x789DD0,
        const CYggScheduler* This, boost::shared_ptr<CYggPicture>& out_spPicture, const char* in_pName);


    class CYggScheduler : public Base::CObject
    {
    public:
        CYggMisc* m_pMisc;
        BB_INSERT_PADDING(0x4);

        virtual ~CYggScheduler() = default;

        Mirage::SShaderPair GetShader(const char* in_pVertexShaderName, const char* in_pPixelShaderName) const
        {
            Mirage::SShaderPair pair;
            fpCYggSchedulerGetShader(this, pair, in_pVertexShaderName, in_pPixelShaderName);
            return pair;
        }

        boost::shared_ptr<CYggPicture> GetPicture(const char* in_pName) const
        {
            boost::shared_ptr<CYggPicture> spPicture;
            fpCYggSchedulerGetPicture(this, spPicture, in_pName);
            return spPicture;
        }
    };

    BB_ASSERT_OFFSETOF(CYggScheduler, m_pMisc, 0x4);
    BB_ASSERT_SIZEOF(CYggScheduler, 0xC);
}
