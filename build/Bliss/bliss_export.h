
#ifndef BLISS_EXPORT_H
#define BLISS_EXPORT_H

#ifdef BLISS_STATIC_DEFINE
#  define BLISS_EXPORT
#  define BLISS_NO_EXPORT
#else
#  ifndef BLISS_EXPORT
#    ifdef Bliss_EXPORTS
        /* We are building this library */
#      define BLISS_EXPORT __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define BLISS_EXPORT __attribute__((visibility("default")))
#    endif
#  endif

#  ifndef BLISS_NO_EXPORT
#    define BLISS_NO_EXPORT __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef BLISS_DEPRECATED
#  define BLISS_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef BLISS_DEPRECATED_EXPORT
#  define BLISS_DEPRECATED_EXPORT BLISS_EXPORT BLISS_DEPRECATED
#endif

#ifndef BLISS_DEPRECATED_NO_EXPORT
#  define BLISS_DEPRECATED_NO_EXPORT BLISS_NO_EXPORT BLISS_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef BLISS_NO_DEPRECATED
#    define BLISS_NO_DEPRECATED
#  endif
#endif

#endif /* BLISS_EXPORT_H */
