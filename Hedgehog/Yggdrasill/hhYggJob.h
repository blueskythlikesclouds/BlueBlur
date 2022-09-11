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

    static inline BB_FUNCTION_PTR(void, __thiscall, fpCYggJobGetDefaultTexture, 0x784A60, const CYggJob* This, boost::shared_ptr<CYggTexture>& spTexture);
    static inline BB_FUNCTION_PTR(void, __thiscall, fpCYggJobGetTexture, 0x7848D0, const CYggJob* This, boost::shared_ptr<CYggTexture>& spTexture, const Hedgehog::Base::CStringSymbol& symbol);
    static inline BB_FUNCTION_PTR(void, __thiscall, fpCYggJobGetSurface, 0x7847B0, const CYggJob* This, boost::shared_ptr<CYggSurface>& spSurface, const Hedgehog::Base::CStringSymbol& symbol);

    static inline BB_FUNCTION_PTR(void, __thiscall, fpCYggJobSetDefaultTexture, 0x784D00, CYggJob* This, const boost::shared_ptr<CYggTexture>& spTexture);
    static inline BB_FUNCTION_PTR(void, __thiscall, fpCYggJobSetBuffer, 0x784BF0, CYggJob* This, const Hedgehog::Base::CStringSymbol& symbol, const boost::shared_ptr<CYggAbstractBuffer>& spBuffer);

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

        boost::shared_ptr<CYggTexture> GetTexture(const Base::CStringSymbol& symbol) const
        {
            boost::shared_ptr<CYggTexture> spTexture;
            fpCYggJobGetTexture(this, spTexture, symbol);
            return spTexture;
        }      

        boost::shared_ptr<CYggSurface> GetSurface(const Base::CStringSymbol& symbol) const
        {
            boost::shared_ptr<CYggSurface> spSurface;
            fpCYggJobGetSurface(this, spSurface, symbol);
            return spSurface;
        }

        void SetDefaultTexture(const boost::shared_ptr<CYggTexture>& spTexture)
        {
            fpCYggJobSetDefaultTexture(this, spTexture);
        }

        void SetBuffer(const Base::CStringSymbol& symbol, const boost::shared_ptr<CYggAbstractBuffer>& spBuffer)
        {
            fpCYggJobSetBuffer(this, symbol, spBuffer);
        }      
    };

    BB_ASSERT_OFFSETOF(CYggJob, m_pScheduler, 0xC);
    BB_ASSERT_SIZEOF(CYggJob, 0x40);
}
