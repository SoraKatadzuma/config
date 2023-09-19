// This header is inspired and heavily based on the one from boost::config.
// https://www.boost.org/libs/config

#ifndef SK_PLATFORM_LINUX_HPP
#define SK_PLATFORM_LINUX_HPP
#define SK_PLATFORM "Linux"


#if defined(__GLIBC__) && defined(__GLIBC_PREREQ)
#  if !__GLIBC_PREREQ(2,2) || (!defined(__USE_ISOC99) && !defined(__USE_UNIX98))
#    define SK_NO_SWPRINTF
#  endif
#else
#  define SK_NO_SWPRINTF
#endif


// if the compiler is not gcc we still need to be able to parse
// the GNU system headers, some of which (mainly <stdint.h>)
// use GNU specific extensions:
#ifndef __GNUC__
#  ifndef __extension__
#     define __extension__
#  endif
#  ifndef __const__
#     define __const__ const
#  endif
#  ifndef __volatile__
#     define __volatile__ volatile
#  endif
#  ifndef __signed__
#     define __signed__ signed
#  endif
#  ifndef __typeof__
#     define __typeof__ typeof
#  endif
#  ifndef __inline__
#     define __inline__ inline
#  endif
#endif


namespace sk {

constexpr platform kActivePlatform = platform::eLinux;

}


#endif // SK_PLATFORM_LINUX_HPP