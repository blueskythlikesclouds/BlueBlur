#pragma once

#define bb_offsetof(s, m) ((size_t)&(((s*)0)->m))

#define _BB_CONCAT(x, y) x##y
#define BB_CONCAT2(x, y) _BB_CONCAT(x, y)
#define BB_INSERT_PADDING(length) \
    uint8_t BB_CONCAT2(pad, __LINE__)[length]

#define BB_ASSERT_OFFSETOF(type, field, offset) \
    static_assert(bb_offsetof(type, field) == offset, "offsetof assertion failed")

#define BB_ASSERT_SIZEOF(type, size) \
    static_assert(sizeof(type) == size, "sizeof assertion failed")
	
#define BB_FUNCTION_PTR(returnType, callingConvention, function, location, ...) \
    returnType (callingConvention *function)(__VA_ARGS__) = (returnType(callingConvention*)(__VA_ARGS__))(location)

// boost
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>

// Eigen
#include <Hedgehog/Math/detail/Eigen/Eigen>
#include <Hedgehog/Math/detail/unsupported/Eigen/AlignedVector3>

// Devil's Details' bullshit
#include <Sonic/DX_PATCH.h>

// Hedgehog::Math
namespace Hedgehog::Math
{
    using CAabb = Eigen::AlignedBox3f;
    using CMatrix = Eigen::Affine3f;
    using CMatrix44 = Eigen::Matrix4f;
    using CQuaternion = Eigen::Quaternionf;
    using CVector = Eigen::AlignedVector3<float>;
    using CVector4 = Eigen::Vector4f;
}

struct bb_null_ctor{};