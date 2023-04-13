#pragma once

#include <BlueBlur.inl>

namespace Hedgehog::Database
{
    struct SArchiveParam
    {
        int Priority;
        size_t Flags;

        size_t Field8;
        size_t FieldC;
        boost::anonymous_shared_ptr Field10;
        boost::function<void()> Field18;
        boost::function<void()> Field38;

        struct SField58
        {
            boost::function<void()> Field0;
            boost::function<void()> Field20;
        } Field58;

        int32_t Field98;
        boost::function<void()> FieldA0;
        boost::anonymous_shared_ptr FieldC0;
        uint8_t FieldC8;
        boost::anonymous_shared_ptr FieldCC;

        SArchiveParam(int in_Priority, size_t in_Flags); // 0x446F90
        ~SArchiveParam(); // 0x446E30
    };

    BB_ASSERT_OFFSETOF(SArchiveParam, Priority, 0x0);
    BB_ASSERT_OFFSETOF(SArchiveParam, Flags, 0x4);
    BB_ASSERT_OFFSETOF(SArchiveParam, Field8, 0x8);
    BB_ASSERT_OFFSETOF(SArchiveParam, FieldC, 0xC);
    BB_ASSERT_OFFSETOF(SArchiveParam, Field10, 0x10);
    BB_ASSERT_OFFSETOF(SArchiveParam, Field18, 0x18);
    BB_ASSERT_OFFSETOF(SArchiveParam, Field38, 0x38);
    BB_ASSERT_OFFSETOF(SArchiveParam, Field58, 0x58);
    BB_ASSERT_OFFSETOF(SArchiveParam, Field98, 0x98);
    BB_ASSERT_OFFSETOF(SArchiveParam, FieldA0, 0xA0);
    BB_ASSERT_OFFSETOF(SArchiveParam, FieldC0, 0xC0);
    BB_ASSERT_OFFSETOF(SArchiveParam, FieldC8, 0xC8);
    BB_ASSERT_OFFSETOF(SArchiveParam, FieldCC, 0xCC);
    BB_ASSERT_SIZEOF(SArchiveParam, 0xD8);
}
