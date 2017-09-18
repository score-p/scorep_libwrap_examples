$ scorep-libwrap-init --name math --display-name "math.h" -x c --libs="-lm"
Created working directory '.' for library wrapper math.

Next:

Add the #include-statements for your library to libwrap.h.

Add one or more function calls to your library into main.c.
It will be used as a linking-test.

    $ make                 # build wrapper
    $ make check           # execute tests
    $ make install         # install wrapper
    $ make installcheck    # execute more tests

To use the wrapper, link your application like this before executing it:

    $ scorep --libwrap=math gcc  app.c  -lm -o app

For detailed instructions consult 'README.md'.

###############################################################################
$ vim libwrap.h

"""
#ifndef LIBWRAP_H
#define LIBWRAP_H

/*
 * You need to  put any needed #include statements to successfully compile a mini program against the
 * to-be-wrapped library in this file.
 *
 * After you are finished, start editing the `main.c` file.
 */

#include <math.h>

#endif /* LIBWRAP_H */
"""

###############################################################################
$ vim main.c

"""
#include "libwrap.h"

#include <stdio.h>

int
main( int   argc,
      char* argv[] )
{
    /*
     * You need to add some calls to the target library to the main function.
     * Note, this program will never be executed, only linked against the target library.
     *
     * After finishing writing this file, run 'make'
     */

    printf("%lf\n", sqrt(argc));

    return 0;
}
"""

###############################################################################
$ make
  CCLD      main
  CPP       libwrap.i
  GEN       scorep_libwrap_math.c
  QUICK-CHECK
[Score-P] Error: There is mismatch between functions found in the header files
[Score-P]        and the symbols present in the target library.
[Score-P]        Use 'make check' to get a list of missing symbols and add
[Score-P]        them to math.filter. After that repeat this step.
Makefile:169: recipe for target 'quick-check' failed
make: *** [quick-check] Error 1

