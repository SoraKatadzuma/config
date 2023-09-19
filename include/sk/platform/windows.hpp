// This header is inspired and heavily based on the one from boost::config.
// https://www.boost.org/libs/config

#ifndef SK_PLATFORM_WINDOWS_HPP
#define SK_PLATFORM_WINDOWS_HPP
#define SK_PLATFORM "Windows"


// Provides MinGW runtime information.
#if defined(__MINGW32__)
#  include <_mingw.h>
#endif


#if defined(__GNUC__) && !defined(SK_NO_SWPRINTF)
#  define SK_NO_SWPRINTF
#endif


#ifndef SK_SYMBOL_EXPORT
#  define SK_HAS_DECLSPEC
#  define SK_SYMBOL_EXPORT __declspec(dllexport)
#  define SK_SYMBOL_IMPORT __declspec(dllimport)
#endif


#if defined(__MINGW32__) && \
    ((__MINGW32_MAJOR_VERSION > 2)  || \
     ((__MINGW32_MAJOR_VERSION == 2) && \
      (__MINGW32_MINOR_VERSION >= 0)))
#  define SK_HAS_STDINT_H
#  ifndef __STDC_LIMIT_MACROS
#    define __STDC_LIMIT_MACROS
#  endif
#  define SK_HAS_DIRENT_H
#  define SK_HAS_UNISTD_H
#endif


#ifndef HAPICALL
#  define HAPICALL __stdcall
#endif


#ifndef SK_HAS_PTHREADS
#  define SK_HAS_PTHREADS
#endif


#if defined(WINAPI_FAMILY) && \
    (WINAPI_FAMILY == WINAPI_FAMILY_APP || \
     WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP)
#  define SK_NO_ANSI_APIS
#endif


#ifndef SK_DISABLE_WIN32
#  define SK_HAS_FTIME
#  define SK_WINDOWS 1
#endif


namespace sk {

constexpr platform kActivePlatform = platform::eWindows;

} // namespace hearth


#endif // SK_PLATFORM_WINDOWS_HPP