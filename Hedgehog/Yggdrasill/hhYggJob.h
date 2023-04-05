#pragma once

#include <Hedgehog/Base/hhObject.h>

namespace Hedgehog::Base
{
    class CStringSymbol;
}

namespace Hedgehog::Yggdrasill
{
    class CYggAbstractBuffer;
    class CYggJob;
    class CYggScheduler;
    class CYggSurface;
    class CYggTexture;

    static inline BB_FUNCTION_PTR(void, __thiscall, fpCYggJobGetDefaultTexture, 0x784A60, const CYggJob* This, boost::shared_ptr<CYggTexture>& out_spTexture);
    static inline BB_FUNCTION_PTR(void, __thiscall, fpCYggJobGetTexture, 0x7848D0, const CYggJob* This, boost::shared_ptr<CYggTexture>& out_spTexture, const Hedgehog::Base::CStringSymbol& in_rSymbol);
    static inline BB_FUNCTION_PTR(void, __thiscall, fpCYggJobGetSurface, 0x7847B0, const CYggJob* This, boost::shared_ptr<CYggSurface>& out_spSurface, const Hedgehog::Base::CStringSymbol& in_rSymbol);

    static inline BB_FUNCTION_PTR(void, __thiscall, fpCYggJobSetDefaultTexture, 0x784D00, CYggJob* This, const boost::shared_ptr<CYggTexture>& in_spTexture);
    static inline BB_FUNCTION_PTR(void, __thiscall, fpCYggJobSetBuffer, 0x784BF0, CYggJob* This, const Hedgehog::Base::CStringSymbol& in_rSymbol, const boost::shared_ptr<CYggAbstractBuffer>& in_spBuffer);

    class CYggJob : public Base::CObject
    {
    public:
        BB_INSERT_PADDING(0x8);
        CYggScheduler* m_pScheduler;
        BB_INSERT_PADDING(0x30);

        virtual ~CYggJob() = default;
        virtual void Initialize() = 0;
        virtual void Execute() = 0;

        boost::shared_ptr<CYggTexture> GetDefaultTexture() const
        {
            boost::shared_ptr<CYggTexture> spTexture;
            fpCYggJobGetDefaultTexture(this, spTexture);
            return spTexture;
        }

        boost::shared_ptr<CYggTexture> GetTexture(const Base::CStringSymbol& in_rSymbol) const
        {
            boost::shared_ptr<CYggTexture> spTexture;
            fpCYggJobGetTexture(this, spTexture, in_rSymbol);
            return spTexture;
        }      

        boost::shared_ptr<CYggSurface> GetSurface(const Base::CStringSymbol& in_rSymbol) const
        {
            boost::shared_ptr<CYggSurface> spSurface;
            fpCYggJobGetSurface(this, spSurface, in_rSymbol);
            return spSurface;
        }

        void SetDefaultTexture(const boost::shared_ptr<CYggTexture>& in_spTexture)
        {
            fpCYggJobSetDefaultTexture(this, in_spTexture);
        }

        void SetBuffer(const Base::CStringSymbol& in_rSymbol, const boost::shared_ptr<CYggAbstractBuffer>& in_spBuffer)
        {
            fpCYggJobSetBuffer(this, in_rSymbol, in_spBuffer);
        }      
    };

    BB_ASSERT_OFFSETOF(CYggJob, m_pScheduler, 0xC);
    BB_ASSERT_SIZEOF(CYggJob, 0x40);
}
