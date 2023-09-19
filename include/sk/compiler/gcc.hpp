// This header is inspired and heavily based on the one from boost::config.
// https://www.boost.org/libs/config

#ifndef SK_COMPILER_GCC_HPP
#define SK_COMPILER_GCC_HPP

#define SK_COMPILER     "gcc"
#define SK_COMPILER_GCC 1
#define SK_GCC_VERSION \
    (__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__)


// CXX11 check.
#if defined(__GXX_EXPERIMENTAL_CXX0X__) || \
           (__cplusplus >= 201103L)
#define SK_GCC_CXX11
#endif


#if __GNUC__ == 3
#  if defined(__PATHSCALE__)
#    define SK_NO_TWO_PHASE_NAME_LOOKUP
#    define SK_NO_IS_ABSTRACT
#  endif
#  if __GNUC__MINOR < 4
#    define SK_NO_IS_ABSTRACT
#  endif
#  define SK_NO_CXX11_EXTERN_TEMPLATE
#endif


#if __GNUC__ == 4
#  define SK_NO_TWO_PHASE_NAME_LOOKUP
#  ifdef __OPEN64__
#    define SK_NO_IS_ABSTRACT
#  endif
#endif


// Before this version, didn't work with symlinks.
#if SK_GCC_VERSION >= 30400
#  define SK_HAS_PRAGMA_ONCE
#endif


// Previous versions of GCC did not completely implement value-initialization:
// GCC Bug 30111, "Value-initialization of POD base class doesn't initialize
// members", reported by Jonathan Wakely in 2006,
// http://gcc.gnu.org/bugzilla/show_bug.cgi?id=30111 (fixed for GCC 4.4)
// GCC Bug 33916, "Default constructor fails to initialize array members",
// reported by Michael Elizabeth Chastain in 2007,
// http://gcc.gnu.org/bugzilla/show_bug.cgi?id=33916 (fixed for GCC 4.2.4)
// See also: http://www.boost.org/libs/utility/value_init.htm#compiler_issues
#if SK_GCC_VERSION < 40400
#define SK_NO_COMPLETE_VALUE_INITIALIZATION
#endif


#if !defined(__EXCEPTIONS) && \
    !defined(SK_NO_EXCEPTIONS)
#define SK_NO_EXCEPTIONS
#endif


#if !defined(__MINGW32__) && \
    !defined(linux)       && \
    !defined(__linux)     && \
    !defined(__linux__)
#define SK_HAS_THREADS
#endif


#if !defined(__DARWIN_NO_LONG_LONG)
#  define SK_HAS_LONG_LONG
#endif


#define SK_HAS_NRVO
#define SK_LIKELY(x)   __builtin_expect(x, 1)
#define SK_UNLIKELY(x) __builtin_expect(x, 0)


#if __GNUC__ >= 4
#  if defined(_WIN32) || defined(__WIN32__) || defined(WIN32) || defined(__CYGWIN__)
#    define SK_HAS_DECLSPEC
#    define SK_SYMBOL_EXPORT __attribute__((__dllexport__))
#    define SK_SYMBOL_IMPORT __attribute__((__dllimport__))
#  else
#    define SK_SYMBOL_EXPORT __attribute__((__visibility__("default")))
#    define SK_SYMBOL_IMPORT
#  endif
#  define SK_SYMBOL_VISIBLE __attribute__((__visibility__("default")))
#else
#  define SK_SYMBOL_EXPORT
#endif


#if SK_GCC_VERSION > 40300
#  ifndef __GXX_RTTI
#    ifndef SK_NO_TYPEID
#      define SK_NO_TYPEID
#    endif
#    ifndef SK_NO_RTTI
#      define SK_NO_RTTI
#    endif
#  endif
#endif


#if defined(__SIZEOF_INT128__)
#  define SK_HAS_INT128
#endif


#ifdef __cplusplus
#include <cstddef>
#else
#include <stddef.h>
#endif
#if defined(_GLIBCXX_USE_FLOAT128) && \
    !defined(__STRICT_ANSI__)
#define SK_HAS_FLOAT128
#endif


