#pragma once

#include <Hedgehog/Base/hhObject.h>

namespace Hedgehog::Base
{
    class CStringSymbol;
}

namespace Hedgehog::Yggdrasill
{
    class CYggAbstractBuffer;
    class CYggScheduler;
    class CYggSurface;
    class CYggTexture;

    class CYggJob : public Base::CObject
    {
    public:
        BB_INSERT_PADDING(0x8);
        CYggScheduler* m_pScheduler;
        BB_INSERT_PADDING(0x30);

        virtual ~CYggJob() = default;
        virtual void Initialize() = 0;
        virtual void Execute() = 0;

        boost::shared_ptr<CYggTexture> GetDefaultTexture() const;
        boost::shared_ptr<CYggTexture> GetTexture(const Base::CStringSymbol& in_rSymbol) const;
        boost::shared_ptr<CYggSurface> GetSurface(const Base::CStringSymbol& in_rSymbol) const;

        void SetDefaultTexture(const boost::shared_ptr<CYggTexture>& in_spTexture);
        void SetBuffer(const Base::CStringSymbol& in_rSymbol, const boost::shared_ptr<CYggAbstractBuffer>& in_spBuffer);
    };

    BB_ASSERT_OFFSETOF(CYggJob, m_pScheduler, 0xC);
    BB_ASSERT_SIZEOF(CYggJob, 0x40);
}

#include <Hedgehog/Yggdrasill/hhYggJob.inl>