/* confdefs.h */
#define PACKAGE_NAME "ClamAV"
#define PACKAGE_TARNAME "clamav"
#define PACKAGE_VERSION "0.98.7"
#define PACKAGE_STRING "ClamAV 0.98.7"
#define PACKAGE_BUGREPORT "http://bugs.clamav.net/"
#define PACKAGE_URL "http://www.clamav.net/"
#define PACKAGE PACKAGE_NAME
#define STDC_HEADERS 1
#define HAVE_SYS_TYPES_H 1
#define HAVE_SYS_STAT_H 1
#define HAVE_STDLIB_H 1
#define HAVE_STRING_H 1
#define HAVE_MEMORY_H 1
#define HAVE_STRINGS_H 1
#define HAVE_INTTYPES_H 1
#define HAVE_STDINT_H 1
#define HAVE_UNISTD_H 1
#define __EXTENSIONS__ 1
#define _ALL_SOURCE 1
#define _GNU_SOURCE 1
#define _POSIX_PTHREAD_SEMANTICS 1
#define _TANDEM_SOURCE 1
#define LIBCLAMAV_FULLVER "6.1.26"
#define LIBCLAMAV_MAJORVER 6
#define VERSION "0.98.7"
#define VERSION_SUFFIX ""
#define HAVE_DLFCN_H 1
#define LT_OBJDIR ".libs/"
#define LT_MODULE_EXT ".so"
#define LT_MODULE_PATH_VAR "LD_LIBRARY_PATH"
#define LT_DLSEARCH_PATH "/lib:/usr/lib:/opt/vc/lib:/lib/arm-linux-gnueabihf:/usr/lib/arm-linux-gnueabihf:/usr/lib/arm-linux-gnueabihf/libfakeroot:/usr/local/lib:/usr/local/lib"
#define HAVE_LIBDL 1
#define HAVE_DLERROR 1
#define HAVE_LIBDLLOADER 1
#define HAVE_ARGZ_H 1
#define HAVE_ERROR_T 1
#define HAVE_ARGZ_ADD 1
#define HAVE_ARGZ_APPEND 1
#define HAVE_ARGZ_COUNT 1
/* end confdefs.h.  */
/* Define argz_create_sep to an innocuous variant, in case <limits.h> declares argz_create_sep.
   For example, HP-UX 11i <limits.h> declares gettimeofday.  */
#define argz_create_sep innocuous_argz_create_sep

/* System header to define __stub macros and hopefully few prototypes,
    which can conflict with char argz_create_sep (); below.
    Prefer <limits.h> to <assert.h> if __STDC__ is defined, since
    <limits.h> exists even on freestanding compilers.  */

#ifdef __STDC__
# include <limits.h>
#else
# include <assert.h>
#endif

#undef argz_create_sep

/* Override any GCC internal prototype to avoid an error.
   Use char because int might match the return type of a GCC
   builtin and then its argument prototype would still apply.  */
#ifdef __cplusplus
extern "C"
#endif
char argz_create_sep ();
/* The GNU C library defines this for functions which it implements
    to always fail with ENOSYS.  Some functions are actually named
    something starting with __ and the normal name is an alias.  */
#if defined __stub_argz_create_sep || defined __stub___argz_create_sep
choke me
#endif

int
main ()
{
return argz_create_sep ();
  ;
  return 0;
}
