// This header is inspired and heavily based on the one from boost::config.
// https://www.boost.org/libs/config

#ifndef SK_COMPILER_SELECT_HPP
#define SK_COMPILER_SELECT_HPP

#if defined(__INTEL_COMPILER) || defined(__ICL) || defined(__ICC) || defined(__ECC)
#  error "Not yet configured for intel compiler, please provide your own."
#  define SK_COMPILER_CONFIG "compiler/intel.hpp"
#elif defined(__clang__) && !defined(__ibmxl__) && !defined(__CODEGEARC__)
#  error "Not yet configured for clang compiler, please provide your own."
#  define SK_COMPILER_CONFIG "compiler/clang.hpp"
#elif defined(__GNUC__) && !defined(__ibmxl__)
#  define SK_COMPILER_CONFIG "compiler/gcc.hpp"
#elif defined(_MSV_VER)
#  error "Not yet configured for msvc compiler, please provide your own."
#  define SK_COMPILER_CONFIG "compiler/msvc.hpp"
#else
#  error "Unknown compiler"
#endif // compiler selection

#endif // SK_COMPILER_SELECT_HPP

// Dependency scanning hack.
#if 0
#include "compiler/clang.hpp"
#include "compiler/gcc.hpp"
#include "compiler/intel.hpp"
#include "compiler/msvc.hpp"
#endif