#pragma once

#include <Hedgehog/Base/hhObject.h>
#include <Hedgehog/Base/Thread/hhSynchronizedPtr.h>

namespace Sonic
{
    class CApplicationDocument;

    class CApplication : public Hedgehog::Base::CObject
    {
    public:
        Hedgehog::Base::TSynchronizedPtr<CApplicationDocument> m_pApplicationDocument;
        BB_INSERT_PADDING(0xC);

        virtual ~CApplication() = default;
    };

    BB_ASSERT_OFFSETOF(CApplication, m_pApplicationDocument, 0x4);
    BB_ASSERT_SIZEOF(CApplication, 0x14);
}
