#ifndef _NBL_BUILTIN_HLSL_CPP_COMPAT_IMPL_INTRINSICS_IMPL_INCLUDED_
#define _NBL_BUILTIN_HLSL_CPP_COMPAT_IMPL_INTRINSICS_IMPL_INCLUDED_

#include <nbl/builtin/hlsl/cpp_compat/basic.h>
#include <nbl/builtin/hlsl/matrix_utils/matrix_traits.hlsl>
#include <nbl/builtin/hlsl/matrix_utils/mul_output_t.hlsl>
#include <nbl/builtin/hlsl/concepts.hlsl>
#include <nbl/builtin/hlsl/spirv_intrinsics/core.hlsl>
#include <nbl/builtin/hlsl/spirv_intrinsics/glsl.std.450.hlsl>
#include <nbl/builtin/hlsl/ieee754.hlsl>
#include <nbl/builtin/hlsl/concepts/core.hlsl>
#include <nbl/builtin/hlsl/concepts/vector.hlsl>
#include <nbl/builtin/hlsl/concepts/matrix.hlsl>
#include <nbl/builtin/hlsl/cpp_compat/promote.hlsl>
#ifndef __HLSL_VERSION
#include <bitset>
#endif

namespace nbl
{
namespace hlsl
{
namespace cpp_compat_intrinsics_impl
{

template<typename T NBL_STRUCT_CONSTRAINABLE>
struct dot_helper;
template<typename T NBL_STRUCT_CONSTRAINABLE>
struct cross_helper;
template<typename T, typename U NBL_STRUCT_CONSTRAINABLE>
struct clamp_helper;
template<typename Integer NBL_STRUCT_CONSTRAINABLE>
struct find_msb_helper;
template<typename Integer NBL_STRUCT_CONSTRAINABLE>
struct find_lsb_helper;
template<typename T NBL_STRUCT_CONSTRAINABLE>
struct bitReverse_helper;
template<typename Matrix NBL_STRUCT_CONSTRAINABLE>
struct transpose_helper;
template<typename Vector NBL_STRUCT_CONSTRAINABLE>
struct length_helper;
template<typename Vector NBL_STRUCT_CONSTRAINABLE>
struct normalize_helper;
template<typename T NBL_STRUCT_CONSTRAINABLE>
struct max_helper;
template<typename T NBL_STRUCT_CONSTRAINABLE>
struct min_helper;
template<typename Integer NBL_STRUCT_CONSTRAINABLE>
struct bitCount_helper;
template<typename LhsT, typename RhsT NBL_STRUCT_CONSTRAINABLE>
struct mul_helper;
template<typename T NBL_STRUCT_CONSTRAINABLE>
struct determinant_helper;
template<typename T NBL_STRUCT_CONSTRAINABLE>
struct inverse_helper;
template<typename T NBL_STRUCT_CONSTRAINABLE>
struct rsqrt_helper;
template<typename T NBL_STRUCT_CONSTRAINABLE>
struct all_helper;
template<typename T NBL_STRUCT_CONSTRAINABLE>
struct any_helper;
template<typename T, uint16_t Bits NBL_STRUCT_CONSTRAINABLE>
struct bitReverseAs_helper;
template<typename T NBL_STRUCT_CONSTRAINABLE>
struct frac_helper;

#ifdef __HLSL_VERSION // HLSL only specializations
template<typename T, typename U> NBL_PARTIAL_REQ_TOP(always_true<decltype(spirv::fClamp<T>(experimental::declval<T>(), experimental::declval<U>(), experimental::declval<U>()))>)
struct clamp_helper<T, U NBL_PARTIAL_REQ_BOT(always_true<decltype(spirv::fClamp<T>(experimental::declval<T>(), experimental::declval<U>(), experimental::declval<U>()))>) >
{
	using return_t = T;
	static return_t __call(NBL_CONST_REF_ARG(T) val, NBL_CONST_REF_ARG(U) min, NBL_CONST_REF_ARG(U) max)
	{
		return spirv::fClamp(val, min, max);
	}
};
template<typename T, typename U> NBL_PARTIAL_REQ_TOP(always_true<decltype(spirv::uClamp<T>(experimental::declval<T>(), experimental::declval<U>(), experimental::declval<U>()))>)
struct clamp_helper<T, U NBL_PARTIAL_REQ_BOT(always_true<decltype(spirv::uClamp<T>(experimental::declval<T>(), experimental::declval<U>(), experimental::declval<U>()))>) >
{
	using return_t = T;
	static return_t __call(NBL_CONST_REF_ARG(T) val, NBL_CONST_REF_ARG(U) min, NBL_CONST_REF_ARG(U) max)
	{
		return spirv::uClamp(val, min, max);
	}
};
template<typename T, typename U> NBL_PARTIAL_REQ_TOP(always_true<decltype(spirv::sClamp<T>(experimental::declval<T>(), experimental::declval<U>(), experimental::declval<U>()))>)
struct clamp_helper<T, U NBL_PARTIAL_REQ_BOT(always_true<decltype(spirv::sClamp<T>(experimental::declval<T>(), experimental::declval<U>(), experimental::declval<U>()))>) >
{
	using return_t = T;
	static return_t __call(NBL_CONST_REF_ARG(T) val, NBL_CONST_REF_ARG(U) min, NBL_CONST_REF_ARG(U) max)
	{
		return spirv::sClamp(val, min, max);
	}
};

#define AUTO_SPECIALIZE_TRIVIAL_CASE_HELPER(HELPER_NAME, SPIRV_FUNCTION_NAME, RETURN_TYPE)\
template<typename T> NBL_PARTIAL_REQ_TOP(always_true<decltype(spirv::SPIRV_FUNCTION_NAME<T>(experimental::declval<T>()))>)\
struct HELPER_NAME<T NBL_PARTIAL_REQ_BOT(always_true<decltype(spirv::SPIRV_FUNCTION_NAME<T>(experimental::declval<T>()))>) >\
{\
	using return_t = RETURN_TYPE;\
	static inline return_t __call(const T arg)\
	{\
		return spirv::SPIRV_FUNCTION_NAME<T>(arg);\
	}\
};

#define FIND_MSB_LSB_RETURN_TYPE conditional_t<is_vector_v<T>, vector<int32_t, vector_traits<T>::Dimension>, int32_t>;
AUTO_SPECIALIZE_TRIVIAL_CASE_HELPER(find_msb_helper, findUMsb, FIND_MSB_LSB_RETURN_TYPE)
AUTO_SPECIALIZE_TRIVIAL_CASE_HELPER(find_msb_helper, findSMsb, FIND_MSB_LSB_RETURN_TYPE)
AUTO_SPECIALIZE_TRIVIAL_CASE_HELPER(find_lsb_helper, findILsb, FIND_MSB_LSB_RETURN_TYPE)
#undef FIND_MSB_LSB_RETURN_TYPE
AUTO_SPECIALIZE_TRIVIAL_CASE_HELPER(bitReverse_helper, bitReverse, T)
AUTO_SPECIALIZE_TRIVIAL_CASE_HELPER(transpose_helper, transpose, T)
AUTO_SPECIALIZE_TRIVIAL_CASE_HELPER(length_helper, length, T)
AUTO_SPECIALIZE_TRIVIAL_CASE_HELPER(normalize_helper, normalize, T)
AUTO_SPECIALIZE_TRIVIAL_CASE_HELPER(rsqrt_helper, inverseSqrt, T)
AUTO_SPECIALIZE_TRIVIAL_CASE_HELPER(frac_helper, fract, T)

template<typename UInt64> NBL_PARTIAL_REQ_TOP(is_same_v<UInt64, uint64_t>)
struct find_msb_helper<UInt64 NBL_PARTIAL_REQ_BOT(is_same_v<UInt64, uint64_t>) >
{
	using return_t = int32_t;
	static return_t __call(NBL_CONST_REF_ARG(UInt64) val)
	{
		const uint32_t highBits = uint32_t(val >> 32);
		const int32_t highMsb = find_msb_helper<uint32_t>::__call(highBits);

		if (highMsb == -1)
		{
			const uint32_t lowBits = uint32_t(val);
			const int32_t lowMsb = find_msb_helper<uint32_t>::__call(lowBits);
			if (lowMsb == -1)
				return -1;

			return lowMsb;
		}

		return highMsb + 32;
	}
};
template<typename UInt64> NBL_PARTIAL_REQ_TOP(is_same_v<UInt64, uint64_t>)
struct find_lsb_helper<UInt64 NBL_PARTIAL_REQ_BOT(is_same_v<UInt64, uint64_t>) >
{
	static int32_t __call(NBL_CONST_REF_ARG(uint64_t) val)
	{
		const uint32_t lowBits = uint32_t(val);
		const int32_t lowLsb = find_lsb_helper<uint32_t>::__call(lowBits);

		if (lowLsb == -1)
		{
			const uint32_t highBits = uint32_t(val >> 32);
			const int32_t highLsb = find_lsb_helper<uint32_t>::__call(highBits);
			if (highLsb == -1)
				return -1;
			else
				return 32 + highLsb;
		}

		return lowLsb;
	}
};

#define AUTO_SPECIALIZE_TRIVIAL_CASE_HELPER_2_ARG_FUNC(HELPER_NAME, SPIRV_FUNCTION_NAME, RETURN_TYPE)\
template<typename T> NBL_PARTIAL_REQ_TOP(always_true<decltype(spirv::SPIRV_FUNCTION_NAME<T>(experimental::declval<T>()))>)\
struct HELPER_NAME<T NBL_PARTIAL_REQ_BOT(always_true<decltype(spirv::SPIRV_FUNCTION_NAME<T>(experimental::declval<T>()))>) >\
{\
	using return_t = RETURN_TYPE;\
	static inline return_t __call(const T a, const T b)\
	{\
		return spirv::SPIRV_FUNCTION_NAME<T>(a, b);\
	}\
};

AUTO_SPECIALIZE_TRIVIAL_CASE_HELPER_2_ARG_FUNC(max_helper, fMax, T)
AUTO_SPECIALIZE_TRIVIAL_CASE_HELPER_2_ARG_FUNC(max_helper, uMax, T)
AUTO_SPECIALIZE_TRIVIAL_CASE_HELPER_2_ARG_FUNC(max_helper, sMax, T)
AUTO_SPECIALIZE_TRIVIAL_CASE_HELPER_2_ARG_FUNC(min_helper, fMax, T)
AUTO_SPECIALIZE_TRIVIAL_CASE_HELPER_2_ARG_FUNC(min_helper, uMax, T)
AUTO_SPECIALIZE_TRIVIAL_CASE_HELPER_2_ARG_FUNC(min_helper, sMax, T)

#else // C++ only specializations

template<typename T>
requires concepts::Scalar<T>
struct clamp_helper<T, T>
{
	using return_t = T;
	static inline return_t __call(const T val, const T min, const T max)
	{
		return std::clamp(val, min, max);
	}
};
template<typename T>
requires concepts::IntegralScalar<T>
struct bitReverse_helper<T>
{
	static inline T __call(NBL_CONST_REF_ARG(T) arg)
	{
		return glm::bitfieldReverse(arg);
	}
};
template<typename Matrix>
requires concepts::Matrix<Matrix>
struct transpose_helper<Matrix>
{
	using transposed_t = typename matrix_traits<Matrix>::transposed_type;

