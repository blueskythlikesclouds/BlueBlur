#pragma once

#include <Hedgehog/Base/Container/hhVector.h>
#include <Hedgehog/Base/System/hhSymbol.h>
#include <Sonic/System/GameObject.h>

namespace Sonic
{
    class CConverseRenderable;

    class CConverseStringRenderable : public Sonic::CGameObject
    {
    public:
        struct SConfig
        {
            const char* Message;
            int MessageLength;
            Hedgehog::Math::CVector2 Position;
            int Field10;
            bool HasOutline;
            float Field18;
            Hedgehog::Math::CColor Color;
        };
        int m_MessageLength;
        const char* m_Message;
        int m_FieldB0; // from config's Field10
        BB_INSERT_PADDING(0xC);
        Hedgehog::Math::CVector2 m_Position;
        int m_FieldC8;
        float m_FieldCC;
        Hedgehog::Math::CColor m_Color;
        float m_FieldD4;
        bool m_HasOutline;
        bool m_FieldD9;
        float m_FieldDC; // from config's Field18
        hh::vector<boost::shared_ptr<Sonic::CConverseRenderable>> m_SpawnedLetters;
        Hedgehog::Base::CStringSymbol m_RenderCategory;

        CConverseStringRenderable(const SConfig& in_rConfig, const Hedgehog::Base::CStringSymbol in_rRenderCategory);            
        CConverseStringRenderable(const SConfig& in_rConfig, Hedgehog::Mirage::ERenderCategory in_rRenderCategory);

        BB_OVERRIDE_FUNCTION_PTR(void, CGameObject, AddCallback, 0xCF8220, (const Hedgehog::Base::THolder<Sonic::CWorld>&, in_rWorldHolder),
            (Sonic::CGameDocument*, in_pGameDocument), (const boost::shared_ptr<Hedgehog::Database::CDatabase>&, in_spDatabase))
    };

    BB_ASSERT_OFFSETOF(CConverseStringRenderable::SConfig, Message, 0x0);
    BB_ASSERT_OFFSETOF(CConverseStringRenderable::SConfig, MessageLength, 0x4);
    BB_ASSERT_OFFSETOF(CConverseStringRenderable::SConfig, Position, 0x8);
    BB_ASSERT_OFFSETOF(CConverseStringRenderable::SConfig, Field10, 0x10);
    BB_ASSERT_OFFSETOF(CConverseStringRenderable::SConfig, HasOutline, 0x14);
    BB_ASSERT_OFFSETOF(CConverseStringRenderable::SConfig, Field18, 0x18);
    BB_ASSERT_OFFSETOF(CConverseStringRenderable::SConfig, Color, 0x1C);
    BB_ASSERT_SIZEOF(CConverseStringRenderable::SConfig, 0x20);

    BB_ASSERT_OFFSETOF(CConverseStringRenderable, m_MessageLength, 0xA8);
    BB_ASSERT_OFFSETOF(CConverseStringRenderable, m_Message, 0xAC);
    BB_ASSERT_OFFSETOF(CConverseStringRenderable, m_FieldB0, 0xB0);
    BB_ASSERT_OFFSETOF(CConverseStringRenderable, m_Position, 0xC0);
    BB_ASSERT_OFFSETOF(CConverseStringRenderable, m_FieldC8, 0xC8);
    BB_ASSERT_OFFSETOF(CConverseStringRenderable, m_FieldCC, 0xCC);
    BB_ASSERT_OFFSETOF(CConverseStringRenderable, m_Color, 0xD0);
    BB_ASSERT_OFFSETOF(CConverseStringRenderable, m_FieldD4, 0xD4);
    BB_ASSERT_OFFSETOF(CConverseStringRenderable, m_HasOutline, 0xD8);
    BB_ASSERT_OFFSETOF(CConverseStringRenderable, m_FieldD9, 0xD9);
    BB_ASSERT_OFFSETOF(CConverseStringRenderable, m_FieldDC, 0xDC);
    BB_ASSERT_OFFSETOF(CConverseStringRenderable, m_SpawnedLetters, 0xE0);
    BB_ASSERT_OFFSETOF(CConverseStringRenderable, m_RenderCategory, 0xF0);
}
#include <Sonic/System/Converse/ConverseStringRenderable.inl>