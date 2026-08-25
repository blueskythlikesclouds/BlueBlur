#pragma once

#include <Hedgehog/MirageCore/Renderable/hhRenderable.h>

namespace Hedgehog::Database
{
    class CDatabase;
}

namespace Hedgehog::Font
{
    class CTextBox;
    class CFontConverseData;
}

namespace Sonic
{
    class CConverseRenderable : public Hedgehog::Mirage::CRenderable
    {
    public:
        enum EAlignment : uint32_t
        {
            eAlignment_Left = 0,
            eAlignment_Screen = 1,
            eAlignment_Element = 2
        };
        struct SConfig
        {
            char FileName[64];
            char GroupName[32];
            char CellName[32];
            Hedgehog::Math::CVector2 Position;
            EAlignment Alignment;
            bool HasOutline;
            int Field90;
            Hedgehog::Base::CColor Color;
        };
        boost::shared_ptr<Hedgehog::Font::CTextBox> m_spTextBox;
        EAlignment m_Alignment;
        int m_Field18;
        int m_Field1C;
        Hedgehog::Math::CVector2 m_Position;
        int m_Field28;
        float m_Field2C;
        Hedgehog::Base::CColor m_Color;
        float m_Opacity;
        uint8_t m_HasOutline;
        uint8_t m_Field39;
        float m_Field3C;
        boost::shared_ptr<Hedgehog::Font::CFontConverseData> m_spFontConverseData;
        int m_Field48;
        int m_Field4C;

        CConverseRenderable(const boost::shared_ptr<Hedgehog::Database::CDatabase>& in_spDatabase, const SConfig& in_rConfig);
    };
    BB_ASSERT_OFFSETOF(CConverseRenderable::SConfig, FileName, 0x0);
    BB_ASSERT_OFFSETOF(CConverseRenderable::SConfig, GroupName, 0x40);
    BB_ASSERT_OFFSETOF(CConverseRenderable::SConfig, CellName, 0x60);
    BB_ASSERT_OFFSETOF(CConverseRenderable::SConfig, Position, 0x80);
    BB_ASSERT_OFFSETOF(CConverseRenderable::SConfig, Alignment, 0x88);
    BB_ASSERT_OFFSETOF(CConverseRenderable::SConfig, HasOutline, 0x8C);
    BB_ASSERT_OFFSETOF(CConverseRenderable::SConfig, Field90, 0x90);
    BB_ASSERT_OFFSETOF(CConverseRenderable::SConfig, Color, 0x94);
    BB_ASSERT_SIZEOF(CConverseRenderable::SConfig, 0x98);

    BB_ASSERT_OFFSETOF(CConverseRenderable, m_spTextBox, 0xC);
    BB_ASSERT_OFFSETOF(CConverseRenderable, m_Alignment, 0x14);
    BB_ASSERT_OFFSETOF(CConverseRenderable, m_Field18, 0x18);
    BB_ASSERT_OFFSETOF(CConverseRenderable, m_Field1C, 0x1C);
    BB_ASSERT_OFFSETOF(CConverseRenderable, m_Position, 0x20);
    BB_ASSERT_OFFSETOF(CConverseRenderable, m_Field28, 0x28);
    BB_ASSERT_OFFSETOF(CConverseRenderable, m_Field2C, 0x2C);
    BB_ASSERT_OFFSETOF(CConverseRenderable, m_Color, 0x30);
    BB_ASSERT_OFFSETOF(CConverseRenderable, m_Opacity, 0x34);
    BB_ASSERT_OFFSETOF(CConverseRenderable, m_HasOutline, 0x38);
    BB_ASSERT_OFFSETOF(CConverseRenderable, m_Field39, 0x39);
    BB_ASSERT_OFFSETOF(CConverseRenderable, m_Field3C, 0x3C);
    BB_ASSERT_OFFSETOF(CConverseRenderable, m_spFontConverseData, 0x40);
    BB_ASSERT_OFFSETOF(CConverseRenderable, m_Field48, 0x48);
    BB_ASSERT_OFFSETOF(CConverseRenderable, m_Field4C, 0x4C);
    BB_ASSERT_SIZEOF(CConverseRenderable, 0x50);
}
#include <Sonic/System/Converse/ConverseRenderable.inl>