###############################################################################
$ make check
  FOUND     acos
  MISSING   __acos
  FOUND     asin
  MISSING   __asin
  FOUND     atan
  MISSING   __atan
  FOUND     atan2
  MISSING   __atan2
  FOUND     cos
  MISSING   __cos
  FOUND     sin
  MISSING   __sin
  FOUND     tan
  MISSING   __tan
  FOUND     cosh
  MISSING   __cosh
  FOUND     sinh
  MISSING   __sinh
  FOUND     tanh
  MISSING   __tanh
  FOUND     acosh
  MISSING   __acosh
  FOUND     asinh
  MISSING   __asinh
  FOUND     atanh
  MISSING   __atanh
  FOUND     exp
  MISSING   __exp
  UNCERTAIN frexp
  MISSING   __frexp
  UNCERTAIN ldexp
  MISSING   __ldexp
  FOUND     log
  MISSING   __log
  FOUND     log10
  MISSING   __log10
  UNCERTAIN modf
  MISSING   __modf
  FOUND     expm1
  MISSING   __expm1
  FOUND     log1p
  MISSING   __log1p
  FOUND     logb
  MISSING   __logb
  FOUND     exp2
  MISSING   __exp2
  FOUND     log2
  MISSING   __log2
  FOUND     pow
  MISSING   __pow
  FOUND     sqrt
  MISSING   __sqrt
  FOUND     hypot
  MISSING   __hypot
  FOUND     cbrt
  MISSING   __cbrt
  FOUND     ceil
  MISSING   __ceil
  FOUND     fabs
  MISSING   __fabs
  FOUND     floor
  MISSING   __floor
  FOUND     fmod
  MISSING   __fmod
  UNCERTAIN __isinf
  UNCERTAIN __finite
  UNCERTAIN isinf
  UNCERTAIN finite
  FOUND     drem
  MISSING   __drem
  FOUND     significand
  MISSING   __significand
  UNCERTAIN copysign
  MISSING   __copysign
  FOUND     nan
  MISSING   __nan
  UNCERTAIN __isnan
  UNCERTAIN isnan
  FOUND     j0
  MISSING   __j0
  FOUND     j1
  MISSING   __j1
  FOUND     jn
  MISSING   __jn
  FOUND     y0
  MISSING   __y0
  FOUND     y1
  MISSING   __y1
  FOUND     yn
  MISSING   __yn
  FOUND     erf
  MISSING   __erf
  FOUND     erfc
  MISSING   __erfc
  FOUND     lgamma
  MISSING   __lgamma
  FOUND     tgamma
  MISSING   __tgamma
  FOUND     gamma
  MISSING   __gamma
  FOUND     lgamma_r
  MISSING   __lgamma_r
  FOUND     rint
  MISSING   __rint
  FOUND     nextafter
  MISSING   __nextafter
  FOUND     nexttoward
  MISSING   __nexttoward
  FOUND     remainder
  MISSING   __remainder
  UNCERTAIN scalbn
  MISSING   __scalbn
  FOUND     ilogb
  MISSING   __ilogb
  FOUND     scalbln
  MISSING   __scalbln
  FOUND     nearbyint
  MISSING   __nearbyint
  FOUND     round
  MISSING   __round
  FOUND     trunc
  MISSING   __trunc
  FOUND     remquo
  MISSING   __remquo
  FOUND     lrint
  MISSING   __lrint
  FOUND     llrint
  MISSING   __llrint
  FOUND     lround
  MISSING   __lround
  FOUND     llround
  MISSING   __llround
  FOUND     fdim
  MISSING   __fdim
  FOUND     fmax
  MISSING   __fmax
  FOUND     fmin
  MISSING   __fmin
  FOUND     __fpclassify
  UNCERTAIN __signbit
  FOUND     fma
  MISSING   __fma
  FOUND     scalb
  MISSING   __scalb
  FOUND     acosf
  MISSING   __acosf
  FOUND     asinf
  MISSING   __asinf
  FOUND     atanf
  MISSING   __atanf
  FOUND     atan2f
  MISSING   __atan2f
  FOUND     cosf
  MISSING   __cosf
  FOUND     sinf
  MISSING   __sinf
  FOUND     tanf
  MISSING   __tanf
  FOUND     coshf
  MISSING   __coshf
  FOUND     sinhf
  MISSING   __sinhf
  FOUND     tanhf
  MISSING   __tanhf
  FOUND     acoshf
  MISSING   __acoshf
  FOUND     asinhf
  MISSING   __asinhf
  FOUND     atanhf
  MISSING   __atanhf
  FOUND     expf
  MISSING   __expf
  UNCERTAIN frexpf
  MISSING   __frexpf
  UNCERTAIN ldexpf
  MISSING   __ldexpf
  FOUND     logf
  MISSING   __logf
  FOUND     log10f
  MISSING   __log10f
  UNCERTAIN modff
  MISSING   __modff
  FOUND     expm1f
  MISSING   __expm1f
  FOUND     log1pf
  MISSING   __log1pf
  FOUND     logbf
  MISSING   __logbf
  FOUND     exp2f
  MISSING   __exp2f
  FOUND     log2f
  MISSING   __log2f
  FOUND     powf
  MISSING   __powf
  FOUND     sqrtf
  MISSING   __sqrtf
  FOUND     hypotf
  MISSING   __hypotf
  FOUND     cbrtf
  MISSING   __cbrtf
  FOUND     ceilf
  MISSING   __ceilf
  FOUND     fabsf
  MISSING   __fabsf
  FOUND     floorf
  MISSING   __floorf
  FOUND     fmodf
  MISSING   __fmodf
  UNCERTAIN __isinff
  UNCERTAIN __finitef
  UNCERTAIN isinff
  UNCERTAIN finitef
  FOUND     dremf
  MISSING   __dremf
  FOUND     significandf
  MISSING   __significandf
  UNCERTAIN copysignf
  MISSING   __copysignf
  FOUND     nanf
  MISSING   __nanf
  UNCERTAIN __isnanf
  UNCERTAIN isnanf
  FOUND     j0f
  MISSING   __j0f
  FOUND     j1f
  MISSING   __j1f
  FOUND     jnf
  MISSING   __jnf
  FOUND     y0f
  MISSING   __y0f
  FOUND     y1f
  MISSING   __y1f
  FOUND     ynf
  MISSING   __ynf
  FOUND     erff
  MISSING   __erff
  FOUND     erfcf
  MISSING   __erfcf
  FOUND     lgammaf
  MISSING   __lgammaf
  FOUND     tgammaf
  MISSING   __tgammaf
  FOUND     gammaf
  MISSING   __gammaf
  FOUND     lgammaf_r
  MISSING   __lgammaf_r
  FOUND     rintf
  MISSING   __rintf
  FOUND     nextafterf
  MISSING   __nextafterf
  FOUND     nexttowardf
  MISSING   __nexttowardf
  FOUND     remainderf
  MISSING   __remainderf
  UNCERTAIN scalbnf
  MISSING   __scalbnf
  FOUND     ilogbf
  MISSING   __ilogbf
  FOUND     scalblnf
  MISSING   __scalblnf
  FOUND     nearbyintf
  MISSING   __nearbyintf
  FOUND     roundf
  MISSING   __roundf
  FOUND     truncf
  MISSING   __truncf
  FOUND     remquof
  MISSING   __remquof
  FOUND     lrintf
  MISSING   __lrintf
  FOUND     llrintf
  MISSING   __llrintf
  FOUND     lroundf
  MISSING   __lroundf
  FOUND     llroundf
  MISSING   __llroundf
  FOUND     fdimf
  MISSING   __fdimf
  FOUND     fmaxf
  MISSING   __fmaxf
  FOUND     fminf
  MISSING   __fminf
  FOUND     __fpclassifyf
  UNCERTAIN __signbitf
  FOUND     fmaf
  MISSING   __fmaf
  FOUND     scalbf
  MISSING   __scalbf
  FOUND     acosl
  MISSING   __acosl
  FOUND     asinl
  MISSING   __asinl
  FOUND     atanl
  MISSING   __atanl
  FOUND     atan2l
  MISSING   __atan2l
  FOUND     cosl
  MISSING   __cosl
  FOUND     sinl
  MISSING   __sinl
  FOUND     tanl
  MISSING   __tanl
  FOUND     coshl
  MISSING   __coshl
  FOUND     sinhl
  MISSING   __sinhl
  FOUND     tanhl
  MISSING   __tanhl
  FOUND     acoshl
  MISSING   __acoshl
  FOUND     asinhl
  MISSING   __asinhl
  FOUND     atanhl
  MISSING   __atanhl
  FOUND     expl
  MISSING   __expl
  UNCERTAIN frexpl
  MISSING   __frexpl
  UNCERTAIN ldexpl
  MISSING   __ldexpl
  FOUND     logl
  MISSING   __logl
  FOUND     log10l
  MISSING   __log10l
  UNCERTAIN modfl
  MISSING   __modfl
  FOUND     expm1l
  MISSING   __expm1l
  FOUND     log1pl
  MISSING   __log1pl
  FOUND     logbl
  MISSING   __logbl
  FOUND     exp2l
  MISSING   __exp2l
  FOUND     log2l
  MISSING   __log2l
  FOUND     powl
  MISSING   __powl
  FOUND     sqrtl
  MISSING   __sqrtl
  FOUND     hypotl
  MISSING   __hypotl
  FOUND     cbrtl
  MISSING   __cbrtl
  FOUND     ceill
  MISSING   __ceill
  FOUND     fabsl
  MISSING   __fabsl
  FOUND     floorl
  MISSING   __floorl
  FOUND     fmodl
  MISSING   __fmodl
  UNCERTAIN __isinfl
  UNCERTAIN __finitel
  UNCERTAIN isinfl
  UNCERTAIN finitel
  FOUND     dreml
  MISSING   __dreml
  FOUND     significandl
  MISSING   __significandl
  UNCERTAIN copysignl
  MISSING   __copysignl
  FOUND     nanl
  MISSING   __nanl
  UNCERTAIN __isnanl
  UNCERTAIN isnanl
  FOUND     j0l
  MISSING   __j0l
  FOUND     j1l
  MISSING   __j1l
  FOUND     jnl
  MISSING   __jnl
  FOUND     y0l
  MISSING   __y0l
  FOUND     y1l
  MISSING   __y1l
  FOUND     ynl
  MISSING   __ynl
  FOUND     erfl
  MISSING   __erfl
  FOUND     erfcl
  MISSING   __erfcl
  FOUND     lgammal
  MISSING   __lgammal
  FOUND     tgammal
  MISSING   __tgammal
  FOUND     gammal
  MISSING   __gammal
  FOUND     lgammal_r
  MISSING   __lgammal_r
  FOUND     rintl
  MISSING   __rintl
  FOUND     nextafterl
  MISSING   __nextafterl
  FOUND     nexttowardl
  MISSING   __nexttowardl
  FOUND     remainderl
  MISSING   __remainderl
  UNCERTAIN scalbnl
  MISSING   __scalbnl
  FOUND     ilogbl
  MISSING   __ilogbl
  FOUND     scalblnl
  MISSING   __scalblnl
  FOUND     nearbyintl
  MISSING   __nearbyintl
  FOUND     roundl
  MISSING   __roundl
  FOUND     truncl
  MISSING   __truncl
  FOUND     remquol
  MISSING   __remquol
  FOUND     lrintl
  MISSING   __lrintl
  FOUND     llrintl
  MISSING   __llrintl
  FOUND     lroundl
  MISSING   __lroundl
  FOUND     llroundl
  MISSING   __llroundl
  FOUND     fdiml
  MISSING   __fdiml
  FOUND     fmaxl
  MISSING   __fmaxl
  FOUND     fminl
  MISSING   __fminl
  FOUND     __fpclassifyl
  UNCERTAIN __signbitl
  FOUND     fmal
  MISSING   __fmal
  FOUND     scalbl
  MISSING   __scalbl
  FOUND     matherr
