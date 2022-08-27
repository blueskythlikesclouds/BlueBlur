#pragma once

#include <Hedgehog/Base/hhObject.h>
#include <Hedgehog/Base/Container/hhVector.h>
#include <Hedgehog/Base/Type/hhSharedString.h>

namespace Sonic
{
    class CSetObjectEntry;

    struct SSetObjectMake
    {
        boost::shared_ptr<CSetObjectEntry> (__cdecl* pFunc)();
        void* (__cdecl* pUnknownFunc)(void*);
    };

    BB_ASSERT_OFFSETOF(SSetObjectMake, pFunc, 0x0);
    BB_ASSERT_OFFSETOF(SSetObjectMake, pUnknownFunc, 0x4);
    BB_ASSERT_SIZEOF(SSetObjectMake, 0x8);

    class CSetObjectMakeEntry : public Hedgehog::Base::CObject
    {
    public:
        const SSetObjectMake* m_pMake;
        Hedgehog::Base::CSharedString m_Name;
        bool m_Field08;

        CSetObjectMakeEntry(const SSetObjectMake& in_rMake, const Hedgehog::Base::CSharedString& in_rName)
            : m_pMake(&in_rMake), m_Name(in_rName), m_Field08(false)
        {
            
        }
    };

    BB_ASSERT_OFFSETOF(CSetObjectMakeEntry, m_pMake, 0x0);
    BB_ASSERT_OFFSETOF(CSetObjectMakeEntry, m_Name, 0x4);
    BB_ASSERT_OFFSETOF(CSetObjectMakeEntry, m_Field08, 0x8);
    BB_ASSERT_SIZEOF(CSetObjectMakeEntry, 0xC);

    class CSetObjectFactory
    {
    public:
        hh::vector<CSetObjectMakeEntry> m_MakeList;
        BB_INSERT_PADDING(0x10);
    };

    BB_ASSERT_OFFSETOF(CSetObjectFactory, m_MakeList, 0x0);
    BB_ASSERT_SIZEOF(CSetObjectFactory, 0x20);
}

#define SET_OBJECT_MAKE(name) \
    template<typename base_t> \
    static auto get_function_base_type(void(base_t::*)())->base_t; \
    \
    template<typename T> void get_base_type(); \
    typedef decltype(get_function_base_type(&get_base_type<void>)) this_t; \
    \
    static constexpr const char* ms_Name = name; \
    \
    static boost::shared_ptr<Sonic::CSetObjectEntry> Make() \
    { \
        const auto spSetObject = boost::make_shared<this_t>(); \
        return boost::make_shared<Sonic::CSetObjectEntry>(boost::make_shared<Sonic::SSetObjectInfo>(spSetObject, spSetObject), ms_Name); \
    }

#define SET_OBJECT_MAKE_HOOK(type) \
    static inline Sonic::SSetObjectMake g_##type##Make = { &(type::Make), nullptr }; \
    \
    static void __cdecl f##type##MakeHook(Sonic::CSetObjectFactory* pSetObjectFactory) \
    { \
        pSetObjectFactory->m_MakeList.push_back({ g_##type##Make, type::ms_Name }); \
    } \
    \
    static inline uint32_t g_##type##MakeReturnAddr = 0x660AE0; \
    \
    static void __declspec(naked) f##type##MakeTrampoline() \
    { \
        __asm { push esi } \
        __asm { call f##type##MakeHook } \
        __asm { pop esi } \
        __asm { jmp[g_##type##MakeReturnAddr] } \
    }

#define INSTALL_SET_OBJECT_MAKE_HOOK(type) \
    { \
        uint32_t* pNextHookAddr = (uint32_t*)0xEBD51C; \
        \
        if (*pNextHookAddr != 0xCCCCCCCC) \
            g_##type##MakeReturnAddr = *pNextHookAddr; \
        \
        WRITE_JUMP(0xEBD515, f##type##MakeTrampoline); \
        WRITE_MEMORY(pNextHookAddr, uint32_t, (uint32_t)&f##type##MakeTrampoline); \
    }