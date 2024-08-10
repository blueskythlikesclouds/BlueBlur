#pragma once

#include <BlueBlur.inl>

namespace Sonic
{
    class CEditParam;

    class CSetObjectListener
    {
    public:
        CSetObjectListener() {}
        CSetObjectListener(const bb_null_ctor&) {}

        virtual ~CSetObjectListener() = default;

        virtual void InitializeEditParam(CEditParam& in_rEditParam) {}
        virtual void CSetObjectListener08(void*, void*) {}
        virtual void CSetObjectListener0C() {}
        virtual bool CSetObjectListener10(void*) { return false; }
        virtual void CSetObjectListener14(void*) {}
        virtual void CSetObjectListener18() {}
        virtual void CSetObjectListener1C(void*) {}
        virtual void OnSetEditorEnter() {}
        virtual void OnSetEditorLeave() {}
        virtual void CSetObjectListener28() {}
        virtual void CSetObjectListener2C() {}
        virtual void CSetObjectListener30(void*) {}
        virtual void CSetObjectListener34(void*) {}
        virtual void CSetObjectListener38() {}
        virtual void CSetObjectListener3C() {}
        virtual void CSetObjectListener40() {}
        virtual void CSetObjectListener44() {}
    };
}