[Score-P] Warning: Symbols that are present without linking against the target
[Score-P]          library and its dependencies have been wrapped. It is uncertain
[Score-P]          whether calls to them can be intercepted, or perhaps you did
[Score-P]          not intend to wrap them. The filter file 'uncertain.filter'
[Score-P]          containing these symbols has been created. Maybe you want to
[Score-P]          add all or some of these symbols to math.filter.
[Score-P]          Then repeat 'make' and 'make check'.
[Score-P] Error: Symbols that are not present in the target library have been
[Score-P]        wrapped. The filter file 'missing.filter' containing these
[Score-P]        symbols has been created. Reconsider your wrapper settings, or
[Score-P]        add these symbols to math.filter if they should not be
[Score-P]        wrapped. Then repeat 'make' and 'make check'.
Makefile:283: recipe for target 'check' failed
make: *** [check] Error 1

###############################################################################
$ vim -p math.filter missing.filter uncertain.filter 

# Put everything from missing.filter and everything with the prefix "__" in uncertain.filter into math.filter

###############################################################################
$ make
  GEN       scorep_libwrap_math.c
  QUICK-CHECK
  CC        libscorep_libwrap_math_linktime.lo
  CCLD      libscorep_libwrap_math_linktime.la
ar: `u' modifier ignored since `D' is the default (see `U')
  CC        libscorep_libwrap_math_runtime.lo
  CCLD      libscorep_libwrap_math_runtime.la
