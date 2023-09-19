// This header is inspired and heavily based on the one from boost::config.
// https://www.boost.org/libs/config

#ifndef SK_CONFIG_HPP
#define SK_CONFIG_HPP
#ifndef SK_NO_CONFIG

// Proceed to select a compiler configuration.
#if !defined(SK_NO_COMPILER_CONFIG) && \
    !defined(SK_COMPILER_CONFIG)
#include "compiler.hpp"
#endif

#ifdef   SK_COMPILER_CONFIG
#include SK_COMPILER_CONFIG
#endif

// Proceed to select a platform configuration.
#if !defined(SK_NO_PLATFORM_CONFIG) && \
    !defined(SK_PLATFORM_CONFIG)
#include "platform.hpp"
#endif

#ifdef   SK_PLATFORM_CONFIG
#include SK_PLATFORM_CONFIG
#endif

// Handle error of both shared and static builds.
#if defined(SK_BUILD_SHARED) && \
    defined(SK_BUILD_STATIC)
#error "Only specify one of SK_BUILD_SHARED or SK_BUILD_STATIC."
#endif

// Set up finalized dll/so macros.
#ifdef SK_SYMBOL_EXPORT
#  if defined(SK_BUILD_SHARED)
#    define SKAPI SK_SYMBOL_EXPORT
#  elif !defined(SK_BUILD_STATIC)
#    define SKAPI SK_SYMBOL_IMPORT
#  else
#    define SKAPI
#  endif
#endif

#ifndef SKAPICALL
#  define SKAPICALL
#endif

// Is compiler/version specific.
#ifdef SK_HAS_PRAGMA_ONCE
#pragma once
#endif

// Helper macro.
#define SK_STRINGIZE(x) SK_DO_STRINGIZE(x)
#define SK_DO_STRINGIZE(x) #x

// Helper macro.
#define SK_CONCAT(x, y) SK_DO_CONCAT(x, y)
#define SK_DO_CONCAT(x, y) SK_DO_CONCAT2(x, y)
#define SK_DO_CONCAT2(x, y) x##y

// Final includes.
#include "types.hpp"

#endif // SK_NO_CONFIG
#endif // SK_CONFIG_HPP