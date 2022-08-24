#pragma once

// boost
#include <boost/any.hpp>
#include <boost/function.hpp>
#include <boost/make_shared.hpp>
#include <boost/scoped_ptr.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/preprocessor.hpp>

// Eigen
#include <Hedgehog/Math/detail/Eigen/Eigen>
#include <Hedgehog/Math/detail/unsupported/Eigen/AlignedVector3>

// Devil's Details
#include <Sonic/DX_PATCH.h>

#define bb_offsetof(s, m) ((size_t)&(((s*)0)->m))

#define BB_INSERT_PADDING(length) \
    uint8_t BOOST_PP_CAT(pad, __LINE__)[length]

#define BB_ASSERT_OFFSETOF(type, field, offset) \
    static_assert(bb_offsetof(type, field) == offset, "offsetof assertion failed")

#define BB_ASSERT_SIZEOF(type, size) \
    static_assert(sizeof type == size, "sizeof assertion failed")
	
#define BB_FUNCTION_PTR(returnType, callingConvention, function, location, ...) \
    returnType (callingConvention *function)(__VA_ARGS__) = (returnType(callingConvention*)(__VA_ARGS__))(location)

#define _BB_TYPE_AND_NAME_FROM_TUPLE(r, data, i, x) BOOST_PP_COMMA_IF(i) BOOST_PP_TUPLE_ELEM(0, x) BOOST_PP_TUPLE_ELEM(1, x)
#define _BB_NAME_FROM_TUPLE(r, data, i, x) BOOST_PP_COMMA_IF(i) BOOST_PP_TUPLE_ELEM(1, x)

#define _BB_VTABLE_FUNCTION_PTR(virtual, returnType, type, function, location, override, ...) \
    virtual returnType function(BOOST_PP_SEQ_FOR_EACH_I(_BB_TYPE_AND_NAME_FROM_TUPLE, _, BOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__))) override \
    { \
        BB_FUNCTION_PTR(returnType, __thiscall, fp##function, location, type This, BOOST_PP_SEQ_FOR_EACH_I(_BB_TYPE_AND_NAME_FROM_TUPLE, _, BOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__))); \
        return fp##function(this, BOOST_PP_SEQ_FOR_EACH_I(_BB_NAME_FROM_TUPLE, _, BOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__))); \
    }

#define BB_VIRTUAL_FUNCTION_PTR(returnType, function, location, ...) \
    _BB_VTABLE_FUNCTION_PTR(virtual, returnType, decltype(this), function, location, , __VA_ARGS__)

#define BB_OVERRIDE_FUNCTION_PTR(returnType, baseType, function, location, ...) \
    _BB_VTABLE_FUNCTION_PTR(, returnType, baseType*, function, location, override, __VA_ARGS__)

// Hedgehog::Math
namespace Hedgehog::Math
{
    using CAabb = Eigen::AlignedBox3f;
    using CMatrix = Eigen::Affine3f;
    using CMatrix44 = Eigen::Matrix4f;
    using CQuaternion = Eigen::Quaternionf;
    using CVector = Eigen::AlignedVector3<float>;
    using CVector2 = Eigen::Vector2f;
    using CVector4 = Eigen::Vector4f;
}

struct bb_null_ctor{};

template<int n>
struct bb_insert_padding { BB_INSERT_PADDING(n); };