#if (SK_GCC_VERSION >= 40300) && defined(SK_GCC_CXX11)
#  define SK_HAS_DECLTYPE
#  define SK_HAS_RVALUE_REFS
#  define SK_HAS_STATIC_ASSERT
#  define SK_HAS_VARIADIC_TEMPLATES
#else
#  define SK_NO_CXX11_DECLTYPE
#  define SK_NO_CXX11_RVALUE_REFS
#  define SK_NO_CXX11_STATIC_ASSERT
#  define SK_NO_CXX11_VARIADIC_TEMPLATES
#endif


#if (SK_GCC_VERSION < 40400) || !defined(SK_GCC_CXX11) 
#  define SK_NO_CXX11_AUTO_DECLARATIONS
#  define SK_NO_CXX11_AUTO_MULTIDECLARATIONS
#  define SK_NO_CXX11_CHAR16_T
#  define SK_NO_CXX11_CHAR32_T
#  define SK_NO_CXX11_HDR_INITIALIZER_LIST
#  define SK_NO_CXX11_DEFAULTED_FUNCTIONS
#  define SK_NO_CXX11_DELETED_FUNCTIONS
#  define SK_NO_CXX11_TRAILING_RESULT_TYPES
#  define SK_NO_CXX11_INLINE_NAMESPACES
#  define SK_NO_CXX11_VARIADIC_TEMPLATES
#endif


#if SK_GCC_VERSION < 40500
#  define SK_NO_SFINAE_EXPR
#endif


// GCC 4.5 forbids declaration of defaulted functions in private or protected sections
#if __GNUC__ < 4 || (__GNUC__ == 4 && __GNUC_MINOR__ == 5) || !defined(SK_GCC_CXX11)
#  define SK_NO_CXX11_NON_PUBLIC_DEFAULTED_FUNCTIONS
#endif


#if (SK_GCC_VERSION < 40500) || !defined(SK_GCC_CXX11)
#  define SK_NO_CXX11_EXPLICIT_CONVERSION_OPERATORS
#  define SK_NO_CXX11_LAMBDAS
#  define SK_NO_CXX11_LOCAL_CLASS_TEMPLATE_PARAMETERS
#  define SK_NO_CXX11_RAW_LITERALS
#  define SK_NO_CXX11_UNICODE_LITERALS
#  define SK_NO_CXX11_ALIGNOF
#endif


#if (SK_GCC_VERSION < 40501) || !defined(SK_GCC_CXX11)
// scoped enums have a serious bug in 4.4.0, so define SK_NO_CXX11_SCOPED_ENUMS before 4.5.1
// See http://gcc.gnu.org/bugzilla/show_bug.cgi?id=38064
#  define SK_NO_CXX11_SCOPED_ENUMS
#endif


#if (SK_GCC_VERSION < 40600) || !defined(SK_GCC_CXX11)
#  define SK_NO_CXX11_DEFAULTED_MOVES
#  define SK_NO_CXX11_NOEXCEPT
#  define SK_NO_CXX11_NULLPTR
#  define SK_NO_CXX11_RANGE_BASED_FOR
#  define SK_NO_CXX11_UNIFIED_INITIALIZATION_SYNTAX
#endif


#if (SK_GCC_VERSION < 40700) || !defined(SK_GCC_CXX11)
// Note that while constexpr is partly supported in gcc-4.6 it's a 
// pre-std version with several bugs:
#  define SK_NO_CXX11_CONSTEXPR
#  define SK_NO_CXX11_FINAL
#  define SK_NO_CXX11_TEMPLATE_ALIASES
#  define SK_NO_CXX11_USER_DEFINED_LITERALS
#  define SK_NO_CXX11_FIXED_LENGTH_VARIADIC_TEMPLATE_EXPANSION_PACKS
#  define SK_NO_CXX11_OVERRIDE
#endif


#if (SK_GCC_VERSION < 40800) || !defined(SK_GCC_CXX11)
#  define SK_NO_CXX11_THREAD_LOCAL
#  define SK_NO_CXX11_SFINAE_EXPR
#endif


