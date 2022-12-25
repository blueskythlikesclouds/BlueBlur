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

#define BB_OFFSETOF(type, member) ((size_t)&(((type*)0)->member))

#define BB_INSERT_PADDING(length) \
    uint8_t BOOST_PP_CAT(pad, __LINE__)[length]

#define BB_ASSERT_OFFSETOF(type, field, offset) \
    static inline bb_assert_offsetof<BB_OFFSETOF(type, field), offset> BOOST_PP_CAT(_, __COUNTER__)

#define BB_ASSERT_SIZEOF(type, size) \
    static inline bb_assert_sizeof<sizeof type, size> BOOST_PP_CAT(_, __COUNTER__)

#define BB_FUNCTION_PTR(returnType, callingConvention, function, location, ...) \
    returnType (callingConvention *function)(__VA_ARGS__) = (returnType(callingConvention*)(__VA_ARGS__))(location)

#define BB_VTABLE_HAS_ARGS_0 0
#define BB_VTABLE_HAS_ARGS_2 1
#define BB_VTABLE_HAS_ARGS(seq) BOOST_PP_CAT(BB_VTABLE_HAS_ARGS_, BOOST_PP_TUPLE_SIZE(BOOST_PP_SEQ_ELEM(0, seq)))

#define BB_VTABLE_TYPE_AND_NAME(r, data, i, x) BOOST_PP_COMMA_IF(i) BOOST_PP_TUPLE_ELEM(1, BOOST_PP_TUPLE_PUSH_FRONT(x,)) BOOST_PP_TUPLE_ELEM(2, BOOST_PP_TUPLE_PUSH_FRONT(x,))
#define BB_VTABLE_TYPE(r, data, i, x) BOOST_PP_COMMA_IF(i) BOOST_PP_TUPLE_ELEM(1, BOOST_PP_TUPLE_PUSH_FRONT(x,))
#define BB_VTABLE_NAME(r, data, i, x) BOOST_PP_COMMA_IF(i) BOOST_PP_TUPLE_ELEM(2, BOOST_PP_TUPLE_PUSH_FRONT(x,))
#define BB_VTABLE_FOR_EACH(macro, seq) BOOST_PP_SEQ_FOR_EACH_I(macro, _, seq)

#define BB_VTABLE_FUNCTION_PTR(virtual, returnType, type, function, location, override, seq) \
    virtual returnType function(BB_VTABLE_FOR_EACH(BB_VTABLE_TYPE_AND_NAME, seq)) override \
    { \
        return ((returnType(__thiscall*)(type BOOST_PP_COMMA_IF(BB_VTABLE_HAS_ARGS(seq)) BB_VTABLE_FOR_EACH(BB_VTABLE_TYPE, seq))) \
            (location))(this BOOST_PP_COMMA_IF(BB_VTABLE_HAS_ARGS(seq)) BB_VTABLE_FOR_EACH(BB_VTABLE_NAME, seq)); \
    }

#define BB_VIRTUAL_FUNCTION_PTR(returnType, function, location, ...) \
    BB_VTABLE_FUNCTION_PTR(virtual, returnType, decltype(this), function, location, , BOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__))

#define BB_OVERRIDE_FUNCTION_PTR(returnType, baseType, function, location, ...) \
    BB_VTABLE_FUNCTION_PTR(, returnType, baseType*, function, location, override, BOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__))

template<int TActual, int TExpected>
struct bb_assert_offsetof
{
    static_assert(TActual == TExpected, "offsetof assertion failed");
};

template<int TActual, int TExpected>
struct bb_assert_sizeof
{
    static_assert(TActual == TExpected, "sizeof assertion failed");
};

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

namespace boost
{
    typedef boost::shared_ptr<void> anonymous_shared_ptr;
}