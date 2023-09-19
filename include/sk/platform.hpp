// This header is inspired and heavily based on the one from boost::config.
// https://www.boost.org/libs/config

#ifndef SK_PLATFORM_SELECT_HPP
#define SK_PLATFORM_SELECT_HPP

namespace sk {


// Numeric/Type based representation of platform.
enum struct platform {
     eLinux,
     eWindows,
     eMacos,
};


} // namespace sk


#if (defined(linux)     || \
     defined(__linux)   || \
     defined(__linux__) || \
     defined(__GNU__)   || \
     defined(__GLIBC__))
#  define SK_PLATFORM_CONFIG "platform/linux.hpp"
#elif defined(_WIN32)    || \
      defined(__WIN32__) || \
      defined(WIN32)
#  define SK_PLATFORM_CONFIG "platform/windows.hpp"
#elif defined(macintosh) || \
      defined(__APPLE__) || \
      defined(__APPLE_CC__)
#  error "Not yet configured for macos platform, please provide your own."
#  define SK_PLATFORM_CONFIG "platform/macos.hpp"
#endif

#endif // SK_PLATFORM_SELECT_HPP

#if 0
#include "platform/macos.hpp"
#include "platform/linux.hpp"
#include "platform/windows.hpp"
#endif