#if (SK_GCC_VERSION < 40801) || !defined(SK_GCC_CXX11)
#  define SK_NO_CXX11_DECLTYPE_N3276
#  define SK_NO_CXX11_REF_QUALIFIERS
#  define SK_NO_CXX14_BINARY_LITERALS
#endif


#if (SK_GCC_VERSION < 40900) || !defined(SK_GCC_CXX11)
// Although alignas support is added in gcc 4.8, it does not accept
// dependent constant expressions as an argument until gcc 4.9.
#  define SK_NO_CXX11_ALIGNAS
#endif


#if (SK_GCC_VERSION < 50100) || !defined(SK_GCC_CXX11)
#  define SK_NO_CXX11_UNRESTRICTED_UNION
#endif


#if (SK_GCC_VERSION < 40900) || (__cplusplus < 201300)
#  define SK_NO_CXX14_RETURN_TYPE_DEDUCTION
#  define SK_NO_CXX14_GENERIC_LAMBDAS
#  define SK_NO_CXX14_DIGIT_SEPARATORS
#  define SK_NO_CXX14_DECLTYPE_AUTO
#  if !((SK_GCC_VERSION >= 40801) && (SK_GCC_VERSION < 40900) && defined(SK_GCC_CXX11))
#     define SK_NO_CXX14_INITIALIZED_LAMBDA_CAPTURES
#  endif
#endif


#if !defined(__cpp_aggregate_nsdmi) || (__cpp_aggregate_nsdmi < 201304)
#  define SK_NO_CXX14_AGGREGATE_NSDMI
#endif
#if !defined(__cpp_constexpr) || (__cpp_constexpr < 201304)
#  define SK_NO_CXX14_CONSTEXPR
#endif
#if (SK_GCC_VERSION < 50200) || !defined(__cpp_variable_templates) || (__cpp_variable_templates < 201304)
#  define SK_NO_CXX14_VARIABLE_TEMPLATES
#endif


#if !defined(__cpp_structured_bindings) || (__cpp_structured_bindings < 201606)
#  define SK_NO_CXX17_STRUCTURED_BINDINGS
#endif
#if !defined(__cpp_inline_variables) || (__cpp_inline_variables < 201606)
#  define SK_NO_CXX17_INLINE_VARIABLES
#endif
#if !defined(__cpp_fold_expressions) || (__cpp_fold_expressions < 201603)
#  define SK_NO_CXX17_FOLD_EXPRESSIONS
#endif
#if !defined(__cpp_if_constexpr) || (__cpp_if_constexpr < 201606)
#  define SK_NO_CXX17_IF_CONSTEXPR
#endif


#if __GNUC__ >= 7
#  define SK_FALLTHROUGH __attribute__((fallthrough))
#endif


#if (__GNUC__ < 11)      && \
    defined(__MINGW32__) && \
    !defined(__MINGW64__)
// thread_local was broken on mingw for all 32bit compiler releases prior to 11.x, see
// https://sourceforge.net/p/mingw-w64/bugs/527/
// https://gcc.gnu.org/bugzilla/show_bug.cgi?id=83562
// Not setting this causes program termination on thread exit.
#define SK_NO_CXX11_THREAD_LOCAL
#endif


#if __GNUC__ >= 4
#  define SK_ATTRIBUTE_UNUSED __attribute__((__unused__))
#endif


// Type aliasing hint. Supported since gcc 3.3.
#define SK_MAY_ALIAS __attribute__((__may_alias__))


// Unreachable code markup
#if SK_GCC_VERSION >= 40500
#  define SK_UNREACHABLE_RETURN(x) __builtin_unreachable();
#endif


// Deprecated symbol markup
#if SK_GCC_VERSION >= 40500
#define SK_DEPRECATED(msg) __attribute__((deprecated(msg)))
#else
#define SK_DEPRECATED(msg) __attribute__((deprecated))
#endif


#ifndef SK_COMPILER
#  define SK_COMPILER "GNU C++ version " __VERSION__
#endif


#if (SK_GCC_VERSION < 30300)
#  error "Compiler not configured - please reconfigure"
#endif

#endif // SK_COMPILER_GCC_HPP