ar: `u' modifier ignored since `D' is the default (see `U')

###############################################################################
$ make install
  QUICK-CHECK
  GEN       math.libwrap
  GEN       math.summary
  INSTALL   libscorep_libwrap_math_linktime.la
  INSTALL   libscorep_libwrap_math_runtime.la
  INSTALL   math.libwrap
  INSTALL   math.summary
  INSTALL   math.wrap
  INSTALL   math.nvcc.wrap
  INSTALL   math.filter

###############################################################################
$ make installcheck
  SCOREP    main_linktime_wrapped
  SCOREP    main_runtime_wrapped
[Score-P] To further check, please execute the generated binaries:
[Score-P]
[Score-P]     $ ./main_linktime_wrapped
[Score-P]     $ ./main_runtime_wrapped
[Score-P]
[Score-P] If available, verify the output via:
[Score-P]
[Score-P]     $ cube_info -m visits:excl scorep-*/profile.cubex
[Score-P]
[Score-P] It should display numbers you would expect from intercepting
[Score-P] main.c's calls to the target library.

###############################################################################
$ ./main_linktime_wrapped && mv scorep-2* scorep-linktime
1.000000

$ ./main_runtime_wrapped && mv scorep-2* scorep-runtime
1.000000

$ cube_info -m visits:excl scorep-linktime/profile.cubex
|      Visits (E) | Diff-Calltree
|               1 |  * main
|               1 |  |  * sqrt(double)

$ cube_info -m visits:excl scorep-runtime/profile.cubex
|      Visits (E) | Diff-Calltree
|               1 |  * main
|               1 |  |  * sqrt(double)

