#pragma once

#define bb_offsetof(s, m) ((size_t)&(((s*)0)->m))

#define _CONCAT2(x, y) x##y
#define CONCAT2(x, y) _CONCAT(x, y)
#define INSERT_PADDING(length) \
    uint8_t CONCAT2(pad, __LINE__)[length]

#define ASSERT_OFFSETOF(type, field, offset) \
    static_assert(bb_offsetof(type, field) == offset, "offsetof assertion failed")

#define ASSERT_SIZEOF(type, size) \
    static_assert(sizeof(type) == size, "sizeof assertion failed")
	
#define FUNCTION_PTR(returnType, callingConvention, function, location, ...) \
    returnType (callingConvention *function)(__VA_ARGS__) = (returnType(callingConvention*)(__VA_ARGS__))(location)

// boost
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>

// Eigen
#include <Eigen/Eigen>
#include <unsupported/Eigen/AlignedVector3>

// Devil's Details' bullshit
#include <Sonic/DX_PATCH.h>

// Sonicteam::System
namespace Sonicteam::System
{
    using Matrix = Eigen::Affine3f;
    using Matrix44 = Eigen::Matrix4f;
    using Quaternion = Eigen::Quaternionf;
    using Vector3 = Eigen::AlignedVector3<float>;
    using Vector4 = Eigen::Vector4f;
}

// Hedgehog::Math
namespace Hedgehog::Math
{
    using CAabb = Eigen::AlignedBox3f;
    using CMatrix = Sonicteam::System::Matrix;
    using CMatrix44 = Sonicteam::System::Matrix44;
    using CQuaternion = Sonicteam::System::Quaternion;
    using CVector = Sonicteam::System::Vector3;
    using CVector4 = Sonicteam::System::Vector4;
}

template<int n> struct InsertPadding
{
    INSERT_PADDING(n);
};

struct null_ctor{};