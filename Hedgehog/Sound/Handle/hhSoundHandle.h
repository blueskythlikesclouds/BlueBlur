#pragma once

#include <Hedgehog/Base/hhObject.h>

namespace Hedgehog::Base
{
    class CSharedString;
}

namespace Hedgehog::Sound
{
    class CSoundCommandProcessor;

    class CSoundHandle : public Hedgehog::Base::CObject
    {
    public:
        uint32_t m_Field04;
        uint32_t m_Field08;
        uint32_t m_Field0C;
        uint32_t m_Field10;
        uint32_t m_Field14;
        uint32_t m_Field18;
        uint32_t m_Field1C;
        uint32_t m_Field20;
        uint32_t m_Field24;
        uint32_t m_Field28;
        uint32_t m_Field2C;
        uint32_t m_Field30;
        uint32_t m_Field34;
        float m_Field38;
        uint32_t m_Field3C;
        uint32_t m_Field40;
        boost::shared_ptr<CSoundCommandProcessor> m_spSoundCommandProcessor;
        uint32_t m_Field4C;
        uint32_t m_Field50;
        uint32_t m_Field54;
        uint32_t m_Field58;
        uint32_t m_Field5C;
        uint8_t m_Field60;
        uint32_t m_Field64;
        uint8_t m_Field68;
        uint8_t m_Field69;
        uint8_t m_Field6A;
        uint32_t m_Field6C;

        virtual void* CSoundHandle00(void* a1) { return nullptr; }
        virtual void* CSoundHandle04(void* a1) { return nullptr; }
        virtual void* CSoundHandle08() { return nullptr; }

        virtual void* Pause(bool a1, bool a2) { return nullptr; }
        virtual void* Stop(void* a1) { return nullptr; }
        virtual void* SetCue(const Hedgehog::Base::CSharedString& in_rCueName) { return nullptr; }
        virtual void* SetCue(uint32_t in_CueID) { return nullptr; }

        virtual void* CSoundHandle1C(void* a1) { return nullptr; }
        virtual void* CSoundHandle20(void* a1) { return nullptr; }
        virtual void  CSoundHandle24(float a1) {}
        virtual float CSoundHandle28() { return 0; }

        virtual void  SetEcho(float a1) {}
        virtual float GetEcho() { return 0; }

        virtual void  CSoundHandle34(float a1) {}
        virtual float CSoundHandle38() { return 0; }
        virtual void* CSoundHandle3C() { return nullptr; }

        virtual void* SetLoop(bool a1) { return nullptr; }

        virtual void* CSoundHandle44() { return nullptr; }
        virtual bool  CSoundHandle48(int a1) { return false; }
        virtual void* CSoundHandle4C(void* a1) { return nullptr; }
        virtual void* CSoundHandle50(void* a1) { return nullptr; }
        virtual void* CSoundHandle54(void* a1) { return nullptr; }
        virtual void* CSoundHandle58(void* a1) { return nullptr; }

        virtual ~CSoundHandle() = default;

        virtual void* CSoundHandle60(void* a1) { return nullptr; }
        virtual void* CSoundHandle64() { return nullptr; }
        virtual void* CSoundHandle68(void* a1, void* a2) { return nullptr; }

        virtual void* GetSoundPlayer() = 0;
    };

    BB_ASSERT_SIZEOF(CSoundHandle, 0x70);
}