###############################################################################

$ ll
total 928
-rw-rw-r-- 1 brendel brendel   1086 Jul 28 16:39 libscorep_libwrap_math_linktime.la
-rw-rw-r-- 1 brendel brendel    345 Jul 28 16:39 libscorep_libwrap_math_linktime.lo
-rw-rw-r-- 1 brendel brendel 233768 Jul 28 16:39 libscorep_libwrap_math_linktime.o
-rw-rw-r-- 1 brendel brendel   1079 Jul 28 16:39 libscorep_libwrap_math_runtime.la
-rw-rw-r-- 1 brendel brendel    342 Jul 28 16:39 libscorep_libwrap_math_runtime.lo
-rw-rw-r-- 1 brendel brendel 295088 Jul 28 16:39 libscorep_libwrap_math_runtime.o
-rw-r--r-- 1 brendel brendel     72 Jul 28 16:33 libwrap.c
-rw-r--r-- 1 brendel brendel    291 Jul 28 16:33 libwrap.h
-rw-rw-r-- 1 brendel brendel  43177 Jul 28 16:37 libwrap.i
-rwxrwxr-x 1 brendel brendel   8464 Jul 28 16:37 main
-rw-r--r-- 1 brendel brendel    381 Jul 28 16:34 main.c
-rwxrwxr-x 1 brendel brendel  21056 Jul 28 16:39 main_linktime_wrapped
-rwxrwxr-x 1 brendel brendel  21016 Jul 28 16:40 main_runtime_wrapped
-rw-rw-r-- 1 brendel brendel  18606 Jul 28 16:33 Makefile
-rw-rw-r-- 1 brendel brendel   7380 Jul 28 16:39 math.filter
-rw-rw-r-- 1 brendel brendel    219 Jul 28 16:39 math.libwrap
-rw-rw-r-- 1 brendel brendel   5920 Jul 28 16:39 math.nvcc.wrap
-rw-rw-r-- 1 brendel brendel    419 Jul 28 16:39 math.summary
-rw-rw-r-- 1 brendel brendel   2428 Jul 28 16:39 math.wrap
-rw-rw-r-- 1 brendel brendel   6048 Jul 28 16:37 missing.filter
-rw-r--r-- 1 brendel brendel  17797 Jul 28 16:33 README.md
-rw-rw-r-- 1 brendel brendel 120925 Jul 28 16:39 scorep_libwrap_math.c
-rw-rw-r-- 1 brendel brendel  63773 Jul 28 16:39 scorep_libwrap_math.inc.c
drwxr-xr-x 2 brendel brendel   4096 Jul 28 16:40 scorep-linktime
drwxr-xr-x 2 brendel brendel   4096 Jul 28 16:40 scorep-runtime
-rw-rw-r-- 1 brendel brendel   1091 Jul 28 16:37 uncertain.filter

$ ll $SCOREP_DIR/share/scorep/ | grep math
-rw-r--r-- 1 brendel brendel   7380 Jul 28 16:39 math.filter
-rw-r--r-- 1 brendel brendel    219 Jul 28 16:39 math.libwrap
-rw-r--r-- 1 brendel brendel   5920 Jul 28 16:39 math.nvcc.wrap
-rw-r--r-- 1 brendel brendel    419 Jul 28 16:39 math.summary
-rw-r--r-- 1 brendel brendel   2428 Jul 28 16:39 math.wrap

$ ll $SCOREP_DIR/lib | grep math
-rw-r--r-- 1 brendel brendel   237366 Jul 28 16:39 libscorep_libwrap_math_linktime.a
-rwxr-xr-x 1 brendel brendel     1087 Jul 28 16:39 libscorep_libwrap_math_linktime.la
-rwxr-xr-x 1 brendel brendel   143176 Jul 28 16:39 libscorep_libwrap_math_linktime.so
-rw-r--r-- 1 brendel brendel   297332 Jul 28 16:39 libscorep_libwrap_math_runtime.a
-rwxr-xr-x 1 brendel brendel     1080 Jul 28 16:39 libscorep_libwrap_math_runtime.la
-rwxr-xr-x 1 brendel brendel   154512 Jul 28 16:39 libscorep_libwrap_math_runtime.so