	static transposed_t __call(NBL_CONST_REF_ARG(Matrix) m)
	{
		return reinterpret_cast<transposed_t&>(glm::transpose(reinterpret_cast<typename Matrix::Base const&>(m)));
	}
};
template<typename Vector>
requires concepts::FloatingPointVector<Vector>
struct length_helper<Vector>
{
	static inline typename vector_traits<Vector>::scalar_type __call(NBL_CONST_REF_ARG(Vector) vec)
	{
		return std::sqrt(dot_helper<Vector>::__call(vec, vec));
	}
};
template<typename Vectorial>
requires concepts::FloatingPointLikeVectorial<Vectorial>
struct normalize_helper<Vectorial>
{
	static inline Vectorial __call(NBL_CONST_REF_ARG(Vectorial) vec)
	{
		return vec / length_helper<Vectorial>::__call(vec);
	}
};
template<typename T>
requires concepts::Scalar<T>
struct max_helper<T>
{
	static T __call(NBL_CONST_REF_ARG(T) a, NBL_CONST_REF_ARG(T) b)
	{
		return std::max(a, b);
	}
};
template<typename T>
requires concepts::Scalar<T>
struct min_helper<T>
{
	static T __call(NBL_CONST_REF_ARG(T) a, NBL_CONST_REF_ARG(T) b)
	{
		return std::min(a, b);
	}
};
template<typename T>
requires concepts::IntegralScalar<T>
struct find_lsb_helper<T>
{
	using return_t = int32_t;
	static inline T __call(const T arg)
	{
		return glm::findLSB(arg);
	}
};
template<typename Integer>
NBL_PARTIAL_REQ_TOP(concepts::IntegralScalar<Integer>)
struct find_msb_helper<Integer NBL_PARTIAL_REQ_BOT(concepts::IntegralScalar<Integer>) >
{
	using return_t = int32_t;
	static return_t __call(NBL_CONST_REF_ARG(Integer) val)
	{
		return glm::findMSB(val);
	}
};
template<typename EnumType>
requires std::is_enum_v<EnumType>
struct find_lsb_helper<EnumType>
{
	using return_t = int32_t;
	static int32_t __call(NBL_CONST_REF_ARG(EnumType) val)
	{
		using underlying_t = std::underlying_type_t<EnumType>;
		return find_lsb_helper<underlying_t>::__call(static_cast<underlying_t>(val));
	}
};
template<typename EnumType>
requires std::is_enum_v<EnumType>
struct find_msb_helper<EnumType>
{
	using return_t = int32_t;
	static return_t __call(NBL_CONST_REF_ARG(EnumType) val)
	{
		using underlying_t = std::underlying_type_t<EnumType>;
		return find_msb_helper<underlying_t>::__call(static_cast<underlying_t>(val));
	}
};

template<typename FloatingPoint>
requires concepts::FloatingPointScalar<FloatingPoint>
struct rsqrt_helper<FloatingPoint>
{
	static FloatingPoint __call(NBL_CONST_REF_ARG(FloatingPoint) x)
	{
		// TODO: https://stackoverflow.com/a/62239778
		return 1.0f / std::sqrt(x);
	}
};

template<typename T>
requires concepts::FloatingPointScalar<T>
struct frac_helper<T>
{
	using return_t = T;
	static inline return_t __call(const T x)
	{
		return x - std::floor(x);
	}
};

#endif // C++ only specializations

// C++ and HLSL specializations

template<typename T, uint16_t Bits>
NBL_PARTIAL_REQ_TOP(concepts::UnsignedIntegralScalar<T> && (Bits <= sizeof(T) * 8))
struct bitReverseAs_helper<T, Bits NBL_PARTIAL_REQ_BOT(concepts::UnsignedIntegralScalar<T> && (Bits <= sizeof(T) * 8)) >
{
	static T __call(NBL_CONST_REF_ARG(T) val)
	{
		return bitReverse_helper<T>::__call(val) >> promote<T, scalar_type_t<T> >(scalar_type_t <T>(sizeof(T) * 8 - Bits));
	}

	static T __call(NBL_CONST_REF_ARG(T) val, uint16_t bits)
	{
		return bitReverse_helper<T>::__call(val) >> promote<T, scalar_type_t<T> >(scalar_type_t <T>(sizeof(T) * 8 - bits));
	}
};

template<typename Vectorial>
NBL_PARTIAL_REQ_TOP(concepts::Vectorial<Vectorial>)
struct dot_helper<Vectorial NBL_PARTIAL_REQ_BOT(concepts::Vectorial<Vectorial>) >
{
	using scalar_type = typename vector_traits<Vectorial>::scalar_type;

	static inline scalar_type __call(NBL_CONST_REF_ARG(Vectorial) lhs, NBL_CONST_REF_ARG(Vectorial) rhs)
	{
		static const uint32_t ArrayDim = vector_traits<Vectorial>::Dimension;
		static array_get<Vectorial, scalar_type> getter;

		scalar_type retval = getter(lhs, 0) * getter(rhs, 0);
		for (uint32_t i = 1; i < ArrayDim; ++i)
			retval = retval + getter(lhs, i) * getter(rhs, i);

		return retval;
	}
};
template<typename FloatingPointLikeVectorial>
NBL_PARTIAL_REQ_TOP(concepts::FloatingPointLikeVectorial<FloatingPointLikeVectorial> && (vector_traits<FloatingPointLikeVectorial>::Dimension == 3))
struct cross_helper<FloatingPointLikeVectorial NBL_PARTIAL_REQ_BOT(concepts::FloatingPointLikeVectorial<FloatingPointLikeVectorial> && (vector_traits<FloatingPointLikeVectorial>::Dimension == 3)) >
{
	static FloatingPointLikeVectorial __call(NBL_CONST_REF_ARG(FloatingPointLikeVectorial) lhs, NBL_CONST_REF_ARG(FloatingPointLikeVectorial) rhs)
	{
#ifdef __HLSL_VERSION
		if (hlsl::is_vector_v<FloatingPointLikeVectorial>)
			return spirv::cross(lhs, rhs);
#else
		using traits = hlsl::vector_traits<FloatingPointLikeVectorial>;
		array_get<FloatingPointLikeVectorial, typename traits::scalar_type> getter;
		array_set<FloatingPointLikeVectorial, typename traits::scalar_type> setter;

		FloatingPointLikeVectorial output;
		setter(output, 0, getter(lhs, 1) * getter(rhs, 2) - getter(rhs, 1) * getter(lhs, 2));
		setter(output, 1, getter(lhs, 2) * getter(rhs, 0) - getter(rhs, 2) * getter(lhs, 0));
		setter(output, 2, getter(lhs, 0) * getter(rhs, 1) - getter(rhs, 0) * getter(lhs, 1));

		return output;
#endif
	}
};

template<typename Vector>
NBL_PARTIAL_REQ_TOP(is_vector_v<Vector>)
struct clamp_helper<Vector, typename vector_traits<Vector>::scalar_type NBL_PARTIAL_REQ_BOT(is_vector_v<Vector>) >
{
	using return_t = Vector;
	static return_t __call(NBL_CONST_REF_ARG(Vector) val, NBL_CONST_REF_ARG(typename vector_traits<Vector>::scalar_type) min, NBL_CONST_REF_ARG(typename vector_traits<Vector>::scalar_type) max)
	{
		using traits = hlsl::vector_traits<Vector>;
		array_get<Vector, typename traits::scalar_type> getter;
		array_set<return_t, typename traits::scalar_type> setter;

		return_t output;
		for (uint32_t i = 0; i < traits::Dimension; ++i)
			setter(output, i, clamp_helper<typename traits::scalar_type, typename traits::scalar_type>::__call(getter(val, i), min, max));

		return output;
	}
};

template<typename Vector>
NBL_PARTIAL_REQ_TOP(hlsl::is_vector_v<Vector>)
struct bitReverse_helper<Vector NBL_PARTIAL_REQ_BOT(concepts::Vectorial<Vector>) >
{
	static Vector __call(NBL_CONST_REF_ARG(Vector) vec)
	{
#ifdef __HLSL_VERSION
		return spirv::bitReverse(vec);
#else
		Vector output;
		using traits = hlsl::vector_traits<Vector>;
		for (uint32_t i = 0; i < traits::Dimension; ++i)
			output[i] = bitReverse_helper<traits::scalar_type>::__call(vec[i]);
		return output;
#endif
	}
};

template<typename Vector>
NBL_PARTIAL_REQ_TOP(is_vector_v<Vector>)
struct min_helper<Vector NBL_PARTIAL_REQ_BOT(is_vector_v<Vector>) >
{
	static Vector __call(NBL_CONST_REF_ARG(Vector) a, NBL_CONST_REF_ARG(Vector) b)
	{
		using traits = hlsl::vector_traits<Vector>;
		array_get<Vector, typename traits::scalar_type> getter;
		array_set<Vector, typename traits::scalar_type> setter;

		Vector output;
		for (uint32_t i = 0; i < traits::Dimension; ++i)
			setter(output, i, min_helper<typename traits::scalar_type>::__call(getter(a, i), getter(b, i)));

		return output;
	}
};
template<typename Vector>
NBL_PARTIAL_REQ_TOP(concepts::Vectorial<Vector>)
struct max_helper<Vector NBL_PARTIAL_REQ_BOT(concepts::Vectorial<Vector>) >
{
	static Vector __call(NBL_CONST_REF_ARG(Vector) a, NBL_CONST_REF_ARG(Vector) b)
	{
		using traits = hlsl::vector_traits<Vector>;
		array_get<Vector, typename traits::scalar_type> getter;
		array_set<Vector, typename traits::scalar_type> setter;

		Vector output;
		for (uint32_t i = 0; i < traits::Dimension; ++i)
			setter(output, i, max_helper<typename traits::scalar_type>::__call(getter(a, i), getter(b, i)));

		return output;
	}
};

template<typename Integer>
NBL_PARTIAL_REQ_TOP(concepts::IntegralScalar<Integer>)
struct bitCount_helper<Integer NBL_PARTIAL_REQ_BOT(concepts::IntegralScalar<Integer>) >
{
	using return_t = int32_t;
	static return_t __call(NBL_CONST_REF_ARG(Integer) val)
	{
#ifdef __HLSL_VERSION
		if (sizeof(Integer) == 8u)
		{
			uint32_t lowBits = uint32_t(val);
			uint32_t highBits = uint32_t(uint64_t(val) >> 32u);

			return countbits(lowBits) + countbits(highBits);
		}

		return spirv::bitCount(val);
#else
		using UnsignedInteger = typename hlsl::unsigned_integer_of_size_t<sizeof(Integer)>;
		constexpr int32_t BitCnt = sizeof(Integer) * 8u;
		std::bitset<BitCnt> bitset(static_cast<UnsignedInteger>(val));
		return bitset.count();
#endif
	}
};

template<typename LhsT, typename RhsT>
NBL_PARTIAL_REQ_TOP(concepts::Matrix<LhsT> && (concepts::Matrix<RhsT> || concepts::Vector<RhsT>))
struct mul_helper<LhsT, RhsT NBL_PARTIAL_REQ_BOT(concepts::Matrix<LhsT> && (concepts::Matrix<RhsT> || concepts::Vector<RhsT>)) >
{
	static inline mul_output_t<LhsT, RhsT> __call(LhsT lhs, RhsT rhs)
	{
		return mul(lhs, rhs);
	}
};

template<typename SquareMatrix>
NBL_PARTIAL_REQ_TOP(matrix_traits<SquareMatrix>::Square)
struct determinant_helper<SquareMatrix NBL_PARTIAL_REQ_BOT(matrix_traits<SquareMatrix>::Square) >
{
	static typename matrix_traits<SquareMatrix>::scalar_type __call(NBL_CONST_REF_ARG(SquareMatrix) mat)
	{
#ifdef __HLSL_VERSION
		spirv::determinant(mat);
#else
		return glm::determinant(reinterpret_cast<typename SquareMatrix::Base const&>(mat));
#endif
	}
};

template<typename SquareMatrix>
NBL_PARTIAL_REQ_TOP(concepts::Matrix<SquareMatrix>&& matrix_traits<SquareMatrix>::Square)
struct inverse_helper<SquareMatrix NBL_PARTIAL_REQ_BOT(concepts::Matrix<SquareMatrix>&& matrix_traits<SquareMatrix>::Square) >
{
	static SquareMatrix __call(NBL_CONST_REF_ARG(SquareMatrix) mat)
	{
#ifdef __HLSL_VERSION
		return spirv::matrixInverse(mat);
#else
		return reinterpret_cast<SquareMatrix&>(glm::inverse(reinterpret_cast<typename SquareMatrix::Base const&>(mat)));
#endif
	}
};

#define AUTO_SPECIALIZE_HELPER_FOR_VECTOR(HELPER_NAME, REQUIREMENT, RETURN_TYPE)\
template<typename T>\
NBL_PARTIAL_REQ_TOP(REQUIREMENT)\
struct HELPER_NAME<T NBL_PARTIAL_REQ_BOT(REQUIREMENT) >\
{\
	using return_t = RETURN_TYPE;\
	static return_t __call(NBL_CONST_REF_ARG(T) vec)\
	{\
		using traits = hlsl::vector_traits<T>;\
		array_get<T, typename traits::scalar_type> getter;\
		array_set<T, typename traits::scalar_type> setter;\
\
		return_t output;\
		for (uint32_t i = 0; i < traits::Dimension; ++i)\
			setter(output, i, HELPER_NAME<typename traits::scalar_type>::__call(getter(vec, i)));\
\
		return output;\
	}\
};

#ifdef __HLSL_VERSION
// SPIR-V already defines specializations for builtin vector types
#define VECTOR_SPECIALIZATION_CONCEPT concepts::Vectorial<T> && !is_vector_v<T>
#else
#define VECTOR_SPECIALIZATION_CONCEPT concepts::Vectorial<T>
#endif

AUTO_SPECIALIZE_HELPER_FOR_VECTOR(rsqrt_helper, concepts::FloatingPointVectorial<T> && VECTOR_SPECIALIZATION_CONCEPT, T)
AUTO_SPECIALIZE_HELPER_FOR_VECTOR(frac_helper, VECTOR_SPECIALIZATION_CONCEPT,T)
#define INT32_VECTOR_TYPE vector<int32_t, hlsl::vector_traits<T>::Dimension>
AUTO_SPECIALIZE_HELPER_FOR_VECTOR(bitCount_helper, VECTOR_SPECIALIZATION_CONCEPT, INT32_VECTOR_TYPE)
AUTO_SPECIALIZE_HELPER_FOR_VECTOR(find_msb_helper, VECTOR_SPECIALIZATION_CONCEPT, INT32_VECTOR_TYPE)
AUTO_SPECIALIZE_HELPER_FOR_VECTOR(find_lsb_helper, VECTOR_SPECIALIZATION_CONCEPT, INT32_VECTOR_TYPE)
#undef INT32_VECTOR_TYPE
#undef AUTO_SPECIALIZE_HELPER_FOR_VECTOR

#ifndef __HLSL_VERSION
template<typename EnumT>
requires std::is_enum_v<EnumT>
struct bitCount_helper<EnumT>
{
	using return_t = int32_t;
	using underlying_t = std::underlying_type_t<EnumT>;
	static return_t __call(NBL_CONST_REF_ARG(EnumT) val)
	{
		return bitCount_helper<const underlying_t>::__call(reinterpret_cast<const underlying_t&>(val));
	}
};
#endif

template<typename BooleanVector>
NBL_PARTIAL_REQ_TOP(is_vector_v<BooleanVector>&& is_same_v<typename vector_traits<BooleanVector>::scalar_type, bool>)
struct all_helper<BooleanVector NBL_PARTIAL_REQ_BOT(is_vector_v<BooleanVector>&& is_same_v<typename vector_traits<BooleanVector>::scalar_type, bool>) >
{
	static bool __call(NBL_CONST_REF_ARG(BooleanVector) x)
	{
		using traits = hlsl::vector_traits<BooleanVector>;
		array_get<BooleanVector, typename traits::scalar_type> getter;
		array_set<BooleanVector, typename traits::scalar_type> setter;

		bool output = true;
		for (uint32_t i = 0; i < traits::Dimension; ++i)
			output = output && getter(x, i);

		return output;
	}
};

template<typename BooleanVector>
NBL_PARTIAL_REQ_TOP(is_vector_v<BooleanVector>&& is_same_v<typename vector_traits<BooleanVector>::scalar_type, bool>)
struct any_helper<BooleanVector NBL_PARTIAL_REQ_BOT(is_vector_v<BooleanVector>&& is_same_v<typename vector_traits<BooleanVector>::scalar_type, bool>) >
{
	static bool __call(NBL_CONST_REF_ARG(BooleanVector) x)
	{
		using traits = hlsl::vector_traits<BooleanVector>;
		array_get<BooleanVector, typename traits::scalar_type> getter;
		array_set<BooleanVector, typename traits::scalar_type> setter;

		bool output = false;
		for (uint32_t i = 0; i < traits::Dimension; ++i)
			output = output || getter(x, i);

		return output;
	}
};

}
}
}

#endif